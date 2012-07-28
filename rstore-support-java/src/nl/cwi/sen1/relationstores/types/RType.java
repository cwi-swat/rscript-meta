package nl.cwi.sen1.relationstores.types;

abstract public class RType extends nl.cwi.sen1.relationstores.AbstractType {
  public RType(nl.cwi.sen1.relationstores.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(RType peer) {
    return super.isEqual(peer);
  }

  public boolean isSortRType()  {
    return true;
  }

  public boolean isInt() {
    return false;
  }

  public boolean isBool() {
    return false;
  }

  public boolean isStr() {
    return false;
  }

  public boolean isLoc() {
    return false;
  }

  public boolean isTuple() {
    return false;
  }

  public boolean isSet() {
    return false;
  }

  public boolean isBag() {
    return false;
  }

  public boolean isRelation() {
    return false;
  }

  public boolean isUserDefined() {
    return false;
  }

  public boolean isParameter() {
    return false;
  }

  public boolean hasColumnTypes() {
    return false;
  }

  public boolean hasElementType() {
    return false;
  }

  public boolean hasTypeName() {
    return false;
  }

  public boolean hasParameterName() {
    return false;
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes getColumnTypes() {
     throw new UnsupportedOperationException("This RType has no ColumnTypes");
  }

  public RType setColumnTypes(nl.cwi.sen1.relationstores.types.RTypeColumnTypes _columnTypes) {
     throw new IllegalArgumentException("Illegal argument: " + _columnTypes);
  }

  public nl.cwi.sen1.relationstores.types.RType getElementType() {
     throw new UnsupportedOperationException("This RType has no ElementType");
  }

  public RType setElementType(nl.cwi.sen1.relationstores.types.RType _elementType) {
     throw new IllegalArgumentException("Illegal argument: " + _elementType);
  }

  public nl.cwi.sen1.relationstores.types.IdCon getTypeName() {
     throw new UnsupportedOperationException("This RType has no TypeName");
  }

  public RType setTypeName(nl.cwi.sen1.relationstores.types.IdCon _typeName) {
     throw new IllegalArgumentException("Illegal argument: " + _typeName);
  }

  public nl.cwi.sen1.relationstores.types.IdCon getParameterName() {
     throw new UnsupportedOperationException("This RType has no ParameterName");
  }

  public RType setParameterName(nl.cwi.sen1.relationstores.types.IdCon _parameterName) {
     throw new IllegalArgumentException("Illegal argument: " + _parameterName);
  }

}

