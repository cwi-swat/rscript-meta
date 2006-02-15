#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "RStore.h"

/*{{{  conversion functions */

ATerm RS_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm RS_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *RS_charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}

char RS_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _RS_RElem;
typedef struct ATerm _RS_RType;
typedef struct ATerm _RS_RTuple;
typedef struct ATerm _RS_RStore;
typedef struct ATerm _RS_RElemList;
typedef struct ATerm _RS_RTypeList;
typedef struct ATerm _RS_RTupleList;
typedef struct ATerm _RS_StrChar;
typedef struct ATerm _RS_StrCon;
typedef struct ATerm _RS_NatCon;
typedef struct ATerm _RS_Location;
typedef struct ATerm _RS_Area;

/*}}}  */

/*{{{  void RS_initRStoreApi(void) */

void RS_initRStoreApi(void)
{
  init_RStore_dict();
}

/*}}}  */

/*{{{  protect functions */

void RS_protectRElem(RS_RElem *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectRType(RS_RType *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectRTuple(RS_RTuple *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectRStore(RS_RStore *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectRElemList(RS_RElemList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectRTypeList(RS_RTypeList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectRTupleList(RS_RTupleList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectStrChar(RS_StrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectStrCon(RS_StrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectNatCon(RS_NatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectLocation(RS_Location *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void RS_protectArea(RS_Area *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  RS_RElem RS_RElemFromTerm(ATerm t) */

RS_RElem RS_RElemFromTerm(ATerm t)
{
  return (RS_RElem)t;
}

/*}}}  */
/*{{{  ATerm RS_RElemToTerm(RS_RElem arg) */

ATerm RS_RElemToTerm(RS_RElem arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_RType RS_RTypeFromTerm(ATerm t) */

RS_RType RS_RTypeFromTerm(ATerm t)
{
  return (RS_RType)t;
}

/*}}}  */
/*{{{  ATerm RS_RTypeToTerm(RS_RType arg) */

ATerm RS_RTypeToTerm(RS_RType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_RTuple RS_RTupleFromTerm(ATerm t) */

RS_RTuple RS_RTupleFromTerm(ATerm t)
{
  return (RS_RTuple)t;
}

/*}}}  */
/*{{{  ATerm RS_RTupleToTerm(RS_RTuple arg) */

ATerm RS_RTupleToTerm(RS_RTuple arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_RStore RS_RStoreFromTerm(ATerm t) */

RS_RStore RS_RStoreFromTerm(ATerm t)
{
  return (RS_RStore)t;
}

/*}}}  */
/*{{{  ATerm RS_RStoreToTerm(RS_RStore arg) */

ATerm RS_RStoreToTerm(RS_RStore arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_RElemList RS_RElemListFromTerm(ATerm t) */

RS_RElemList RS_RElemListFromTerm(ATerm t)
{
  return (RS_RElemList)t;
}

/*}}}  */
/*{{{  ATerm RS_RElemListToTerm(RS_RElemList arg) */

ATerm RS_RElemListToTerm(RS_RElemList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_RTypeList RS_RTypeListFromTerm(ATerm t) */

RS_RTypeList RS_RTypeListFromTerm(ATerm t)
{
  return (RS_RTypeList)t;
}

/*}}}  */
/*{{{  ATerm RS_RTypeListToTerm(RS_RTypeList arg) */

ATerm RS_RTypeListToTerm(RS_RTypeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_RTupleList RS_RTupleListFromTerm(ATerm t) */

RS_RTupleList RS_RTupleListFromTerm(ATerm t)
{
  return (RS_RTupleList)t;
}

/*}}}  */
/*{{{  ATerm RS_RTupleListToTerm(RS_RTupleList arg) */

ATerm RS_RTupleListToTerm(RS_RTupleList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_StrChar RS_StrCharFromTerm(ATerm t) */

RS_StrChar RS_StrCharFromTerm(ATerm t)
{
  return (RS_StrChar)t;
}

/*}}}  */
/*{{{  ATerm RS_StrCharToTerm(RS_StrChar arg) */

ATerm RS_StrCharToTerm(RS_StrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_StrCon RS_StrConFromTerm(ATerm t) */

RS_StrCon RS_StrConFromTerm(ATerm t)
{
  return (RS_StrCon)t;
}

/*}}}  */
/*{{{  ATerm RS_StrConToTerm(RS_StrCon arg) */

ATerm RS_StrConToTerm(RS_StrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_NatCon RS_NatConFromTerm(ATerm t) */

RS_NatCon RS_NatConFromTerm(ATerm t)
{
  return (RS_NatCon)t;
}

/*}}}  */
/*{{{  ATerm RS_NatConToTerm(RS_NatCon arg) */

ATerm RS_NatConToTerm(RS_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_Location RS_LocationFromTerm(ATerm t) */

RS_Location RS_LocationFromTerm(ATerm t)
{
  return (RS_Location)t;
}

/*}}}  */
/*{{{  ATerm RS_LocationToTerm(RS_Location arg) */

ATerm RS_LocationToTerm(RS_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  RS_Area RS_AreaFromTerm(ATerm t) */

RS_Area RS_AreaFromTerm(ATerm t)
{
  return (RS_Area)t;
}

/*}}}  */
/*{{{  ATerm RS_AreaToTerm(RS_Area arg) */

ATerm RS_AreaToTerm(RS_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int RS_getRElemListLength (RS_RElemList arg) {
  return ATgetLength((ATermList) arg);
}
RS_RElemList RS_reverseRElemList(RS_RElemList arg) {
  return (RS_RElemList) ATreverse((ATermList) arg);
}
RS_RElemList RS_appendRElemList(RS_RElemList arg, RS_RElem elem) {
  return (RS_RElemList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
RS_RElemList RS_concatRElemList(RS_RElemList arg0, RS_RElemList arg1) {
  return (RS_RElemList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
RS_RElemList RS_sliceRElemList(RS_RElemList arg, int start, int end) {
  return (RS_RElemList) ATgetSlice((ATermList) arg, start, end);
}
RS_RElem RS_getRElemListRElemAt(RS_RElemList arg, int index) {
 return (RS_RElem)ATelementAt((ATermList) arg,index);
}
RS_RElemList RS_replaceRElemListRElemAt(RS_RElemList arg, RS_RElem elem, int index) {
 return (RS_RElemList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
RS_RElemList RS_makeRElemList2(RS_RElem elem1, RS_RElem elem2) {
  return (RS_RElemList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
RS_RElemList RS_makeRElemList3(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3) {
  return (RS_RElemList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
RS_RElemList RS_makeRElemList4(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3, RS_RElem elem4) {
  return (RS_RElemList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
RS_RElemList RS_makeRElemList5(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3, RS_RElem elem4, RS_RElem elem5) {
  return (RS_RElemList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
RS_RElemList RS_makeRElemList6(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3, RS_RElem elem4, RS_RElem elem5, RS_RElem elem6) {
  return (RS_RElemList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int RS_getRTypeListLength (RS_RTypeList arg) {
  return ATgetLength((ATermList) arg);
}
RS_RTypeList RS_reverseRTypeList(RS_RTypeList arg) {
  return (RS_RTypeList) ATreverse((ATermList) arg);
}
RS_RTypeList RS_appendRTypeList(RS_RTypeList arg, RS_RType elem) {
  return (RS_RTypeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
RS_RTypeList RS_concatRTypeList(RS_RTypeList arg0, RS_RTypeList arg1) {
  return (RS_RTypeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
RS_RTypeList RS_sliceRTypeList(RS_RTypeList arg, int start, int end) {
  return (RS_RTypeList) ATgetSlice((ATermList) arg, start, end);
}
RS_RType RS_getRTypeListRTypeAt(RS_RTypeList arg, int index) {
 return (RS_RType)ATelementAt((ATermList) arg,index);
}
RS_RTypeList RS_replaceRTypeListRTypeAt(RS_RTypeList arg, RS_RType elem, int index) {
 return (RS_RTypeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
RS_RTypeList RS_makeRTypeList2(RS_RType elem1, RS_RType elem2) {
  return (RS_RTypeList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
RS_RTypeList RS_makeRTypeList3(RS_RType elem1, RS_RType elem2, RS_RType elem3) {
  return (RS_RTypeList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
RS_RTypeList RS_makeRTypeList4(RS_RType elem1, RS_RType elem2, RS_RType elem3, RS_RType elem4) {
  return (RS_RTypeList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
RS_RTypeList RS_makeRTypeList5(RS_RType elem1, RS_RType elem2, RS_RType elem3, RS_RType elem4, RS_RType elem5) {
  return (RS_RTypeList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
RS_RTypeList RS_makeRTypeList6(RS_RType elem1, RS_RType elem2, RS_RType elem3, RS_RType elem4, RS_RType elem5, RS_RType elem6) {
  return (RS_RTypeList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int RS_getRTupleListLength (RS_RTupleList arg) {
  return ATgetLength((ATermList) arg);
}
RS_RTupleList RS_reverseRTupleList(RS_RTupleList arg) {
  return (RS_RTupleList) ATreverse((ATermList) arg);
}
RS_RTupleList RS_appendRTupleList(RS_RTupleList arg, RS_RTuple elem) {
  return (RS_RTupleList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
RS_RTupleList RS_concatRTupleList(RS_RTupleList arg0, RS_RTupleList arg1) {
  return (RS_RTupleList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
RS_RTupleList RS_sliceRTupleList(RS_RTupleList arg, int start, int end) {
  return (RS_RTupleList) ATgetSlice((ATermList) arg, start, end);
}
RS_RTuple RS_getRTupleListRTupleAt(RS_RTupleList arg, int index) {
 return (RS_RTuple)ATelementAt((ATermList) arg,index);
}
RS_RTupleList RS_replaceRTupleListRTupleAt(RS_RTupleList arg, RS_RTuple elem, int index) {
 return (RS_RTupleList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
RS_RTupleList RS_makeRTupleList2(RS_RTuple elem1, RS_RTuple elem2) {
  return (RS_RTupleList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
RS_RTupleList RS_makeRTupleList3(RS_RTuple elem1, RS_RTuple elem2, RS_RTuple elem3) {
  return (RS_RTupleList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
RS_RTupleList RS_makeRTupleList4(RS_RTuple elem1, RS_RTuple elem2, RS_RTuple elem3, RS_RTuple elem4) {
  return (RS_RTupleList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
RS_RTupleList RS_makeRTupleList5(RS_RTuple elem1, RS_RTuple elem2, RS_RTuple elem3, RS_RTuple elem4, RS_RTuple elem5) {
  return (RS_RTupleList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
RS_RTupleList RS_makeRTupleList6(RS_RTuple elem1, RS_RTuple elem2, RS_RTuple elem3, RS_RTuple elem4, RS_RTuple elem5, RS_RTuple elem6) {
  return (RS_RTupleList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  RS_RElem RS_makeRElemInt(int intValue) */

RS_RElem RS_makeRElemInt(int intValue)
{
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun0, (ATerm) (ATerm) ATmakeInt(intValue));
}

/*}}}  */
/*{{{  RS_RElem RS_makeRElemStr(const char* strValue) */

RS_RElem RS_makeRElemStr(const char* strValue)
{
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(strValue, 0, ATtrue)));
}

/*}}}  */
/*{{{  RS_RElem RS_makeRElemLoc(RS_Location locValue) */

RS_RElem RS_makeRElemLoc(RS_Location locValue)
{
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun2, (ATerm) locValue);
}

/*}}}  */
/*{{{  RS_RElem RS_makeRElemSet(RS_RElemList list) */

RS_RElem RS_makeRElemSet(RS_RElemList list)
{
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun3, (ATerm) list);
}

/*}}}  */
/*{{{  RS_RElem RS_makeRElemBag(RS_RElemList list) */

RS_RElem RS_makeRElemBag(RS_RElemList list)
{
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun4, (ATerm) list);
}

/*}}}  */
/*{{{  RS_RElem RS_makeRElemTuple(RS_RElemList list) */

RS_RElem RS_makeRElemTuple(RS_RElemList list)
{
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun5, (ATerm) list);
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeInt(void) */

RS_RType RS_makeRTypeInt(void)
{
  return (RS_RType)(ATerm)ATmakeAppl0(RS_afun6);
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeStr(void) */

RS_RType RS_makeRTypeStr(void)
{
  return (RS_RType)(ATerm)ATmakeAppl0(RS_afun7);
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeLoc(void) */

RS_RType RS_makeRTypeLoc(void)
{
  return (RS_RType)(ATerm)ATmakeAppl0(RS_afun8);
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeTuple(RS_RTypeList list) */

RS_RType RS_makeRTypeTuple(RS_RTypeList list)
{
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun5, (ATerm) list);
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeSet(RS_RType RType) */

RS_RType RS_makeRTypeSet(RS_RType RType)
{
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun3, (ATerm) RType);
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeBag(RS_RType RType) */

RS_RType RS_makeRTypeBag(RS_RType RType)
{
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun4, (ATerm) RType);
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeRel(RS_RTypeList list) */

RS_RType RS_makeRTypeRel(RS_RTypeList list)
{
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun9, (ATerm) list);
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeUser(const char* StrCon) */

RS_RType RS_makeRTypeUser(const char* StrCon)
{
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun10, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(StrCon, 0, ATtrue)));
}

/*}}}  */
/*{{{  RS_RType RS_makeRTypeParameter(const char* StrCon) */

RS_RType RS_makeRTypeParameter(const char* StrCon)
{
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun11, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(StrCon, 0, ATtrue)));
}

/*}}}  */
/*{{{  RS_RTuple RS_makeRTupleRtuple(const char* id, RS_RType type, RS_RElem data) */

RS_RTuple RS_makeRTupleRtuple(const char* id, RS_RType type, RS_RElem data)
{
  return (RS_RTuple)(ATerm)ATmakeAppl3(RS_afun12, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) type, (ATerm) data);
}

/*}}}  */
/*{{{  RS_RStore RS_makeRStoreRstore(RS_RTupleList list) */

RS_RStore RS_makeRStoreRstore(RS_RTupleList list)
{
  return (RS_RStore)(ATerm)ATmakeAppl1(RS_afun13, (ATerm) list);
}

/*}}}  */
/*{{{  RS_RElemList RS_makeRElemListEmpty(void) */

RS_RElemList RS_makeRElemListEmpty(void)
{
  return (RS_RElemList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  RS_RElemList RS_makeRElemListSingle(RS_RElem head) */

RS_RElemList RS_makeRElemListSingle(RS_RElem head)
{
  return (RS_RElemList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  RS_RElemList RS_makeRElemListMany(RS_RElem head, RS_RElemList tail) */

RS_RElemList RS_makeRElemListMany(RS_RElem head, RS_RElemList tail)
{
  return (RS_RElemList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  RS_RTypeList RS_makeRTypeListEmpty(void) */

RS_RTypeList RS_makeRTypeListEmpty(void)
{
  return (RS_RTypeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  RS_RTypeList RS_makeRTypeListSingle(RS_RType head) */

RS_RTypeList RS_makeRTypeListSingle(RS_RType head)
{
  return (RS_RTypeList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  RS_RTypeList RS_makeRTypeListMany(RS_RType head, RS_RTypeList tail) */

RS_RTypeList RS_makeRTypeListMany(RS_RType head, RS_RTypeList tail)
{
  return (RS_RTypeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  RS_RTupleList RS_makeRTupleListEmpty(void) */

RS_RTupleList RS_makeRTupleListEmpty(void)
{
  return (RS_RTupleList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  RS_RTupleList RS_makeRTupleListSingle(RS_RTuple head) */

RS_RTupleList RS_makeRTupleListSingle(RS_RTuple head)
{
  return (RS_RTupleList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  RS_RTupleList RS_makeRTupleListMany(RS_RTuple head, RS_RTupleList tail) */

RS_RTupleList RS_makeRTupleListMany(RS_RTuple head, RS_RTupleList tail)
{
  return (RS_RTupleList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  RS_StrChar RS_makeStrCharStrChar(const char* string) */

RS_StrChar RS_makeStrCharStrChar(const char* string)
{
  return (RS_StrChar)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}

/*}}}  */
/*{{{  RS_StrCon RS_makeStrConStrCon(const char* string) */

RS_StrCon RS_makeStrConStrCon(const char* string)
{
  return (RS_StrCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}

/*}}}  */
/*{{{  RS_NatCon RS_makeNatConNatCon(const char* string) */

RS_NatCon RS_makeNatConNatCon(const char* string)
{
  return (RS_NatCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}

/*}}}  */
/*{{{  RS_Location RS_makeLocationFile(const char* filename) */

RS_Location RS_makeLocationFile(const char* filename)
{
  return (RS_Location)(ATerm)ATmakeAppl1(RS_afun14, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)));
}

/*}}}  */
/*{{{  RS_Location RS_makeLocationArea(RS_Area Area) */

RS_Location RS_makeLocationArea(RS_Area Area)
{
  return (RS_Location)(ATerm)ATmakeAppl1(RS_afun15, (ATerm) Area);
}

/*}}}  */
/*{{{  RS_Location RS_makeLocationAreaInFile(const char* filename, RS_Area Area) */

RS_Location RS_makeLocationAreaInFile(const char* filename, RS_Area Area)
{
  return (RS_Location)(ATerm)ATmakeAppl2(RS_afun16, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) Area);
}

/*}}}  */
/*{{{  RS_Area RS_makeAreaArea(int beginLine, int beginColumn, int endLine, int endColumn, int offset, int length) */

RS_Area RS_makeAreaArea(int beginLine, int beginColumn, int endLine, int endColumn, int offset, int length)
{
  return (RS_Area)(ATerm)ATmakeAppl6(RS_afun17, (ATerm) (ATerm) ATmakeInt(beginLine), (ATerm) (ATerm) ATmakeInt(beginColumn), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endColumn), (ATerm) (ATerm) ATmakeInt(offset), (ATerm) (ATerm) ATmakeInt(length));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool RS_isEqualRElem(RS_RElem arg0, RS_RElem arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualRType(RS_RType arg0, RS_RType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualRTuple(RS_RTuple arg0, RS_RTuple arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualRStore(RS_RStore arg0, RS_RStore arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualRElemList(RS_RElemList arg0, RS_RElemList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualRTypeList(RS_RTypeList arg0, RS_RTypeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualRTupleList(RS_RTupleList arg0, RS_RTupleList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualStrChar(RS_StrChar arg0, RS_StrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualStrCon(RS_StrCon arg0, RS_StrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualNatCon(RS_NatCon arg0, RS_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualLocation(RS_Location arg0, RS_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool RS_isEqualArea(RS_Area arg0, RS_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  RS_RElem accessors */

/*{{{  ATbool RS_isValidRElem(RS_RElem arg) */

ATbool RS_isValidRElem(RS_RElem arg)
{
  if (RS_isRElemInt(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemStr(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemLoc(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemInt(RS_RElem arg) */

inline ATbool RS_isRElemInt(RS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRElemInt, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemStr(RS_RElem arg) */

inline ATbool RS_isRElemStr(RS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRElemStr, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemLoc(RS_RElem arg) */

inline ATbool RS_isRElemLoc(RS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRElemLoc, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemSet(RS_RElem arg) */

inline ATbool RS_isRElemSet(RS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRElemSet, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemBag(RS_RElem arg) */

inline ATbool RS_isRElemBag(RS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRElemBag, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemTuple(RS_RElem arg) */

inline ATbool RS_isRElemTuple(RS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRElemTuple, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool RS_hasRElemIntValue(RS_RElem arg) */

ATbool RS_hasRElemIntValue(RS_RElem arg)
{
  if (RS_isRElemInt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRElemStrValue(RS_RElem arg) */

ATbool RS_hasRElemStrValue(RS_RElem arg)
{
  if (RS_isRElemStr(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRElemLocValue(RS_RElem arg) */

ATbool RS_hasRElemLocValue(RS_RElem arg)
{
  if (RS_isRElemLoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRElemList(RS_RElem arg) */

ATbool RS_hasRElemList(RS_RElem arg)
{
  if (RS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int RS_getRElemIntValue(RS_RElem arg) */

int RS_getRElemIntValue(RS_RElem arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  char* RS_getRElemStrValue(RS_RElem arg) */

char* RS_getRElemStrValue(RS_RElem arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  RS_Location RS_getRElemLocValue(RS_RElem arg) */

RS_Location RS_getRElemLocValue(RS_RElem arg)
{
  
    return (RS_Location)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  RS_RElemList RS_getRElemList(RS_RElem arg) */

RS_RElemList RS_getRElemList(RS_RElem arg)
{
  if (RS_isRElemSet(arg)) {
    return (RS_RElemList)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (RS_isRElemBag(arg)) {
    return (RS_RElemList)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_RElemList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  RS_RElem RS_setRElemIntValue(RS_RElem arg, int intValue) */

RS_RElem RS_setRElemIntValue(RS_RElem arg, int intValue)
{
  if (RS_isRElemInt(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(intValue)), 0);
  }

  ATabort("RElem has no IntValue: %t\n", arg);
  return (RS_RElem)NULL;
}

/*}}}  */
/*{{{  RS_RElem RS_setRElemStrValue(RS_RElem arg, const char* strValue) */

RS_RElem RS_setRElemStrValue(RS_RElem arg, const char* strValue)
{
  if (RS_isRElemStr(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(strValue, 0, ATtrue))), 0);
  }

  ATabort("RElem has no StrValue: %t\n", arg);
  return (RS_RElem)NULL;
}

/*}}}  */
/*{{{  RS_RElem RS_setRElemLocValue(RS_RElem arg, RS_Location locValue) */

RS_RElem RS_setRElemLocValue(RS_RElem arg, RS_Location locValue)
{
  if (RS_isRElemLoc(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) locValue), 0);
  }

  ATabort("RElem has no LocValue: %t\n", arg);
  return (RS_RElem)NULL;
}

/*}}}  */
/*{{{  RS_RElem RS_setRElemList(RS_RElem arg, RS_RElemList list) */

RS_RElem RS_setRElemList(RS_RElem arg, RS_RElemList list)
{
  if (RS_isRElemSet(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }
  else if (RS_isRElemBag(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }
  else if (RS_isRElemTuple(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("RElem has no List: %t\n", arg);
  return (RS_RElem)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_RType accessors */

/*{{{  ATbool RS_isValidRType(RS_RType arg) */

ATbool RS_isValidRType(RS_RType arg)
{
  if (RS_isRTypeInt(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeStr(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeLoc(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeBag(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeRel(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeUser(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeInt(RS_RType arg) */

inline ATbool RS_isRTypeInt(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeInt);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeStr(RS_RType arg) */

inline ATbool RS_isRTypeStr(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeStr);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeLoc(RS_RType arg) */

inline ATbool RS_isRTypeLoc(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeLoc);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeTuple(RS_RType arg) */

inline ATbool RS_isRTypeTuple(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeTuple, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeSet(RS_RType arg) */

inline ATbool RS_isRTypeSet(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeSet, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeBag(RS_RType arg) */

inline ATbool RS_isRTypeBag(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeBag, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeRel(RS_RType arg) */

inline ATbool RS_isRTypeRel(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeRel, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeUser(RS_RType arg) */

inline ATbool RS_isRTypeUser(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeUser, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeParameter(RS_RType arg) */

inline ATbool RS_isRTypeParameter(RS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeParameter, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool RS_hasRTypeList(RS_RType arg) */

ATbool RS_hasRTypeList(RS_RType arg)
{
  if (RS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeRel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRTypeRType(RS_RType arg) */

ATbool RS_hasRTypeRType(RS_RType arg)
{
  if (RS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRTypeStrCon(RS_RType arg) */

ATbool RS_hasRTypeStrCon(RS_RType arg)
{
  if (RS_isRTypeUser(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  RS_RTypeList RS_getRTypeList(RS_RType arg) */

RS_RTypeList RS_getRTypeList(RS_RType arg)
{
  if (RS_isRTypeTuple(arg)) {
    return (RS_RTypeList)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_RTypeList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  RS_RType RS_getRTypeRType(RS_RType arg) */

RS_RType RS_getRTypeRType(RS_RType arg)
{
  if (RS_isRTypeSet(arg)) {
    return (RS_RType)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_RType)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* RS_getRTypeStrCon(RS_RType arg) */

char* RS_getRTypeStrCon(RS_RType arg)
{
  if (RS_isRTypeUser(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  RS_RType RS_setRTypeList(RS_RType arg, RS_RTypeList list) */

RS_RType RS_setRTypeList(RS_RType arg, RS_RTypeList list)
{
  if (RS_isRTypeTuple(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }
  else if (RS_isRTypeRel(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("RType has no List: %t\n", arg);
  return (RS_RType)NULL;
}

/*}}}  */
/*{{{  RS_RType RS_setRTypeRType(RS_RType arg, RS_RType RType) */

RS_RType RS_setRTypeRType(RS_RType arg, RS_RType RType)
{
  if (RS_isRTypeSet(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) RType), 0);
  }
  else if (RS_isRTypeBag(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) RType), 0);
  }

  ATabort("RType has no RType: %t\n", arg);
  return (RS_RType)NULL;
}

/*}}}  */
/*{{{  RS_RType RS_setRTypeStrCon(RS_RType arg, const char* StrCon) */

RS_RType RS_setRTypeStrCon(RS_RType arg, const char* StrCon)
{
  if (RS_isRTypeUser(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(StrCon, 0, ATtrue))), 0);
  }
  else if (RS_isRTypeParameter(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(StrCon, 0, ATtrue))), 0);
  }

  ATabort("RType has no StrCon: %t\n", arg);
  return (RS_RType)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_RTuple accessors */

/*{{{  ATbool RS_isValidRTuple(RS_RTuple arg) */

ATbool RS_isValidRTuple(RS_RTuple arg)
{
  if (RS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isRTupleRtuple(RS_RTuple arg) */

inline ATbool RS_isRTupleRtuple(RS_RTuple arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternRTupleRtuple, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool RS_hasRTupleId(RS_RTuple arg) */

ATbool RS_hasRTupleId(RS_RTuple arg)
{
  if (RS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRTupleType(RS_RTuple arg) */

ATbool RS_hasRTupleType(RS_RTuple arg)
{
  if (RS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRTupleData(RS_RTuple arg) */

ATbool RS_hasRTupleData(RS_RTuple arg)
{
  if (RS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* RS_getRTupleId(RS_RTuple arg) */

char* RS_getRTupleId(RS_RTuple arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  RS_RType RS_getRTupleType(RS_RTuple arg) */

RS_RType RS_getRTupleType(RS_RTuple arg)
{
  
    return (RS_RType)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  RS_RElem RS_getRTupleData(RS_RTuple arg) */

RS_RElem RS_getRTupleData(RS_RTuple arg)
{
  
    return (RS_RElem)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  RS_RTuple RS_setRTupleId(RS_RTuple arg, const char* id) */

RS_RTuple RS_setRTupleId(RS_RTuple arg, const char* id)
{
  if (RS_isRTupleRtuple(arg)) {
    return (RS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }

  ATabort("RTuple has no Id: %t\n", arg);
  return (RS_RTuple)NULL;
}

/*}}}  */
/*{{{  RS_RTuple RS_setRTupleType(RS_RTuple arg, RS_RType type) */

RS_RTuple RS_setRTupleType(RS_RTuple arg, RS_RType type)
{
  if (RS_isRTupleRtuple(arg)) {
    return (RS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) type), 1);
  }

  ATabort("RTuple has no Type: %t\n", arg);
  return (RS_RTuple)NULL;
}

/*}}}  */
/*{{{  RS_RTuple RS_setRTupleData(RS_RTuple arg, RS_RElem data) */

RS_RTuple RS_setRTupleData(RS_RTuple arg, RS_RElem data)
{
  if (RS_isRTupleRtuple(arg)) {
    return (RS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) data), 2);
  }

  ATabort("RTuple has no Data: %t\n", arg);
  return (RS_RTuple)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_RStore accessors */

/*{{{  ATbool RS_isValidRStore(RS_RStore arg) */

ATbool RS_isValidRStore(RS_RStore arg)
{
  if (RS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isRStoreRstore(RS_RStore arg) */

inline ATbool RS_isRStoreRstore(RS_RStore arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternRStoreRstore, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool RS_hasRStoreList(RS_RStore arg) */

ATbool RS_hasRStoreList(RS_RStore arg)
{
  if (RS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  RS_RTupleList RS_getRStoreList(RS_RStore arg) */

RS_RTupleList RS_getRStoreList(RS_RStore arg)
{
  
    return (RS_RTupleList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  RS_RStore RS_setRStoreList(RS_RStore arg, RS_RTupleList list) */

RS_RStore RS_setRStoreList(RS_RStore arg, RS_RTupleList list)
{
  if (RS_isRStoreRstore(arg)) {
    return (RS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("RStore has no List: %t\n", arg);
  return (RS_RStore)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_RElemList accessors */

/*{{{  ATbool RS_isValidRElemList(RS_RElemList arg) */

ATbool RS_isValidRElemList(RS_RElemList arg)
{
  if (RS_isRElemListEmpty(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemListSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemListEmpty(RS_RElemList arg) */

inline ATbool RS_isRElemListEmpty(RS_RElemList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternRElemListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemListSingle(RS_RElemList arg) */

inline ATbool RS_isRElemListSingle(RS_RElemList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRElemListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRElemListMany(RS_RElemList arg) */

inline ATbool RS_isRElemListMany(RS_RElemList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRElemListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool RS_hasRElemListHead(RS_RElemList arg) */

ATbool RS_hasRElemListHead(RS_RElemList arg)
{
  if (RS_isRElemListSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRElemListTail(RS_RElemList arg) */

ATbool RS_hasRElemListTail(RS_RElemList arg)
{
  if (RS_isRElemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  RS_RElem RS_getRElemListHead(RS_RElemList arg) */

RS_RElem RS_getRElemListHead(RS_RElemList arg)
{
  if (RS_isRElemListSingle(arg)) {
    return (RS_RElem)ATgetFirst((ATermList)arg);
  }
  else 
    return (RS_RElem)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  RS_RElemList RS_getRElemListTail(RS_RElemList arg) */

RS_RElemList RS_getRElemListTail(RS_RElemList arg)
{
  
    return (RS_RElemList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  RS_RElemList RS_setRElemListHead(RS_RElemList arg, RS_RElem head) */

RS_RElemList RS_setRElemListHead(RS_RElemList arg, RS_RElem head)
{
  if (RS_isRElemListSingle(arg)) {
    return (RS_RElemList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (RS_isRElemListMany(arg)) {
    return (RS_RElemList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RElemList has no Head: %t\n", arg);
  return (RS_RElemList)NULL;
}

/*}}}  */
/*{{{  RS_RElemList RS_setRElemListTail(RS_RElemList arg, RS_RElemList tail) */

RS_RElemList RS_setRElemListTail(RS_RElemList arg, RS_RElemList tail)
{
  if (RS_isRElemListMany(arg)) {
    return (RS_RElemList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("RElemList has no Tail: %t\n", arg);
  return (RS_RElemList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_RTypeList accessors */

/*{{{  ATbool RS_isValidRTypeList(RS_RTypeList arg) */

ATbool RS_isValidRTypeList(RS_RTypeList arg)
{
  if (RS_isRTypeListEmpty(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeListSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeListEmpty(RS_RTypeList arg) */

inline ATbool RS_isRTypeListEmpty(RS_RTypeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternRTypeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeListSingle(RS_RTypeList arg) */

inline ATbool RS_isRTypeListSingle(RS_RTypeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTypeListMany(RS_RTypeList arg) */

inline ATbool RS_isRTypeListMany(RS_RTypeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTypeListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool RS_hasRTypeListHead(RS_RTypeList arg) */

ATbool RS_hasRTypeListHead(RS_RTypeList arg)
{
  if (RS_isRTypeListSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRTypeListTail(RS_RTypeList arg) */

ATbool RS_hasRTypeListTail(RS_RTypeList arg)
{
  if (RS_isRTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  RS_RType RS_getRTypeListHead(RS_RTypeList arg) */

RS_RType RS_getRTypeListHead(RS_RTypeList arg)
{
  if (RS_isRTypeListSingle(arg)) {
    return (RS_RType)ATgetFirst((ATermList)arg);
  }
  else 
    return (RS_RType)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  RS_RTypeList RS_getRTypeListTail(RS_RTypeList arg) */

RS_RTypeList RS_getRTypeListTail(RS_RTypeList arg)
{
  
    return (RS_RTypeList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  RS_RTypeList RS_setRTypeListHead(RS_RTypeList arg, RS_RType head) */

RS_RTypeList RS_setRTypeListHead(RS_RTypeList arg, RS_RType head)
{
  if (RS_isRTypeListSingle(arg)) {
    return (RS_RTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (RS_isRTypeListMany(arg)) {
    return (RS_RTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RTypeList has no Head: %t\n", arg);
  return (RS_RTypeList)NULL;
}

/*}}}  */
/*{{{  RS_RTypeList RS_setRTypeListTail(RS_RTypeList arg, RS_RTypeList tail) */

RS_RTypeList RS_setRTypeListTail(RS_RTypeList arg, RS_RTypeList tail)
{
  if (RS_isRTypeListMany(arg)) {
    return (RS_RTypeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("RTypeList has no Tail: %t\n", arg);
  return (RS_RTypeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_RTupleList accessors */

/*{{{  ATbool RS_isValidRTupleList(RS_RTupleList arg) */

ATbool RS_isValidRTupleList(RS_RTupleList arg)
{
  if (RS_isRTupleListEmpty(arg)) {
    return ATtrue;
  }
  else if (RS_isRTupleListSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRTupleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isRTupleListEmpty(RS_RTupleList arg) */

inline ATbool RS_isRTupleListEmpty(RS_RTupleList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternRTupleListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool RS_isRTupleListSingle(RS_RTupleList arg) */

inline ATbool RS_isRTupleListSingle(RS_RTupleList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTupleListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isRTupleListMany(RS_RTupleList arg) */

inline ATbool RS_isRTupleListMany(RS_RTupleList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternRTupleListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool RS_hasRTupleListHead(RS_RTupleList arg) */

ATbool RS_hasRTupleListHead(RS_RTupleList arg)
{
  if (RS_isRTupleListSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRTupleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasRTupleListTail(RS_RTupleList arg) */

ATbool RS_hasRTupleListTail(RS_RTupleList arg)
{
  if (RS_isRTupleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  RS_RTuple RS_getRTupleListHead(RS_RTupleList arg) */

RS_RTuple RS_getRTupleListHead(RS_RTupleList arg)
{
  if (RS_isRTupleListSingle(arg)) {
    return (RS_RTuple)ATgetFirst((ATermList)arg);
  }
  else 
    return (RS_RTuple)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  RS_RTupleList RS_getRTupleListTail(RS_RTupleList arg) */

RS_RTupleList RS_getRTupleListTail(RS_RTupleList arg)
{
  
    return (RS_RTupleList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  RS_RTupleList RS_setRTupleListHead(RS_RTupleList arg, RS_RTuple head) */

RS_RTupleList RS_setRTupleListHead(RS_RTupleList arg, RS_RTuple head)
{
  if (RS_isRTupleListSingle(arg)) {
    return (RS_RTupleList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (RS_isRTupleListMany(arg)) {
    return (RS_RTupleList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RTupleList has no Head: %t\n", arg);
  return (RS_RTupleList)NULL;
}

/*}}}  */
/*{{{  RS_RTupleList RS_setRTupleListTail(RS_RTupleList arg, RS_RTupleList tail) */

RS_RTupleList RS_setRTupleListTail(RS_RTupleList arg, RS_RTupleList tail)
{
  if (RS_isRTupleListMany(arg)) {
    return (RS_RTupleList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("RTupleList has no Tail: %t\n", arg);
  return (RS_RTupleList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_StrChar accessors */

/*{{{  ATbool RS_isValidStrChar(RS_StrChar arg) */

ATbool RS_isValidStrChar(RS_StrChar arg)
{
  if (RS_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isStrCharStrChar(RS_StrChar arg) */

inline ATbool RS_isStrCharStrChar(RS_StrChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternStrCharStrChar, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool RS_hasStrCharString(RS_StrChar arg) */

ATbool RS_hasStrCharString(RS_StrChar arg)
{
  if (RS_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* RS_getStrCharString(RS_StrChar arg) */

char* RS_getStrCharString(RS_StrChar arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/*}}}  */
/*{{{  RS_StrChar RS_setStrCharString(RS_StrChar arg, const char* string) */

RS_StrChar RS_setStrCharString(RS_StrChar arg, const char* string)
{
  if (RS_isStrCharStrChar(arg)) {
    return (RS_StrChar)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrChar has no String: %t\n", arg);
  return (RS_StrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_StrCon accessors */

/*{{{  ATbool RS_isValidStrCon(RS_StrCon arg) */

ATbool RS_isValidStrCon(RS_StrCon arg)
{
  if (RS_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isStrConStrCon(RS_StrCon arg) */

inline ATbool RS_isStrConStrCon(RS_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternStrConStrCon, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool RS_hasStrConString(RS_StrCon arg) */

ATbool RS_hasStrConString(RS_StrCon arg)
{
  if (RS_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* RS_getStrConString(RS_StrCon arg) */

char* RS_getStrConString(RS_StrCon arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/*}}}  */
/*{{{  RS_StrCon RS_setStrConString(RS_StrCon arg, const char* string) */

RS_StrCon RS_setStrConString(RS_StrCon arg, const char* string)
{
  if (RS_isStrConStrCon(arg)) {
    return (RS_StrCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrCon has no String: %t\n", arg);
  return (RS_StrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_NatCon accessors */

/*{{{  ATbool RS_isValidNatCon(RS_NatCon arg) */

ATbool RS_isValidNatCon(RS_NatCon arg)
{
  if (RS_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isNatConNatCon(RS_NatCon arg) */

inline ATbool RS_isNatConNatCon(RS_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternNatConNatCon, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool RS_hasNatConString(RS_NatCon arg) */

ATbool RS_hasNatConString(RS_NatCon arg)
{
  if (RS_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* RS_getNatConString(RS_NatCon arg) */

char* RS_getNatConString(RS_NatCon arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/*}}}  */
/*{{{  RS_NatCon RS_setNatConString(RS_NatCon arg, const char* string) */

RS_NatCon RS_setNatConString(RS_NatCon arg, const char* string)
{
  if (RS_isNatConNatCon(arg)) {
    return (RS_NatCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("NatCon has no String: %t\n", arg);
  return (RS_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_Location accessors */

/*{{{  ATbool RS_isValidLocation(RS_Location arg) */

ATbool RS_isValidLocation(RS_Location arg)
{
  if (RS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (RS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isLocationFile(RS_Location arg) */

inline ATbool RS_isLocationFile(RS_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternLocationFile, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isLocationArea(RS_Location arg) */

inline ATbool RS_isLocationArea(RS_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternLocationArea, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool RS_isLocationAreaInFile(RS_Location arg) */

inline ATbool RS_isLocationAreaInFile(RS_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, RS_patternLocationAreaInFile, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool RS_hasLocationFilename(RS_Location arg) */

ATbool RS_hasLocationFilename(RS_Location arg)
{
  if (RS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasLocationArea(RS_Location arg) */

ATbool RS_hasLocationArea(RS_Location arg)
{
  if (RS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* RS_getLocationFilename(RS_Location arg) */

char* RS_getLocationFilename(RS_Location arg)
{
  if (RS_isLocationFile(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  RS_Area RS_getLocationArea(RS_Location arg) */

RS_Area RS_getLocationArea(RS_Location arg)
{
  if (RS_isLocationArea(arg)) {
    return (RS_Area)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_Area)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  RS_Location RS_setLocationFilename(RS_Location arg, const char* filename) */

RS_Location RS_setLocationFilename(RS_Location arg, const char* filename)
{
  if (RS_isLocationFile(arg)) {
    return (RS_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return (RS_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (RS_Location)NULL;
}

/*}}}  */
/*{{{  RS_Location RS_setLocationArea(RS_Location arg, RS_Area Area) */

RS_Location RS_setLocationArea(RS_Location arg, RS_Area Area)
{
  if (RS_isLocationArea(arg)) {
    return (RS_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 0);
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return (RS_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (RS_Location)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  RS_Area accessors */

/*{{{  ATbool RS_isValidArea(RS_Area arg) */

ATbool RS_isValidArea(RS_Area arg)
{
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool RS_isAreaArea(RS_Area arg) */

inline ATbool RS_isAreaArea(RS_Area arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, RS_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool RS_hasAreaBeginLine(RS_Area arg) */

ATbool RS_hasAreaBeginLine(RS_Area arg)
{
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasAreaBeginColumn(RS_Area arg) */

ATbool RS_hasAreaBeginColumn(RS_Area arg)
{
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasAreaEndLine(RS_Area arg) */

ATbool RS_hasAreaEndLine(RS_Area arg)
{
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasAreaEndColumn(RS_Area arg) */

ATbool RS_hasAreaEndColumn(RS_Area arg)
{
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasAreaOffset(RS_Area arg) */

ATbool RS_hasAreaOffset(RS_Area arg)
{
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool RS_hasAreaLength(RS_Area arg) */

ATbool RS_hasAreaLength(RS_Area arg)
{
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int RS_getAreaBeginLine(RS_Area arg) */

int RS_getAreaBeginLine(RS_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int RS_getAreaBeginColumn(RS_Area arg) */

int RS_getAreaBeginColumn(RS_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  int RS_getAreaEndLine(RS_Area arg) */

int RS_getAreaEndLine(RS_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  int RS_getAreaEndColumn(RS_Area arg) */

int RS_getAreaEndColumn(RS_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  int RS_getAreaOffset(RS_Area arg) */

int RS_getAreaOffset(RS_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 4));
}

/*}}}  */
/*{{{  int RS_getAreaLength(RS_Area arg) */

int RS_getAreaLength(RS_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 5));
}

/*}}}  */
/*{{{  RS_Area RS_setAreaBeginLine(RS_Area arg, int beginLine) */

RS_Area RS_setAreaBeginLine(RS_Area arg, int beginLine)
{
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginLine)), 0);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (RS_Area)NULL;
}

/*}}}  */
/*{{{  RS_Area RS_setAreaBeginColumn(RS_Area arg, int beginColumn) */

RS_Area RS_setAreaBeginColumn(RS_Area arg, int beginColumn)
{
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginColumn)), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (RS_Area)NULL;
}

/*}}}  */
/*{{{  RS_Area RS_setAreaEndLine(RS_Area arg, int endLine) */

RS_Area RS_setAreaEndLine(RS_Area arg, int endLine)
{
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (RS_Area)NULL;
}

/*}}}  */
/*{{{  RS_Area RS_setAreaEndColumn(RS_Area arg, int endColumn) */

RS_Area RS_setAreaEndColumn(RS_Area arg, int endColumn)
{
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endColumn)), 3);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (RS_Area)NULL;
}

/*}}}  */
/*{{{  RS_Area RS_setAreaOffset(RS_Area arg, int offset) */

RS_Area RS_setAreaOffset(RS_Area arg, int offset)
{
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(offset)), 4);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (RS_Area)NULL;
}

/*}}}  */
/*{{{  RS_Area RS_setAreaLength(RS_Area arg, int length) */

RS_Area RS_setAreaLength(RS_Area arg, int length)
{
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 5);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (RS_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  RS_RElem RS_visitRElem(RS_RElem arg, int (*acceptIntValue)(int), char* (*acceptStrValue)(char*), RS_Location (*acceptLocValue)(RS_Location), RS_RElemList (*acceptList)(RS_RElemList)) */

RS_RElem RS_visitRElem(RS_RElem arg, int (*acceptIntValue)(int), char* (*acceptStrValue)(char*), RS_Location (*acceptLocValue)(RS_Location), RS_RElemList (*acceptList)(RS_RElemList))
{
  if (RS_isRElemInt(arg)) {
    return RS_makeRElemInt(
        acceptIntValue ? acceptIntValue(RS_getRElemIntValue(arg)) : RS_getRElemIntValue(arg));
  }
  if (RS_isRElemStr(arg)) {
    return RS_makeRElemStr(
        acceptStrValue ? acceptStrValue(RS_getRElemStrValue(arg)) : RS_getRElemStrValue(arg));
  }
  if (RS_isRElemLoc(arg)) {
    return RS_makeRElemLoc(
        acceptLocValue ? acceptLocValue(RS_getRElemLocValue(arg)) : RS_getRElemLocValue(arg));
  }
  if (RS_isRElemSet(arg)) {
    return RS_makeRElemSet(
        acceptList ? acceptList(RS_getRElemList(arg)) : RS_getRElemList(arg));
  }
  if (RS_isRElemBag(arg)) {
    return RS_makeRElemBag(
        acceptList ? acceptList(RS_getRElemList(arg)) : RS_getRElemList(arg));
  }
  if (RS_isRElemTuple(arg)) {
    return RS_makeRElemTuple(
        acceptList ? acceptList(RS_getRElemList(arg)) : RS_getRElemList(arg));
  }
  ATabort("not a RElem: %t\n", arg);
  return (RS_RElem)NULL;
}

/*}}}  */
/*{{{  RS_RType RS_visitRType(RS_RType arg, RS_RTypeList (*acceptList)(RS_RTypeList), char* (*acceptStrCon)(char*)) */

RS_RType RS_visitRType(RS_RType arg, RS_RTypeList (*acceptList)(RS_RTypeList), char* (*acceptStrCon)(char*))
{
  if (RS_isRTypeInt(arg)) {
    return RS_makeRTypeInt();
  }
  if (RS_isRTypeStr(arg)) {
    return RS_makeRTypeStr();
  }
  if (RS_isRTypeLoc(arg)) {
    return RS_makeRTypeLoc();
  }
  if (RS_isRTypeTuple(arg)) {
    return RS_makeRTypeTuple(
        acceptList ? acceptList(RS_getRTypeList(arg)) : RS_getRTypeList(arg));
  }
  if (RS_isRTypeSet(arg)) {
    return RS_makeRTypeSet(
        RS_visitRType(RS_getRTypeRType(arg), acceptList, acceptStrCon));
  }
  if (RS_isRTypeBag(arg)) {
    return RS_makeRTypeBag(
        RS_visitRType(RS_getRTypeRType(arg), acceptList, acceptStrCon));
  }
  if (RS_isRTypeRel(arg)) {
    return RS_makeRTypeRel(
        acceptList ? acceptList(RS_getRTypeList(arg)) : RS_getRTypeList(arg));
  }
  if (RS_isRTypeUser(arg)) {
    return RS_makeRTypeUser(
        acceptStrCon ? acceptStrCon(RS_getRTypeStrCon(arg)) : RS_getRTypeStrCon(arg));
  }
  if (RS_isRTypeParameter(arg)) {
    return RS_makeRTypeParameter(
        acceptStrCon ? acceptStrCon(RS_getRTypeStrCon(arg)) : RS_getRTypeStrCon(arg));
  }
  ATabort("not a RType: %t\n", arg);
  return (RS_RType)NULL;
}

/*}}}  */
/*{{{  RS_RTuple RS_visitRTuple(RS_RTuple arg, char* (*acceptId)(char*), RS_RType (*acceptType)(RS_RType), RS_RElem (*acceptData)(RS_RElem)) */

RS_RTuple RS_visitRTuple(RS_RTuple arg, char* (*acceptId)(char*), RS_RType (*acceptType)(RS_RType), RS_RElem (*acceptData)(RS_RElem))
{
  if (RS_isRTupleRtuple(arg)) {
    return RS_makeRTupleRtuple(
        acceptId ? acceptId(RS_getRTupleId(arg)) : RS_getRTupleId(arg),
        acceptType ? acceptType(RS_getRTupleType(arg)) : RS_getRTupleType(arg),
        acceptData ? acceptData(RS_getRTupleData(arg)) : RS_getRTupleData(arg));
  }
  ATabort("not a RTuple: %t\n", arg);
  return (RS_RTuple)NULL;
}

/*}}}  */
/*{{{  RS_RStore RS_visitRStore(RS_RStore arg, RS_RTupleList (*acceptList)(RS_RTupleList)) */

RS_RStore RS_visitRStore(RS_RStore arg, RS_RTupleList (*acceptList)(RS_RTupleList))
{
  if (RS_isRStoreRstore(arg)) {
    return RS_makeRStoreRstore(
        acceptList ? acceptList(RS_getRStoreList(arg)) : RS_getRStoreList(arg));
  }
  ATabort("not a RStore: %t\n", arg);
  return (RS_RStore)NULL;
}

/*}}}  */
/*{{{  RS_RElemList RS_visitRElemList(RS_RElemList arg, RS_RElem (*acceptHead)(RS_RElem)) */

RS_RElemList RS_visitRElemList(RS_RElemList arg, RS_RElem (*acceptHead)(RS_RElem))
{
  if (RS_isRElemListEmpty(arg)) {
    return RS_makeRElemListEmpty();
  }
  if (RS_isRElemListSingle(arg)) {
    return RS_makeRElemListSingle(
        acceptHead ? acceptHead(RS_getRElemListHead(arg)) : RS_getRElemListHead(arg));
  }
  if (RS_isRElemListMany(arg)) {
    return RS_makeRElemListMany(
        acceptHead ? acceptHead(RS_getRElemListHead(arg)) : RS_getRElemListHead(arg),
        RS_visitRElemList(RS_getRElemListTail(arg), acceptHead));
  }
  ATabort("not a RElemList: %t\n", arg);
  return (RS_RElemList)NULL;
}

/*}}}  */
/*{{{  RS_RTypeList RS_visitRTypeList(RS_RTypeList arg, RS_RType (*acceptHead)(RS_RType)) */

RS_RTypeList RS_visitRTypeList(RS_RTypeList arg, RS_RType (*acceptHead)(RS_RType))
{
  if (RS_isRTypeListEmpty(arg)) {
    return RS_makeRTypeListEmpty();
  }
  if (RS_isRTypeListSingle(arg)) {
    return RS_makeRTypeListSingle(
        acceptHead ? acceptHead(RS_getRTypeListHead(arg)) : RS_getRTypeListHead(arg));
  }
  if (RS_isRTypeListMany(arg)) {
    return RS_makeRTypeListMany(
        acceptHead ? acceptHead(RS_getRTypeListHead(arg)) : RS_getRTypeListHead(arg),
        RS_visitRTypeList(RS_getRTypeListTail(arg), acceptHead));
  }
  ATabort("not a RTypeList: %t\n", arg);
  return (RS_RTypeList)NULL;
}

/*}}}  */
/*{{{  RS_RTupleList RS_visitRTupleList(RS_RTupleList arg, RS_RTuple (*acceptHead)(RS_RTuple)) */

RS_RTupleList RS_visitRTupleList(RS_RTupleList arg, RS_RTuple (*acceptHead)(RS_RTuple))
{
  if (RS_isRTupleListEmpty(arg)) {
    return RS_makeRTupleListEmpty();
  }
  if (RS_isRTupleListSingle(arg)) {
    return RS_makeRTupleListSingle(
        acceptHead ? acceptHead(RS_getRTupleListHead(arg)) : RS_getRTupleListHead(arg));
  }
  if (RS_isRTupleListMany(arg)) {
    return RS_makeRTupleListMany(
        acceptHead ? acceptHead(RS_getRTupleListHead(arg)) : RS_getRTupleListHead(arg),
        RS_visitRTupleList(RS_getRTupleListTail(arg), acceptHead));
  }
  ATabort("not a RTupleList: %t\n", arg);
  return (RS_RTupleList)NULL;
}

/*}}}  */
/*{{{  RS_StrChar RS_visitStrChar(RS_StrChar arg, char* (*acceptString)(char*)) */

RS_StrChar RS_visitStrChar(RS_StrChar arg, char* (*acceptString)(char*))
{
  if (RS_isStrCharStrChar(arg)) {
    return RS_makeStrCharStrChar(
        acceptString ? acceptString(RS_getStrCharString(arg)) : RS_getStrCharString(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (RS_StrChar)NULL;
}

/*}}}  */
/*{{{  RS_StrCon RS_visitStrCon(RS_StrCon arg, char* (*acceptString)(char*)) */

RS_StrCon RS_visitStrCon(RS_StrCon arg, char* (*acceptString)(char*))
{
  if (RS_isStrConStrCon(arg)) {
    return RS_makeStrConStrCon(
        acceptString ? acceptString(RS_getStrConString(arg)) : RS_getStrConString(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (RS_StrCon)NULL;
}

/*}}}  */
/*{{{  RS_NatCon RS_visitNatCon(RS_NatCon arg, char* (*acceptString)(char*)) */

RS_NatCon RS_visitNatCon(RS_NatCon arg, char* (*acceptString)(char*))
{
  if (RS_isNatConNatCon(arg)) {
    return RS_makeNatConNatCon(
        acceptString ? acceptString(RS_getNatConString(arg)) : RS_getNatConString(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (RS_NatCon)NULL;
}

/*}}}  */
/*{{{  RS_Location RS_visitLocation(RS_Location arg, char* (*acceptFilename)(char*), RS_Area (*acceptArea)(RS_Area)) */

RS_Location RS_visitLocation(RS_Location arg, char* (*acceptFilename)(char*), RS_Area (*acceptArea)(RS_Area))
{
  if (RS_isLocationFile(arg)) {
    return RS_makeLocationFile(
        acceptFilename ? acceptFilename(RS_getLocationFilename(arg)) : RS_getLocationFilename(arg));
  }
  if (RS_isLocationArea(arg)) {
    return RS_makeLocationArea(
        acceptArea ? acceptArea(RS_getLocationArea(arg)) : RS_getLocationArea(arg));
  }
  if (RS_isLocationAreaInFile(arg)) {
    return RS_makeLocationAreaInFile(
        acceptFilename ? acceptFilename(RS_getLocationFilename(arg)) : RS_getLocationFilename(arg),
        acceptArea ? acceptArea(RS_getLocationArea(arg)) : RS_getLocationArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (RS_Location)NULL;
}

/*}}}  */
/*{{{  RS_Area RS_visitArea(RS_Area arg, int (*acceptBeginLine)(int), int (*acceptBeginColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptOffset)(int), int (*acceptLength)(int)) */

RS_Area RS_visitArea(RS_Area arg, int (*acceptBeginLine)(int), int (*acceptBeginColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptOffset)(int), int (*acceptLength)(int))
{
  if (RS_isAreaArea(arg)) {
    return RS_makeAreaArea(
        acceptBeginLine ? acceptBeginLine(RS_getAreaBeginLine(arg)) : RS_getAreaBeginLine(arg),
        acceptBeginColumn ? acceptBeginColumn(RS_getAreaBeginColumn(arg)) : RS_getAreaBeginColumn(arg),
        acceptEndLine ? acceptEndLine(RS_getAreaEndLine(arg)) : RS_getAreaEndLine(arg),
        acceptEndColumn ? acceptEndColumn(RS_getAreaEndColumn(arg)) : RS_getAreaEndColumn(arg),
        acceptOffset ? acceptOffset(RS_getAreaOffset(arg)) : RS_getAreaOffset(arg),
        acceptLength ? acceptLength(RS_getAreaLength(arg)) : RS_getAreaLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (RS_Area)NULL;
}

/*}}}  */

/*}}}  */
