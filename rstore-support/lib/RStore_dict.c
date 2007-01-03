#include "RStore_dict.h"

AFun RS_afun17;
AFun RS_afun22;
AFun RS_afun3;
AFun RS_afun9;
AFun RS_afun19;
AFun RS_afun2;
AFun RS_afun12;
AFun RS_afun15;
AFun RS_afun18;
AFun RS_afun20;
AFun RS_afun8;
AFun RS_afun21;
AFun RS_afun0;
AFun RS_afun11;
AFun RS_afun5;
AFun RS_afun16;
AFun RS_afun10;
AFun RS_afun13;
AFun RS_afun4;
AFun RS_afun14;
AFun RS_afun23;
AFun RS_afun7;
AFun RS_afun24;
AFun RS_afun1;
AFun RS_afun6;

ATerm RS_patternAreaArea = NULL;
ATerm RS_patternLocationAreaInFile = NULL;
ATerm RS_patternLocationArea = NULL;
ATerm RS_patternLocationFile = NULL;
ATerm RS_patternIntegerNegative = NULL;
ATerm RS_patternIntegerPositive = NULL;
ATerm RS_patternIntegerNatCon = NULL;
ATerm RS_patternIdConIdCon = NULL;
ATerm RS_patternNatConNatCon = NULL;
ATerm RS_patternBoolConFalse = NULL;
ATerm RS_patternBoolConTrue = NULL;
ATerm RS_patternStrConStrCon = NULL;
ATerm RS_patternStrCharStrChar = NULL;
ATerm RS_patternRTupleRtuplesMany = NULL;
ATerm RS_patternRTupleRtuplesSingle = NULL;
ATerm RS_patternRTupleRtuplesEmpty = NULL;
ATerm RS_patternRTypeColumnTypesMany = NULL;
ATerm RS_patternRTypeColumnTypesSingle = NULL;
ATerm RS_patternRTypeColumnTypesEmpty = NULL;
ATerm RS_patternRElemElementsMany = NULL;
ATerm RS_patternRElemElementsSingle = NULL;
ATerm RS_patternRElemElementsEmpty = NULL;
ATerm RS_patternRStoreRstore = NULL;
ATerm RS_patternRTupleRtuple = NULL;
ATerm RS_patternRTypeParameter = NULL;
ATerm RS_patternRTypeUserDefined = NULL;
ATerm RS_patternRTypeRelation = NULL;
ATerm RS_patternRTypeBag = NULL;
ATerm RS_patternRTypeSet = NULL;
ATerm RS_patternRTypeTuple = NULL;
ATerm RS_patternRTypeLoc = NULL;
ATerm RS_patternRTypeStr = NULL;
ATerm RS_patternRTypeBool = NULL;
ATerm RS_patternRTypeInt = NULL;
ATerm RS_patternRElemTuple = NULL;
ATerm RS_patternRElemBag = NULL;
ATerm RS_patternRElemSet = NULL;
ATerm RS_patternRElemLoc = NULL;
ATerm RS_patternRElemBool = NULL;
ATerm RS_patternRElemStr = NULL;
ATerm RS_patternRElemInt = NULL;

