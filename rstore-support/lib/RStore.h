#ifndef _RSTORE_H
#define _RSTORE_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "RStore_dict.h"

typedef struct _RS_RElem *RS_RElem;
typedef struct _RS_RType *RS_RType;
typedef struct _RS_RTuple *RS_RTuple;
typedef struct _RS_RStore *RS_RStore;
typedef struct _RS_RElemElements *RS_RElemElements;
typedef struct _RS_RTypeColumnTypes *RS_RTypeColumnTypes;
typedef struct _RS_RTupleRtuples *RS_RTupleRtuples;
typedef struct _RS_StrChar *RS_StrChar;
typedef struct _RS_StrCon *RS_StrCon;
typedef struct _RS_BoolCon *RS_BoolCon;
typedef struct _RS_NatCon *RS_NatCon;
typedef struct _RS_IdCon *RS_IdCon;
typedef struct _RS_IntCon *RS_IntCon;
typedef struct _RS_Location *RS_Location;
typedef struct _RS_Area *RS_Area;

void RS_initRStoreApi (void);

void RS_protectRElem (RS_RElem * arg);
void RS_unprotectRElem (RS_RElem * arg);
void RS_protectRType (RS_RType * arg);
void RS_unprotectRType (RS_RType * arg);
void RS_protectRTuple (RS_RTuple * arg);
void RS_unprotectRTuple (RS_RTuple * arg);
void RS_protectRStore (RS_RStore * arg);
void RS_unprotectRStore (RS_RStore * arg);
void RS_protectRElemElements (RS_RElemElements * arg);
void RS_unprotectRElemElements (RS_RElemElements * arg);
void RS_protectRTypeColumnTypes (RS_RTypeColumnTypes * arg);
void RS_unprotectRTypeColumnTypes (RS_RTypeColumnTypes * arg);
void RS_protectRTupleRtuples (RS_RTupleRtuples * arg);
void RS_unprotectRTupleRtuples (RS_RTupleRtuples * arg);
void RS_protectStrChar (RS_StrChar * arg);
void RS_unprotectStrChar (RS_StrChar * arg);
void RS_protectStrCon (RS_StrCon * arg);
void RS_unprotectStrCon (RS_StrCon * arg);
void RS_protectBoolCon (RS_BoolCon * arg);
void RS_unprotectBoolCon (RS_BoolCon * arg);
void RS_protectNatCon (RS_NatCon * arg);
void RS_unprotectNatCon (RS_NatCon * arg);
void RS_protectIdCon (RS_IdCon * arg);
void RS_unprotectIdCon (RS_IdCon * arg);
void RS_protectIntCon (RS_IntCon * arg);
void RS_unprotectIntCon (RS_IntCon * arg);
void RS_protectLocation (RS_Location * arg);
void RS_unprotectLocation (RS_Location * arg);
void RS_protectArea (RS_Area * arg);
void RS_unprotectArea (RS_Area * arg);
RS_RElem RS_RElemFromTerm (ATerm t);
ATerm RS_RElemToTerm (RS_RElem arg);
RS_RType RS_RTypeFromTerm (ATerm t);
ATerm RS_RTypeToTerm (RS_RType arg);
RS_RTuple RS_RTupleFromTerm (ATerm t);
ATerm RS_RTupleToTerm (RS_RTuple arg);
RS_RStore RS_RStoreFromTerm (ATerm t);
ATerm RS_RStoreToTerm (RS_RStore arg);
RS_RElemElements RS_RElemElementsFromTerm (ATerm t);
ATerm RS_RElemElementsToTerm (RS_RElemElements arg);
RS_RTypeColumnTypes RS_RTypeColumnTypesFromTerm (ATerm t);
ATerm RS_RTypeColumnTypesToTerm (RS_RTypeColumnTypes arg);
RS_RTupleRtuples RS_RTupleRtuplesFromTerm (ATerm t);
ATerm RS_RTupleRtuplesToTerm (RS_RTupleRtuples arg);
RS_StrChar RS_StrCharFromTerm (ATerm t);
ATerm RS_StrCharToTerm (RS_StrChar arg);
RS_StrCon RS_StrConFromTerm (ATerm t);
ATerm RS_StrConToTerm (RS_StrCon arg);
RS_BoolCon RS_BoolConFromTerm (ATerm t);
ATerm RS_BoolConToTerm (RS_BoolCon arg);
RS_NatCon RS_NatConFromTerm (ATerm t);
ATerm RS_NatConToTerm (RS_NatCon arg);
RS_IdCon RS_IdConFromTerm (ATerm t);
ATerm RS_IdConToTerm (RS_IdCon arg);
RS_IntCon RS_IntConFromTerm (ATerm t);
ATerm RS_IntConToTerm (RS_IntCon arg);
RS_Location RS_LocationFromTerm (ATerm t);
ATerm RS_LocationToTerm (RS_Location arg);
RS_Area RS_AreaFromTerm (ATerm t);
ATerm RS_AreaToTerm (RS_Area arg);
int RS_getRElemElementsLength (RS_RElemElements arg);
RS_RElemElements RS_reverseRElemElements (RS_RElemElements arg);
RS_RElemElements RS_appendRElemElements (RS_RElemElements arg, RS_RElem elem);
RS_RElemElements RS_concatRElemElements (RS_RElemElements arg0,
					 RS_RElemElements arg1);
