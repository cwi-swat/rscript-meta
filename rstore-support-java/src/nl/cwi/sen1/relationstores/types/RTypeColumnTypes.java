package nl.cwi.sen1.relationstores.types;

public class RTypeColumnTypes extends nl.cwi.sen1.relationstores.AbstractList {
  private aterm.ATerm term = null;
  public RTypeColumnTypes(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof RTypeColumnTypes) {
      return super.equivalent(peer);
    }
    return false;
  }

  public shared.SharedObject duplicate() {
    return this;
  }

  public aterm.ATerm toTerm() {
    aterm.ATermFactory atermFactory = getRelationstoresFactory().getPureFactory();
    if (this.term == null) {
      RTypeColumnTypes reversed = (RTypeColumnTypes)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortRTypeColumnTypes()  {
    return true;
  }

  public nl.cwi.sen1.relationstores.types.RType getHead() {
    return (nl.cwi.sen1.relationstores.types.RType)getFirst();
  }

  public RTypeColumnTypes getTail() {
    return (RTypeColumnTypes) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getRelationstoresFactory().makeRTypeColumnTypes();
  }

  public RTypeColumnTypes insert(nl.cwi.sen1.relationstores.types.RType head) {
    return getRelationstoresFactory().makeRTypeColumnTypes(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getRelationstoresFactory().makeRTypeColumnTypes(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getRelationstoresFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public RTypeColumnTypes reverseRTypeColumnTypes() {
    return getRelationstoresFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseRTypeColumnTypes();
  }

  public RTypeColumnTypes concat(RTypeColumnTypes peer) {
    return getRelationstoresFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((RTypeColumnTypes) peer);
  }

  public RTypeColumnTypes append(nl.cwi.sen1.relationstores.types.RType elem) {
    return getRelationstoresFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.relationstores.types.RType) elem);
  }

  public nl.cwi.sen1.relationstores.types.RType getRTypeAt(int index) {
    return (nl.cwi.sen1.relationstores.types.RType) elementAt(index);
  }

}
