package nl.dancingbear.visbase.rstorecontainer;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.ArrayList;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RStore;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RTupleRtuples;
import nl.dancingbear.visbase.rstorecontainer.datatypes.FactInfo;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import aterm.ATerm;
import aterm.ATermInt;
import aterm.ATermList;
import aterm.pure.ATermApplImpl;
import aterm.pure.PureFactory;

/**
 * JUnit Testcase used to test RStoreContainer.
 * 
 * Some tests depend on the file.
 * 
 * @c simple_graph_test.rstore.
 * 
 * This file should be stored in the same package as this class.
 * 
 * @author Ricardo Lindooren
 * @author Arend van Beelen (reviewer)
 * @date 2007-02-13
 */
public class RStoreContainerTest extends TestCase {

    private RStoreContainer m_container;

    private static final Log m_log = LogFactory
            .getLog(RStoreContainerTest.class);

    private final static String NAME_OF_TESTFILE = "simple_graph_test.rstore";

    private final static String NAME_OF_UPDATED_TESTFILE = "simple_graph_test_updated.rstore";

    @Override
    protected void setUp() throws Exception {
        super.setUp();

        m_container = new RStoreContainer();
    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();

        m_container = null;
    }

    /**
     * Opens the reference to the Test File (DTF).
     * 
     * Creates an InputStream (IS) based on the DTF.
     * 
     * Reads bytes from the IS and prints these to System.out till there are no
     * more bytes left.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-13
     */
    public void testInputStreamFromFile() throws Exception {

        // destructive test, null input
        RuntimeException runtimeException = null;
        try {
            m_container.inputStreamFromFile(null);
        } catch (RuntimeException exception) {
            runtimeException = exception;
        }
        assertNotNull("Should throw RuntimeException when File input is null",
                runtimeException);

        // normal use test, using the testfile
        File testFile = getTestFile();
        assertNotNull("TestFile should not be null", testFile);
        assertTrue("TestFile should be readable", testFile.canRead());

        // create InputStream from File
        InputStream inputStream = m_container.inputStreamFromFile(testFile);
        assertNotNull("Inputstream created from file should not be null",
                inputStream);

        // Read InputStream
        InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
        assertNotNull(
                "InputStreamReader used to read InputStream should not be null",
                inputStreamReader);

        // read contents from input stream (bitwise and unbuffered, so this is
        // slow, but the testfile is small)
        int numBytesRead = -1;
        StringBuilder stringBuilder = new StringBuilder();
        while (true) {
            numBytesRead = inputStreamReader.read();

            if (numBytesRead == -1) {
                break;
            }

            stringBuilder.append((char) numBytesRead);
        }

        if (m_log.isDebugEnabled()) {
            m_log.debug("Data from InputStream: \n\n\t"
                    + stringBuilder.toString() + "\n");
        }

        inputStreamReader.close();
        inputStream.close();
    }