RS_RElemElements RS_sliceRElemElements (RS_RElemElements arg, int start,
					int end);
RS_RElem RS_getRElemElementsRElemAt (RS_RElemElements arg, int index);
RS_RElemElements RS_replaceRElemElementsRElemAt (RS_RElemElements arg,
						 RS_RElem elem, int index);
RS_RElemElements RS_makeRElemElements2 (RS_RElem elem1, RS_RElem elem2);
RS_RElemElements RS_makeRElemElements3 (RS_RElem elem1, RS_RElem elem2,
					RS_RElem elem3);
RS_RElemElements RS_makeRElemElements4 (RS_RElem elem1, RS_RElem elem2,
					RS_RElem elem3, RS_RElem elem4);
RS_RElemElements RS_makeRElemElements5 (RS_RElem elem1, RS_RElem elem2,
					RS_RElem elem3, RS_RElem elem4,
					RS_RElem elem5);
RS_RElemElements RS_makeRElemElements6 (RS_RElem elem1, RS_RElem elem2,
					RS_RElem elem3, RS_RElem elem4,
					RS_RElem elem5, RS_RElem elem6);
int RS_getRTypeColumnTypesLength (RS_RTypeColumnTypes arg);
RS_RTypeColumnTypes RS_reverseRTypeColumnTypes (RS_RTypeColumnTypes arg);
RS_RTypeColumnTypes RS_appendRTypeColumnTypes (RS_RTypeColumnTypes arg,
					       RS_RType elem);
RS_RTypeColumnTypes RS_concatRTypeColumnTypes (RS_RTypeColumnTypes arg0,
					       RS_RTypeColumnTypes arg1);
RS_RTypeColumnTypes RS_sliceRTypeColumnTypes (RS_RTypeColumnTypes arg,
					      int start, int end);
RS_RType RS_getRTypeColumnTypesRTypeAt (RS_RTypeColumnTypes arg, int index);
RS_RTypeColumnTypes RS_replaceRTypeColumnTypesRTypeAt (RS_RTypeColumnTypes
						       arg, RS_RType elem,
						       int index);
RS_RTypeColumnTypes RS_makeRTypeColumnTypes2 (RS_RType elem1, RS_RType elem2);
RS_RTypeColumnTypes RS_makeRTypeColumnTypes3 (RS_RType elem1, RS_RType elem2,
					      RS_RType elem3);
RS_RTypeColumnTypes RS_makeRTypeColumnTypes4 (RS_RType elem1, RS_RType elem2,
					      RS_RType elem3, RS_RType elem4);
RS_RTypeColumnTypes RS_makeRTypeColumnTypes5 (RS_RType elem1, RS_RType elem2,
					      RS_RType elem3, RS_RType elem4,
					      RS_RType elem5);
RS_RTypeColumnTypes RS_makeRTypeColumnTypes6 (RS_RType elem1, RS_RType elem2,
					      RS_RType elem3, RS_RType elem4,
					      RS_RType elem5, RS_RType elem6);
