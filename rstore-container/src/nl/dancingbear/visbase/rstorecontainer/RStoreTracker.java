package nl.dancingbear.visbase.rstorecontainer;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.TreeSet;

import nl.cwi.sen1.relationstores.types.RStore;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RTupleRtuples;
import nl.dancingbear.visbase.rstorecontainer.datatypes.FactInfo;
import nl.dancingbear.visbase.rstorecontainer.datatypes.FactInfoList;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import aterm.pure.ATermApplImpl;

/**
 * Keeps track of the Rtuples associated to a RStore. Manages the identifiers.
 * 
 * @Date 2007-03-13
 * @author Ricardo Lindooren
 */
public class RStoreTracker {
	private static final Log m_log = LogFactory.getLog(RStoreContainer.class);

	private RStore m_RStore;

	private Map<Integer, RTuple> m_loadedRTuplesMap;

	private Map<String, Integer> m_identifiedRTuplesMap;

	/**
	 * Default Constructor. Reads all RTuple (facts) from the given RStore
	 * 
	 * @param rStore
	 * 
	 * @throws RuntimeException
	 *             if rStore input is null
	 * 
	 * @Date 2007-03-13
	 * @author Ricardo Lindooren
	 */
	public RStoreTracker(RStore rStore) {
		if (rStore == null) {
			throw new RuntimeException("RStore input should not be null");
		}

		updateRStore(rStore);
	}

	private void updateRStore(RStore rStore) {
		m_RStore = rStore;

		m_identifiedRTuplesMap = new LinkedHashMap<String, Integer>();
		m_loadedRTuplesMap = new LinkedHashMap<Integer, RTuple>();

		RTupleRtuples rTuples = rStore.getRtuples();

		final int numRTuples = rTuples.getLength();

		for (int tupleNum = 0; tupleNum < numRTuples; tupleNum++) {
			RTuple rTuple = rTuples.getRTupleAt(tupleNum);

			if (rTuple != null) {
				registerNewRTuple(rTuple);
			}
		}
	}

	/**
	 * Updates this tracker with new or updated facts
	 * 
	 * @param updatedRStore
	 * @return list of ID's of facts that where updated
	 */
	public synchronized List<Integer> update(RStore updatedRStore) {
		List<Integer> updatedFactIds = new ArrayList<Integer>();

		RTupleRtuples rTuples = updatedRStore.getRtuples();

		final int numRTuples = rTuples.getLength();

		for (int tupleNum = 0; tupleNum < numRTuples; tupleNum++) {
			RTuple rTuple = rTuples.getRTupleAt(tupleNum);

			if (rTuple != null) {
				final String identifier = createIdentifierForRTuple(rTuple);

				// Check if a RTuple already existed with this identifier
				if (m_identifiedRTuplesMap.containsKey(identifier)) {
					/* RTuple exists */

					Integer existingId = m_identifiedRTuplesMap.get(identifier);

					if (m_log.isDebugEnabled()) {
						m_log.info("RTuple already exists for identidier: "
								+ identifier + "(id: " + existingId + ")");
					}

					RTuple existingRTuple = m_loadedRTuplesMap.get(existingId);

					boolean rTuplesDifferFromEachOther = diffRtuples(
							existingRTuple, rTuple);

					if (rTuplesDifferFromEachOther) {
						if (m_log.isInfoEnabled()) {
							m_log
									.info("Replacing existing RTuple with new RTuple");
						}

						updatedFactIds.add(existingId);

						// Replace existing loaded RTuple with new RTuple
						m_loadedRTuplesMap.put(existingId, rTuple);
					}
				}
			}
		}

		// Replace current RStore with new RStore, which ensures that all added
		// and removed relations are updated
		updateRStore(updatedRStore);

		return updatedFactIds;
	}

	/**
	 * Simple getter
	 * 
	 * @return the RStore object belonging to this Fact Tracker
	 * 
	 * @Date 2007-03-13
	 * @author Ricardo Lindooren
	 */
	public RStore getRStore() {
		return m_RStore;
	}

	/**
	 * Simple getter
	 * 
	 * @param id
	 * @return the RTuple belonging to the id (null if it doesn't exist)
	 * 
	 * @Date 2007-03-13
	 * @author Ricardo Lindooren
	 */
	public RTuple getRTuple(int id) {
		RTuple rTuple = m_loadedRTuplesMap.get(new Integer(id));

		if (rTuple == null) {
			if (m_log.isWarnEnabled()) {
				m_log.warn("RTuple fact doesn't exist for id: " + id
						+ ". Valid ID's are: " + m_loadedRTuplesMap.keySet());
			}
		}

		return rTuple;
	}

