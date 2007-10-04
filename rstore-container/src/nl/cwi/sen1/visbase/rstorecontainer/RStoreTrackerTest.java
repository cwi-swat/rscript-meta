package nl.cwi.sen1.visbase.rstorecontainer;

import junit.framework.TestCase;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.IdCon;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RStore;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RTupleRtuples;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.RTypeColumnTypes;
import nl.cwi.sen1.relationstores.types.relem.Tuple;
import nl.cwi.sen1.visbase.rstorecontainer.datatypes.FactInfoList;
import aterm.pure.PureFactory;

/**
 * Tests the code of the RStore Tracker
 * 
 * @Date 2007-03-13
 * @author Ricardo Lindooren
 */
public class RStoreTrackerTest extends TestCase {

    // private RStoreTracker rStoreTrackerUnderTest;

    public RStoreTrackerTest(String arg0) {
        super(arg0);
    }

    @Override
    protected void setUp() throws Exception {
        super.setUp();
    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();
    }

    /**
     * Tests the code of the constructor
     * 
     * @Date 2007-03-13
     * @author Ricardo Lindooren
     */
    public void testRStoreTracker() {

        // First a destructive test, null-input
        RuntimeException rex = null;
        try {
            new RStoreTracker(null);
        } catch (RuntimeException ex) {
            rex = ex;
        }
        assertNotNull(
                "Using the constructor with null-input should throw a RuntimeException",
                rex);

        RStoreTracker rStoreTracker = new RStoreTracker(createSimpleRStore());
        assertNotNull("Newly created RStoreTracker should not be null",
                rStoreTracker);
    }

    /**
     * <b>TODO</b>
     * 
     * @Date 2007-03-13
     * @author Ricardo Lindooren
     */
    public void testUpdate() {

        RStoreTracker rStoreTracker = new RStoreTracker(createSimpleRStore());

        rStoreTracker.update(createUpdatedRStore());

        // TODO
    }

    /**
     * Simple getter test
     * 
     * @Date 2007-03-13
     * @author Ricardo Lindooren
     */
    public void testGetRStore() {
        RStoreTracker rStoreTracker = new RStoreTracker(createSimpleRStore());

        assertNotNull("RStore object should not be null", rStoreTracker
                .getRStore());
    }

    /**
     * Simple getter test
     * 
     * @Date 2007-03-13
     * @author Ricardo Lindooren
     */
    public void testGetRTuple() {
        RStoreTracker rStoreTracker = new RStoreTracker(createSimpleRStore());

        assertNotNull("There should be a RTuple associated with id 1",
                rStoreTracker.getRTuple(1));

        assertNull("There shouldn't be a RTuple associated with id 2",
                rStoreTracker.getRTuple(2));
    }

    /**
     * Tests the code used for retrieving a FactInfoList based on the RStore in
     * the Tracker
     * 
     * @Date 2007-03-13
     * @author Ricardo Lindooren
     */
    public void testGetFactInfoFromRStore() {
        RStoreTracker rStoreTracker = new RStoreTracker(createUpdatedRStore());

        FactInfoList fil = rStoreTracker.getFactInfoFromRStore();

        assertNotNull("The FactInfoList should not be null", fil);

        assertEquals(
                "The FactInfoList should contain two FactInfo objects when created based on the updated RStore",
                2, fil.getFactInfos().size());
    }

    /**
     * Tests the code used to determine if two RTuples differ from eachother
     * 
     * @Date 2007-03-13
     * @author Ricardo Lindooren
     */
    public void testDiffRtuples() {
        RStore simpleRStoreA = createSimpleRStore();

        RTuple rTupleA1 = simpleRStoreA.getRtuples().getRTupleAt(0);

        // First destructive tests (null-input)
        RuntimeException rex = null;
        try {
            RStoreTracker.diffRtuples(null, rTupleA1);
        } catch (RuntimeException ex) {
            rex = ex;
        }
        assertNotNull(
                "Using diffRtuples with null-input should throw a RuntimeException",
                rex);
        
        rex = null;
        try {
            RStoreTracker.diffRtuples(rTupleA1, null);
        } catch (RuntimeException ex) {
            rex = ex;
        }
        assertNotNull(
                "Using diffRtuples with null-input should throw a RuntimeException",
                rex);

        // Normal usage tests
        RStore simpleRStoreB = createSimpleRStore();

        RTuple rTupleB1 = simpleRStoreB.getRtuples().getRTupleAt(0);

        boolean areDifferent = RStoreTracker.diffRtuples(rTupleA1, rTupleB1);

        assertFalse("RTuples should be equal", areDifferent);

        RStore updatedRStoreC = createUpdatedRStore();

        RTuple rTupleC1 = updatedRStoreC.getRtuples().getRTupleAt(0);

        areDifferent = RStoreTracker.diffRtuples(rTupleA1, rTupleC1);

        assertTrue("RTuples should not be equal", areDifferent);
    }

