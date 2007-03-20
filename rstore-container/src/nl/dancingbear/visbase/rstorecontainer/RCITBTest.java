package nl.dancingbear.visbase.rstorecontainer;

import java.io.File;
import java.net.URL;

import nl.dancingbear.tunit.StackTraceUtil;
import nl.dancingbear.tunit.TUnitTestCase;
import nl.dancingbear.tunit.ToolStub;
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
        try {
            ToolStub rStoreContainer = createToolStub("rStoreContainer");
            ToolStub rciTest = createToolStub("rciTest");

            connectToolStubs();

            // test values used in the messages
            String rStoreFile = "awesome.rstore";
            int rStoreId = 10;
            int factId = 16;

            // query for loading of an RStore
            ATerm rcLoadRStore = factory.make("rc-load-rstore(<str>)", rStoreFile);
            ATerm rcRStoreLoaded = factory.make("rc-rstore-loaded(<str>, <int>)", rStoreFile, rStoreId);

            rciTest.sendEvent(rcLoadRStore);
            rciTest.expectAckEvent(rcLoadRStore, 3000);

            rStoreContainer.expectEval(rcLoadRStore, 3000);
            rStoreContainer.sendValue(rcRStoreLoaded);

            rciTest.expectDo(rcRStoreLoaded, 3000);

            // query for RStore facts
            ATermList emptyList = factory.makeList();
            ATerm rcGetRStoreFacts = factory.make("rc-get-rstore-facts(<int>)", rStoreId);
            ATerm rcRStoreFacts = factory.make("rc-rstore-facts(<list>)", emptyList);
            ATerm rcGetRStoreFactsReply = factory.make("rc-get-rstore-facts(<int>, <list>)", rStoreId, emptyList);

            rciTest.sendEvent(rcGetRStoreFacts);
            rciTest.expectAckEvent(rcGetRStoreFacts, 3000);

            rStoreContainer.expectEval(rcGetRStoreFacts, 3000);
            rStoreContainer.sendValue(rcRStoreFacts);

            rciTest.expectDo(rcGetRStoreFactsReply, 3000);

            // query for fact data
            ATerm rcGetFactData = factory.make("rc-get-fact-data(<int>, <int>)", rStoreId, factId);
            ATerm rcFactData = factory.make("rc-fact-data(<term>)", emptyList);
            ATerm rcGetFactDataReply = factory.make("rc-get-fact-data(<int>, <int>, <term>)", rStoreId, factId, emptyList);

            rciTest.sendEvent(rcGetFactData);
            rciTest.expectAckEvent(rcGetFactData, 3000);

            rStoreContainer.expectEval(rcGetFactData, 3000);
            rStoreContainer.sendValue(rcFactData);

            rciTest.expectDo(rcGetFactDataReply, 3000);

            disconnectToolStubs();
        } catch (Exception ex) {
            System.out.println(StackTraceUtil.getStackTrace(ex));
            fail(ex.toString());
        }
    }

    /**
     * Initialize the RCI process.
     *
     * @author Arend van Beelen
     * @date 06-03-2007
     */
    protected void setUp() {
        try {
            URL url = this.getClass().getResource("/tbscript/init.tb");

            File file = new File(url.toURI());

            this.startToolbus(file.getParent(), url.getPath(), 7000);
        } catch (Exception exception) {
            System.out.println(StackTraceUtil.getStackTrace(exception));
            stopToolbus();
            fail(exception.toString());
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