    /**
     * Parses the RStore data from the test file and checks the expected values.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testParseRstore() throws Exception {

        // destructive test, null input
        RuntimeException runtimeException = null;
        try {
            m_container.parseRStore(null);
        } catch (RuntimeException exception) {
            runtimeException = exception;
        }
        assertNotNull("Should throw RuntimeException when InputStream is null",
                runtimeException);

        // destrucive test, wrong InputStream
        RStoreParseException rpex = null;
        try {
            byte[] fakeByteArray = new byte[1];
            
            InputStream defectiveInputStream = new ByteArrayInputStream(fakeByteArray);
            m_container.parseRStore(defectiveInputStream);
        } catch (RStoreParseException exx) {
            rpex = exx;
        }
        assertNotNull("Should throw RStoreParseException when InputStream is not correct",
                rpex);
        
        // normal use test, using the testfile
        File testFile = getTestFile();
        assertTrue("TestFile should be readable", testFile.canRead());

        InputStream inputStream = m_container.inputStreamFromFile(testFile);
        assertNotNull("Inputstream created from file should not be null",
                inputStream);

        RStore parsedRStore = m_container.parseRStore(inputStream);
        assertNotNull("Parsed RStore should not be null", parsedRStore);

        RTupleRtuples rTuples = parsedRStore.getRtuples();
        assertEquals("There should be exactly one (1) RTuple in the test file",
                1, rTuples.getLength());

        RTuple rTuple = rTuples.getRTupleAt(0);
        assertNotNull("There should be a RTuple in the test file", rTuple);

        FactInfo factInfo = new FactInfo(1, rTuple);
        final String factName = factInfo.getName();
        assertEquals("Name of RTuple not equal to expected value",
                "SIMPLE_GRAPH", factName);

        final String relationType = factInfo.getType();
        assertEquals("Type of RTuple not equal to expected value",
                "relation([str,str])", relationType);

        RElem rElem_tupleValue = rTuple.getValue();
        assertNotNull("Value of RTuple should not be null", rElem_tupleValue);

        if (m_log.isDebugEnabled()) {
            // debug found values
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.append("\n\t" + "*RTuple name*\t= " + factName);
            stringBuilder.append("\n\t" + "*RTuple type*\t= " + relationType);
            stringBuilder.append("\n\t" + "*RTuple value*\t= "
                    + rElem_tupleValue);

            m_log.debug("Found RStore values:\n" + stringBuilder.toString()
                    + "\n");
        }
    }

    /**
     * Creates a RStore and tries to register it.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testRegisterRStore() throws Exception {

        // destructive test, null input
        RuntimeException runtimeException = null;
        try {
            m_container.registerRStore(null, null);
        } catch (RuntimeException exception) {
            runtimeException = exception;
        }
        assertNotNull("Should throw RuntimeException when File input is null",
                runtimeException);

        runtimeException = null;
        try {
            m_container.registerRStore(new File("bla"), null);
        } catch (RuntimeException exception) {
            runtimeException = exception;
        }
        assertNotNull(
                "Should throw RuntimeException when RStore input is null",
                runtimeException);

        File testFile = getTestFile();
        InputStream inputStream = m_container.inputStreamFromFile(testFile);
        assertNotNull("Inputstream created from file should not be null",
                inputStream);

        RStore parsedRStore = m_container.parseRStore(inputStream);

        // ---

        // destructive test, insert first element with key-value 2 (by not using
        // the registerRStore method)
        m_container.getLoadedRStoreTrackersMap().put(new Integer(2),
                new RStoreTracker(parsedRStore));
        int idForRstoreAfterIllegalInsert = m_container.registerRStore(
                testFile, parsedRStore);
        assertEquals(3, idForRstoreAfterIllegalInsert);

        // ---

        m_container.getLoadedRStoreTrackersMap().clear();
        m_container.getLoadedRStoreFilesMap().clear();

        // ---
        
        // Normal usage tests

        int rStoreId = m_container.registerRStore(testFile, parsedRStore);
        assertEquals("Id for RStore should be 1 after first time", 1, rStoreId);
        
        // register same RStore file again
        
        rStoreId = m_container.registerRStore(testFile, parsedRStore);
        assertEquals("Id for RStore should be 1 after second time", 1, rStoreId);
        assertEquals("Size of loadedRStoresMap should be 1", 1, m_container
                .getLoadedRStoreTrackersMap().size());
        
        // Register Updated RStore file (using the original filename but
        // modified RStore data)
        File updatedTestFile = getUpdatedTestFile();
        RStore updatedRStore = m_container.parseRStore(new FileInputStream(updatedTestFile));
        
        rStoreId = m_container.registerRStore(testFile, updatedRStore);
        assertEquals("Id for RStore should be 1 after updating", 1, rStoreId);
        assertEquals("Size of loadedRStoresMap should be 1", 1, m_container
                .getLoadedRStoreTrackersMap().size());
        
        // Register new RStore file (by faking a new filename)
        rStoreId = m_container.registerRStore(new File("fakeFileName"), parsedRStore);
        assertEquals("Id for RStore should be 2 after second time", 2, rStoreId);
        assertEquals("Size of loadedRStoresMap should be 2", 2, m_container
                .getLoadedRStoreTrackersMap().size());
    }

    /**
     * Very simple test to make sure that the Map containing the loaded RStores
     * is never null.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    public void testGetLoadedRStoresMap() {
        assertNotNull("The loaded RStoresMap should never be null", m_container
                .getLoadedRStoreTrackersMap());
    }

    /**
     * Tests the rcLoadRstore method without having an actual connection with
     * the Toolbus.
     * 
     * Input and output is processed in this test.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-20
     */
    public void testRcLoadRstoreWithoutToolbusConnection() {

        // destructive test with fake filename
        final String fakeFileName = "testWithFakeFileName";
        ATermApplImpl aTermApplImpl_response = (ATermApplImpl) m_container
                .rcLoadRstore(fakeFileName);
        ATermApplImpl aTermApplImpl_result = (ATermApplImpl) aTermApplImpl_response
                .getArgument(0);

        ATermApplImpl aTermApplImpl_fileName = (ATermApplImpl) aTermApplImpl_result
                .getArgument(0);
        ATermInt aTermInt_fileId = (ATermInt) aTermApplImpl_result
                .getArgument(1);

        assertEquals("Fake file name of RStore doesn't have expected value",
                aTermApplImpl_fileName.getName(), fakeFileName);
        assertEquals(
                "File identifier of RStore doesn't have expected value after supplying fake file name",
                aTermInt_fileId.getInt(), -1);

        // normal use test with real filename
        final String realFileName = getTestFile().toString();
        ATermApplImpl aTermApplImpl_response2 = (ATermApplImpl) m_container
                .rcLoadRstore(realFileName);
        ATermApplImpl aTermApplImpl_result2 = (ATermApplImpl) aTermApplImpl_response2
                .getArgument(0);

        ATermApplImpl aTermApplImpl_fileName2 = (ATermApplImpl) aTermApplImpl_result2
                .getArgument(0);
        ATermInt aTermInt_fileId2 = (ATermInt) aTermApplImpl_result2
                .getArgument(1);

        assertEquals("File name of RStore doesn't have expected value",
                aTermApplImpl_fileName2.getName(), realFileName);
        assertEquals(
                "FileIdentifier of RStore doesn't have expected value (it should be 1)",
                1, aTermInt_fileId2.getInt());
    }