/*
 * RS_afun17 = false
 * RS_afun22 = area(x)
 * RS_afun3 = loc(x)
 * RS_afun9 = str
 * RS_afun19 = positive(x)
 * RS_afun2 = bool(x)
 * RS_afun12 = user-defined(x)
 * RS_afun15 = rstore(x)
 * RS_afun18 = nat-con(x)
 * RS_afun20 = negative(x)
 * RS_afun8 = bool
 * RS_afun21 = file(x)
 * RS_afun0 = int(x)
 * RS_afun11 = relation(x)
 * RS_afun5 = bag(x)
 * RS_afun16 = true
 * RS_afun10 = loc
 * RS_afun13 = parameter(x)
 * RS_afun4 = set(x)
 * RS_afun14 = rtuple(x,x,x)
 * RS_afun23 = area-in-file(x,x)
 * RS_afun7 = int
 * RS_afun24 = area(x,x,x,x,x,x)
 * RS_afun1 = str(x)
 * RS_afun6 = tuple(x)
 *
 * RS_patternAreaArea = area(<int>,<int>,<int>,<int>,<int>,<int>)
 * RS_patternLocationAreaInFile = area-in-file(<str>,<term>)
 * RS_patternLocationArea = area(<term>)
 * RS_patternLocationFile = file(<str>)
 * RS_patternIntegerNegative = negative(<term>)
 * RS_patternIntegerPositive = positive(<term>)
 * RS_patternIntegerNatCon = nat-con(<int>)
 * RS_patternIdConIdCon = <str>
 * RS_patternNatConNatCon = <str>
 * RS_patternBoolConFalse = false
 * RS_patternBoolConTrue = true
 * RS_patternStrConStrCon = <str>
 * RS_patternStrCharStrChar = <str>
 * RS_patternRTupleRtuplesMany = [<term>,<list>]
 * RS_patternRTupleRtuplesSingle = [<term>]
 * RS_patternRTupleRtuplesEmpty = []
 * RS_patternRTypeColumnTypesMany = [<term>,<list>]
 * RS_patternRTypeColumnTypesSingle = [<term>]
 * RS_patternRTypeColumnTypesEmpty = []
 * RS_patternRElemElementsMany = [<term>,<list>]
 * RS_patternRElemElementsSingle = [<term>]
 * RS_patternRElemElementsEmpty = []
 * RS_patternRStoreRstore = rstore(<term>)
 * RS_patternRTupleRtuple = rtuple(<term>,<term>,<term>)
 * RS_patternRTypeParameter = parameter(<term>)
 * RS_patternRTypeUserDefined = user-defined(<term>)
 * RS_patternRTypeRelation = relation(<term>)
 * RS_patternRTypeBag = bag(<term>)
 * RS_patternRTypeSet = set(<term>)
 * RS_patternRTypeTuple = tuple(<term>)
 * RS_patternRTypeLoc = loc
 * RS_patternRTypeStr = str
 * RS_patternRTypeBool = bool
 * RS_patternRTypeInt = int
 * RS_patternRElemTuple = tuple(<term>)
 * RS_patternRElemBag = bag(<term>)
 * RS_patternRElemSet = set(<term>)
 * RS_patternRElemLoc = loc(<term>)
 * RS_patternRElemBool = bool(<term>)
 * RS_patternRElemStr = str(<str>)
 * RS_patternRElemInt = int(<term>)
 *
 */

static ATerm _RStore_dict = NULL;

#define _RStore_dict_LEN 568

