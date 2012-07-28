package nl.cwi.sen1.relationstores.types;

abstract public class RTuple extends nl.cwi.sen1.relationstores.AbstractType {
  public RTuple(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(RTuple peer) {
    return super.isEqual(peer);
  }

  public boolean isSortRTuple()  {
    return true;
  }

  public boolean isRtuple() {
    return false;
  }

  public boolean hasVariable() {
    return false;
  }

  public boolean hasRtype() {
    return false;
  }

  public boolean hasValue() {
    return false;
  }

  public nl.cwi.sen1.relationstores.types.IdCon getVariable() {
     throw new UnsupportedOperationException("This RTuple has no Variable");
  }

  public RTuple setVariable(nl.cwi.sen1.relationstores.types.IdCon _variable) {
     throw new IllegalArgumentException("Illegal argument: " + _variable);
  }

  public nl.cwi.sen1.relationstores.types.RType getRtype() {
     throw new UnsupportedOperationException("This RTuple has no Rtype");
  }

  public RTuple setRtype(nl.cwi.sen1.relationstores.types.RType _rtype) {
     throw new IllegalArgumentException("Illegal argument: " + _rtype);
  }

  public nl.cwi.sen1.relationstores.types.RElem getValue() {
     throw new UnsupportedOperationException("This RTuple has no Value");
  }

  public RTuple setValue(nl.cwi.sen1.relationstores.types.RElem _value) {
     throw new IllegalArgumentException("Illegal argument: " + _value);
  }

}

