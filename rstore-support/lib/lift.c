#include <RStore.h>
#include <ParsedRStore.h>
#include <assert.h>
#include <ctype.h>

static PRS_IdCon RS_liftIdCon(RS_IdCon in)
{
  PRS_LexIdCon result = NULL;
 
  if (RS_isValidIdCon(in))  {
    const char *string = RS_getIdConString(in);
    result = PRS_makeLexIdConDefault(string[0], string+1);
  }
  else {
    ATwarning("lift rstore: this is an invalid IdCon: %t, default\n", in);
    const char *string = "default";
    result = PRS_makeLexIdConDefault(string[0], string+1);
  }

  return PRS_makeIdConLexToCf(result);
}

static PRS_RType RS_liftRType(RS_RType in);

static PRS_RTypeColumnTypes RS_liftColumnTypes(RS_RTypeColumnTypes in)
{
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();

  PRS_RTypeColumnTypes types = PRS_makeRTypeColumnTypesEmpty();

  if (!RS_isValidRTypeColumnTypes(in)) {
    ATwarning("lift rstore: this is not a list of Column types: %t\n", in);
    return types;
  }

  for ( ; !RS_isRTypeColumnTypesEmpty(in); in = RS_getRTypeColumnTypesTail(in)) {
    PRS_RType type = RS_liftRType(RS_getRTypeColumnTypesHead(in));
    types = PRS_makeRTypeColumnTypesMany(type, e, e, types);
  }

  /* order is relevant */
  return PRS_reverseRTypeColumnTypes(types);
}

static PRS_RType RS_liftRType(RS_RType in)
{
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();

  if (!RS_isValidRType(in)) {
    ATwarning("lift rstore: this is not an rtype: %t, default to bool\n", in);
    return PRS_makeRTypeBool();
  }

  if (RS_isRTypeInt(in)) {
    return PRS_makeRTypeInt();
  }
  else if (RS_isRTypeBool(in)) {
    return PRS_makeRTypeBool();
  }
  else if (RS_isRTypeStr(in)) {
    return PRS_makeRTypeStr();
  }
  else if (RS_isRTypeLoc(in)) { 
    return PRS_makeRTypeLoc();
  }
  else if (RS_isRTypeTuple(in)) { 
    PRS_RTypeColumnTypes types = RS_liftColumnTypes(RS_getRTypeColumnTypes(in));
    return PRS_makeRTypeTuple(e, types, e);
  }
  else if (RS_isRTypeSet(in)) { 
    PRS_RType type = RS_liftRType(RS_getRTypeElementType(in));
    return PRS_makeRTypeSet(e, e, type, e);
  }
  else if (RS_isRTypeBag(in)) { 
    PRS_RType type = RS_liftRType(RS_getRTypeElementType(in));
    return PRS_makeRTypeSet(e, e, type, e);
  }
  else if (RS_isRTypeRelation(in)) { 
    PRS_RTypeColumnTypes types = RS_liftColumnTypes(RS_getRTypeColumnTypes(in));
    return PRS_makeRTypeRelation(e, e, types, e);
  }
  else if (RS_isRTypeUserDefined(in)) { 
    PRS_IdCon id = RS_liftIdCon(RS_getRTypeTypeName(in));
    return PRS_makeRTypeUserDefined(id);
  }
  else if (RS_isRTypeParameter(in)) { 
    PRS_IdCon name = RS_liftIdCon(RS_getRTypeParameterName(in));
    return PRS_makeRTypeParameter(e, name);
  }

  ATwarning("lift rstore: unknown rtype %t, default to bool\n", in);
  return PRS_makeRTypeBool();
}

static PRS_NatCon RS_liftNatCon(int in)
{
  static char string[1024];
  sprintf(string, "%d", in);
  return PRS_makeNatConLexToCf(PRS_makeLexNatConDigits(string));
}

static PRS_Integer RS_liftInteger(RS_Integer in)
{
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();

  if (RS_isValidInteger(in)) {
    if (RS_isIntegerNatCon(in)) {
      PRS_NatCon nat = RS_liftNatCon(RS_getIntegerNatCon(in));
      return PRS_makeIntegerNatCon(nat);
    }
    else if (RS_isIntegerPositive(in)) {
      PRS_Integer nat = RS_liftInteger(RS_getIntegerInteger(in));
      return PRS_makeIntegerPositive(e, nat);
    }
    else {
      PRS_Integer nat = RS_liftInteger(RS_getIntegerInteger(in));
      return PRS_makeIntegerNegative(e, nat);
    }
  }
  else {
    ATwarning("lift rstore: this is not a valid Integer: %t, default to -1\n", in);
    PRS_NatCon nat = RS_liftNatCon(1);
    return PRS_makeIntegerNegative(e, PRS_makeIntegerNatCon(nat));
  }
}