static char _RStore_dict_baf[_RStore_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x1F,0x7B,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x05,
0x06,0x04,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x47,0x1C,0x01,0x02,0x00,
0x07,0x09,0x0A,0x04,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,
0x17,0x18,0x19,0x1A,0x1B,0x03,0x1C,0x1D,0x1E,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,
0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,
0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,
0x05,0x66,0x61,0x6C,0x73,0x65,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x04,0x61,
0x72,0x65,0x61,0x01,0x00,0x02,0x02,0x00,0x08,0x03,0x6C,0x6F,0x63,0x01,0x00,0x02,
0x02,0x00,0x08,0x08,0x70,0x6F,0x73,0x69,0x74,0x69,0x76,0x65,0x01,0x00,0x02,0x02,
0x00,0x08,0x04,0x62,0x6F,0x6F,0x6C,0x01,0x00,0x02,0x02,0x00,0x08,0x0C,0x75,0x73,
0x65,0x72,0x2D,0x64,0x65,0x66,0x69,0x6E,0x65,0x64,0x01,0x00,0x02,0x02,0x00,0x08,
0x06,0x72,0x73,0x74,0x6F,0x72,0x65,0x01,0x00,0x02,0x02,0x00,0x08,0x07,0x6E,0x61,
0x74,0x2D,0x63,0x6F,0x6E,0x01,0x00,0x02,0x02,0x00,0x08,0x08,0x6E,0x65,0x67,0x61,
0x74,0x69,0x76,0x65,0x01,0x00,0x02,0x02,0x00,0x08,0x04,0x62,0x6F,0x6F,0x6C,0x00,
0x00,0x01,0x04,0x66,0x69,0x6C,0x65,0x01,0x00,0x02,0x02,0x00,0x08,0x03,0x69,0x6E,
0x74,0x01,0x00,0x02,0x02,0x00,0x08,0x08,0x72,0x65,0x6C,0x61,0x74,0x69,0x6F,0x6E,
0x01,0x00,0x02,0x02,0x00,0x08,0x03,0x62,0x61,0x67,0x01,0x00,0x02,0x02,0x00,0x08,
0x04,0x74,0x72,0x75,0x65,0x00,0x00,0x01,0x03,0x6C,0x6F,0x63,0x00,0x00,0x01,0x09,
0x70,0x61,0x72,0x61,0x6D,0x65,0x74,0x65,0x72,0x01,0x00,0x02,0x02,0x00,0x08,0x03,
0x73,0x65,0x74,0x01,0x00,0x02,0x02,0x00,0x08,0x06,0x72,0x74,0x75,0x70,0x6C,0x65,
0x03,0x00,0x02,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x0C,0x61,0x72,0x65,
0x61,0x2D,0x69,0x6E,0x2D,0x66,0x69,0x6C,0x65,0x02,0x00,0x02,0x02,0x00,0x08,0x02,
0x00,0x08,0x04,0x61,0x72,0x65,0x61,0x06,0x00,0x02,0x02,0x00,0x08,0x02,0x00,0x08,
0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x03,0x73,0x74,0x72,
0x01,0x00,0x02,0x02,0x00,0x08,0x05,0x74,0x75,0x70,0x6C,0x65,0x01,0x00,0x02,0x02,
0x00,0x08,0x01,0x00,0xCC,0x1D,0x08,0x43,0x4A,0x11,0x51,0x81,0x4E,0x11,0x90,0x44,
0x24,0x91,0x11,0x14,0x40,0x4D,0x11,0xE0,0xC4,0x38,0xB1,0x61,0xC4,0x18,0xF1,0x1A,
0x02,0x42,0x88,0x91,0x21,0x20,0x8C,0x9C,0x0A,0x43,0x0A,0x91,0x41,0xA5,0x41,0x0E,
0x94,0x60,0x18,0x82,0x65,0x55,0x10,0x16,0x40,0x0D,0x94,0x51,0x01,0x19,0xC0,0xC0,
0x00,0x00,0x03,0x0F,0x62,0x21,0x41,0x09,0x21,0x10,0x5D,0x10,0x02,0x68,0x47,0xEE,
0x42,0x1F,0x6A,0x01,0x79,0x10,0x3C,0x88,0x6E,0xC0,0xB9,0x24,0xE4,0x40,0x72,0x21,
0xD8,0x0B,0x10,0x89,0x88,0xC2,0x1B,0x03,0x62,0x14,0x56,0x80,0x58,0x0B,0x0C,0xC0,
0xD8,0x26,0x81,0x18,0x0B,0x00,0xC0,0xD8,0x7A,0x80,0xE9,0x50,0x8B,0x4D,0x84,0x21,
0x06,0x8B,0x08,0xD5,0x28,0x42,0xA0,0xC2,0x25,0x46,0x10,0x2A,0xB0,0x8E,0x5B,0x84,
0x32,0xC9,0x49,0x81,0x2B,0x18,0x86,0x22,0xDC,0x42,0x8C,0x02,0xAC,0x7C,0xA4,0x21,
0xE0,0xA1,0x17,0x17,0x10,0x39,0xE8,0x54
};

void init_RStore_dict()
{
  ATermList afuns, terms;

  _RStore_dict = ATreadFromBinaryString(_RStore_dict_baf, _RStore_dict_LEN);

  ATprotect(&_RStore_dict);

  afuns = (ATermList)ATelementAt((ATermList)_RStore_dict, 0);

  RS_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_RStore_dict, 1);

  RS_patternAreaArea = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternLocationAreaInFile = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternLocationArea = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternLocationFile = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternIntegerNegative = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternIntegerPositive = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternIntegerNatCon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternIdConIdCon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternNatConNatCon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternBoolConFalse = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternBoolConTrue = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternStrConStrCon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternStrCharStrChar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTupleRtuplesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTupleRtuplesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTupleRtuplesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeColumnTypesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeColumnTypesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeColumnTypesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemElementsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemElementsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemElementsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRStoreRstore = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTupleRtuple = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeParameter = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeUserDefined = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeRelation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeBag = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeSet = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeTuple = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeLoc = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeStr = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeBool = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeInt = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemTuple = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemBag = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemSet = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemLoc = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemBool = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemStr = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemInt = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
