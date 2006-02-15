#ifndef _RSTORE_H
#define _RSTORE_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "RStore_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _RS_RElem *RS_RElem;
typedef struct _RS_RType *RS_RType;
typedef struct _RS_RTuple *RS_RTuple;
typedef struct _RS_RStore *RS_RStore;
typedef struct _RS_RElemList *RS_RElemList;
typedef struct _RS_RTypeList *RS_RTypeList;
typedef struct _RS_RTupleList *RS_RTupleList;
typedef struct _RS_StrChar *RS_StrChar;
typedef struct _RS_StrCon *RS_StrCon;
typedef struct _RS_NatCon *RS_NatCon;
typedef struct _RS_Location *RS_Location;
typedef struct _RS_Area *RS_Area;

/*}}}  */

void RS_initRStoreApi(void);

/*{{{  protect functions */

void RS_protectRElem(RS_RElem * arg);
void RS_protectRType(RS_RType * arg);
void RS_protectRTuple(RS_RTuple * arg);
void RS_protectRStore(RS_RStore * arg);
void RS_protectRElemList(RS_RElemList * arg);
void RS_protectRTypeList(RS_RTypeList * arg);
void RS_protectRTupleList(RS_RTupleList * arg);
void RS_protectStrChar(RS_StrChar * arg);
void RS_protectStrCon(RS_StrCon * arg);
void RS_protectNatCon(RS_NatCon * arg);
void RS_protectLocation(RS_Location * arg);
void RS_protectArea(RS_Area * arg);

/*}}}  */
/*{{{  term conversion functions */

RS_RElem RS_RElemFromTerm(ATerm t);
ATerm RS_RElemToTerm(RS_RElem arg);
RS_RType RS_RTypeFromTerm(ATerm t);
ATerm RS_RTypeToTerm(RS_RType arg);
RS_RTuple RS_RTupleFromTerm(ATerm t);
ATerm RS_RTupleToTerm(RS_RTuple arg);
RS_RStore RS_RStoreFromTerm(ATerm t);
ATerm RS_RStoreToTerm(RS_RStore arg);
RS_RElemList RS_RElemListFromTerm(ATerm t);
ATerm RS_RElemListToTerm(RS_RElemList arg);
RS_RTypeList RS_RTypeListFromTerm(ATerm t);
ATerm RS_RTypeListToTerm(RS_RTypeList arg);
RS_RTupleList RS_RTupleListFromTerm(ATerm t);
ATerm RS_RTupleListToTerm(RS_RTupleList arg);
RS_StrChar RS_StrCharFromTerm(ATerm t);
ATerm RS_StrCharToTerm(RS_StrChar arg);
RS_StrCon RS_StrConFromTerm(ATerm t);
ATerm RS_StrConToTerm(RS_StrCon arg);
RS_NatCon RS_NatConFromTerm(ATerm t);
ATerm RS_NatConToTerm(RS_NatCon arg);
RS_Location RS_LocationFromTerm(ATerm t);
ATerm RS_LocationToTerm(RS_Location arg);
RS_Area RS_AreaFromTerm(ATerm t);
ATerm RS_AreaToTerm(RS_Area arg);

/*}}}  */
/*{{{  list functions */

int RS_getRElemListLength(RS_RElemList arg);
RS_RElemList RS_reverseRElemList(RS_RElemList arg);
RS_RElemList RS_appendRElemList(RS_RElemList arg, RS_RElem elem);
RS_RElemList RS_concatRElemList(RS_RElemList arg0, RS_RElemList arg1);
RS_RElemList RS_sliceRElemList(RS_RElemList arg, int start, int end);
RS_RElem RS_getRElemListRElemAt(RS_RElemList arg, int index);
RS_RElemList RS_replaceRElemListRElemAt(RS_RElemList arg, RS_RElem elem,
					int index);
RS_RElemList RS_makeRElemList2(RS_RElem elem1, RS_RElem elem2);
RS_RElemList RS_makeRElemList3(RS_RElem elem1, RS_RElem elem2,
			       RS_RElem elem3);
RS_RElemList RS_makeRElemList4(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3,
			       RS_RElem elem4);
RS_RElemList RS_makeRElemList5(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3,
			       RS_RElem elem4, RS_RElem elem5);
RS_RElemList RS_makeRElemList6(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3,
			       RS_RElem elem4, RS_RElem elem5,
			       RS_RElem elem6);
