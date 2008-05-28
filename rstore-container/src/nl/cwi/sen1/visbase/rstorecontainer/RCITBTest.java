package nl.cwi.sen1.visbase.rstorecontainer;

import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolStubNG;
import aterm.ATerm;
import aterm.ATermList;


/**
 * Unit test for testing the RStore Container Interface TB script.
 *
 * @author Arend van Beelen
 * @date 06-03-2007
 */
public class RCITBTest extends TUnitTestCase {

    /**
     * The function that contains the actual test case.
     *
      * @author Arend van Beelen
      * @date 06-03-2007
     */
    public void testMessages() {
        ToolStubNG rStoreContainer = new ToolStubNG("rStoreContainer", "localhost", getPort(), false);
        ToolStubNG rciTest = new ToolStubNG("rciTest", "localhost", getPort(), false);

        try {
            rStoreContainer.connect();
            rciTest.connect();

            // test values used in the messages
            String rStoreFile = "awesome.rstore";
            int rStoreId = 10;
            int factId = 16;

            // query for loading of an RStore
            ATerm rcLoadRStore = factory.make("rc-load-rstore(<str>)", rStoreFile);
            ATerm rcRStoreLoaded = factory.make("rc-rstore-loaded(<str>, <int>)", rStoreFile, new Integer(rStoreId));

            rciTest.sendEvent(rcLoadRStore);

            rStoreContainer.registerForEval(rcLoadRStore, rcRStoreLoaded);
            rStoreContainer.expectAction();

            rciTest.registerForDo(rcRStoreLoaded);
            rciTest.expectAction();

            // query for RStore facts
            ATermList emptyList = factory.makeList();
            ATerm rcGetRStoreFacts = factory.make("rc-get-rstore-facts(<int>)", new Integer(rStoreId));
            ATerm rcRStoreFacts = factory.make("rc-rstore-facts(<list>)", emptyList);
            ATerm rcGetRStoreFactsReply = factory.make("rc-get-rstore-facts(<int>, <list>)", new Integer(rStoreId), emptyList);

            rciTest.sendEvent(rcGetRStoreFacts);
            rStoreContainer.registerForEval(rcGetRStoreFacts, rcRStoreFacts);
            rStoreContainer.expectAction();

            rciTest.registerForDo(rcGetRStoreFactsReply);
            rciTest.expectAction();

            // query for fact data
            ATerm rcGetFactData = factory.make("rc-get-fact-data(<int>, <int>)", new Integer(rStoreId), new Integer(factId));
            ATerm rcFactData = factory.make("rc-fact-data(<term>)", emptyList);
            ATerm rcGetFactDataReply = factory.make("rc-get-fact-data(<int>, <int>, <term>)", new Integer(rStoreId), new Integer(factId), emptyList);

            rciTest.sendEvent(rcGetFactData);

            rStoreContainer.registerForEval(rcGetFactData, rcFactData);
            rStoreContainer.expectAction();

            rciTest.registerForDo(rcGetFactDataReply);
            rciTest.expectAction();
            
            rStoreContainer.waitForCompletion();
            rciTest.waitForCompletion();            
        } catch (Exception ex) {
            ex.printStackTrace();
            fail(ex.toString());
        } finally {
        	rStoreContainer.disconnect();
        	rciTest.disconnect();
        }
    }

    /**
     * Initialize the RCI process.
     *
     * @author Arend van Beelen
     * @date 06-03-2007
     */
    protected void setUp() {
    	String topSrcDir = ".";

        System.out.println(topSrcDir);
         
        try {
            startToolbus(topSrcDir + "/tbscript/", topSrcDir + "/tbscript/init.tb");
        }
        catch (Exception ex) {
        	ex.printStackTrace();
            stopToolbus();
            fail(ex.toString());
        }
    }

    /**
     * Clean up the allocated resources at the end of the test.
     *
     * @author Arend van Beelen
     * @date 06-03-2007
     */
    protected void tearDown() {
        stopToolbus();
    }
}