    /**
     * Tests the rcGetRstoreFacts method without having an actual connection
     * with the Toolbus.
     * 
     * Input and output is processed in this test.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-20
     */
    public void testRcGetRstoreFactsWithoutToolbusConnection() {
        // destructive test with non-existing rstore-id
        ATermApplImpl aTermApplImpl_response = (ATermApplImpl) m_container
                .rcGetRstoreFacts(1);
        ATermApplImpl aTermList_result = (ATermApplImpl) aTermApplImpl_response
                .getArgument(0);
        ATermList aTermList_factInfos = (ATermList) aTermList_result
                .getArgument(0);

        assertEquals(
                "RStore Facts Info list should be empty if retrieving facts for non-existing RStore ",
                0, aTermList_factInfos.getLength());

        // normal use test, registering a real Rstore file first
        final String realFileName = getTestFile().toString();
        m_container.rcLoadRstore(realFileName);

        // get the facts for RStore with ID 1 (should exist)
        ATermApplImpl aTermApplImpl_response2 = (ATermApplImpl) m_container
                .rcGetRstoreFacts(1);
        ATermApplImpl aTermList_result2 = (ATermApplImpl) aTermApplImpl_response2
                .getArgument(0);
        ATermList aTermList_factInfos2 = (ATermList) aTermList_result2
                .getArgument(0);

        assertEquals(
                "RStore Facts Info list should contain one value (representing one fact) if retrieving facts for earlier registerd RStore",
                1, aTermList_factInfos2.getLength());

        ATermList atermList_factInfo = (ATermList) aTermList_factInfos2
                .elementAt(0);

        assertEquals(
                "RStore Fact Info list should contain three values (representing id, name and type) if retrieving facts for earlier registerd RStore",
                3, atermList_factInfo.getLength());
    }