     /*
     * Test method for
     *
     'nl.cwi.sen1.visbase.rstorecontainer.RStoreTracker.registerNewRTuple(RTuple)'
     */
     public void testRegisterNewRTuple() {

         RStoreTracker rStoreTracker = new RStoreTracker(createSimpleRStore());
         
         // First a destructive test, null-input
         RuntimeException rex = null;
         try {
             rStoreTracker.registerNewRTuple(null);
         } catch (RuntimeException ex) {
             rex = ex;
         }
         assertNotNull(
                 "Using registerNewRTuple with null-input should throw a RuntimeException",
                 rex);
     }

    /**
     * Tests the code that is used to generate an textual identifier for a
     * RTuple
     * 
     * @author Ricardo Lindooren
     * @Date 2007-03-13
     */
    public void testCreateIdentifierForRTuple() {
        // First a destructive test (null-input)
        RuntimeException rex = null;
        try {
            RStoreTracker.createIdentifierForRTuple(null);
        } catch (RuntimeException ex) {
            rex = ex;
        }
        assertNotNull(
                "Using createIdentifierForRTupler with null-input should throw a RuntimeException",
                rex);

        // Normal usage test
        RStore simpleRStoreA = createSimpleRStore();

        RTuple rTupleA1 = simpleRStoreA.getRtuples().getRTupleAt(0);

        final String identifier = RStoreTracker
                .createIdentifierForRTuple(rTupleA1);

        assertEquals("CYCLIC_GRAPH-relation([str,str])", identifier);
    }

    /**
     * Creates a simple RStore.
     * 
     * Using coding example from the WIKI
     * (http://www.renarj.nl/metatrac/wiki/RStores)
     * 
     * @author Ricardo Lindooren
     * @Date 2007-03-13
     * 
     * @return the generated simple RStore
     */
    private RStore createSimpleRStore() {
        PureFactory pureFactory = RStoreContainer.getPureFactory();
        Factory factory = Factory.getInstance(pureFactory);

        IdCon idCon = factory.makeIdCon_IdCon("CYCLIC_GRAPH");
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

        RTupleRtuples rTupleRtuples = factory.makeRTupleRtuples(rTuple);
        RStore rstore = factory.makeRStore_Rstore(rTupleRtuples);

        return rstore;
    }

    /**
     * Creates an updated version of the simple RStore.
     * 
     * @see #createSimpleRStore()
     * 
     * Using coding example from the WIKI
     * (http://www.renarj.nl/metatrac/wiki/RStores)
     * 
     * @author Ricardo Lindooren
     * @Date 2007-03-13
     * 
     * @return the generated updated RStore
     */
    private RStore createUpdatedRStore() {
        PureFactory pureFactory = RStoreContainer.getPureFactory();
        Factory factory = Factory.getInstance(pureFactory);

        IdCon idCon = factory.makeIdCon_IdCon("CYCLIC_GRAPH");
        RElem a = factory.makeRElem_Str("a");
        RElem b = factory.makeRElem_Str("b");
        RElem c = factory.makeRElem_Str("c");
        RElem d = factory.makeRElem_Str("d");
        RElem e = factory.makeRElem_Str("e"); //

        RType stringType = factory.makeRType_Str();
        RTypeColumnTypes rTypeColumnTypes = factory.makeRTypeColumnTypes(
                stringType, stringType);
        RType rType = factory.makeRType_Relation(rTypeColumnTypes);
        Tuple ab = factory.makeRElem_Tuple(factory.makeRElemElements(a, b));
        Tuple bc = factory.makeRElem_Tuple(factory.makeRElemElements(b, c));
        Tuple cd = factory.makeRElem_Tuple(factory.makeRElemElements(c, d));
        Tuple da = factory.makeRElem_Tuple(factory.makeRElemElements(d, a));

        Tuple de = factory.makeRElem_Tuple(factory.makeRElemElements(d, e));
        // RElem rElem = factory.makeRElem_Set(factory.makeRElemElements(ab, bc,
        // cd, da));
        RElem rElem = factory.makeRElem_Set(factory.makeRElemElements(ab, bc,
                cd, da, de));
        RTuple rTuple = factory.makeRTuple_Rtuple(idCon, rType, rElem);

        // ---

        IdCon idCon2 = factory.makeIdCon_IdCon("CYCLIC_GRAPH2");
        RElem x = factory.makeRElem_Str("x");
        RElem y = factory.makeRElem_Str("y");
        RElem z = factory.makeRElem_Str("z");

        RTypeColumnTypes rTypeColumnTypes2 = factory.makeRTypeColumnTypes(
                stringType, stringType);
        RType rType2 = factory.makeRType_Relation(rTypeColumnTypes2);

        Tuple xy = factory.makeRElem_Tuple(factory.makeRElemElements(x, y));
        Tuple xz = factory.makeRElem_Tuple(factory.makeRElemElements(x, z));
        Tuple zy = factory.makeRElem_Tuple(factory.makeRElemElements(z, y));

        RElem rElem2 = factory.makeRElem_Set(factory.makeRElemElements(xy, xz,
                zy));
        RTuple rTuple2 = factory.makeRTuple_Rtuple(idCon2, rType2, rElem2);

        // ---

        RTupleRtuples rTupleRtuples = factory
                .makeRTupleRtuples(rTuple, rTuple2);
        RStore rstore = factory.makeRStore_Rstore(rTupleRtuples);

        return rstore;
    }
}
