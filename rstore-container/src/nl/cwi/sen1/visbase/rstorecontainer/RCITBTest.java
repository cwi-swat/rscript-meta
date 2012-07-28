package nl.cwi.sen1.visbase.rstorecontainer;

import nl.cwi.sen1.tunit.TUnitTestCase;
import nl.cwi.sen1.tunit.ToolComValidator;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;


/**
 * Unit test for testing the RStore Container Interface TB script.
 *
 * @author Arend van Beelen
 * @date 06-03-2007
 */
public class RCITBTest extends TUnitTestCase {

    /**
     * The function that contains the actual test case.
     */
    public void testMessages() {
    	RStoreContainerTool rStoreContainerTool = new RStoreContainerTool(this, "rStoreContainer", true);
    	RCITool rciTool = new RCITool(this, "rciTest", true);
    	
    	Thread rStoreToolExecutor = new Thread(rStoreContainerTool);
    	rStoreToolExecutor.setDaemon(true);
    	rStoreToolExecutor.start();
    	Thread rciToolExecutor = new Thread(rciTool);
    	rciToolExecutor.setDaemon(true);
    	rciToolExecutor.start();
    	
    	toolbus.waitTillShutdown();
    	
    	if(hasFailed()) fail();
        
        System.out.println("Test Passed");
    }
    
    private static class RStoreContainerTool extends ToolComValidator{
    	private final TUnitTestCase testCase;
    	
    	public RStoreContainerTool(TUnitTestCase testCase, String name, boolean verbose){
    		super(testCase, name, verbose);
    		
    		this.testCase = testCase;
    	}
    	
    	public void run(){
    		try{
    			testCase.connectToolComValidator(this);
    			
    			PureFactory factory = getFactory();
    			
    			int rStoreId = 10;
                String rStoreFile = "awesome.rstore";
                ATerm rcLoadRStore = factory.make("rc-load-rstore(<str>)", rStoreFile);
                ATerm rcRStoreLoaded = factory.make("rc-rstore-loaded(<str>, <int>)", rStoreFile, new Integer(rStoreId));

                registerForEval(rcLoadRStore, rcRStoreLoaded);
                expectAction();
                
                ATermList emptyList = factory.makeList();
                ATerm rcGetRStoreFacts = factory.make("rc-get-rstore-facts(<int>)", new Integer(rStoreId));
                ATerm rcRStoreFacts = factory.make("rc-rstore-facts(<list>)", emptyList);

                registerForEval(rcGetRStoreFacts, rcRStoreFacts);
                expectAction();

                int factId = 16;
                ATerm rcGetFactData = factory.make("rc-get-fact-data(<int>, <int>)", new Integer(rStoreId), new Integer(factId));
                ATerm rcFactData = factory.make("rc-fact-data(<term>)", emptyList);
                
                registerForEval(rcGetFactData, rcFactData);
                expectAction();
    		}catch(Exception ex){
    			ex.printStackTrace();
    		}finally{
    			disconnect();
    		}
    	}
    }
    
    private static class RCITool extends ToolComValidator{
    	private final TUnitTestCase testCase;
    	
    	public RCITool(TUnitTestCase testCase, String name, boolean verbose){
    		super(testCase, name, verbose);
    		
    		this.testCase = testCase;
    	}
    	
    	public void run(){
    		try{
    			testCase.connectToolComValidator(this);
    			
    			PureFactory factory = getFactory();
    			
                String rStoreFile = "awesome.rstore";
                ATerm rcLoadRStore = factory.make("rc-load-rstore(<str>)", rStoreFile);
    			
                sendEvent(rcLoadRStore);

                int rStoreId = 10;
                ATerm rcRStoreLoaded = factory.make("rc-rstore-loaded(<str>, <int>)", rStoreFile, new Integer(rStoreId));
                
                registerForDo(rcRStoreLoaded);
                expectAction();

                ATerm rcGetRStoreFacts = factory.make("rc-get-rstore-facts(<int>)", new Integer(rStoreId));
                
                sendEvent(rcGetRStoreFacts);

                ATermList emptyList = factory.makeList();
                ATerm rcGetRStoreFactsReply = factory.make("rc-get-rstore-facts(<int>, <list>)", new Integer(rStoreId), emptyList);
                
                registerForDo(rcGetRStoreFactsReply);
                expectAction();
                
                int factId = 16;
                ATerm rcGetFactData = factory.make("rc-get-fact-data(<int>, <int>)", new Integer(rStoreId), new Integer(factId));
                
                sendEvent(rcGetFactData);

                ATerm rcGetFactDataReply = factory.make("rc-get-fact-data(<int>, <int>, <term>)", new Integer(rStoreId), new Integer(factId), emptyList);
                
                registerForDo(rcGetFactDataReply);
                expectAction();

                waitForCompletion();   
    		}catch(Exception ex){
    			ex.printStackTrace();
    		}finally{
    			disconnect();
    		}
    	}
    }

    /**
     * Initialize the RCI process.
     */
    protected void setUp(){
        try{
            startToolbus("./tbscript/", "./tbscript/init.tb");
        }catch(Exception ex){
        	ex.printStackTrace();
            stopToolbus();
            fail(ex.toString());
        }
    }

    /**
     * Clean up the allocated resources at the end of the test.
     */
    protected void tearDown(){
        stopToolbus();
    }
}
