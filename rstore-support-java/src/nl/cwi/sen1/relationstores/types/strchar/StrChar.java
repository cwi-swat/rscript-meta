package nl.cwi.sen1.relationstores.types.strchar;

public class StrChar extends nl.cwi.sen1.relationstores.types.StrChar {
  public StrChar(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_string = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof StrChar) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeStrChar_StrChar(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isStrChar()
  {
    return true;
  }

  public boolean hasString() {
    return true;
  }

  public String getString() {
   return ((aterm.ATermAppl) getArgument(index_string)).getAFun().getName();
  }

  public nl.cwi.sen1.relationstores.types.StrChar setString(String _string) {
    return (nl.cwi.sen1.relationstores.types.StrChar) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_string, 0, true)), index_string);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a StrChar should have type str");
        }
        break;
      default: throw new RuntimeException("StrChar does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
