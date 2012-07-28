package nl.cwi.sen1.relationstores;

abstract public class AbstractType extends aterm.pure.ATermApplImpl {
  protected aterm.ATerm term;

  private nl.cwi.sen1.relationstores.Factory abstractTypeFactory;

  public AbstractType(nl.cwi.sen1.relationstores.Factory abstractTypeFactory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(abstractTypeFactory.getPureFactory(), annos, fun, args);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
  }

  protected void setTerm(aterm.ATerm term) {
    this.term = term;
  }

  public nl.cwi.sen1.relationstores.Factory getRelationstoresFactory() {
    return abstractTypeFactory;
  }

  public boolean isSortRElem() {
    return false;
  }

  public boolean isSortRType() {
    return false;
  }

  public boolean isSortRTuple() {
    return false;
  }

  public boolean isSortRStore() {
    return false;
  }

  public boolean isSortIdCon() {
    return false;
  }

  public boolean isSortRElemElements() {
    return false;
  }

  public boolean isSortRTypeColumnTypes() {
    return false;
  }

  public boolean isSortRTupleRtuples() {
    return false;
  }

  public boolean isSortStrChar() {
    return false;
  }

  public boolean isSortStrCon() {
    return false;
  }

  public boolean isSortBoolCon() {
    return false;
  }

  public boolean isSortNatCon() {
    return false;
  }

  public boolean isSortInteger() {
    return false;
  }

  public boolean isSortLocation() {
    return false;
  }

  public boolean isSortArea() {
    return false;
  }

}