/* note that the function below is copied from another lifting
 * library. This kind of duplication can be avoided when apigen
 * for C will support modular generation of API's.
 */
static PRS_LexStrCon RS_makeLexStrCon(const char* str)
{
  int len = strlen(str);
  int i;
  PRS_LexStrCharChars list = PRS_makeLexStrCharCharsEmpty();

  for (i = len - 1; i >= 0; i--) {
    PRS_LexStrChar ch;

    switch(str[i]) {
      case '\n':
	ch = PRS_makeLexStrCharNewline();
	break;
      case '\t':
	ch = PRS_makeLexStrCharTab();
	break;
      case '"':
	ch = PRS_makeLexStrCharQuote();
	break;
      case '\\':
	ch = PRS_makeLexStrCharBackslash();
	break;
      default:
	if (isprint((int) str[i])) {
	  ch = PRS_makeLexStrCharNormal(str[i]);
	}
	else {
	  int value = str[i];
	  int a, b, c;

	  c = value % 10;
	  value /= 10;
	  b = value % 10;
	  value /= 10;
	  a = value;

	  ch = PRS_makeLexStrCharDecimal(a,b,c);
	}
    }

    list = PRS_makeLexStrCharCharsMany(ch, list);
  }
  return PRS_makeLexStrConDefault(list);
}

static PRS_StrCon RS_liftStrCon(const char *str)
{
  return PRS_makeStrConLexToCf(RS_makeLexStrCon(str));
}

static PRS_BoolCon RS_liftBoolCon(RS_BoolCon in)
{
  if (RS_isValidBoolCon(in)) {
    if (RS_isBoolConTrue(in)) {
      return PRS_makeBoolConTrue();
    }
    else {
      return PRS_makeBoolConFalse();
    }
  }
  else {
    ATwarning("lift rstore: this is not a valid BoolCon: %t, default to false\n", in);
    return PRS_makeBoolConFalse();
  }
}

static PRS_Area RS_liftArea(RS_Area in)
{
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();

  if (RS_isValidArea(in)) {
    PRS_NatCon bl = RS_liftNatCon(RS_getAreaBeginLine(in));
    PRS_NatCon el = RS_liftNatCon(RS_getAreaEndLine(in));
    PRS_NatCon bc = RS_liftNatCon(RS_getAreaBeginColumn(in));
    PRS_NatCon ec = RS_liftNatCon(RS_getAreaEndColumn(in));
    PRS_NatCon o = RS_liftNatCon(RS_getAreaOffset(in));
    PRS_NatCon l = RS_liftNatCon(RS_getAreaLength(in));

    return PRS_makeAreaArea(e, e, bl, e, e, bc,
                            e, e, el, e, e, ec,
                            e, e, o, e, e, l, e);
  }
  else {
    ATwarning("lift rstore: this is not a valid Area: %t, default to 0,0,0,0\n", in);
    PRS_NatCon nat = RS_liftNatCon(0);
    return PRS_makeAreaArea(e, e, nat, e, e, nat,
			    e, e, nat, e, e, nat, 
			    e, e, nat, e, e, nat, e);
  }
}

static PRS_Location RS_liftLocation(RS_Location in)
{
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();

  if (RS_isValidLocation(in)) {
    if (RS_isLocationFile(in)) {
      PRS_StrCon name = RS_liftStrCon(RS_getLocationFilename(in));
      return PRS_makeLocationFile(e, e, name, e);
    }
    else if (RS_isLocationAreaInFile(in)) {
      PRS_StrCon name = RS_liftStrCon(RS_getLocationFilename(in));
      PRS_Area area = RS_liftArea(RS_getLocationArea(in));
      return PRS_makeLocationAreaInFile(e, e, name, e, e, area, e);
    }
    else {
      ATwarning("lift rstore: this is not a Location %t, defaulting\n", in);
      PRS_StrCon name = RS_liftStrCon("/dev/NULL");
      return PRS_makeLocationFile(e, e, name, e);
    }
  }
  else {
    ATwarning("lift rstore: this is not a Location %t, defaulting\n", in);
    PRS_StrCon name = RS_liftStrCon("/dev/NULL");
    return PRS_makeLocationFile(e, e, name, e);
  }
}

static PRS_RElem RS_liftRElem(RS_RElem in);

