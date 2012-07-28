package nl.cwi.sen1.visbase.rstorecontainer;

/**
 * @author Ricardo Lindooren
 * @author Arend van Beelen (reviewer)
 * @date 2007-02-14
 */
public class RStoreParseException extends Exception {

    private static final long serialVersionUID = 1L;

    public RStoreParseException() {
        super();
    }

    public RStoreParseException(String message) {
        super(message);
    }

    public RStoreParseException(String message, Throwable cause) {
        super(message, cause);
    }

    public RStoreParseException(Throwable cause) {
        super(cause);
    }
}
