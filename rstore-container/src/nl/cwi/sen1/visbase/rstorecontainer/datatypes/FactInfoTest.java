package nl.cwi.sen1.visbase.rstorecontainer.datatypes;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.IdCon;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.RTypeColumnTypes;
import nl.cwi.sen1.relationstores.types.relem.Tuple;
import nl.cwi.sen1.visbase.rstorecontainer.RStoreContainer;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import aterm.ATermAppl;
import aterm.ATermInt;
import aterm.ATermList;

/**
 * Tests the FactInfo class.
 *
 * @author Ricardo Lindooren
 * @author Arend van Beelen (reviewer)
 * @date 2007-02-14
 */
public class FactInfoTest extends TestCase {

    private FactInfo m_factInfo;

    private final static Log m_log = LogFactory.getLog(FactInfoTest.class);

    private final static int RSTORE_ID = 1;
    private final static String RSTORE_NAME = "RicoTestFact";
    private final static String RSTORE_TYPE = "relation([str,str])";

    @Override
    protected void setUp() throws Exception {
        super.setUp();

        m_factInfo = new FactInfo(RSTORE_ID, getTestRTuple(RSTORE_NAME));
    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();

        m_factInfo = null;
    }

    /**
     * Simple getter test.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testGetId() {
        assertEquals(RSTORE_ID, m_factInfo.getId());
    }

    /**
     * Simple getter test.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testGetName() {
        assertEquals(RSTORE_NAME, m_factInfo.getName());
    }

    /**
     * Simple getter test.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testGetType() {
        assertEquals(RSTORE_TYPE, m_factInfo.getType());
    }

    /**
     * Simple getter test.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-21
     */
    public void testGetRType() {
        assertNotNull("The RType instance of the factinfo under test should not be null",
                      m_factInfo.getRType());
    }

    /**
     * Tests the code that creates an AtermList.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testToAtermList() {
        ATermList list = m_factInfo.toAtermList();

        assertNotNull("AtermList should not be null", list);

        if (m_log.isDebugEnabled()) {
            m_log.debug("AtermList created from RStoreFactData during test: \n\n\t"
                        + list.toString() + "\n");
        }

        ATermInt factId = (ATermInt) list.elementAt(0);
        assertEquals("Id of fact does not equal expected value",
                     1, factId.getInt());

        ATermAppl factName = (ATermAppl) list.elementAt(1);
        assertEquals("Name of fact does not equal expected value",
                    RSTORE_NAME, factName.getName());

        ATermAppl factType = (ATermAppl) list.elementAt(2);

        Factory factory = Factory.getInstance(RStoreContainer.getPureFactory());
        RType rType = factory.RTypeFromTerm(factType);

        final String typeName = rType.toString();

        assertEquals("Name of fact does not equal expected value",
                     RSTORE_TYPE, typeName);
    }

    /**
     * Tests the Constructor used to parse ATermList data.
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testConstructFromAtermList() throws Exception {

        ATermList list = m_factInfo.toAtermList();

        // first some destructive tests
        RuntimeException runtimeException = null;
        try {
            new FactInfo(null);
        } catch (RuntimeException exception) {
            runtimeException = exception;
        }
        assertNotNull("Creating a new instance of FactInfo with a null-ATermList should throw a RuntimeException",
                      runtimeException);

        ATermList illegalList = RStoreContainer.getPureFactory().makeList();

        ATermParseException termParseException = null;
        try {
            new FactInfo(illegalList);
        } catch (ATermParseException exception) {
            termParseException = exception;
        }
        assertNotNull("Creating a new instance of FactInfo with a not correctly constructed ATermList should throw a ATermParseException",
                      termParseException);

        FactInfo factInfo = new FactInfo(list);

        assertEquals("Id of constructed FactData from ATermList not correct",
                     factInfo.getId(), m_factInfo.getId());
        assertEquals("Name of constructed FactData from ATermList not correct",
                     factInfo.getName(), m_factInfo.getName());
        assertNotNull("The RType instance should not be null after constructing from ATermList",
                      m_factInfo.getRType());
        assertEquals("Type of constructed FactData from ATermList not correct",
                     factInfo.getType(), m_factInfo.getType());
    }

    /**
     * Tests the Constructor used to parse RTuple data (this code is actually
     * also indirectly tested from the RStoreContainerTest).
     *
     * @see nl.cwi.sen1.visbase.rstorecontainer.RStoreContainerTest
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testConstructFromRTuple() {
        RuntimeException runtimeException = null;
        try {
            new FactInfo(1, null);
        } catch (RuntimeException exception) {
            runtimeException = exception;
        }

        assertNotNull("Creating a new instance of FactInfo with a null-RTuple should throw a RuntimeException",
                      runtimeException);
    }

    /**
     * Creates a dummy RTuple.
     *
     * Format is like:
     * <code>rtuple("##name##",relation([str,str]),set([tuple([str("a"),str("b")]),tuple([str("b"),str("c")]),tuple([str("c"),str("d")]),tuple([str("d"),str("a")])]))</code><br />
     *
     * This method is shared with the FactInfoListTest.
     *
     * @return The dummy RTuple
     *
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-21
     */
    public static RTuple getTestRTuple(final String name) {
        Factory factory = Factory.getInstance(RStoreContainer.getPureFactory());

        IdCon idCon = factory.makeIdCon_IdCon(name);
        RElem a = factory.makeRElem_Str("a");
        RElem b = factory.makeRElem_Str("b");
        RElem c = factory.makeRElem_Str("c");
        RElem d = factory.makeRElem_Str("d");

        RType stringType = factory.makeRType_Str();
        RTypeColumnTypes rTypeColumnTypes = factory.makeRTypeColumnTypes(
                stringType, stringType);
        RType rType = factory.makeRType_Relation(rTypeColumnTypes);
        Tuple ab = factory.makeRElem_Tuple(factory.makeRElemElements(a, b));
        Tuple bc = factory.makeRElem_Tuple(factory.makeRElemElements(b, c));
        Tuple cd = factory.makeRElem_Tuple(factory.makeRElemElements(c, d));
        Tuple da = factory.makeRElem_Tuple(factory.makeRElemElements(d, a));
        RElem rElem = factory.makeRElem_Set(factory.makeRElemElements(ab, bc,
                cd, da));
        RTuple rTuple = factory.makeRTuple_Rtuple(idCon, rType, rElem);

        return rTuple;
    }
}
