#ifndef _PARSEDRSTORE_H
#define _PARSEDRSTORE_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ParsedRStore_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _PRS_OptLayout *PRS_OptLayout;
typedef struct _PRS_Layout *PRS_Layout;
typedef struct _PRS_LexLayoutList *PRS_LexLayoutList;
typedef struct _PRS_RElem *PRS_RElem;
typedef struct _PRS_RType *PRS_RType;
typedef struct _PRS_RTuple *PRS_RTuple;
typedef struct _PRS_RStore *PRS_RStore;
typedef struct _PRS_Start *PRS_Start;
typedef struct _PRS_RElemList *PRS_RElemList;
typedef struct _PRS_RTypeList *PRS_RTypeList;
typedef struct _PRS_RTupleList *PRS_RTupleList;
typedef struct _PRS_LexStrChar *PRS_LexStrChar;
typedef struct _PRS_StrChar *PRS_StrChar;
typedef struct _PRS_LexStrCon *PRS_LexStrCon;
typedef struct _PRS_StrCon *PRS_StrCon;
typedef struct _PRS_LexStrCharChars *PRS_LexStrCharChars;
typedef struct _PRS_LexNatCon *PRS_LexNatCon;
typedef struct _PRS_NatCon *PRS_NatCon;
typedef struct _PRS_LexLayout *PRS_LexLayout;
typedef struct _PRS_Location *PRS_Location;
typedef struct _PRS_Area *PRS_Area;

/*}}}  */

void PRS_initParsedRStoreApi(void);

/*{{{  protect functions */

void PRS_protectOptLayout(PRS_OptLayout * arg);
void PRS_protectLayout(PRS_Layout * arg);
void PRS_protectLexLayoutList(PRS_LexLayoutList * arg);
void PRS_protectRElem(PRS_RElem * arg);
void PRS_protectRType(PRS_RType * arg);
void PRS_protectRTuple(PRS_RTuple * arg);
void PRS_protectRStore(PRS_RStore * arg);
void PRS_protectStart(PRS_Start * arg);
void PRS_protectRElemList(PRS_RElemList * arg);
void PRS_protectRTypeList(PRS_RTypeList * arg);
void PRS_protectRTupleList(PRS_RTupleList * arg);
void PRS_protectLexStrChar(PRS_LexStrChar * arg);
void PRS_protectStrChar(PRS_StrChar * arg);
void PRS_protectLexStrCon(PRS_LexStrCon * arg);
void PRS_protectStrCon(PRS_StrCon * arg);
void PRS_protectLexStrCharChars(PRS_LexStrCharChars * arg);
void PRS_protectLexNatCon(PRS_LexNatCon * arg);
void PRS_protectNatCon(PRS_NatCon * arg);
void PRS_protectLexLayout(PRS_LexLayout * arg);
void PRS_protectLocation(PRS_Location * arg);
void PRS_protectArea(PRS_Area * arg);

/*}}}  */
/*{{{  term conversion functions */

PRS_OptLayout PRS_OptLayoutFromTerm(ATerm t);
ATerm PRS_OptLayoutToTerm(PRS_OptLayout arg);
PRS_Layout PRS_LayoutFromTerm(ATerm t);
ATerm PRS_LayoutToTerm(PRS_Layout arg);
PRS_LexLayoutList PRS_LexLayoutListFromTerm(ATerm t);
ATerm PRS_LexLayoutListToTerm(PRS_LexLayoutList arg);
PRS_RElem PRS_RElemFromTerm(ATerm t);
ATerm PRS_RElemToTerm(PRS_RElem arg);
PRS_RType PRS_RTypeFromTerm(ATerm t);
ATerm PRS_RTypeToTerm(PRS_RType arg);
PRS_RTuple PRS_RTupleFromTerm(ATerm t);
ATerm PRS_RTupleToTerm(PRS_RTuple arg);
PRS_RStore PRS_RStoreFromTerm(ATerm t);
ATerm PRS_RStoreToTerm(PRS_RStore arg);
PRS_Start PRS_StartFromTerm(ATerm t);
ATerm PRS_StartToTerm(PRS_Start arg);
PRS_RElemList PRS_RElemListFromTerm(ATerm t);
ATerm PRS_RElemListToTerm(PRS_RElemList arg);
PRS_RTypeList PRS_RTypeListFromTerm(ATerm t);
ATerm PRS_RTypeListToTerm(PRS_RTypeList arg);
PRS_RTupleList PRS_RTupleListFromTerm(ATerm t);
ATerm PRS_RTupleListToTerm(PRS_RTupleList arg);
PRS_LexStrChar PRS_LexStrCharFromTerm(ATerm t);
ATerm PRS_LexStrCharToTerm(PRS_LexStrChar arg);
PRS_StrChar PRS_StrCharFromTerm(ATerm t);
ATerm PRS_StrCharToTerm(PRS_StrChar arg);
PRS_LexStrCon PRS_LexStrConFromTerm(ATerm t);
ATerm PRS_LexStrConToTerm(PRS_LexStrCon arg);
PRS_StrCon PRS_StrConFromTerm(ATerm t);
ATerm PRS_StrConToTerm(PRS_StrCon arg);
PRS_LexStrCharChars PRS_LexStrCharCharsFromTerm(ATerm t);
ATerm PRS_LexStrCharCharsToTerm(PRS_LexStrCharChars arg);
PRS_LexNatCon PRS_LexNatConFromTerm(ATerm t);
ATerm PRS_LexNatConToTerm(PRS_LexNatCon arg);
PRS_NatCon PRS_NatConFromTerm(ATerm t);
ATerm PRS_NatConToTerm(PRS_NatCon arg);
PRS_LexLayout PRS_LexLayoutFromTerm(ATerm t);
ATerm PRS_LexLayoutToTerm(PRS_LexLayout arg);
PRS_Location PRS_LocationFromTerm(ATerm t);
ATerm PRS_LocationToTerm(PRS_Location arg);
PRS_Area PRS_AreaFromTerm(ATerm t);
ATerm PRS_AreaToTerm(PRS_Area arg);

/*}}}  */
/*{{{  list functions */

int PRS_getLexLayoutListLength(PRS_LexLayoutList arg);
PRS_LexLayoutList PRS_reverseLexLayoutList(PRS_LexLayoutList arg);
PRS_LexLayoutList PRS_appendLexLayoutList(PRS_LexLayoutList arg,
					  PRS_LexLayout elem);
PRS_LexLayoutList PRS_concatLexLayoutList(PRS_LexLayoutList arg0,
					  PRS_LexLayoutList arg1);
PRS_LexLayoutList PRS_sliceLexLayoutList(PRS_LexLayoutList arg, int start,
					 int end);
PRS_LexLayout PRS_getLexLayoutListLexLayoutAt(PRS_LexLayoutList arg,
					      int index);
PRS_LexLayoutList PRS_replaceLexLayoutListLexLayoutAt(PRS_LexLayoutList arg,
						      PRS_LexLayout elem,
						      int index);
PRS_LexLayoutList PRS_makeLexLayoutList2(PRS_LexLayout elem1,
					 PRS_LexLayout elem2);
PRS_LexLayoutList PRS_makeLexLayoutList3(PRS_LexLayout elem1,
					 PRS_LexLayout elem2,
					 PRS_LexLayout elem3);
PRS_LexLayoutList PRS_makeLexLayoutList4(PRS_LexLayout elem1,
					 PRS_LexLayout elem2,
					 PRS_LexLayout elem3,
					 PRS_LexLayout elem4);
PRS_LexLayoutList PRS_makeLexLayoutList5(PRS_LexLayout elem1,
					 PRS_LexLayout elem2,
					 PRS_LexLayout elem3,
					 PRS_LexLayout elem4,
					 PRS_LexLayout elem5);
PRS_LexLayoutList PRS_makeLexLayoutList6(PRS_LexLayout elem1,
					 PRS_LexLayout elem2,
					 PRS_LexLayout elem3,
					 PRS_LexLayout elem4,
					 PRS_LexLayout elem5,
					 PRS_LexLayout elem6);
int PRS_getRElemListLength(PRS_RElemList arg);
PRS_RElemList PRS_reverseRElemList(PRS_RElemList arg);
PRS_RElemList PRS_appendRElemList(PRS_RElemList arg0,
				  PRS_OptLayout wsAfterHead,
				  PRS_OptLayout wsAfterSep, PRS_RElem arg1);
PRS_RElemList PRS_concatRElemList(PRS_RElemList arg0,
				  PRS_OptLayout wsAfterHead,
				  PRS_OptLayout wsAfterSep,
				  PRS_RElemList arg1);
PRS_RElemList PRS_sliceRElemList(PRS_RElemList arg, int start, int end);
PRS_RElem PRS_getRElemListRElemAt(PRS_RElemList arg, int index);
PRS_RElemList PRS_replaceRElemListRElemAt(PRS_RElemList arg, PRS_RElem elem,
					  int index);
