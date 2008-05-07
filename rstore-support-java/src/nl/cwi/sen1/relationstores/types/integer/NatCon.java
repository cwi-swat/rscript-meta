package nl.cwi.sen1.relationstores.types.integer;

public class NatCon extends nl.cwi.sen1.relationstores.types.Integer {
  public NatCon(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_NatCon = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof NatCon) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeInteger_NatCon(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isNatCon()
  {
    return true;
  }

  public boolean hasNatCon() {
    return true;
  }

  public int getNatCon() {
   return ((aterm.ATermInt) getArgument(index_NatCon)).getInt();
  }

  public nl.cwi.sen1.relationstores.types.Integer setNatCon(int _NatCon) {
    return (nl.cwi.sen1.relationstores.types.Integer) super.setArgument(getFactory().makeInt(_NatCon), index_NatCon);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a NatCon should have type int");
        }
        break;
      default: throw new RuntimeException("NatCon does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
