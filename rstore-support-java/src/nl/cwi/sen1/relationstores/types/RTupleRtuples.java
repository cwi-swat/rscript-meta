package nl.cwi.sen1.relationstores.types;

public class RTupleRtuples extends nl.cwi.sen1.relationstores.AbstractList {
  private aterm.ATerm term = null;
  public RTupleRtuples(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof RTupleRtuples) {
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
      RTupleRtuples reversed = (RTupleRtuples)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortRTupleRtuples()  {
    return true;
  }

  public nl.cwi.sen1.relationstores.types.RTuple getHead() {
    return (nl.cwi.sen1.relationstores.types.RTuple)getFirst();
  }

  public RTupleRtuples getTail() {
    return (RTupleRtuples) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getRelationstoresFactory().makeRTupleRtuples();
  }

  public RTupleRtuples insert(nl.cwi.sen1.relationstores.types.RTuple head) {
    return getRelationstoresFactory().makeRTupleRtuples(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getRelationstoresFactory().makeRTupleRtuples(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getRelationstoresFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public RTupleRtuples reverseRTupleRtuples() {
    return getRelationstoresFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseRTupleRtuples();
  }

  public RTupleRtuples concat(RTupleRtuples peer) {
    return getRelationstoresFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((RTupleRtuples) peer);
  }

  public RTupleRtuples append(nl.cwi.sen1.relationstores.types.RTuple elem) {
    return getRelationstoresFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.relationstores.types.RTuple) elem);
  }

  public nl.cwi.sen1.relationstores.types.RTuple getRTupleAt(int index) {
    return (nl.cwi.sen1.relationstores.types.RTuple) elementAt(index);
  }

}