PRS_RElemList PRS_makeRElemList2(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RElem elem1,
				 PRS_RElem elem2);
PRS_RElemList PRS_makeRElemList3(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RElem elem1,
				 PRS_RElem elem2, PRS_RElem elem3);
PRS_RElemList PRS_makeRElemList4(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RElem elem1,
				 PRS_RElem elem2, PRS_RElem elem3,
				 PRS_RElem elem4);
PRS_RElemList PRS_makeRElemList5(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RElem elem1,
				 PRS_RElem elem2, PRS_RElem elem3,
				 PRS_RElem elem4, PRS_RElem elem5);
PRS_RElemList PRS_makeRElemList6(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RElem elem1,
				 PRS_RElem elem2, PRS_RElem elem3,
				 PRS_RElem elem4, PRS_RElem elem5,
				 PRS_RElem elem6);
int PRS_getRTypeListLength(PRS_RTypeList arg);
PRS_RTypeList PRS_reverseRTypeList(PRS_RTypeList arg);
PRS_RTypeList PRS_appendRTypeList(PRS_RTypeList arg0,
				  PRS_OptLayout wsAfterHead,
				  PRS_OptLayout wsAfterSep, PRS_RType arg1);
PRS_RTypeList PRS_concatRTypeList(PRS_RTypeList arg0,
				  PRS_OptLayout wsAfterHead,
				  PRS_OptLayout wsAfterSep,
				  PRS_RTypeList arg1);
PRS_RTypeList PRS_sliceRTypeList(PRS_RTypeList arg, int start, int end);
PRS_RType PRS_getRTypeListRTypeAt(PRS_RTypeList arg, int index);
PRS_RTypeList PRS_replaceRTypeListRTypeAt(PRS_RTypeList arg, PRS_RType elem,
					  int index);
PRS_RTypeList PRS_makeRTypeList2(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RType elem1,
				 PRS_RType elem2);
PRS_RTypeList PRS_makeRTypeList3(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RType elem1,
				 PRS_RType elem2, PRS_RType elem3);
PRS_RTypeList PRS_makeRTypeList4(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RType elem1,
				 PRS_RType elem2, PRS_RType elem3,
				 PRS_RType elem4);
PRS_RTypeList PRS_makeRTypeList5(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RType elem1,
				 PRS_RType elem2, PRS_RType elem3,
				 PRS_RType elem4, PRS_RType elem5);
PRS_RTypeList PRS_makeRTypeList6(PRS_OptLayout wsAfterHead,
				 PRS_OptLayout wsAfterSep, PRS_RType elem1,
				 PRS_RType elem2, PRS_RType elem3,
				 PRS_RType elem4, PRS_RType elem5,
				 PRS_RType elem6);
int PRS_getRTupleListLength(PRS_RTupleList arg);
PRS_RTupleList PRS_reverseRTupleList(PRS_RTupleList arg);
PRS_RTupleList PRS_appendRTupleList(PRS_RTupleList arg0,
				    PRS_OptLayout wsAfterHead,
				    PRS_OptLayout wsAfterSep,
				    PRS_RTuple arg1);
PRS_RTupleList PRS_concatRTupleList(PRS_RTupleList arg0,
				    PRS_OptLayout wsAfterHead,
				    PRS_OptLayout wsAfterSep,
				    PRS_RTupleList arg1);
PRS_RTupleList PRS_sliceRTupleList(PRS_RTupleList arg, int start, int end);
PRS_RTuple PRS_getRTupleListRTupleAt(PRS_RTupleList arg, int index);
PRS_RTupleList PRS_replaceRTupleListRTupleAt(PRS_RTupleList arg,
					     PRS_RTuple elem, int index);
PRS_RTupleList PRS_makeRTupleList2(PRS_OptLayout wsAfterHead,
				   PRS_OptLayout wsAfterSep, PRS_RTuple elem1,
				   PRS_RTuple elem2);
PRS_RTupleList PRS_makeRTupleList3(PRS_OptLayout wsAfterHead,
				   PRS_OptLayout wsAfterSep, PRS_RTuple elem1,
				   PRS_RTuple elem2, PRS_RTuple elem3);
PRS_RTupleList PRS_makeRTupleList4(PRS_OptLayout wsAfterHead,
				   PRS_OptLayout wsAfterSep, PRS_RTuple elem1,
				   PRS_RTuple elem2, PRS_RTuple elem3,
				   PRS_RTuple elem4);
PRS_RTupleList PRS_makeRTupleList5(PRS_OptLayout wsAfterHead,
				   PRS_OptLayout wsAfterSep, PRS_RTuple elem1,
				   PRS_RTuple elem2, PRS_RTuple elem3,
				   PRS_RTuple elem4, PRS_RTuple elem5);
PRS_RTupleList PRS_makeRTupleList6(PRS_OptLayout wsAfterHead,
				   PRS_OptLayout wsAfterSep, PRS_RTuple elem1,
				   PRS_RTuple elem2, PRS_RTuple elem3,
				   PRS_RTuple elem4, PRS_RTuple elem5,
				   PRS_RTuple elem6);
int PRS_getLexStrCharCharsLength(PRS_LexStrCharChars arg);
PRS_LexStrCharChars PRS_reverseLexStrCharChars(PRS_LexStrCharChars arg);
PRS_LexStrCharChars PRS_appendLexStrCharChars(PRS_LexStrCharChars arg,
					      PRS_LexStrChar elem);
PRS_LexStrCharChars PRS_concatLexStrCharChars(PRS_LexStrCharChars arg0,
					      PRS_LexStrCharChars arg1);
PRS_LexStrCharChars PRS_sliceLexStrCharChars(PRS_LexStrCharChars arg,
					     int start, int end);
PRS_LexStrChar PRS_getLexStrCharCharsLexStrCharAt(PRS_LexStrCharChars arg,
						  int index);
PRS_LexStrCharChars PRS_replaceLexStrCharCharsLexStrCharAt(PRS_LexStrCharChars
							   arg,
							   PRS_LexStrChar
							   elem, int index);
PRS_LexStrCharChars PRS_makeLexStrCharChars2(PRS_LexStrChar elem1,
					     PRS_LexStrChar elem2);
PRS_LexStrCharChars PRS_makeLexStrCharChars3(PRS_LexStrChar elem1,
					     PRS_LexStrChar elem2,
					     PRS_LexStrChar elem3);
PRS_LexStrCharChars PRS_makeLexStrCharChars4(PRS_LexStrChar elem1,
					     PRS_LexStrChar elem2,
					     PRS_LexStrChar elem3,
					     PRS_LexStrChar elem4);
PRS_LexStrCharChars PRS_makeLexStrCharChars5(PRS_LexStrChar elem1,
					     PRS_LexStrChar elem2,
					     PRS_LexStrChar elem3,
					     PRS_LexStrChar elem4,
					     PRS_LexStrChar elem5);
PRS_LexStrCharChars PRS_makeLexStrCharChars6(PRS_LexStrChar elem1,
					     PRS_LexStrChar elem2,
					     PRS_LexStrChar elem3,
					     PRS_LexStrChar elem4,
					     PRS_LexStrChar elem5,
					     PRS_LexStrChar elem6);

/*}}}  */
/*{{{  constructors */

PRS_OptLayout PRS_makeOptLayoutAbsent(void);
PRS_OptLayout PRS_makeOptLayoutPresent(PRS_Layout layout);
PRS_Layout PRS_makeLayoutLexToCf(PRS_LexLayoutList list);
PRS_LexLayoutList PRS_makeLexLayoutListEmpty(void);
PRS_LexLayoutList PRS_makeLexLayoutListSingle(PRS_LexLayout head);
PRS_LexLayoutList PRS_makeLexLayoutListMany(PRS_LexLayout head,
					    PRS_LexLayoutList tail);
PRS_RElem PRS_makeRElemInteger(PRS_OptLayout wsAfterInt,
			       PRS_OptLayout wsAfterParenOpen,
			       PRS_NatCon intValue,
			       PRS_OptLayout wsAfterIntValue);
PRS_RElem PRS_makeRElemString(PRS_OptLayout wsAfterStr,
			      PRS_OptLayout wsAfterParenOpen,
			      PRS_StrCon strValue,
			      PRS_OptLayout wsAfterStrValue);
PRS_RElem PRS_makeRElemLocation(PRS_OptLayout wsAfterLoc,
				PRS_OptLayout wsAfterParenOpen,
				PRS_Location locValue,
				PRS_OptLayout wsAfterLocValue);
PRS_RElem PRS_makeRElemSet(PRS_OptLayout wsAfterSet,
			   PRS_OptLayout wsAfterParenOpen,
			   PRS_OptLayout wsAfterBracketOpen,
			   PRS_RElemList list, PRS_OptLayout wsAfterList,
			   PRS_OptLayout wsAfterBracketClose);