    /**
     * Tests the rcGetFactData method without having an actual connection with
     * the Toolbus.
     * 
     * Input and output is processed in this test.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer + implemented assertions)
     * @date 2007-02-20
     */
    public void testRcGetFactDataWithoutToolbusConnection() {

        PureFactory pureFactory = RStoreContainer.getPureFactory();

        // destructive test with fake RStore id and fake Fact id
        ATerm expectedResult = pureFactory
                .parse("snd-value(rc-fact-data(set([tuple([str(\"\"),str(\"\")])])))");
        ATerm result = m_container.rcGetFactData(99, 3);
        assertEquals("Result should be a fake empty set", expectedResult,
                result);

        // normal use test, registering a real Rstore file first
        final String realFileName = getTestFile().toString();
        m_container.rcLoadRstore(realFileName);

        expectedResult = pureFactory
                .parse("snd-value(rc-fact-data(rtuple(\"SIMPLE_GRAPH\",relation([str,str]),set([tuple([str(\"a\"),str(\"b\")]),tuple([str(\"b\"),str(\"c\")]),tuple([str(\"b\"),str(\"d\")]),tuple([str(\"c\"),str(\"d\")])]))))");
        result = m_container.rcGetFactData(1, 1);
        assertEquals("Result should match set from test file", expectedResult,
                result);
    }

    /**
     * Tests the rcUnloadRstore method without having an actual connection with
     * the Toolbus.
     * 
     * Input and output is processed in this test.
     * 
     * @author Ricardo Lindooren
     * @date 2007-03-14
     */
    public void testRcUnLoadRstoreWithoutToolbusConnection() {

        // First destructive test (not exosting RStoreId)
        ATermApplImpl aTermApplImpl_fakeUnloadResponse = (ATermApplImpl) m_container.rcUnloadRstore(999);
        ATermApplImpl aTermApplImpl_fakeUnloadResponseResult = (ATermApplImpl) aTermApplImpl_fakeUnloadResponse.getArgument(0);
        ATermInt aTermInt_fakeUnloadedId1 = (ATermInt) aTermApplImpl_fakeUnloadResponseResult.getArgument(0);
        assertEquals("Returned value should be -1", -1, aTermInt_fakeUnloadedId1.getInt());
        
        // Normal usage tests
        final String realFileName = getTestFile().toString();
        ATermApplImpl aTermApplImpl_response1 = (ATermApplImpl) m_container
                .rcLoadRstore(realFileName);
        ATermApplImpl aTermApplImpl_result1 = (ATermApplImpl) aTermApplImpl_response1
                .getArgument(0);

        ATermApplImpl aTermApplImpl_fileName1 = (ATermApplImpl) aTermApplImpl_result1
                .getArgument(0);
        ATermInt aTermInt_fileId1 = (ATermInt) aTermApplImpl_result1
                .getArgument(1);

        assertEquals("File name of RStore doesn't have expected value",
                aTermApplImpl_fileName1.getName(), realFileName);
        assertEquals(
                "FileIdentifier of RStore doesn't have expected value (it should be 1)",
                1, aTermInt_fileId1.getInt());
        
        // Do the unloading
        ATermApplImpl aTermApplImpl_unloadResponse = (ATermApplImpl) m_container.rcUnloadRstore(aTermInt_fileId1.getInt());
        ATermApplImpl aTermApplImpl_unloadResponseResult = (ATermApplImpl) aTermApplImpl_unloadResponse.getArgument(0);
        ATermInt aTermInt_unloadedId1 = (ATermInt) aTermApplImpl_unloadResponseResult.getArgument(0);
        
        assertEquals("The ID of the unloaded RStore is not correct", aTermInt_fileId1.getInt(), aTermInt_unloadedId1.getInt());
        
        assertEquals("The loaded RStoreFilesMap should be empty after unloading the only RStore", 0, m_container.getLoadedRStoreFilesMap().size());
        assertEquals("The loaded RStoreTrackersMap should be empty after unloading the only RStore", 0, m_container.getLoadedRStoreTrackersMap().size());
    }
    
