package nl.cwi.sen1.relationstores.types.relem;

public class Str extends nl.cwi.sen1.relationstores.types.RElem {
  public Str(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_StrCon = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Str) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeRElem_Str(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isStr()
  {
    return true;
  }

  public boolean hasStrCon() {
    return true;
  }

  public String getStrCon() {
   return ((aterm.ATermAppl) getArgument(index_StrCon)).getAFun().getName();
  }

  public nl.cwi.sen1.relationstores.types.RElem setStrCon(String _StrCon) {
    return (nl.cwi.sen1.relationstores.types.RElem) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_StrCon, 0, true)), index_StrCon);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Str should have type str");
        }
        break;
      default: throw new RuntimeException("Str does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
