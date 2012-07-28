#include <RStore.h>
#include <ParsedRStore.h>
#include <assert.h>

/* BUFSIZ appears to be not large enough on Darwin */
#define BUFFER_SIZE 8192

static void invalidTerm(const char* msg, ATerm erroneous)
{
  ATwarning("lower: %s\n", msg);
  ATwarning("lower: writing invalid term to .lower.debug.txt\n");
  ATwriteToNamedSAFFile(erroneous, ".lower.debug.txt");
}

static RS_IdCon RS_lowerIdCon(PRS_IdCon in)
{
  RS_IdCon result = NULL;
 
  if (PRS_isValidIdCon(in))  {
    /* TODO: optimize memory usage here */
    PRS_LexIdCon lex = PRS_getIdConIdCon(in);
    char head = PRS_getLexIdConHead(lex);
    char* tail = PRS_getLexIdConTail(lex);
    int len  = strlen(tail) + 2;
    static char tmp[BUFFER_SIZE];

    if (len + 2 >= BUFFER_SIZE) {
      return RS_makeIdConIdCon("id-too-long");
    }

    tmp[0] = head;
    tmp[1] = '\0';
    strcat(tmp+1, tail);

    result = RS_makeIdConIdCon(tmp);
  }
  else {
    invalidTerm("invalid IdCon found, defaulting to \"default\"",
		PRS_IdConToTerm(in));
    result = RS_makeIdConIdCon("default");
  }

  return result;
}

static RS_RType RS_lowerRType(PRS_RType in);

static RS_RTypeColumnTypes RS_lowerColumnTypes(PRS_RTypeColumnTypes in)
{
  RS_RTypeColumnTypes types = RS_makeRTypeColumnTypesEmpty();

  if (!PRS_isValidRTypeColumnTypes(in)) {
    invalidTerm("invalid column types", PRS_RTypeColumnTypesToTerm(in));
    return types;
  }

  for ( ; !PRS_isRTypeColumnTypesEmpty(in); in = PRS_getRTypeColumnTypesTail(in)) {
    RS_RType type = RS_lowerRType(PRS_getRTypeColumnTypesHead(in));
    types = RS_makeRTypeColumnTypesMany(type, types);
  }

  /* order is relevant */
  return RS_reverseRTypeColumnTypes(types);
}

static RS_RType RS_lowerRType(PRS_RType in) 
{
  if (!PRS_isValidRType(in)) {
    invalidTerm("invalid rtype found, defaulting to bool", PRS_RTypeToTerm(in));
    return RS_makeRTypeBool();
  }

  if (PRS_isRTypeInt(in)) {
    return RS_makeRTypeInt();
  }
  else if (PRS_isRTypeBool(in)) { 
    return RS_makeRTypeBool();
  }
  else if (PRS_isRTypeStr(in)) { 
    return RS_makeRTypeStr();
  }
  else if (PRS_isRTypeLoc(in)) { 
    return RS_makeRTypeLoc();
  }
  else if (PRS_isRTypeTuple(in)) { 
    RS_RTypeColumnTypes types = RS_lowerColumnTypes(PRS_getRTypeColumnTypes(in));
    return RS_makeRTypeTuple(types);
  }
  else if (PRS_isRTypeSet(in)) { 
    RS_RType type = RS_lowerRType(PRS_getRTypeElementType(in));
    return RS_makeRTypeSet(type);
  }
  else if (PRS_isRTypeBag(in)) { 
    RS_RType type = RS_lowerRType(PRS_getRTypeElementType(in));
    return RS_makeRTypeSet(type);
  }
  else if (PRS_isRTypeRelation(in)) { 
    RS_RTypeColumnTypes types = RS_lowerColumnTypes(PRS_getRTypeColumnTypes(in));
    return RS_makeRTypeRelation(types);
  }
  else if (PRS_isRTypeUserDefined(in)) { 
    RS_IdCon id = RS_lowerIdCon(PRS_getRTypeTypeName(in));
    return RS_makeRTypeUserDefined(id);
  }
  else if (PRS_isRTypeParameter(in)) { 
    RS_IdCon name = RS_lowerIdCon(PRS_getRTypeParameterName(in));
    return RS_makeRTypeParameter(name);
  }

  invalidTerm("Unknown rtype encountered, defaulting to bool", 
	      PRS_RTypeToTerm(in));

  return RS_makeRTypeBool();
}

static int RS_lowerNatCon(PRS_NatCon in)
{
  if (PRS_isValidNatCon(in)) {
    PRS_LexNatCon lex = PRS_getNatConNatCon(in);
    const char *ch = PRS_getLexNatConList(lex);
    return atoi(ch);
  }
  else {
    invalidTerm("invalid NatCon encountered, defaulting to -1",
		PRS_NatConToTerm(in));
  }

  return -1;
}

