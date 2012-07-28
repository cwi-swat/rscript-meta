package nl.cwi.sen1.relationstores.types;

abstract public class Integer extends nl.cwi.sen1.relationstores.AbstractType {
  public Integer(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Integer peer) {
    return super.isEqual(peer);
  }

  public boolean isSortInteger()  {
    return true;
  }

  public boolean isNatCon() {
    return false;
  }

  public boolean isPositive() {
    return false;
  }

  public boolean isNegative() {
    return false;
  }

  public boolean hasNatCon() {
    return false;
  }

  public boolean hasInteger() {
    return false;
  }

  public int getNatCon() {
     throw new UnsupportedOperationException("This Integer has no NatCon");
  }

  public Integer setNatCon(int _NatCon) {
     throw new IllegalArgumentException("Illegal argument: " + _NatCon);
  }

  public nl.cwi.sen1.relationstores.types.Integer getInteger() {
     throw new UnsupportedOperationException("This Integer has no Integer");
  }

  public Integer setInteger(nl.cwi.sen1.relationstores.types.Integer _integer) {
     throw new IllegalArgumentException("Illegal argument: " + _integer);
  }

}