int RS_getRTupleRtuplesLength (RS_RTupleRtuples arg);
RS_RTupleRtuples RS_reverseRTupleRtuples (RS_RTupleRtuples arg);
RS_RTupleRtuples RS_appendRTupleRtuples (RS_RTupleRtuples arg,
					 RS_RTuple elem);
RS_RTupleRtuples RS_concatRTupleRtuples (RS_RTupleRtuples arg0,
					 RS_RTupleRtuples arg1);
RS_RTupleRtuples RS_sliceRTupleRtuples (RS_RTupleRtuples arg, int start,
					int end);
RS_RTuple RS_getRTupleRtuplesRTupleAt (RS_RTupleRtuples arg, int index);
RS_RTupleRtuples RS_replaceRTupleRtuplesRTupleAt (RS_RTupleRtuples arg,
						  RS_RTuple elem, int index);
RS_RTupleRtuples RS_makeRTupleRtuples2 (RS_RTuple elem1, RS_RTuple elem2);
RS_RTupleRtuples RS_makeRTupleRtuples3 (RS_RTuple elem1, RS_RTuple elem2,
					RS_RTuple elem3);
RS_RTupleRtuples RS_makeRTupleRtuples4 (RS_RTuple elem1, RS_RTuple elem2,
					RS_RTuple elem3, RS_RTuple elem4);
RS_RTupleRtuples RS_makeRTupleRtuples5 (RS_RTuple elem1, RS_RTuple elem2,
					RS_RTuple elem3, RS_RTuple elem4,
					RS_RTuple elem5);
RS_RTupleRtuples RS_makeRTupleRtuples6 (RS_RTuple elem1, RS_RTuple elem2,
					RS_RTuple elem3, RS_RTuple elem4,
					RS_RTuple elem5, RS_RTuple elem6);
RS_RElem RS_makeRElemInt (RS_IntCon IntCon);
RS_RElem RS_makeRElemStr (const char *StrCon);
RS_RElem RS_makeRElemBool (RS_BoolCon BoolCon);
RS_RElem RS_makeRElemLoc (RS_Location Location);
RS_RElem RS_makeRElemSet (RS_RElemElements elements);
RS_RElem RS_makeRElemBag (RS_RElemElements elements);
RS_RElem RS_makeRElemTuple (RS_RElemElements elements);
RS_RType RS_makeRTypeInt (void);
RS_RType RS_makeRTypeBool (void);
RS_RType RS_makeRTypeStr (void);
RS_RType RS_makeRTypeLoc (void);
RS_RType RS_makeRTypeTuple (RS_RTypeColumnTypes columnTypes);
RS_RType RS_makeRTypeSet (RS_RType elementType);
RS_RType RS_makeRTypeBag (RS_RType elementType);
RS_RType RS_makeRTypeRelation (RS_RTypeColumnTypes columnTypes);
RS_RType RS_makeRTypeUserDefined (RS_IdCon typeName);
RS_RType RS_makeRTypeParameter (RS_IdCon parameterName);
RS_RTuple RS_makeRTupleRtuple (RS_IdCon variable, RS_RType rtype,
			       RS_RElem value);
RS_RStore RS_makeRStoreRstore (RS_RTupleRtuples rtuples);
RS_RElemElements RS_makeRElemElementsEmpty (void);
RS_RElemElements RS_makeRElemElementsSingle (RS_RElem head);
RS_RElemElements RS_makeRElemElementsMany (RS_RElem head,
					   RS_RElemElements tail);
RS_RTypeColumnTypes RS_makeRTypeColumnTypesEmpty (void);
RS_RTypeColumnTypes RS_makeRTypeColumnTypesSingle (RS_RType head);
RS_RTypeColumnTypes RS_makeRTypeColumnTypesMany (RS_RType head,
						 RS_RTypeColumnTypes tail);
RS_RTupleRtuples RS_makeRTupleRtuplesEmpty (void);
RS_RTupleRtuples RS_makeRTupleRtuplesSingle (RS_RTuple head);
RS_RTupleRtuples RS_makeRTupleRtuplesMany (RS_RTuple head,
					   RS_RTupleRtuples tail);