static RS_Integer RS_lowerInteger(PRS_Integer in)
{ 
  if (PRS_isValidInteger(in)) {
    if (PRS_isIntegerNatCon(in)) {
      int nat = RS_lowerNatCon(PRS_getIntegerNatCon(in));
      return RS_makeIntegerNatCon(nat);
    }
    else if (PRS_isIntegerPositive(in)) {
      RS_Integer nat = RS_lowerInteger(PRS_getIntegerInteger(in));
      return RS_makeIntegerPositive(nat);
    }
    else {
      RS_Integer nat = RS_lowerInteger(PRS_getIntegerInteger(in));
      return RS_makeIntegerNegative(nat);
    }
  }
  else {
    invalidTerm("invalid Integer encountered, defaulting to -1",
		PRS_IntegerToTerm(in));
    return RS_makeIntegerNegative(RS_makeIntegerNatCon(1));
  }
}


static const char *RS_lowerStrCon(PRS_StrCon pStr)
{
  static char result[BUFFER_SIZE];
  
  if (PRS_isValidStrCon(pStr)) {
    PRS_LexStrCon strcon = PRS_getStrConStrCon(pStr);
    PRS_LexStrCharChars list = PRS_getLexStrConChars(strcon);
    int len = PRS_getLexStrCharCharsLength(list);
    int i;
    assert(pStr != NULL);

    if (len >= BUFFER_SIZE - 2) {
      ATwarning("PRS_lowerStrCon: insufficient memory to allocate string\n");
      return NULL;
    }

    for (i = 0;
	 !PRS_isLexStrCharCharsEmpty(list);
	 list = PRS_getLexStrCharCharsTail(list),
	 i++) {

      PRS_LexStrChar ch = PRS_getLexStrCharCharsHead(list);


      if (PRS_isLexStrCharNewline(ch)) {
	result[i] = '\n';
      }
      else if (PRS_isLexStrCharTab(ch)) {
	result[i] = '\t';
      }
      else if (PRS_isLexStrCharQuote(ch)) {
	result[i] = '\"';
      }
      else if (PRS_isLexStrCharBackslash(ch)) {
	result[i] = '\\';
      }
      else if (PRS_isLexStrCharNormal(ch)) {
	result[i] = PRS_getLexStrCharCh(ch);
      }
      else if (PRS_isLexStrCharDecimal(ch)) {
	int a = PRS_getLexStrCharA(ch);
	int b = PRS_getLexStrCharB(ch);
	int c = PRS_getLexStrCharC(ch);
	result[i] = (char) 100*a + 10*b + c;
      }
    }

    result[len] = '\0'; 
    return result;
  }
  else {
    invalidTerm("invalid StrCon encountered, defaulting to empty string\n", 
		PRS_StrConToTerm(pStr));
    result[0] = '\0';
    return result;
  }
}

static RS_BoolCon RS_lowerBoolCon(PRS_BoolCon in)
{
  if (PRS_isValidBoolCon(in)) {
    if (PRS_isBoolConTrue(in)) {
      return RS_makeBoolConTrue();
    }
    else {
      return RS_makeBoolConFalse();
    }
  }
  else {
    invalidTerm("invalid BoolCon encountered, defaulting to false\n", 
		PRS_BoolConToTerm(in));
    return RS_makeBoolConFalse();
  }
}

static RS_Area RS_lowerArea(PRS_Area in)
{
  if (PRS_isValidArea(in)) {
    int bl = RS_lowerNatCon(PRS_getAreaBeginLine(in));
    int el = RS_lowerNatCon(PRS_getAreaEndLine(in));
    int bc = RS_lowerNatCon(PRS_getAreaBeginColumn(in));
    int ec = RS_lowerNatCon(PRS_getAreaEndColumn(in));
    int o = RS_lowerNatCon(PRS_getAreaOffset(in));
    int l = RS_lowerNatCon(PRS_getAreaLength(in));

    return RS_makeAreaArea(bl,bc,el,ec,o,l);
  }
  else {
    invalidTerm("invalid area, defaulting to 0,0,0,0",
		PRS_AreaToTerm(in));
    return RS_makeAreaArea(0,0,0,0,0,0);
  }
}

static RS_Location RS_lowerLocation(PRS_Location in)
{
  if (PRS_isValidLocation(in)) {
    if (PRS_isLocationFile(in)) {
      const char* name = RS_lowerStrCon(PRS_getLocationFilename(in));
      return RS_makeLocationFile(name);
    }
    else if (PRS_isLocationAreaInFile(in)) {
      const char* name = RS_lowerStrCon(PRS_getLocationFilename(in));
      RS_Area area = RS_lowerArea(PRS_getLocationArea(in));
      return RS_makeLocationAreaInFile(name, area);
    }
    else {
      invalidTerm("invalid location found, defaulting to /dev/null",
		  PRS_LocationToTerm(in));
      return RS_makeLocationFile("/dev/null");  
    }
  }
  else {
    invalidTerm("invalid location found, defaulting to /dev/null",
		  PRS_LocationToTerm(in));
    return RS_makeLocationFile("/dev/null");  
  }
}

