package nl.cwi.sen1.relationstores.types.relem;

public class Bool extends nl.cwi.sen1.relationstores.types.RElem {
  public Bool(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_BoolCon = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Bool) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeRElem_Bool(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isBool()
  {
    return true;
  }

  public boolean hasBoolCon() {
    return true;
  }

  public nl.cwi.sen1.relationstores.types.BoolCon getBoolCon() {
    return (nl.cwi.sen1.relationstores.types.BoolCon) getArgument(index_BoolCon);
  }

  public nl.cwi.sen1.relationstores.types.RElem setBoolCon(nl.cwi.sen1.relationstores.types.BoolCon _BoolCon) {
    return (nl.cwi.sen1.relationstores.types.RElem) super.setArgument(_BoolCon, index_BoolCon);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.relationstores.types.BoolCon)) { 
          throw new RuntimeException("Argument 0 of a Bool should have type BoolCon");
        }
        break;
      default: throw new RuntimeException("Bool does not have an argument at " + i );
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