int RS_getRTypeListLength(RS_RTypeList arg);
RS_RTypeList RS_reverseRTypeList(RS_RTypeList arg);
RS_RTypeList RS_appendRTypeList(RS_RTypeList arg, RS_RType elem);
RS_RTypeList RS_concatRTypeList(RS_RTypeList arg0, RS_RTypeList arg1);
RS_RTypeList RS_sliceRTypeList(RS_RTypeList arg, int start, int end);
RS_RType RS_getRTypeListRTypeAt(RS_RTypeList arg, int index);
RS_RTypeList RS_replaceRTypeListRTypeAt(RS_RTypeList arg, RS_RType elem,
					int index);
RS_RTypeList RS_makeRTypeList2(RS_RType elem1, RS_RType elem2);
RS_RTypeList RS_makeRTypeList3(RS_RType elem1, RS_RType elem2,
			       RS_RType elem3);
RS_RTypeList RS_makeRTypeList4(RS_RType elem1, RS_RType elem2, RS_RType elem3,
			       RS_RType elem4);
RS_RTypeList RS_makeRTypeList5(RS_RType elem1, RS_RType elem2, RS_RType elem3,
			       RS_RType elem4, RS_RType elem5);
RS_RTypeList RS_makeRTypeList6(RS_RType elem1, RS_RType elem2, RS_RType elem3,
			       RS_RType elem4, RS_RType elem5,
			       RS_RType elem6);
int RS_getRTupleListLength(RS_RTupleList arg);
RS_RTupleList RS_reverseRTupleList(RS_RTupleList arg);
RS_RTupleList RS_appendRTupleList(RS_RTupleList arg, RS_RTuple elem);
RS_RTupleList RS_concatRTupleList(RS_RTupleList arg0, RS_RTupleList arg1);
RS_RTupleList RS_sliceRTupleList(RS_RTupleList arg, int start, int end);
RS_RTuple RS_getRTupleListRTupleAt(RS_RTupleList arg, int index);
RS_RTupleList RS_replaceRTupleListRTupleAt(RS_RTupleList arg, RS_RTuple elem,
					   int index);
RS_RTupleList RS_makeRTupleList2(RS_RTuple elem1, RS_RTuple elem2);
RS_RTupleList RS_makeRTupleList3(RS_RTuple elem1, RS_RTuple elem2,
				 RS_RTuple elem3);
RS_RTupleList RS_makeRTupleList4(RS_RTuple elem1, RS_RTuple elem2,
				 RS_RTuple elem3, RS_RTuple elem4);
RS_RTupleList RS_makeRTupleList5(RS_RTuple elem1, RS_RTuple elem2,
				 RS_RTuple elem3, RS_RTuple elem4,
				 RS_RTuple elem5);
RS_RTupleList RS_makeRTupleList6(RS_RTuple elem1, RS_RTuple elem2,
				 RS_RTuple elem3, RS_RTuple elem4,
				 RS_RTuple elem5, RS_RTuple elem6);

/*}}}  */
/*{{{  constructors */

RS_RElem RS_makeRElemInt(int intValue);
RS_RElem RS_makeRElemStr(const char *strValue);
RS_RElem RS_makeRElemLoc(RS_Location locValue);
RS_RElem RS_makeRElemSet(RS_RElemList list);
RS_RElem RS_makeRElemBag(RS_RElemList list);
RS_RElem RS_makeRElemTuple(RS_RElemList list);
RS_RType RS_makeRTypeInt(void);
RS_RType RS_makeRTypeStr(void);
RS_RType RS_makeRTypeLoc(void);
RS_RType RS_makeRTypeTuple(RS_RTypeList list);
RS_RType RS_makeRTypeSet(RS_RType RType);
RS_RType RS_makeRTypeBag(RS_RType RType);
RS_RType RS_makeRTypeRel(RS_RTypeList list);
RS_RType RS_makeRTypeUser(const char *StrCon);
RS_RType RS_makeRTypeParameter(const char *StrCon);
RS_RTuple RS_makeRTupleRtuple(const char *id, RS_RType type, RS_RElem data);
RS_RStore RS_makeRStoreRstore(RS_RTupleList list);
RS_RElemList RS_makeRElemListEmpty(void);
RS_RElemList RS_makeRElemListSingle(RS_RElem head);
RS_RElemList RS_makeRElemListMany(RS_RElem head, RS_RElemList tail);
RS_RTypeList RS_makeRTypeListEmpty(void);
RS_RTypeList RS_makeRTypeListSingle(RS_RType head);
RS_RTypeList RS_makeRTypeListMany(RS_RType head, RS_RTypeList tail);
RS_RTupleList RS_makeRTupleListEmpty(void);
RS_RTupleList RS_makeRTupleListSingle(RS_RTuple head);
RS_RTupleList RS_makeRTupleListMany(RS_RTuple head, RS_RTupleList tail);
RS_StrChar RS_makeStrCharStrChar(const char *string);
RS_StrCon RS_makeStrConStrCon(const char *string);
RS_NatCon RS_makeNatConNatCon(const char *string);
RS_Location RS_makeLocationFile(const char *filename);
RS_Location RS_makeLocationArea(RS_Area Area);
RS_Location RS_makeLocationAreaInFile(const char *filename, RS_Area Area);
RS_Area RS_makeAreaArea(int beginLine, int beginColumn, int endLine,
			int endColumn, int offset, int length);