RS_StrChar RS_makeStrCharStrChar (const char *string);
RS_StrCon RS_makeStrConStrCon (const char *string);
RS_BoolCon RS_makeBoolConTrue (void);
RS_BoolCon RS_makeBoolConFalse (void);
RS_NatCon RS_makeNatConNatCon (const char *string);
RS_IdCon RS_makeIdConIdCon (const char *string);
RS_IntCon RS_makeIntConIntCon (const char *string);
RS_Location RS_makeLocationFile (const char *filename);
RS_Location RS_makeLocationArea (RS_Area Area);
RS_Location RS_makeLocationAreaInFile (const char *filename, RS_Area Area);
RS_Area RS_makeAreaArea (int beginLine, int beginColumn, int endLine,
			 int endColumn, int offset, int length);
ATbool RS_isEqualRElem (RS_RElem arg0, RS_RElem arg1);
ATbool RS_isEqualRType (RS_RType arg0, RS_RType arg1);
ATbool RS_isEqualRTuple (RS_RTuple arg0, RS_RTuple arg1);
ATbool RS_isEqualRStore (RS_RStore arg0, RS_RStore arg1);
ATbool RS_isEqualRElemElements (RS_RElemElements arg0, RS_RElemElements arg1);
ATbool RS_isEqualRTypeColumnTypes (RS_RTypeColumnTypes arg0,
				   RS_RTypeColumnTypes arg1);
ATbool RS_isEqualRTupleRtuples (RS_RTupleRtuples arg0, RS_RTupleRtuples arg1);
ATbool RS_isEqualStrChar (RS_StrChar arg0, RS_StrChar arg1);
ATbool RS_isEqualStrCon (RS_StrCon arg0, RS_StrCon arg1);
ATbool RS_isEqualBoolCon (RS_BoolCon arg0, RS_BoolCon arg1);
ATbool RS_isEqualNatCon (RS_NatCon arg0, RS_NatCon arg1);
ATbool RS_isEqualIdCon (RS_IdCon arg0, RS_IdCon arg1);
ATbool RS_isEqualIntCon (RS_IntCon arg0, RS_IntCon arg1);
ATbool RS_isEqualLocation (RS_Location arg0, RS_Location arg1);
ATbool RS_isEqualArea (RS_Area arg0, RS_Area arg1);
ATbool RS_isValidRElem (RS_RElem arg);
inline ATbool RS_isRElemInt (RS_RElem arg);
inline ATbool RS_isRElemStr (RS_RElem arg);
inline ATbool RS_isRElemBool (RS_RElem arg);
inline ATbool RS_isRElemLoc (RS_RElem arg);
inline ATbool RS_isRElemSet (RS_RElem arg);
inline ATbool RS_isRElemBag (RS_RElem arg);
inline ATbool RS_isRElemTuple (RS_RElem arg);
ATbool RS_hasRElemIntCon (RS_RElem arg);
ATbool RS_hasRElemStrCon (RS_RElem arg);
ATbool RS_hasRElemBoolCon (RS_RElem arg);
ATbool RS_hasRElemLocation (RS_RElem arg);
ATbool RS_hasRElemElements (RS_RElem arg);
RS_IntCon RS_getRElemIntCon (RS_RElem arg);
char *RS_getRElemStrCon (RS_RElem arg);
RS_BoolCon RS_getRElemBoolCon (RS_RElem arg);
RS_Location RS_getRElemLocation (RS_RElem arg);
RS_RElemElements RS_getRElemElements (RS_RElem arg);
RS_RElem RS_setRElemIntCon (RS_RElem arg, RS_IntCon IntCon);
RS_RElem RS_setRElemStrCon (RS_RElem arg, const char *StrCon);
RS_RElem RS_setRElemBoolCon (RS_RElem arg, RS_BoolCon BoolCon);
RS_RElem RS_setRElemLocation (RS_RElem arg, RS_Location Location);
RS_RElem RS_setRElemElements (RS_RElem arg, RS_RElemElements elements);
ATbool RS_isValidRType (RS_RType arg);
inline ATbool RS_isRTypeInt (RS_RType arg);
inline ATbool RS_isRTypeBool (RS_RType arg);
inline ATbool RS_isRTypeStr (RS_RType arg);
inline ATbool RS_isRTypeLoc (RS_RType arg);
inline ATbool RS_isRTypeTuple (RS_RType arg);
inline ATbool RS_isRTypeSet (RS_RType arg);
inline ATbool RS_isRTypeBag (RS_RType arg);
inline ATbool RS_isRTypeRelation (RS_RType arg);
inline ATbool RS_isRTypeUserDefined (RS_RType arg);
inline ATbool RS_isRTypeParameter (RS_RType arg);
ATbool RS_hasRTypeColumnTypes (RS_RType arg);
ATbool RS_hasRTypeElementType (RS_RType arg);
ATbool RS_hasRTypeTypeName (RS_RType arg);
ATbool RS_hasRTypeParameterName (RS_RType arg);
RS_RTypeColumnTypes RS_getRTypeColumnTypes (RS_RType arg);
RS_RType RS_getRTypeElementType (RS_RType arg);
RS_IdCon RS_getRTypeTypeName (RS_RType arg);
RS_IdCon RS_getRTypeParameterName (RS_RType arg);
RS_RType RS_setRTypeColumnTypes (RS_RType arg,
				 RS_RTypeColumnTypes columnTypes);
