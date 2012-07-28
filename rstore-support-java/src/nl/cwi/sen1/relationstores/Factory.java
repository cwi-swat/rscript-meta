package nl.cwi.sen1.relationstores;

public class Factory {
  private aterm.pure.PureFactory factory;


  private aterm.AFun fun_RElem_Int;
  private aterm.ATerm pattern_RElem_Int;
  private aterm.AFun fun_RElem_Str;
  private aterm.ATerm pattern_RElem_Str;
  private aterm.AFun fun_RElem_Bool;
  private aterm.ATerm pattern_RElem_Bool;
  private aterm.AFun fun_RElem_Loc;
  private aterm.ATerm pattern_RElem_Loc;
  private aterm.AFun fun_RElem_Set;
  private aterm.ATerm pattern_RElem_Set;
  private aterm.AFun fun_RElem_Bag;
  private aterm.ATerm pattern_RElem_Bag;
  private aterm.AFun fun_RElem_Tuple;
  private aterm.ATerm pattern_RElem_Tuple;

  private aterm.AFun fun_RType_Int;
  private aterm.ATerm pattern_RType_Int;
  private aterm.AFun fun_RType_Bool;
  private aterm.ATerm pattern_RType_Bool;
  private aterm.AFun fun_RType_Str;
  private aterm.ATerm pattern_RType_Str;
  private aterm.AFun fun_RType_Loc;
  private aterm.ATerm pattern_RType_Loc;
  private aterm.AFun fun_RType_Tuple;
  private aterm.ATerm pattern_RType_Tuple;
  private aterm.AFun fun_RType_Set;
  private aterm.ATerm pattern_RType_Set;
  private aterm.AFun fun_RType_Bag;
  private aterm.ATerm pattern_RType_Bag;
  private aterm.AFun fun_RType_Relation;
  private aterm.ATerm pattern_RType_Relation;
  private aterm.AFun fun_RType_UserDefined;
  private aterm.ATerm pattern_RType_UserDefined;
  private aterm.AFun fun_RType_Parameter;
  private aterm.ATerm pattern_RType_Parameter;

  private aterm.AFun fun_RTuple_Rtuple;
  private aterm.ATerm pattern_RTuple_Rtuple;

  private aterm.AFun fun_RStore_Rstore;
  private aterm.ATerm pattern_RStore_Rstore;

  private aterm.AFun fun_IdCon_Default;
  private aterm.ATerm pattern_IdCon_Default;
  private aterm.AFun fun_IdCon_IdCon;
  private aterm.ATerm pattern_IdCon_IdCon;




  private aterm.AFun fun_StrChar_StrChar;
  private aterm.ATerm pattern_StrChar_StrChar;

  private aterm.AFun fun_StrCon_StrCon;
  private aterm.ATerm pattern_StrCon_StrCon;

  private aterm.AFun fun_BoolCon_True;
  private aterm.ATerm pattern_BoolCon_True;
  private aterm.AFun fun_BoolCon_False;
  private aterm.ATerm pattern_BoolCon_False;

  private aterm.AFun fun_NatCon_NatCon;
  private aterm.ATerm pattern_NatCon_NatCon;

  private aterm.AFun fun_Integer_NatCon;
  private aterm.ATerm pattern_Integer_NatCon;
  private aterm.AFun fun_Integer_Positive;
  private aterm.ATerm pattern_Integer_Positive;
  private aterm.AFun fun_Integer_Negative;
  private aterm.ATerm pattern_Integer_Negative;

  private aterm.AFun fun_Location_File;
  private aterm.ATerm pattern_Location_File;
  private aterm.AFun fun_Location_Area;
  private aterm.ATerm pattern_Location_Area;
  private aterm.AFun fun_Location_AreaInFile;
  private aterm.ATerm pattern_Location_AreaInFile;

  private aterm.AFun fun_Area_Area;
  private aterm.ATerm pattern_Area_Area;

  private nl.cwi.sen1.relationstores.types.RElemElements empty_RElemElements;
  private nl.cwi.sen1.relationstores.types.RTypeColumnTypes empty_RTypeColumnTypes;
  private nl.cwi.sen1.relationstores.types.RTupleRtuples empty_RTupleRtuples;

  private Factory(aterm.pure.PureFactory factory) {
    this.factory = factory;
  }

  private static Factory instance = null;

  public synchronized static Factory getInstance(aterm.pure.PureFactory factory) {
    if (instance == null) {
        instance = new Factory(factory);
        instance.initialize();
    }
    if (instance.factory != factory) {
        throw new RuntimeException("Don't create two Factory factories with differents PureFactory ");
    }
    return instance;
  }

  public aterm.pure.PureFactory getPureFactory() {
    return factory;
  }

