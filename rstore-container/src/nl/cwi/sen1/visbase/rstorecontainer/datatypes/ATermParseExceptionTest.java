package nl.cwi.sen1.visbase.rstorecontainer.datatypes;

import junit.framework.TestCase;

/**
 * Used to test the ATermParseExceptionTest code
 *
 * @author Ricardo Lindooren
 * @date 2007-02-20
 */
public class ATermParseExceptionTest extends TestCase
{
    private final static String MESSAGE = "fakeMessage";

    private final static String MESSAGE2 = "fakeMessage2";

    public void testATermParseException()
    {
        ATermParseException rpe = new ATermParseException();

        assertNotNull(rpe);
    }

    public void testATermParseExceptionString()
    {
        ATermParseException rpe = new ATermParseException(MESSAGE);

        assertEquals(rpe.getMessage(), MESSAGE);
    }

    public void testATermParseExceptionStringThrowable()
    {
        ATermParseException rpe = null;
        Exception exp;

        try
        {
            throw new Exception(MESSAGE);
        }
        catch (Exception ex)
        {
            exp = ex;
            rpe = new ATermParseException(MESSAGE2, ex);
        }

        assertNotNull(rpe);

        assertEquals(rpe.getMessage(), MESSAGE2);

        assertEquals(rpe.getCause(), exp);

        assertEquals(rpe.getCause().getMessage(), MESSAGE);
    }

    public void testATermParseExceptionThrowable()
    {
        ATermParseException rpe = null;
        Exception exp;

        try
        {
            throw new Exception(MESSAGE);
        }
        catch (Exception ex)
        {
            exp = ex;
            rpe = new ATermParseException(ex);
        }

        assertNotNull(rpe);

        assertEquals(rpe.getCause(), exp);

        assertEquals(rpe.getCause().getMessage(), MESSAGE);
    }
}
