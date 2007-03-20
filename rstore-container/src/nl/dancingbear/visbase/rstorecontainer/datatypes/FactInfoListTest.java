package nl.dancingbear.visbase.rstorecontainer.datatypes;

import java.util.List;

import junit.framework.TestCase;
import nl.dancingbear.visbase.rstorecontainer.RStoreContainer;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import aterm.ATermList;

/**
 * Tests the FactInfoList code
 * 
 * @author Ricardo Lindooren
 * @date 2007-02-14
 * 
 */
public class FactInfoListTest extends TestCase
{
    private static final Log log = LogFactory.getLog(FactInfoListTest.class);

    private FactInfoList rStoreFactInfoListUnderTest;

    private FactInfo rStoreFactInfoUsedForTests1;

    private FactInfo rStoreFactInfoUsedForTests2;

    @Override
    protected void setUp() throws Exception
    {
        super.setUp();

        rStoreFactInfoListUnderTest = new FactInfoList();

        rStoreFactInfoUsedForTests1 = new FactInfo(1, FactInfoTest.getTestRTuple("FooType1"));
        rStoreFactInfoUsedForTests2 = new FactInfo(2, FactInfoTest.getTestRTuple("FooType2"));
    }

    @Override
    protected void tearDown() throws Exception
    {
        super.tearDown();

        rStoreFactInfoListUnderTest = null;

        rStoreFactInfoUsedForTests1 = null;
    }

    /**
     * Test the constructor code
     * 
     */
    public void testRStoreFactIdentificationsList()
    {
        FactInfoList rfdl = new FactInfoList();

        assertNotNull("new RStoreFactDataList Instance should not be null", rfdl);

        rfdl = null;
    }

    /**
     * Tests the Constructor used to parse ATermList data
     * 
     * @throws Exception
     * 
     * @author Ricardo Lindooren
     * @date 2007-02-14
     */
    public void testConstructFromAtermList() throws Exception
    {
        // First dome destructive tests
        RuntimeException rex = null;
        try
        {
            new FactInfoList(null);
        }
        catch (RuntimeException ex)
        {
            rex = ex;
        }
        assertNotNull("Creating a new instance of FactInfoList with a null-ATermList should throw a RuntimeException", rex);

        // The illegalList contains only an int
        ATermList illegalList = RStoreContainer.getPureFactory().makeList();
        illegalList = illegalList.insert(RStoreContainer.getPureFactory().makeInt(6));

        ATermParseException ate = null;
        try
        {
            new FactInfoList(illegalList);
        }
        catch (ATermParseException ex)
        {
            ate = ex;
        }
        assertNotNull("Creating a new instance of FactInfoList with a not correctly constructed ATermList should throw a ATermParseException", ate);

        // Then the normal use tests

        // Add two RStoreFactData objects to list
        rStoreFactInfoListUnderTest.addFactInfoToList(rStoreFactInfoUsedForTests1);
        rStoreFactInfoListUnderTest.addFactInfoToList(rStoreFactInfoUsedForTests2);

        ATermList list = rStoreFactInfoListUnderTest.toATermList();

        assertNotNull("ATermList should not be null", list);

        FactInfoList rsfdl = new FactInfoList(list);

        assertNotNull("Constructed RStoreFactDataList from ATermList should not be null", rsfdl);

        int sizeOfListAfterConstruction = rsfdl.getFactInfos().size();

        assertEquals("Size of list after construction not correct", sizeOfListAfterConstruction, 2);

        list = null;
        rsfdl = null;
    }

    /**
     * Tests adding a FactInfo object to the list
     * 
     * @author Ricardo Lindooren
     * @date 2007-02-14
     */
    public void testAddFactInfoToList()
    {
        // First a destructive test
        RuntimeException rex = null;
        try
        {
            rStoreFactInfoListUnderTest.addFactInfoToList(null);
        }
        catch (RuntimeException ex)
        {
            rex = ex;
        }
        assertNotNull("Adding a null-FactInfo should throw a RuntimeException", rex);

        // Then the normal use tests

        // Add first time
        rStoreFactInfoListUnderTest.addFactInfoToList(rStoreFactInfoUsedForTests1);

        List<FactInfo> internalList = rStoreFactInfoListUnderTest.getFactInfos();

        assertNotNull("List<RStoreFactData> should not be null", internalList);

        assertEquals("Size of List should be 1 after one RStoreFactData has been added", 1, internalList.size());

        // Add second time
        rStoreFactInfoListUnderTest.addFactInfoToList(rStoreFactInfoUsedForTests1);

        assertEquals("Size of List should be 2 after second RStoreFactData has been added", 2, internalList.size());
    }

    /**
     * Simple getter test (only checks for not null)
     * 
     * @author Ricardo Lindooren
     * @date 2007-02-14
     */
    public void testGetRStoreFactIdentificationsList()
    {
        List<FactInfo> internalList = rStoreFactInfoListUnderTest.getFactInfos();

        assertNotNull("List<RStoreFactData> should not be null", internalList);
    }

    /**
     * 
     * @author Ricardo Lindooren
     * @date 2007-02-14
     */
    public void testToATermList()
    {
        // Add two RStoreFactData objects to list
        rStoreFactInfoListUnderTest.addFactInfoToList(rStoreFactInfoUsedForTests1);
        rStoreFactInfoListUnderTest.addFactInfoToList(rStoreFactInfoUsedForTests2);

        ATermList list = rStoreFactInfoListUnderTest.toATermList();

        if (log.isDebugEnabled())
            log.debug("AtermList created from RStoreFactDataList during test: \n\n\t"
                    + list.toString() + "\n");
    }
}
