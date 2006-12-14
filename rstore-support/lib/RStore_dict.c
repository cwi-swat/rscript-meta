#include "RStore_dict.h"

AFun RS_afun8;
AFun RS_afun17;
AFun RS_afun0;
AFun RS_afun11;
AFun RS_afun5;
AFun RS_afun3;
AFun RS_afun9;
AFun RS_afun16;
AFun RS_afun10;
AFun RS_afun4;
AFun RS_afun13;
AFun RS_afun14;
AFun RS_afun2;
AFun RS_afun7;
AFun RS_afun12;
AFun RS_afun15;
AFun RS_afun18;
AFun RS_afun6;
AFun RS_afun1;

ATerm RS_patternAreaArea = NULL;
ATerm RS_patternLocationAreaInFile = NULL;
ATerm RS_patternLocationArea = NULL;
ATerm RS_patternLocationFile = NULL;
ATerm RS_patternIntConIntCon = NULL;
ATerm RS_patternIdConIdCon = NULL;
ATerm RS_patternNatConNatCon = NULL;
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
ATerm RS_patternRTypeLocation = NULL;
ATerm RS_patternRTypeString = NULL;
ATerm RS_patternRTypeBoolean = NULL;
ATerm RS_patternRTypeInteger = NULL;
ATerm RS_patternRElemTuple = NULL;
ATerm RS_patternRElemBag = NULL;
ATerm RS_patternRElemSet = NULL;
ATerm RS_patternRElemLocation = NULL;
ATerm RS_patternRElemString = NULL;
ATerm RS_patternRElemInteger = NULL;

/*
 * RS_afun8 = string
 * RS_afun17 = area-in-file(x,x)
 * RS_afun0 = integer(x)
 * RS_afun11 = user-defined(x)
 * RS_afun5 = tuple(x)
 * RS_afun3 = set(x)
 * RS_afun9 = location
 * RS_afun16 = area(x)
 * RS_afun10 = relation(x)
 * RS_afun4 = bag(x)
 * RS_afun13 = rtuple(x,x,x)
 * RS_afun14 = rstore(x)
 * RS_afun2 = location(x)
 * RS_afun7 = boolean
 * RS_afun12 = parameter(x)
 * RS_afun15 = file(x)
 * RS_afun18 = area(x,x,x,x,x,x)
 * RS_afun6 = integer
 * RS_afun1 = string(x)
 *
 * RS_patternAreaArea = area(<int>,<int>,<int>,<int>,<int>,<int>)
 * RS_patternLocationAreaInFile = area-in-file(<str>,<term>)
 * RS_patternLocationArea = area(<term>)
 * RS_patternLocationFile = file(<str>)
 * RS_patternIntConIntCon = <str>
 * RS_patternIdConIdCon = <str>
 * RS_patternNatConNatCon = <str>
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
 * RS_patternRTypeLocation = location
 * RS_patternRTypeString = string
 * RS_patternRTypeBoolean = boolean
 * RS_patternRTypeInteger = integer
 * RS_patternRElemTuple = tuple(<term>)
 * RS_patternRElemBag = bag(<term>)
 * RS_patternRElemSet = set(<term>)
 * RS_patternRElemLocation = location(<term>)
 * RS_patternRElemString = string(<str>)
 * RS_patternRElemInteger = integer(<term>)
 *
 */

static ATerm _RStore_dict = NULL;

#define _RStore_dict_LEN 499

