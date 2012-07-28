package nl.cwi.sen1.visbase.rstorecontainer.datatypes;

/**
 * Generic Exception for errors during parsing of ATerm data
 * 
 * @author Ricardo Lindooren
 * @date 2007-02-14
 * 
 */
public class ATermParseException extends Exception
{

    /**
     * 
     */
    private static final long serialVersionUID = 1L;

    public ATermParseException()
    {
        super();
    }

    public ATermParseException(String message)
    {
        super(message);
    }

    public ATermParseException(String message, Throwable cause)
    {
        super(message, cause);
    }

    public ATermParseException(Throwable cause)
    {
        super(cause);
    }
}