PRS_RElem PRS_makeRElemBag(PRS_OptLayout wsAfterBag,
			   PRS_OptLayout wsAfterParenOpen,
			   PRS_OptLayout wsAfterBracketOpen,
			   PRS_RElemList list, PRS_OptLayout wsAfterList,
			   PRS_OptLayout wsAfterBracketClose);
PRS_RElem PRS_makeRElemTuple(PRS_OptLayout wsAfterTuple,
			     PRS_OptLayout wsAfterParenOpen,
			     PRS_OptLayout wsAfterBracketOpen,
			     PRS_RElemList list, PRS_OptLayout wsAfterList,
			     PRS_OptLayout wsAfterBracketClose);
PRS_RType PRS_makeRTypeInteger(void);
PRS_RType PRS_makeRTypeString(void);
PRS_RType PRS_makeRTypeLocation(void);
PRS_RType PRS_makeRTypeTuple(PRS_OptLayout wsAfterTuple,
			     PRS_OptLayout wsAfterParenOpen,
			     PRS_OptLayout wsAfterBracketOpen,
			     PRS_RTypeList list, PRS_OptLayout wsAfterList,
			     PRS_OptLayout wsAfterBracketClose);
PRS_RType PRS_makeRTypeSet(PRS_OptLayout wsAfterSet,
			   PRS_OptLayout wsAfterParenOpen, PRS_RType RType,
			   PRS_OptLayout wsAfterRType);
PRS_RType PRS_makeRTypeBag(PRS_OptLayout wsAfterBag,
			   PRS_OptLayout wsAfterParenOpen, PRS_RType RType,
			   PRS_OptLayout wsAfterRType);
PRS_RType PRS_makeRTypeRel(PRS_OptLayout wsAfterRel,
			   PRS_OptLayout wsAfterParenOpen,
			   PRS_OptLayout wsAfterBracketOpen,
			   PRS_RTypeList list, PRS_OptLayout wsAfterList,
			   PRS_OptLayout wsAfterBracketClose);
PRS_RType PRS_makeRTypeUser(PRS_OptLayout wsAfterUser,
			    PRS_OptLayout wsAfterParenOpen, PRS_StrCon StrCon,
			    PRS_OptLayout wsAfterStrCon);
PRS_RType PRS_makeRTypeParameter(PRS_OptLayout wsAfterParameter,
				 PRS_OptLayout wsAfterParenOpen,
				 PRS_StrCon StrCon,
				 PRS_OptLayout wsAfterStrCon);
PRS_RTuple PRS_makeRTupleRtuple(PRS_OptLayout wsAfterRtuple,
				PRS_OptLayout wsAfterParenOpen, PRS_StrCon id,
				PRS_OptLayout wsAfterId,
				PRS_OptLayout wsAfterComma, PRS_RType rtype,
				PRS_OptLayout wsAfterRtype,
				PRS_OptLayout wsAfterComma1, PRS_RElem data,
				PRS_OptLayout wsAfterData);
PRS_RStore PRS_makeRStoreRstore(PRS_OptLayout wsAfterRstore,
				PRS_OptLayout wsAfterParenOpen,
				PRS_OptLayout wsAfterBracketOpen,
				PRS_RTupleList list,
				PRS_OptLayout wsAfterList,
				PRS_OptLayout wsAfterBracketClose);
PRS_Start PRS_makeStartRStore(PRS_OptLayout wsBefore, PRS_RStore topRStore,
			      PRS_OptLayout wsAfter, int ambCnt);
PRS_RElemList PRS_makeRElemListEmpty(void);
PRS_RElemList PRS_makeRElemListSingle(PRS_RElem head);
PRS_RElemList PRS_makeRElemListMany(PRS_RElem head, PRS_OptLayout wsAfterHead,
				    PRS_OptLayout wsAfterSep,
				    PRS_RElemList tail);
PRS_RTypeList PRS_makeRTypeListEmpty(void);
PRS_RTypeList PRS_makeRTypeListSingle(PRS_RType head);
PRS_RTypeList PRS_makeRTypeListMany(PRS_RType head, PRS_OptLayout wsAfterHead,
				    PRS_OptLayout wsAfterSep,
				    PRS_RTypeList tail);
PRS_RTupleList PRS_makeRTupleListEmpty(void);
PRS_RTupleList PRS_makeRTupleListSingle(PRS_RTuple head);
PRS_RTupleList PRS_makeRTupleListMany(PRS_RTuple head,
				      PRS_OptLayout wsAfterHead,
				      PRS_OptLayout wsAfterSep,
				      PRS_RTupleList tail);
PRS_LexStrChar PRS_makeLexStrCharNewline(void);
PRS_LexStrChar PRS_makeLexStrCharTab(void);
PRS_LexStrChar PRS_makeLexStrCharQuote(void);
PRS_LexStrChar PRS_makeLexStrCharBackslash(void);
PRS_LexStrChar PRS_makeLexStrCharDecimal(char a, char b, char c);
PRS_LexStrChar PRS_makeLexStrCharNormal(char ch);
PRS_StrChar PRS_makeStrCharLexToCf(PRS_LexStrChar StrChar);
PRS_LexStrCon PRS_makeLexStrConDefault(PRS_LexStrCharChars chars);
PRS_StrCon PRS_makeStrConLexToCf(PRS_LexStrCon StrCon);
PRS_LexStrCharChars PRS_makeLexStrCharCharsEmpty(void);
PRS_LexStrCharChars PRS_makeLexStrCharCharsSingle(PRS_LexStrChar head);
PRS_LexStrCharChars PRS_makeLexStrCharCharsMany(PRS_LexStrChar head,
						PRS_LexStrCharChars tail);
PRS_LexNatCon PRS_makeLexNatConDigits(const char *list);
PRS_NatCon PRS_makeNatConLexToCf(PRS_LexNatCon NatCon);
PRS_LexLayout PRS_makeLexLayoutWhitespace(char ch);
PRS_Location PRS_makeLocationFile(PRS_OptLayout wsAfterFile,
				  PRS_OptLayout wsAfterParenOpen,
				  PRS_StrCon filename,
				  PRS_OptLayout wsAfterFilename);
PRS_Location PRS_makeLocationArea(PRS_OptLayout wsAfterA,
				  PRS_OptLayout wsAfterParenOpen,
				  PRS_Area Area, PRS_OptLayout wsAfterArea);
PRS_Location PRS_makeLocationAreaInFile(PRS_OptLayout wsAfterAreaInFile,
					PRS_OptLayout wsAfterParenOpen,
					PRS_StrCon filename,
					PRS_OptLayout wsAfterFilename,
					PRS_OptLayout wsAfterComma,
					PRS_Area Area,
					PRS_OptLayout wsAfterArea);
PRS_Area PRS_makeAreaArea(PRS_OptLayout wsAfterArea,
			  PRS_OptLayout wsAfterParenOpen,
			  PRS_NatCon beginLine,
			  PRS_OptLayout wsAfterBeginLine,
			  PRS_OptLayout wsAfterComma, PRS_NatCon beginColumn,
			  PRS_OptLayout wsAfterBeginColumn,
			  PRS_OptLayout wsAfterComma1, PRS_NatCon endLine,
			  PRS_OptLayout wsAfterEndLine,
			  PRS_OptLayout wsAfterComma2, PRS_NatCon endColumn,
			  PRS_OptLayout wsAfterEndColumn,
			  PRS_OptLayout wsAfterComma3, PRS_NatCon offset,
			  PRS_OptLayout wsAfterOffset,
			  PRS_OptLayout wsAfterComma4, PRS_NatCon length,
			  PRS_OptLayout wsAfterLength);

/*}}}  */
/*{{{  equality functions */

ATbool PRS_isEqualOptLayout(PRS_OptLayout arg0, PRS_OptLayout arg1);
ATbool PRS_isEqualLayout(PRS_Layout arg0, PRS_Layout arg1);
ATbool PRS_isEqualLexLayoutList(PRS_LexLayoutList arg0,
				PRS_LexLayoutList arg1);
ATbool PRS_isEqualRElem(PRS_RElem arg0, PRS_RElem arg1);
ATbool PRS_isEqualRType(PRS_RType arg0, PRS_RType arg1);
ATbool PRS_isEqualRTuple(PRS_RTuple arg0, PRS_RTuple arg1);
ATbool PRS_isEqualRStore(PRS_RStore arg0, PRS_RStore arg1);
ATbool PRS_isEqualStart(PRS_Start arg0, PRS_Start arg1);
ATbool PRS_isEqualRElemList(PRS_RElemList arg0, PRS_RElemList arg1);
ATbool PRS_isEqualRTypeList(PRS_RTypeList arg0, PRS_RTypeList arg1);
ATbool PRS_isEqualRTupleList(PRS_RTupleList arg0, PRS_RTupleList arg1);
ATbool PRS_isEqualLexStrChar(PRS_LexStrChar arg0, PRS_LexStrChar arg1);
ATbool PRS_isEqualStrChar(PRS_StrChar arg0, PRS_StrChar arg1);
ATbool PRS_isEqualLexStrCon(PRS_LexStrCon arg0, PRS_LexStrCon arg1);
ATbool PRS_isEqualStrCon(PRS_StrCon arg0, PRS_StrCon arg1);
ATbool PRS_isEqualLexStrCharChars(PRS_LexStrCharChars arg0,
				  PRS_LexStrCharChars arg1);
