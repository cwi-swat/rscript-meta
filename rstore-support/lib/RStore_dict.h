#ifndef __RStore_dict_H
#define __RStore_dict_H

#include <aterm2.h>

extern AFun RS_afun8;
extern AFun RS_afun21;
extern AFun RS_afun17;
extern AFun RS_afun0;
extern AFun RS_afun11;
extern AFun RS_afun5;
extern AFun RS_afun3;
extern AFun RS_afun9;
extern AFun RS_afun16;
extern AFun RS_afun10;
extern AFun RS_afun4;
extern AFun RS_afun13;
extern AFun RS_afun14;
extern AFun RS_afun19;
extern AFun RS_afun2;
extern AFun RS_afun7;
extern AFun RS_afun12;
extern AFun RS_afun15;
extern AFun RS_afun18;
extern AFun RS_afun6;
extern AFun RS_afun1;
extern AFun RS_afun20;

extern ATerm RS_patternAreaArea;
extern ATerm RS_patternLocationAreaInFile;
extern ATerm RS_patternLocationArea;
extern ATerm RS_patternLocationFile;
extern ATerm RS_patternIntConIntCon;
extern ATerm RS_patternIdConIdCon;
extern ATerm RS_patternNatConNatCon;
extern ATerm RS_patternBoolConFalse;
extern ATerm RS_patternBoolConTrue;
extern ATerm RS_patternStrConStrCon;
extern ATerm RS_patternStrCharStrChar;
extern ATerm RS_patternRTupleRtuplesMany;
extern ATerm RS_patternRTupleRtuplesSingle;
extern ATerm RS_patternRTupleRtuplesEmpty;
extern ATerm RS_patternRTypeColumnTypesMany;
extern ATerm RS_patternRTypeColumnTypesSingle;
extern ATerm RS_patternRTypeColumnTypesEmpty;
extern ATerm RS_patternRElemElementsMany;
extern ATerm RS_patternRElemElementsSingle;
extern ATerm RS_patternRElemElementsEmpty;
extern ATerm RS_patternRStoreRstore;
extern ATerm RS_patternRTupleRtuple;
extern ATerm RS_patternRTypeParameter;
extern ATerm RS_patternRTypeUserDefined;
extern ATerm RS_patternRTypeRelation;
extern ATerm RS_patternRTypeBag;
extern ATerm RS_patternRTypeSet;
extern ATerm RS_patternRTypeTuple;
extern ATerm RS_patternRTypeLoc;
extern ATerm RS_patternRTypeStr;
extern ATerm RS_patternRTypeBool;
extern ATerm RS_patternRTypeInt;
extern ATerm RS_patternRElemTuple;
extern ATerm RS_patternRElemBag;
extern ATerm RS_patternRElemSet;
extern ATerm RS_patternRElemLoc;
extern ATerm RS_patternRElemBool;
extern ATerm RS_patternRElemStr;
extern ATerm RS_patternRElemInt;

extern void init_RStore_dict();

#endif /* __RStore_dict_H */