RS_RType RS_setRTypeElementType (RS_RType arg, RS_RType elementType);
RS_RType RS_setRTypeTypeName (RS_RType arg, RS_IdCon typeName);
RS_RType RS_setRTypeParameterName (RS_RType arg, RS_IdCon parameterName);
ATbool RS_isValidRTuple (RS_RTuple arg);
inline ATbool RS_isRTupleRtuple (RS_RTuple arg);
ATbool RS_hasRTupleVariable (RS_RTuple arg);
ATbool RS_hasRTupleRtype (RS_RTuple arg);
ATbool RS_hasRTupleValue (RS_RTuple arg);
RS_IdCon RS_getRTupleVariable (RS_RTuple arg);
RS_RType RS_getRTupleRtype (RS_RTuple arg);
RS_RElem RS_getRTupleValue (RS_RTuple arg);
RS_RTuple RS_setRTupleVariable (RS_RTuple arg, RS_IdCon variable);
RS_RTuple RS_setRTupleRtype (RS_RTuple arg, RS_RType rtype);
RS_RTuple RS_setRTupleValue (RS_RTuple arg, RS_RElem value);
ATbool RS_isValidRStore (RS_RStore arg);
inline ATbool RS_isRStoreRstore (RS_RStore arg);
ATbool RS_hasRStoreRtuples (RS_RStore arg);
RS_RTupleRtuples RS_getRStoreRtuples (RS_RStore arg);
RS_RStore RS_setRStoreRtuples (RS_RStore arg, RS_RTupleRtuples rtuples);
ATbool RS_isValidRElemElements (RS_RElemElements arg);
inline ATbool RS_isRElemElementsEmpty (RS_RElemElements arg);
inline ATbool RS_isRElemElementsSingle (RS_RElemElements arg);
inline ATbool RS_isRElemElementsMany (RS_RElemElements arg);
ATbool RS_hasRElemElementsHead (RS_RElemElements arg);
ATbool RS_hasRElemElementsTail (RS_RElemElements arg);
RS_RElem RS_getRElemElementsHead (RS_RElemElements arg);
RS_RElemElements RS_getRElemElementsTail (RS_RElemElements arg);
RS_RElemElements RS_setRElemElementsHead (RS_RElemElements arg,
					  RS_RElem head);
RS_RElemElements RS_setRElemElementsTail (RS_RElemElements arg,
					  RS_RElemElements tail);
