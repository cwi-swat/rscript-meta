package nl.cwi.sen1.relationstores.types;

abstract public class IdCon extends nl.cwi.sen1.relationstores.AbstractType {
  public IdCon(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(IdCon peer) {
    return super.isEqual(peer);
  }

  public boolean isSortIdCon()  {
    return true;
  }

  public boolean isDefault() {
    return false;
  }

  public boolean isIdCon() {
    return false;
  }

  public boolean hasString() {
    return false;
  }

  public String getString() {
     throw new UnsupportedOperationException("This IdCon has no String");
  }

  public IdCon setString(String _string) {
     throw new IllegalArgumentException("Illegal argument: " + _string);
  }

}

