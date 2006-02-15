#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ParsedRStore.h"

/*{{{  conversion functions */

ATerm PRS_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm PRS_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *PRS_charsToString(ATerm arg)
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

char PRS_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _PRS_OptLayout;
typedef struct ATerm _PRS_Layout;
typedef struct ATerm _PRS_LexLayoutList;
typedef struct ATerm _PRS_RElem;
typedef struct ATerm _PRS_RType;
typedef struct ATerm _PRS_RTuple;
typedef struct ATerm _PRS_RStore;
typedef struct ATerm _PRS_Start;
typedef struct ATerm _PRS_RElemList;
typedef struct ATerm _PRS_RTypeList;
typedef struct ATerm _PRS_RTupleList;
typedef struct ATerm _PRS_LexStrChar;
typedef struct ATerm _PRS_StrChar;
typedef struct ATerm _PRS_LexStrCon;
typedef struct ATerm _PRS_StrCon;
typedef struct ATerm _PRS_LexStrCharChars;
typedef struct ATerm _PRS_LexNatCon;
typedef struct ATerm _PRS_NatCon;
typedef struct ATerm _PRS_LexLayout;
typedef struct ATerm _PRS_Location;
typedef struct ATerm _PRS_Area;

/*}}}  */

/*{{{  void PRS_initParsedRStoreApi(void) */

void PRS_initParsedRStoreApi(void)
{
  init_ParsedRStore_dict();
}

/*}}}  */

/*{{{  protect functions */

void PRS_protectOptLayout(PRS_OptLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectLayout(PRS_Layout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectLexLayoutList(PRS_LexLayoutList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectRElem(PRS_RElem *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectRType(PRS_RType *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectRTuple(PRS_RTuple *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectRStore(PRS_RStore *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectStart(PRS_Start *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectRElemList(PRS_RElemList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectRTypeList(PRS_RTypeList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectRTupleList(PRS_RTupleList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectLexStrChar(PRS_LexStrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectStrChar(PRS_StrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectLexStrCon(PRS_LexStrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectStrCon(PRS_StrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectLexStrCharChars(PRS_LexStrCharChars *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectLexNatCon(PRS_LexNatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectNatCon(PRS_NatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectLexLayout(PRS_LexLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectLocation(PRS_Location *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PRS_protectArea(PRS_Area *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  PRS_OptLayout PRS_OptLayoutFromTerm(ATerm t) */

PRS_OptLayout PRS_OptLayoutFromTerm(ATerm t)
{
  return (PRS_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm PRS_OptLayoutToTerm(PRS_OptLayout arg) */

ATerm PRS_OptLayoutToTerm(PRS_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_Layout PRS_LayoutFromTerm(ATerm t) */

PRS_Layout PRS_LayoutFromTerm(ATerm t)
{
  return (PRS_Layout)t;
}

/*}}}  */
/*{{{  ATerm PRS_LayoutToTerm(PRS_Layout arg) */

ATerm PRS_LayoutToTerm(PRS_Layout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_LexLayoutListFromTerm(ATerm t) */

PRS_LexLayoutList PRS_LexLayoutListFromTerm(ATerm t)
{
  return (PRS_LexLayoutList)t;
}

/*}}}  */
/*{{{  ATerm PRS_LexLayoutListToTerm(PRS_LexLayoutList arg) */

ATerm PRS_LexLayoutListToTerm(PRS_LexLayoutList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_RElem PRS_RElemFromTerm(ATerm t) */

PRS_RElem PRS_RElemFromTerm(ATerm t)
{
  return (PRS_RElem)t;
}

/*}}}  */
/*{{{  ATerm PRS_RElemToTerm(PRS_RElem arg) */

ATerm PRS_RElemToTerm(PRS_RElem arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_RType PRS_RTypeFromTerm(ATerm t) */

PRS_RType PRS_RTypeFromTerm(ATerm t)
{
  return (PRS_RType)t;
}

/*}}}  */
/*{{{  ATerm PRS_RTypeToTerm(PRS_RType arg) */

ATerm PRS_RTypeToTerm(PRS_RType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_RTupleFromTerm(ATerm t) */

PRS_RTuple PRS_RTupleFromTerm(ATerm t)
{
  return (PRS_RTuple)t;
}

/*}}}  */
/*{{{  ATerm PRS_RTupleToTerm(PRS_RTuple arg) */

ATerm PRS_RTupleToTerm(PRS_RTuple arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_RStore PRS_RStoreFromTerm(ATerm t) */

PRS_RStore PRS_RStoreFromTerm(ATerm t)
{
  return (PRS_RStore)t;
}

/*}}}  */
/*{{{  ATerm PRS_RStoreToTerm(PRS_RStore arg) */

ATerm PRS_RStoreToTerm(PRS_RStore arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_Start PRS_StartFromTerm(ATerm t) */

PRS_Start PRS_StartFromTerm(ATerm t)
{
  return (PRS_Start)t;
}

/*}}}  */
/*{{{  ATerm PRS_StartToTerm(PRS_Start arg) */

ATerm PRS_StartToTerm(PRS_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_RElemList PRS_RElemListFromTerm(ATerm t) */

PRS_RElemList PRS_RElemListFromTerm(ATerm t)
{
  return (PRS_RElemList)t;
}

/*}}}  */
/*{{{  ATerm PRS_RElemListToTerm(PRS_RElemList arg) */

ATerm PRS_RElemListToTerm(PRS_RElemList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_RTypeListFromTerm(ATerm t) */

PRS_RTypeList PRS_RTypeListFromTerm(ATerm t)
{
  return (PRS_RTypeList)t;
}

/*}}}  */
/*{{{  ATerm PRS_RTypeListToTerm(PRS_RTypeList arg) */

ATerm PRS_RTypeListToTerm(PRS_RTypeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_RTupleListFromTerm(ATerm t) */

PRS_RTupleList PRS_RTupleListFromTerm(ATerm t)
{
  return (PRS_RTupleList)t;
}

/*}}}  */
/*{{{  ATerm PRS_RTupleListToTerm(PRS_RTupleList arg) */

ATerm PRS_RTupleListToTerm(PRS_RTupleList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_LexStrCharFromTerm(ATerm t) */

PRS_LexStrChar PRS_LexStrCharFromTerm(ATerm t)
{
  return (PRS_LexStrChar)t;
}

/*}}}  */
/*{{{  ATerm PRS_LexStrCharToTerm(PRS_LexStrChar arg) */

ATerm PRS_LexStrCharToTerm(PRS_LexStrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_StrChar PRS_StrCharFromTerm(ATerm t) */

PRS_StrChar PRS_StrCharFromTerm(ATerm t)
{
  return (PRS_StrChar)t;
}

/*}}}  */
/*{{{  ATerm PRS_StrCharToTerm(PRS_StrChar arg) */

ATerm PRS_StrCharToTerm(PRS_StrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_LexStrCon PRS_LexStrConFromTerm(ATerm t) */

PRS_LexStrCon PRS_LexStrConFromTerm(ATerm t)
{
  return (PRS_LexStrCon)t;
}

/*}}}  */
/*{{{  ATerm PRS_LexStrConToTerm(PRS_LexStrCon arg) */

ATerm PRS_LexStrConToTerm(PRS_LexStrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_StrCon PRS_StrConFromTerm(ATerm t) */

PRS_StrCon PRS_StrConFromTerm(ATerm t)
{
  return (PRS_StrCon)t;
}

/*}}}  */
/*{{{  ATerm PRS_StrConToTerm(PRS_StrCon arg) */

ATerm PRS_StrConToTerm(PRS_StrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_LexStrCharCharsFromTerm(ATerm t) */

PRS_LexStrCharChars PRS_LexStrCharCharsFromTerm(ATerm t)
{
  return (PRS_LexStrCharChars)t;
}

/*}}}  */
/*{{{  ATerm PRS_LexStrCharCharsToTerm(PRS_LexStrCharChars arg) */

ATerm PRS_LexStrCharCharsToTerm(PRS_LexStrCharChars arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_LexNatCon PRS_LexNatConFromTerm(ATerm t) */

PRS_LexNatCon PRS_LexNatConFromTerm(ATerm t)
{
  return (PRS_LexNatCon)t;
}

/*}}}  */
/*{{{  ATerm PRS_LexNatConToTerm(PRS_LexNatCon arg) */

ATerm PRS_LexNatConToTerm(PRS_LexNatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_NatCon PRS_NatConFromTerm(ATerm t) */

PRS_NatCon PRS_NatConFromTerm(ATerm t)
{
  return (PRS_NatCon)t;
}

/*}}}  */
/*{{{  ATerm PRS_NatConToTerm(PRS_NatCon arg) */

ATerm PRS_NatConToTerm(PRS_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_LexLayout PRS_LexLayoutFromTerm(ATerm t) */

PRS_LexLayout PRS_LexLayoutFromTerm(ATerm t)
{
  return (PRS_LexLayout)t;
}

/*}}}  */
/*{{{  ATerm PRS_LexLayoutToTerm(PRS_LexLayout arg) */

ATerm PRS_LexLayoutToTerm(PRS_LexLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_Location PRS_LocationFromTerm(ATerm t) */

PRS_Location PRS_LocationFromTerm(ATerm t)
{
  return (PRS_Location)t;
}

/*}}}  */
/*{{{  ATerm PRS_LocationToTerm(PRS_Location arg) */

ATerm PRS_LocationToTerm(PRS_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PRS_Area PRS_AreaFromTerm(ATerm t) */

PRS_Area PRS_AreaFromTerm(ATerm t)
{
  return (PRS_Area)t;
}

/*}}}  */
/*{{{  ATerm PRS_AreaToTerm(PRS_Area arg) */

ATerm PRS_AreaToTerm(PRS_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int PRS_getLexLayoutListLength (PRS_LexLayoutList arg) {
  return ATgetLength((ATermList) arg);
}
PRS_LexLayoutList PRS_reverseLexLayoutList(PRS_LexLayoutList arg) {
  return (PRS_LexLayoutList) ATreverse((ATermList) arg);
}
PRS_LexLayoutList PRS_appendLexLayoutList(PRS_LexLayoutList arg, PRS_LexLayout elem) {
  return (PRS_LexLayoutList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
PRS_LexLayoutList PRS_concatLexLayoutList(PRS_LexLayoutList arg0, PRS_LexLayoutList arg1) {
  return (PRS_LexLayoutList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PRS_LexLayoutList PRS_sliceLexLayoutList(PRS_LexLayoutList arg, int start, int end) {
  return (PRS_LexLayoutList) ATgetSlice((ATermList) arg, start, end);
}
PRS_LexLayout PRS_getLexLayoutListLexLayoutAt(PRS_LexLayoutList arg, int index) {
 return (PRS_LexLayout)ATelementAt((ATermList) arg,index);
}
PRS_LexLayoutList PRS_replaceLexLayoutListLexLayoutAt(PRS_LexLayoutList arg, PRS_LexLayout elem, int index) {
 return (PRS_LexLayoutList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
PRS_LexLayoutList PRS_makeLexLayoutList2(PRS_LexLayout elem1, PRS_LexLayout elem2) {
  return (PRS_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
PRS_LexLayoutList PRS_makeLexLayoutList3(PRS_LexLayout elem1, PRS_LexLayout elem2, PRS_LexLayout elem3) {
  return (PRS_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
PRS_LexLayoutList PRS_makeLexLayoutList4(PRS_LexLayout elem1, PRS_LexLayout elem2, PRS_LexLayout elem3, PRS_LexLayout elem4) {
  return (PRS_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
PRS_LexLayoutList PRS_makeLexLayoutList5(PRS_LexLayout elem1, PRS_LexLayout elem2, PRS_LexLayout elem3, PRS_LexLayout elem4, PRS_LexLayout elem5) {
  return (PRS_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
PRS_LexLayoutList PRS_makeLexLayoutList6(PRS_LexLayout elem1, PRS_LexLayout elem2, PRS_LexLayout elem3, PRS_LexLayout elem4, PRS_LexLayout elem5, PRS_LexLayout elem6) {
  return (PRS_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int PRS_getRElemListLength (PRS_RElemList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PRS_RElemList PRS_reverseRElemList(PRS_RElemList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PRS_RElemList) result;
}
PRS_RElemList PRS_appendRElemList(PRS_RElemList arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem arg1) {
  return PRS_concatRElemList(arg0, wsAfterHead, wsAfterSep, PRS_makeRElemListSingle(arg1));
}
PRS_RElemList PRS_concatRElemList(PRS_RElemList arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElemList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PRS_makeRElemListMany((PRS_RElem)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PRS_RElemList) ATgetNext((ATermList) arg1);
  return (PRS_RElemList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PRS_RElemList PRS_sliceRElemList(PRS_RElemList arg, int start, int end) {
  return (PRS_RElemList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PRS_RElem PRS_getRElemListRElemAt(PRS_RElemList arg, int index) {
 return (PRS_RElem)ATelementAt((ATermList) arg,index * 4);
}
PRS_RElemList PRS_replaceRElemListRElemAt(PRS_RElemList arg, PRS_RElem elem, int index) {
 return (PRS_RElemList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PRS_RElemList PRS_makeRElemList2(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2) {
  return PRS_makeRElemListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemListSingle(elem2));
}
PRS_RElemList PRS_makeRElemList3(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2, PRS_RElem elem3) {
  return PRS_makeRElemListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PRS_RElemList PRS_makeRElemList4(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2, PRS_RElem elem3, PRS_RElem elem4) {
  return PRS_makeRElemListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PRS_RElemList PRS_makeRElemList5(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2, PRS_RElem elem3, PRS_RElem elem4, PRS_RElem elem5) {
  return PRS_makeRElemListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PRS_RElemList PRS_makeRElemList6(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElem elem1, PRS_RElem elem2, PRS_RElem elem3, PRS_RElem elem4, PRS_RElem elem5, PRS_RElem elem6) {
  return PRS_makeRElemListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRElemList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PRS_getRTypeListLength (PRS_RTypeList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PRS_RTypeList PRS_reverseRTypeList(PRS_RTypeList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PRS_RTypeList) result;
}
PRS_RTypeList PRS_appendRTypeList(PRS_RTypeList arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType arg1) {
  return PRS_concatRTypeList(arg0, wsAfterHead, wsAfterSep, PRS_makeRTypeListSingle(arg1));
}
PRS_RTypeList PRS_concatRTypeList(PRS_RTypeList arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTypeList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PRS_makeRTypeListMany((PRS_RType)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PRS_RTypeList) ATgetNext((ATermList) arg1);
  return (PRS_RTypeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PRS_RTypeList PRS_sliceRTypeList(PRS_RTypeList arg, int start, int end) {
  return (PRS_RTypeList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PRS_RType PRS_getRTypeListRTypeAt(PRS_RTypeList arg, int index) {
 return (PRS_RType)ATelementAt((ATermList) arg,index * 4);
}
PRS_RTypeList PRS_replaceRTypeListRTypeAt(PRS_RTypeList arg, PRS_RType elem, int index) {
 return (PRS_RTypeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PRS_RTypeList PRS_makeRTypeList2(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2) {
  return PRS_makeRTypeListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeListSingle(elem2));
}
PRS_RTypeList PRS_makeRTypeList3(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2, PRS_RType elem3) {
  return PRS_makeRTypeListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PRS_RTypeList PRS_makeRTypeList4(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2, PRS_RType elem3, PRS_RType elem4) {
  return PRS_makeRTypeListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PRS_RTypeList PRS_makeRTypeList5(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2, PRS_RType elem3, PRS_RType elem4, PRS_RType elem5) {
  return PRS_makeRTypeListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PRS_RTypeList PRS_makeRTypeList6(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RType elem1, PRS_RType elem2, PRS_RType elem3, PRS_RType elem4, PRS_RType elem5, PRS_RType elem6) {
  return PRS_makeRTypeListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTypeList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PRS_getRTupleListLength (PRS_RTupleList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PRS_RTupleList PRS_reverseRTupleList(PRS_RTupleList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PRS_RTupleList) result;
}
PRS_RTupleList PRS_appendRTupleList(PRS_RTupleList arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple arg1) {
  return PRS_concatRTupleList(arg0, wsAfterHead, wsAfterSep, PRS_makeRTupleListSingle(arg1));
}
PRS_RTupleList PRS_concatRTupleList(PRS_RTupleList arg0, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTupleList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PRS_makeRTupleListMany((PRS_RTuple)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PRS_RTupleList) ATgetNext((ATermList) arg1);
  return (PRS_RTupleList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PRS_RTupleList PRS_sliceRTupleList(PRS_RTupleList arg, int start, int end) {
  return (PRS_RTupleList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PRS_RTuple PRS_getRTupleListRTupleAt(PRS_RTupleList arg, int index) {
 return (PRS_RTuple)ATelementAt((ATermList) arg,index * 4);
}
PRS_RTupleList PRS_replaceRTupleListRTupleAt(PRS_RTupleList arg, PRS_RTuple elem, int index) {
 return (PRS_RTupleList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PRS_RTupleList PRS_makeRTupleList2(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2) {
  return PRS_makeRTupleListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleListSingle(elem2));
}
PRS_RTupleList PRS_makeRTupleList3(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2, PRS_RTuple elem3) {
  return PRS_makeRTupleListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PRS_RTupleList PRS_makeRTupleList4(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2, PRS_RTuple elem3, PRS_RTuple elem4) {
  return PRS_makeRTupleListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PRS_RTupleList PRS_makeRTupleList5(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2, PRS_RTuple elem3, PRS_RTuple elem4, PRS_RTuple elem5) {
  return PRS_makeRTupleListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PRS_RTupleList PRS_makeRTupleList6(PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTuple elem1, PRS_RTuple elem2, PRS_RTuple elem3, PRS_RTuple elem4, PRS_RTuple elem5, PRS_RTuple elem6) {
  return PRS_makeRTupleListMany(elem1, wsAfterHead, wsAfterSep, PRS_makeRTupleList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PRS_getLexStrCharCharsLength (PRS_LexStrCharChars arg) {
  return ATgetLength((ATermList) arg);
}
PRS_LexStrCharChars PRS_reverseLexStrCharChars(PRS_LexStrCharChars arg) {
  return (PRS_LexStrCharChars) ATreverse((ATermList) arg);
}
PRS_LexStrCharChars PRS_appendLexStrCharChars(PRS_LexStrCharChars arg, PRS_LexStrChar elem) {
  return (PRS_LexStrCharChars) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
PRS_LexStrCharChars PRS_concatLexStrCharChars(PRS_LexStrCharChars arg0, PRS_LexStrCharChars arg1) {
  return (PRS_LexStrCharChars) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PRS_LexStrCharChars PRS_sliceLexStrCharChars(PRS_LexStrCharChars arg, int start, int end) {
  return (PRS_LexStrCharChars) ATgetSlice((ATermList) arg, start, end);
}
PRS_LexStrChar PRS_getLexStrCharCharsLexStrCharAt(PRS_LexStrCharChars arg, int index) {
 return (PRS_LexStrChar)ATelementAt((ATermList) arg,index);
}
PRS_LexStrCharChars PRS_replaceLexStrCharCharsLexStrCharAt(PRS_LexStrCharChars arg, PRS_LexStrChar elem, int index) {
 return (PRS_LexStrCharChars) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
PRS_LexStrCharChars PRS_makeLexStrCharChars2(PRS_LexStrChar elem1, PRS_LexStrChar elem2) {
  return (PRS_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
PRS_LexStrCharChars PRS_makeLexStrCharChars3(PRS_LexStrChar elem1, PRS_LexStrChar elem2, PRS_LexStrChar elem3) {
  return (PRS_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
PRS_LexStrCharChars PRS_makeLexStrCharChars4(PRS_LexStrChar elem1, PRS_LexStrChar elem2, PRS_LexStrChar elem3, PRS_LexStrChar elem4) {
  return (PRS_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
PRS_LexStrCharChars PRS_makeLexStrCharChars5(PRS_LexStrChar elem1, PRS_LexStrChar elem2, PRS_LexStrChar elem3, PRS_LexStrChar elem4, PRS_LexStrChar elem5) {
  return (PRS_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
PRS_LexStrCharChars PRS_makeLexStrCharChars6(PRS_LexStrChar elem1, PRS_LexStrChar elem2, PRS_LexStrChar elem3, PRS_LexStrChar elem4, PRS_LexStrChar elem5, PRS_LexStrChar elem6) {
  return (PRS_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  PRS_OptLayout PRS_makeOptLayoutAbsent(void) */

PRS_OptLayout PRS_makeOptLayoutAbsent(void)
{
  return (PRS_OptLayout)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_makeOptLayoutPresent(PRS_Layout layout) */

PRS_OptLayout PRS_makeOptLayoutPresent(PRS_Layout layout)
{
  return (PRS_OptLayout)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl0(PRS_afun4))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) layout));
}

/*}}}  */
/*{{{  PRS_Layout PRS_makeLayoutLexToCf(PRS_LexLayoutList list) */

PRS_Layout PRS_makeLayoutLexToCf(PRS_LexLayoutList list)
{
  return (PRS_Layout)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun7, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl0(PRS_afun4)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun7, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm) list)));
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_makeLexLayoutListEmpty(void) */

PRS_LexLayoutList PRS_makeLexLayoutListEmpty(void)
{
  return (PRS_LexLayoutList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_makeLexLayoutListSingle(PRS_LexLayout head) */

PRS_LexLayoutList PRS_makeLexLayoutListSingle(PRS_LexLayout head)
{
  return (PRS_LexLayoutList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_makeLexLayoutListMany(PRS_LexLayout head, PRS_LexLayoutList tail) */

PRS_LexLayoutList PRS_makeLexLayoutListMany(PRS_LexLayout head, PRS_LexLayoutList tail)
{
  return (PRS_LexLayoutList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  PRS_RElem PRS_makeRElemInteger(PRS_OptLayout wsAfterInt, PRS_OptLayout wsAfterParenOpen, PRS_NatCon intValue, PRS_OptLayout wsAfterIntValue) */

PRS_RElem PRS_makeRElemInteger(PRS_OptLayout wsAfterInt, PRS_OptLayout wsAfterParenOpen, PRS_NatCon intValue, PRS_OptLayout wsAfterIntValue)
{
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun14))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun19)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterIntValue), (ATerm) intValue), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterInt), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun14)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PRS_RElem PRS_makeRElemString(PRS_OptLayout wsAfterStr, PRS_OptLayout wsAfterParenOpen, PRS_StrCon strValue, PRS_OptLayout wsAfterStrValue) */

PRS_RElem PRS_makeRElemString(PRS_OptLayout wsAfterStr, PRS_OptLayout wsAfterParenOpen, PRS_StrCon strValue, PRS_OptLayout wsAfterStrValue)
{
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun22))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun23)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterStrValue), (ATerm) strValue), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterStr), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun22)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  PRS_RElem PRS_makeRElemLocation(PRS_OptLayout wsAfterLoc, PRS_OptLayout wsAfterParenOpen, PRS_Location locValue, PRS_OptLayout wsAfterLocValue) */

PRS_RElem PRS_makeRElemLocation(PRS_OptLayout wsAfterLoc, PRS_OptLayout wsAfterParenOpen, PRS_Location locValue, PRS_OptLayout wsAfterLocValue)
{
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun24)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun25))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun26)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterLocValue), (ATerm) locValue), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterLoc), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun25)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  PRS_RElem PRS_makeRElemSet(PRS_OptLayout wsAfterSet, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RElemList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose) */

PRS_RElem PRS_makeRElemSet(PRS_OptLayout wsAfterSet, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RElemList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose)
{
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun28, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun31))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun31)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun28, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterSet), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun31)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  PRS_RElem PRS_makeRElemBag(PRS_OptLayout wsAfterBag, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RElemList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose) */

PRS_RElem PRS_makeRElemBag(PRS_OptLayout wsAfterBag, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RElemList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose)
{
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun28, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun32))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun32)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun28, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterBag), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun32)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(98)))));
}

/*}}}  */
/*{{{  PRS_RElem PRS_makeRElemTuple(PRS_OptLayout wsAfterTuple, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RElemList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose) */

PRS_RElem PRS_makeRElemTuple(PRS_OptLayout wsAfterTuple, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RElemList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose)
{
  return (PRS_RElem)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun33, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun34))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun34)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun33, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterTuple), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun34)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeInteger(void) */

PRS_RType PRS_makeRTypeInteger(void)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun14))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun19)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun14)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeString(void) */

PRS_RType PRS_makeRTypeString(void)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun22))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun23)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun22)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeLocation(void) */

PRS_RType PRS_makeRTypeLocation(void)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun25))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun26)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun25)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeTuple(PRS_OptLayout wsAfterTuple, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RTypeList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose) */

PRS_RType PRS_makeRTypeTuple(PRS_OptLayout wsAfterTuple, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RTypeList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun33, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun34))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun34)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun33, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterTuple), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun34)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeSet(PRS_OptLayout wsAfterSet, PRS_OptLayout wsAfterParenOpen, PRS_RType RType, PRS_OptLayout wsAfterRType) */

PRS_RType PRS_makeRTypeSet(PRS_OptLayout wsAfterSet, PRS_OptLayout wsAfterParenOpen, PRS_RType RType, PRS_OptLayout wsAfterRType)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun31))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun31)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterRType), (ATerm) RType), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterSet), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun31)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeBag(PRS_OptLayout wsAfterBag, PRS_OptLayout wsAfterParenOpen, PRS_RType RType, PRS_OptLayout wsAfterRType) */

PRS_RType PRS_makeRTypeBag(PRS_OptLayout wsAfterBag, PRS_OptLayout wsAfterParenOpen, PRS_RType RType, PRS_OptLayout wsAfterRType)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun32))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun32)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterRType), (ATerm) RType), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterBag), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun32)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(98)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeRel(PRS_OptLayout wsAfterRel, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RTypeList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose) */

PRS_RType PRS_makeRTypeRel(PRS_OptLayout wsAfterRel, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RTypeList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun28, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun36))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun36)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun28, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterRel), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun36)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeUser(PRS_OptLayout wsAfterUser, PRS_OptLayout wsAfterParenOpen, PRS_StrCon StrCon, PRS_OptLayout wsAfterStrCon) */

PRS_RType PRS_makeRTypeUser(PRS_OptLayout wsAfterUser, PRS_OptLayout wsAfterParenOpen, PRS_StrCon StrCon, PRS_OptLayout wsAfterStrCon)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun37))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun37)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterStrCon), (ATerm) StrCon), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterUser), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun37)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(117)))));
}

/*}}}  */
/*{{{  PRS_RType PRS_makeRTypeParameter(PRS_OptLayout wsAfterParameter, PRS_OptLayout wsAfterParenOpen, PRS_StrCon StrCon, PRS_OptLayout wsAfterStrCon) */

PRS_RType PRS_makeRTypeParameter(PRS_OptLayout wsAfterParameter, PRS_OptLayout wsAfterParenOpen, PRS_StrCon StrCon, PRS_OptLayout wsAfterStrCon)
{
  return (PRS_RType)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun38))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterStrCon), (ATerm) StrCon), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterParameter), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun38)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(112)))));
}

/*}}}  */
/*{{{  PRS_RTuple PRS_makeRTupleRtuple(PRS_OptLayout wsAfterRtuple, PRS_OptLayout wsAfterParenOpen, PRS_StrCon id, PRS_OptLayout wsAfterId, PRS_OptLayout wsAfterComma, PRS_RType rtype, PRS_OptLayout wsAfterRtype, PRS_OptLayout wsAfterComma1, PRS_RElem data, PRS_OptLayout wsAfterData) */

PRS_RTuple PRS_makeRTupleRtuple(PRS_OptLayout wsAfterRtuple, PRS_OptLayout wsAfterParenOpen, PRS_StrCon id, PRS_OptLayout wsAfterId, PRS_OptLayout wsAfterComma, PRS_RType rtype, PRS_OptLayout wsAfterRtype, PRS_OptLayout wsAfterComma1, PRS_RElem data, PRS_OptLayout wsAfterData)
{
  return (PRS_RTuple)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun15)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun35)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun39))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun40))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun39)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterData), (ATerm) data), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterRtype), (ATerm) rtype), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterRtuple), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun39)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  PRS_RStore PRS_makeRStoreRstore(PRS_OptLayout wsAfterRstore, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RTupleList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose) */

