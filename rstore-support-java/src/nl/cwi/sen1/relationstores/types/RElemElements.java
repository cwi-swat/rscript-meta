package nl.cwi.sen1.relationstores.types;

public class RElemElements extends nl.cwi.sen1.relationstores.AbstractList {
  private aterm.ATerm term = null;
  public RElemElements(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof RElemElements) {
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
      RElemElements reversed = (RElemElements)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortRElemElements()  {
    return true;
  }

  public nl.cwi.sen1.relationstores.types.RElem getHead() {
    return (nl.cwi.sen1.relationstores.types.RElem)getFirst();
  }

  public RElemElements getTail() {
    return (RElemElements) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getRelationstoresFactory().makeRElemElements();
  }

  public RElemElements insert(nl.cwi.sen1.relationstores.types.RElem head) {
    return getRelationstoresFactory().makeRElemElements(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getRelationstoresFactory().makeRElemElements(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getRelationstoresFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public RElemElements reverseRElemElements() {
    return getRelationstoresFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseRElemElements();
  }

  public RElemElements concat(RElemElements peer) {
    return getRelationstoresFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((RElemElements) peer);
  }

  public RElemElements append(nl.cwi.sen1.relationstores.types.RElem elem) {
    return getRelationstoresFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.relationstores.types.RElem) elem);
  }

  public nl.cwi.sen1.relationstores.types.RElem getRElemAt(int index) {
    return (nl.cwi.sen1.relationstores.types.RElem) elementAt(index);
  }

}
