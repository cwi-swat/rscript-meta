package nl.dancingbear.visbase.rstorecontainer.datatypes;

import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.dancingbear.visbase.rstorecontainer.RStoreContainer;
import aterm.ATermAppl;
import aterm.ATermInt;
import aterm.ATermList;
import aterm.pure.ATermApplImpl;
import aterm.pure.PureFactory;

/**
 * This class represents the 'RStore Fact-identification data' being
 * communicated over the ToolBus
 *
 * @see FactInfoList
 *
 * @author Ricardo Lindooren
 * @author Arend van Beelen (reviewer)
 * @date 2007-02-14
 */
public class FactInfo {

    private int m_id;
    private String m_name;
    private RType m_rType;

    /**
     * Contructor that can be used to retrieve RStore FactInfo data from an
     * ATermList representing this data.
     *
     * @param aTermList
     *            the ATermList containing the FactInfo Data (Format:
     *            (int,str,term)
     *            <code>[1,"SIMPLE_GRAPH",relation([str,str])]</code>)
     *
     * @throws ATermParseException if parsing of ATermList fails.
     * @throws RuntimeException if ATermList input is null.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public FactInfo(final ATermList aTermList)
            throws ATermParseException {
        if (aTermList == null) {
            throw new RuntimeException("ATermList input should not be null");
        }

        try {
            PureFactory pureFactory = (PureFactory) aTermList.getFactory();
            Factory factory = Factory.getInstance(pureFactory);

            m_id = ((ATermInt) aTermList.elementAt(0)).getInt();
            m_name = ((ATermAppl) aTermList.elementAt(1)).getName();
            m_rType = factory.RTypeFromTerm((ATermAppl) aTermList.elementAt(2));

        } catch (Exception exception) {
            throw new ATermParseException(
                    "Exception while parsing ATermList containing FactData (see cause) ",
                    exception);
        }
    }

    /**
     * Contructor that can be used to retrieve RStore Fact data from an RTuple
     * representing this data.
     *
     * @param factId ID of the fact. This ID is used to identify facts
     *               between the visualisation tools.
     * @param factRTuple RTuple containing the fact data.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public FactInfo(final int factId, final RTuple factRTuple) {
        if (factRTuple == null) {
            throw new RuntimeException("RTuple input should not be null");
        }

        m_id = factId;
        m_name = ((ATermApplImpl) factRTuple.getVariable().getArgument(0)).getName();
        m_rType = factRTuple.getRtype();
    }

    /**
     * Returns the numeric ID of the fact.
     *
     * @return The ID.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public int getId() {
        return m_id;
    }

    /**
     * Gets the name of the fact.
     *
     * @return Name of the fact.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public String getName() {
        return m_name;
    }

    /**
     * Gets the relation type of the fact.
     *
     * @return A string representing the relation type, like
     *         "relation([str,str])".
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public String getType() {
        if (m_rType != null) {
            // TODO is it wise to use the toString() method
            return m_rType.toString();
        } else {
            return "";
        }
    }

    /**
     * Gets the RType instance that represents the relation type of the fact.
     *
     * @return The relation type of the fact.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-21
     */
    public RType getRType() {
        return m_rType;
    }

    /**
     * Creates a new ATermList containing the values in this datatype.
     *
     * @return A new ATermList instance in the format (int,str,term),
     *         like @c [1,"SIMPLE_GRAPH",relation([str,str])].
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public ATermList toAtermList() {

        PureFactory pureFactory = RStoreContainer.getPureFactory();

        ATermList list = pureFactory.makeList();

        list = list.insertAt(pureFactory.makeInt(getId()), 0);
        list = list.insertAt(pureFactory.make("<str>", getName()), 1);
        list = list.insertAt(getRType().toTerm(), 2);

        return list;
    }
}
