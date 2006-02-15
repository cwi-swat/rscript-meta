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
AFun RS_afun6;
AFun RS_afun1;

ATerm RS_patternAreaArea = NULL;
ATerm RS_patternLocationAreaInFile = NULL;
ATerm RS_patternLocationArea = NULL;
ATerm RS_patternLocationFile = NULL;
ATerm RS_patternNatConNatCon = NULL;
ATerm RS_patternStrConStrCon = NULL;
ATerm RS_patternStrCharStrChar = NULL;
ATerm RS_patternRTupleListMany = NULL;
ATerm RS_patternRTupleListSingle = NULL;
ATerm RS_patternRTupleListEmpty = NULL;
ATerm RS_patternRTypeListMany = NULL;
ATerm RS_patternRTypeListSingle = NULL;
ATerm RS_patternRTypeListEmpty = NULL;
ATerm RS_patternRElemListMany = NULL;
ATerm RS_patternRElemListSingle = NULL;
ATerm RS_patternRElemListEmpty = NULL;
ATerm RS_patternRStoreRstore = NULL;
ATerm RS_patternRTupleRtuple = NULL;
ATerm RS_patternRTypeParameter = NULL;
ATerm RS_patternRTypeUser = NULL;
ATerm RS_patternRTypeRel = NULL;
ATerm RS_patternRTypeBag = NULL;
ATerm RS_patternRTypeSet = NULL;
ATerm RS_patternRTypeTuple = NULL;
ATerm RS_patternRTypeLoc = NULL;
ATerm RS_patternRTypeStr = NULL;
ATerm RS_patternRTypeInt = NULL;
ATerm RS_patternRElemTuple = NULL;
ATerm RS_patternRElemBag = NULL;
ATerm RS_patternRElemSet = NULL;
ATerm RS_patternRElemLoc = NULL;
ATerm RS_patternRElemStr = NULL;
ATerm RS_patternRElemInt = NULL;

/*
 * RS_afun8 = "loc"
 * RS_afun17 = "area"(x,x,x,x,x,x)
 * RS_afun0 = "int"(x)
 * RS_afun11 = "parameter"(x)
 * RS_afun5 = "tuple"(x)
 * RS_afun3 = "set"(x)
 * RS_afun9 = "rel"(x)
 * RS_afun16 = "area-in-file"(x,x)
 * RS_afun10 = "user"(x)
 * RS_afun4 = "bag"(x)
 * RS_afun13 = "rstore"(x)
 * RS_afun14 = "file"(x)
 * RS_afun2 = "loc"(x)
 * RS_afun7 = "str"
 * RS_afun12 = "rtuple"(x,x,x)
 * RS_afun15 = "area"(x)
 * RS_afun6 = "int"
 * RS_afun1 = "str"(x)
 *
 * RS_patternAreaArea = "area"(<int>,<int>,<int>,<int>,<int>,<int>)
 * RS_patternLocationAreaInFile = "area-in-file"(<str>,<term>)
 * RS_patternLocationArea = "area"(<term>)
 * RS_patternLocationFile = "file"(<str>)
 * RS_patternNatConNatCon = <str>
 * RS_patternStrConStrCon = <str>
 * RS_patternStrCharStrChar = <str>
 * RS_patternRTupleListMany = [<term>,<list>]
 * RS_patternRTupleListSingle = [<term>]
 * RS_patternRTupleListEmpty = []
 * RS_patternRTypeListMany = [<term>,<list>]
 * RS_patternRTypeListSingle = [<term>]
 * RS_patternRTypeListEmpty = []
 * RS_patternRElemListMany = [<term>,<list>]
 * RS_patternRElemListSingle = [<term>]
 * RS_patternRElemListEmpty = []
 * RS_patternRStoreRstore = "rstore"(<term>)
 * RS_patternRTupleRtuple = "rtuple"(<str>,<term>,<term>)
 * RS_patternRTypeParameter = "parameter"(<str>)
 * RS_patternRTypeUser = "user"(<str>)
 * RS_patternRTypeRel = "rel"(<term>)
 * RS_patternRTypeBag = "bag"(<term>)
 * RS_patternRTypeSet = "set"(<term>)
 * RS_patternRTypeTuple = "tuple"(<term>)
 * RS_patternRTypeLoc = "loc"
 * RS_patternRTypeStr = "str"
 * RS_patternRTypeInt = "int"
 * RS_patternRElemTuple = "tuple"(<term>)
 * RS_patternRElemBag = "bag"(<term>)
 * RS_patternRElemSet = "set"(<term>)
 * RS_patternRElemLoc = "loc"(<term>)
 * RS_patternRElemStr = "str"(<str>)
 * RS_patternRElemInt = "int"(<int>)
 *
 */

