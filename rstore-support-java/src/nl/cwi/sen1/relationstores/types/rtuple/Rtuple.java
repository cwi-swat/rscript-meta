package nl.cwi.sen1.relationstores.types.rtuple;

public class Rtuple extends nl.cwi.sen1.relationstores.types.RTuple {
  public Rtuple(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_variable = 0;
  private static int index_rtype = 1;
  private static int index_value = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Rtuple) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeRTuple_Rtuple(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isRtuple()
  {
    return true;
  }

  public boolean hasVariable() {
    return true;
  }

  public boolean hasRtype() {
    return true;
  }

  public boolean hasValue() {
    return true;
  }

  public nl.cwi.sen1.relationstores.types.IdCon getVariable() {
    return (nl.cwi.sen1.relationstores.types.IdCon) getArgument(index_variable);
  }

  public nl.cwi.sen1.relationstores.types.RTuple setVariable(nl.cwi.sen1.relationstores.types.IdCon _variable) {
    return (nl.cwi.sen1.relationstores.types.RTuple) super.setArgument(_variable, index_variable);
  }

  public nl.cwi.sen1.relationstores.types.RType getRtype() {
    return (nl.cwi.sen1.relationstores.types.RType) getArgument(index_rtype);
  }

  public nl.cwi.sen1.relationstores.types.RTuple setRtype(nl.cwi.sen1.relationstores.types.RType _rtype) {
    return (nl.cwi.sen1.relationstores.types.RTuple) super.setArgument(_rtype, index_rtype);
  }

  public nl.cwi.sen1.relationstores.types.RElem getValue() {
    return (nl.cwi.sen1.relationstores.types.RElem) getArgument(index_value);
  }

  public nl.cwi.sen1.relationstores.types.RTuple setValue(nl.cwi.sen1.relationstores.types.RElem _value) {
    return (nl.cwi.sen1.relationstores.types.RTuple) super.setArgument(_value, index_value);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.relationstores.types.IdCon)) { 
          throw new RuntimeException("Argument 0 of a Rtuple should have type IdCon");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.relationstores.types.RType)) { 
          throw new RuntimeException("Argument 1 of a Rtuple should have type RType");
        }
        break;
      case 2:
        if (!(arg instanceof nl.cwi.sen1.relationstores.types.RElem)) { 
          throw new RuntimeException("Argument 2 of a Rtuple should have type RElem");
        }
        break;
      default: throw new RuntimeException("Rtuple does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(2).hashCode() << 16);
    a += (getArgument(1).hashCode() << 8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }

}