ATbool PRS_isEqualLexNatCon(PRS_LexNatCon arg0, PRS_LexNatCon arg1);
ATbool PRS_isEqualNatCon(PRS_NatCon arg0, PRS_NatCon arg1);
ATbool PRS_isEqualLexLayout(PRS_LexLayout arg0, PRS_LexLayout arg1);
ATbool PRS_isEqualLocation(PRS_Location arg0, PRS_Location arg1);
ATbool PRS_isEqualArea(PRS_Area arg0, PRS_Area arg1);

/*}}}  */
/*{{{  PRS_OptLayout accessors */

ATbool PRS_isValidOptLayout(PRS_OptLayout arg);
inline ATbool PRS_isOptLayoutAbsent(PRS_OptLayout arg);
inline ATbool PRS_isOptLayoutPresent(PRS_OptLayout arg);
ATbool PRS_hasOptLayoutLayout(PRS_OptLayout arg);
PRS_Layout PRS_getOptLayoutLayout(PRS_OptLayout arg);
PRS_OptLayout PRS_setOptLayoutLayout(PRS_OptLayout arg, PRS_Layout layout);

/*}}}  */
/*{{{  PRS_Layout accessors */

ATbool PRS_isValidLayout(PRS_Layout arg);
inline ATbool PRS_isLayoutLexToCf(PRS_Layout arg);
ATbool PRS_hasLayoutList(PRS_Layout arg);
PRS_LexLayoutList PRS_getLayoutList(PRS_Layout arg);
PRS_Layout PRS_setLayoutList(PRS_Layout arg, PRS_LexLayoutList list);

/*}}}  */
/*{{{  PRS_LexLayoutList accessors */

ATbool PRS_isValidLexLayoutList(PRS_LexLayoutList arg);
inline ATbool PRS_isLexLayoutListEmpty(PRS_LexLayoutList arg);
inline ATbool PRS_isLexLayoutListSingle(PRS_LexLayoutList arg);
inline ATbool PRS_isLexLayoutListMany(PRS_LexLayoutList arg);
ATbool PRS_hasLexLayoutListHead(PRS_LexLayoutList arg);
ATbool PRS_hasLexLayoutListTail(PRS_LexLayoutList arg);
PRS_LexLayout PRS_getLexLayoutListHead(PRS_LexLayoutList arg);
PRS_LexLayoutList PRS_getLexLayoutListTail(PRS_LexLayoutList arg);
PRS_LexLayoutList PRS_setLexLayoutListHead(PRS_LexLayoutList arg,
					   PRS_LexLayout head);
PRS_LexLayoutList PRS_setLexLayoutListTail(PRS_LexLayoutList arg,
					   PRS_LexLayoutList tail);

/*}}}  */
/*{{{  PRS_RElem accessors */

