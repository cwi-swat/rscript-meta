package nl.cwi.sen1.relationstores.types.strcon;

public class StrCon extends nl.cwi.sen1.relationstores.types.StrCon {
  public StrCon(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_string = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof StrCon) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeStrCon_StrCon(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isStrCon()
  {
    return true;
  }

  public boolean hasString() {
    return true;
  }

  public String getString() {
   return ((aterm.ATermAppl) getArgument(index_string)).getAFun().getName();
  }

  public nl.cwi.sen1.relationstores.types.StrCon setString(String _string) {
    return (nl.cwi.sen1.relationstores.types.StrCon) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_string, 0, true)), index_string);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a StrCon should have type str");
        }
        break;
      default: throw new RuntimeException("StrCon does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