/*}}}  */
/*{{{  equality functions */

ATbool RS_isEqualRElem(RS_RElem arg0, RS_RElem arg1);
ATbool RS_isEqualRType(RS_RType arg0, RS_RType arg1);
ATbool RS_isEqualRTuple(RS_RTuple arg0, RS_RTuple arg1);
ATbool RS_isEqualRStore(RS_RStore arg0, RS_RStore arg1);
ATbool RS_isEqualRElemList(RS_RElemList arg0, RS_RElemList arg1);
ATbool RS_isEqualRTypeList(RS_RTypeList arg0, RS_RTypeList arg1);
ATbool RS_isEqualRTupleList(RS_RTupleList arg0, RS_RTupleList arg1);
ATbool RS_isEqualStrChar(RS_StrChar arg0, RS_StrChar arg1);
ATbool RS_isEqualStrCon(RS_StrCon arg0, RS_StrCon arg1);
ATbool RS_isEqualNatCon(RS_NatCon arg0, RS_NatCon arg1);
ATbool RS_isEqualLocation(RS_Location arg0, RS_Location arg1);
ATbool RS_isEqualArea(RS_Area arg0, RS_Area arg1);

/*}}}  */
/*{{{  RS_RElem accessors */

ATbool RS_isValidRElem(RS_RElem arg);
inline ATbool RS_isRElemInt(RS_RElem arg);
inline ATbool RS_isRElemStr(RS_RElem arg);
inline ATbool RS_isRElemLoc(RS_RElem arg);
inline ATbool RS_isRElemSet(RS_RElem arg);
inline ATbool RS_isRElemBag(RS_RElem arg);
inline ATbool RS_isRElemTuple(RS_RElem arg);
ATbool RS_hasRElemIntValue(RS_RElem arg);
ATbool RS_hasRElemStrValue(RS_RElem arg);
ATbool RS_hasRElemLocValue(RS_RElem arg);
ATbool RS_hasRElemList(RS_RElem arg);
int RS_getRElemIntValue(RS_RElem arg);
char *RS_getRElemStrValue(RS_RElem arg);
RS_Location RS_getRElemLocValue(RS_RElem arg);
RS_RElemList RS_getRElemList(RS_RElem arg);
RS_RElem RS_setRElemIntValue(RS_RElem arg, int intValue);
RS_RElem RS_setRElemStrValue(RS_RElem arg, const char *strValue);
RS_RElem RS_setRElemLocValue(RS_RElem arg, RS_Location locValue);
RS_RElem RS_setRElemList(RS_RElem arg, RS_RElemList list);

/*}}}  */
/*{{{  RS_RType accessors */

ATbool RS_isValidRType(RS_RType arg);
inline ATbool RS_isRTypeInt(RS_RType arg);
inline ATbool RS_isRTypeStr(RS_RType arg);
inline ATbool RS_isRTypeLoc(RS_RType arg);
inline ATbool RS_isRTypeTuple(RS_RType arg);
inline ATbool RS_isRTypeSet(RS_RType arg);
inline ATbool RS_isRTypeBag(RS_RType arg);
inline ATbool RS_isRTypeRel(RS_RType arg);
inline ATbool RS_isRTypeUser(RS_RType arg);
inline ATbool RS_isRTypeParameter(RS_RType arg);
ATbool RS_hasRTypeList(RS_RType arg);
ATbool RS_hasRTypeRType(RS_RType arg);
ATbool RS_hasRTypeStrCon(RS_RType arg);
RS_RTypeList RS_getRTypeList(RS_RType arg);
RS_RType RS_getRTypeRType(RS_RType arg);
char *RS_getRTypeStrCon(RS_RType arg);
RS_RType RS_setRTypeList(RS_RType arg, RS_RTypeList list);
RS_RType RS_setRTypeRType(RS_RType arg, RS_RType RType);
RS_RType RS_setRTypeStrCon(RS_RType arg, const char *StrCon);

/*}}}  */
/*{{{  RS_RTuple accessors */

