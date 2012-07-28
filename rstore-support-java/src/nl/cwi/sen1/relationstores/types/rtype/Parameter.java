package nl.cwi.sen1.relationstores.types.rtype;

public class Parameter extends nl.cwi.sen1.relationstores.types.RType {
  public Parameter(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_parameterName = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Parameter) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeRType_Parameter(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isParameter()
  {
    return true;
  }

  public boolean hasParameterName() {
    return true;
  }

  public nl.cwi.sen1.relationstores.types.IdCon getParameterName() {
    return (nl.cwi.sen1.relationstores.types.IdCon) getArgument(index_parameterName);
  }

  public nl.cwi.sen1.relationstores.types.RType setParameterName(nl.cwi.sen1.relationstores.types.IdCon _parameterName) {
    return (nl.cwi.sen1.relationstores.types.RType) super.setArgument(_parameterName, index_parameterName);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.relationstores.types.IdCon)) { 
          throw new RuntimeException("Argument 0 of a Parameter should have type IdCon");
        }
        break;
      default: throw new RuntimeException("Parameter does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
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
