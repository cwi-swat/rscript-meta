package nl.cwi.sen1.relationstores;

abstract public class AbstractList extends aterm.pure.ATermListImpl {
  private nl.cwi.sen1.relationstores.Factory abstractTypeFactory;

  public AbstractList(nl.cwi.sen1.relationstores.Factory abstractTypeFactory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
    super(abstractTypeFactory.getPureFactory(), annos, first, next);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
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

  public boolean isEmpty() {
    return getFirst()==getEmpty().getFirst() && getNext()==getEmpty().getNext();
  }

  public boolean isMany() {
    return !isEmpty();
  }

  public boolean isSingle() {
    return !isEmpty() && getNext().isEmpty();
  }

  public boolean hasHead() {
    return !isEmpty();
  }

  public boolean hasTail() {
    return !isEmpty();
  }

}