ATbool RS_isValidRTuple(RS_RTuple arg);
inline ATbool RS_isRTupleRtuple(RS_RTuple arg);
ATbool RS_hasRTupleId(RS_RTuple arg);
ATbool RS_hasRTupleType(RS_RTuple arg);
ATbool RS_hasRTupleData(RS_RTuple arg);
char *RS_getRTupleId(RS_RTuple arg);
RS_RType RS_getRTupleType(RS_RTuple arg);
RS_RElem RS_getRTupleData(RS_RTuple arg);
RS_RTuple RS_setRTupleId(RS_RTuple arg, const char *id);
RS_RTuple RS_setRTupleType(RS_RTuple arg, RS_RType type);
RS_RTuple RS_setRTupleData(RS_RTuple arg, RS_RElem data);

/*}}}  */
/*{{{  RS_RStore accessors */

ATbool RS_isValidRStore(RS_RStore arg);
inline ATbool RS_isRStoreRstore(RS_RStore arg);
ATbool RS_hasRStoreList(RS_RStore arg);
RS_RTupleList RS_getRStoreList(RS_RStore arg);
RS_RStore RS_setRStoreList(RS_RStore arg, RS_RTupleList list);

/*}}}  */
/*{{{  RS_RElemList accessors */

ATbool RS_isValidRElemList(RS_RElemList arg);
inline ATbool RS_isRElemListEmpty(RS_RElemList arg);
inline ATbool RS_isRElemListSingle(RS_RElemList arg);
inline ATbool RS_isRElemListMany(RS_RElemList arg);
ATbool RS_hasRElemListHead(RS_RElemList arg);
ATbool RS_hasRElemListTail(RS_RElemList arg);
RS_RElem RS_getRElemListHead(RS_RElemList arg);
RS_RElemList RS_getRElemListTail(RS_RElemList arg);
RS_RElemList RS_setRElemListHead(RS_RElemList arg, RS_RElem head);
RS_RElemList RS_setRElemListTail(RS_RElemList arg, RS_RElemList tail);

/*}}}  */
/*{{{  RS_RTypeList accessors */

ATbool RS_isValidRTypeList(RS_RTypeList arg);
inline ATbool RS_isRTypeListEmpty(RS_RTypeList arg);
inline ATbool RS_isRTypeListSingle(RS_RTypeList arg);
inline ATbool RS_isRTypeListMany(RS_RTypeList arg);
ATbool RS_hasRTypeListHead(RS_RTypeList arg);
ATbool RS_hasRTypeListTail(RS_RTypeList arg);
RS_RType RS_getRTypeListHead(RS_RTypeList arg);
RS_RTypeList RS_getRTypeListTail(RS_RTypeList arg);
RS_RTypeList RS_setRTypeListHead(RS_RTypeList arg, RS_RType head);
RS_RTypeList RS_setRTypeListTail(RS_RTypeList arg, RS_RTypeList tail);

/*}}}  */
/*{{{  RS_RTupleList accessors */

ATbool RS_isValidRTupleList(RS_RTupleList arg);
inline ATbool RS_isRTupleListEmpty(RS_RTupleList arg);
inline ATbool RS_isRTupleListSingle(RS_RTupleList arg);
inline ATbool RS_isRTupleListMany(RS_RTupleList arg);
ATbool RS_hasRTupleListHead(RS_RTupleList arg);
ATbool RS_hasRTupleListTail(RS_RTupleList arg);
RS_RTuple RS_getRTupleListHead(RS_RTupleList arg);
RS_RTupleList RS_getRTupleListTail(RS_RTupleList arg);
RS_RTupleList RS_setRTupleListHead(RS_RTupleList arg, RS_RTuple head);
RS_RTupleList RS_setRTupleListTail(RS_RTupleList arg, RS_RTupleList tail);

/*}}}  */
/*{{{  RS_StrChar accessors */

ATbool RS_isValidStrChar(RS_StrChar arg);
inline ATbool RS_isStrCharStrChar(RS_StrChar arg);
ATbool RS_hasStrCharString(RS_StrChar arg);
char *RS_getStrCharString(RS_StrChar arg);
RS_StrChar RS_setStrCharString(RS_StrChar arg, const char *string);

/*}}}  */
/*{{{  RS_StrCon accessors */

ATbool RS_isValidStrCon(RS_StrCon arg);
inline ATbool RS_isStrConStrCon(RS_StrCon arg);
ATbool RS_hasStrConString(RS_StrCon arg);
char *RS_getStrConString(RS_StrCon arg);
RS_StrCon RS_setStrConString(RS_StrCon arg, const char *string);