static ATerm _RStore_dict = NULL;

#define _RStore_dict_LEN 443

static char _RStore_dict_baf[_RStore_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x1A,0x63,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x05,
0x06,0x04,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x38,0x15,0x01,0x02,0x00,
0x07,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
0x18,0x19,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,
0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,
0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x03,0x6C,0x6F,0x63,0x00,0x01,0x01,
0x01,0x78,0x00,0x00,0x01,0x04,0x61,0x72,0x65,0x61,0x06,0x01,0x02,0x02,0x00,0x08,
0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x03,
0x69,0x6E,0x74,0x01,0x01,0x02,0x02,0x00,0x08,0x09,0x70,0x61,0x72,0x61,0x6D,0x65,
0x74,0x65,0x72,0x01,0x01,0x02,0x02,0x00,0x08,0x05,0x74,0x75,0x70,0x6C,0x65,0x01,
0x01,0x02,0x02,0x00,0x08,0x03,0x73,0x65,0x74,0x01,0x01,0x02,0x02,0x00,0x08,0x03,
0x72,0x65,0x6C,0x01,0x01,0x02,0x02,0x00,0x08,0x0C,0x61,0x72,0x65,0x61,0x2D,0x69,
0x6E,0x2D,0x66,0x69,0x6C,0x65,0x02,0x01,0x02,0x02,0x00,0x08,0x02,0x00,0x08,0x04,
0x75,0x73,0x65,0x72,0x01,0x01,0x02,0x02,0x00,0x08,0x03,0x62,0x61,0x67,0x01,0x01,
0x02,0x02,0x00,0x08,0x06,0x72,0x73,0x74,0x6F,0x72,0x65,0x01,0x01,0x02,0x02,0x00,
0x08,0x04,0x66,0x69,0x6C,0x65,0x01,0x01,0x02,0x02,0x00,0x08,0x03,0x6C,0x6F,0x63,
0x01,0x01,0x02,0x02,0x00,0x08,0x03,0x73,0x74,0x72,0x00,0x01,0x01,0x06,0x72,0x74,
0x75,0x70,0x6C,0x65,0x03,0x01,0x02,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,
0x04,0x61,0x72,0x65,0x61,0x01,0x01,0x02,0x02,0x00,0x08,0x03,0x69,0x6E,0x74,0x00,
0x01,0x01,0x03,0x73,0x74,0x72,0x01,0x01,0x02,0x02,0x00,0x08,0x01,0x04,0x58,0x02,
0x21,0x55,0x47,0x94,0x21,0xC6,0x11,0x67,0x08,0x30,0x44,0x69,0x22,0x14,0x51,0x44,
0x9A,0x20,0x43,0x11,0xC5,0x88,0x61,0xC4,0x51,0xE2,0x08,0x09,0x84,0x4A,0x84,0x12,
0x44,0x19,0x00,0x29,0x43,0x60,0xAC,0x90,0x30,0x00,0x00,0x00,0x2D,0x51,0x10,0xA1,
0x9A,0x61,0x09,0xBA,0x21,0x1A,0x20,0x1A,0x21,0xEA,0x20,0xE8,0x32,0x42,0x12,0x46,
0x11,0x68,0x0A,0x42,0x83,0x60,0x6A,0x0C,0x85,0x40,0x51,0x2C,0x01,0x41,0x91,0xC8,
0x0A,0x19,0x81,0x4D,0xA1,0x04,0xC6,0x20,0x84,0x62,0xC8,0x82,0x3A,0x88,0x43,0x28,
0x40,0x26,0x84,0x7C,0x28,0x43,0xDC,0x84,0x5D,0x80,0xE0,0x9B,0x64,0x5B,0x91,0x31,
0xA0,0x61,0x47,0x5E,0x84,0x34,0x58,0x85,0x54,0x81,0x40
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
  RS_patternNatConNatCon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternStrConStrCon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternStrCharStrChar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTupleListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTupleListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTupleListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRStoreRstore = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTupleRtuple = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeParameter = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeUser = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRTypeRel = ATgetFirst(terms);
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
  RS_patternRElemStr = ATgetFirst(terms);
  terms = ATgetNext(terms);
  RS_patternRElemInt = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
