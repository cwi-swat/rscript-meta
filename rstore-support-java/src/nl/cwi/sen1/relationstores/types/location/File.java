package nl.cwi.sen1.relationstores.types.location;

public class File extends nl.cwi.sen1.relationstores.types.Location {
  public File(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_filename = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof File) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getRelationstoresFactory().makeLocation_File(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getRelationstoresFactory().toTerm(this);
    }
    return term;
  }

  public boolean isFile()
  {
    return true;
  }

  public boolean hasFilename() {
    return true;
  }

  public String getFilename() {
   return ((aterm.ATermAppl) getArgument(index_filename)).getAFun().getName();
  }

  public nl.cwi.sen1.relationstores.types.Location setFilename(String _filename) {
    return (nl.cwi.sen1.relationstores.types.Location) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_filename, 0, true)), index_filename);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a File should have type str");
        }
        break;
      default: throw new RuntimeException("File does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