static PRS_RElemElements RS_liftRElemElements(RS_RElemElements in) 
{
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();
  PRS_RElemElements elems = PRS_makeRElemElementsEmpty();
  
  if (RS_isValidRElemElements(in)) {
    for ( ; !RS_isRElemElementsEmpty(in); in = RS_getRElemElementsTail(in)) {
      PRS_RElem elem = RS_liftRElem(RS_getRElemElementsHead(in));
      if (elem != NULL) {
        elems = PRS_makeRElemElementsMany(elem, e, e, elems);
      }
      else {
        ATwarning("warning: dropping element\n");
      }
    }
  }
  else {
    ATwarning("lift rstore: this is not a list of Elements: %t, default to empty\n", in);
  }

  /* order is irrelevant */
  return elems;
} 

static PRS_RElem RS_liftRElem(RS_RElem in)
{
  PRS_OptLayout l = PRS_makeOptLayoutAbsent();

  if (RS_isValidRElem(in)) {
    if (RS_isRElemInt(in)) {
      PRS_Integer i = RS_liftInteger(RS_getRElemInteger(in));
      return PRS_makeRElemInt(i);
    }
    else if (RS_isRElemStr(in)) {
      PRS_StrCon s = RS_liftStrCon(RS_getRElemStrCon(in));
      return PRS_makeRElemStr(s);
    }
    else if (RS_isRElemBool(in)) {
      PRS_BoolCon b = RS_liftBoolCon(RS_getRElemBoolCon(in));
      return PRS_makeRElemBool(b);
    }
    else if (RS_isRElemLoc(in)) {
      PRS_Location l = RS_liftLocation(RS_getRElemLocation(in));
      return PRS_makeRElemLoc(l);
    }
    else if (RS_isRElemSet(in)) {
      PRS_RElemElements e = RS_liftRElemElements(RS_getRElemElements(in));
      return PRS_makeRElemSet(l, e, l);
    }
    else if (RS_isRElemBag(in)) {
      PRS_RElemElements e = RS_liftRElemElements(RS_getRElemElements(in));
      return PRS_makeRElemBag(l, e, l);
    }
    else if (RS_isRElemTuple(in)) {
      PRS_RElemElements e = RS_liftRElemElements(RS_getRElemElements(in));
      /* order is relevant here */
      return PRS_makeRElemTuple(l, PRS_reverseRElemElements(e), l);
    }
    else {
      ATwarning("lift rstore: unhandled RElem: %t, default to boolean\n", in);
      return PRS_makeRElemBool(PRS_makeBoolConFalse());
    }
  }
  else {
    ATwarning("lift rstore: this is not an RElem: %t, default to boolean\n", in);
    return PRS_makeRElemBool(PRS_makeBoolConFalse());;
  }
}

PRS_RTuple RS_liftRTuple(RS_RTuple in)
{
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();

  if (RS_isValidRTuple(in)) {
    PRS_IdCon variable = RS_liftIdCon(RS_getRTupleVariable(in));
    PRS_RType type = RS_liftRType(RS_getRTupleRtype(in));
    PRS_RElem value = RS_liftRElem(RS_getRTupleValue(in));

    return PRS_makeRTupleRtuple(e, variable, e, e, type, e, e, value, e);
  }

  ATwarning("lift rstore: this is not an RTuple: %t\n, defaulting", in);

  PRS_IdCon variable = RS_liftIdCon(RS_makeIdConIdCon("default"));
  return PRS_makeRTupleRtuple(e, variable, e, e,
			      PRS_makeRTypeBool(), e, e,
			      PRS_makeRElemBool(PRS_makeBoolConFalse()), e);
}

static PRS_RTupleRtuples RS_liftRTuples(RS_RTupleRtuples in) {
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();
  PRS_RTupleRtuples out = PRS_makeRTupleRtuplesEmpty();

  if (RS_isValidRTupleRtuples(in)) {
    for (; !RS_isRTupleRtuplesEmpty(in); in = RS_getRTupleRtuplesTail(in)) {
      PRS_RTuple tuple = RS_liftRTuple(RS_getRTupleRtuplesHead(in));
      out = PRS_makeRTupleRtuplesMany(tuple, e, e, out);
    }
  }
  else {
    ATwarning("lift rstore: this is not a list of RTuples: %t\n", in);
  }

  /* order is irrelevant, so no reverse */
  return out;
}

PRS_RStore RS_liftRStore(RS_RStore in)
{
  PRS_OptLayout e = PRS_makeOptLayoutAbsent();
  RS_RTupleRtuples tuples = RS_getRStoreRtuples(in);
  PRS_RTupleRtuples pTuples = RS_liftRTuples(tuples);

  if (RS_isValidRStore(in)) {
    return PRS_makeRStoreRstore(e, e, e, pTuples, e, e);
  }
  else {
    ATwarning("lift rstore: this is not an rstore: %t\n", in);
    return PRS_makeRStoreRstore(e, e, e, PRS_makeRTupleRtuplesEmpty(), e, e);
  }
}
