package nl.cwi.sen1.relationstores.types;

abstract public class RElem extends nl.cwi.sen1.relationstores.AbstractType {
  public RElem(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(RElem peer) {
    return super.isEqual(peer);
  }

  public boolean isSortRElem()  {
    return true;
  }

  public boolean isInt() {
    return false;
  }

  public boolean isStr() {
    return false;
  }

  public boolean isBool() {
    return false;
  }

  public boolean isLoc() {
    return false;
  }

  public boolean isSet() {
    return false;
  }

  public boolean isBag() {
    return false;
  }

  public boolean isTuple() {
    return false;
  }

  public boolean hasInteger() {
    return false;
  }

  public boolean hasStrCon() {
    return false;
  }

  public boolean hasBoolCon() {
    return false;
  }

  public boolean hasLocation() {
    return false;
  }

  public boolean hasElements() {
    return false;
  }

  public nl.cwi.sen1.relationstores.types.Integer getInteger() {
     throw new UnsupportedOperationException("This RElem has no Integer");
  }

  public RElem setInteger(nl.cwi.sen1.relationstores.types.Integer _Integer) {
     throw new IllegalArgumentException("Illegal argument: " + _Integer);
  }

  public String getStrCon() {
     throw new UnsupportedOperationException("This RElem has no StrCon");
  }

  public RElem setStrCon(String _StrCon) {
     throw new IllegalArgumentException("Illegal argument: " + _StrCon);
  }

  public nl.cwi.sen1.relationstores.types.BoolCon getBoolCon() {
     throw new UnsupportedOperationException("This RElem has no BoolCon");
  }

  public RElem setBoolCon(nl.cwi.sen1.relationstores.types.BoolCon _BoolCon) {
     throw new IllegalArgumentException("Illegal argument: " + _BoolCon);
  }

  public nl.cwi.sen1.relationstores.types.Location getLocation() {
     throw new UnsupportedOperationException("This RElem has no Location");
  }

  public RElem setLocation(nl.cwi.sen1.relationstores.types.Location _Location) {
     throw new IllegalArgumentException("Illegal argument: " + _Location);
  }

  public nl.cwi.sen1.relationstores.types.RElemElements getElements() {
     throw new UnsupportedOperationException("This RElem has no Elements");
  }

  public RElem setElements(nl.cwi.sen1.relationstores.types.RElemElements _elements) {
     throw new IllegalArgumentException("Illegal argument: " + _elements);
  }

}