    /**
     * Tests the constructor that is used to make a connection with the ToolBus.
     * 
     * Because there is no Toolbus process available this test is used to test
     * the try-catch blocks surrounding the connection initialization code.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-20
     */
    public void testToolbusConstructorWithoutToolbusConnection() {
        String[] fakeArgs = { "" };
        new RStoreContainer(fakeArgs);
    }

    /**
     * Tests the static main method that is called by the ToolBus Java
     * connector.
     * 
     * Because there is no Toolbus process it will not really connect with the
     * Toolbus.
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-20
     */
    public void testMainWithoutToolbusConnection() {
        String[] fakeArgs = { "fakeArg1", "fakeArg2" };
        RStoreContainer.main(fakeArgs);
        
        RStoreContainer.main(null);
    }

    /**
     * Only calls the recTerminate method
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-20
     */
    public void testRecTerminateWithoutToolbusConnection() {
        m_container.recTerminate(null);
    }

    /**
     * Very simple test to make sure that the Factory is never null
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-14
     */
    @SuppressWarnings("static-access")
    public void testGetPureFactory() {
        assertNotNull("The PureFactory should never be null", m_container
                .getPureFactory());
    }

    /**
     * Returns a File reference to a test file.
     * 
     * The test file is stored in the same package as this file.
     * 
     * @return the test file
     * 
     * @author Ricardo Lindooren
     * @author Arend van Beelen (reviewer)
     * @date 2007-02-13
     */
    private File getTestFile() {

        StringBuilder stringBuilder = new StringBuilder();

        Package packageOfThisClass = this.getClass().getPackage();

        if (packageOfThisClass != null) {

            String packageName = packageOfThisClass.getName();
            if (packageName != null) {

                packageName = packageName.replaceAll("\\.", "/");

                stringBuilder.append("/");
                stringBuilder.append(packageName);
                stringBuilder.append("/");
            }
        }

        stringBuilder.append(NAME_OF_TESTFILE);

        URL url = this.getClass().getResource(stringBuilder.toString());

        File testFile = null;
        try {
            testFile = new File(url.toURI());
        } catch (URISyntaxException exception) {
            exception.printStackTrace();
        }

        return testFile;
    }

     /**
         * Returns a File reference to a test file that is a updated version of
         * the default test file.
         * 
         * The updated test file is stored in the same package as this file.
         * 
         * @see #getTestFile()
         * 
         * @return the updated test file
         * 
         * @author Ricardo Lindooren
         * @date 2007-03-13
         */
    private File getUpdatedTestFile() {

        StringBuilder stringBuilder = new StringBuilder();

        Package packageOfThisClass = this.getClass().getPackage();

        if (packageOfThisClass != null) {

            String packageName = packageOfThisClass.getName();
            if (packageName != null) {

                packageName = packageName.replaceAll("\\.", "/");

                stringBuilder.append("/");
                stringBuilder.append(packageName);
                stringBuilder.append("/");
            }
        }

        stringBuilder.append(NAME_OF_UPDATED_TESTFILE);

        URL url = this.getClass().getResource(stringBuilder.toString());

        File testFile = null;
        try {
            testFile = new File(url.toURI());
        } catch (URISyntaxException exception) {
            exception.printStackTrace();
        }

        return testFile;
    }
    
    /**
     * Simple getter test
     * 
     * @author Ricardo Lindooren
     * @Date 2007-03-14
     */
    public void testGetName()
    {
        assertEquals("rStoreContainer",m_container.getName());
    }
    
    /**
     * Only tests null input exceptions
     * 
     * @author Ricardo Lindooren
     * @Date 2007-03-14
     */
    public void testSendFactUpdatedEvents()
    {
        RuntimeException rex = null;
        try{
            m_container.sendFactUpdatedEvents(null, new ArrayList<Integer>());
        }
        catch(RuntimeException ex){
            rex = ex;
        }
        
        assertNotNull(rex);
        
        rex = null;
        
        try{
            m_container.sendFactUpdatedEvents(new Integer(1), null);
        }
        catch(RuntimeException ex){
            rex = ex;
        }
        
        assertNotNull(rex);
    }
}