PRS_RStore PRS_makeRStoreRstore(PRS_OptLayout wsAfterRstore, PRS_OptLayout wsAfterParenOpen, PRS_OptLayout wsAfterBracketOpen, PRS_RTupleList list, PRS_OptLayout wsAfterList, PRS_OptLayout wsAfterBracketClose)
{
  return (PRS_RStore)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun28, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun40)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun41))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun42))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun41)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun27)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl2(PRS_afun28, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun40)), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun30)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterRstore), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun41)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  PRS_Start PRS_makeStartRStore(PRS_OptLayout wsBefore, PRS_RStore topRStore, PRS_OptLayout wsAfter, int ambCnt) */

PRS_Start PRS_makeStartRStore(PRS_OptLayout wsBefore, PRS_RStore topRStore, PRS_OptLayout wsAfter, int ambCnt)
{
  return (PRS_Start)(ATerm)ATmakeAppl2(PRS_afun43, (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun42))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun44)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topRStore), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PRS_RElemList PRS_makeRElemListEmpty(void) */

PRS_RElemList PRS_makeRElemListEmpty(void)
{
  return (PRS_RElemList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PRS_RElemList PRS_makeRElemListSingle(PRS_RElem head) */

PRS_RElemList PRS_makeRElemListSingle(PRS_RElem head)
{
  return (PRS_RElemList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PRS_RElemList PRS_makeRElemListMany(PRS_RElem head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElemList tail) */

PRS_RElemList PRS_makeRElemListMany(PRS_RElem head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RElemList tail)
{
  if (PRS_isRElemListEmpty(tail)) {
    return PRS_makeRElemListSingle(head);
  }
  return (PRS_RElemList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_makeRTypeListEmpty(void) */

PRS_RTypeList PRS_makeRTypeListEmpty(void)
{
  return (PRS_RTypeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_makeRTypeListSingle(PRS_RType head) */

PRS_RTypeList PRS_makeRTypeListSingle(PRS_RType head)
{
  return (PRS_RTypeList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_makeRTypeListMany(PRS_RType head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTypeList tail) */

PRS_RTypeList PRS_makeRTypeListMany(PRS_RType head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTypeList tail)
{
  if (PRS_isRTypeListEmpty(tail)) {
    return PRS_makeRTypeListSingle(head);
  }
  return (PRS_RTypeList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_makeRTupleListEmpty(void) */

PRS_RTupleList PRS_makeRTupleListEmpty(void)
{
  return (PRS_RTupleList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_makeRTupleListSingle(PRS_RTuple head) */

PRS_RTupleList PRS_makeRTupleListSingle(PRS_RTuple head)
{
  return (PRS_RTupleList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_makeRTupleListMany(PRS_RTuple head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTupleList tail) */

PRS_RTupleList PRS_makeRTupleListMany(PRS_RTuple head, PRS_OptLayout wsAfterHead, PRS_OptLayout wsAfterSep, PRS_RTupleList tail)
{
  if (PRS_isRTupleListEmpty(tail)) {
    return PRS_makeRTupleListSingle(head);
  }
  return (PRS_RTupleList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_makeLexStrCharNewline(void) */

PRS_LexStrChar PRS_makeLexStrCharNewline(void)
{
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun45))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun47)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun45)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_makeLexStrCharTab(void) */

PRS_LexStrChar PRS_makeLexStrCharTab(void)
{
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun48))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun49)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun48)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_makeLexStrCharQuote(void) */

PRS_LexStrChar PRS_makeLexStrCharQuote(void)
{
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun50))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun51)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun50)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_makeLexStrCharBackslash(void) */

PRS_LexStrChar PRS_makeLexStrCharBackslash(void)
{
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun52))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun53)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun52)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(92)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_makeLexStrCharDecimal(char a, char b, char c) */

PRS_LexStrChar PRS_makeLexStrCharDecimal(char a, char b, char c)
{
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun55))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun56)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ((ATerm) PRS_byteToChar(c))), (ATerm) ((ATerm) PRS_byteToChar(b))), (ATerm) ((ATerm) PRS_byteToChar(a))), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun55)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_makeLexStrCharNormal(char ch) */

PRS_LexStrChar PRS_makeLexStrCharNormal(char ch)
{
  return (PRS_LexStrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(93), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(35), (ATerm)ATmakeInt(91))), (ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(32), (ATerm)ATmakeInt(33))))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun57)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) PRS_byteToChar(ch))));
}

/*}}}  */
/*{{{  PRS_StrChar PRS_makeStrCharLexToCf(PRS_LexStrChar StrChar) */

PRS_StrChar PRS_makeStrCharLexToCf(PRS_LexStrChar StrChar)
{
  return (PRS_StrChar)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) StrChar));
}

/*}}}  */
/*{{{  PRS_LexStrCon PRS_makeLexStrConDefault(PRS_LexStrCharChars chars) */

PRS_LexStrCon PRS_makeLexStrConDefault(PRS_LexStrCharChars chars)
{
  return (PRS_LexStrCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun58, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun59)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun58, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun46))))), (ATerm) chars)), (ATerm)ATmakeInt(34)));
}

/*}}}  */
/*{{{  PRS_StrCon PRS_makeStrConLexToCf(PRS_LexStrCon StrCon) */

PRS_StrCon PRS_makeStrConLexToCf(PRS_LexStrCon StrCon)
{
  return (PRS_StrCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_makeLexStrCharCharsEmpty(void) */

PRS_LexStrCharChars PRS_makeLexStrCharCharsEmpty(void)
{
  return (PRS_LexStrCharChars)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_makeLexStrCharCharsSingle(PRS_LexStrChar head) */

PRS_LexStrCharChars PRS_makeLexStrCharCharsSingle(PRS_LexStrChar head)
{
  return (PRS_LexStrCharChars)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_makeLexStrCharCharsMany(PRS_LexStrChar head, PRS_LexStrCharChars tail) */

PRS_LexStrCharChars PRS_makeLexStrCharCharsMany(PRS_LexStrChar head, PRS_LexStrCharChars tail)
{
  return (PRS_LexStrCharChars)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  PRS_LexNatCon PRS_makeLexNatConDigits(const char* list) */

PRS_LexNatCon PRS_makeLexNatConDigits(const char* list)
{
  return (PRS_LexNatCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun7, (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun60)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl1(PRS_afun8, (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun7, (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm) ((ATerm) PRS_stringToChars(list)))));
}

/*}}}  */
/*{{{  PRS_NatCon PRS_makeNatConLexToCf(PRS_LexNatCon NatCon) */

PRS_NatCon PRS_makeNatConLexToCf(PRS_LexNatCon NatCon)
{
  return (PRS_NatCon)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12))), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  PRS_LexLayout PRS_makeLexLayoutWhitespace(char ch) */

PRS_LexLayout PRS_makeLexLayoutWhitespace(char ch)
{
  return (PRS_LexLayout)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(32)), (ATerm)ATmakeInt(13)), (ATerm)ATmakeAppl2(PRS_afun54, (ATerm)ATmakeInt(9), (ATerm)ATmakeInt(10))))), (ATerm)ATmakeAppl1(PRS_afun6, (ATerm)ATmakeAppl0(PRS_afun4)), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun61)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) PRS_byteToChar(ch))));
}

/*}}}  */
/*{{{  PRS_Location PRS_makeLocationFile(PRS_OptLayout wsAfterFile, PRS_OptLayout wsAfterParenOpen, PRS_StrCon filename, PRS_OptLayout wsAfterFilename) */

PRS_Location PRS_makeLocationFile(PRS_OptLayout wsAfterFile, PRS_OptLayout wsAfterParenOpen, PRS_StrCon filename, PRS_OptLayout wsAfterFilename)
{
  return (PRS_Location)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun62))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun24))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun62)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFile), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun62)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(102)))));
}

/*}}}  */
/*{{{  PRS_Location PRS_makeLocationArea(PRS_OptLayout wsAfterA, PRS_OptLayout wsAfterParenOpen, PRS_Area Area, PRS_OptLayout wsAfterArea) */

PRS_Location PRS_makeLocationArea(PRS_OptLayout wsAfterA, PRS_OptLayout wsAfterParenOpen, PRS_Area Area, PRS_OptLayout wsAfterArea)
{
  return (PRS_Location)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun63)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun64))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun24))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun64)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterA), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun64)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PRS_Location PRS_makeLocationAreaInFile(PRS_OptLayout wsAfterAreaInFile, PRS_OptLayout wsAfterParenOpen, PRS_StrCon filename, PRS_OptLayout wsAfterFilename, PRS_OptLayout wsAfterComma, PRS_Area Area, PRS_OptLayout wsAfterArea) */

PRS_Location PRS_makeLocationAreaInFile(PRS_OptLayout wsAfterAreaInFile, PRS_OptLayout wsAfterParenOpen, PRS_StrCon filename, PRS_OptLayout wsAfterFilename, PRS_OptLayout wsAfterComma, PRS_Area Area, PRS_OptLayout wsAfterArea)
{
  return (PRS_Location)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun63)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun21)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun65))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun24))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun65)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAreaInFile), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun65)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PRS_Area PRS_makeAreaArea(PRS_OptLayout wsAfterArea, PRS_OptLayout wsAfterParenOpen, PRS_NatCon beginLine, PRS_OptLayout wsAfterBeginLine, PRS_OptLayout wsAfterComma, PRS_NatCon beginColumn, PRS_OptLayout wsAfterBeginColumn, PRS_OptLayout wsAfterComma1, PRS_NatCon endLine, PRS_OptLayout wsAfterEndLine, PRS_OptLayout wsAfterComma2, PRS_NatCon endColumn, PRS_OptLayout wsAfterEndColumn, PRS_OptLayout wsAfterComma3, PRS_NatCon offset, PRS_OptLayout wsAfterOffset, PRS_OptLayout wsAfterComma4, PRS_NatCon length, PRS_OptLayout wsAfterLength) */