static RS_RElem RS_lowerRElem(PRS_RElem in);

static RS_RElemElements RS_lowerRElemElements(PRS_RElemElements in) 
{
  RS_RElemElements elems = RS_makeRElemElementsEmpty();
  
  if (PRS_isValidRElemElements(in)) {
    for ( ; !PRS_isRElemElementsEmpty(in); in = PRS_getRElemElementsTail(in)) {
      RS_RElem elem = RS_lowerRElem(PRS_getRElemElementsHead(in));
      if (elem != NULL) {
	elems = RS_makeRElemElementsMany(elem, elems);
      }
      else {
	ATwarning("warning: dropping element\n");
      }
    }
  }
  else {
    invalidTerm("invalid list of elements, defaulting to empty list",
		PRS_RElemElementsToTerm(in));
  }

  /* order is irrelevant */
  return elems;
}

static RS_RElem RS_lowerRElem(PRS_RElem in)
{
  if (PRS_isValidRElem(in)) {
    if (PRS_isRElemInt(in)) {
      RS_Integer i = RS_lowerInteger(PRS_getRElemInteger(in));
      return RS_makeRElemInt(i);
    }
    else if (PRS_isRElemStr(in)) {
      const char *s = RS_lowerStrCon(PRS_getRElemStrCon(in));
      return RS_makeRElemStr(s);
    }
    else if (PRS_isRElemBool(in)) {
      RS_BoolCon b = RS_lowerBoolCon(PRS_getRElemBoolCon(in));
      return RS_makeRElemBool(b);
    }
    else if (PRS_isRElemLoc(in)) {
      RS_Location l = RS_lowerLocation(PRS_getRElemLocation(in));
      return RS_makeRElemLoc(l);
    }
    else if (PRS_isRElemSet(in)) {
      RS_RElemElements e = RS_lowerRElemElements(PRS_getRElemElements(in));
      return RS_makeRElemSet(e);
    }
    else if (PRS_isRElemBag(in)) {
      RS_RElemElements e = RS_lowerRElemElements(PRS_getRElemElements(in));
      return RS_makeRElemBag(e);
    }
    else if (PRS_isRElemTuple(in)) {
      RS_RElemElements e = RS_lowerRElemElements(PRS_getRElemElements(in));
      /* order is relevant here */
      return RS_makeRElemTuple(RS_reverseRElemElements(e));
    }
    else {
      invalidTerm("unhandled relem found, defaulting to boolean false",
		  PRS_RElemToTerm(in));
      return RS_makeRElemBool(RS_makeBoolConFalse());
    }
  }
  else {
      invalidTerm("unhandled relem found, defaulting to boolean false",
		  PRS_RElemToTerm(in));
    return RS_makeRElemBool(RS_makeBoolConFalse());;
  }
}


static RS_RTuple RS_lowerRTuple(PRS_RTuple in)
{
  if (PRS_isValidRTuple(in)) {
    RS_IdCon variable = RS_lowerIdCon(PRS_getRTupleVariable(in));
    RS_RType type = RS_lowerRType(PRS_getRTupleRtype(in));
    RS_RElem value = RS_lowerRElem(PRS_getRTupleValue(in));

    return RS_makeRTupleRtuple(variable, type, value);
  }

  invalidTerm("invalid RTuple found, defaulting to <\"default\", false>",
	      PRS_RTupleToTerm(in));

  return RS_makeRTupleRtuple(RS_makeIdConIdCon("default"),
			     RS_makeRTypeBool(),
			     RS_makeRElemBool(RS_makeBoolConFalse()));
}

static RS_RTupleRtuples RS_lowerRTuples(PRS_RTupleRtuples in)
{
  RS_RTupleRtuples out = RS_makeRTupleRtuplesEmpty();

  if (PRS_isValidRTupleRtuples(in)) {
    for (; !PRS_isRTupleRtuplesEmpty(in); in = PRS_getRTupleRtuplesTail(in)) {
      RS_RTuple tuple = RS_lowerRTuple(PRS_getRTupleRtuplesHead(in));
	out = RS_makeRTupleRtuplesMany(tuple, out);
    }
  }
  else {
    invalidTerm("invalid list of RTuples found, defaulting to empty",
		PRS_RTupleRtuplesToTerm(in));
  }

  /* order is irrelevant, so no reverse */
  return out;
}

RS_RStore RS_lowerRStore(PRS_RStore in)
{
  if (PRS_isValidRStore(in)) {
    return RS_makeRStoreRstore(RS_lowerRTuples(PRS_getRStoreRtuples(in)));
  }
  else {
    invalidTerm("invalid rstore found, defaulting to empty",
		PRS_RStoreToTerm(in));
    return RS_makeRStoreRstore(RS_makeRTupleRtuplesEmpty());
  }
}