static char _RStore_dict_baf[_RStore_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x1B,0x68,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x05,
0x06,0x04,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x3C,0x16,0x01,0x02,0x00,
0x07,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
0x18,0x19,0x1A,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,
0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,
0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x06,0x73,0x74,0x72,0x69,0x6E,
0x67,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x0C,0x61,0x72,0x65,0x61,0x2D,0x69,
0x6E,0x2D,0x66,0x69,0x6C,0x65,0x02,0x00,0x02,0x02,0x00,0x08,0x02,0x00,0x08,0x07,
0x69,0x6E,0x74,0x65,0x67,0x65,0x72,0x01,0x00,0x02,0x02,0x00,0x08,0x0C,0x75,0x73,
0x65,0x72,0x2D,0x64,0x65,0x66,0x69,0x6E,0x65,0x64,0x01,0x00,0x02,0x02,0x00,0x08,
0x05,0x74,0x75,0x70,0x6C,0x65,0x01,0x00,0x02,0x02,0x00,0x08,0x03,0x73,0x65,0x74,
0x01,0x00,0x02,0x02,0x00,0x08,0x08,0x6C,0x6F,0x63,0x61,0x74,0x69,0x6F,0x6E,0x00,
0x00,0x01,0x04,0x61,0x72,0x65,0x61,0x01,0x00,0x02,0x02,0x00,0x08,0x08,0x72,0x65,
0x6C,0x61,0x74,0x69,0x6F,0x6E,0x01,0x00,0x02,0x02,0x00,0x08,0x03,0x62,0x61,0x67,
0x01,0x00,0x02,0x02,0x00,0x08,0x06,0x72,0x74,0x75,0x70,0x6C,0x65,0x03,0x00,0x02,
0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x06,0x72,0x73,0x74,0x6F,0x72,0x65,
0x01,0x00,0x02,0x02,0x00,0x08,0x08,0x6C,0x6F,0x63,0x61,0x74,0x69,0x6F,0x6E,0x01,
0x00,0x02,0x02,0x00,0x08,0x07,0x62,0x6F,0x6F,0x6C,0x65,0x61,0x6E,0x00,0x00,0x01,
0x09,0x70,0x61,0x72,0x61,0x6D,0x65,0x74,0x65,0x72,0x01,0x00,0x02,0x02,0x00,0x08,
0x04,0x66,0x69,0x6C,0x65,0x01,0x00,0x02,0x02,0x00,0x08,0x04,0x61,0x72,0x65,0x61,
0x06,0x00,0x02,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,
0x00,0x08,0x02,0x00,0x08,0x07,0x69,0x6E,0x74,0x65,0x67,0x65,0x72,0x00,0x00,0x01,
0x06,0x73,0x74,0x72,0x69,0x6E,0x67,0x01,0x00,0x02,0x02,0x00,0x08,0x01,0x02,0x58,
0x22,0x21,0x40,0x54,0x23,0xC6,0x10,0xE7,0x08,0xB0,0x44,0x19,0x23,0x45,0x10,0xA6,
0x88,0x90,0xC4,0x09,0x62,0xA3,0x87,0x10,0xC7,0x88,0xA0,0x21,0x11,0x23,0x04,0x90,
0x86,0x4A,0xAA,0x20,0x28,0x05,0x4A,0x17,0x04,0xF9,0x81,0x80,0x00,0x00,0x00,0xE4,
0x88,0x85,0x0E,0xD5,0x08,0x6D,0x31,0x0A,0xD1,0x02,0xD1,0x0C,0xD1,0x04,0xD1,0x08,
0xD1,0x00,0xC0,0x52,0x11,0x92,0x30,0x8F,0x41,0x52,0x14,0x3B,0x02,0xD0,0x14,0x1A,
0x0A,0x8D,0x60,0x2A,0x02,0x89,0x41,0x50,0x2C,0x0E,0x5D,0x08,0x66,0xD0,0x84,0x22,
0x98,0xC2,0x09,0x64,0x23,0x1D,0x42,0x11,0x34,0x22,0x11,0x42,0x01,0xE4,0x23,0xE9,
0x0F,0x60,0xB8,0x21,0xC5,0x36,0xE4,0x2C,0x68,0x98,0x50,0x37,0xA1,0x1D,0x56,0x20,
0xD5,0x21,0x50
};

void init_RStore_dict()
{
  ATermList afuns, terms;

  _RStore_dict = ATreadFromBinaryString(_RStore_dict_baf, _RStore_dict_LEN);

  ATprotect(&_RStore_dict);

  afuns = (ATermList)ATelementAt((ATermList)_RStore_dict, 0);

  RS_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  RS_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
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
  RS_patternIntConIntCon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternIdConIdCon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternNatConNatCon = ATgetFirst(terms);
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
  RS_patternRTypeLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeString = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeBoolean = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeInteger = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemTuple = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemBag = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemSet = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemString = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemInteger = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