  private void initialize() {

    pattern_RElem_Int = factory.parse("int(<term>)");
    fun_RElem_Int = factory.makeAFun("_RElem_int", 1, false);

    pattern_RElem_Str = factory.parse("str(<str>)");
    fun_RElem_Str = factory.makeAFun("_RElem_str", 1, false);

    pattern_RElem_Bool = factory.parse("bool(<term>)");
    fun_RElem_Bool = factory.makeAFun("_RElem_bool", 1, false);

    pattern_RElem_Loc = factory.parse("loc(<term>)");
    fun_RElem_Loc = factory.makeAFun("_RElem_loc", 1, false);

    pattern_RElem_Set = factory.parse("set(<term>)");
    fun_RElem_Set = factory.makeAFun("_RElem_set", 1, false);

    pattern_RElem_Bag = factory.parse("bag(<term>)");
    fun_RElem_Bag = factory.makeAFun("_RElem_bag", 1, false);

    pattern_RElem_Tuple = factory.parse("tuple(<term>)");
    fun_RElem_Tuple = factory.makeAFun("_RElem_tuple", 1, false);

    pattern_RType_Int = factory.parse("int");
    fun_RType_Int = factory.makeAFun("_RType_int", 0, false);

    pattern_RType_Bool = factory.parse("bool");
    fun_RType_Bool = factory.makeAFun("_RType_bool", 0, false);

    pattern_RType_Str = factory.parse("str");
    fun_RType_Str = factory.makeAFun("_RType_str", 0, false);

    pattern_RType_Loc = factory.parse("loc");
    fun_RType_Loc = factory.makeAFun("_RType_loc", 0, false);

    pattern_RType_Tuple = factory.parse("tuple(<term>)");
    fun_RType_Tuple = factory.makeAFun("_RType_tuple", 1, false);

    pattern_RType_Set = factory.parse("set(<term>)");
    fun_RType_Set = factory.makeAFun("_RType_set", 1, false);

    pattern_RType_Bag = factory.parse("bag(<term>)");
    fun_RType_Bag = factory.makeAFun("_RType_bag", 1, false);

    pattern_RType_Relation = factory.parse("relation(<term>)");
    fun_RType_Relation = factory.makeAFun("_RType_relation", 1, false);

    pattern_RType_UserDefined = factory.parse("user-defined(<term>)");
    fun_RType_UserDefined = factory.makeAFun("_RType_user-defined", 1, false);

    pattern_RType_Parameter = factory.parse("parameter(<term>)");
    fun_RType_Parameter = factory.makeAFun("_RType_parameter", 1, false);

    pattern_RTuple_Rtuple = factory.parse("rtuple(<term>,<term>,<term>)");
    fun_RTuple_Rtuple = factory.makeAFun("_RTuple_rtuple", 3, false);

    pattern_RStore_Rstore = factory.parse("rstore(<term>)");
    fun_RStore_Rstore = factory.makeAFun("_RStore_rstore", 1, false);

    pattern_IdCon_Default = factory.parse("Default");
    fun_IdCon_Default = factory.makeAFun("_IdCon_Default", 0, false);

    pattern_IdCon_IdCon = factory.parse("<str>");
    fun_IdCon_IdCon = factory.makeAFun("_IdCon_IdCon", 1, false);

    empty_RElemElements = (nl.cwi.sen1.relationstores.types.RElemElements) factory.build(new nl.cwi.sen1.relationstores.types.RElemElements(this, factory.getEmpty(), null, null));
    empty_RTypeColumnTypes = (nl.cwi.sen1.relationstores.types.RTypeColumnTypes) factory.build(new nl.cwi.sen1.relationstores.types.RTypeColumnTypes(this, factory.getEmpty(), null, null));
    empty_RTupleRtuples = (nl.cwi.sen1.relationstores.types.RTupleRtuples) factory.build(new nl.cwi.sen1.relationstores.types.RTupleRtuples(this, factory.getEmpty(), null, null));
    pattern_StrChar_StrChar = factory.parse("<str>");
    fun_StrChar_StrChar = factory.makeAFun("_StrChar_StrChar", 1, false);

    pattern_StrCon_StrCon = factory.parse("<str>");
    fun_StrCon_StrCon = factory.makeAFun("_StrCon_StrCon", 1, false);

    pattern_BoolCon_True = factory.parse("true");
    fun_BoolCon_True = factory.makeAFun("_BoolCon_true", 0, false);

    pattern_BoolCon_False = factory.parse("false");
    fun_BoolCon_False = factory.makeAFun("_BoolCon_false", 0, false);

    pattern_NatCon_NatCon = factory.parse("<str>");
    fun_NatCon_NatCon = factory.makeAFun("_NatCon_NatCon", 1, false);

    pattern_Integer_NatCon = factory.parse("nat-con(<int>)");
    fun_Integer_NatCon = factory.makeAFun("_Integer_nat-con", 1, false);

    pattern_Integer_Positive = factory.parse("positive(<term>)");
    fun_Integer_Positive = factory.makeAFun("_Integer_positive", 1, false);

    pattern_Integer_Negative = factory.parse("negative(<term>)");
    fun_Integer_Negative = factory.makeAFun("_Integer_negative", 1, false);

    pattern_Location_File = factory.parse("file(<str>)");
    fun_Location_File = factory.makeAFun("_Location_file", 1, false);

    pattern_Location_Area = factory.parse("area(<term>)");
    fun_Location_Area = factory.makeAFun("_Location_area", 1, false);

    pattern_Location_AreaInFile = factory.parse("area-in-file(<str>,<term>)");
    fun_Location_AreaInFile = factory.makeAFun("_Location_area-in-file", 2, false);

    pattern_Area_Area = factory.parse("area(<int>,<int>,<int>,<int>,<int>,<int>)");
    fun_Area_Area = factory.makeAFun("_Area_area", 6, false);

  }

/*genAlternativeMethods*/
  public nl.cwi.sen1.relationstores.types.relem.Int makeRElem_Int(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.relem.Int) factory.build( new nl.cwi.sen1.relationstores.types.relem.Int(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.relem.Int makeRElem_Int(nl.cwi.sen1.relationstores.types.Integer _Integer) {
    aterm.ATerm[] args = new aterm.ATerm[] {_Integer};
    return makeRElem_Int(fun_RElem_Int, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RElem RElem_IntFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RElem_Int);

    if (children != null) {
      return makeRElem_Int(
        IntegerFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.relem.Int arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getInteger().toTerm());
    return factory.make(pattern_RElem_Int, args);
  }

  public nl.cwi.sen1.relationstores.types.relem.Str makeRElem_Str(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.relem.Str) factory.build( new nl.cwi.sen1.relationstores.types.relem.Str(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.relem.Str makeRElem_Str(String _StrCon) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_StrCon, 0, true))};
    return makeRElem_Str(fun_RElem_Str, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RElem RElem_StrFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RElem_Str);

    if (children != null) {
      return makeRElem_Str(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.relem.Str arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getStrCon());
    return factory.make(pattern_RElem_Str, args);
  }

  public nl.cwi.sen1.relationstores.types.relem.Bool makeRElem_Bool(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.relem.Bool) factory.build( new nl.cwi.sen1.relationstores.types.relem.Bool(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.relem.Bool makeRElem_Bool(nl.cwi.sen1.relationstores.types.BoolCon _BoolCon) {
    aterm.ATerm[] args = new aterm.ATerm[] {_BoolCon};
    return makeRElem_Bool(fun_RElem_Bool, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RElem RElem_BoolFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RElem_Bool);

    if (children != null) {
      return makeRElem_Bool(
        BoolConFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.relem.Bool arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getBoolCon().toTerm());
    return factory.make(pattern_RElem_Bool, args);
  }

  public nl.cwi.sen1.relationstores.types.relem.Loc makeRElem_Loc(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.relem.Loc) factory.build( new nl.cwi.sen1.relationstores.types.relem.Loc(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.relem.Loc makeRElem_Loc(nl.cwi.sen1.relationstores.types.Location _Location) {
    aterm.ATerm[] args = new aterm.ATerm[] {_Location};
    return makeRElem_Loc(fun_RElem_Loc, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RElem RElem_LocFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RElem_Loc);

    if (children != null) {
      return makeRElem_Loc(
        LocationFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.relem.Loc arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLocation().toTerm());
    return factory.make(pattern_RElem_Loc, args);
  }

  public nl.cwi.sen1.relationstores.types.relem.Set makeRElem_Set(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.relem.Set) factory.build( new nl.cwi.sen1.relationstores.types.relem.Set(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.relem.Set makeRElem_Set(nl.cwi.sen1.relationstores.types.RElemElements _elements) {
    aterm.ATerm[] args = new aterm.ATerm[] {_elements};
    return makeRElem_Set(fun_RElem_Set, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RElem RElem_SetFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RElem_Set);

    if (children != null) {
      return makeRElem_Set(
        RElemElementsFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.relem.Set arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getElements().toTerm());
    return factory.make(pattern_RElem_Set, args);
  }

  public nl.cwi.sen1.relationstores.types.relem.Bag makeRElem_Bag(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.relem.Bag) factory.build( new nl.cwi.sen1.relationstores.types.relem.Bag(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.relem.Bag makeRElem_Bag(nl.cwi.sen1.relationstores.types.RElemElements _elements) {
    aterm.ATerm[] args = new aterm.ATerm[] {_elements};
    return makeRElem_Bag(fun_RElem_Bag, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RElem RElem_BagFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RElem_Bag);

    if (children != null) {
      return makeRElem_Bag(
        RElemElementsFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.relem.Bag arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getElements().toTerm());
    return factory.make(pattern_RElem_Bag, args);
  }

  public nl.cwi.sen1.relationstores.types.relem.Tuple makeRElem_Tuple(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.relem.Tuple) factory.build( new nl.cwi.sen1.relationstores.types.relem.Tuple(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.relem.Tuple makeRElem_Tuple(nl.cwi.sen1.relationstores.types.RElemElements _elements) {
    aterm.ATerm[] args = new aterm.ATerm[] {_elements};
    return makeRElem_Tuple(fun_RElem_Tuple, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RElem RElem_TupleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RElem_Tuple);

    if (children != null) {
      return makeRElem_Tuple(
        RElemElementsFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.relem.Tuple arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getElements().toTerm());
    return factory.make(pattern_RElem_Tuple, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Int makeRType_Int(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Int) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Int(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Int makeRType_Int() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeRType_Int(fun_RType_Int, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_IntFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Int);

    if (children != null) {
      return makeRType_Int(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Int arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_RType_Int, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Bool makeRType_Bool(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Bool) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Bool(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Bool makeRType_Bool() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeRType_Bool(fun_RType_Bool, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_BoolFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Bool);

    if (children != null) {
      return makeRType_Bool(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Bool arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_RType_Bool, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Str makeRType_Str(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Str) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Str(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Str makeRType_Str() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeRType_Str(fun_RType_Str, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_StrFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Str);

    if (children != null) {
      return makeRType_Str(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Str arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_RType_Str, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Loc makeRType_Loc(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Loc) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Loc(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Loc makeRType_Loc() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeRType_Loc(fun_RType_Loc, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_LocFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Loc);

    if (children != null) {
      return makeRType_Loc(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Loc arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_RType_Loc, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Tuple makeRType_Tuple(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Tuple) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Tuple(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Tuple makeRType_Tuple(nl.cwi.sen1.relationstores.types.RTypeColumnTypes _columnTypes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_columnTypes};
    return makeRType_Tuple(fun_RType_Tuple, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_TupleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Tuple);

    if (children != null) {
      return makeRType_Tuple(
        RTypeColumnTypesFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Tuple arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getColumnTypes().toTerm());
    return factory.make(pattern_RType_Tuple, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Set makeRType_Set(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Set) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Set(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Set makeRType_Set(nl.cwi.sen1.relationstores.types.RType _elementType) {
    aterm.ATerm[] args = new aterm.ATerm[] {_elementType};
    return makeRType_Set(fun_RType_Set, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_SetFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Set);

    if (children != null) {
      return makeRType_Set(
        RTypeFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Set arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getElementType().toTerm());
    return factory.make(pattern_RType_Set, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Bag makeRType_Bag(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Bag) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Bag(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Bag makeRType_Bag(nl.cwi.sen1.relationstores.types.RType _elementType) {
    aterm.ATerm[] args = new aterm.ATerm[] {_elementType};
    return makeRType_Bag(fun_RType_Bag, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_BagFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Bag);

    if (children != null) {
      return makeRType_Bag(
        RTypeFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Bag arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getElementType().toTerm());
    return factory.make(pattern_RType_Bag, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Relation makeRType_Relation(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Relation) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Relation(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Relation makeRType_Relation(nl.cwi.sen1.relationstores.types.RTypeColumnTypes _columnTypes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_columnTypes};
    return makeRType_Relation(fun_RType_Relation, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_RelationFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Relation);

    if (children != null) {
      return makeRType_Relation(
        RTypeColumnTypesFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Relation arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getColumnTypes().toTerm());
    return factory.make(pattern_RType_Relation, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.UserDefined makeRType_UserDefined(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.UserDefined) factory.build( new nl.cwi.sen1.relationstores.types.rtype.UserDefined(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.UserDefined makeRType_UserDefined(nl.cwi.sen1.relationstores.types.IdCon _typeName) {
    aterm.ATerm[] args = new aterm.ATerm[] {_typeName};
    return makeRType_UserDefined(fun_RType_UserDefined, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_UserDefinedFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_UserDefined);

    if (children != null) {
      return makeRType_UserDefined(
        IdConFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.UserDefined arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getTypeName().toTerm());
    return factory.make(pattern_RType_UserDefined, args);
  }

  public nl.cwi.sen1.relationstores.types.rtype.Parameter makeRType_Parameter(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtype.Parameter) factory.build( new nl.cwi.sen1.relationstores.types.rtype.Parameter(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtype.Parameter makeRType_Parameter(nl.cwi.sen1.relationstores.types.IdCon _parameterName) {
    aterm.ATerm[] args = new aterm.ATerm[] {_parameterName};
    return makeRType_Parameter(fun_RType_Parameter, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RType RType_ParameterFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RType_Parameter);

    if (children != null) {
      return makeRType_Parameter(
        IdConFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtype.Parameter arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getParameterName().toTerm());
    return factory.make(pattern_RType_Parameter, args);
  }

  public nl.cwi.sen1.relationstores.types.rtuple.Rtuple makeRTuple_Rtuple(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rtuple.Rtuple) factory.build( new nl.cwi.sen1.relationstores.types.rtuple.Rtuple(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rtuple.Rtuple makeRTuple_Rtuple(nl.cwi.sen1.relationstores.types.IdCon _variable, nl.cwi.sen1.relationstores.types.RType _rtype, nl.cwi.sen1.relationstores.types.RElem _value) {
    aterm.ATerm[] args = new aterm.ATerm[] {_variable, _rtype, _value};
    return makeRTuple_Rtuple(fun_RTuple_Rtuple, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RTuple RTuple_RtupleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RTuple_Rtuple);

    if (children != null) {
      return makeRTuple_Rtuple(
        IdConFromTerm((aterm.ATerm) children.get(0)),
        RTypeFromTerm((aterm.ATerm) children.get(1)),
        RElemFromTerm((aterm.ATerm) children.get(2))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rtuple.Rtuple arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getVariable().toTerm());
    args.add(arg.getRtype().toTerm());
    args.add(arg.getValue().toTerm());
    return factory.make(pattern_RTuple_Rtuple, args);
  }

  public nl.cwi.sen1.relationstores.types.rstore.Rstore makeRStore_Rstore(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.rstore.Rstore) factory.build( new nl.cwi.sen1.relationstores.types.rstore.Rstore(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.rstore.Rstore makeRStore_Rstore(nl.cwi.sen1.relationstores.types.RTupleRtuples _rtuples) {
    aterm.ATerm[] args = new aterm.ATerm[] {_rtuples};
    return makeRStore_Rstore(fun_RStore_Rstore, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.RStore RStore_RstoreFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_RStore_Rstore);

    if (children != null) {
      return makeRStore_Rstore(
        RTupleRtuplesFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.rstore.Rstore arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getRtuples().toTerm());
    return factory.make(pattern_RStore_Rstore, args);
  }

  public nl.cwi.sen1.relationstores.types.idcon.Default makeIdCon_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.idcon.Default) factory.build( new nl.cwi.sen1.relationstores.types.idcon.Default(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.idcon.Default makeIdCon_Default() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeIdCon_Default(fun_IdCon_Default, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.IdCon IdCon_DefaultFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_IdCon_Default);

    if (children != null) {
      return makeIdCon_Default(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.idcon.Default arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_IdCon_Default, args);
  }

  public nl.cwi.sen1.relationstores.types.idcon.IdCon makeIdCon_IdCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.idcon.IdCon) factory.build( new nl.cwi.sen1.relationstores.types.idcon.IdCon(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.idcon.IdCon makeIdCon_IdCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeIdCon_IdCon(fun_IdCon_IdCon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.IdCon IdCon_IdConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_IdCon_IdCon);

    if (children != null) {
      return makeIdCon_IdCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.idcon.IdCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_IdCon_IdCon, args);
  }

  public nl.cwi.sen1.relationstores.types.strchar.StrChar makeStrChar_StrChar(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.strchar.StrChar) factory.build( new nl.cwi.sen1.relationstores.types.strchar.StrChar(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.strchar.StrChar makeStrChar_StrChar(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeStrChar_StrChar(fun_StrChar_StrChar, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.StrChar StrChar_StrCharFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_StrChar_StrChar);

    if (children != null) {
      return makeStrChar_StrChar(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.strchar.StrChar arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_StrChar_StrChar, args);
  }

  public nl.cwi.sen1.relationstores.types.strcon.StrCon makeStrCon_StrCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.strcon.StrCon) factory.build( new nl.cwi.sen1.relationstores.types.strcon.StrCon(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.strcon.StrCon makeStrCon_StrCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeStrCon_StrCon(fun_StrCon_StrCon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.StrCon StrCon_StrConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_StrCon_StrCon);

    if (children != null) {
      return makeStrCon_StrCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.strcon.StrCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_StrCon_StrCon, args);
  }

  public nl.cwi.sen1.relationstores.types.boolcon.True makeBoolCon_True(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.boolcon.True) factory.build( new nl.cwi.sen1.relationstores.types.boolcon.True(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.boolcon.True makeBoolCon_True() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeBoolCon_True(fun_BoolCon_True, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.BoolCon BoolCon_TrueFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_BoolCon_True);

    if (children != null) {
      return makeBoolCon_True(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.boolcon.True arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_BoolCon_True, args);
  }

  public nl.cwi.sen1.relationstores.types.boolcon.False makeBoolCon_False(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.boolcon.False) factory.build( new nl.cwi.sen1.relationstores.types.boolcon.False(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.boolcon.False makeBoolCon_False() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeBoolCon_False(fun_BoolCon_False, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.BoolCon BoolCon_FalseFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_BoolCon_False);

    if (children != null) {
      return makeBoolCon_False(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.boolcon.False arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_BoolCon_False, args);
  }

  public nl.cwi.sen1.relationstores.types.natcon.NatCon makeNatCon_NatCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.natcon.NatCon) factory.build( new nl.cwi.sen1.relationstores.types.natcon.NatCon(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.natcon.NatCon makeNatCon_NatCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeNatCon_NatCon(fun_NatCon_NatCon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.NatCon NatCon_NatConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_NatCon_NatCon);

    if (children != null) {
      return makeNatCon_NatCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.natcon.NatCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_NatCon_NatCon, args);
  }

  public nl.cwi.sen1.relationstores.types.integer.NatCon makeInteger_NatCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.integer.NatCon) factory.build( new nl.cwi.sen1.relationstores.types.integer.NatCon(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.integer.NatCon makeInteger_NatCon(int _NatCon) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_NatCon)};
    return makeInteger_NatCon(fun_Integer_NatCon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.Integer Integer_NatConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Integer_NatCon);

    if (children != null) {
      return makeInteger_NatCon(
        ((Integer) children.get(0)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.integer.NatCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getNatCon()));
    return factory.make(pattern_Integer_NatCon, args);
  }

  public nl.cwi.sen1.relationstores.types.integer.Positive makeInteger_Positive(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.integer.Positive) factory.build( new nl.cwi.sen1.relationstores.types.integer.Positive(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.integer.Positive makeInteger_Positive(nl.cwi.sen1.relationstores.types.Integer _integer) {
    aterm.ATerm[] args = new aterm.ATerm[] {_integer};
    return makeInteger_Positive(fun_Integer_Positive, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.Integer Integer_PositiveFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Integer_Positive);

    if (children != null) {
      return makeInteger_Positive(
        IntegerFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.integer.Positive arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getInteger().toTerm());
    return factory.make(pattern_Integer_Positive, args);
  }

  public nl.cwi.sen1.relationstores.types.integer.Negative makeInteger_Negative(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.integer.Negative) factory.build( new nl.cwi.sen1.relationstores.types.integer.Negative(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.integer.Negative makeInteger_Negative(nl.cwi.sen1.relationstores.types.Integer _integer) {
    aterm.ATerm[] args = new aterm.ATerm[] {_integer};
    return makeInteger_Negative(fun_Integer_Negative, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.Integer Integer_NegativeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Integer_Negative);

    if (children != null) {
      return makeInteger_Negative(
        IntegerFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.integer.Negative arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getInteger().toTerm());
    return factory.make(pattern_Integer_Negative, args);
  }

  public nl.cwi.sen1.relationstores.types.location.File makeLocation_File(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.location.File) factory.build( new nl.cwi.sen1.relationstores.types.location.File(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.location.File makeLocation_File(String _filename) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_filename, 0, true))};
    return makeLocation_File(fun_Location_File, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.Location Location_FileFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_File);

    if (children != null) {
      return makeLocation_File(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.location.File arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFilename());
    return factory.make(pattern_Location_File, args);
  }

  public nl.cwi.sen1.relationstores.types.location.Area makeLocation_Area(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.location.Area) factory.build( new nl.cwi.sen1.relationstores.types.location.Area(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.location.Area makeLocation_Area(nl.cwi.sen1.relationstores.types.Area _Area) {
    aterm.ATerm[] args = new aterm.ATerm[] {_Area};
    return makeLocation_Area(fun_Location_Area, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.Location Location_AreaFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_Area);

    if (children != null) {
      return makeLocation_Area(
        AreaFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.location.Area arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getArea().toTerm());
    return factory.make(pattern_Location_Area, args);
  }

  public nl.cwi.sen1.relationstores.types.location.AreaInFile makeLocation_AreaInFile(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.location.AreaInFile) factory.build( new nl.cwi.sen1.relationstores.types.location.AreaInFile(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.location.AreaInFile makeLocation_AreaInFile(String _filename, nl.cwi.sen1.relationstores.types.Area _Area) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_filename, 0, true)), _Area};
    return makeLocation_AreaInFile(fun_Location_AreaInFile, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.Location Location_AreaInFileFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_AreaInFile);

    if (children != null) {
      return makeLocation_AreaInFile(
        (String) children.get(0),
        AreaFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.location.AreaInFile arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFilename());
    args.add(arg.getArea().toTerm());
    return factory.make(pattern_Location_AreaInFile, args);
  }

  public nl.cwi.sen1.relationstores.types.area.Area makeArea_Area(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.relationstores.types.area.Area) factory.build( new nl.cwi.sen1.relationstores.types.area.Area(this, annos, fun, args));
  }

  public nl.cwi.sen1.relationstores.types.area.Area makeArea_Area(int _beginLine, int _beginColumn, int _endLine, int _endColumn, int _offset, int _length) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_beginLine), factory.makeInt(_beginColumn), factory.makeInt(_endLine), factory.makeInt(_endColumn), factory.makeInt(_offset), factory.makeInt(_length)};
    return makeArea_Area(fun_Area_Area, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.relationstores.types.Area Area_AreaFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Area_Area);

    if (children != null) {
      return makeArea_Area(
        ((Integer) children.get(0)).intValue(),
        ((Integer) children.get(1)).intValue(),
        ((Integer) children.get(2)).intValue(),
        ((Integer) children.get(3)).intValue(),
        ((Integer) children.get(4)).intValue(),
        ((Integer) children.get(5)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.relationstores.types.area.Area arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getBeginLine()));
    args.add(new Integer(arg.getBeginColumn()));
    args.add(new Integer(arg.getEndLine()));
    args.add(new Integer(arg.getEndColumn()));
    args.add(new Integer(arg.getOffset()));
    args.add(new Integer(arg.getLength()));
    return factory.make(pattern_Area_Area, args);
  }

/*genMakeLists*/
  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements() {
    return empty_RElemElements;
  }

  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements(nl.cwi.sen1.relationstores.types.RElem elem) {
    return makeRElemElements(elem, empty_RElemElements);
  }

  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements(nl.cwi.sen1.relationstores.types.RElem head, nl.cwi.sen1.relationstores.types.RElemElements tail) {
    return makeRElemElements(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.relationstores.types.RElemElements) factory.build(new nl.cwi.sen1.relationstores.types.RElemElements(this, annos, head, tail));
  }

  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements(nl.cwi.sen1.relationstores.types.RElem elem0, nl.cwi.sen1.relationstores.types.RElem elem1) {
    return makeRElemElements(elem0, makeRElemElements(elem1));
  }

  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements(nl.cwi.sen1.relationstores.types.RElem elem0, nl.cwi.sen1.relationstores.types.RElem elem1, nl.cwi.sen1.relationstores.types.RElem elem2) {
    return makeRElemElements(elem0, makeRElemElements(elem1, elem2));
  }

  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements(nl.cwi.sen1.relationstores.types.RElem elem0, nl.cwi.sen1.relationstores.types.RElem elem1, nl.cwi.sen1.relationstores.types.RElem elem2, nl.cwi.sen1.relationstores.types.RElem elem3) {
    return makeRElemElements(elem0, makeRElemElements(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements(nl.cwi.sen1.relationstores.types.RElem elem0, nl.cwi.sen1.relationstores.types.RElem elem1, nl.cwi.sen1.relationstores.types.RElem elem2, nl.cwi.sen1.relationstores.types.RElem elem3, nl.cwi.sen1.relationstores.types.RElem elem4) {
    return makeRElemElements(elem0, makeRElemElements(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.relationstores.types.RElemElements makeRElemElements(nl.cwi.sen1.relationstores.types.RElem elem0, nl.cwi.sen1.relationstores.types.RElem elem1, nl.cwi.sen1.relationstores.types.RElem elem2, nl.cwi.sen1.relationstores.types.RElem elem3, nl.cwi.sen1.relationstores.types.RElem elem4, nl.cwi.sen1.relationstores.types.RElem elem5) {
    return makeRElemElements(elem0, makeRElemElements(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.relationstores.types.RElemElements reverse(nl.cwi.sen1.relationstores.types.RElemElements arg) {
    nl.cwi.sen1.relationstores.types.RElemElements reversed = makeRElemElements();
    while (!arg.isEmpty()) {
      reversed = makeRElemElements(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.relationstores.types.RElemElements concat(nl.cwi.sen1.relationstores.types.RElemElements arg0, nl.cwi.sen1.relationstores.types.RElemElements arg1) {
    nl.cwi.sen1.relationstores.types.RElemElements result = arg1;

    for (nl.cwi.sen1.relationstores.types.RElemElements list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeRElemElements(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.relationstores.types.RElemElements append(nl.cwi.sen1.relationstores.types.RElemElements list, nl.cwi.sen1.relationstores.types.RElem elem) {
    return concat(list, makeRElemElements(elem));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes() {
    return empty_RTypeColumnTypes;
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes(nl.cwi.sen1.relationstores.types.RType elem) {
    return makeRTypeColumnTypes(elem, empty_RTypeColumnTypes);
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes(nl.cwi.sen1.relationstores.types.RType head, nl.cwi.sen1.relationstores.types.RTypeColumnTypes tail) {
    return makeRTypeColumnTypes(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.relationstores.types.RTypeColumnTypes) factory.build(new nl.cwi.sen1.relationstores.types.RTypeColumnTypes(this, annos, head, tail));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes(nl.cwi.sen1.relationstores.types.RType elem0, nl.cwi.sen1.relationstores.types.RType elem1) {
    return makeRTypeColumnTypes(elem0, makeRTypeColumnTypes(elem1));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes(nl.cwi.sen1.relationstores.types.RType elem0, nl.cwi.sen1.relationstores.types.RType elem1, nl.cwi.sen1.relationstores.types.RType elem2) {
    return makeRTypeColumnTypes(elem0, makeRTypeColumnTypes(elem1, elem2));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes(nl.cwi.sen1.relationstores.types.RType elem0, nl.cwi.sen1.relationstores.types.RType elem1, nl.cwi.sen1.relationstores.types.RType elem2, nl.cwi.sen1.relationstores.types.RType elem3) {
    return makeRTypeColumnTypes(elem0, makeRTypeColumnTypes(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes(nl.cwi.sen1.relationstores.types.RType elem0, nl.cwi.sen1.relationstores.types.RType elem1, nl.cwi.sen1.relationstores.types.RType elem2, nl.cwi.sen1.relationstores.types.RType elem3, nl.cwi.sen1.relationstores.types.RType elem4) {
    return makeRTypeColumnTypes(elem0, makeRTypeColumnTypes(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes makeRTypeColumnTypes(nl.cwi.sen1.relationstores.types.RType elem0, nl.cwi.sen1.relationstores.types.RType elem1, nl.cwi.sen1.relationstores.types.RType elem2, nl.cwi.sen1.relationstores.types.RType elem3, nl.cwi.sen1.relationstores.types.RType elem4, nl.cwi.sen1.relationstores.types.RType elem5) {
    return makeRTypeColumnTypes(elem0, makeRTypeColumnTypes(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes reverse(nl.cwi.sen1.relationstores.types.RTypeColumnTypes arg) {
    nl.cwi.sen1.relationstores.types.RTypeColumnTypes reversed = makeRTypeColumnTypes();
    while (!arg.isEmpty()) {
      reversed = makeRTypeColumnTypes(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes concat(nl.cwi.sen1.relationstores.types.RTypeColumnTypes arg0, nl.cwi.sen1.relationstores.types.RTypeColumnTypes arg1) {
    nl.cwi.sen1.relationstores.types.RTypeColumnTypes result = arg1;

    for (nl.cwi.sen1.relationstores.types.RTypeColumnTypes list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeRTypeColumnTypes(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes append(nl.cwi.sen1.relationstores.types.RTypeColumnTypes list, nl.cwi.sen1.relationstores.types.RType elem) {
    return concat(list, makeRTypeColumnTypes(elem));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples() {
    return empty_RTupleRtuples;
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples(nl.cwi.sen1.relationstores.types.RTuple elem) {
    return makeRTupleRtuples(elem, empty_RTupleRtuples);
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples(nl.cwi.sen1.relationstores.types.RTuple head, nl.cwi.sen1.relationstores.types.RTupleRtuples tail) {
    return makeRTupleRtuples(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.relationstores.types.RTupleRtuples) factory.build(new nl.cwi.sen1.relationstores.types.RTupleRtuples(this, annos, head, tail));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples(nl.cwi.sen1.relationstores.types.RTuple elem0, nl.cwi.sen1.relationstores.types.RTuple elem1) {
    return makeRTupleRtuples(elem0, makeRTupleRtuples(elem1));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples(nl.cwi.sen1.relationstores.types.RTuple elem0, nl.cwi.sen1.relationstores.types.RTuple elem1, nl.cwi.sen1.relationstores.types.RTuple elem2) {
    return makeRTupleRtuples(elem0, makeRTupleRtuples(elem1, elem2));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples(nl.cwi.sen1.relationstores.types.RTuple elem0, nl.cwi.sen1.relationstores.types.RTuple elem1, nl.cwi.sen1.relationstores.types.RTuple elem2, nl.cwi.sen1.relationstores.types.RTuple elem3) {
    return makeRTupleRtuples(elem0, makeRTupleRtuples(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples(nl.cwi.sen1.relationstores.types.RTuple elem0, nl.cwi.sen1.relationstores.types.RTuple elem1, nl.cwi.sen1.relationstores.types.RTuple elem2, nl.cwi.sen1.relationstores.types.RTuple elem3, nl.cwi.sen1.relationstores.types.RTuple elem4) {
    return makeRTupleRtuples(elem0, makeRTupleRtuples(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples makeRTupleRtuples(nl.cwi.sen1.relationstores.types.RTuple elem0, nl.cwi.sen1.relationstores.types.RTuple elem1, nl.cwi.sen1.relationstores.types.RTuple elem2, nl.cwi.sen1.relationstores.types.RTuple elem3, nl.cwi.sen1.relationstores.types.RTuple elem4, nl.cwi.sen1.relationstores.types.RTuple elem5) {
    return makeRTupleRtuples(elem0, makeRTupleRtuples(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples reverse(nl.cwi.sen1.relationstores.types.RTupleRtuples arg) {
    nl.cwi.sen1.relationstores.types.RTupleRtuples reversed = makeRTupleRtuples();
    while (!arg.isEmpty()) {
      reversed = makeRTupleRtuples(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples concat(nl.cwi.sen1.relationstores.types.RTupleRtuples arg0, nl.cwi.sen1.relationstores.types.RTupleRtuples arg1) {
    nl.cwi.sen1.relationstores.types.RTupleRtuples result = arg1;

    for (nl.cwi.sen1.relationstores.types.RTupleRtuples list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeRTupleRtuples(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples append(nl.cwi.sen1.relationstores.types.RTupleRtuples list, nl.cwi.sen1.relationstores.types.RTuple elem) {
    return concat(list, makeRTupleRtuples(elem));
  }

/*genTypeFromTermMethods*/
  public nl.cwi.sen1.relationstores.types.RElem RElemFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.RElem tmp;
    tmp = RElem_IntFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RElem_StrFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RElem_BoolFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RElem_LocFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RElem_SetFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RElem_BagFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RElem_TupleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a RElem: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.RType RTypeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.RType tmp;
    tmp = RType_IntFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_BoolFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_StrFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_LocFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_TupleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_SetFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_BagFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_RelationFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_UserDefinedFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = RType_ParameterFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a RType: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.RTuple RTupleFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.RTuple tmp;
    tmp = RTuple_RtupleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a RTuple: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.RStore RStoreFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.RStore tmp;
    tmp = RStore_RstoreFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a RStore: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.IdCon IdConFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.IdCon tmp;
    tmp = IdCon_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = IdCon_IdConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a IdCon: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.RElemElements RElemElementsFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.relationstores.types.RElemElements result = makeRElemElements();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.relationstores.types.RElem elem = RElemFromTerm(list.getFirst());
            result = makeRElemElements(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a RElemElements: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes RTypeColumnTypesFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.relationstores.types.RTypeColumnTypes result = makeRTypeColumnTypes();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.relationstores.types.RType elem = RTypeFromTerm(list.getFirst());
            result = makeRTypeColumnTypes(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a RTypeColumnTypes: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples RTupleRtuplesFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.relationstores.types.RTupleRtuples result = makeRTupleRtuples();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.relationstores.types.RTuple elem = RTupleFromTerm(list.getFirst());
            result = makeRTupleRtuples(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a RTupleRtuples: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.StrChar StrCharFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.StrChar tmp;
    tmp = StrChar_StrCharFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a StrChar: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.StrCon StrConFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.StrCon tmp;
    tmp = StrCon_StrConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a StrCon: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.BoolCon BoolConFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.BoolCon tmp;
    tmp = BoolCon_TrueFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = BoolCon_FalseFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a BoolCon: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.NatCon NatConFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.NatCon tmp;
    tmp = NatCon_NatConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a NatCon: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.Integer IntegerFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.Integer tmp;
    tmp = Integer_NatConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Integer_PositiveFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Integer_NegativeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Integer: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.Location LocationFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.Location tmp;
    tmp = Location_FileFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Location_AreaFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Location_AreaInFileFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Location: " + trm);
  }

  public nl.cwi.sen1.relationstores.types.Area AreaFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.relationstores.types.Area tmp;
    tmp = Area_AreaFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Area: " + trm);
  }

/*genTypeFromMethods*/
  public nl.cwi.sen1.relationstores.types.RElem RElemFromString(String str) {
    return RElemFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.RElem RElemFromFile(java.io.InputStream stream) throws java.io.IOException {
    return RElemFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.RType RTypeFromString(String str) {
    return RTypeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.RType RTypeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return RTypeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.RTuple RTupleFromString(String str) {
    return RTupleFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.RTuple RTupleFromFile(java.io.InputStream stream) throws java.io.IOException {
    return RTupleFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.RStore RStoreFromString(String str) {
    return RStoreFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.RStore RStoreFromFile(java.io.InputStream stream) throws java.io.IOException {
    return RStoreFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.IdCon IdConFromString(String str) {
    return IdConFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.IdCon IdConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return IdConFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.RElemElements RElemElementsFromString(String str) {
    return RElemElementsFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.RElemElements RElemElementsFromFile(java.io.InputStream stream) throws java.io.IOException {
    return RElemElementsFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes RTypeColumnTypesFromString(String str) {
    return RTypeColumnTypesFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.RTypeColumnTypes RTypeColumnTypesFromFile(java.io.InputStream stream) throws java.io.IOException {
    return RTypeColumnTypesFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples RTupleRtuplesFromString(String str) {
    return RTupleRtuplesFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.RTupleRtuples RTupleRtuplesFromFile(java.io.InputStream stream) throws java.io.IOException {
    return RTupleRtuplesFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.StrChar StrCharFromString(String str) {
    return StrCharFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.StrChar StrCharFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StrCharFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.StrCon StrConFromString(String str) {
    return StrConFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.StrCon StrConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StrConFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.BoolCon BoolConFromString(String str) {
    return BoolConFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.BoolCon BoolConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return BoolConFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.NatCon NatConFromString(String str) {
    return NatConFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.NatCon NatConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NatConFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.Integer IntegerFromString(String str) {
    return IntegerFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.Integer IntegerFromFile(java.io.InputStream stream) throws java.io.IOException {
    return IntegerFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.Location LocationFromString(String str) {
    return LocationFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.Location LocationFromFile(java.io.InputStream stream) throws java.io.IOException {
    return LocationFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.relationstores.types.Area AreaFromString(String str) {
    return AreaFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.relationstores.types.Area AreaFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AreaFromTerm(factory.readFromFile(stream));
  }

/*genForwardingAlternativeMethods*/
/*genForwardingMakeLists*/
/*genForwardingTypeFromTermMethods*/
/*TODOgenForwardingTypeFromMethods*/
  public static String charsToString(aterm.ATerm arg) {
    aterm.ATermList list = (aterm.ATermList) arg;
    StringBuffer str = new StringBuffer();

    for ( ; !list.isEmpty(); list = list.getNext()) {
      str.append((char) ((aterm.ATermInt) list.getFirst()).getInt());
    }

    return str.toString();
  }

  public static char charToByte(aterm.ATerm arg) {

      return((char) ((aterm.ATermInt) arg).getInt());
  }

  public aterm.ATerm stringToChars(String str) {
    int len = str.length();
    byte chars[] = str.getBytes();
    aterm.ATermList result = getPureFactory().makeList();

    for (int i = len - 1; i >= 0; i--) {
      result = result.insert(getPureFactory().makeInt(chars[i]));
    }

    return result;
  }

  public aterm.ATerm byteToChar(char ch) {
      return getPureFactory().makeInt(ch);
  }

}