	/**
	 * Creates a list of FactInfo objects containing the descriptive data from
	 * the found facts (using the RTuples in the RStore).
	 * 
	 * @return A FactInfoList object containing information about all the facts
	 *         in the RStore.
	 * 
	 * @author Ricardo Lindooren
	 * @author Arend van Beelen (reviewer)
	 * @date 14-02-2007
	 */
	public FactInfoList getFactInfoFromRStore() {

		FactInfoList factInfoList = new FactInfoList();

		RTupleRtuples rTuples = m_RStore.getRtuples();

		final int numRTuples = rTuples.getLength();
		for (int tupleNum = 0; tupleNum < numRTuples; tupleNum++) {
			RTuple rTuple = rTuples.getRTupleAt(tupleNum);

			if (rTuple != null) {
				FactInfo factInfo = new FactInfo(tupleNum + 1, rTuple);

				factInfoList.addFactInfoToList(factInfo);
			}
		}

		return factInfoList;
	}

	/**
	 * Checks if RTuples differ from eachother
	 * 
	 * @param existingRTuple
	 * @param newRTuple
	 * @return <b>true</b> if RTuples are <b>NOT equal</b>
	 * 
	 * @throws RuntimeException
	 *             if input is null
	 * 
	 * @Date 2007-03-13
	 * @author Ricardo Lindooren
	 */
	public static boolean diffRtuples(RTuple existingRTuple, RTuple newRTuple) {
		boolean result_not_equal;

		if (existingRTuple == null) {
			throw new RuntimeException(
					"existingRTuple input should not be null");
		}
		if (newRTuple == null) {
			throw new RuntimeException("newRTuple input should not be null");
		}

		result_not_equal = !existingRTuple.equals(newRTuple);

		m_log.debug("existingRTuple is " + (result_not_equal ? "NOT" : "")
				+ " EQUAL to newRTuple");

		return result_not_equal;
	}

	/**
	 * Registers
	 * 
	 * @param rTuple
	 * @throws RuntimeException
	 *             if rtuple is null
	 * 
	 * @author Ricardo Lindooren
	 */
	protected void registerNewRTuple(RTuple rTuple) {
		if (rTuple == null) {
			throw new RuntimeException("RTuple input should not be null");
		}

		/* RTuple is new, generate new number identidfier */

		// Create identification for this RTuple
		final String identifier = createIdentifierForRTuple(rTuple);

		// Use a TreeSet to sort the Keys (whe want to have the highest)
		TreeSet<Integer> existingIds = new TreeSet<Integer>(m_loadedRTuplesMap
				.keySet());

		Integer lastId = null;

		try {
			lastId = existingIds.last();
		} catch (NoSuchElementException ex) {
			lastId = new Integer(0);
		}

		Integer newId = new Integer(lastId.intValue() + 1);

		// while (m_loadedRTuplesMap.containsKey(newId)) {
		// if (m_log.isWarnEnabled()) {
		// m_log.warn("Key already existed in m_loadedRTuplesMap: "
		// + newId + ". *generating a new one*");
		// }
		//
		// newId = new Integer(newId.intValue() + 1);
		// }

		if (m_log.isDebugEnabled()) {
			m_log.debug("Identified new RTuple. id:" + newId + ", identifier: "
					+ identifier);
		}

		// Register new RTuple
		m_identifiedRTuplesMap.put(identifier, newId);
		m_loadedRTuplesMap.put(newId, rTuple);
	}

	/**
	 * Used to create a textual identifier for a RTuple
	 * 
	 * @param rTuple
	 * @return the identifier (name + "-" + rType)
	 * @throws RuntimeException
	 *             if rtuple is null
	 * 
	 * @Date 2007-03-13
	 * @author Ricardo Lindooren
	 */
	public static String createIdentifierForRTuple(RTuple rTuple) {
		if (rTuple == null) {
			throw new RuntimeException("RTuple input should not be null");
		}

		final String m_name = ((ATermApplImpl) rTuple.getVariable()
				.getArgument(0)).getName();
		// TODO is it wise to use the toString() method
		final String m_rType = rTuple.getRtype().toString();

		final String identifier = m_name + "-" + m_rType;

		return identifier;
	}
}
