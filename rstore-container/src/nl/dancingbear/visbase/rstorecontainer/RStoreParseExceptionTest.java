package nl.dancingbear.visbase.rstorecontainer;

import junit.framework.TestCase;

/**
 * Used to test the RStoreParseExceptionTest code
 *
 * @author Ricardo Lindooren
 * @author Arend van Beelen (reviewer)
 * @date 2007-02-20
 */
public class RStoreParseExceptionTest extends TestCase {

    private final static String MESSAGE = "fakeMessage";
    private final static String MESSAGE2 = "fakeMessage2";

    public void testRStoreParseException() {
        RStoreParseException rpe = new RStoreParseException();
        assertNotNull(rpe);
    }

    public void testRStoreParseExceptionString() {
        RStoreParseException rpe = new RStoreParseException(MESSAGE);
        assertEquals(MESSAGE, rpe.getMessage());
    }

    public void testRStoreParseExceptionStringThrowable() {
        RStoreParseException rpe = null;
        Exception exp;

        try {
            throw new Exception(MESSAGE);
        } catch (Exception ex) {
            exp = ex;
            rpe = new RStoreParseException(MESSAGE2, ex);
        }

        assertNotNull(rpe);
        assertEquals(MESSAGE2, rpe.getMessage());
        assertEquals(exp, rpe.getCause());
        assertEquals(MESSAGE, rpe.getCause().getMessage());
    }

    public void testRStoreParseExceptionThrowable() {
        RStoreParseException rpe = null;
        Exception exp;

        try {
            throw new Exception(MESSAGE);
        } catch (Exception ex) {
            exp = ex;
            rpe = new RStoreParseException(ex);
        }

        assertNotNull(rpe);
        assertEquals(exp, rpe.getCause());
        assertEquals(MESSAGE, rpe.getCause().getMessage());
    }
}