ATbool RS_isValidRTypeColumnTypes (RS_RTypeColumnTypes arg);
inline ATbool RS_isRTypeColumnTypesEmpty (RS_RTypeColumnTypes arg);
inline ATbool RS_isRTypeColumnTypesSingle (RS_RTypeColumnTypes arg);
inline ATbool RS_isRTypeColumnTypesMany (RS_RTypeColumnTypes arg);
ATbool RS_hasRTypeColumnTypesHead (RS_RTypeColumnTypes arg);
ATbool RS_hasRTypeColumnTypesTail (RS_RTypeColumnTypes arg);
RS_RType RS_getRTypeColumnTypesHead (RS_RTypeColumnTypes arg);
RS_RTypeColumnTypes RS_getRTypeColumnTypesTail (RS_RTypeColumnTypes arg);
RS_RTypeColumnTypes RS_setRTypeColumnTypesHead (RS_RTypeColumnTypes arg,
						RS_RType head);
RS_RTypeColumnTypes RS_setRTypeColumnTypesTail (RS_RTypeColumnTypes arg,
						RS_RTypeColumnTypes tail);
ATbool RS_isValidRTupleRtuples (RS_RTupleRtuples arg);
inline ATbool RS_isRTupleRtuplesEmpty (RS_RTupleRtuples arg);
inline ATbool RS_isRTupleRtuplesSingle (RS_RTupleRtuples arg);
inline ATbool RS_isRTupleRtuplesMany (RS_RTupleRtuples arg);
ATbool RS_hasRTupleRtuplesHead (RS_RTupleRtuples arg);
ATbool RS_hasRTupleRtuplesTail (RS_RTupleRtuples arg);
RS_RTuple RS_getRTupleRtuplesHead (RS_RTupleRtuples arg);
RS_RTupleRtuples RS_getRTupleRtuplesTail (RS_RTupleRtuples arg);
RS_RTupleRtuples RS_setRTupleRtuplesHead (RS_RTupleRtuples arg,
					  RS_RTuple head);
RS_RTupleRtuples RS_setRTupleRtuplesTail (RS_RTupleRtuples arg,
					  RS_RTupleRtuples tail);
ATbool RS_isValidStrChar (RS_StrChar arg);
inline ATbool RS_isStrCharStrChar (RS_StrChar arg);
ATbool RS_hasStrCharString (RS_StrChar arg);
char *RS_getStrCharString (RS_StrChar arg);
RS_StrChar RS_setStrCharString (RS_StrChar arg, const char *string);
ATbool RS_isValidStrCon (RS_StrCon arg);
inline ATbool RS_isStrConStrCon (RS_StrCon arg);
ATbool RS_hasStrConString (RS_StrCon arg);
char *RS_getStrConString (RS_StrCon arg);
RS_StrCon RS_setStrConString (RS_StrCon arg, const char *string);
ATbool RS_isValidBoolCon (RS_BoolCon arg);
inline ATbool RS_isBoolConTrue (RS_BoolCon arg);
inline ATbool RS_isBoolConFalse (RS_BoolCon arg);
ATbool RS_isValidNatCon (RS_NatCon arg);
inline ATbool RS_isNatConNatCon (RS_NatCon arg);
ATbool RS_hasNatConString (RS_NatCon arg);
char *RS_getNatConString (RS_NatCon arg);
RS_NatCon RS_setNatConString (RS_NatCon arg, const char *string);
ATbool RS_isValidIdCon (RS_IdCon arg);
inline ATbool RS_isIdConIdCon (RS_IdCon arg);
ATbool RS_hasIdConString (RS_IdCon arg);
char *RS_getIdConString (RS_IdCon arg);
RS_IdCon RS_setIdConString (RS_IdCon arg, const char *string);
ATbool RS_isValidIntCon (RS_IntCon arg);
inline ATbool RS_isIntConIntCon (RS_IntCon arg);
ATbool RS_hasIntConString (RS_IntCon arg);
char *RS_getIntConString (RS_IntCon arg);
RS_IntCon RS_setIntConString (RS_IntCon arg, const char *string);
ATbool RS_isValidLocation (RS_Location arg);
inline ATbool RS_isLocationFile (RS_Location arg);
inline ATbool RS_isLocationArea (RS_Location arg);
inline ATbool RS_isLocationAreaInFile (RS_Location arg);
ATbool RS_hasLocationFilename (RS_Location arg);
ATbool RS_hasLocationArea (RS_Location arg);
char *RS_getLocationFilename (RS_Location arg);
RS_Area RS_getLocationArea (RS_Location arg);
RS_Location RS_setLocationFilename (RS_Location arg, const char *filename);
RS_Location RS_setLocationArea (RS_Location arg, RS_Area Area);
ATbool RS_isValidArea (RS_Area arg);
inline ATbool RS_isAreaArea (RS_Area arg);
ATbool RS_hasAreaBeginLine (RS_Area arg);
ATbool RS_hasAreaBeginColumn (RS_Area arg);
ATbool RS_hasAreaEndLine (RS_Area arg);
ATbool RS_hasAreaEndColumn (RS_Area arg);
ATbool RS_hasAreaOffset (RS_Area arg);
ATbool RS_hasAreaLength (RS_Area arg);
int RS_getAreaBeginLine (RS_Area arg);
int RS_getAreaBeginColumn (RS_Area arg);
int RS_getAreaEndLine (RS_Area arg);
int RS_getAreaEndColumn (RS_Area arg);
int RS_getAreaOffset (RS_Area arg);
int RS_getAreaLength (RS_Area arg);
RS_Area RS_setAreaBeginLine (RS_Area arg, int beginLine);
RS_Area RS_setAreaBeginColumn (RS_Area arg, int beginColumn);
RS_Area RS_setAreaEndLine (RS_Area arg, int endLine);
RS_Area RS_setAreaEndColumn (RS_Area arg, int endColumn);
RS_Area RS_setAreaOffset (RS_Area arg, int offset);
RS_Area RS_setAreaLength (RS_Area arg, int length);
RS_RElem RS_visitRElem (RS_RElem arg, RS_IntCon (*acceptIntCon) (RS_IntCon),
			char *(*acceptStrCon) (char *),
			RS_BoolCon (*acceptBoolCon) (RS_BoolCon),
			RS_Location (*acceptLocation) (RS_Location),
			RS_RElemElements (*acceptElements)
			(RS_RElemElements));
