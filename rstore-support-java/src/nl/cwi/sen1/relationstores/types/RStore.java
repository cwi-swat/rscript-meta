package nl.cwi.sen1.relationstores.types;

abstract public class RStore extends nl.cwi.sen1.relationstores.AbstractType {
  public RStore(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(RStore peer) {
    return super.isEqual(peer);
  }

  public boolean isSortRStore()  {
    return true;
  }

  public boolean isRstore() {
    return false;
  }

  public boolean hasRtuples() {
    return false;
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples getRtuples() {
     throw new UnsupportedOperationException("This RStore has no Rtuples");
  }

  public RStore setRtuples(nl.cwi.sen1.relationstores.types.RTupleRtuples _rtuples) {
     throw new IllegalArgumentException("Illegal argument: " + _rtuples);
  }

}