ATbool PRS_isValidRElem(PRS_RElem arg);
inline ATbool PRS_isRElemInteger(PRS_RElem arg);
inline ATbool PRS_isRElemString(PRS_RElem arg);
inline ATbool PRS_isRElemLocation(PRS_RElem arg);
inline ATbool PRS_isRElemSet(PRS_RElem arg);
inline ATbool PRS_isRElemBag(PRS_RElem arg);
inline ATbool PRS_isRElemTuple(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterInt(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterParenOpen(PRS_RElem arg);
ATbool PRS_hasRElemIntValue(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterIntValue(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterStr(PRS_RElem arg);
ATbool PRS_hasRElemStrValue(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterStrValue(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterLoc(PRS_RElem arg);
ATbool PRS_hasRElemLocValue(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterLocValue(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterSet(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterBracketOpen(PRS_RElem arg);
ATbool PRS_hasRElemList(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterList(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterBracketClose(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterBag(PRS_RElem arg);
ATbool PRS_hasRElemWsAfterTuple(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterInt(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterParenOpen(PRS_RElem arg);
PRS_NatCon PRS_getRElemIntValue(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterIntValue(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterStr(PRS_RElem arg);
PRS_StrCon PRS_getRElemStrValue(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterStrValue(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterLoc(PRS_RElem arg);
PRS_Location PRS_getRElemLocValue(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterLocValue(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterSet(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterBracketOpen(PRS_RElem arg);
PRS_RElemList PRS_getRElemList(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterList(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterBracketClose(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterBag(PRS_RElem arg);
PRS_OptLayout PRS_getRElemWsAfterTuple(PRS_RElem arg);
PRS_RElem PRS_setRElemWsAfterInt(PRS_RElem arg, PRS_OptLayout wsAfterInt);
PRS_RElem PRS_setRElemWsAfterParenOpen(PRS_RElem arg,
				       PRS_OptLayout wsAfterParenOpen);
PRS_RElem PRS_setRElemIntValue(PRS_RElem arg, PRS_NatCon intValue);
PRS_RElem PRS_setRElemWsAfterIntValue(PRS_RElem arg,
				      PRS_OptLayout wsAfterIntValue);
PRS_RElem PRS_setRElemWsAfterStr(PRS_RElem arg, PRS_OptLayout wsAfterStr);
PRS_RElem PRS_setRElemStrValue(PRS_RElem arg, PRS_StrCon strValue);
PRS_RElem PRS_setRElemWsAfterStrValue(PRS_RElem arg,
				      PRS_OptLayout wsAfterStrValue);
PRS_RElem PRS_setRElemWsAfterLoc(PRS_RElem arg, PRS_OptLayout wsAfterLoc);
PRS_RElem PRS_setRElemLocValue(PRS_RElem arg, PRS_Location locValue);
PRS_RElem PRS_setRElemWsAfterLocValue(PRS_RElem arg,
				      PRS_OptLayout wsAfterLocValue);
PRS_RElem PRS_setRElemWsAfterSet(PRS_RElem arg, PRS_OptLayout wsAfterSet);
PRS_RElem PRS_setRElemWsAfterBracketOpen(PRS_RElem arg,
					 PRS_OptLayout wsAfterBracketOpen);
PRS_RElem PRS_setRElemList(PRS_RElem arg, PRS_RElemList list);
PRS_RElem PRS_setRElemWsAfterList(PRS_RElem arg, PRS_OptLayout wsAfterList);
PRS_RElem PRS_setRElemWsAfterBracketClose(PRS_RElem arg,
					  PRS_OptLayout wsAfterBracketClose);
PRS_RElem PRS_setRElemWsAfterBag(PRS_RElem arg, PRS_OptLayout wsAfterBag);
PRS_RElem PRS_setRElemWsAfterTuple(PRS_RElem arg, PRS_OptLayout wsAfterTuple);

/*}}}  */
/*{{{  PRS_RType accessors */

ATbool PRS_isValidRType(PRS_RType arg);
inline ATbool PRS_isRTypeInteger(PRS_RType arg);
inline ATbool PRS_isRTypeString(PRS_RType arg);
inline ATbool PRS_isRTypeLocation(PRS_RType arg);
inline ATbool PRS_isRTypeTuple(PRS_RType arg);
inline ATbool PRS_isRTypeSet(PRS_RType arg);
inline ATbool PRS_isRTypeBag(PRS_RType arg);
inline ATbool PRS_isRTypeRel(PRS_RType arg);
inline ATbool PRS_isRTypeUser(PRS_RType arg);
inline ATbool PRS_isRTypeParameter(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterTuple(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterParenOpen(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterBracketOpen(PRS_RType arg);
ATbool PRS_hasRTypeList(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterList(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterBracketClose(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterSet(PRS_RType arg);
ATbool PRS_hasRTypeRType(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterRType(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterBag(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterRel(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterUser(PRS_RType arg);
ATbool PRS_hasRTypeStrCon(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterStrCon(PRS_RType arg);
ATbool PRS_hasRTypeWsAfterParameter(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterTuple(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterParenOpen(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterBracketOpen(PRS_RType arg);
PRS_RTypeList PRS_getRTypeList(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterList(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterBracketClose(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterSet(PRS_RType arg);
PRS_RType PRS_getRTypeRType(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterRType(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterBag(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterRel(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterUser(PRS_RType arg);
PRS_StrCon PRS_getRTypeStrCon(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterStrCon(PRS_RType arg);
PRS_OptLayout PRS_getRTypeWsAfterParameter(PRS_RType arg);
PRS_RType PRS_setRTypeWsAfterTuple(PRS_RType arg, PRS_OptLayout wsAfterTuple);
PRS_RType PRS_setRTypeWsAfterParenOpen(PRS_RType arg,
				       PRS_OptLayout wsAfterParenOpen);
PRS_RType PRS_setRTypeWsAfterBracketOpen(PRS_RType arg,
					 PRS_OptLayout wsAfterBracketOpen);
PRS_RType PRS_setRTypeList(PRS_RType arg, PRS_RTypeList list);
PRS_RType PRS_setRTypeWsAfterList(PRS_RType arg, PRS_OptLayout wsAfterList);
PRS_RType PRS_setRTypeWsAfterBracketClose(PRS_RType arg,
					  PRS_OptLayout wsAfterBracketClose);
PRS_RType PRS_setRTypeWsAfterSet(PRS_RType arg, PRS_OptLayout wsAfterSet);
PRS_RType PRS_setRTypeRType(PRS_RType arg, PRS_RType RType);
PRS_RType PRS_setRTypeWsAfterRType(PRS_RType arg, PRS_OptLayout wsAfterRType);
PRS_RType PRS_setRTypeWsAfterBag(PRS_RType arg, PRS_OptLayout wsAfterBag);
PRS_RType PRS_setRTypeWsAfterRel(PRS_RType arg, PRS_OptLayout wsAfterRel);
PRS_RType PRS_setRTypeWsAfterUser(PRS_RType arg, PRS_OptLayout wsAfterUser);
PRS_RType PRS_setRTypeStrCon(PRS_RType arg, PRS_StrCon StrCon);
PRS_RType PRS_setRTypeWsAfterStrCon(PRS_RType arg,
				    PRS_OptLayout wsAfterStrCon);
PRS_RType PRS_setRTypeWsAfterParameter(PRS_RType arg,
				       PRS_OptLayout wsAfterParameter);

/*}}}  */
/*{{{  PRS_RTuple accessors */

ATbool PRS_isValidRTuple(PRS_RTuple arg);
inline ATbool PRS_isRTupleRtuple(PRS_RTuple arg);
ATbool PRS_hasRTupleWsAfterRtuple(PRS_RTuple arg);
ATbool PRS_hasRTupleWsAfterParenOpen(PRS_RTuple arg);
ATbool PRS_hasRTupleId(PRS_RTuple arg);
ATbool PRS_hasRTupleWsAfterId(PRS_RTuple arg);
ATbool PRS_hasRTupleWsAfterComma(PRS_RTuple arg);
ATbool PRS_hasRTupleRtype(PRS_RTuple arg);
ATbool PRS_hasRTupleWsAfterRtype(PRS_RTuple arg);
ATbool PRS_hasRTupleWsAfterComma1(PRS_RTuple arg);
ATbool PRS_hasRTupleData(PRS_RTuple arg);
ATbool PRS_hasRTupleWsAfterData(PRS_RTuple arg);
PRS_OptLayout PRS_getRTupleWsAfterRtuple(PRS_RTuple arg);
PRS_OptLayout PRS_getRTupleWsAfterParenOpen(PRS_RTuple arg);
PRS_StrCon PRS_getRTupleId(PRS_RTuple arg);
PRS_OptLayout PRS_getRTupleWsAfterId(PRS_RTuple arg);
PRS_OptLayout PRS_getRTupleWsAfterComma(PRS_RTuple arg);
PRS_RType PRS_getRTupleRtype(PRS_RTuple arg);
PRS_OptLayout PRS_getRTupleWsAfterRtype(PRS_RTuple arg);
PRS_OptLayout PRS_getRTupleWsAfterComma1(PRS_RTuple arg);
PRS_RElem PRS_getRTupleData(PRS_RTuple arg);
PRS_OptLayout PRS_getRTupleWsAfterData(PRS_RTuple arg);
PRS_RTuple PRS_setRTupleWsAfterRtuple(PRS_RTuple arg,
				      PRS_OptLayout wsAfterRtuple);
PRS_RTuple PRS_setRTupleWsAfterParenOpen(PRS_RTuple arg,
					 PRS_OptLayout wsAfterParenOpen);
PRS_RTuple PRS_setRTupleId(PRS_RTuple arg, PRS_StrCon id);
PRS_RTuple PRS_setRTupleWsAfterId(PRS_RTuple arg, PRS_OptLayout wsAfterId);
PRS_RTuple PRS_setRTupleWsAfterComma(PRS_RTuple arg,
				     PRS_OptLayout wsAfterComma);
PRS_RTuple PRS_setRTupleRtype(PRS_RTuple arg, PRS_RType rtype);
PRS_RTuple PRS_setRTupleWsAfterRtype(PRS_RTuple arg,
				     PRS_OptLayout wsAfterRtype);
PRS_RTuple PRS_setRTupleWsAfterComma1(PRS_RTuple arg,
				      PRS_OptLayout wsAfterComma1);
PRS_RTuple PRS_setRTupleData(PRS_RTuple arg, PRS_RElem data);
PRS_RTuple PRS_setRTupleWsAfterData(PRS_RTuple arg,
				    PRS_OptLayout wsAfterData);

/*}}}  */
/*{{{  PRS_RStore accessors */

ATbool PRS_isValidRStore(PRS_RStore arg);
inline ATbool PRS_isRStoreRstore(PRS_RStore arg);
ATbool PRS_hasRStoreWsAfterRstore(PRS_RStore arg);
ATbool PRS_hasRStoreWsAfterParenOpen(PRS_RStore arg);
ATbool PRS_hasRStoreWsAfterBracketOpen(PRS_RStore arg);
ATbool PRS_hasRStoreList(PRS_RStore arg);
ATbool PRS_hasRStoreWsAfterList(PRS_RStore arg);
ATbool PRS_hasRStoreWsAfterBracketClose(PRS_RStore arg);
PRS_OptLayout PRS_getRStoreWsAfterRstore(PRS_RStore arg);
PRS_OptLayout PRS_getRStoreWsAfterParenOpen(PRS_RStore arg);
PRS_OptLayout PRS_getRStoreWsAfterBracketOpen(PRS_RStore arg);
PRS_RTupleList PRS_getRStoreList(PRS_RStore arg);
PRS_OptLayout PRS_getRStoreWsAfterList(PRS_RStore arg);
PRS_OptLayout PRS_getRStoreWsAfterBracketClose(PRS_RStore arg);
PRS_RStore PRS_setRStoreWsAfterRstore(PRS_RStore arg,
				      PRS_OptLayout wsAfterRstore);
PRS_RStore PRS_setRStoreWsAfterParenOpen(PRS_RStore arg,
					 PRS_OptLayout wsAfterParenOpen);
PRS_RStore PRS_setRStoreWsAfterBracketOpen(PRS_RStore arg,
					   PRS_OptLayout wsAfterBracketOpen);
PRS_RStore PRS_setRStoreList(PRS_RStore arg, PRS_RTupleList list);
PRS_RStore PRS_setRStoreWsAfterList(PRS_RStore arg,
				    PRS_OptLayout wsAfterList);
PRS_RStore PRS_setRStoreWsAfterBracketClose(PRS_RStore arg,
					    PRS_OptLayout
					    wsAfterBracketClose);

/*}}}  */
/*{{{  PRS_Start accessors */

ATbool PRS_isValidStart(PRS_Start arg);
inline ATbool PRS_isStartRStore(PRS_Start arg);
ATbool PRS_hasStartWsBefore(PRS_Start arg);
ATbool PRS_hasStartTopRStore(PRS_Start arg);
ATbool PRS_hasStartWsAfter(PRS_Start arg);
ATbool PRS_hasStartAmbCnt(PRS_Start arg);
PRS_OptLayout PRS_getStartWsBefore(PRS_Start arg);
PRS_RStore PRS_getStartTopRStore(PRS_Start arg);
PRS_OptLayout PRS_getStartWsAfter(PRS_Start arg);
int PRS_getStartAmbCnt(PRS_Start arg);
PRS_Start PRS_setStartWsBefore(PRS_Start arg, PRS_OptLayout wsBefore);
PRS_Start PRS_setStartTopRStore(PRS_Start arg, PRS_RStore topRStore);
PRS_Start PRS_setStartWsAfter(PRS_Start arg, PRS_OptLayout wsAfter);
PRS_Start PRS_setStartAmbCnt(PRS_Start arg, int ambCnt);

/*}}}  */
/*{{{  PRS_RElemList accessors */

ATbool PRS_isValidRElemList(PRS_RElemList arg);
inline ATbool PRS_isRElemListEmpty(PRS_RElemList arg);
inline ATbool PRS_isRElemListSingle(PRS_RElemList arg);
inline ATbool PRS_isRElemListMany(PRS_RElemList arg);
ATbool PRS_hasRElemListHead(PRS_RElemList arg);
ATbool PRS_hasRElemListWsAfterHead(PRS_RElemList arg);
ATbool PRS_hasRElemListWsAfterSep(PRS_RElemList arg);
ATbool PRS_hasRElemListTail(PRS_RElemList arg);
PRS_RElemList PRS_getRElemListTail(PRS_RElemList arg);
PRS_RElem PRS_getRElemListHead(PRS_RElemList arg);
PRS_OptLayout PRS_getRElemListWsAfterHead(PRS_RElemList arg);
PRS_OptLayout PRS_getRElemListWsAfterSep(PRS_RElemList arg);
PRS_RElemList PRS_setRElemListHead(PRS_RElemList arg, PRS_RElem head);
PRS_RElemList PRS_setRElemListWsAfterHead(PRS_RElemList arg,
					  PRS_OptLayout wsAfterHead);
PRS_RElemList PRS_setRElemListWsAfterSep(PRS_RElemList arg,
					 PRS_OptLayout wsAfterSep);
PRS_RElemList PRS_setRElemListTail(PRS_RElemList arg, PRS_RElemList tail);

/*}}}  */
/*{{{  PRS_RTypeList accessors */

ATbool PRS_isValidRTypeList(PRS_RTypeList arg);
inline ATbool PRS_isRTypeListEmpty(PRS_RTypeList arg);
inline ATbool PRS_isRTypeListSingle(PRS_RTypeList arg);
inline ATbool PRS_isRTypeListMany(PRS_RTypeList arg);
ATbool PRS_hasRTypeListHead(PRS_RTypeList arg);
ATbool PRS_hasRTypeListWsAfterHead(PRS_RTypeList arg);
ATbool PRS_hasRTypeListWsAfterSep(PRS_RTypeList arg);
ATbool PRS_hasRTypeListTail(PRS_RTypeList arg);
PRS_RTypeList PRS_getRTypeListTail(PRS_RTypeList arg);
PRS_RType PRS_getRTypeListHead(PRS_RTypeList arg);
PRS_OptLayout PRS_getRTypeListWsAfterHead(PRS_RTypeList arg);
PRS_OptLayout PRS_getRTypeListWsAfterSep(PRS_RTypeList arg);
PRS_RTypeList PRS_setRTypeListHead(PRS_RTypeList arg, PRS_RType head);
PRS_RTypeList PRS_setRTypeListWsAfterHead(PRS_RTypeList arg,
					  PRS_OptLayout wsAfterHead);
PRS_RTypeList PRS_setRTypeListWsAfterSep(PRS_RTypeList arg,
					 PRS_OptLayout wsAfterSep);
PRS_RTypeList PRS_setRTypeListTail(PRS_RTypeList arg, PRS_RTypeList tail);

/*}}}  */
/*{{{  PRS_RTupleList accessors */

ATbool PRS_isValidRTupleList(PRS_RTupleList arg);
inline ATbool PRS_isRTupleListEmpty(PRS_RTupleList arg);
inline ATbool PRS_isRTupleListSingle(PRS_RTupleList arg);
inline ATbool PRS_isRTupleListMany(PRS_RTupleList arg);
ATbool PRS_hasRTupleListHead(PRS_RTupleList arg);
ATbool PRS_hasRTupleListWsAfterHead(PRS_RTupleList arg);
ATbool PRS_hasRTupleListWsAfterSep(PRS_RTupleList arg);
ATbool PRS_hasRTupleListTail(PRS_RTupleList arg);
PRS_RTupleList PRS_getRTupleListTail(PRS_RTupleList arg);
PRS_RTuple PRS_getRTupleListHead(PRS_RTupleList arg);
PRS_OptLayout PRS_getRTupleListWsAfterHead(PRS_RTupleList arg);
PRS_OptLayout PRS_getRTupleListWsAfterSep(PRS_RTupleList arg);
PRS_RTupleList PRS_setRTupleListHead(PRS_RTupleList arg, PRS_RTuple head);
PRS_RTupleList PRS_setRTupleListWsAfterHead(PRS_RTupleList arg,
					    PRS_OptLayout wsAfterHead);
PRS_RTupleList PRS_setRTupleListWsAfterSep(PRS_RTupleList arg,
					   PRS_OptLayout wsAfterSep);
PRS_RTupleList PRS_setRTupleListTail(PRS_RTupleList arg, PRS_RTupleList tail);

/*}}}  */
/*{{{  PRS_LexStrChar accessors */

ATbool PRS_isValidLexStrChar(PRS_LexStrChar arg);
inline ATbool PRS_isLexStrCharNewline(PRS_LexStrChar arg);
inline ATbool PRS_isLexStrCharTab(PRS_LexStrChar arg);
inline ATbool PRS_isLexStrCharQuote(PRS_LexStrChar arg);
inline ATbool PRS_isLexStrCharBackslash(PRS_LexStrChar arg);
inline ATbool PRS_isLexStrCharDecimal(PRS_LexStrChar arg);
inline ATbool PRS_isLexStrCharNormal(PRS_LexStrChar arg);
ATbool PRS_hasLexStrCharA(PRS_LexStrChar arg);
ATbool PRS_hasLexStrCharB(PRS_LexStrChar arg);
ATbool PRS_hasLexStrCharC(PRS_LexStrChar arg);
ATbool PRS_hasLexStrCharCh(PRS_LexStrChar arg);
char PRS_getLexStrCharA(PRS_LexStrChar arg);
char PRS_getLexStrCharB(PRS_LexStrChar arg);
char PRS_getLexStrCharC(PRS_LexStrChar arg);
char PRS_getLexStrCharCh(PRS_LexStrChar arg);
PRS_LexStrChar PRS_setLexStrCharA(PRS_LexStrChar arg, char a);
PRS_LexStrChar PRS_setLexStrCharB(PRS_LexStrChar arg, char b);
PRS_LexStrChar PRS_setLexStrCharC(PRS_LexStrChar arg, char c);
PRS_LexStrChar PRS_setLexStrCharCh(PRS_LexStrChar arg, char ch);

/*}}}  */
/*{{{  PRS_StrChar accessors */

ATbool PRS_isValidStrChar(PRS_StrChar arg);
inline ATbool PRS_isStrCharLexToCf(PRS_StrChar arg);
ATbool PRS_hasStrCharStrChar(PRS_StrChar arg);
PRS_LexStrChar PRS_getStrCharStrChar(PRS_StrChar arg);
PRS_StrChar PRS_setStrCharStrChar(PRS_StrChar arg, PRS_LexStrChar StrChar);

/*}}}  */
/*{{{  PRS_LexStrCon accessors */

ATbool PRS_isValidLexStrCon(PRS_LexStrCon arg);
inline ATbool PRS_isLexStrConDefault(PRS_LexStrCon arg);
ATbool PRS_hasLexStrConChars(PRS_LexStrCon arg);
PRS_LexStrCharChars PRS_getLexStrConChars(PRS_LexStrCon arg);
PRS_LexStrCon PRS_setLexStrConChars(PRS_LexStrCon arg,
				    PRS_LexStrCharChars chars);

/*}}}  */
/*{{{  PRS_StrCon accessors */

ATbool PRS_isValidStrCon(PRS_StrCon arg);
inline ATbool PRS_isStrConLexToCf(PRS_StrCon arg);
ATbool PRS_hasStrConStrCon(PRS_StrCon arg);
PRS_LexStrCon PRS_getStrConStrCon(PRS_StrCon arg);
PRS_StrCon PRS_setStrConStrCon(PRS_StrCon arg, PRS_LexStrCon StrCon);

/*}}}  */
/*{{{  PRS_LexStrCharChars accessors */

ATbool PRS_isValidLexStrCharChars(PRS_LexStrCharChars arg);
inline ATbool PRS_isLexStrCharCharsEmpty(PRS_LexStrCharChars arg);
inline ATbool PRS_isLexStrCharCharsSingle(PRS_LexStrCharChars arg);
inline ATbool PRS_isLexStrCharCharsMany(PRS_LexStrCharChars arg);
ATbool PRS_hasLexStrCharCharsHead(PRS_LexStrCharChars arg);
ATbool PRS_hasLexStrCharCharsTail(PRS_LexStrCharChars arg);
PRS_LexStrChar PRS_getLexStrCharCharsHead(PRS_LexStrCharChars arg);
PRS_LexStrCharChars PRS_getLexStrCharCharsTail(PRS_LexStrCharChars arg);
PRS_LexStrCharChars PRS_setLexStrCharCharsHead(PRS_LexStrCharChars arg,
					       PRS_LexStrChar head);
PRS_LexStrCharChars PRS_setLexStrCharCharsTail(PRS_LexStrCharChars arg,
					       PRS_LexStrCharChars tail);

/*}}}  */
/*{{{  PRS_LexNatCon accessors */

ATbool PRS_isValidLexNatCon(PRS_LexNatCon arg);
inline ATbool PRS_isLexNatConDigits(PRS_LexNatCon arg);
ATbool PRS_hasLexNatConList(PRS_LexNatCon arg);
char *PRS_getLexNatConList(PRS_LexNatCon arg);
PRS_LexNatCon PRS_setLexNatConList(PRS_LexNatCon arg, const char *list);

/*}}}  */
/*{{{  PRS_NatCon accessors */

ATbool PRS_isValidNatCon(PRS_NatCon arg);
inline ATbool PRS_isNatConLexToCf(PRS_NatCon arg);
ATbool PRS_hasNatConNatCon(PRS_NatCon arg);
PRS_LexNatCon PRS_getNatConNatCon(PRS_NatCon arg);
PRS_NatCon PRS_setNatConNatCon(PRS_NatCon arg, PRS_LexNatCon NatCon);

/*}}}  */
/*{{{  PRS_LexLayout accessors */

ATbool PRS_isValidLexLayout(PRS_LexLayout arg);
inline ATbool PRS_isLexLayoutWhitespace(PRS_LexLayout arg);
ATbool PRS_hasLexLayoutCh(PRS_LexLayout arg);
char PRS_getLexLayoutCh(PRS_LexLayout arg);
PRS_LexLayout PRS_setLexLayoutCh(PRS_LexLayout arg, char ch);

/*}}}  */
/*{{{  PRS_Location accessors */

ATbool PRS_isValidLocation(PRS_Location arg);
inline ATbool PRS_isLocationFile(PRS_Location arg);
inline ATbool PRS_isLocationArea(PRS_Location arg);
inline ATbool PRS_isLocationAreaInFile(PRS_Location arg);
ATbool PRS_hasLocationWsAfterFile(PRS_Location arg);
ATbool PRS_hasLocationWsAfterParenOpen(PRS_Location arg);
ATbool PRS_hasLocationFilename(PRS_Location arg);
ATbool PRS_hasLocationWsAfterFilename(PRS_Location arg);
ATbool PRS_hasLocationWsAfterA(PRS_Location arg);
ATbool PRS_hasLocationArea(PRS_Location arg);
ATbool PRS_hasLocationWsAfterArea(PRS_Location arg);
ATbool PRS_hasLocationWsAfterAreaInFile(PRS_Location arg);
ATbool PRS_hasLocationWsAfterComma(PRS_Location arg);
PRS_OptLayout PRS_getLocationWsAfterFile(PRS_Location arg);
PRS_OptLayout PRS_getLocationWsAfterParenOpen(PRS_Location arg);
PRS_StrCon PRS_getLocationFilename(PRS_Location arg);
PRS_OptLayout PRS_getLocationWsAfterFilename(PRS_Location arg);
PRS_OptLayout PRS_getLocationWsAfterA(PRS_Location arg);
PRS_Area PRS_getLocationArea(PRS_Location arg);
PRS_OptLayout PRS_getLocationWsAfterArea(PRS_Location arg);
PRS_OptLayout PRS_getLocationWsAfterAreaInFile(PRS_Location arg);
PRS_OptLayout PRS_getLocationWsAfterComma(PRS_Location arg);
PRS_Location PRS_setLocationWsAfterFile(PRS_Location arg,
					PRS_OptLayout wsAfterFile);
PRS_Location PRS_setLocationWsAfterParenOpen(PRS_Location arg,
					     PRS_OptLayout wsAfterParenOpen);
PRS_Location PRS_setLocationFilename(PRS_Location arg, PRS_StrCon filename);
PRS_Location PRS_setLocationWsAfterFilename(PRS_Location arg,
					    PRS_OptLayout wsAfterFilename);
PRS_Location PRS_setLocationWsAfterA(PRS_Location arg,
				     PRS_OptLayout wsAfterA);
PRS_Location PRS_setLocationArea(PRS_Location arg, PRS_Area Area);
PRS_Location PRS_setLocationWsAfterArea(PRS_Location arg,
					PRS_OptLayout wsAfterArea);
PRS_Location PRS_setLocationWsAfterAreaInFile(PRS_Location arg,
					      PRS_OptLayout
					      wsAfterAreaInFile);
PRS_Location PRS_setLocationWsAfterComma(PRS_Location arg,
					 PRS_OptLayout wsAfterComma);

/*}}}  */
/*{{{  PRS_Area accessors */

ATbool PRS_isValidArea(PRS_Area arg);
inline ATbool PRS_isAreaArea(PRS_Area arg);
ATbool PRS_hasAreaWsAfterArea(PRS_Area arg);
ATbool PRS_hasAreaWsAfterParenOpen(PRS_Area arg);
ATbool PRS_hasAreaBeginLine(PRS_Area arg);
ATbool PRS_hasAreaWsAfterBeginLine(PRS_Area arg);
ATbool PRS_hasAreaWsAfterComma(PRS_Area arg);
ATbool PRS_hasAreaBeginColumn(PRS_Area arg);
ATbool PRS_hasAreaWsAfterBeginColumn(PRS_Area arg);
ATbool PRS_hasAreaWsAfterComma1(PRS_Area arg);
ATbool PRS_hasAreaEndLine(PRS_Area arg);
ATbool PRS_hasAreaWsAfterEndLine(PRS_Area arg);
ATbool PRS_hasAreaWsAfterComma2(PRS_Area arg);
ATbool PRS_hasAreaEndColumn(PRS_Area arg);
ATbool PRS_hasAreaWsAfterEndColumn(PRS_Area arg);
ATbool PRS_hasAreaWsAfterComma3(PRS_Area arg);
ATbool PRS_hasAreaOffset(PRS_Area arg);
ATbool PRS_hasAreaWsAfterOffset(PRS_Area arg);
ATbool PRS_hasAreaWsAfterComma4(PRS_Area arg);
ATbool PRS_hasAreaLength(PRS_Area arg);
ATbool PRS_hasAreaWsAfterLength(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterArea(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterParenOpen(PRS_Area arg);
PRS_NatCon PRS_getAreaBeginLine(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterBeginLine(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterComma(PRS_Area arg);
PRS_NatCon PRS_getAreaBeginColumn(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterBeginColumn(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterComma1(PRS_Area arg);
PRS_NatCon PRS_getAreaEndLine(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterEndLine(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterComma2(PRS_Area arg);
PRS_NatCon PRS_getAreaEndColumn(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterEndColumn(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterComma3(PRS_Area arg);
PRS_NatCon PRS_getAreaOffset(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterOffset(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterComma4(PRS_Area arg);
PRS_NatCon PRS_getAreaLength(PRS_Area arg);
PRS_OptLayout PRS_getAreaWsAfterLength(PRS_Area arg);
PRS_Area PRS_setAreaWsAfterArea(PRS_Area arg, PRS_OptLayout wsAfterArea);
PRS_Area PRS_setAreaWsAfterParenOpen(PRS_Area arg,
				     PRS_OptLayout wsAfterParenOpen);
PRS_Area PRS_setAreaBeginLine(PRS_Area arg, PRS_NatCon beginLine);
PRS_Area PRS_setAreaWsAfterBeginLine(PRS_Area arg,
				     PRS_OptLayout wsAfterBeginLine);
PRS_Area PRS_setAreaWsAfterComma(PRS_Area arg, PRS_OptLayout wsAfterComma);
PRS_Area PRS_setAreaBeginColumn(PRS_Area arg, PRS_NatCon beginColumn);
PRS_Area PRS_setAreaWsAfterBeginColumn(PRS_Area arg,
				       PRS_OptLayout wsAfterBeginColumn);
PRS_Area PRS_setAreaWsAfterComma1(PRS_Area arg, PRS_OptLayout wsAfterComma1);
PRS_Area PRS_setAreaEndLine(PRS_Area arg, PRS_NatCon endLine);
PRS_Area PRS_setAreaWsAfterEndLine(PRS_Area arg,
				   PRS_OptLayout wsAfterEndLine);
PRS_Area PRS_setAreaWsAfterComma2(PRS_Area arg, PRS_OptLayout wsAfterComma2);
PRS_Area PRS_setAreaEndColumn(PRS_Area arg, PRS_NatCon endColumn);
PRS_Area PRS_setAreaWsAfterEndColumn(PRS_Area arg,
				     PRS_OptLayout wsAfterEndColumn);
PRS_Area PRS_setAreaWsAfterComma3(PRS_Area arg, PRS_OptLayout wsAfterComma3);
PRS_Area PRS_setAreaOffset(PRS_Area arg, PRS_NatCon offset);
PRS_Area PRS_setAreaWsAfterOffset(PRS_Area arg, PRS_OptLayout wsAfterOffset);
PRS_Area PRS_setAreaWsAfterComma4(PRS_Area arg, PRS_OptLayout wsAfterComma4);
PRS_Area PRS_setAreaLength(PRS_Area arg, PRS_NatCon length);
PRS_Area PRS_setAreaWsAfterLength(PRS_Area arg, PRS_OptLayout wsAfterLength);

/*}}}  */
/*{{{  sort visitors */

PRS_OptLayout PRS_visitOptLayout(PRS_OptLayout arg,
				 PRS_Layout(*acceptLayout) (PRS_Layout));
PRS_Layout PRS_visitLayout(PRS_Layout arg,
			   PRS_LexLayoutList(*acceptList)
			   (PRS_LexLayoutList));
PRS_LexLayoutList PRS_visitLexLayoutList(PRS_LexLayoutList arg,
					 PRS_LexLayout(*acceptHead)
					 (PRS_LexLayout));
PRS_RElem PRS_visitRElem(PRS_RElem arg,
			 PRS_OptLayout(*acceptWsAfterInt) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterParenOpen)
			 (PRS_OptLayout),
			 PRS_NatCon(*acceptIntValue) (PRS_NatCon),
			 PRS_OptLayout(*acceptWsAfterIntValue)
			 (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterStr) (PRS_OptLayout),
			 PRS_StrCon(*acceptStrValue) (PRS_StrCon),
			 PRS_OptLayout(*acceptWsAfterStrValue)
			 (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterLoc) (PRS_OptLayout),
			 PRS_Location(*acceptLocValue) (PRS_Location),
			 PRS_OptLayout(*acceptWsAfterLocValue)
			 (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterSet) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterBracketOpen)
			 (PRS_OptLayout),
			 PRS_RElemList(*acceptList) (PRS_RElemList),
			 PRS_OptLayout(*acceptWsAfterList) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterBracketClose)
			 (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterBag) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterTuple) (PRS_OptLayout));
PRS_RType PRS_visitRType(PRS_RType arg,
			 PRS_OptLayout(*acceptWsAfterTuple) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterParenOpen)
			 (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterBracketOpen)
			 (PRS_OptLayout),
			 PRS_RTypeList(*acceptList) (PRS_RTypeList),
			 PRS_OptLayout(*acceptWsAfterList) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterBracketClose)
			 (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterSet) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterRType) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterBag) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterRel) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterUser) (PRS_OptLayout),
			 PRS_StrCon(*acceptStrCon) (PRS_StrCon),
			 PRS_OptLayout(*acceptWsAfterStrCon) (PRS_OptLayout),
			 PRS_OptLayout(*acceptWsAfterParameter)
			 (PRS_OptLayout));
PRS_RTuple PRS_visitRTuple(PRS_RTuple arg,
			   PRS_OptLayout(*acceptWsAfterRtuple)
			   (PRS_OptLayout),
			   PRS_OptLayout(*acceptWsAfterParenOpen)
			   (PRS_OptLayout),
			   PRS_StrCon(*acceptId) (PRS_StrCon),
			   PRS_OptLayout(*acceptWsAfterId) (PRS_OptLayout),
			   PRS_OptLayout(*acceptWsAfterComma) (PRS_OptLayout),
			   PRS_RType(*acceptRtype) (PRS_RType),
			   PRS_OptLayout(*acceptWsAfterRtype) (PRS_OptLayout),
			   PRS_OptLayout(*acceptWsAfterComma1)
			   (PRS_OptLayout),
			   PRS_RElem(*acceptData) (PRS_RElem),
			   PRS_OptLayout(*acceptWsAfterData) (PRS_OptLayout));
PRS_RStore PRS_visitRStore(PRS_RStore arg,
			   PRS_OptLayout(*acceptWsAfterRstore)
			   (PRS_OptLayout),
			   PRS_OptLayout(*acceptWsAfterParenOpen)
			   (PRS_OptLayout),
			   PRS_OptLayout(*acceptWsAfterBracketOpen)
			   (PRS_OptLayout),
			   PRS_RTupleList(*acceptList) (PRS_RTupleList),
			   PRS_OptLayout(*acceptWsAfterList) (PRS_OptLayout),
			   PRS_OptLayout(*acceptWsAfterBracketClose)
			   (PRS_OptLayout));
PRS_Start PRS_visitStart(PRS_Start arg,
			 PRS_OptLayout(*acceptWsBefore) (PRS_OptLayout),
			 PRS_RStore(*acceptTopRStore) (PRS_RStore),
			 PRS_OptLayout(*acceptWsAfter) (PRS_OptLayout),
			 int (*acceptAmbCnt) (int));
PRS_RElemList PRS_visitRElemList(PRS_RElemList arg,
				 PRS_RElem(*acceptHead) (PRS_RElem),
				 PRS_OptLayout(*acceptWsAfterHead)
				 (PRS_OptLayout),
				 PRS_OptLayout(*acceptWsAfterSep)
				 (PRS_OptLayout));
PRS_RTypeList PRS_visitRTypeList(PRS_RTypeList arg,
				 PRS_RType(*acceptHead) (PRS_RType),
				 PRS_OptLayout(*acceptWsAfterHead)
				 (PRS_OptLayout),
				 PRS_OptLayout(*acceptWsAfterSep)
				 (PRS_OptLayout));
PRS_RTupleList PRS_visitRTupleList(PRS_RTupleList arg,
				   PRS_RTuple(*acceptHead) (PRS_RTuple),
				   PRS_OptLayout(*acceptWsAfterHead)
				   (PRS_OptLayout),
				   PRS_OptLayout(*acceptWsAfterSep)
				   (PRS_OptLayout));
PRS_LexStrChar PRS_visitLexStrChar(PRS_LexStrChar arg, char (*acceptA) (char),
				   char (*acceptB) (char),
				   char (*acceptC) (char),
				   char (*acceptCh) (char));
PRS_StrChar PRS_visitStrChar(PRS_StrChar arg,
			     PRS_LexStrChar(*acceptStrChar) (PRS_LexStrChar));
PRS_LexStrCon PRS_visitLexStrCon(PRS_LexStrCon arg,
				 PRS_LexStrCharChars(*acceptChars)
				 (PRS_LexStrCharChars));
PRS_StrCon PRS_visitStrCon(PRS_StrCon arg,
			   PRS_LexStrCon(*acceptStrCon) (PRS_LexStrCon));
PRS_LexStrCharChars PRS_visitLexStrCharChars(PRS_LexStrCharChars arg,
					     PRS_LexStrChar(*acceptHead)
					     (PRS_LexStrChar));
PRS_LexNatCon PRS_visitLexNatCon(PRS_LexNatCon arg,
				 char *(*acceptList) (char *));
PRS_NatCon PRS_visitNatCon(PRS_NatCon arg,
			   PRS_LexNatCon(*acceptNatCon) (PRS_LexNatCon));
PRS_LexLayout PRS_visitLexLayout(PRS_LexLayout arg, char (*acceptCh) (char));
PRS_Location PRS_visitLocation(PRS_Location arg,
			       PRS_OptLayout(*acceptWsAfterFile)
			       (PRS_OptLayout),
			       PRS_OptLayout(*acceptWsAfterParenOpen)
			       (PRS_OptLayout),
			       PRS_StrCon(*acceptFilename) (PRS_StrCon),
			       PRS_OptLayout(*acceptWsAfterFilename)
			       (PRS_OptLayout),
			       PRS_OptLayout(*acceptWsAfterA) (PRS_OptLayout),
			       PRS_Area(*acceptArea) (PRS_Area),
			       PRS_OptLayout(*acceptWsAfterArea)
			       (PRS_OptLayout),
			       PRS_OptLayout(*acceptWsAfterAreaInFile)
			       (PRS_OptLayout),
			       PRS_OptLayout(*acceptWsAfterComma)
			       (PRS_OptLayout));
PRS_Area PRS_visitArea(PRS_Area arg,
		       PRS_OptLayout(*acceptWsAfterArea) (PRS_OptLayout),
		       PRS_OptLayout(*acceptWsAfterParenOpen) (PRS_OptLayout),
		       PRS_NatCon(*acceptBeginLine) (PRS_NatCon),
		       PRS_OptLayout(*acceptWsAfterBeginLine) (PRS_OptLayout),
		       PRS_OptLayout(*acceptWsAfterComma) (PRS_OptLayout),
		       PRS_NatCon(*acceptBeginColumn) (PRS_NatCon),
		       PRS_OptLayout(*acceptWsAfterBeginColumn)
		       (PRS_OptLayout),
		       PRS_OptLayout(*acceptWsAfterComma1) (PRS_OptLayout),
		       PRS_NatCon(*acceptEndLine) (PRS_NatCon),
		       PRS_OptLayout(*acceptWsAfterEndLine) (PRS_OptLayout),
		       PRS_OptLayout(*acceptWsAfterComma2) (PRS_OptLayout),
		       PRS_NatCon(*acceptEndColumn) (PRS_NatCon),
		       PRS_OptLayout(*acceptWsAfterEndColumn) (PRS_OptLayout),
		       PRS_OptLayout(*acceptWsAfterComma3) (PRS_OptLayout),
		       PRS_NatCon(*acceptOffset) (PRS_NatCon),
		       PRS_OptLayout(*acceptWsAfterOffset) (PRS_OptLayout),
		       PRS_OptLayout(*acceptWsAfterComma4) (PRS_OptLayout),
		       PRS_NatCon(*acceptLength) (PRS_NatCon),
		       PRS_OptLayout(*acceptWsAfterLength) (PRS_OptLayout));

/*}}}  */

#endif /* _PARSEDRSTORE_H */
