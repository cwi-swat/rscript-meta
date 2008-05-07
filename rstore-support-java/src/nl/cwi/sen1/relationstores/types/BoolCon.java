package nl.cwi.sen1.relationstores.types;

abstract public class BoolCon extends nl.cwi.sen1.relationstores.AbstractType {
  public BoolCon(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(BoolCon peer) {
    return super.isEqual(peer);
  }

  public boolean isSortBoolCon()  {
    return true;
  }

  public boolean isTrue() {
    return false;
  }

  public boolean isFalse() {
    return false;
  }

}