PRS_Area PRS_makeAreaArea(PRS_OptLayout wsAfterArea, PRS_OptLayout wsAfterParenOpen, PRS_NatCon beginLine, PRS_OptLayout wsAfterBeginLine, PRS_OptLayout wsAfterComma, PRS_NatCon beginColumn, PRS_OptLayout wsAfterBeginColumn, PRS_OptLayout wsAfterComma1, PRS_NatCon endLine, PRS_OptLayout wsAfterEndLine, PRS_OptLayout wsAfterComma2, PRS_NatCon endColumn, PRS_OptLayout wsAfterEndColumn, PRS_OptLayout wsAfterComma3, PRS_NatCon offset, PRS_OptLayout wsAfterOffset, PRS_OptLayout wsAfterComma4, PRS_NatCon length, PRS_OptLayout wsAfterLength)
{
  return (PRS_Area)(ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun12)))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun3, (ATerm)ATmakeAppl0(PRS_afun4)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun64))), (ATerm)ATmakeAppl1(PRS_afun2, (ATerm)ATmakeAppl1(PRS_afun11, (ATerm)ATmakeAppl0(PRS_afun63))), (ATerm)ATmakeAppl1(PRS_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun17, (ATerm)ATmakeAppl1(PRS_afun18, (ATerm)ATmakeAppl0(PRS_afun64)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun10)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterLength), (ATerm) length), (ATerm) wsAfterComma4), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterOffset), (ATerm) offset), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterEndColumn), (ATerm) endColumn), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterEndLine), (ATerm) endLine), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterBeginColumn), (ATerm) beginColumn), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun29)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterBeginLine), (ATerm) beginLine), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun13)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterArea), (ATerm)ATmakeAppl2(PRS_afun0, (ATerm)ATmakeAppl3(PRS_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PRS_afun20, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PRS_afun9, (ATerm)ATmakeAppl0(PRS_afun64)), (ATerm)ATmakeAppl0(PRS_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PRS_isEqualOptLayout(PRS_OptLayout arg0, PRS_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualLayout(PRS_Layout arg0, PRS_Layout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualLexLayoutList(PRS_LexLayoutList arg0, PRS_LexLayoutList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualRElem(PRS_RElem arg0, PRS_RElem arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualRType(PRS_RType arg0, PRS_RType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualRTuple(PRS_RTuple arg0, PRS_RTuple arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualRStore(PRS_RStore arg0, PRS_RStore arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualStart(PRS_Start arg0, PRS_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualRElemList(PRS_RElemList arg0, PRS_RElemList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualRTypeList(PRS_RTypeList arg0, PRS_RTypeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualRTupleList(PRS_RTupleList arg0, PRS_RTupleList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualLexStrChar(PRS_LexStrChar arg0, PRS_LexStrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualStrChar(PRS_StrChar arg0, PRS_StrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualLexStrCon(PRS_LexStrCon arg0, PRS_LexStrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualStrCon(PRS_StrCon arg0, PRS_StrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualLexStrCharChars(PRS_LexStrCharChars arg0, PRS_LexStrCharChars arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualLexNatCon(PRS_LexNatCon arg0, PRS_LexNatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualNatCon(PRS_NatCon arg0, PRS_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualLexLayout(PRS_LexLayout arg0, PRS_LexLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualLocation(PRS_Location arg0, PRS_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PRS_isEqualArea(PRS_Area arg0, PRS_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PRS_OptLayout accessors */

/*{{{  ATbool PRS_isValidOptLayout(PRS_OptLayout arg) */

ATbool PRS_isValidOptLayout(PRS_OptLayout arg)
{
  if (PRS_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (PRS_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isOptLayoutAbsent(PRS_OptLayout arg) */

inline ATbool PRS_isOptLayoutAbsent(PRS_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isOptLayoutPresent(PRS_OptLayout arg) */

inline ATbool PRS_isOptLayoutPresent(PRS_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasOptLayoutLayout(PRS_OptLayout arg) */

ATbool PRS_hasOptLayoutLayout(PRS_OptLayout arg)
{
  if (PRS_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_Layout PRS_getOptLayoutLayout(PRS_OptLayout arg) */

PRS_Layout PRS_getOptLayoutLayout(PRS_OptLayout arg)
{
  
    return (PRS_Layout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_setOptLayoutLayout(PRS_OptLayout arg, PRS_Layout layout) */

PRS_OptLayout PRS_setOptLayoutLayout(PRS_OptLayout arg, PRS_Layout layout)
{
  if (PRS_isOptLayoutPresent(arg)) {
    return (PRS_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) layout), 0), 1);
  }

  ATabort("OptLayout has no Layout: %t\n", arg);
  return (PRS_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_Layout accessors */

/*{{{  ATbool PRS_isValidLayout(PRS_Layout arg) */

ATbool PRS_isValidLayout(PRS_Layout arg)
{
  if (PRS_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLayoutLexToCf(PRS_Layout arg) */

inline ATbool PRS_isLayoutLexToCf(PRS_Layout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLayoutLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasLayoutList(PRS_Layout arg) */

ATbool PRS_hasLayoutList(PRS_Layout arg)
{
  if (PRS_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_getLayoutList(PRS_Layout arg) */

PRS_LexLayoutList PRS_getLayoutList(PRS_Layout arg)
{
  
    return (PRS_LexLayoutList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  PRS_Layout PRS_setLayoutList(PRS_Layout arg, PRS_LexLayoutList list) */

PRS_Layout PRS_setLayoutList(PRS_Layout arg, PRS_LexLayoutList list)
{
  if (PRS_isLayoutLexToCf(arg)) {
    return (PRS_Layout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("Layout has no List: %t\n", arg);
  return (PRS_Layout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_LexLayoutList accessors */

/*{{{  ATbool PRS_isValidLexLayoutList(PRS_LexLayoutList arg) */

ATbool PRS_isValidLexLayoutList(PRS_LexLayoutList arg)
{
  if (PRS_isLexLayoutListEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexLayoutListEmpty(PRS_LexLayoutList arg) */

inline ATbool PRS_isLexLayoutListEmpty(PRS_LexLayoutList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexLayoutListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexLayoutListSingle(PRS_LexLayoutList arg) */

inline ATbool PRS_isLexLayoutListSingle(PRS_LexLayoutList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexLayoutListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexLayoutListMany(PRS_LexLayoutList arg) */

inline ATbool PRS_isLexLayoutListMany(PRS_LexLayoutList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexLayoutListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasLexLayoutListHead(PRS_LexLayoutList arg) */

ATbool PRS_hasLexLayoutListHead(PRS_LexLayoutList arg)
{
  if (PRS_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLexLayoutListTail(PRS_LexLayoutList arg) */

ATbool PRS_hasLexLayoutListTail(PRS_LexLayoutList arg)
{
  if (PRS_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_LexLayout PRS_getLexLayoutListHead(PRS_LexLayoutList arg) */

PRS_LexLayout PRS_getLexLayoutListHead(PRS_LexLayoutList arg)
{
  if (PRS_isLexLayoutListSingle(arg)) {
    return (PRS_LexLayout)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_LexLayout)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_getLexLayoutListTail(PRS_LexLayoutList arg) */

PRS_LexLayoutList PRS_getLexLayoutListTail(PRS_LexLayoutList arg)
{
  
    return (PRS_LexLayoutList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_setLexLayoutListHead(PRS_LexLayoutList arg, PRS_LexLayout head) */

PRS_LexLayoutList PRS_setLexLayoutListHead(PRS_LexLayoutList arg, PRS_LexLayout head)
{
  if (PRS_isLexLayoutListSingle(arg)) {
    return (PRS_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isLexLayoutListMany(arg)) {
    return (PRS_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexLayoutList has no Head: %t\n", arg);
  return (PRS_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_setLexLayoutListTail(PRS_LexLayoutList arg, PRS_LexLayoutList tail) */

PRS_LexLayoutList PRS_setLexLayoutListTail(PRS_LexLayoutList arg, PRS_LexLayoutList tail)
{
  if (PRS_isLexLayoutListMany(arg)) {
    return (PRS_LexLayoutList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexLayoutList has no Tail: %t\n", arg);
  return (PRS_LexLayoutList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_RElem accessors */

/*{{{  ATbool PRS_isValidRElem(PRS_RElem arg) */

ATbool PRS_isValidRElem(PRS_RElem arg)
{
  if (PRS_isRElemInteger(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemString(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemLocation(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemInteger(PRS_RElem arg) */

inline ATbool PRS_isRElemInteger(PRS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemInteger, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemString(PRS_RElem arg) */

inline ATbool PRS_isRElemString(PRS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemString, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemLocation(PRS_RElem arg) */

inline ATbool PRS_isRElemLocation(PRS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemLocation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemSet(PRS_RElem arg) */

inline ATbool PRS_isRElemSet(PRS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemSet, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemBag(PRS_RElem arg) */

inline ATbool PRS_isRElemBag(PRS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemBag, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemTuple(PRS_RElem arg) */

inline ATbool PRS_isRElemTuple(PRS_RElem arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemTuple, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterInt(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterInt(PRS_RElem arg)
{
  if (PRS_isRElemInteger(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterParenOpen(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterParenOpen(PRS_RElem arg)
{
  if (PRS_isRElemInteger(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemString(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemLocation(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemIntValue(PRS_RElem arg) */

ATbool PRS_hasRElemIntValue(PRS_RElem arg)
{
  if (PRS_isRElemInteger(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterIntValue(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterIntValue(PRS_RElem arg)
{
  if (PRS_isRElemInteger(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterStr(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterStr(PRS_RElem arg)
{
  if (PRS_isRElemString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemStrValue(PRS_RElem arg) */

ATbool PRS_hasRElemStrValue(PRS_RElem arg)
{
  if (PRS_isRElemString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterStrValue(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterStrValue(PRS_RElem arg)
{
  if (PRS_isRElemString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterLoc(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterLoc(PRS_RElem arg)
{
  if (PRS_isRElemLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemLocValue(PRS_RElem arg) */

ATbool PRS_hasRElemLocValue(PRS_RElem arg)
{
  if (PRS_isRElemLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterLocValue(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterLocValue(PRS_RElem arg)
{
  if (PRS_isRElemLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterSet(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterSet(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterBracketOpen(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterBracketOpen(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemList(PRS_RElem arg) */

ATbool PRS_hasRElemList(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterList(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterList(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterBracketClose(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterBracketClose(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterBag(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterBag(PRS_RElem arg)
{
  if (PRS_isRElemBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemWsAfterTuple(PRS_RElem arg) */

ATbool PRS_hasRElemWsAfterTuple(PRS_RElem arg)
{
  if (PRS_isRElemTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterInt(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterInt(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterParenOpen(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterParenOpen(PRS_RElem arg)
{
  if (PRS_isRElemInteger(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRElemString(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRElemLocation(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRElemSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PRS_NatCon PRS_getRElemIntValue(PRS_RElem arg) */

PRS_NatCon PRS_getRElemIntValue(PRS_RElem arg)
{
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterIntValue(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterIntValue(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterStr(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterStr(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_StrCon PRS_getRElemStrValue(PRS_RElem arg) */

PRS_StrCon PRS_getRElemStrValue(PRS_RElem arg)
{
  
    return (PRS_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterStrValue(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterStrValue(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterLoc(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterLoc(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_Location PRS_getRElemLocValue(PRS_RElem arg) */

PRS_Location PRS_getRElemLocValue(PRS_RElem arg)
{
  
    return (PRS_Location)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterLocValue(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterLocValue(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterSet(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterSet(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterBracketOpen(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterBracketOpen(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_RElemList PRS_getRElemList(PRS_RElem arg) */

PRS_RElemList PRS_getRElemList(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElemList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElemList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else 
    return (PRS_RElemList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterList(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterList(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterBracketClose(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterBracketClose(PRS_RElem arg)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterBag(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterBag(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemWsAfterTuple(PRS_RElem arg) */

PRS_OptLayout PRS_getRElemWsAfterTuple(PRS_RElem arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterInt(PRS_RElem arg, PRS_OptLayout wsAfterInt) */

PRS_RElem PRS_setRElemWsAfterInt(PRS_RElem arg, PRS_OptLayout wsAfterInt)
{
  if (PRS_isRElemInteger(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterInt), 1), 1);
  }

  ATabort("RElem has no WsAfterInt: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterParenOpen(PRS_RElem arg, PRS_OptLayout wsAfterParenOpen) */

PRS_RElem PRS_setRElemWsAfterParenOpen(PRS_RElem arg, PRS_OptLayout wsAfterParenOpen)
{
  if (PRS_isRElemInteger(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRElemString(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRElemLocation(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("RElem has no WsAfterParenOpen: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemIntValue(PRS_RElem arg, PRS_NatCon intValue) */

PRS_RElem PRS_setRElemIntValue(PRS_RElem arg, PRS_NatCon intValue)
{
  if (PRS_isRElemInteger(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) intValue), 4), 1);
  }

  ATabort("RElem has no IntValue: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterIntValue(PRS_RElem arg, PRS_OptLayout wsAfterIntValue) */

PRS_RElem PRS_setRElemWsAfterIntValue(PRS_RElem arg, PRS_OptLayout wsAfterIntValue)
{
  if (PRS_isRElemInteger(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIntValue), 5), 1);
  }

  ATabort("RElem has no WsAfterIntValue: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterStr(PRS_RElem arg, PRS_OptLayout wsAfterStr) */

PRS_RElem PRS_setRElemWsAfterStr(PRS_RElem arg, PRS_OptLayout wsAfterStr)
{
  if (PRS_isRElemString(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStr), 1), 1);
  }

  ATabort("RElem has no WsAfterStr: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemStrValue(PRS_RElem arg, PRS_StrCon strValue) */

PRS_RElem PRS_setRElemStrValue(PRS_RElem arg, PRS_StrCon strValue)
{
  if (PRS_isRElemString(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) strValue), 4), 1);
  }

  ATabort("RElem has no StrValue: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterStrValue(PRS_RElem arg, PRS_OptLayout wsAfterStrValue) */

PRS_RElem PRS_setRElemWsAfterStrValue(PRS_RElem arg, PRS_OptLayout wsAfterStrValue)
{
  if (PRS_isRElemString(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStrValue), 5), 1);
  }

  ATabort("RElem has no WsAfterStrValue: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterLoc(PRS_RElem arg, PRS_OptLayout wsAfterLoc) */

PRS_RElem PRS_setRElemWsAfterLoc(PRS_RElem arg, PRS_OptLayout wsAfterLoc)
{
  if (PRS_isRElemLocation(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLoc), 1), 1);
  }

  ATabort("RElem has no WsAfterLoc: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemLocValue(PRS_RElem arg, PRS_Location locValue) */

PRS_RElem PRS_setRElemLocValue(PRS_RElem arg, PRS_Location locValue)
{
  if (PRS_isRElemLocation(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) locValue), 4), 1);
  }

  ATabort("RElem has no LocValue: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterLocValue(PRS_RElem arg, PRS_OptLayout wsAfterLocValue) */

PRS_RElem PRS_setRElemWsAfterLocValue(PRS_RElem arg, PRS_OptLayout wsAfterLocValue)
{
  if (PRS_isRElemLocation(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocValue), 5), 1);
  }

  ATabort("RElem has no WsAfterLocValue: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterSet(PRS_RElem arg, PRS_OptLayout wsAfterSet) */

PRS_RElem PRS_setRElemWsAfterSet(PRS_RElem arg, PRS_OptLayout wsAfterSet)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSet), 1), 1);
  }

  ATabort("RElem has no WsAfterSet: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterBracketOpen(PRS_RElem arg, PRS_OptLayout wsAfterBracketOpen) */

PRS_RElem PRS_setRElemWsAfterBracketOpen(PRS_RElem arg, PRS_OptLayout wsAfterBracketOpen)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }

  ATabort("RElem has no WsAfterBracketOpen: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemList(PRS_RElem arg, PRS_RElemList list) */

PRS_RElem PRS_setRElemList(PRS_RElem arg, PRS_RElemList list)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }
  else if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }

  ATabort("RElem has no List: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterList(PRS_RElem arg, PRS_OptLayout wsAfterList) */

PRS_RElem PRS_setRElemWsAfterList(PRS_RElem arg, PRS_OptLayout wsAfterList)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }
  else if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }

  ATabort("RElem has no WsAfterList: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterBracketClose(PRS_RElem arg, PRS_OptLayout wsAfterBracketClose) */

PRS_RElem PRS_setRElemWsAfterBracketClose(PRS_RElem arg, PRS_OptLayout wsAfterBracketClose)
{
  if (PRS_isRElemSet(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 9), 1);
  }
  else if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 9), 1);
  }
  else if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 9), 1);
  }

  ATabort("RElem has no WsAfterBracketClose: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterBag(PRS_RElem arg, PRS_OptLayout wsAfterBag) */

PRS_RElem PRS_setRElemWsAfterBag(PRS_RElem arg, PRS_OptLayout wsAfterBag)
{
  if (PRS_isRElemBag(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBag), 1), 1);
  }

  ATabort("RElem has no WsAfterBag: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_setRElemWsAfterTuple(PRS_RElem arg, PRS_OptLayout wsAfterTuple) */

PRS_RElem PRS_setRElemWsAfterTuple(PRS_RElem arg, PRS_OptLayout wsAfterTuple)
{
  if (PRS_isRElemTuple(arg)) {
    return (PRS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTuple), 1), 1);
  }

  ATabort("RElem has no WsAfterTuple: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_RType accessors */

/*{{{  ATbool PRS_isValidRType(PRS_RType arg) */

ATbool PRS_isValidRType(PRS_RType arg)
{
  if (PRS_isRTypeInteger(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeString(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeLocation(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRel(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeUser(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeInteger(PRS_RType arg) */

inline ATbool PRS_isRTypeInteger(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeInteger);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeString(PRS_RType arg) */

inline ATbool PRS_isRTypeString(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeString);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeLocation(PRS_RType arg) */

inline ATbool PRS_isRTypeLocation(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeLocation);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeTuple(PRS_RType arg) */

inline ATbool PRS_isRTypeTuple(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeTuple, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeSet(PRS_RType arg) */

inline ATbool PRS_isRTypeSet(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeSet, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeBag(PRS_RType arg) */

inline ATbool PRS_isRTypeBag(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeBag, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeRel(PRS_RType arg) */

inline ATbool PRS_isRTypeRel(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeRel, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeUser(PRS_RType arg) */

inline ATbool PRS_isRTypeUser(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeUser, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeParameter(PRS_RType arg) */

inline ATbool PRS_isRTypeParameter(PRS_RType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeParameter, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterTuple(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterTuple(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterParenOpen(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterParenOpen(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRel(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeUser(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterBracketOpen(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterBracketOpen(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeList(PRS_RType arg) */

ATbool PRS_hasRTypeList(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterList(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterList(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterBracketClose(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterBracketClose(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeRel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterSet(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterSet(PRS_RType arg)
{
  if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeRType(PRS_RType arg) */

ATbool PRS_hasRTypeRType(PRS_RType arg)
{
  if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterRType(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterRType(PRS_RType arg)
{
  if (PRS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterBag(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterBag(PRS_RType arg)
{
  if (PRS_isRTypeBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterRel(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterRel(PRS_RType arg)
{
  if (PRS_isRTypeRel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterUser(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterUser(PRS_RType arg)
{
  if (PRS_isRTypeUser(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeStrCon(PRS_RType arg) */

ATbool PRS_hasRTypeStrCon(PRS_RType arg)
{
  if (PRS_isRTypeUser(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterStrCon(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterStrCon(PRS_RType arg)
{
  if (PRS_isRTypeUser(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeWsAfterParameter(PRS_RType arg) */

ATbool PRS_hasRTypeWsAfterParameter(PRS_RType arg)
{
  if (PRS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterTuple(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterTuple(PRS_RType arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterParenOpen(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterParenOpen(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRTypeSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRTypeBag(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRTypeRel(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isRTypeUser(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterBracketOpen(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterBracketOpen(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_getRTypeList(PRS_RType arg) */

PRS_RTypeList PRS_getRTypeList(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RTypeList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else 
    return (PRS_RTypeList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterList(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterList(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterBracketClose(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterBracketClose(PRS_RType arg)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterSet(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterSet(PRS_RType arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_RType PRS_getRTypeRType(PRS_RType arg) */

PRS_RType PRS_getRTypeRType(PRS_RType arg)
{
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PRS_RType)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterRType(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterRType(PRS_RType arg)
{
  if (PRS_isRTypeSet(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterBag(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterBag(PRS_RType arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterRel(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterRel(PRS_RType arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterUser(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterUser(PRS_RType arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_StrCon PRS_getRTypeStrCon(PRS_RType arg) */

PRS_StrCon PRS_getRTypeStrCon(PRS_RType arg)
{
  if (PRS_isRTypeUser(arg)) {
    return (PRS_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PRS_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterStrCon(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterStrCon(PRS_RType arg)
{
  if (PRS_isRTypeUser(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeWsAfterParameter(PRS_RType arg) */

PRS_OptLayout PRS_getRTypeWsAfterParameter(PRS_RType arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterTuple(PRS_RType arg, PRS_OptLayout wsAfterTuple) */

PRS_RType PRS_setRTypeWsAfterTuple(PRS_RType arg, PRS_OptLayout wsAfterTuple)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTuple), 1), 1);
  }

  ATabort("RType has no WsAfterTuple: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterParenOpen(PRS_RType arg, PRS_OptLayout wsAfterParenOpen) */

PRS_RType PRS_setRTypeWsAfterParenOpen(PRS_RType arg, PRS_OptLayout wsAfterParenOpen)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRTypeBag(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRTypeRel(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRTypeUser(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isRTypeParameter(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("RType has no WsAfterParenOpen: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterBracketOpen(PRS_RType arg, PRS_OptLayout wsAfterBracketOpen) */

PRS_RType PRS_setRTypeWsAfterBracketOpen(PRS_RType arg, PRS_OptLayout wsAfterBracketOpen)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (PRS_isRTypeRel(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }

  ATabort("RType has no WsAfterBracketOpen: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeList(PRS_RType arg, PRS_RTypeList list) */

PRS_RType PRS_setRTypeList(PRS_RType arg, PRS_RTypeList list)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }
  else if (PRS_isRTypeRel(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }

  ATabort("RType has no List: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterList(PRS_RType arg, PRS_OptLayout wsAfterList) */

PRS_RType PRS_setRTypeWsAfterList(PRS_RType arg, PRS_OptLayout wsAfterList)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }
  else if (PRS_isRTypeRel(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }

  ATabort("RType has no WsAfterList: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterBracketClose(PRS_RType arg, PRS_OptLayout wsAfterBracketClose) */

PRS_RType PRS_setRTypeWsAfterBracketClose(PRS_RType arg, PRS_OptLayout wsAfterBracketClose)
{
  if (PRS_isRTypeTuple(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 9), 1);
  }
  else if (PRS_isRTypeRel(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 9), 1);
  }

  ATabort("RType has no WsAfterBracketClose: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterSet(PRS_RType arg, PRS_OptLayout wsAfterSet) */

PRS_RType PRS_setRTypeWsAfterSet(PRS_RType arg, PRS_OptLayout wsAfterSet)
{
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSet), 1), 1);
  }

  ATabort("RType has no WsAfterSet: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeRType(PRS_RType arg, PRS_RType RType) */

PRS_RType PRS_setRTypeRType(PRS_RType arg, PRS_RType RType)
{
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) RType), 4), 1);
  }
  else if (PRS_isRTypeBag(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) RType), 4), 1);
  }

  ATabort("RType has no RType: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterRType(PRS_RType arg, PRS_OptLayout wsAfterRType) */

PRS_RType PRS_setRTypeWsAfterRType(PRS_RType arg, PRS_OptLayout wsAfterRType)
{
  if (PRS_isRTypeSet(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRType), 5), 1);
  }
  else if (PRS_isRTypeBag(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRType), 5), 1);
  }

  ATabort("RType has no WsAfterRType: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterBag(PRS_RType arg, PRS_OptLayout wsAfterBag) */

PRS_RType PRS_setRTypeWsAfterBag(PRS_RType arg, PRS_OptLayout wsAfterBag)
{
  if (PRS_isRTypeBag(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBag), 1), 1);
  }

  ATabort("RType has no WsAfterBag: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterRel(PRS_RType arg, PRS_OptLayout wsAfterRel) */

PRS_RType PRS_setRTypeWsAfterRel(PRS_RType arg, PRS_OptLayout wsAfterRel)
{
  if (PRS_isRTypeRel(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRel), 1), 1);
  }

  ATabort("RType has no WsAfterRel: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterUser(PRS_RType arg, PRS_OptLayout wsAfterUser) */

PRS_RType PRS_setRTypeWsAfterUser(PRS_RType arg, PRS_OptLayout wsAfterUser)
{
  if (PRS_isRTypeUser(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterUser), 1), 1);
  }

  ATabort("RType has no WsAfterUser: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeStrCon(PRS_RType arg, PRS_StrCon StrCon) */

PRS_RType PRS_setRTypeStrCon(PRS_RType arg, PRS_StrCon StrCon)
{
  if (PRS_isRTypeUser(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 4), 1);
  }
  else if (PRS_isRTypeParameter(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 4), 1);
  }

  ATabort("RType has no StrCon: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterStrCon(PRS_RType arg, PRS_OptLayout wsAfterStrCon) */

PRS_RType PRS_setRTypeWsAfterStrCon(PRS_RType arg, PRS_OptLayout wsAfterStrCon)
{
  if (PRS_isRTypeUser(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStrCon), 5), 1);
  }
  else if (PRS_isRTypeParameter(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStrCon), 5), 1);
  }

  ATabort("RType has no WsAfterStrCon: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_setRTypeWsAfterParameter(PRS_RType arg, PRS_OptLayout wsAfterParameter) */

PRS_RType PRS_setRTypeWsAfterParameter(PRS_RType arg, PRS_OptLayout wsAfterParameter)
{
  if (PRS_isRTypeParameter(arg)) {
    return (PRS_RType)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParameter), 1), 1);
  }

  ATabort("RType has no WsAfterParameter: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_RTuple accessors */

/*{{{  ATbool PRS_isValidRTuple(PRS_RTuple arg) */

ATbool PRS_isValidRTuple(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTupleRtuple(PRS_RTuple arg) */

inline ATbool PRS_isRTupleRtuple(PRS_RTuple arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRTupleRtuple, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleWsAfterRtuple(PRS_RTuple arg) */

ATbool PRS_hasRTupleWsAfterRtuple(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleWsAfterParenOpen(PRS_RTuple arg) */

ATbool PRS_hasRTupleWsAfterParenOpen(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleId(PRS_RTuple arg) */

ATbool PRS_hasRTupleId(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleWsAfterId(PRS_RTuple arg) */

ATbool PRS_hasRTupleWsAfterId(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleWsAfterComma(PRS_RTuple arg) */

ATbool PRS_hasRTupleWsAfterComma(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleRtype(PRS_RTuple arg) */

ATbool PRS_hasRTupleRtype(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleWsAfterRtype(PRS_RTuple arg) */

ATbool PRS_hasRTupleWsAfterRtype(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleWsAfterComma1(PRS_RTuple arg) */

ATbool PRS_hasRTupleWsAfterComma1(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleData(PRS_RTuple arg) */

ATbool PRS_hasRTupleData(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleWsAfterData(PRS_RTuple arg) */

ATbool PRS_hasRTupleWsAfterData(PRS_RTuple arg)
{
  if (PRS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleWsAfterRtuple(PRS_RTuple arg) */

PRS_OptLayout PRS_getRTupleWsAfterRtuple(PRS_RTuple arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleWsAfterParenOpen(PRS_RTuple arg) */

PRS_OptLayout PRS_getRTupleWsAfterParenOpen(PRS_RTuple arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PRS_StrCon PRS_getRTupleId(PRS_RTuple arg) */

PRS_StrCon PRS_getRTupleId(PRS_RTuple arg)
{
  
    return (PRS_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleWsAfterId(PRS_RTuple arg) */

PRS_OptLayout PRS_getRTupleWsAfterId(PRS_RTuple arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleWsAfterComma(PRS_RTuple arg) */

PRS_OptLayout PRS_getRTupleWsAfterComma(PRS_RTuple arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PRS_RType PRS_getRTupleRtype(PRS_RTuple arg) */

PRS_RType PRS_getRTupleRtype(PRS_RTuple arg)
{
  
    return (PRS_RType)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleWsAfterRtype(PRS_RTuple arg) */

PRS_OptLayout PRS_getRTupleWsAfterRtype(PRS_RTuple arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleWsAfterComma1(PRS_RTuple arg) */

PRS_OptLayout PRS_getRTupleWsAfterComma1(PRS_RTuple arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PRS_RElem PRS_getRTupleData(PRS_RTuple arg) */

PRS_RElem PRS_getRTupleData(PRS_RTuple arg)
{
  
    return (PRS_RElem)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleWsAfterData(PRS_RTuple arg) */

PRS_OptLayout PRS_getRTupleWsAfterData(PRS_RTuple arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleWsAfterRtuple(PRS_RTuple arg, PRS_OptLayout wsAfterRtuple) */

PRS_RTuple PRS_setRTupleWsAfterRtuple(PRS_RTuple arg, PRS_OptLayout wsAfterRtuple)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRtuple), 1), 1);
  }

  ATabort("RTuple has no WsAfterRtuple: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleWsAfterParenOpen(PRS_RTuple arg, PRS_OptLayout wsAfterParenOpen) */

PRS_RTuple PRS_setRTupleWsAfterParenOpen(PRS_RTuple arg, PRS_OptLayout wsAfterParenOpen)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("RTuple has no WsAfterParenOpen: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleId(PRS_RTuple arg, PRS_StrCon id) */

PRS_RTuple PRS_setRTupleId(PRS_RTuple arg, PRS_StrCon id)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }

  ATabort("RTuple has no Id: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleWsAfterId(PRS_RTuple arg, PRS_OptLayout wsAfterId) */

PRS_RTuple PRS_setRTupleWsAfterId(PRS_RTuple arg, PRS_OptLayout wsAfterId)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }

  ATabort("RTuple has no WsAfterId: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleWsAfterComma(PRS_RTuple arg, PRS_OptLayout wsAfterComma) */

PRS_RTuple PRS_setRTupleWsAfterComma(PRS_RTuple arg, PRS_OptLayout wsAfterComma)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("RTuple has no WsAfterComma: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleRtype(PRS_RTuple arg, PRS_RType rtype) */

PRS_RTuple PRS_setRTupleRtype(PRS_RTuple arg, PRS_RType rtype)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rtype), 8), 1);
  }

  ATabort("RTuple has no Rtype: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleWsAfterRtype(PRS_RTuple arg, PRS_OptLayout wsAfterRtype) */

PRS_RTuple PRS_setRTupleWsAfterRtype(PRS_RTuple arg, PRS_OptLayout wsAfterRtype)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRtype), 9), 1);
  }

  ATabort("RTuple has no WsAfterRtype: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleWsAfterComma1(PRS_RTuple arg, PRS_OptLayout wsAfterComma1) */

PRS_RTuple PRS_setRTupleWsAfterComma1(PRS_RTuple arg, PRS_OptLayout wsAfterComma1)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("RTuple has no WsAfterComma1: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleData(PRS_RTuple arg, PRS_RElem data) */

PRS_RTuple PRS_setRTupleData(PRS_RTuple arg, PRS_RElem data)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) data), 12), 1);
  }

  ATabort("RTuple has no Data: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_setRTupleWsAfterData(PRS_RTuple arg, PRS_OptLayout wsAfterData) */

PRS_RTuple PRS_setRTupleWsAfterData(PRS_RTuple arg, PRS_OptLayout wsAfterData)
{
  if (PRS_isRTupleRtuple(arg)) {
    return (PRS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterData), 13), 1);
  }

  ATabort("RTuple has no WsAfterData: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_RStore accessors */

/*{{{  ATbool PRS_isValidRStore(PRS_RStore arg) */

ATbool PRS_isValidRStore(PRS_RStore arg)
{
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRStoreRstore(PRS_RStore arg) */

inline ATbool PRS_isRStoreRstore(PRS_RStore arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRStoreRstore, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasRStoreWsAfterRstore(PRS_RStore arg) */

ATbool PRS_hasRStoreWsAfterRstore(PRS_RStore arg)
{
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRStoreWsAfterParenOpen(PRS_RStore arg) */

ATbool PRS_hasRStoreWsAfterParenOpen(PRS_RStore arg)
{
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRStoreWsAfterBracketOpen(PRS_RStore arg) */

ATbool PRS_hasRStoreWsAfterBracketOpen(PRS_RStore arg)
{
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRStoreList(PRS_RStore arg) */

ATbool PRS_hasRStoreList(PRS_RStore arg)
{
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRStoreWsAfterList(PRS_RStore arg) */

ATbool PRS_hasRStoreWsAfterList(PRS_RStore arg)
{
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRStoreWsAfterBracketClose(PRS_RStore arg) */

ATbool PRS_hasRStoreWsAfterBracketClose(PRS_RStore arg)
{
  if (PRS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRStoreWsAfterRstore(PRS_RStore arg) */

PRS_OptLayout PRS_getRStoreWsAfterRstore(PRS_RStore arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRStoreWsAfterParenOpen(PRS_RStore arg) */

PRS_OptLayout PRS_getRStoreWsAfterParenOpen(PRS_RStore arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRStoreWsAfterBracketOpen(PRS_RStore arg) */

PRS_OptLayout PRS_getRStoreWsAfterBracketOpen(PRS_RStore arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_getRStoreList(PRS_RStore arg) */

PRS_RTupleList PRS_getRStoreList(PRS_RStore arg)
{
  
    return (PRS_RTupleList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRStoreWsAfterList(PRS_RStore arg) */

PRS_OptLayout PRS_getRStoreWsAfterList(PRS_RStore arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRStoreWsAfterBracketClose(PRS_RStore arg) */

PRS_OptLayout PRS_getRStoreWsAfterBracketClose(PRS_RStore arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PRS_RStore PRS_setRStoreWsAfterRstore(PRS_RStore arg, PRS_OptLayout wsAfterRstore) */

PRS_RStore PRS_setRStoreWsAfterRstore(PRS_RStore arg, PRS_OptLayout wsAfterRstore)
{
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRstore), 1), 1);
  }

  ATabort("RStore has no WsAfterRstore: %t\n", arg);
  return (PRS_RStore)NULL;
}

/*}}}  */
/*{{{  PRS_RStore PRS_setRStoreWsAfterParenOpen(PRS_RStore arg, PRS_OptLayout wsAfterParenOpen) */

PRS_RStore PRS_setRStoreWsAfterParenOpen(PRS_RStore arg, PRS_OptLayout wsAfterParenOpen)
{
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("RStore has no WsAfterParenOpen: %t\n", arg);
  return (PRS_RStore)NULL;
}

/*}}}  */
/*{{{  PRS_RStore PRS_setRStoreWsAfterBracketOpen(PRS_RStore arg, PRS_OptLayout wsAfterBracketOpen) */

PRS_RStore PRS_setRStoreWsAfterBracketOpen(PRS_RStore arg, PRS_OptLayout wsAfterBracketOpen)
{
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }

  ATabort("RStore has no WsAfterBracketOpen: %t\n", arg);
  return (PRS_RStore)NULL;
}

/*}}}  */
/*{{{  PRS_RStore PRS_setRStoreList(PRS_RStore arg, PRS_RTupleList list) */

PRS_RStore PRS_setRStoreList(PRS_RStore arg, PRS_RTupleList list)
{
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }

  ATabort("RStore has no List: %t\n", arg);
  return (PRS_RStore)NULL;
}

/*}}}  */
/*{{{  PRS_RStore PRS_setRStoreWsAfterList(PRS_RStore arg, PRS_OptLayout wsAfterList) */

PRS_RStore PRS_setRStoreWsAfterList(PRS_RStore arg, PRS_OptLayout wsAfterList)
{
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }

  ATabort("RStore has no WsAfterList: %t\n", arg);
  return (PRS_RStore)NULL;
}

/*}}}  */
/*{{{  PRS_RStore PRS_setRStoreWsAfterBracketClose(PRS_RStore arg, PRS_OptLayout wsAfterBracketClose) */

PRS_RStore PRS_setRStoreWsAfterBracketClose(PRS_RStore arg, PRS_OptLayout wsAfterBracketClose)
{
  if (PRS_isRStoreRstore(arg)) {
    return (PRS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 9), 1);
  }

  ATabort("RStore has no WsAfterBracketClose: %t\n", arg);
  return (PRS_RStore)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_Start accessors */

/*{{{  ATbool PRS_isValidStart(PRS_Start arg) */

ATbool PRS_isValidStart(PRS_Start arg)
{
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isStartRStore(PRS_Start arg) */

inline ATbool PRS_isStartRStore(PRS_Start arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternStartRStore, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasStartWsBefore(PRS_Start arg) */

ATbool PRS_hasStartWsBefore(PRS_Start arg)
{
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasStartTopRStore(PRS_Start arg) */

ATbool PRS_hasStartTopRStore(PRS_Start arg)
{
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasStartWsAfter(PRS_Start arg) */

ATbool PRS_hasStartWsAfter(PRS_Start arg)
{
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasStartAmbCnt(PRS_Start arg) */

ATbool PRS_hasStartAmbCnt(PRS_Start arg)
{
  if (PRS_isStartRStore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getStartWsBefore(PRS_Start arg) */

PRS_OptLayout PRS_getStartWsBefore(PRS_Start arg)
{
  
    return (PRS_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  PRS_RStore PRS_getStartTopRStore(PRS_Start arg) */

PRS_RStore PRS_getStartTopRStore(PRS_Start arg)
{
  
    return (PRS_RStore)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getStartWsAfter(PRS_Start arg) */

PRS_OptLayout PRS_getStartWsAfter(PRS_Start arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  int PRS_getStartAmbCnt(PRS_Start arg) */

int PRS_getStartAmbCnt(PRS_Start arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PRS_Start PRS_setStartWsBefore(PRS_Start arg, PRS_OptLayout wsBefore) */

PRS_Start PRS_setStartWsBefore(PRS_Start arg, PRS_OptLayout wsBefore)
{
  if (PRS_isStartRStore(arg)) {
    return (PRS_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (PRS_Start)NULL;
}

/*}}}  */
/*{{{  PRS_Start PRS_setStartTopRStore(PRS_Start arg, PRS_RStore topRStore) */

PRS_Start PRS_setStartTopRStore(PRS_Start arg, PRS_RStore topRStore)
{
  if (PRS_isStartRStore(arg)) {
    return (PRS_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topRStore), 1), 1), 0);
  }

  ATabort("Start has no TopRStore: %t\n", arg);
  return (PRS_Start)NULL;
}

/*}}}  */
/*{{{  PRS_Start PRS_setStartWsAfter(PRS_Start arg, PRS_OptLayout wsAfter) */

PRS_Start PRS_setStartWsAfter(PRS_Start arg, PRS_OptLayout wsAfter)
{
  if (PRS_isStartRStore(arg)) {
    return (PRS_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (PRS_Start)NULL;
}

/*}}}  */
/*{{{  PRS_Start PRS_setStartAmbCnt(PRS_Start arg, int ambCnt) */

PRS_Start PRS_setStartAmbCnt(PRS_Start arg, int ambCnt)
{
  if (PRS_isStartRStore(arg)) {
    return (PRS_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (PRS_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_RElemList accessors */

/*{{{  ATbool PRS_isValidRElemList(PRS_RElemList arg) */

ATbool PRS_isValidRElemList(PRS_RElemList arg)
{
  if (PRS_isRElemListEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemListEmpty(PRS_RElemList arg) */

inline ATbool PRS_isRElemListEmpty(PRS_RElemList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRElemListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemListSingle(PRS_RElemList arg) */

inline ATbool PRS_isRElemListSingle(PRS_RElemList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRElemListMany(PRS_RElemList arg) */

inline ATbool PRS_isRElemListMany(PRS_RElemList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRElemListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemListHead(PRS_RElemList arg) */

ATbool PRS_hasRElemListHead(PRS_RElemList arg)
{
  if (PRS_isRElemListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRElemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemListWsAfterHead(PRS_RElemList arg) */

ATbool PRS_hasRElemListWsAfterHead(PRS_RElemList arg)
{
  if (PRS_isRElemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemListWsAfterSep(PRS_RElemList arg) */

ATbool PRS_hasRElemListWsAfterSep(PRS_RElemList arg)
{
  if (PRS_isRElemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRElemListTail(PRS_RElemList arg) */

ATbool PRS_hasRElemListTail(PRS_RElemList arg)
{
  if (PRS_isRElemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_RElemList PRS_getRElemListTail(PRS_RElemList arg) */

PRS_RElemList PRS_getRElemListTail(PRS_RElemList arg)
{
  assert(!PRS_isRElemListEmpty(arg) && "getTail on an empty list");
  if (PRS_isRElemListSingle(arg)) {
    return (PRS_RElemList) PRS_makeRElemListEmpty();
  }
  else {
  
    return (PRS_RElemList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PRS_RElem PRS_getRElemListHead(PRS_RElemList arg) */

PRS_RElem PRS_getRElemListHead(PRS_RElemList arg)
{
  if (PRS_isRElemListSingle(arg)) {
    return (PRS_RElem)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_RElem)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemListWsAfterHead(PRS_RElemList arg) */

PRS_OptLayout PRS_getRElemListWsAfterHead(PRS_RElemList arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRElemListWsAfterSep(PRS_RElemList arg) */

PRS_OptLayout PRS_getRElemListWsAfterSep(PRS_RElemList arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PRS_RElemList PRS_setRElemListHead(PRS_RElemList arg, PRS_RElem head) */

PRS_RElemList PRS_setRElemListHead(PRS_RElemList arg, PRS_RElem head)
{
  if (PRS_isRElemListSingle(arg)) {
    return (PRS_RElemList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isRElemListMany(arg)) {
    return (PRS_RElemList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RElemList has no Head: %t\n", arg);
  return (PRS_RElemList)NULL;
}

/*}}}  */
/*{{{  PRS_RElemList PRS_setRElemListWsAfterHead(PRS_RElemList arg, PRS_OptLayout wsAfterHead) */

PRS_RElemList PRS_setRElemListWsAfterHead(PRS_RElemList arg, PRS_OptLayout wsAfterHead)
{
  if (PRS_isRElemListMany(arg)) {
    return (PRS_RElemList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("RElemList has no WsAfterHead: %t\n", arg);
  return (PRS_RElemList)NULL;
}

/*}}}  */
/*{{{  PRS_RElemList PRS_setRElemListWsAfterSep(PRS_RElemList arg, PRS_OptLayout wsAfterSep) */

PRS_RElemList PRS_setRElemListWsAfterSep(PRS_RElemList arg, PRS_OptLayout wsAfterSep)
{
  if (PRS_isRElemListMany(arg)) {
    return (PRS_RElemList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("RElemList has no WsAfterSep: %t\n", arg);
  return (PRS_RElemList)NULL;
}

/*}}}  */
/*{{{  PRS_RElemList PRS_setRElemListTail(PRS_RElemList arg, PRS_RElemList tail) */

PRS_RElemList PRS_setRElemListTail(PRS_RElemList arg, PRS_RElemList tail)
{
  if (PRS_isRElemListMany(arg)) {
    return (PRS_RElemList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("RElemList has no Tail: %t\n", arg);
  return (PRS_RElemList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_RTypeList accessors */

/*{{{  ATbool PRS_isValidRTypeList(PRS_RTypeList arg) */

ATbool PRS_isValidRTypeList(PRS_RTypeList arg)
{
  if (PRS_isRTypeListEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeListEmpty(PRS_RTypeList arg) */

inline ATbool PRS_isRTypeListEmpty(PRS_RTypeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRTypeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeListSingle(PRS_RTypeList arg) */

inline ATbool PRS_isRTypeListSingle(PRS_RTypeList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTypeListMany(PRS_RTypeList arg) */

inline ATbool PRS_isRTypeListMany(PRS_RTypeList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTypeListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeListHead(PRS_RTypeList arg) */

ATbool PRS_hasRTypeListHead(PRS_RTypeList arg)
{
  if (PRS_isRTypeListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeListWsAfterHead(PRS_RTypeList arg) */

ATbool PRS_hasRTypeListWsAfterHead(PRS_RTypeList arg)
{
  if (PRS_isRTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeListWsAfterSep(PRS_RTypeList arg) */

ATbool PRS_hasRTypeListWsAfterSep(PRS_RTypeList arg)
{
  if (PRS_isRTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTypeListTail(PRS_RTypeList arg) */

ATbool PRS_hasRTypeListTail(PRS_RTypeList arg)
{
  if (PRS_isRTypeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_getRTypeListTail(PRS_RTypeList arg) */

PRS_RTypeList PRS_getRTypeListTail(PRS_RTypeList arg)
{
  assert(!PRS_isRTypeListEmpty(arg) && "getTail on an empty list");
  if (PRS_isRTypeListSingle(arg)) {
    return (PRS_RTypeList) PRS_makeRTypeListEmpty();
  }
  else {
  
    return (PRS_RTypeList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PRS_RType PRS_getRTypeListHead(PRS_RTypeList arg) */

PRS_RType PRS_getRTypeListHead(PRS_RTypeList arg)
{
  if (PRS_isRTypeListSingle(arg)) {
    return (PRS_RType)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_RType)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeListWsAfterHead(PRS_RTypeList arg) */

PRS_OptLayout PRS_getRTypeListWsAfterHead(PRS_RTypeList arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTypeListWsAfterSep(PRS_RTypeList arg) */

PRS_OptLayout PRS_getRTypeListWsAfterSep(PRS_RTypeList arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_setRTypeListHead(PRS_RTypeList arg, PRS_RType head) */

PRS_RTypeList PRS_setRTypeListHead(PRS_RTypeList arg, PRS_RType head)
{
  if (PRS_isRTypeListSingle(arg)) {
    return (PRS_RTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isRTypeListMany(arg)) {
    return (PRS_RTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RTypeList has no Head: %t\n", arg);
  return (PRS_RTypeList)NULL;
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_setRTypeListWsAfterHead(PRS_RTypeList arg, PRS_OptLayout wsAfterHead) */

PRS_RTypeList PRS_setRTypeListWsAfterHead(PRS_RTypeList arg, PRS_OptLayout wsAfterHead)
{
  if (PRS_isRTypeListMany(arg)) {
    return (PRS_RTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("RTypeList has no WsAfterHead: %t\n", arg);
  return (PRS_RTypeList)NULL;
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_setRTypeListWsAfterSep(PRS_RTypeList arg, PRS_OptLayout wsAfterSep) */

PRS_RTypeList PRS_setRTypeListWsAfterSep(PRS_RTypeList arg, PRS_OptLayout wsAfterSep)
{
  if (PRS_isRTypeListMany(arg)) {
    return (PRS_RTypeList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("RTypeList has no WsAfterSep: %t\n", arg);
  return (PRS_RTypeList)NULL;
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_setRTypeListTail(PRS_RTypeList arg, PRS_RTypeList tail) */

PRS_RTypeList PRS_setRTypeListTail(PRS_RTypeList arg, PRS_RTypeList tail)
{
  if (PRS_isRTypeListMany(arg)) {
    return (PRS_RTypeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("RTypeList has no Tail: %t\n", arg);
  return (PRS_RTypeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_RTupleList accessors */

/*{{{  ATbool PRS_isValidRTupleList(PRS_RTupleList arg) */

ATbool PRS_isValidRTupleList(PRS_RTupleList arg)
{
  if (PRS_isRTupleListEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTupleListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTupleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTupleListEmpty(PRS_RTupleList arg) */

inline ATbool PRS_isRTupleListEmpty(PRS_RTupleList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternRTupleListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTupleListSingle(PRS_RTupleList arg) */

inline ATbool PRS_isRTupleListSingle(PRS_RTupleList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTupleListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isRTupleListMany(PRS_RTupleList arg) */

inline ATbool PRS_isRTupleListMany(PRS_RTupleList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternRTupleListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleListHead(PRS_RTupleList arg) */

ATbool PRS_hasRTupleListHead(PRS_RTupleList arg)
{
  if (PRS_isRTupleListSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isRTupleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleListWsAfterHead(PRS_RTupleList arg) */

ATbool PRS_hasRTupleListWsAfterHead(PRS_RTupleList arg)
{
  if (PRS_isRTupleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleListWsAfterSep(PRS_RTupleList arg) */

ATbool PRS_hasRTupleListWsAfterSep(PRS_RTupleList arg)
{
  if (PRS_isRTupleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasRTupleListTail(PRS_RTupleList arg) */

ATbool PRS_hasRTupleListTail(PRS_RTupleList arg)
{
  if (PRS_isRTupleListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_getRTupleListTail(PRS_RTupleList arg) */

PRS_RTupleList PRS_getRTupleListTail(PRS_RTupleList arg)
{
  assert(!PRS_isRTupleListEmpty(arg) && "getTail on an empty list");
  if (PRS_isRTupleListSingle(arg)) {
    return (PRS_RTupleList) PRS_makeRTupleListEmpty();
  }
  else {
  
    return (PRS_RTupleList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PRS_RTuple PRS_getRTupleListHead(PRS_RTupleList arg) */

PRS_RTuple PRS_getRTupleListHead(PRS_RTupleList arg)
{
  if (PRS_isRTupleListSingle(arg)) {
    return (PRS_RTuple)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_RTuple)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleListWsAfterHead(PRS_RTupleList arg) */

PRS_OptLayout PRS_getRTupleListWsAfterHead(PRS_RTupleList arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getRTupleListWsAfterSep(PRS_RTupleList arg) */

PRS_OptLayout PRS_getRTupleListWsAfterSep(PRS_RTupleList arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_setRTupleListHead(PRS_RTupleList arg, PRS_RTuple head) */

PRS_RTupleList PRS_setRTupleListHead(PRS_RTupleList arg, PRS_RTuple head)
{
  if (PRS_isRTupleListSingle(arg)) {
    return (PRS_RTupleList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isRTupleListMany(arg)) {
    return (PRS_RTupleList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RTupleList has no Head: %t\n", arg);
  return (PRS_RTupleList)NULL;
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_setRTupleListWsAfterHead(PRS_RTupleList arg, PRS_OptLayout wsAfterHead) */

PRS_RTupleList PRS_setRTupleListWsAfterHead(PRS_RTupleList arg, PRS_OptLayout wsAfterHead)
{
  if (PRS_isRTupleListMany(arg)) {
    return (PRS_RTupleList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("RTupleList has no WsAfterHead: %t\n", arg);
  return (PRS_RTupleList)NULL;
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_setRTupleListWsAfterSep(PRS_RTupleList arg, PRS_OptLayout wsAfterSep) */

PRS_RTupleList PRS_setRTupleListWsAfterSep(PRS_RTupleList arg, PRS_OptLayout wsAfterSep)
{
  if (PRS_isRTupleListMany(arg)) {
    return (PRS_RTupleList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("RTupleList has no WsAfterSep: %t\n", arg);
  return (PRS_RTupleList)NULL;
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_setRTupleListTail(PRS_RTupleList arg, PRS_RTupleList tail) */

PRS_RTupleList PRS_setRTupleListTail(PRS_RTupleList arg, PRS_RTupleList tail)
{
  if (PRS_isRTupleListMany(arg)) {
    return (PRS_RTupleList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("RTupleList has no Tail: %t\n", arg);
  return (PRS_RTupleList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_LexStrChar accessors */

/*{{{  ATbool PRS_isValidLexStrChar(PRS_LexStrChar arg) */

ATbool PRS_isValidLexStrChar(PRS_LexStrChar arg)
{
  if (PRS_isLexStrCharNewline(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharTab(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharQuote(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharBackslash(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharNewline(PRS_LexStrChar arg) */

inline ATbool PRS_isLexStrCharNewline(PRS_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharNewline);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharTab(PRS_LexStrChar arg) */

inline ATbool PRS_isLexStrCharTab(PRS_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharTab);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharQuote(PRS_LexStrChar arg) */

inline ATbool PRS_isLexStrCharQuote(PRS_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharQuote);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharBackslash(PRS_LexStrChar arg) */

inline ATbool PRS_isLexStrCharBackslash(PRS_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharBackslash);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharDecimal(PRS_LexStrChar arg) */

inline ATbool PRS_isLexStrCharDecimal(PRS_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharDecimal, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharNormal(PRS_LexStrChar arg) */

inline ATbool PRS_isLexStrCharNormal(PRS_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharNormal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasLexStrCharA(PRS_LexStrChar arg) */

ATbool PRS_hasLexStrCharA(PRS_LexStrChar arg)
{
  if (PRS_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLexStrCharB(PRS_LexStrChar arg) */

ATbool PRS_hasLexStrCharB(PRS_LexStrChar arg)
{
  if (PRS_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLexStrCharC(PRS_LexStrChar arg) */

ATbool PRS_hasLexStrCharC(PRS_LexStrChar arg)
{
  if (PRS_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLexStrCharCh(PRS_LexStrChar arg) */

ATbool PRS_hasLexStrCharCh(PRS_LexStrChar arg)
{
  if (PRS_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char PRS_getLexStrCharA(PRS_LexStrChar arg) */

char PRS_getLexStrCharA(PRS_LexStrChar arg)
{
  
    return (char)PRS_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1));
}

/*}}}  */
/*{{{  char PRS_getLexStrCharB(PRS_LexStrChar arg) */

char PRS_getLexStrCharB(PRS_LexStrChar arg)
{
  
    return (char)PRS_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2));
}

/*}}}  */
/*{{{  char PRS_getLexStrCharC(PRS_LexStrChar arg) */

char PRS_getLexStrCharC(PRS_LexStrChar arg)
{
  
    return (char)PRS_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3));
}

/*}}}  */
/*{{{  char PRS_getLexStrCharCh(PRS_LexStrChar arg) */

char PRS_getLexStrCharCh(PRS_LexStrChar arg)
{
  
    return (char)PRS_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_setLexStrCharA(PRS_LexStrChar arg, char a) */

PRS_LexStrChar PRS_setLexStrCharA(PRS_LexStrChar arg, char a)
{
  if (PRS_isLexStrCharDecimal(arg)) {
    return (PRS_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(a))), 1), 1);
  }

  ATabort("LexStrChar has no A: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_setLexStrCharB(PRS_LexStrChar arg, char b) */

PRS_LexStrChar PRS_setLexStrCharB(PRS_LexStrChar arg, char b)
{
  if (PRS_isLexStrCharDecimal(arg)) {
    return (PRS_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(b))), 2), 1);
  }

  ATabort("LexStrChar has no B: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_setLexStrCharC(PRS_LexStrChar arg, char c) */

PRS_LexStrChar PRS_setLexStrCharC(PRS_LexStrChar arg, char c)
{
  if (PRS_isLexStrCharDecimal(arg)) {
    return (PRS_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(c))), 3), 1);
  }

  ATabort("LexStrChar has no C: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_setLexStrCharCh(PRS_LexStrChar arg, char ch) */

PRS_LexStrChar PRS_setLexStrCharCh(PRS_LexStrChar arg, char ch)
{
  if (PRS_isLexStrCharNormal(arg)) {
    return (PRS_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(ch))), 0), 1);
  }

  ATabort("LexStrChar has no Ch: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_StrChar accessors */

/*{{{  ATbool PRS_isValidStrChar(PRS_StrChar arg) */

ATbool PRS_isValidStrChar(PRS_StrChar arg)
{
  if (PRS_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isStrCharLexToCf(PRS_StrChar arg) */

inline ATbool PRS_isStrCharLexToCf(PRS_StrChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternStrCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasStrCharStrChar(PRS_StrChar arg) */

ATbool PRS_hasStrCharStrChar(PRS_StrChar arg)
{
  if (PRS_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_getStrCharStrChar(PRS_StrChar arg) */

PRS_LexStrChar PRS_getStrCharStrChar(PRS_StrChar arg)
{
  
    return (PRS_LexStrChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PRS_StrChar PRS_setStrCharStrChar(PRS_StrChar arg, PRS_LexStrChar StrChar) */

PRS_StrChar PRS_setStrCharStrChar(PRS_StrChar arg, PRS_LexStrChar StrChar)
{
  if (PRS_isStrCharLexToCf(arg)) {
    return (PRS_StrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrChar), 0), 1);
  }

  ATabort("StrChar has no StrChar: %t\n", arg);
  return (PRS_StrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_LexStrCon accessors */

/*{{{  ATbool PRS_isValidLexStrCon(PRS_LexStrCon arg) */

ATbool PRS_isValidLexStrCon(PRS_LexStrCon arg)
{
  if (PRS_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrConDefault(PRS_LexStrCon arg) */

inline ATbool PRS_isLexStrConDefault(PRS_LexStrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexStrConDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasLexStrConChars(PRS_LexStrCon arg) */

ATbool PRS_hasLexStrConChars(PRS_LexStrCon arg)
{
  if (PRS_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_getLexStrConChars(PRS_LexStrCon arg) */

PRS_LexStrCharChars PRS_getLexStrConChars(PRS_LexStrCon arg)
{
  
    return (PRS_LexStrCharChars)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1);
}

/*}}}  */
/*{{{  PRS_LexStrCon PRS_setLexStrConChars(PRS_LexStrCon arg, PRS_LexStrCharChars chars) */

PRS_LexStrCon PRS_setLexStrConChars(PRS_LexStrCon arg, PRS_LexStrCharChars chars)
{
  if (PRS_isLexStrConDefault(arg)) {
    return (PRS_LexStrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) chars), 1), 1), 1);
  }

  ATabort("LexStrCon has no Chars: %t\n", arg);
  return (PRS_LexStrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_StrCon accessors */

/*{{{  ATbool PRS_isValidStrCon(PRS_StrCon arg) */

ATbool PRS_isValidStrCon(PRS_StrCon arg)
{
  if (PRS_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isStrConLexToCf(PRS_StrCon arg) */

inline ATbool PRS_isStrConLexToCf(PRS_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternStrConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasStrConStrCon(PRS_StrCon arg) */

ATbool PRS_hasStrConStrCon(PRS_StrCon arg)
{
  if (PRS_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_LexStrCon PRS_getStrConStrCon(PRS_StrCon arg) */

PRS_LexStrCon PRS_getStrConStrCon(PRS_StrCon arg)
{
  
    return (PRS_LexStrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PRS_StrCon PRS_setStrConStrCon(PRS_StrCon arg, PRS_LexStrCon StrCon) */

PRS_StrCon PRS_setStrConStrCon(PRS_StrCon arg, PRS_LexStrCon StrCon)
{
  if (PRS_isStrConLexToCf(arg)) {
    return (PRS_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("StrCon has no StrCon: %t\n", arg);
  return (PRS_StrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_LexStrCharChars accessors */

/*{{{  ATbool PRS_isValidLexStrCharChars(PRS_LexStrCharChars arg) */

ATbool PRS_isValidLexStrCharChars(PRS_LexStrCharChars arg)
{
  if (PRS_isLexStrCharCharsEmpty(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharCharsEmpty(PRS_LexStrCharChars arg) */

inline ATbool PRS_isLexStrCharCharsEmpty(PRS_LexStrCharChars arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexStrCharCharsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharCharsSingle(PRS_LexStrCharChars arg) */

inline ATbool PRS_isLexStrCharCharsSingle(PRS_LexStrCharChars arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharCharsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexStrCharCharsMany(PRS_LexStrCharChars arg) */

inline ATbool PRS_isLexStrCharCharsMany(PRS_LexStrCharChars arg)
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
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLexStrCharCharsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasLexStrCharCharsHead(PRS_LexStrCharChars arg) */

ATbool PRS_hasLexStrCharCharsHead(PRS_LexStrCharChars arg)
{
  if (PRS_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (PRS_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLexStrCharCharsTail(PRS_LexStrCharChars arg) */

ATbool PRS_hasLexStrCharCharsTail(PRS_LexStrCharChars arg)
{
  if (PRS_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_getLexStrCharCharsHead(PRS_LexStrCharChars arg) */

PRS_LexStrChar PRS_getLexStrCharCharsHead(PRS_LexStrCharChars arg)
{
  if (PRS_isLexStrCharCharsSingle(arg)) {
    return (PRS_LexStrChar)ATgetFirst((ATermList)arg);
  }
  else 
    return (PRS_LexStrChar)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_getLexStrCharCharsTail(PRS_LexStrCharChars arg) */

PRS_LexStrCharChars PRS_getLexStrCharCharsTail(PRS_LexStrCharChars arg)
{
  
    return (PRS_LexStrCharChars)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_setLexStrCharCharsHead(PRS_LexStrCharChars arg, PRS_LexStrChar head) */

PRS_LexStrCharChars PRS_setLexStrCharCharsHead(PRS_LexStrCharChars arg, PRS_LexStrChar head)
{
  if (PRS_isLexStrCharCharsSingle(arg)) {
    return (PRS_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PRS_isLexStrCharCharsMany(arg)) {
    return (PRS_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexStrCharChars has no Head: %t\n", arg);
  return (PRS_LexStrCharChars)NULL;
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_setLexStrCharCharsTail(PRS_LexStrCharChars arg, PRS_LexStrCharChars tail) */

PRS_LexStrCharChars PRS_setLexStrCharCharsTail(PRS_LexStrCharChars arg, PRS_LexStrCharChars tail)
{
  if (PRS_isLexStrCharCharsMany(arg)) {
    return (PRS_LexStrCharChars)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexStrCharChars has no Tail: %t\n", arg);
  return (PRS_LexStrCharChars)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_LexNatCon accessors */

/*{{{  ATbool PRS_isValidLexNatCon(PRS_LexNatCon arg) */

ATbool PRS_isValidLexNatCon(PRS_LexNatCon arg)
{
  if (PRS_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexNatConDigits(PRS_LexNatCon arg) */

inline ATbool PRS_isLexNatConDigits(PRS_LexNatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexNatConDigits, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasLexNatConList(PRS_LexNatCon arg) */

ATbool PRS_hasLexNatConList(PRS_LexNatCon arg)
{
  if (PRS_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PRS_getLexNatConList(PRS_LexNatCon arg) */

char* PRS_getLexNatConList(PRS_LexNatCon arg)
{
  
    return (char*)PRS_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  PRS_LexNatCon PRS_setLexNatConList(PRS_LexNatCon arg, const char* list) */

PRS_LexNatCon PRS_setLexNatConList(PRS_LexNatCon arg, const char* list)
{
  if (PRS_isLexNatConDigits(arg)) {
    return (PRS_LexNatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) PRS_stringToChars(list))), 1), 0), 1);
  }

  ATabort("LexNatCon has no List: %t\n", arg);
  return (PRS_LexNatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_NatCon accessors */

/*{{{  ATbool PRS_isValidNatCon(PRS_NatCon arg) */

ATbool PRS_isValidNatCon(PRS_NatCon arg)
{
  if (PRS_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isNatConLexToCf(PRS_NatCon arg) */

inline ATbool PRS_isNatConLexToCf(PRS_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternNatConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasNatConNatCon(PRS_NatCon arg) */

ATbool PRS_hasNatConNatCon(PRS_NatCon arg)
{
  if (PRS_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_LexNatCon PRS_getNatConNatCon(PRS_NatCon arg) */

PRS_LexNatCon PRS_getNatConNatCon(PRS_NatCon arg)
{
  
    return (PRS_LexNatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PRS_NatCon PRS_setNatConNatCon(PRS_NatCon arg, PRS_LexNatCon NatCon) */

PRS_NatCon PRS_setNatConNatCon(PRS_NatCon arg, PRS_LexNatCon NatCon)
{
  if (PRS_isNatConLexToCf(arg)) {
    return (PRS_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("NatCon has no NatCon: %t\n", arg);
  return (PRS_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_LexLayout accessors */

/*{{{  ATbool PRS_isValidLexLayout(PRS_LexLayout arg) */

ATbool PRS_isValidLexLayout(PRS_LexLayout arg)
{
  if (PRS_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLexLayoutWhitespace(PRS_LexLayout arg) */

inline ATbool PRS_isLexLayoutWhitespace(PRS_LexLayout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternLexLayoutWhitespace, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasLexLayoutCh(PRS_LexLayout arg) */

ATbool PRS_hasLexLayoutCh(PRS_LexLayout arg)
{
  if (PRS_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char PRS_getLexLayoutCh(PRS_LexLayout arg) */

char PRS_getLexLayoutCh(PRS_LexLayout arg)
{
  
    return (char)PRS_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  PRS_LexLayout PRS_setLexLayoutCh(PRS_LexLayout arg, char ch) */

PRS_LexLayout PRS_setLexLayoutCh(PRS_LexLayout arg, char ch)
{
  if (PRS_isLexLayoutWhitespace(arg)) {
    return (PRS_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PRS_byteToChar(ch))), 0), 1);
  }

  ATabort("LexLayout has no Ch: %t\n", arg);
  return (PRS_LexLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_Location accessors */

/*{{{  ATbool PRS_isValidLocation(PRS_Location arg) */

ATbool PRS_isValidLocation(PRS_Location arg)
{
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isLocationFile(PRS_Location arg) */

inline ATbool PRS_isLocationFile(PRS_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLocationFile, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLocationArea(PRS_Location arg) */

inline ATbool PRS_isLocationArea(PRS_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLocationArea, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PRS_isLocationAreaInFile(PRS_Location arg) */

inline ATbool PRS_isLocationAreaInFile(PRS_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PRS_patternLocationAreaInFile, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationWsAfterFile(PRS_Location arg) */

ATbool PRS_hasLocationWsAfterFile(PRS_Location arg)
{
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationWsAfterParenOpen(PRS_Location arg) */

ATbool PRS_hasLocationWsAfterParenOpen(PRS_Location arg)
{
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationFilename(PRS_Location arg) */

ATbool PRS_hasLocationFilename(PRS_Location arg)
{
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationWsAfterFilename(PRS_Location arg) */

ATbool PRS_hasLocationWsAfterFilename(PRS_Location arg)
{
  if (PRS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationWsAfterA(PRS_Location arg) */

ATbool PRS_hasLocationWsAfterA(PRS_Location arg)
{
  if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationArea(PRS_Location arg) */

ATbool PRS_hasLocationArea(PRS_Location arg)
{
  if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationWsAfterArea(PRS_Location arg) */

ATbool PRS_hasLocationWsAfterArea(PRS_Location arg)
{
  if (PRS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationWsAfterAreaInFile(PRS_Location arg) */

ATbool PRS_hasLocationWsAfterAreaInFile(PRS_Location arg)
{
  if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasLocationWsAfterComma(PRS_Location arg) */

ATbool PRS_hasLocationWsAfterComma(PRS_Location arg)
{
  if (PRS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getLocationWsAfterFile(PRS_Location arg) */

PRS_OptLayout PRS_getLocationWsAfterFile(PRS_Location arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getLocationWsAfterParenOpen(PRS_Location arg) */

PRS_OptLayout PRS_getLocationWsAfterParenOpen(PRS_Location arg)
{
  if (PRS_isLocationFile(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PRS_isLocationArea(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PRS_StrCon PRS_getLocationFilename(PRS_Location arg) */

PRS_StrCon PRS_getLocationFilename(PRS_Location arg)
{
  if (PRS_isLocationFile(arg)) {
    return (PRS_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PRS_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getLocationWsAfterFilename(PRS_Location arg) */

PRS_OptLayout PRS_getLocationWsAfterFilename(PRS_Location arg)
{
  if (PRS_isLocationFile(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getLocationWsAfterA(PRS_Location arg) */

PRS_OptLayout PRS_getLocationWsAfterA(PRS_Location arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_Area PRS_getLocationArea(PRS_Location arg) */

PRS_Area PRS_getLocationArea(PRS_Location arg)
{
  if (PRS_isLocationArea(arg)) {
    return (PRS_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PRS_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getLocationWsAfterArea(PRS_Location arg) */

PRS_OptLayout PRS_getLocationWsAfterArea(PRS_Location arg)
{
  if (PRS_isLocationArea(arg)) {
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getLocationWsAfterAreaInFile(PRS_Location arg) */

PRS_OptLayout PRS_getLocationWsAfterAreaInFile(PRS_Location arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getLocationWsAfterComma(PRS_Location arg) */

PRS_OptLayout PRS_getLocationWsAfterComma(PRS_Location arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationWsAfterFile(PRS_Location arg, PRS_OptLayout wsAfterFile) */

PRS_Location PRS_setLocationWsAfterFile(PRS_Location arg, PRS_OptLayout wsAfterFile)
{
  if (PRS_isLocationFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFile), 1), 1);
  }

  ATabort("Location has no WsAfterFile: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationWsAfterParenOpen(PRS_Location arg, PRS_OptLayout wsAfterParenOpen) */

PRS_Location PRS_setLocationWsAfterParenOpen(PRS_Location arg, PRS_OptLayout wsAfterParenOpen)
{
  if (PRS_isLocationFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isLocationArea(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Location has no WsAfterParenOpen: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationFilename(PRS_Location arg, PRS_StrCon filename) */

PRS_Location PRS_setLocationFilename(PRS_Location arg, PRS_StrCon filename)
{
  if (PRS_isLocationFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationWsAfterFilename(PRS_Location arg, PRS_OptLayout wsAfterFilename) */

PRS_Location PRS_setLocationWsAfterFilename(PRS_Location arg, PRS_OptLayout wsAfterFilename)
{
  if (PRS_isLocationFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }

  ATabort("Location has no WsAfterFilename: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationWsAfterA(PRS_Location arg, PRS_OptLayout wsAfterA) */

PRS_Location PRS_setLocationWsAfterA(PRS_Location arg, PRS_OptLayout wsAfterA)
{
  if (PRS_isLocationArea(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterA), 1), 1);
  }

  ATabort("Location has no WsAfterA: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationArea(PRS_Location arg, PRS_Area Area) */

PRS_Location PRS_setLocationArea(PRS_Location arg, PRS_Area Area)
{
  if (PRS_isLocationArea(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 4), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 8), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationWsAfterArea(PRS_Location arg, PRS_OptLayout wsAfterArea) */

PRS_Location PRS_setLocationWsAfterArea(PRS_Location arg, PRS_OptLayout wsAfterArea)
{
  if (PRS_isLocationArea(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 5), 1);
  }
  else if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 9), 1);
  }

  ATabort("Location has no WsAfterArea: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationWsAfterAreaInFile(PRS_Location arg, PRS_OptLayout wsAfterAreaInFile) */

PRS_Location PRS_setLocationWsAfterAreaInFile(PRS_Location arg, PRS_OptLayout wsAfterAreaInFile)
{
  if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAreaInFile), 1), 1);
  }

  ATabort("Location has no WsAfterAreaInFile: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_setLocationWsAfterComma(PRS_Location arg, PRS_OptLayout wsAfterComma) */

PRS_Location PRS_setLocationWsAfterComma(PRS_Location arg, PRS_OptLayout wsAfterComma)
{
  if (PRS_isLocationAreaInFile(arg)) {
    return (PRS_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Location has no WsAfterComma: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PRS_Area accessors */

/*{{{  ATbool PRS_isValidArea(PRS_Area arg) */

ATbool PRS_isValidArea(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PRS_isAreaArea(PRS_Area arg) */

inline ATbool PRS_isAreaArea(PRS_Area arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PRS_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterArea(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterArea(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterParenOpen(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterParenOpen(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaBeginLine(PRS_Area arg) */

ATbool PRS_hasAreaBeginLine(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterBeginLine(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterBeginLine(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterComma(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterComma(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaBeginColumn(PRS_Area arg) */

ATbool PRS_hasAreaBeginColumn(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterBeginColumn(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterBeginColumn(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterComma1(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterComma1(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaEndLine(PRS_Area arg) */

ATbool PRS_hasAreaEndLine(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterEndLine(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterEndLine(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterComma2(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterComma2(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaEndColumn(PRS_Area arg) */

ATbool PRS_hasAreaEndColumn(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterEndColumn(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterEndColumn(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterComma3(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterComma3(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaOffset(PRS_Area arg) */

ATbool PRS_hasAreaOffset(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterOffset(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterOffset(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterComma4(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterComma4(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaLength(PRS_Area arg) */

ATbool PRS_hasAreaLength(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PRS_hasAreaWsAfterLength(PRS_Area arg) */

ATbool PRS_hasAreaWsAfterLength(PRS_Area arg)
{
  if (PRS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterArea(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterArea(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterParenOpen(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterParenOpen(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PRS_NatCon PRS_getAreaBeginLine(PRS_Area arg) */

PRS_NatCon PRS_getAreaBeginLine(PRS_Area arg)
{
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterBeginLine(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterBeginLine(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterComma(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterComma(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PRS_NatCon PRS_getAreaBeginColumn(PRS_Area arg) */

PRS_NatCon PRS_getAreaBeginColumn(PRS_Area arg)
{
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterBeginColumn(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterBeginColumn(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterComma1(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterComma1(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PRS_NatCon PRS_getAreaEndLine(PRS_Area arg) */

PRS_NatCon PRS_getAreaEndLine(PRS_Area arg)
{
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterEndLine(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterEndLine(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterComma2(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterComma2(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PRS_NatCon PRS_getAreaEndColumn(PRS_Area arg) */

PRS_NatCon PRS_getAreaEndColumn(PRS_Area arg)
{
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterEndColumn(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterEndColumn(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterComma3(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterComma3(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/*}}}  */
/*{{{  PRS_NatCon PRS_getAreaOffset(PRS_Area arg) */

PRS_NatCon PRS_getAreaOffset(PRS_Area arg)
{
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 20);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterOffset(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterOffset(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterComma4(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterComma4(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/*}}}  */
/*{{{  PRS_NatCon PRS_getAreaLength(PRS_Area arg) */

PRS_NatCon PRS_getAreaLength(PRS_Area arg)
{
  
    return (PRS_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 24);
}

/*}}}  */
/*{{{  PRS_OptLayout PRS_getAreaWsAfterLength(PRS_Area arg) */

PRS_OptLayout PRS_getAreaWsAfterLength(PRS_Area arg)
{
  
    return (PRS_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterArea(PRS_Area arg, PRS_OptLayout wsAfterArea) */

PRS_Area PRS_setAreaWsAfterArea(PRS_Area arg, PRS_OptLayout wsAfterArea)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 1), 1);
  }

  ATabort("Area has no WsAfterArea: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterParenOpen(PRS_Area arg, PRS_OptLayout wsAfterParenOpen) */

PRS_Area PRS_setAreaWsAfterParenOpen(PRS_Area arg, PRS_OptLayout wsAfterParenOpen)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Area has no WsAfterParenOpen: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaBeginLine(PRS_Area arg, PRS_NatCon beginLine) */

PRS_Area PRS_setAreaBeginLine(PRS_Area arg, PRS_NatCon beginLine)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginLine), 4), 1);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterBeginLine(PRS_Area arg, PRS_OptLayout wsAfterBeginLine) */

PRS_Area PRS_setAreaWsAfterBeginLine(PRS_Area arg, PRS_OptLayout wsAfterBeginLine)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginLine), 5), 1);
  }

  ATabort("Area has no WsAfterBeginLine: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterComma(PRS_Area arg, PRS_OptLayout wsAfterComma) */

PRS_Area PRS_setAreaWsAfterComma(PRS_Area arg, PRS_OptLayout wsAfterComma)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Area has no WsAfterComma: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaBeginColumn(PRS_Area arg, PRS_NatCon beginColumn) */

PRS_Area PRS_setAreaBeginColumn(PRS_Area arg, PRS_NatCon beginColumn)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginColumn), 8), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterBeginColumn(PRS_Area arg, PRS_OptLayout wsAfterBeginColumn) */

PRS_Area PRS_setAreaWsAfterBeginColumn(PRS_Area arg, PRS_OptLayout wsAfterBeginColumn)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginColumn), 9), 1);
  }

  ATabort("Area has no WsAfterBeginColumn: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterComma1(PRS_Area arg, PRS_OptLayout wsAfterComma1) */

PRS_Area PRS_setAreaWsAfterComma1(PRS_Area arg, PRS_OptLayout wsAfterComma1)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Area has no WsAfterComma1: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaEndLine(PRS_Area arg, PRS_NatCon endLine) */

PRS_Area PRS_setAreaEndLine(PRS_Area arg, PRS_NatCon endLine)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endLine), 12), 1);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterEndLine(PRS_Area arg, PRS_OptLayout wsAfterEndLine) */

PRS_Area PRS_setAreaWsAfterEndLine(PRS_Area arg, PRS_OptLayout wsAfterEndLine)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndLine), 13), 1);
  }

  ATabort("Area has no WsAfterEndLine: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterComma2(PRS_Area arg, PRS_OptLayout wsAfterComma2) */

PRS_Area PRS_setAreaWsAfterComma2(PRS_Area arg, PRS_OptLayout wsAfterComma2)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("Area has no WsAfterComma2: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaEndColumn(PRS_Area arg, PRS_NatCon endColumn) */

PRS_Area PRS_setAreaEndColumn(PRS_Area arg, PRS_NatCon endColumn)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endColumn), 16), 1);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterEndColumn(PRS_Area arg, PRS_OptLayout wsAfterEndColumn) */

PRS_Area PRS_setAreaWsAfterEndColumn(PRS_Area arg, PRS_OptLayout wsAfterEndColumn)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndColumn), 17), 1);
  }

  ATabort("Area has no WsAfterEndColumn: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterComma3(PRS_Area arg, PRS_OptLayout wsAfterComma3) */

PRS_Area PRS_setAreaWsAfterComma3(PRS_Area arg, PRS_OptLayout wsAfterComma3)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }

  ATabort("Area has no WsAfterComma3: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaOffset(PRS_Area arg, PRS_NatCon offset) */

PRS_Area PRS_setAreaOffset(PRS_Area arg, PRS_NatCon offset)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) offset), 20), 1);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterOffset(PRS_Area arg, PRS_OptLayout wsAfterOffset) */

PRS_Area PRS_setAreaWsAfterOffset(PRS_Area arg, PRS_OptLayout wsAfterOffset)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOffset), 21), 1);
  }

  ATabort("Area has no WsAfterOffset: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterComma4(PRS_Area arg, PRS_OptLayout wsAfterComma4) */

PRS_Area PRS_setAreaWsAfterComma4(PRS_Area arg, PRS_OptLayout wsAfterComma4)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma4), 23), 1);
  }

  ATabort("Area has no WsAfterComma4: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaLength(PRS_Area arg, PRS_NatCon length) */

PRS_Area PRS_setAreaLength(PRS_Area arg, PRS_NatCon length)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) length), 24), 1);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_setAreaWsAfterLength(PRS_Area arg, PRS_OptLayout wsAfterLength) */

PRS_Area PRS_setAreaWsAfterLength(PRS_Area arg, PRS_OptLayout wsAfterLength)
{
  if (PRS_isAreaArea(arg)) {
    return (PRS_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLength), 25), 1);
  }

  ATabort("Area has no WsAfterLength: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  PRS_OptLayout PRS_visitOptLayout(PRS_OptLayout arg, PRS_Layout (*acceptLayout)(PRS_Layout)) */

PRS_OptLayout PRS_visitOptLayout(PRS_OptLayout arg, PRS_Layout (*acceptLayout)(PRS_Layout))
{
  if (PRS_isOptLayoutAbsent(arg)) {
    return PRS_makeOptLayoutAbsent();
  }
  if (PRS_isOptLayoutPresent(arg)) {
    return PRS_makeOptLayoutPresent(
        acceptLayout ? acceptLayout(PRS_getOptLayoutLayout(arg)) : PRS_getOptLayoutLayout(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (PRS_OptLayout)NULL;
}

/*}}}  */
/*{{{  PRS_Layout PRS_visitLayout(PRS_Layout arg, PRS_LexLayoutList (*acceptList)(PRS_LexLayoutList)) */

PRS_Layout PRS_visitLayout(PRS_Layout arg, PRS_LexLayoutList (*acceptList)(PRS_LexLayoutList))
{
  if (PRS_isLayoutLexToCf(arg)) {
    return PRS_makeLayoutLexToCf(
        acceptList ? acceptList(PRS_getLayoutList(arg)) : PRS_getLayoutList(arg));
  }
  ATabort("not a Layout: %t\n", arg);
  return (PRS_Layout)NULL;
}

/*}}}  */
/*{{{  PRS_LexLayoutList PRS_visitLexLayoutList(PRS_LexLayoutList arg, PRS_LexLayout (*acceptHead)(PRS_LexLayout)) */

PRS_LexLayoutList PRS_visitLexLayoutList(PRS_LexLayoutList arg, PRS_LexLayout (*acceptHead)(PRS_LexLayout))
{
  if (PRS_isLexLayoutListEmpty(arg)) {
    return PRS_makeLexLayoutListEmpty();
  }
  if (PRS_isLexLayoutListSingle(arg)) {
    return PRS_makeLexLayoutListSingle(
        acceptHead ? acceptHead(PRS_getLexLayoutListHead(arg)) : PRS_getLexLayoutListHead(arg));
  }
  if (PRS_isLexLayoutListMany(arg)) {
    return PRS_makeLexLayoutListMany(
        acceptHead ? acceptHead(PRS_getLexLayoutListHead(arg)) : PRS_getLexLayoutListHead(arg),
        PRS_visitLexLayoutList(PRS_getLexLayoutListTail(arg), acceptHead));
  }
  ATabort("not a LexLayoutList: %t\n", arg);
  return (PRS_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  PRS_RElem PRS_visitRElem(PRS_RElem arg, PRS_OptLayout (*acceptWsAfterInt)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_NatCon (*acceptIntValue)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterIntValue)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterStr)(PRS_OptLayout), PRS_StrCon (*acceptStrValue)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterStrValue)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterLoc)(PRS_OptLayout), PRS_Location (*acceptLocValue)(PRS_Location), PRS_OptLayout (*acceptWsAfterLocValue)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSet)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketOpen)(PRS_OptLayout), PRS_RElemList (*acceptList)(PRS_RElemList), PRS_OptLayout (*acceptWsAfterList)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketClose)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBag)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterTuple)(PRS_OptLayout)) */

PRS_RElem PRS_visitRElem(PRS_RElem arg, PRS_OptLayout (*acceptWsAfterInt)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_NatCon (*acceptIntValue)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterIntValue)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterStr)(PRS_OptLayout), PRS_StrCon (*acceptStrValue)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterStrValue)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterLoc)(PRS_OptLayout), PRS_Location (*acceptLocValue)(PRS_Location), PRS_OptLayout (*acceptWsAfterLocValue)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSet)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketOpen)(PRS_OptLayout), PRS_RElemList (*acceptList)(PRS_RElemList), PRS_OptLayout (*acceptWsAfterList)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketClose)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBag)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterTuple)(PRS_OptLayout))
{
  if (PRS_isRElemInteger(arg)) {
    return PRS_makeRElemInteger(
        acceptWsAfterInt ? acceptWsAfterInt(PRS_getRElemWsAfterInt(arg)) : PRS_getRElemWsAfterInt(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRElemWsAfterParenOpen(arg)) : PRS_getRElemWsAfterParenOpen(arg),
        acceptIntValue ? acceptIntValue(PRS_getRElemIntValue(arg)) : PRS_getRElemIntValue(arg),
        acceptWsAfterIntValue ? acceptWsAfterIntValue(PRS_getRElemWsAfterIntValue(arg)) : PRS_getRElemWsAfterIntValue(arg));
  }
  if (PRS_isRElemString(arg)) {
    return PRS_makeRElemString(
        acceptWsAfterStr ? acceptWsAfterStr(PRS_getRElemWsAfterStr(arg)) : PRS_getRElemWsAfterStr(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRElemWsAfterParenOpen(arg)) : PRS_getRElemWsAfterParenOpen(arg),
        acceptStrValue ? acceptStrValue(PRS_getRElemStrValue(arg)) : PRS_getRElemStrValue(arg),
        acceptWsAfterStrValue ? acceptWsAfterStrValue(PRS_getRElemWsAfterStrValue(arg)) : PRS_getRElemWsAfterStrValue(arg));
  }
  if (PRS_isRElemLocation(arg)) {
    return PRS_makeRElemLocation(
        acceptWsAfterLoc ? acceptWsAfterLoc(PRS_getRElemWsAfterLoc(arg)) : PRS_getRElemWsAfterLoc(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRElemWsAfterParenOpen(arg)) : PRS_getRElemWsAfterParenOpen(arg),
        acceptLocValue ? acceptLocValue(PRS_getRElemLocValue(arg)) : PRS_getRElemLocValue(arg),
        acceptWsAfterLocValue ? acceptWsAfterLocValue(PRS_getRElemWsAfterLocValue(arg)) : PRS_getRElemWsAfterLocValue(arg));
  }
  if (PRS_isRElemSet(arg)) {
    return PRS_makeRElemSet(
        acceptWsAfterSet ? acceptWsAfterSet(PRS_getRElemWsAfterSet(arg)) : PRS_getRElemWsAfterSet(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRElemWsAfterParenOpen(arg)) : PRS_getRElemWsAfterParenOpen(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRElemWsAfterBracketOpen(arg)) : PRS_getRElemWsAfterBracketOpen(arg),
        acceptList ? acceptList(PRS_getRElemList(arg)) : PRS_getRElemList(arg),
        acceptWsAfterList ? acceptWsAfterList(PRS_getRElemWsAfterList(arg)) : PRS_getRElemWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PRS_getRElemWsAfterBracketClose(arg)) : PRS_getRElemWsAfterBracketClose(arg));
  }
  if (PRS_isRElemBag(arg)) {
    return PRS_makeRElemBag(
        acceptWsAfterBag ? acceptWsAfterBag(PRS_getRElemWsAfterBag(arg)) : PRS_getRElemWsAfterBag(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRElemWsAfterParenOpen(arg)) : PRS_getRElemWsAfterParenOpen(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRElemWsAfterBracketOpen(arg)) : PRS_getRElemWsAfterBracketOpen(arg),
        acceptList ? acceptList(PRS_getRElemList(arg)) : PRS_getRElemList(arg),
        acceptWsAfterList ? acceptWsAfterList(PRS_getRElemWsAfterList(arg)) : PRS_getRElemWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PRS_getRElemWsAfterBracketClose(arg)) : PRS_getRElemWsAfterBracketClose(arg));
  }
  if (PRS_isRElemTuple(arg)) {
    return PRS_makeRElemTuple(
        acceptWsAfterTuple ? acceptWsAfterTuple(PRS_getRElemWsAfterTuple(arg)) : PRS_getRElemWsAfterTuple(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRElemWsAfterParenOpen(arg)) : PRS_getRElemWsAfterParenOpen(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRElemWsAfterBracketOpen(arg)) : PRS_getRElemWsAfterBracketOpen(arg),
        acceptList ? acceptList(PRS_getRElemList(arg)) : PRS_getRElemList(arg),
        acceptWsAfterList ? acceptWsAfterList(PRS_getRElemWsAfterList(arg)) : PRS_getRElemWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PRS_getRElemWsAfterBracketClose(arg)) : PRS_getRElemWsAfterBracketClose(arg));
  }
  ATabort("not a RElem: %t\n", arg);
  return (PRS_RElem)NULL;
}

/*}}}  */
/*{{{  PRS_RType PRS_visitRType(PRS_RType arg, PRS_OptLayout (*acceptWsAfterTuple)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketOpen)(PRS_OptLayout), PRS_RTypeList (*acceptList)(PRS_RTypeList), PRS_OptLayout (*acceptWsAfterList)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketClose)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSet)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterRType)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBag)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterRel)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterUser)(PRS_OptLayout), PRS_StrCon (*acceptStrCon)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterStrCon)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParameter)(PRS_OptLayout)) */

PRS_RType PRS_visitRType(PRS_RType arg, PRS_OptLayout (*acceptWsAfterTuple)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketOpen)(PRS_OptLayout), PRS_RTypeList (*acceptList)(PRS_RTypeList), PRS_OptLayout (*acceptWsAfterList)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketClose)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSet)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterRType)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBag)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterRel)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterUser)(PRS_OptLayout), PRS_StrCon (*acceptStrCon)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterStrCon)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParameter)(PRS_OptLayout))
{
  if (PRS_isRTypeInteger(arg)) {
    return PRS_makeRTypeInteger();
  }
  if (PRS_isRTypeString(arg)) {
    return PRS_makeRTypeString();
  }
  if (PRS_isRTypeLocation(arg)) {
    return PRS_makeRTypeLocation();
  }
  if (PRS_isRTypeTuple(arg)) {
    return PRS_makeRTypeTuple(
        acceptWsAfterTuple ? acceptWsAfterTuple(PRS_getRTypeWsAfterTuple(arg)) : PRS_getRTypeWsAfterTuple(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRTypeWsAfterParenOpen(arg)) : PRS_getRTypeWsAfterParenOpen(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRTypeWsAfterBracketOpen(arg)) : PRS_getRTypeWsAfterBracketOpen(arg),
        acceptList ? acceptList(PRS_getRTypeList(arg)) : PRS_getRTypeList(arg),
        acceptWsAfterList ? acceptWsAfterList(PRS_getRTypeWsAfterList(arg)) : PRS_getRTypeWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PRS_getRTypeWsAfterBracketClose(arg)) : PRS_getRTypeWsAfterBracketClose(arg));
  }
  if (PRS_isRTypeSet(arg)) {
    return PRS_makeRTypeSet(
        acceptWsAfterSet ? acceptWsAfterSet(PRS_getRTypeWsAfterSet(arg)) : PRS_getRTypeWsAfterSet(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRTypeWsAfterParenOpen(arg)) : PRS_getRTypeWsAfterParenOpen(arg),
        PRS_visitRType(PRS_getRTypeRType(arg), acceptWsAfterTuple, acceptWsAfterParenOpen, acceptWsAfterBracketOpen, acceptList, acceptWsAfterList, acceptWsAfterBracketClose, acceptWsAfterSet, acceptWsAfterRType, acceptWsAfterBag, acceptWsAfterRel, acceptWsAfterUser, acceptStrCon, acceptWsAfterStrCon, acceptWsAfterParameter),
        acceptWsAfterRType ? acceptWsAfterRType(PRS_getRTypeWsAfterRType(arg)) : PRS_getRTypeWsAfterRType(arg));
  }
  if (PRS_isRTypeBag(arg)) {
    return PRS_makeRTypeBag(
        acceptWsAfterBag ? acceptWsAfterBag(PRS_getRTypeWsAfterBag(arg)) : PRS_getRTypeWsAfterBag(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRTypeWsAfterParenOpen(arg)) : PRS_getRTypeWsAfterParenOpen(arg),
        PRS_visitRType(PRS_getRTypeRType(arg), acceptWsAfterTuple, acceptWsAfterParenOpen, acceptWsAfterBracketOpen, acceptList, acceptWsAfterList, acceptWsAfterBracketClose, acceptWsAfterSet, acceptWsAfterRType, acceptWsAfterBag, acceptWsAfterRel, acceptWsAfterUser, acceptStrCon, acceptWsAfterStrCon, acceptWsAfterParameter),
        acceptWsAfterRType ? acceptWsAfterRType(PRS_getRTypeWsAfterRType(arg)) : PRS_getRTypeWsAfterRType(arg));
  }
  if (PRS_isRTypeRel(arg)) {
    return PRS_makeRTypeRel(
        acceptWsAfterRel ? acceptWsAfterRel(PRS_getRTypeWsAfterRel(arg)) : PRS_getRTypeWsAfterRel(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRTypeWsAfterParenOpen(arg)) : PRS_getRTypeWsAfterParenOpen(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRTypeWsAfterBracketOpen(arg)) : PRS_getRTypeWsAfterBracketOpen(arg),
        acceptList ? acceptList(PRS_getRTypeList(arg)) : PRS_getRTypeList(arg),
        acceptWsAfterList ? acceptWsAfterList(PRS_getRTypeWsAfterList(arg)) : PRS_getRTypeWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PRS_getRTypeWsAfterBracketClose(arg)) : PRS_getRTypeWsAfterBracketClose(arg));
  }
  if (PRS_isRTypeUser(arg)) {
    return PRS_makeRTypeUser(
        acceptWsAfterUser ? acceptWsAfterUser(PRS_getRTypeWsAfterUser(arg)) : PRS_getRTypeWsAfterUser(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRTypeWsAfterParenOpen(arg)) : PRS_getRTypeWsAfterParenOpen(arg),
        acceptStrCon ? acceptStrCon(PRS_getRTypeStrCon(arg)) : PRS_getRTypeStrCon(arg),
        acceptWsAfterStrCon ? acceptWsAfterStrCon(PRS_getRTypeWsAfterStrCon(arg)) : PRS_getRTypeWsAfterStrCon(arg));
  }
  if (PRS_isRTypeParameter(arg)) {
    return PRS_makeRTypeParameter(
        acceptWsAfterParameter ? acceptWsAfterParameter(PRS_getRTypeWsAfterParameter(arg)) : PRS_getRTypeWsAfterParameter(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRTypeWsAfterParenOpen(arg)) : PRS_getRTypeWsAfterParenOpen(arg),
        acceptStrCon ? acceptStrCon(PRS_getRTypeStrCon(arg)) : PRS_getRTypeStrCon(arg),
        acceptWsAfterStrCon ? acceptWsAfterStrCon(PRS_getRTypeWsAfterStrCon(arg)) : PRS_getRTypeWsAfterStrCon(arg));
  }
  ATabort("not a RType: %t\n", arg);
  return (PRS_RType)NULL;
}

/*}}}  */
/*{{{  PRS_RTuple PRS_visitRTuple(PRS_RTuple arg, PRS_OptLayout (*acceptWsAfterRtuple)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_StrCon (*acceptId)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterId)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout), PRS_RType (*acceptRtype)(PRS_RType), PRS_OptLayout (*acceptWsAfterRtype)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma1)(PRS_OptLayout), PRS_RElem (*acceptData)(PRS_RElem), PRS_OptLayout (*acceptWsAfterData)(PRS_OptLayout)) */

PRS_RTuple PRS_visitRTuple(PRS_RTuple arg, PRS_OptLayout (*acceptWsAfterRtuple)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_StrCon (*acceptId)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterId)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout), PRS_RType (*acceptRtype)(PRS_RType), PRS_OptLayout (*acceptWsAfterRtype)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma1)(PRS_OptLayout), PRS_RElem (*acceptData)(PRS_RElem), PRS_OptLayout (*acceptWsAfterData)(PRS_OptLayout))
{
  if (PRS_isRTupleRtuple(arg)) {
    return PRS_makeRTupleRtuple(
        acceptWsAfterRtuple ? acceptWsAfterRtuple(PRS_getRTupleWsAfterRtuple(arg)) : PRS_getRTupleWsAfterRtuple(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRTupleWsAfterParenOpen(arg)) : PRS_getRTupleWsAfterParenOpen(arg),
        acceptId ? acceptId(PRS_getRTupleId(arg)) : PRS_getRTupleId(arg),
        acceptWsAfterId ? acceptWsAfterId(PRS_getRTupleWsAfterId(arg)) : PRS_getRTupleWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PRS_getRTupleWsAfterComma(arg)) : PRS_getRTupleWsAfterComma(arg),
        acceptRtype ? acceptRtype(PRS_getRTupleRtype(arg)) : PRS_getRTupleRtype(arg),
        acceptWsAfterRtype ? acceptWsAfterRtype(PRS_getRTupleWsAfterRtype(arg)) : PRS_getRTupleWsAfterRtype(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PRS_getRTupleWsAfterComma1(arg)) : PRS_getRTupleWsAfterComma1(arg),
        acceptData ? acceptData(PRS_getRTupleData(arg)) : PRS_getRTupleData(arg),
        acceptWsAfterData ? acceptWsAfterData(PRS_getRTupleWsAfterData(arg)) : PRS_getRTupleWsAfterData(arg));
  }
  ATabort("not a RTuple: %t\n", arg);
  return (PRS_RTuple)NULL;
}

/*}}}  */
/*{{{  PRS_RStore PRS_visitRStore(PRS_RStore arg, PRS_OptLayout (*acceptWsAfterRstore)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketOpen)(PRS_OptLayout), PRS_RTupleList (*acceptList)(PRS_RTupleList), PRS_OptLayout (*acceptWsAfterList)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketClose)(PRS_OptLayout)) */

PRS_RStore PRS_visitRStore(PRS_RStore arg, PRS_OptLayout (*acceptWsAfterRstore)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketOpen)(PRS_OptLayout), PRS_RTupleList (*acceptList)(PRS_RTupleList), PRS_OptLayout (*acceptWsAfterList)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterBracketClose)(PRS_OptLayout))
{
  if (PRS_isRStoreRstore(arg)) {
    return PRS_makeRStoreRstore(
        acceptWsAfterRstore ? acceptWsAfterRstore(PRS_getRStoreWsAfterRstore(arg)) : PRS_getRStoreWsAfterRstore(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getRStoreWsAfterParenOpen(arg)) : PRS_getRStoreWsAfterParenOpen(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PRS_getRStoreWsAfterBracketOpen(arg)) : PRS_getRStoreWsAfterBracketOpen(arg),
        acceptList ? acceptList(PRS_getRStoreList(arg)) : PRS_getRStoreList(arg),
        acceptWsAfterList ? acceptWsAfterList(PRS_getRStoreWsAfterList(arg)) : PRS_getRStoreWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PRS_getRStoreWsAfterBracketClose(arg)) : PRS_getRStoreWsAfterBracketClose(arg));
  }
  ATabort("not a RStore: %t\n", arg);
  return (PRS_RStore)NULL;
}

/*}}}  */
/*{{{  PRS_Start PRS_visitStart(PRS_Start arg, PRS_OptLayout (*acceptWsBefore)(PRS_OptLayout), PRS_RStore (*acceptTopRStore)(PRS_RStore), PRS_OptLayout (*acceptWsAfter)(PRS_OptLayout), int (*acceptAmbCnt)(int)) */

PRS_Start PRS_visitStart(PRS_Start arg, PRS_OptLayout (*acceptWsBefore)(PRS_OptLayout), PRS_RStore (*acceptTopRStore)(PRS_RStore), PRS_OptLayout (*acceptWsAfter)(PRS_OptLayout), int (*acceptAmbCnt)(int))
{
  if (PRS_isStartRStore(arg)) {
    return PRS_makeStartRStore(
        acceptWsBefore ? acceptWsBefore(PRS_getStartWsBefore(arg)) : PRS_getStartWsBefore(arg),
        acceptTopRStore ? acceptTopRStore(PRS_getStartTopRStore(arg)) : PRS_getStartTopRStore(arg),
        acceptWsAfter ? acceptWsAfter(PRS_getStartWsAfter(arg)) : PRS_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PRS_getStartAmbCnt(arg)) : PRS_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (PRS_Start)NULL;
}

/*}}}  */
/*{{{  PRS_RElemList PRS_visitRElemList(PRS_RElemList arg, PRS_RElem (*acceptHead)(PRS_RElem), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout)) */

PRS_RElemList PRS_visitRElemList(PRS_RElemList arg, PRS_RElem (*acceptHead)(PRS_RElem), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout))
{
  if (PRS_isRElemListEmpty(arg)) {
    return PRS_makeRElemListEmpty();
  }
  if (PRS_isRElemListSingle(arg)) {
    return PRS_makeRElemListSingle(
        acceptHead ? acceptHead(PRS_getRElemListHead(arg)) : PRS_getRElemListHead(arg));
  }
  if (PRS_isRElemListMany(arg)) {
    return PRS_makeRElemListMany(
        acceptHead ? acceptHead(PRS_getRElemListHead(arg)) : PRS_getRElemListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PRS_getRElemListWsAfterHead(arg)) : PRS_getRElemListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PRS_getRElemListWsAfterSep(arg)) : PRS_getRElemListWsAfterSep(arg),
        PRS_visitRElemList(PRS_getRElemListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a RElemList: %t\n", arg);
  return (PRS_RElemList)NULL;
}

/*}}}  */
/*{{{  PRS_RTypeList PRS_visitRTypeList(PRS_RTypeList arg, PRS_RType (*acceptHead)(PRS_RType), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout)) */

PRS_RTypeList PRS_visitRTypeList(PRS_RTypeList arg, PRS_RType (*acceptHead)(PRS_RType), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout))
{
  if (PRS_isRTypeListEmpty(arg)) {
    return PRS_makeRTypeListEmpty();
  }
  if (PRS_isRTypeListSingle(arg)) {
    return PRS_makeRTypeListSingle(
        acceptHead ? acceptHead(PRS_getRTypeListHead(arg)) : PRS_getRTypeListHead(arg));
  }
  if (PRS_isRTypeListMany(arg)) {
    return PRS_makeRTypeListMany(
        acceptHead ? acceptHead(PRS_getRTypeListHead(arg)) : PRS_getRTypeListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PRS_getRTypeListWsAfterHead(arg)) : PRS_getRTypeListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PRS_getRTypeListWsAfterSep(arg)) : PRS_getRTypeListWsAfterSep(arg),
        PRS_visitRTypeList(PRS_getRTypeListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a RTypeList: %t\n", arg);
  return (PRS_RTypeList)NULL;
}

/*}}}  */
/*{{{  PRS_RTupleList PRS_visitRTupleList(PRS_RTupleList arg, PRS_RTuple (*acceptHead)(PRS_RTuple), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout)) */

PRS_RTupleList PRS_visitRTupleList(PRS_RTupleList arg, PRS_RTuple (*acceptHead)(PRS_RTuple), PRS_OptLayout (*acceptWsAfterHead)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterSep)(PRS_OptLayout))
{
  if (PRS_isRTupleListEmpty(arg)) {
    return PRS_makeRTupleListEmpty();
  }
  if (PRS_isRTupleListSingle(arg)) {
    return PRS_makeRTupleListSingle(
        acceptHead ? acceptHead(PRS_getRTupleListHead(arg)) : PRS_getRTupleListHead(arg));
  }
  if (PRS_isRTupleListMany(arg)) {
    return PRS_makeRTupleListMany(
        acceptHead ? acceptHead(PRS_getRTupleListHead(arg)) : PRS_getRTupleListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PRS_getRTupleListWsAfterHead(arg)) : PRS_getRTupleListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PRS_getRTupleListWsAfterSep(arg)) : PRS_getRTupleListWsAfterSep(arg),
        PRS_visitRTupleList(PRS_getRTupleListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a RTupleList: %t\n", arg);
  return (PRS_RTupleList)NULL;
}

/*}}}  */
/*{{{  PRS_LexStrChar PRS_visitLexStrChar(PRS_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char)) */

PRS_LexStrChar PRS_visitLexStrChar(PRS_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char))
{
  if (PRS_isLexStrCharNewline(arg)) {
    return PRS_makeLexStrCharNewline();
  }
  if (PRS_isLexStrCharTab(arg)) {
    return PRS_makeLexStrCharTab();
  }
  if (PRS_isLexStrCharQuote(arg)) {
    return PRS_makeLexStrCharQuote();
  }
  if (PRS_isLexStrCharBackslash(arg)) {
    return PRS_makeLexStrCharBackslash();
  }
  if (PRS_isLexStrCharDecimal(arg)) {
    return PRS_makeLexStrCharDecimal(
        acceptA ? acceptA(PRS_getLexStrCharA(arg)) : PRS_getLexStrCharA(arg),
        acceptB ? acceptB(PRS_getLexStrCharB(arg)) : PRS_getLexStrCharB(arg),
        acceptC ? acceptC(PRS_getLexStrCharC(arg)) : PRS_getLexStrCharC(arg));
  }
  if (PRS_isLexStrCharNormal(arg)) {
    return PRS_makeLexStrCharNormal(
        acceptCh ? acceptCh(PRS_getLexStrCharCh(arg)) : PRS_getLexStrCharCh(arg));
  }
  ATabort("not a LexStrChar: %t\n", arg);
  return (PRS_LexStrChar)NULL;
}

/*}}}  */
/*{{{  PRS_StrChar PRS_visitStrChar(PRS_StrChar arg, PRS_LexStrChar (*acceptStrChar)(PRS_LexStrChar)) */

PRS_StrChar PRS_visitStrChar(PRS_StrChar arg, PRS_LexStrChar (*acceptStrChar)(PRS_LexStrChar))
{
  if (PRS_isStrCharLexToCf(arg)) {
    return PRS_makeStrCharLexToCf(
        acceptStrChar ? acceptStrChar(PRS_getStrCharStrChar(arg)) : PRS_getStrCharStrChar(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (PRS_StrChar)NULL;
}

/*}}}  */
/*{{{  PRS_LexStrCon PRS_visitLexStrCon(PRS_LexStrCon arg, PRS_LexStrCharChars (*acceptChars)(PRS_LexStrCharChars)) */

PRS_LexStrCon PRS_visitLexStrCon(PRS_LexStrCon arg, PRS_LexStrCharChars (*acceptChars)(PRS_LexStrCharChars))
{
  if (PRS_isLexStrConDefault(arg)) {
    return PRS_makeLexStrConDefault(
        acceptChars ? acceptChars(PRS_getLexStrConChars(arg)) : PRS_getLexStrConChars(arg));
  }
  ATabort("not a LexStrCon: %t\n", arg);
  return (PRS_LexStrCon)NULL;
}

/*}}}  */
/*{{{  PRS_StrCon PRS_visitStrCon(PRS_StrCon arg, PRS_LexStrCon (*acceptStrCon)(PRS_LexStrCon)) */

PRS_StrCon PRS_visitStrCon(PRS_StrCon arg, PRS_LexStrCon (*acceptStrCon)(PRS_LexStrCon))
{
  if (PRS_isStrConLexToCf(arg)) {
    return PRS_makeStrConLexToCf(
        acceptStrCon ? acceptStrCon(PRS_getStrConStrCon(arg)) : PRS_getStrConStrCon(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (PRS_StrCon)NULL;
}

/*}}}  */
/*{{{  PRS_LexStrCharChars PRS_visitLexStrCharChars(PRS_LexStrCharChars arg, PRS_LexStrChar (*acceptHead)(PRS_LexStrChar)) */

PRS_LexStrCharChars PRS_visitLexStrCharChars(PRS_LexStrCharChars arg, PRS_LexStrChar (*acceptHead)(PRS_LexStrChar))
{
  if (PRS_isLexStrCharCharsEmpty(arg)) {
    return PRS_makeLexStrCharCharsEmpty();
  }
  if (PRS_isLexStrCharCharsSingle(arg)) {
    return PRS_makeLexStrCharCharsSingle(
        acceptHead ? acceptHead(PRS_getLexStrCharCharsHead(arg)) : PRS_getLexStrCharCharsHead(arg));
  }
  if (PRS_isLexStrCharCharsMany(arg)) {
    return PRS_makeLexStrCharCharsMany(
        acceptHead ? acceptHead(PRS_getLexStrCharCharsHead(arg)) : PRS_getLexStrCharCharsHead(arg),
        PRS_visitLexStrCharChars(PRS_getLexStrCharCharsTail(arg), acceptHead));
  }
  ATabort("not a LexStrCharChars: %t\n", arg);
  return (PRS_LexStrCharChars)NULL;
}

/*}}}  */
/*{{{  PRS_LexNatCon PRS_visitLexNatCon(PRS_LexNatCon arg, char* (*acceptList)(char*)) */

PRS_LexNatCon PRS_visitLexNatCon(PRS_LexNatCon arg, char* (*acceptList)(char*))
{
  if (PRS_isLexNatConDigits(arg)) {
    return PRS_makeLexNatConDigits(
        acceptList ? acceptList(PRS_getLexNatConList(arg)) : PRS_getLexNatConList(arg));
  }
  ATabort("not a LexNatCon: %t\n", arg);
  return (PRS_LexNatCon)NULL;
}

/*}}}  */
/*{{{  PRS_NatCon PRS_visitNatCon(PRS_NatCon arg, PRS_LexNatCon (*acceptNatCon)(PRS_LexNatCon)) */

PRS_NatCon PRS_visitNatCon(PRS_NatCon arg, PRS_LexNatCon (*acceptNatCon)(PRS_LexNatCon))
{
  if (PRS_isNatConLexToCf(arg)) {
    return PRS_makeNatConLexToCf(
        acceptNatCon ? acceptNatCon(PRS_getNatConNatCon(arg)) : PRS_getNatConNatCon(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (PRS_NatCon)NULL;
}

/*}}}  */
/*{{{  PRS_LexLayout PRS_visitLexLayout(PRS_LexLayout arg, char (*acceptCh)(char)) */

PRS_LexLayout PRS_visitLexLayout(PRS_LexLayout arg, char (*acceptCh)(char))
{
  if (PRS_isLexLayoutWhitespace(arg)) {
    return PRS_makeLexLayoutWhitespace(
        acceptCh ? acceptCh(PRS_getLexLayoutCh(arg)) : PRS_getLexLayoutCh(arg));
  }
  ATabort("not a LexLayout: %t\n", arg);
  return (PRS_LexLayout)NULL;
}

/*}}}  */
/*{{{  PRS_Location PRS_visitLocation(PRS_Location arg, PRS_OptLayout (*acceptWsAfterFile)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_StrCon (*acceptFilename)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterFilename)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterA)(PRS_OptLayout), PRS_Area (*acceptArea)(PRS_Area), PRS_OptLayout (*acceptWsAfterArea)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterAreaInFile)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout)) */

PRS_Location PRS_visitLocation(PRS_Location arg, PRS_OptLayout (*acceptWsAfterFile)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_StrCon (*acceptFilename)(PRS_StrCon), PRS_OptLayout (*acceptWsAfterFilename)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterA)(PRS_OptLayout), PRS_Area (*acceptArea)(PRS_Area), PRS_OptLayout (*acceptWsAfterArea)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterAreaInFile)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout))
{
  if (PRS_isLocationFile(arg)) {
    return PRS_makeLocationFile(
        acceptWsAfterFile ? acceptWsAfterFile(PRS_getLocationWsAfterFile(arg)) : PRS_getLocationWsAfterFile(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getLocationWsAfterParenOpen(arg)) : PRS_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(PRS_getLocationFilename(arg)) : PRS_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(PRS_getLocationWsAfterFilename(arg)) : PRS_getLocationWsAfterFilename(arg));
  }
  if (PRS_isLocationArea(arg)) {
    return PRS_makeLocationArea(
        acceptWsAfterA ? acceptWsAfterA(PRS_getLocationWsAfterA(arg)) : PRS_getLocationWsAfterA(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getLocationWsAfterParenOpen(arg)) : PRS_getLocationWsAfterParenOpen(arg),
        acceptArea ? acceptArea(PRS_getLocationArea(arg)) : PRS_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(PRS_getLocationWsAfterArea(arg)) : PRS_getLocationWsAfterArea(arg));
  }
  if (PRS_isLocationAreaInFile(arg)) {
    return PRS_makeLocationAreaInFile(
        acceptWsAfterAreaInFile ? acceptWsAfterAreaInFile(PRS_getLocationWsAfterAreaInFile(arg)) : PRS_getLocationWsAfterAreaInFile(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getLocationWsAfterParenOpen(arg)) : PRS_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(PRS_getLocationFilename(arg)) : PRS_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(PRS_getLocationWsAfterFilename(arg)) : PRS_getLocationWsAfterFilename(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PRS_getLocationWsAfterComma(arg)) : PRS_getLocationWsAfterComma(arg),
        acceptArea ? acceptArea(PRS_getLocationArea(arg)) : PRS_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(PRS_getLocationWsAfterArea(arg)) : PRS_getLocationWsAfterArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (PRS_Location)NULL;
}

/*}}}  */
/*{{{  PRS_Area PRS_visitArea(PRS_Area arg, PRS_OptLayout (*acceptWsAfterArea)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_NatCon (*acceptBeginLine)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterBeginLine)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout), PRS_NatCon (*acceptBeginColumn)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterBeginColumn)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma1)(PRS_OptLayout), PRS_NatCon (*acceptEndLine)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterEndLine)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma2)(PRS_OptLayout), PRS_NatCon (*acceptEndColumn)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterEndColumn)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma3)(PRS_OptLayout), PRS_NatCon (*acceptOffset)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterOffset)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma4)(PRS_OptLayout), PRS_NatCon (*acceptLength)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterLength)(PRS_OptLayout)) */

PRS_Area PRS_visitArea(PRS_Area arg, PRS_OptLayout (*acceptWsAfterArea)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterParenOpen)(PRS_OptLayout), PRS_NatCon (*acceptBeginLine)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterBeginLine)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma)(PRS_OptLayout), PRS_NatCon (*acceptBeginColumn)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterBeginColumn)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma1)(PRS_OptLayout), PRS_NatCon (*acceptEndLine)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterEndLine)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma2)(PRS_OptLayout), PRS_NatCon (*acceptEndColumn)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterEndColumn)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma3)(PRS_OptLayout), PRS_NatCon (*acceptOffset)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterOffset)(PRS_OptLayout), PRS_OptLayout (*acceptWsAfterComma4)(PRS_OptLayout), PRS_NatCon (*acceptLength)(PRS_NatCon), PRS_OptLayout (*acceptWsAfterLength)(PRS_OptLayout))
{
  if (PRS_isAreaArea(arg)) {
    return PRS_makeAreaArea(
        acceptWsAfterArea ? acceptWsAfterArea(PRS_getAreaWsAfterArea(arg)) : PRS_getAreaWsAfterArea(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PRS_getAreaWsAfterParenOpen(arg)) : PRS_getAreaWsAfterParenOpen(arg),
        acceptBeginLine ? acceptBeginLine(PRS_getAreaBeginLine(arg)) : PRS_getAreaBeginLine(arg),
        acceptWsAfterBeginLine ? acceptWsAfterBeginLine(PRS_getAreaWsAfterBeginLine(arg)) : PRS_getAreaWsAfterBeginLine(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PRS_getAreaWsAfterComma(arg)) : PRS_getAreaWsAfterComma(arg),
        acceptBeginColumn ? acceptBeginColumn(PRS_getAreaBeginColumn(arg)) : PRS_getAreaBeginColumn(arg),
        acceptWsAfterBeginColumn ? acceptWsAfterBeginColumn(PRS_getAreaWsAfterBeginColumn(arg)) : PRS_getAreaWsAfterBeginColumn(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PRS_getAreaWsAfterComma1(arg)) : PRS_getAreaWsAfterComma1(arg),
        acceptEndLine ? acceptEndLine(PRS_getAreaEndLine(arg)) : PRS_getAreaEndLine(arg),
        acceptWsAfterEndLine ? acceptWsAfterEndLine(PRS_getAreaWsAfterEndLine(arg)) : PRS_getAreaWsAfterEndLine(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PRS_getAreaWsAfterComma2(arg)) : PRS_getAreaWsAfterComma2(arg),
        acceptEndColumn ? acceptEndColumn(PRS_getAreaEndColumn(arg)) : PRS_getAreaEndColumn(arg),
        acceptWsAfterEndColumn ? acceptWsAfterEndColumn(PRS_getAreaWsAfterEndColumn(arg)) : PRS_getAreaWsAfterEndColumn(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PRS_getAreaWsAfterComma3(arg)) : PRS_getAreaWsAfterComma3(arg),
        acceptOffset ? acceptOffset(PRS_getAreaOffset(arg)) : PRS_getAreaOffset(arg),
        acceptWsAfterOffset ? acceptWsAfterOffset(PRS_getAreaWsAfterOffset(arg)) : PRS_getAreaWsAfterOffset(arg),
        acceptWsAfterComma4 ? acceptWsAfterComma4(PRS_getAreaWsAfterComma4(arg)) : PRS_getAreaWsAfterComma4(arg),
        acceptLength ? acceptLength(PRS_getAreaLength(arg)) : PRS_getAreaLength(arg),
        acceptWsAfterLength ? acceptWsAfterLength(PRS_getAreaWsAfterLength(arg)) : PRS_getAreaWsAfterLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (PRS_Area)NULL;
}

/*}}}  */

/*}}}  */