RS_RType RS_visitRType (RS_RType arg,
			RS_RTypeColumnTypes (*acceptColumnTypes)
			(RS_RTypeColumnTypes),
			RS_IdCon (*acceptTypeName) (RS_IdCon),
			RS_IdCon (*acceptParameterName) (RS_IdCon));
RS_RTuple RS_visitRTuple (RS_RTuple arg,
			  RS_IdCon (*acceptVariable) (RS_IdCon),
			  RS_RType (*acceptRtype) (RS_RType),
			  RS_RElem (*acceptValue) (RS_RElem));
RS_RStore RS_visitRStore (RS_RStore arg,
			  RS_RTupleRtuples (*acceptRtuples)
			  (RS_RTupleRtuples));
RS_RElemElements RS_visitRElemElements (RS_RElemElements arg,
					RS_RElem (*acceptHead) (RS_RElem));
RS_RTypeColumnTypes RS_visitRTypeColumnTypes (RS_RTypeColumnTypes arg,
					      RS_RType (*acceptHead)
					      (RS_RType));
RS_RTupleRtuples RS_visitRTupleRtuples (RS_RTupleRtuples arg,
					RS_RTuple (*acceptHead) (RS_RTuple));
RS_StrChar RS_visitStrChar (RS_StrChar arg, char *(*acceptString) (char *));
RS_StrCon RS_visitStrCon (RS_StrCon arg, char *(*acceptString) (char *));
RS_BoolCon RS_visitBoolCon (RS_BoolCon arg);
RS_NatCon RS_visitNatCon (RS_NatCon arg, char *(*acceptString) (char *));
RS_IdCon RS_visitIdCon (RS_IdCon arg, char *(*acceptString) (char *));
RS_IntCon RS_visitIntCon (RS_IntCon arg, char *(*acceptString) (char *));
RS_Location RS_visitLocation (RS_Location arg,
			      char *(*acceptFilename) (char *),
			      RS_Area (*acceptArea) (RS_Area));
RS_Area RS_visitArea (RS_Area arg, int (*acceptBeginLine) (int),
		      int (*acceptBeginColumn) (int),
		      int (*acceptEndLine) (int),
		      int (*acceptEndColumn) (int), int (*acceptOffset) (int),
		      int (*acceptLength) (int));

#endif /* _RSTORE_H */