/*}}}  */
/*{{{  RS_NatCon accessors */

ATbool RS_isValidNatCon(RS_NatCon arg);
inline ATbool RS_isNatConNatCon(RS_NatCon arg);
ATbool RS_hasNatConString(RS_NatCon arg);
char *RS_getNatConString(RS_NatCon arg);
RS_NatCon RS_setNatConString(RS_NatCon arg, const char *string);

/*}}}  */
/*{{{  RS_Location accessors */

ATbool RS_isValidLocation(RS_Location arg);
inline ATbool RS_isLocationFile(RS_Location arg);
inline ATbool RS_isLocationArea(RS_Location arg);
inline ATbool RS_isLocationAreaInFile(RS_Location arg);
ATbool RS_hasLocationFilename(RS_Location arg);
ATbool RS_hasLocationArea(RS_Location arg);
char *RS_getLocationFilename(RS_Location arg);
RS_Area RS_getLocationArea(RS_Location arg);
RS_Location RS_setLocationFilename(RS_Location arg, const char *filename);
RS_Location RS_setLocationArea(RS_Location arg, RS_Area Area);

/*}}}  */
/*{{{  RS_Area accessors */

ATbool RS_isValidArea(RS_Area arg);
inline ATbool RS_isAreaArea(RS_Area arg);
ATbool RS_hasAreaBeginLine(RS_Area arg);
ATbool RS_hasAreaBeginColumn(RS_Area arg);
ATbool RS_hasAreaEndLine(RS_Area arg);
ATbool RS_hasAreaEndColumn(RS_Area arg);
ATbool RS_hasAreaOffset(RS_Area arg);
ATbool RS_hasAreaLength(RS_Area arg);
int RS_getAreaBeginLine(RS_Area arg);
int RS_getAreaBeginColumn(RS_Area arg);
int RS_getAreaEndLine(RS_Area arg);
int RS_getAreaEndColumn(RS_Area arg);
int RS_getAreaOffset(RS_Area arg);
int RS_getAreaLength(RS_Area arg);
RS_Area RS_setAreaBeginLine(RS_Area arg, int beginLine);
RS_Area RS_setAreaBeginColumn(RS_Area arg, int beginColumn);
RS_Area RS_setAreaEndLine(RS_Area arg, int endLine);
RS_Area RS_setAreaEndColumn(RS_Area arg, int endColumn);
RS_Area RS_setAreaOffset(RS_Area arg, int offset);
RS_Area RS_setAreaLength(RS_Area arg, int length);

/*}}}  */
/*{{{  sort visitors */

RS_RElem RS_visitRElem(RS_RElem arg, int (*acceptIntValue) (int),
		       char *(*acceptStrValue) (char *),
		       RS_Location(*acceptLocValue) (RS_Location),
		       RS_RElemList(*acceptList) (RS_RElemList));
RS_RType RS_visitRType(RS_RType arg, RS_RTypeList(*acceptList) (RS_RTypeList),
		       char *(*acceptStrCon) (char *));
RS_RTuple RS_visitRTuple(RS_RTuple arg, char *(*acceptId) (char *),
			 RS_RType(*acceptType) (RS_RType),
			 RS_RElem(*acceptData) (RS_RElem));
RS_RStore RS_visitRStore(RS_RStore arg,
			 RS_RTupleList(*acceptList) (RS_RTupleList));
RS_RElemList RS_visitRElemList(RS_RElemList arg,
			       RS_RElem(*acceptHead) (RS_RElem));
RS_RTypeList RS_visitRTypeList(RS_RTypeList arg,
			       RS_RType(*acceptHead) (RS_RType));
RS_RTupleList RS_visitRTupleList(RS_RTupleList arg,
				 RS_RTuple(*acceptHead) (RS_RTuple));
RS_StrChar RS_visitStrChar(RS_StrChar arg, char *(*acceptString) (char *));
RS_StrCon RS_visitStrCon(RS_StrCon arg, char *(*acceptString) (char *));
RS_NatCon RS_visitNatCon(RS_NatCon arg, char *(*acceptString) (char *));
RS_Location RS_visitLocation(RS_Location arg,
			     char *(*acceptFilename) (char *),
			     RS_Area(*acceptArea) (RS_Area));
RS_Area RS_visitArea(RS_Area arg, int (*acceptBeginLine) (int),
		     int (*acceptBeginColumn) (int),
		     int (*acceptEndLine) (int), int (*acceptEndColumn) (int),
		     int (*acceptOffset) (int), int (*acceptLength) (int));

/*}}}  */

#endif /* _RSTORE_H */
