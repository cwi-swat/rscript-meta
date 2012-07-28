package nl.cwi.sen1.visbase.rstorecontainer.datatypes;

import java.util.ArrayList;
import java.util.List;

import nl.cwi.sen1.visbase.rstorecontainer.RStoreContainer;
import aterm.ATermList;
import aterm.pure.PureFactory;

/**
 * This class represents the list of 'RStore Fact-identification data' being
 * communicated over the ToolBus.
 * 
 * It can be used to automatically convert the ATerm(List) that is send over the
 * ToolBus to the FactBrowser.
 * 
 * Example: <code>
 * // The ATerm received by another Java tool<br />
 * ATerm incomingAterm;<br />
 * <br />
 * // Use the constructor that accepts an ATermList as argument <br />
 * FactInfoList factInfoList = new FactInfoList((ATermList) incomingAterm); <br />
 * <br />
 * //Iterate through FactInfo list <br />
 * for (FactInfo factInfo : factInfoList.getFactInfos()) <br />
 * { <br />
 * &nbsp;&nbsp;// Access Fact information <br />
 * &nbsp;&nbsp;factInfo.getId(); <br />
 * &nbsp;&nbsp;factInfo.getName(); <br />
 * &nbsp;&nbsp;factInfo.getType(); <br />
 * }  <br />
 * </code>
 * 
 * @see FactInfo
 * 
 * @author Ricardo Lindooren
 * @author Arend van Beelen (reviewer)
 * @date 2007-02-14
 */
public class FactInfoList {
    private List<FactInfo> m_factInfoList;

    /**
     * Default constructor.
     * 
     * Creates an empty list.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public FactInfoList() {
        super();

        m_factInfoList = new ArrayList<FactInfo>();
    }

    /**
     * Constructor that initializes the list from an ATermList.
     * 
     * @param termList ATermList containing fact data.
     * 
     * @throws ATermParseException if parsing of ATermList fails.
     * @throws RuntimeException if ATermList input is null.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public FactInfoList(ATermList termList)
            throws ATermParseException {
        if (termList == null) {
            throw new RuntimeException("ATermList input should not be null");
        }

        m_factInfoList = new ArrayList<FactInfo>();

        try {
            int numFactInfoObjects = termList.getLength();
            for (int i = 0; i < numFactInfoObjects; i++) {

                ATermList factData = (ATermList) termList.elementAt(i);
        
                FactInfo factInfo = new FactInfo(factData);

                m_factInfoList.add(factInfo);
            }
        } catch (Exception exception) {
            throw new ATermParseException("Exception while parsing ATermList containing List of FactInfo (see cause) ",
                    exception);
        }
    }

    /**
     * Adds a FactInfo object to this list.
     * 
     * Another option is to use the list directly with getFactInfos().
     * 
     * @param rStoreFactData
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void addFactInfoToList(FactInfo rStoreFactData) {
        if (rStoreFactData == null) {
            throw new RuntimeException("RStoreFactData should not be null");
        }

        m_factInfoList.add(rStoreFactData);
    }

    /**
     * Getter for the intern List instance
     * 
     * @return
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public List<FactInfo> getFactInfos() {
        return m_factInfoList;
    }

    /**
     * Creates a new ATermList containing the values in this datatype
     * 
     * @return new instance of ATermList
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public ATermList toATermList() {
        
        PureFactory pureFactory = RStoreContainer.getPureFactory();
        ATermList list = pureFactory.makeList();

        for (FactInfo factInfo : m_factInfoList) {        
            ATermList factTermList = factInfo.toAtermList();
            list = list.append(factTermList);
        }
        return list;
    }
}
