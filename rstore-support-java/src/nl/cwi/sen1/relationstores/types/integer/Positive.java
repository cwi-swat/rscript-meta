package nl.cwi.sen1.relationstores.types.integer;

public class Positive extends nl.cwi.sen1.relationstores.types.Integer {
  public Positive(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_integer = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Positive) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeInteger_Positive(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isPositive()
  {
    return true;
  }

  public boolean hasInteger() {
    return true;
  }

  public nl.cwi.sen1.relationstores.types.Integer getInteger() {
    return (nl.cwi.sen1.relationstores.types.Integer) getArgument(index_integer);
  }

  public nl.cwi.sen1.relationstores.types.Integer setInteger(nl.cwi.sen1.relationstores.types.Integer _integer) {
    return (nl.cwi.sen1.relationstores.types.Integer) super.setArgument(_integer, index_integer);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.relationstores.types.Integer)) { 
          throw new RuntimeException("Argument 0 of a Positive should have type Integer");
        }
        break;
      default: throw new RuntimeException("Positive does not have an argument at " + i );
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
