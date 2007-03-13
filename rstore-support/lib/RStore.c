#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "RStore.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm RS_stringToChars(const char *str) {
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

/**
 * Converts an ASCII char to an ATermInt. 
 * \param[in] ch an ASCII character
 * \return An ATerm representing the ASCII value of #arg
 */
ATerm RS_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *RS_charsToString(ATerm arg) {
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

char RS_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _RS_RElem;
typedef struct ATerm _RS_RType;
typedef struct ATerm _RS_RTuple;
typedef struct ATerm _RS_RStore;
typedef struct ATerm _RS_RElemElements;
typedef struct ATerm _RS_RTypeColumnTypes;
typedef struct ATerm _RS_RTupleRtuples;
typedef struct ATerm _RS_StrChar;
typedef struct ATerm _RS_StrCon;
typedef struct ATerm _RS_BoolCon;
typedef struct ATerm _RS_NatCon;
typedef struct ATerm _RS_IdCon;
typedef struct ATerm _RS_Integer;
typedef struct ATerm _RS_Location;
typedef struct ATerm _RS_Area;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _RS_initRStoreApi(void) {
  init_RStore_dict();

}

/**
 * Protect a RS_RElem from the ATerm garbage collector. Every RS_RElem that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_RElem
 */
void _RS_protectRElem(RS_RElem *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_RElem from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_RElem
 */
void _RS_unprotectRElem(RS_RElem *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_RType from the ATerm garbage collector. Every RS_RType that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_RType
 */
void _RS_protectRType(RS_RType *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_RType from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_RType
 */
void _RS_unprotectRType(RS_RType *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_RTuple from the ATerm garbage collector. Every RS_RTuple that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_RTuple
 */
void _RS_protectRTuple(RS_RTuple *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_RTuple from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_RTuple
 */
void _RS_unprotectRTuple(RS_RTuple *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_RStore from the ATerm garbage collector. Every RS_RStore that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_RStore
 */
void _RS_protectRStore(RS_RStore *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_RStore from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_RStore
 */
void _RS_unprotectRStore(RS_RStore *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_RElemElements from the ATerm garbage collector. Every RS_RElemElements that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_RElemElements
 */
void _RS_protectRElemElements(RS_RElemElements *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_RElemElements from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_RElemElements
 */
void _RS_unprotectRElemElements(RS_RElemElements *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_RTypeColumnTypes from the ATerm garbage collector. Every RS_RTypeColumnTypes that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_RTypeColumnTypes
 */
void _RS_protectRTypeColumnTypes(RS_RTypeColumnTypes *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_RTypeColumnTypes from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_RTypeColumnTypes
 */
void _RS_unprotectRTypeColumnTypes(RS_RTypeColumnTypes *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_RTupleRtuples from the ATerm garbage collector. Every RS_RTupleRtuples that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_RTupleRtuples
 */
void _RS_protectRTupleRtuples(RS_RTupleRtuples *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_RTupleRtuples from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_RTupleRtuples
 */
void _RS_unprotectRTupleRtuples(RS_RTupleRtuples *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_StrChar from the ATerm garbage collector. Every RS_StrChar that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_StrChar
 */
void _RS_protectStrChar(RS_StrChar *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_StrChar from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_StrChar
 */
void _RS_unprotectStrChar(RS_StrChar *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_StrCon from the ATerm garbage collector. Every RS_StrCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_StrCon
 */
void _RS_protectStrCon(RS_StrCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_StrCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_StrCon
 */
void _RS_unprotectStrCon(RS_StrCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_BoolCon from the ATerm garbage collector. Every RS_BoolCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_BoolCon
 */
void _RS_protectBoolCon(RS_BoolCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_BoolCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_BoolCon
 */
void _RS_unprotectBoolCon(RS_BoolCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_NatCon from the ATerm garbage collector. Every RS_NatCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_NatCon
 */
void _RS_protectNatCon(RS_NatCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_NatCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_NatCon
 */
void _RS_unprotectNatCon(RS_NatCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_IdCon from the ATerm garbage collector. Every RS_IdCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_IdCon
 */
void _RS_protectIdCon(RS_IdCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_IdCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_IdCon
 */
void _RS_unprotectIdCon(RS_IdCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_Integer from the ATerm garbage collector. Every RS_Integer that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_Integer
 */
void _RS_protectInteger(RS_Integer *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_Integer from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_Integer
 */
void _RS_unprotectInteger(RS_Integer *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_Location from the ATerm garbage collector. Every RS_Location that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_Location
 */
void _RS_protectLocation(RS_Location *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_Location from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_Location
 */
void _RS_unprotectLocation(RS_Location *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a RS_Area from the ATerm garbage collector. Every RS_Area that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a RS_Area
 */
void _RS_protectArea(RS_Area *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a RS_Area from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a RS_Area
 */
void _RS_unprotectArea(RS_Area *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a RS_RElem. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_RElem that was encoded by \arg
 */
RS_RElem _RS_RElemFromTerm(ATerm t) {
  return (RS_RElem)t;
}

/**
 * Transforms a RS_RElemto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_RElem to be converted
 * \return ATerm that represents the RS_RElem
 */
ATerm _RS_RElemToTerm(RS_RElem arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_RType. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_RType that was encoded by \arg
 */
RS_RType _RS_RTypeFromTerm(ATerm t) {
  return (RS_RType)t;
}

/**
 * Transforms a RS_RTypeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_RType to be converted
 * \return ATerm that represents the RS_RType
 */
ATerm _RS_RTypeToTerm(RS_RType arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_RTuple. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_RTuple that was encoded by \arg
 */
RS_RTuple _RS_RTupleFromTerm(ATerm t) {
  return (RS_RTuple)t;
}

/**
 * Transforms a RS_RTupleto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_RTuple to be converted
 * \return ATerm that represents the RS_RTuple
 */
ATerm _RS_RTupleToTerm(RS_RTuple arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_RStore. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_RStore that was encoded by \arg
 */
RS_RStore _RS_RStoreFromTerm(ATerm t) {
  return (RS_RStore)t;
}

/**
 * Transforms a RS_RStoreto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_RStore to be converted
 * \return ATerm that represents the RS_RStore
 */
ATerm _RS_RStoreToTerm(RS_RStore arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_RElemElements. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_RElemElements that was encoded by \arg
 */
RS_RElemElements _RS_RElemElementsFromTerm(ATerm t) {
  return (RS_RElemElements)t;
}

/**
 * Transforms a RS_RElemElementsto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_RElemElements to be converted
 * \return ATerm that represents the RS_RElemElements
 */
ATerm _RS_RElemElementsToTerm(RS_RElemElements arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_RTypeColumnTypes. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_RTypeColumnTypes that was encoded by \arg
 */
RS_RTypeColumnTypes _RS_RTypeColumnTypesFromTerm(ATerm t) {
  return (RS_RTypeColumnTypes)t;
}

/**
 * Transforms a RS_RTypeColumnTypesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_RTypeColumnTypes to be converted
 * \return ATerm that represents the RS_RTypeColumnTypes
 */
ATerm _RS_RTypeColumnTypesToTerm(RS_RTypeColumnTypes arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_RTupleRtuples. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_RTupleRtuples that was encoded by \arg
 */
RS_RTupleRtuples _RS_RTupleRtuplesFromTerm(ATerm t) {
  return (RS_RTupleRtuples)t;
}

/**
 * Transforms a RS_RTupleRtuplesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_RTupleRtuples to be converted
 * \return ATerm that represents the RS_RTupleRtuples
 */
ATerm _RS_RTupleRtuplesToTerm(RS_RTupleRtuples arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_StrChar. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_StrChar that was encoded by \arg
 */
RS_StrChar _RS_StrCharFromTerm(ATerm t) {
  return (RS_StrChar)t;
}

/**
 * Transforms a RS_StrCharto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_StrChar to be converted
 * \return ATerm that represents the RS_StrChar
 */
ATerm _RS_StrCharToTerm(RS_StrChar arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_StrCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_StrCon that was encoded by \arg
 */
RS_StrCon _RS_StrConFromTerm(ATerm t) {
  return (RS_StrCon)t;
}

/**
 * Transforms a RS_StrConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_StrCon to be converted
 * \return ATerm that represents the RS_StrCon
 */
ATerm _RS_StrConToTerm(RS_StrCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_BoolCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_BoolCon that was encoded by \arg
 */
RS_BoolCon _RS_BoolConFromTerm(ATerm t) {
  return (RS_BoolCon)t;
}

/**
 * Transforms a RS_BoolConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_BoolCon to be converted
 * \return ATerm that represents the RS_BoolCon
 */
ATerm _RS_BoolConToTerm(RS_BoolCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_NatCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_NatCon that was encoded by \arg
 */
RS_NatCon _RS_NatConFromTerm(ATerm t) {
  return (RS_NatCon)t;
}

/**
 * Transforms a RS_NatConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_NatCon to be converted
 * \return ATerm that represents the RS_NatCon
 */
ATerm _RS_NatConToTerm(RS_NatCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_IdCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_IdCon that was encoded by \arg
 */
RS_IdCon _RS_IdConFromTerm(ATerm t) {
  return (RS_IdCon)t;
}

/**
 * Transforms a RS_IdConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_IdCon to be converted
 * \return ATerm that represents the RS_IdCon
 */
ATerm _RS_IdConToTerm(RS_IdCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_Integer. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_Integer that was encoded by \arg
 */
RS_Integer _RS_IntegerFromTerm(ATerm t) {
  return (RS_Integer)t;
}

/**
 * Transforms a RS_Integerto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_Integer to be converted
 * \return ATerm that represents the RS_Integer
 */
ATerm _RS_IntegerToTerm(RS_Integer arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_Location. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_Location that was encoded by \arg
 */
RS_Location _RS_LocationFromTerm(ATerm t) {
  return (RS_Location)t;
}

/**
 * Transforms a RS_Locationto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_Location to be converted
 * \return ATerm that represents the RS_Location
 */
ATerm _RS_LocationToTerm(RS_Location arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a RS_Area. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return RS_Area that was encoded by \arg
 */
RS_Area _RS_AreaFromTerm(ATerm t) {
  return (RS_Area)t;
}

/**
 * Transforms a RS_Areato an ATerm. This is just a wrapper for a cast.
 * \param[in] arg RS_Area to be converted
 * \return ATerm that represents the RS_Area
 */
ATerm _RS_AreaToTerm(RS_Area arg) {
  return (ATerm)arg;
}

/**
 * Retrieve the length of a RS_RElemElements. 
 * \param[in] arg input RS_RElemElements
 * \return The number of elements in the RS_RElemElements
 */
int _RS_getRElemElementsLength(RS_RElemElements arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a RS_RElemElements. 
 * \param[in] arg RS_RElemElements to be reversed
 * \return a reversed #arg
 */
RS_RElemElements _RS_reverseRElemElements(RS_RElemElements arg) {
  return (RS_RElemElements) ATreverse((ATermList) arg);
}

/**
 * Append a RS_RElem to the end of a RS_RElemElements. 
 * \param[in] arg RS_RElemElements to append the RS_RElem to
 * \param[in] elem RS_RElem to be appended
 * \return new RS_RElemElements with #elem appended
 */
RS_RElemElements _RS_appendRElemElements(RS_RElemElements arg, RS_RElem elem) {
  return (RS_RElemElements) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two RS_RElemElementss. 
 * \param[in] arg0 first RS_RElemElements
 * \param[in] arg1 second RS_RElemElements
 * \return RS_RElemElements with the elements of #arg0 before the elements of #arg1
 */
RS_RElemElements _RS_concatRElemElements(RS_RElemElements arg0, RS_RElemElements arg1) {
  return (RS_RElemElements) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a RS_RElemElements. 
 * \param[in] arg RS_RElemElements to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new RS_RElemElements with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
RS_RElemElements _RS_sliceRElemElements(RS_RElemElements arg, int start, int end) {
  return (RS_RElemElements) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the RS_RElem at #index from a RS_RElemElements. 
 * \param[in] arg RS_RElemElements to retrieve the RS_RElem from
 * \param[in] index index to use to point in the RS_RElemElements
 * \return RS_RElem at position #index in #arg
 */
RS_RElem _RS_getRElemElementsRElemAt(RS_RElemElements arg, int index) {
 return (RS_RElem)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the RS_RElem at #index from a RS_RElemElements by a new one. 
 * \param[in] arg RS_RElemElements to retrieve the RS_RElem from
 * \param[in] elem new RS_RElem to replace another
 * \param[in] index index to use to point in the RS_RElemElements
 * \return A new RS_RElemElementswith #elem replaced in #arg at position #index
 */
RS_RElemElements _RS_replaceRElemElementsRElemAt(RS_RElemElements arg, RS_RElem elem, int index) {
 return (RS_RElemElements) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a RS_RElemElements of 2 consecutive elements. 
 * \param[in] elem1 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem2 One RS_RElem element of the new RS_RElemElements
 * \return A new RS_RElemElements consisting of 2 RS_RElems
 */
RS_RElemElements _RS_makeRElemElements2(RS_RElem elem1, RS_RElem elem2) {
  return (RS_RElemElements) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a RS_RElemElements of 3 consecutive elements. 
 * \param[in] elem1 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem2 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem3 One RS_RElem element of the new RS_RElemElements
 * \return A new RS_RElemElements consisting of 3 RS_RElems
 */
RS_RElemElements _RS_makeRElemElements3(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3) {
  return (RS_RElemElements) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a RS_RElemElements of 4 consecutive elements. 
 * \param[in] elem1 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem2 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem3 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem4 One RS_RElem element of the new RS_RElemElements
 * \return A new RS_RElemElements consisting of 4 RS_RElems
 */
RS_RElemElements _RS_makeRElemElements4(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3, RS_RElem elem4) {
  return (RS_RElemElements) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a RS_RElemElements of 5 consecutive elements. 
 * \param[in] elem1 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem2 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem3 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem4 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem5 One RS_RElem element of the new RS_RElemElements
 * \return A new RS_RElemElements consisting of 5 RS_RElems
 */
RS_RElemElements _RS_makeRElemElements5(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3, RS_RElem elem4, RS_RElem elem5) {
  return (RS_RElemElements) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a RS_RElemElements of 6 consecutive elements. 
 * \param[in] elem1 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem2 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem3 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem4 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem5 One RS_RElem element of the new RS_RElemElements
 * \param[in] elem6 One RS_RElem element of the new RS_RElemElements
 * \return A new RS_RElemElements consisting of 6 RS_RElems
 */
RS_RElemElements _RS_makeRElemElements6(RS_RElem elem1, RS_RElem elem2, RS_RElem elem3, RS_RElem elem4, RS_RElem elem5, RS_RElem elem6) {
  return (RS_RElemElements) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a RS_RTypeColumnTypes. 
 * \param[in] arg input RS_RTypeColumnTypes
 * \return The number of elements in the RS_RTypeColumnTypes
 */
int _RS_getRTypeColumnTypesLength(RS_RTypeColumnTypes arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a RS_RTypeColumnTypes. 
 * \param[in] arg RS_RTypeColumnTypes to be reversed
 * \return a reversed #arg
 */
RS_RTypeColumnTypes _RS_reverseRTypeColumnTypes(RS_RTypeColumnTypes arg) {
  return (RS_RTypeColumnTypes) ATreverse((ATermList) arg);
}

/**
 * Append a RS_RType to the end of a RS_RTypeColumnTypes. 
 * \param[in] arg RS_RTypeColumnTypes to append the RS_RType to
 * \param[in] elem RS_RType to be appended
 * \return new RS_RTypeColumnTypes with #elem appended
 */
RS_RTypeColumnTypes _RS_appendRTypeColumnTypes(RS_RTypeColumnTypes arg, RS_RType elem) {
  return (RS_RTypeColumnTypes) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two RS_RTypeColumnTypess. 
 * \param[in] arg0 first RS_RTypeColumnTypes
 * \param[in] arg1 second RS_RTypeColumnTypes
 * \return RS_RTypeColumnTypes with the elements of #arg0 before the elements of #arg1
 */
RS_RTypeColumnTypes _RS_concatRTypeColumnTypes(RS_RTypeColumnTypes arg0, RS_RTypeColumnTypes arg1) {
  return (RS_RTypeColumnTypes) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a RS_RTypeColumnTypes. 
 * \param[in] arg RS_RTypeColumnTypes to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new RS_RTypeColumnTypes with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
RS_RTypeColumnTypes _RS_sliceRTypeColumnTypes(RS_RTypeColumnTypes arg, int start, int end) {
  return (RS_RTypeColumnTypes) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the RS_RType at #index from a RS_RTypeColumnTypes. 
 * \param[in] arg RS_RTypeColumnTypes to retrieve the RS_RType from
 * \param[in] index index to use to point in the RS_RTypeColumnTypes
 * \return RS_RType at position #index in #arg
 */
RS_RType _RS_getRTypeColumnTypesRTypeAt(RS_RTypeColumnTypes arg, int index) {
 return (RS_RType)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the RS_RType at #index from a RS_RTypeColumnTypes by a new one. 
 * \param[in] arg RS_RTypeColumnTypes to retrieve the RS_RType from
 * \param[in] elem new RS_RType to replace another
 * \param[in] index index to use to point in the RS_RTypeColumnTypes
 * \return A new RS_RTypeColumnTypeswith #elem replaced in #arg at position #index
 */
RS_RTypeColumnTypes _RS_replaceRTypeColumnTypesRTypeAt(RS_RTypeColumnTypes arg, RS_RType elem, int index) {
 return (RS_RTypeColumnTypes) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a RS_RTypeColumnTypes of 2 consecutive elements. 
 * \param[in] elem1 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem2 One RS_RType element of the new RS_RTypeColumnTypes
 * \return A new RS_RTypeColumnTypes consisting of 2 RS_RTypes
 */
RS_RTypeColumnTypes _RS_makeRTypeColumnTypes2(RS_RType elem1, RS_RType elem2) {
  return (RS_RTypeColumnTypes) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a RS_RTypeColumnTypes of 3 consecutive elements. 
 * \param[in] elem1 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem2 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem3 One RS_RType element of the new RS_RTypeColumnTypes
 * \return A new RS_RTypeColumnTypes consisting of 3 RS_RTypes
 */
RS_RTypeColumnTypes _RS_makeRTypeColumnTypes3(RS_RType elem1, RS_RType elem2, RS_RType elem3) {
  return (RS_RTypeColumnTypes) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a RS_RTypeColumnTypes of 4 consecutive elements. 
 * \param[in] elem1 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem2 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem3 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem4 One RS_RType element of the new RS_RTypeColumnTypes
 * \return A new RS_RTypeColumnTypes consisting of 4 RS_RTypes
 */
RS_RTypeColumnTypes _RS_makeRTypeColumnTypes4(RS_RType elem1, RS_RType elem2, RS_RType elem3, RS_RType elem4) {
  return (RS_RTypeColumnTypes) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a RS_RTypeColumnTypes of 5 consecutive elements. 
 * \param[in] elem1 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem2 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem3 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem4 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem5 One RS_RType element of the new RS_RTypeColumnTypes
 * \return A new RS_RTypeColumnTypes consisting of 5 RS_RTypes
 */
RS_RTypeColumnTypes _RS_makeRTypeColumnTypes5(RS_RType elem1, RS_RType elem2, RS_RType elem3, RS_RType elem4, RS_RType elem5) {
  return (RS_RTypeColumnTypes) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a RS_RTypeColumnTypes of 6 consecutive elements. 
 * \param[in] elem1 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem2 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem3 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem4 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem5 One RS_RType element of the new RS_RTypeColumnTypes
 * \param[in] elem6 One RS_RType element of the new RS_RTypeColumnTypes
 * \return A new RS_RTypeColumnTypes consisting of 6 RS_RTypes
 */
RS_RTypeColumnTypes _RS_makeRTypeColumnTypes6(RS_RType elem1, RS_RType elem2, RS_RType elem3, RS_RType elem4, RS_RType elem5, RS_RType elem6) {
  return (RS_RTypeColumnTypes) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a RS_RTupleRtuples. 
 * \param[in] arg input RS_RTupleRtuples
 * \return The number of elements in the RS_RTupleRtuples
 */
int _RS_getRTupleRtuplesLength(RS_RTupleRtuples arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a RS_RTupleRtuples. 
 * \param[in] arg RS_RTupleRtuples to be reversed
 * \return a reversed #arg
 */
RS_RTupleRtuples _RS_reverseRTupleRtuples(RS_RTupleRtuples arg) {
  return (RS_RTupleRtuples) ATreverse((ATermList) arg);
}

/**
 * Append a RS_RTuple to the end of a RS_RTupleRtuples. 
 * \param[in] arg RS_RTupleRtuples to append the RS_RTuple to
 * \param[in] elem RS_RTuple to be appended
 * \return new RS_RTupleRtuples with #elem appended
 */
RS_RTupleRtuples _RS_appendRTupleRtuples(RS_RTupleRtuples arg, RS_RTuple elem) {
  return (RS_RTupleRtuples) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two RS_RTupleRtupless. 
 * \param[in] arg0 first RS_RTupleRtuples
 * \param[in] arg1 second RS_RTupleRtuples
 * \return RS_RTupleRtuples with the elements of #arg0 before the elements of #arg1
 */
RS_RTupleRtuples _RS_concatRTupleRtuples(RS_RTupleRtuples arg0, RS_RTupleRtuples arg1) {
  return (RS_RTupleRtuples) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a RS_RTupleRtuples. 
 * \param[in] arg RS_RTupleRtuples to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new RS_RTupleRtuples with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
RS_RTupleRtuples _RS_sliceRTupleRtuples(RS_RTupleRtuples arg, int start, int end) {
  return (RS_RTupleRtuples) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the RS_RTuple at #index from a RS_RTupleRtuples. 
 * \param[in] arg RS_RTupleRtuples to retrieve the RS_RTuple from
 * \param[in] index index to use to point in the RS_RTupleRtuples
 * \return RS_RTuple at position #index in #arg
 */
RS_RTuple _RS_getRTupleRtuplesRTupleAt(RS_RTupleRtuples arg, int index) {
 return (RS_RTuple)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the RS_RTuple at #index from a RS_RTupleRtuples by a new one. 
 * \param[in] arg RS_RTupleRtuples to retrieve the RS_RTuple from
 * \param[in] elem new RS_RTuple to replace another
 * \param[in] index index to use to point in the RS_RTupleRtuples
 * \return A new RS_RTupleRtupleswith #elem replaced in #arg at position #index
 */
RS_RTupleRtuples _RS_replaceRTupleRtuplesRTupleAt(RS_RTupleRtuples arg, RS_RTuple elem, int index) {
 return (RS_RTupleRtuples) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a RS_RTupleRtuples of 2 consecutive elements. 
 * \param[in] elem1 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem2 One RS_RTuple element of the new RS_RTupleRtuples
 * \return A new RS_RTupleRtuples consisting of 2 RS_RTuples
 */
RS_RTupleRtuples _RS_makeRTupleRtuples2(RS_RTuple elem1, RS_RTuple elem2) {
  return (RS_RTupleRtuples) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a RS_RTupleRtuples of 3 consecutive elements. 
 * \param[in] elem1 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem2 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem3 One RS_RTuple element of the new RS_RTupleRtuples
 * \return A new RS_RTupleRtuples consisting of 3 RS_RTuples
 */
RS_RTupleRtuples _RS_makeRTupleRtuples3(RS_RTuple elem1, RS_RTuple elem2, RS_RTuple elem3) {
  return (RS_RTupleRtuples) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a RS_RTupleRtuples of 4 consecutive elements. 
 * \param[in] elem1 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem2 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem3 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem4 One RS_RTuple element of the new RS_RTupleRtuples
 * \return A new RS_RTupleRtuples consisting of 4 RS_RTuples
 */
RS_RTupleRtuples _RS_makeRTupleRtuples4(RS_RTuple elem1, RS_RTuple elem2, RS_RTuple elem3, RS_RTuple elem4) {
  return (RS_RTupleRtuples) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a RS_RTupleRtuples of 5 consecutive elements. 
 * \param[in] elem1 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem2 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem3 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem4 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem5 One RS_RTuple element of the new RS_RTupleRtuples
 * \return A new RS_RTupleRtuples consisting of 5 RS_RTuples
 */
RS_RTupleRtuples _RS_makeRTupleRtuples5(RS_RTuple elem1, RS_RTuple elem2, RS_RTuple elem3, RS_RTuple elem4, RS_RTuple elem5) {
  return (RS_RTupleRtuples) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a RS_RTupleRtuples of 6 consecutive elements. 
 * \param[in] elem1 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem2 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem3 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem4 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem5 One RS_RTuple element of the new RS_RTupleRtuples
 * \param[in] elem6 One RS_RTuple element of the new RS_RTupleRtuples
 * \return A new RS_RTupleRtuples consisting of 6 RS_RTuples
 */
RS_RTupleRtuples _RS_makeRTupleRtuples6(RS_RTuple elem1, RS_RTuple elem2, RS_RTuple elem3, RS_RTuple elem4, RS_RTuple elem5, RS_RTuple elem6) {
  return (RS_RTupleRtuples) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a int of type RS_RElem. Like all ATerm types, RS_RElems are maximally shared.
 * \param[in] Integer a child of the new int
 * \return A pointer to a int, either newly constructed or shared
 */
RS_RElem RS_makeRElemInt(RS_Integer Integer) {
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun0, (ATerm) Integer);
}
/**
 * Constructs a str of type RS_RElem. Like all ATerm types, RS_RElems are maximally shared.
 * \param[in] StrCon a child of the new str
 * \return A pointer to a str, either newly constructed or shared
 */
RS_RElem RS_makeRElemStr(const char* StrCon) {
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(StrCon, 0, ATtrue)));
}
/**
 * Constructs a bool of type RS_RElem. Like all ATerm types, RS_RElems are maximally shared.
 * \param[in] BoolCon a child of the new bool
 * \return A pointer to a bool, either newly constructed or shared
 */
RS_RElem RS_makeRElemBool(RS_BoolCon BoolCon) {
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun2, (ATerm) BoolCon);
}
/**
 * Constructs a loc of type RS_RElem. Like all ATerm types, RS_RElems are maximally shared.
 * \param[in] Location a child of the new loc
 * \return A pointer to a loc, either newly constructed or shared
 */
RS_RElem RS_makeRElemLoc(RS_Location Location) {
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun3, (ATerm) Location);
}
/**
 * Constructs a set of type RS_RElem. Like all ATerm types, RS_RElems are maximally shared.
 * \param[in] elements a child of the new set
 * \return A pointer to a set, either newly constructed or shared
 */
RS_RElem RS_makeRElemSet(RS_RElemElements elements) {
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun4, (ATerm) elements);
}
/**
 * Constructs a bag of type RS_RElem. Like all ATerm types, RS_RElems are maximally shared.
 * \param[in] elements a child of the new bag
 * \return A pointer to a bag, either newly constructed or shared
 */
RS_RElem RS_makeRElemBag(RS_RElemElements elements) {
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun5, (ATerm) elements);
}
/**
 * Constructs a tuple of type RS_RElem. Like all ATerm types, RS_RElems are maximally shared.
 * \param[in] elements a child of the new tuple
 * \return A pointer to a tuple, either newly constructed or shared
 */
RS_RElem RS_makeRElemTuple(RS_RElemElements elements) {
  return (RS_RElem)(ATerm)ATmakeAppl1(RS_afun6, (ATerm) elements);
}
/**
 * Constructs a int of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \return A pointer to a int, either newly constructed or shared
 */
RS_RType RS_makeRTypeInt(void) {
  return (RS_RType)(ATerm)ATmakeAppl0(RS_afun7);
}
/**
 * Constructs a bool of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \return A pointer to a bool, either newly constructed or shared
 */
RS_RType RS_makeRTypeBool(void) {
  return (RS_RType)(ATerm)ATmakeAppl0(RS_afun8);
}
/**
 * Constructs a str of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \return A pointer to a str, either newly constructed or shared
 */
RS_RType RS_makeRTypeStr(void) {
  return (RS_RType)(ATerm)ATmakeAppl0(RS_afun9);
}
/**
 * Constructs a loc of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \return A pointer to a loc, either newly constructed or shared
 */
RS_RType RS_makeRTypeLoc(void) {
  return (RS_RType)(ATerm)ATmakeAppl0(RS_afun10);
}
/**
 * Constructs a tuple of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \param[in] columnTypes a child of the new tuple
 * \return A pointer to a tuple, either newly constructed or shared
 */
RS_RType RS_makeRTypeTuple(RS_RTypeColumnTypes columnTypes) {
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun6, (ATerm) columnTypes);
}
/**
 * Constructs a set of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \param[in] elementType a child of the new set
 * \return A pointer to a set, either newly constructed or shared
 */
RS_RType RS_makeRTypeSet(RS_RType elementType) {
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun4, (ATerm) elementType);
}
/**
 * Constructs a bag of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \param[in] elementType a child of the new bag
 * \return A pointer to a bag, either newly constructed or shared
 */
RS_RType RS_makeRTypeBag(RS_RType elementType) {
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun5, (ATerm) elementType);
}
/**
 * Constructs a relation of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \param[in] columnTypes a child of the new relation
 * \return A pointer to a relation, either newly constructed or shared
 */
RS_RType RS_makeRTypeRelation(RS_RTypeColumnTypes columnTypes) {
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun11, (ATerm) columnTypes);
}
/**
 * Constructs a user-defined of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \param[in] typeName a child of the new user-defined
 * \return A pointer to a user-defined, either newly constructed or shared
 */
RS_RType RS_makeRTypeUserDefined(RS_IdCon typeName) {
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun12, (ATerm) typeName);
}
/**
 * Constructs a parameter of type RS_RType. Like all ATerm types, RS_RTypes are maximally shared.
 * \param[in] parameterName a child of the new parameter
 * \return A pointer to a parameter, either newly constructed or shared
 */
RS_RType RS_makeRTypeParameter(RS_IdCon parameterName) {
  return (RS_RType)(ATerm)ATmakeAppl1(RS_afun13, (ATerm) parameterName);
}
/**
 * Constructs a rtuple of type RS_RTuple. Like all ATerm types, RS_RTuples are maximally shared.
 * \param[in] variable a child of the new rtuple
 * \param[in] rtype a child of the new rtuple
 * \param[in] value a child of the new rtuple
 * \return A pointer to a rtuple, either newly constructed or shared
 */
RS_RTuple RS_makeRTupleRtuple(RS_IdCon variable, RS_RType rtype, RS_RElem value) {
  return (RS_RTuple)(ATerm)ATmakeAppl3(RS_afun14, (ATerm) variable, (ATerm) rtype, (ATerm) value);
}
/**
 * Constructs a rstore of type RS_RStore. Like all ATerm types, RS_RStores are maximally shared.
 * \param[in] rtuples a child of the new rstore
 * \return A pointer to a rstore, either newly constructed or shared
 */
RS_RStore RS_makeRStoreRstore(RS_RTupleRtuples rtuples) {
  return (RS_RStore)(ATerm)ATmakeAppl1(RS_afun15, (ATerm) rtuples);
}
/**
 * Constructs a empty of type RS_RElemElements. Like all ATerm types, RS_RElemElementss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
RS_RElemElements RS_makeRElemElementsEmpty(void) {
  return (RS_RElemElements)(ATerm)ATempty;
}
/**
 * Constructs a single of type RS_RElemElements. Like all ATerm types, RS_RElemElementss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
RS_RElemElements RS_makeRElemElementsSingle(RS_RElem head) {
  return (RS_RElemElements)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type RS_RElemElements. Like all ATerm types, RS_RElemElementss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
RS_RElemElements RS_makeRElemElementsMany(RS_RElem head, RS_RElemElements tail) {
  return (RS_RElemElements)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a empty of type RS_RTypeColumnTypes. Like all ATerm types, RS_RTypeColumnTypess are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
RS_RTypeColumnTypes RS_makeRTypeColumnTypesEmpty(void) {
  return (RS_RTypeColumnTypes)(ATerm)ATempty;
}
/**
 * Constructs a single of type RS_RTypeColumnTypes. Like all ATerm types, RS_RTypeColumnTypess are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
RS_RTypeColumnTypes RS_makeRTypeColumnTypesSingle(RS_RType head) {
  return (RS_RTypeColumnTypes)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type RS_RTypeColumnTypes. Like all ATerm types, RS_RTypeColumnTypess are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
RS_RTypeColumnTypes RS_makeRTypeColumnTypesMany(RS_RType head, RS_RTypeColumnTypes tail) {
  return (RS_RTypeColumnTypes)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a empty of type RS_RTupleRtuples. Like all ATerm types, RS_RTupleRtupless are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
RS_RTupleRtuples RS_makeRTupleRtuplesEmpty(void) {
  return (RS_RTupleRtuples)(ATerm)ATempty;
}
/**
 * Constructs a single of type RS_RTupleRtuples. Like all ATerm types, RS_RTupleRtupless are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
RS_RTupleRtuples RS_makeRTupleRtuplesSingle(RS_RTuple head) {
  return (RS_RTupleRtuples)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type RS_RTupleRtuples. Like all ATerm types, RS_RTupleRtupless are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
RS_RTupleRtuples RS_makeRTupleRtuplesMany(RS_RTuple head, RS_RTupleRtuples tail) {
  return (RS_RTupleRtuples)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a StrChar of type RS_StrChar. Like all ATerm types, RS_StrChars are maximally shared.
 * \param[in] string a child of the new StrChar
 * \return A pointer to a StrChar, either newly constructed or shared
 */
RS_StrChar RS_makeStrCharStrChar(const char* string) {
  return (RS_StrChar)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a StrCon of type RS_StrCon. Like all ATerm types, RS_StrCons are maximally shared.
 * \param[in] string a child of the new StrCon
 * \return A pointer to a StrCon, either newly constructed or shared
 */
RS_StrCon RS_makeStrConStrCon(const char* string) {
  return (RS_StrCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a true of type RS_BoolCon. Like all ATerm types, RS_BoolCons are maximally shared.
 * \return A pointer to a true, either newly constructed or shared
 */
RS_BoolCon RS_makeBoolConTrue(void) {
  return (RS_BoolCon)(ATerm)ATmakeAppl0(RS_afun16);
}
/**
 * Constructs a false of type RS_BoolCon. Like all ATerm types, RS_BoolCons are maximally shared.
 * \return A pointer to a false, either newly constructed or shared
 */
RS_BoolCon RS_makeBoolConFalse(void) {
  return (RS_BoolCon)(ATerm)ATmakeAppl0(RS_afun17);
}
/**
 * Constructs a NatCon of type RS_NatCon. Like all ATerm types, RS_NatCons are maximally shared.
 * \param[in] string a child of the new NatCon
 * \return A pointer to a NatCon, either newly constructed or shared
 */
RS_NatCon RS_makeNatConNatCon(const char* string) {
  return (RS_NatCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a IdCon of type RS_IdCon. Like all ATerm types, RS_IdCons are maximally shared.
 * \param[in] string a child of the new IdCon
 * \return A pointer to a IdCon, either newly constructed or shared
 */
RS_IdCon RS_makeIdConIdCon(const char* string) {
  return (RS_IdCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a nat-con of type RS_Integer. Like all ATerm types, RS_Integers are maximally shared.
 * \param[in] NatCon a child of the new nat-con
 * \return A pointer to a nat-con, either newly constructed or shared
 */
RS_Integer RS_makeIntegerNatCon(int NatCon) {
  return (RS_Integer)(ATerm)ATmakeAppl1(RS_afun18, (ATerm) (ATerm) ATmakeInt(NatCon));
}
/**
 * Constructs a positive of type RS_Integer. Like all ATerm types, RS_Integers are maximally shared.
 * \param[in] integer a child of the new positive
 * \return A pointer to a positive, either newly constructed or shared
 */
RS_Integer RS_makeIntegerPositive(RS_Integer integer) {
  return (RS_Integer)(ATerm)ATmakeAppl1(RS_afun19, (ATerm) integer);
}
/**
 * Constructs a negative of type RS_Integer. Like all ATerm types, RS_Integers are maximally shared.
 * \param[in] integer a child of the new negative
 * \return A pointer to a negative, either newly constructed or shared
 */
RS_Integer RS_makeIntegerNegative(RS_Integer integer) {
  return (RS_Integer)(ATerm)ATmakeAppl1(RS_afun20, (ATerm) integer);
}
/**
 * Constructs a file of type RS_Location. Like all ATerm types, RS_Locations are maximally shared.
 * \param[in] filename a child of the new file
 * \return A pointer to a file, either newly constructed or shared
 */
RS_Location RS_makeLocationFile(const char* filename) {
  return (RS_Location)(ATerm)ATmakeAppl1(RS_afun21, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)));
}
/**
 * Constructs a area of type RS_Location. Like all ATerm types, RS_Locations are maximally shared.
 * \param[in] Area a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
RS_Location RS_makeLocationArea(RS_Area Area) {
  return (RS_Location)(ATerm)ATmakeAppl1(RS_afun22, (ATerm) Area);
}
/**
 * Constructs a area-in-file of type RS_Location. Like all ATerm types, RS_Locations are maximally shared.
 * \param[in] filename a child of the new area-in-file
 * \param[in] Area a child of the new area-in-file
 * \return A pointer to a area-in-file, either newly constructed or shared
 */
RS_Location RS_makeLocationAreaInFile(const char* filename, RS_Area Area) {
  return (RS_Location)(ATerm)ATmakeAppl2(RS_afun23, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) Area);
}
/**
 * Constructs a area of type RS_Area. Like all ATerm types, RS_Areas are maximally shared.
 * \param[in] beginLine a child of the new area
 * \param[in] beginColumn a child of the new area
 * \param[in] endLine a child of the new area
 * \param[in] endColumn a child of the new area
 * \param[in] offset a child of the new area
 * \param[in] length a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
RS_Area RS_makeAreaArea(int beginLine, int beginColumn, int endLine, int endColumn, int offset, int length) {
  return (RS_Area)(ATerm)ATmakeAppl6(RS_afun24, (ATerm) (ATerm) ATmakeInt(beginLine), (ATerm) (ATerm) ATmakeInt(beginColumn), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endColumn), (ATerm) (ATerm) ATmakeInt(offset), (ATerm) (ATerm) ATmakeInt(length));
}

/**
 * Tests equality of two RS_RElems. A constant time operation.
 * \param[in] arg0 first RS_RElem to be compared
 * \param[in] arg1 second RS_RElem to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualRElem(RS_RElem arg0, RS_RElem arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_RTypes. A constant time operation.
 * \param[in] arg0 first RS_RType to be compared
 * \param[in] arg1 second RS_RType to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualRType(RS_RType arg0, RS_RType arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_RTuples. A constant time operation.
 * \param[in] arg0 first RS_RTuple to be compared
 * \param[in] arg1 second RS_RTuple to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualRTuple(RS_RTuple arg0, RS_RTuple arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_RStores. A constant time operation.
 * \param[in] arg0 first RS_RStore to be compared
 * \param[in] arg1 second RS_RStore to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualRStore(RS_RStore arg0, RS_RStore arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_RElemElementss. A constant time operation.
 * \param[in] arg0 first RS_RElemElements to be compared
 * \param[in] arg1 second RS_RElemElements to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualRElemElements(RS_RElemElements arg0, RS_RElemElements arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_RTypeColumnTypess. A constant time operation.
 * \param[in] arg0 first RS_RTypeColumnTypes to be compared
 * \param[in] arg1 second RS_RTypeColumnTypes to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualRTypeColumnTypes(RS_RTypeColumnTypes arg0, RS_RTypeColumnTypes arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_RTupleRtupless. A constant time operation.
 * \param[in] arg0 first RS_RTupleRtuples to be compared
 * \param[in] arg1 second RS_RTupleRtuples to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualRTupleRtuples(RS_RTupleRtuples arg0, RS_RTupleRtuples arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_StrChars. A constant time operation.
 * \param[in] arg0 first RS_StrChar to be compared
 * \param[in] arg1 second RS_StrChar to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualStrChar(RS_StrChar arg0, RS_StrChar arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_StrCons. A constant time operation.
 * \param[in] arg0 first RS_StrCon to be compared
 * \param[in] arg1 second RS_StrCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualStrCon(RS_StrCon arg0, RS_StrCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_BoolCons. A constant time operation.
 * \param[in] arg0 first RS_BoolCon to be compared
 * \param[in] arg1 second RS_BoolCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualBoolCon(RS_BoolCon arg0, RS_BoolCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_NatCons. A constant time operation.
 * \param[in] arg0 first RS_NatCon to be compared
 * \param[in] arg1 second RS_NatCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualNatCon(RS_NatCon arg0, RS_NatCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_IdCons. A constant time operation.
 * \param[in] arg0 first RS_IdCon to be compared
 * \param[in] arg1 second RS_IdCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualIdCon(RS_IdCon arg0, RS_IdCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_Integers. A constant time operation.
 * \param[in] arg0 first RS_Integer to be compared
 * \param[in] arg1 second RS_Integer to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualInteger(RS_Integer arg0, RS_Integer arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_Locations. A constant time operation.
 * \param[in] arg0 first RS_Location to be compared
 * \param[in] arg1 second RS_Location to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualLocation(RS_Location arg0, RS_Location arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two RS_Areas. A constant time operation.
 * \param[in] arg0 first RS_Area to be compared
 * \param[in] arg1 second RS_Area to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _RS_isEqualArea(RS_Area arg0, RS_Area arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a RS_RElem is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_RElem
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidRElem(RS_RElem arg) {
  if (RS_isRElemInt(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemStr(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemBool(arg)) {
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

/**
 * Assert whether a RS_RElem is a int by checking against the following ATerm pattern: int(<"Integer"("Integer")>). May not be used to assert correctness of the RS_RElem
 * \param[in] arg input RS_RElem
 * \return ATtrue if #arg corresponds to the signature of a int, or ATfalse otherwise
 */
inline ATbool RS_isRElemInt(RS_RElem arg){
  /* checking for: int */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun0) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem is a str by checking against the following ATerm pattern: str(<"StrCon"(str)>). May not be used to assert correctness of the RS_RElem
 * \param[in] arg input RS_RElem
 * \return ATtrue if #arg corresponds to the signature of a str, or ATfalse otherwise
 */
inline ATbool RS_isRElemStr(RS_RElem arg){
  /* checking for: str */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun1) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem is a bool by checking against the following ATerm pattern: bool(<"BoolCon"("BoolCon")>). May not be used to assert correctness of the RS_RElem
 * \param[in] arg input RS_RElem
 * \return ATtrue if #arg corresponds to the signature of a bool, or ATfalse otherwise
 */
inline ATbool RS_isRElemBool(RS_RElem arg){
  /* checking for: bool */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun2) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem is a loc by checking against the following ATerm pattern: loc(<"Location"("Location")>). May not be used to assert correctness of the RS_RElem
 * \param[in] arg input RS_RElem
 * \return ATtrue if #arg corresponds to the signature of a loc, or ATfalse otherwise
 */
inline ATbool RS_isRElemLoc(RS_RElem arg){
  /* checking for: loc */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun3) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem is a set by checking against the following ATerm pattern: set(<"elements"("RElem-elements")>). May not be used to assert correctness of the RS_RElem
 * \param[in] arg input RS_RElem
 * \return ATtrue if #arg corresponds to the signature of a set, or ATfalse otherwise
 */
inline ATbool RS_isRElemSet(RS_RElem arg){
  /* checking for: set */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun4) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem is a bag by checking against the following ATerm pattern: bag(<"elements"("RElem-elements")>). May not be used to assert correctness of the RS_RElem
 * \param[in] arg input RS_RElem
 * \return ATtrue if #arg corresponds to the signature of a bag, or ATfalse otherwise
 */
inline ATbool RS_isRElemBag(RS_RElem arg){
  /* checking for: bag */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun5) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem is a tuple by checking against the following ATerm pattern: tuple(<"elements"("RElem-elements")>). May not be used to assert correctness of the RS_RElem
 * \param[in] arg input RS_RElem
 * \return ATtrue if #arg corresponds to the signature of a tuple, or ATfalse otherwise
 */
inline ATbool RS_isRElemTuple(RS_RElem arg){
  /* checking for: tuple */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun6) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem has a Integer. 
 * \param[in] arg input RS_RElem
 * \return ATtrue if the RS_RElem had a Integer, or ATfalse otherwise
 */
ATbool RS_hasRElemInteger(RS_RElem arg) {
  if (RS_isRElemInt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem has a StrCon. 
 * \param[in] arg input RS_RElem
 * \return ATtrue if the RS_RElem had a StrCon, or ATfalse otherwise
 */
ATbool RS_hasRElemStrCon(RS_RElem arg) {
  if (RS_isRElemStr(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem has a BoolCon. 
 * \param[in] arg input RS_RElem
 * \return ATtrue if the RS_RElem had a BoolCon, or ATfalse otherwise
 */
ATbool RS_hasRElemBoolCon(RS_RElem arg) {
  if (RS_isRElemBool(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem has a Location. 
 * \param[in] arg input RS_RElem
 * \return ATtrue if the RS_RElem had a Location, or ATfalse otherwise
 */
ATbool RS_hasRElemLocation(RS_RElem arg) {
  if (RS_isRElemLoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElem has a elements. 
 * \param[in] arg input RS_RElem
 * \return ATtrue if the RS_RElem had a elements, or ATfalse otherwise
 */
ATbool RS_hasRElemElements(RS_RElem arg) {
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

/**
 * Get the Integer RS_Integer of a RS_RElem. Note that the precondition is that this RS_RElem actually has a Integer
 * \param[in] arg input RS_RElem
 * \return the Integer of #arg, if it exist or an undefined value if it does not
 */
RS_Integer RS_getRElemInteger(RS_RElem arg) {
  
    return (RS_Integer)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the StrCon char* of a RS_RElem. Note that the precondition is that this RS_RElem actually has a StrCon
 * \param[in] arg input RS_RElem
 * \return the StrCon of #arg, if it exist or an undefined value if it does not
 */
char* RS_getRElemStrCon(RS_RElem arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the BoolCon RS_BoolCon of a RS_RElem. Note that the precondition is that this RS_RElem actually has a BoolCon
 * \param[in] arg input RS_RElem
 * \return the BoolCon of #arg, if it exist or an undefined value if it does not
 */
RS_BoolCon RS_getRElemBoolCon(RS_RElem arg) {
  
    return (RS_BoolCon)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the Location RS_Location of a RS_RElem. Note that the precondition is that this RS_RElem actually has a Location
 * \param[in] arg input RS_RElem
 * \return the Location of #arg, if it exist or an undefined value if it does not
 */
RS_Location RS_getRElemLocation(RS_RElem arg) {
  
    return (RS_Location)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the elements RS_RElemElements of a RS_RElem. Note that the precondition is that this RS_RElem actually has a elements
 * \param[in] arg input RS_RElem
 * \return the elements of #arg, if it exist or an undefined value if it does not
 */
RS_RElemElements RS_getRElemElements(RS_RElem arg) {
  if (RS_isRElemSet(arg)) {
    return (RS_RElemElements)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (RS_isRElemBag(arg)) {
    return (RS_RElemElements)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_RElemElements)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Set the Integer of a RS_RElem. The precondition being that this RS_RElem actually has a Integer
 * \param[in] arg input RS_RElem
 * \param[in] Integer new RS_Integer to set in #arg
 * \return A new RS_RElem with Integer at the right place, or a core dump if #arg did not have a Integer
 */
RS_RElem RS_setRElemInteger(RS_RElem arg, RS_Integer Integer) {
  if (RS_isRElemInt(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Integer), 0);
  }

  ATabort("RElem has no Integer: %t\n", arg);
  return (RS_RElem)NULL;
}

/**
 * Set the StrCon of a RS_RElem. The precondition being that this RS_RElem actually has a StrCon
 * \param[in] arg input RS_RElem
 * \param[in] StrCon new const char* to set in #arg
 * \return A new RS_RElem with StrCon at the right place, or a core dump if #arg did not have a StrCon
 */
RS_RElem RS_setRElemStrCon(RS_RElem arg, const char* StrCon) {
  if (RS_isRElemStr(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(StrCon, 0, ATtrue))), 0);
  }

  ATabort("RElem has no StrCon: %t\n", arg);
  return (RS_RElem)NULL;
}

/**
 * Set the BoolCon of a RS_RElem. The precondition being that this RS_RElem actually has a BoolCon
 * \param[in] arg input RS_RElem
 * \param[in] BoolCon new RS_BoolCon to set in #arg
 * \return A new RS_RElem with BoolCon at the right place, or a core dump if #arg did not have a BoolCon
 */
RS_RElem RS_setRElemBoolCon(RS_RElem arg, RS_BoolCon BoolCon) {
  if (RS_isRElemBool(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) BoolCon), 0);
  }

  ATabort("RElem has no BoolCon: %t\n", arg);
  return (RS_RElem)NULL;
}

/**
 * Set the Location of a RS_RElem. The precondition being that this RS_RElem actually has a Location
 * \param[in] arg input RS_RElem
 * \param[in] Location new RS_Location to set in #arg
 * \return A new RS_RElem with Location at the right place, or a core dump if #arg did not have a Location
 */
RS_RElem RS_setRElemLocation(RS_RElem arg, RS_Location Location) {
  if (RS_isRElemLoc(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Location), 0);
  }

  ATabort("RElem has no Location: %t\n", arg);
  return (RS_RElem)NULL;
}

/**
 * Set the elements of a RS_RElem. The precondition being that this RS_RElem actually has a elements
 * \param[in] arg input RS_RElem
 * \param[in] elements new RS_RElemElements to set in #arg
 * \return A new RS_RElem with elements at the right place, or a core dump if #arg did not have a elements
 */
RS_RElem RS_setRElemElements(RS_RElem arg, RS_RElemElements elements) {
  if (RS_isRElemSet(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) elements), 0);
  }
  else if (RS_isRElemBag(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) elements), 0);
  }
  else if (RS_isRElemTuple(arg)) {
    return (RS_RElem)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) elements), 0);
  }

  ATabort("RElem has no Elements: %t\n", arg);
  return (RS_RElem)NULL;
}

/**
 * Assert whether a RS_RType is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidRType(RS_RType arg) {
  if (RS_isRTypeInt(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeBool(arg)) {
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
  else if (RS_isRTypeRelation(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeUserDefined(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a int by checking against the following ATerm pattern: int. May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a int, or ATfalse otherwise
 */
inline ATbool RS_isRTypeInt(RS_RType arg){
  /* checking for: int */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun7) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a bool by checking against the following ATerm pattern: bool. May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a bool, or ATfalse otherwise
 */
inline ATbool RS_isRTypeBool(RS_RType arg){
  /* checking for: bool */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun8) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a str by checking against the following ATerm pattern: str. May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a str, or ATfalse otherwise
 */
inline ATbool RS_isRTypeStr(RS_RType arg){
  /* checking for: str */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun9) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a loc by checking against the following ATerm pattern: loc. May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a loc, or ATfalse otherwise
 */
inline ATbool RS_isRTypeLoc(RS_RType arg){
  /* checking for: loc */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun10) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a tuple by checking against the following ATerm pattern: tuple(<"column-types"("RType-column-types")>). May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a tuple, or ATfalse otherwise
 */
inline ATbool RS_isRTypeTuple(RS_RType arg){
  /* checking for: tuple */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun6) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a set by checking against the following ATerm pattern: set(<"element-type"("RType")>). May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a set, or ATfalse otherwise
 */
inline ATbool RS_isRTypeSet(RS_RType arg){
  /* checking for: set */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun4) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a bag by checking against the following ATerm pattern: bag(<"element-type"("RType")>). May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a bag, or ATfalse otherwise
 */
inline ATbool RS_isRTypeBag(RS_RType arg){
  /* checking for: bag */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun5) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a relation by checking against the following ATerm pattern: relation(<"column-types"("RType-column-types")>). May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a relation, or ATfalse otherwise
 */
inline ATbool RS_isRTypeRelation(RS_RType arg){
  /* checking for: relation */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun11) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a user-defined by checking against the following ATerm pattern: user-defined(<"type-name"("IdCon")>). May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a user-defined, or ATfalse otherwise
 */
inline ATbool RS_isRTypeUserDefined(RS_RType arg){
  /* checking for: user-defined */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun12) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType is a parameter by checking against the following ATerm pattern: parameter(<"parameter-name"("IdCon")>). May not be used to assert correctness of the RS_RType
 * \param[in] arg input RS_RType
 * \return ATtrue if #arg corresponds to the signature of a parameter, or ATfalse otherwise
 */
inline ATbool RS_isRTypeParameter(RS_RType arg){
  /* checking for: parameter */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun13) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType has a column-types. 
 * \param[in] arg input RS_RType
 * \return ATtrue if the RS_RType had a column-types, or ATfalse otherwise
 */
ATbool RS_hasRTypeColumnTypes(RS_RType arg) {
  if (RS_isRTypeTuple(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeRelation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType has a element-type. 
 * \param[in] arg input RS_RType
 * \return ATtrue if the RS_RType had a element-type, or ATfalse otherwise
 */
ATbool RS_hasRTypeElementType(RS_RType arg) {
  if (RS_isRTypeSet(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeBag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType has a type-name. 
 * \param[in] arg input RS_RType
 * \return ATtrue if the RS_RType had a type-name, or ATfalse otherwise
 */
ATbool RS_hasRTypeTypeName(RS_RType arg) {
  if (RS_isRTypeUserDefined(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RType has a parameter-name. 
 * \param[in] arg input RS_RType
 * \return ATtrue if the RS_RType had a parameter-name, or ATfalse otherwise
 */
ATbool RS_hasRTypeParameterName(RS_RType arg) {
  if (RS_isRTypeParameter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the column-types RS_RTypeColumnTypes of a RS_RType. Note that the precondition is that this RS_RType actually has a column-types
 * \param[in] arg input RS_RType
 * \return the column-types of #arg, if it exist or an undefined value if it does not
 */
RS_RTypeColumnTypes RS_getRTypeColumnTypes(RS_RType arg) {
  if (RS_isRTypeTuple(arg)) {
    return (RS_RTypeColumnTypes)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_RTypeColumnTypes)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the element-type RS_RType of a RS_RType. Note that the precondition is that this RS_RType actually has a element-type
 * \param[in] arg input RS_RType
 * \return the element-type of #arg, if it exist or an undefined value if it does not
 */
RS_RType RS_getRTypeElementType(RS_RType arg) {
  if (RS_isRTypeSet(arg)) {
    return (RS_RType)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_RType)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the type-name RS_IdCon of a RS_RType. Note that the precondition is that this RS_RType actually has a type-name
 * \param[in] arg input RS_RType
 * \return the type-name of #arg, if it exist or an undefined value if it does not
 */
RS_IdCon RS_getRTypeTypeName(RS_RType arg) {
  
    return (RS_IdCon)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the parameter-name RS_IdCon of a RS_RType. Note that the precondition is that this RS_RType actually has a parameter-name
 * \param[in] arg input RS_RType
 * \return the parameter-name of #arg, if it exist or an undefined value if it does not
 */
RS_IdCon RS_getRTypeParameterName(RS_RType arg) {
  
    return (RS_IdCon)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Set the column-types of a RS_RType. The precondition being that this RS_RType actually has a column-types
 * \param[in] arg input RS_RType
 * \param[in] columnTypes new RS_RTypeColumnTypes to set in #arg
 * \return A new RS_RType with columnTypes at the right place, or a core dump if #arg did not have a columnTypes
 */
RS_RType RS_setRTypeColumnTypes(RS_RType arg, RS_RTypeColumnTypes columnTypes) {
  if (RS_isRTypeTuple(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) columnTypes), 0);
  }
  else if (RS_isRTypeRelation(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) columnTypes), 0);
  }

  ATabort("RType has no ColumnTypes: %t\n", arg);
  return (RS_RType)NULL;
}

/**
 * Set the element-type of a RS_RType. The precondition being that this RS_RType actually has a element-type
 * \param[in] arg input RS_RType
 * \param[in] elementType new RS_RType to set in #arg
 * \return A new RS_RType with elementType at the right place, or a core dump if #arg did not have a elementType
 */
RS_RType RS_setRTypeElementType(RS_RType arg, RS_RType elementType) {
  if (RS_isRTypeSet(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) elementType), 0);
  }
  else if (RS_isRTypeBag(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) elementType), 0);
  }

  ATabort("RType has no ElementType: %t\n", arg);
  return (RS_RType)NULL;
}

/**
 * Set the type-name of a RS_RType. The precondition being that this RS_RType actually has a type-name
 * \param[in] arg input RS_RType
 * \param[in] typeName new RS_IdCon to set in #arg
 * \return A new RS_RType with typeName at the right place, or a core dump if #arg did not have a typeName
 */
RS_RType RS_setRTypeTypeName(RS_RType arg, RS_IdCon typeName) {
  if (RS_isRTypeUserDefined(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) typeName), 0);
  }

  ATabort("RType has no TypeName: %t\n", arg);
  return (RS_RType)NULL;
}

/**
 * Set the parameter-name of a RS_RType. The precondition being that this RS_RType actually has a parameter-name
 * \param[in] arg input RS_RType
 * \param[in] parameterName new RS_IdCon to set in #arg
 * \return A new RS_RType with parameterName at the right place, or a core dump if #arg did not have a parameterName
 */
RS_RType RS_setRTypeParameterName(RS_RType arg, RS_IdCon parameterName) {
  if (RS_isRTypeParameter(arg)) {
    return (RS_RType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) parameterName), 0);
  }

  ATabort("RType has no ParameterName: %t\n", arg);
  return (RS_RType)NULL;
}

/**
 * Assert whether a RS_RTuple is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_RTuple
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidRTuple(RS_RTuple arg) {
  if (RS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTuple is a rtuple by checking against the following ATerm pattern: rtuple(<"variable"("IdCon")>,<"rtype"("RType")>,<"value"("RElem")>). Always returns ATtrue
 * \param[in] arg input RS_RTuple
 * \return ATtrue if #arg corresponds to the signature of a rtuple, or ATfalse otherwise
 */
inline ATbool RS_isRTupleRtuple(RS_RTuple arg){
  /* checking for: rtuple */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun14) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTuple has a variable. 
 * \param[in] arg input RS_RTuple
 * \return ATtrue if the RS_RTuple had a variable, or ATfalse otherwise
 */
ATbool RS_hasRTupleVariable(RS_RTuple arg) {
  if (RS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTuple has a rtype. 
 * \param[in] arg input RS_RTuple
 * \return ATtrue if the RS_RTuple had a rtype, or ATfalse otherwise
 */
ATbool RS_hasRTupleRtype(RS_RTuple arg) {
  if (RS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTuple has a value. 
 * \param[in] arg input RS_RTuple
 * \return ATtrue if the RS_RTuple had a value, or ATfalse otherwise
 */
ATbool RS_hasRTupleValue(RS_RTuple arg) {
  if (RS_isRTupleRtuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the variable RS_IdCon of a RS_RTuple. Note that the precondition is that this RS_RTuple actually has a variable
 * \param[in] arg input RS_RTuple
 * \return the variable of #arg, if it exist or an undefined value if it does not
 */
RS_IdCon RS_getRTupleVariable(RS_RTuple arg) {
  
    return (RS_IdCon)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the rtype RS_RType of a RS_RTuple. Note that the precondition is that this RS_RTuple actually has a rtype
 * \param[in] arg input RS_RTuple
 * \return the rtype of #arg, if it exist or an undefined value if it does not
 */
RS_RType RS_getRTupleRtype(RS_RTuple arg) {
  
    return (RS_RType)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Get the value RS_RElem of a RS_RTuple. Note that the precondition is that this RS_RTuple actually has a value
 * \param[in] arg input RS_RTuple
 * \return the value of #arg, if it exist or an undefined value if it does not
 */
RS_RElem RS_getRTupleValue(RS_RTuple arg) {
  
    return (RS_RElem)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Set the variable of a RS_RTuple. The precondition being that this RS_RTuple actually has a variable
 * \param[in] arg input RS_RTuple
 * \param[in] variable new RS_IdCon to set in #arg
 * \return A new RS_RTuple with variable at the right place, or a core dump if #arg did not have a variable
 */
RS_RTuple RS_setRTupleVariable(RS_RTuple arg, RS_IdCon variable) {
  if (RS_isRTupleRtuple(arg)) {
    return (RS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) variable), 0);
  }

  ATabort("RTuple has no Variable: %t\n", arg);
  return (RS_RTuple)NULL;
}

/**
 * Set the rtype of a RS_RTuple. The precondition being that this RS_RTuple actually has a rtype
 * \param[in] arg input RS_RTuple
 * \param[in] rtype new RS_RType to set in #arg
 * \return A new RS_RTuple with rtype at the right place, or a core dump if #arg did not have a rtype
 */
RS_RTuple RS_setRTupleRtype(RS_RTuple arg, RS_RType rtype) {
  if (RS_isRTupleRtuple(arg)) {
    return (RS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) rtype), 1);
  }

  ATabort("RTuple has no Rtype: %t\n", arg);
  return (RS_RTuple)NULL;
}

/**
 * Set the value of a RS_RTuple. The precondition being that this RS_RTuple actually has a value
 * \param[in] arg input RS_RTuple
 * \param[in] value new RS_RElem to set in #arg
 * \return A new RS_RTuple with value at the right place, or a core dump if #arg did not have a value
 */
RS_RTuple RS_setRTupleValue(RS_RTuple arg, RS_RElem value) {
  if (RS_isRTupleRtuple(arg)) {
    return (RS_RTuple)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) value), 2);
  }

  ATabort("RTuple has no Value: %t\n", arg);
  return (RS_RTuple)NULL;
}

/**
 * Assert whether a RS_RStore is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_RStore
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidRStore(RS_RStore arg) {
  if (RS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RStore is a rstore by checking against the following ATerm pattern: rstore(<"rtuples"("RTuple-rtuples")>). Always returns ATtrue
 * \param[in] arg input RS_RStore
 * \return ATtrue if #arg corresponds to the signature of a rstore, or ATfalse otherwise
 */
inline ATbool RS_isRStoreRstore(RS_RStore arg){
  /* checking for: rstore */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun15) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RStore has a rtuples. 
 * \param[in] arg input RS_RStore
 * \return ATtrue if the RS_RStore had a rtuples, or ATfalse otherwise
 */
ATbool RS_hasRStoreRtuples(RS_RStore arg) {
  if (RS_isRStoreRstore(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the rtuples RS_RTupleRtuples of a RS_RStore. Note that the precondition is that this RS_RStore actually has a rtuples
 * \param[in] arg input RS_RStore
 * \return the rtuples of #arg, if it exist or an undefined value if it does not
 */
RS_RTupleRtuples RS_getRStoreRtuples(RS_RStore arg) {
  
    return (RS_RTupleRtuples)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Set the rtuples of a RS_RStore. The precondition being that this RS_RStore actually has a rtuples
 * \param[in] arg input RS_RStore
 * \param[in] rtuples new RS_RTupleRtuples to set in #arg
 * \return A new RS_RStore with rtuples at the right place, or a core dump if #arg did not have a rtuples
 */
RS_RStore RS_setRStoreRtuples(RS_RStore arg, RS_RTupleRtuples rtuples) {
  if (RS_isRStoreRstore(arg)) {
    return (RS_RStore)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) rtuples), 0);
  }

  ATabort("RStore has no Rtuples: %t\n", arg);
  return (RS_RStore)NULL;
}

/**
 * Assert whether a RS_RElemElements is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_RElemElements
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidRElemElements(RS_RElemElements arg) {
  if (RS_isRElemElementsEmpty(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemElementsSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemElementsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElemElements is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the RS_RElemElements
 * \param[in] arg input RS_RElemElements
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool RS_isRElemElementsEmpty(RS_RElemElements arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElemElements is a single by checking against the following ATerm pattern: [<head(RElem)>]. May not be used to assert correctness of the RS_RElemElements
 * \param[in] arg input RS_RElemElements
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool RS_isRElemElementsSingle(RS_RElemElements arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElemElements is a many by checking against the following ATerm pattern: [<head(RElem)>,<[tail(RElem-elements)]>]. May not be used to assert correctness of the RS_RElemElements
 * \param[in] arg input RS_RElemElements
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool RS_isRElemElementsMany(RS_RElemElements arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElemElements has a head. 
 * \param[in] arg input RS_RElemElements
 * \return ATtrue if the RS_RElemElements had a head, or ATfalse otherwise
 */
ATbool RS_hasRElemElementsHead(RS_RElemElements arg) {
  if (RS_isRElemElementsSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRElemElementsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RElemElements has a tail. 
 * \param[in] arg input RS_RElemElements
 * \return ATtrue if the RS_RElemElements had a tail, or ATfalse otherwise
 */
ATbool RS_hasRElemElementsTail(RS_RElemElements arg) {
  if (RS_isRElemElementsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head RS_RElem of a RS_RElemElements. Note that the precondition is that this RS_RElemElements actually has a head
 * \param[in] arg input RS_RElemElements
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
RS_RElem RS_getRElemElementsHead(RS_RElemElements arg) {
  if (RS_isRElemElementsSingle(arg)) {
    return (RS_RElem)ATgetFirst((ATermList)arg);
  }
  else 
    return (RS_RElem)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail RS_RElemElements of a RS_RElemElements. Note that the precondition is that this RS_RElemElements actually has a tail
 * \param[in] arg input RS_RElemElements
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
RS_RElemElements RS_getRElemElementsTail(RS_RElemElements arg) {
  
    return (RS_RElemElements)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a RS_RElemElements. The precondition being that this RS_RElemElements actually has a head
 * \param[in] arg input RS_RElemElements
 * \param[in] head new RS_RElem to set in #arg
 * \return A new RS_RElemElements with head at the right place, or a core dump if #arg did not have a head
 */
RS_RElemElements RS_setRElemElementsHead(RS_RElemElements arg, RS_RElem head) {
  if (RS_isRElemElementsSingle(arg)) {
    return (RS_RElemElements)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (RS_isRElemElementsMany(arg)) {
    return (RS_RElemElements)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RElemElements has no Head: %t\n", arg);
  return (RS_RElemElements)NULL;
}

/**
 * Set the tail of a RS_RElemElements. The precondition being that this RS_RElemElements actually has a tail
 * \param[in] arg input RS_RElemElements
 * \param[in] tail new RS_RElemElements to set in #arg
 * \return A new RS_RElemElements with tail at the right place, or a core dump if #arg did not have a tail
 */
RS_RElemElements RS_setRElemElementsTail(RS_RElemElements arg, RS_RElemElements tail) {
  if (RS_isRElemElementsMany(arg)) {
    return (RS_RElemElements)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("RElemElements has no Tail: %t\n", arg);
  return (RS_RElemElements)NULL;
}

/**
 * Assert whether a RS_RTypeColumnTypes is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_RTypeColumnTypes
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidRTypeColumnTypes(RS_RTypeColumnTypes arg) {
  if (RS_isRTypeColumnTypesEmpty(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeColumnTypesSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeColumnTypesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTypeColumnTypes is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the RS_RTypeColumnTypes
 * \param[in] arg input RS_RTypeColumnTypes
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool RS_isRTypeColumnTypesEmpty(RS_RTypeColumnTypes arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTypeColumnTypes is a single by checking against the following ATerm pattern: [<head(RType)>]. May not be used to assert correctness of the RS_RTypeColumnTypes
 * \param[in] arg input RS_RTypeColumnTypes
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool RS_isRTypeColumnTypesSingle(RS_RTypeColumnTypes arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTypeColumnTypes is a many by checking against the following ATerm pattern: [<head(RType)>,<[tail(RType-column-types)]>]. May not be used to assert correctness of the RS_RTypeColumnTypes
 * \param[in] arg input RS_RTypeColumnTypes
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool RS_isRTypeColumnTypesMany(RS_RTypeColumnTypes arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTypeColumnTypes has a head. 
 * \param[in] arg input RS_RTypeColumnTypes
 * \return ATtrue if the RS_RTypeColumnTypes had a head, or ATfalse otherwise
 */
ATbool RS_hasRTypeColumnTypesHead(RS_RTypeColumnTypes arg) {
  if (RS_isRTypeColumnTypesSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRTypeColumnTypesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTypeColumnTypes has a tail. 
 * \param[in] arg input RS_RTypeColumnTypes
 * \return ATtrue if the RS_RTypeColumnTypes had a tail, or ATfalse otherwise
 */
ATbool RS_hasRTypeColumnTypesTail(RS_RTypeColumnTypes arg) {
  if (RS_isRTypeColumnTypesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head RS_RType of a RS_RTypeColumnTypes. Note that the precondition is that this RS_RTypeColumnTypes actually has a head
 * \param[in] arg input RS_RTypeColumnTypes
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
RS_RType RS_getRTypeColumnTypesHead(RS_RTypeColumnTypes arg) {
  if (RS_isRTypeColumnTypesSingle(arg)) {
    return (RS_RType)ATgetFirst((ATermList)arg);
  }
  else 
    return (RS_RType)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail RS_RTypeColumnTypes of a RS_RTypeColumnTypes. Note that the precondition is that this RS_RTypeColumnTypes actually has a tail
 * \param[in] arg input RS_RTypeColumnTypes
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
RS_RTypeColumnTypes RS_getRTypeColumnTypesTail(RS_RTypeColumnTypes arg) {
  
    return (RS_RTypeColumnTypes)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a RS_RTypeColumnTypes. The precondition being that this RS_RTypeColumnTypes actually has a head
 * \param[in] arg input RS_RTypeColumnTypes
 * \param[in] head new RS_RType to set in #arg
 * \return A new RS_RTypeColumnTypes with head at the right place, or a core dump if #arg did not have a head
 */
RS_RTypeColumnTypes RS_setRTypeColumnTypesHead(RS_RTypeColumnTypes arg, RS_RType head) {
  if (RS_isRTypeColumnTypesSingle(arg)) {
    return (RS_RTypeColumnTypes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (RS_isRTypeColumnTypesMany(arg)) {
    return (RS_RTypeColumnTypes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RTypeColumnTypes has no Head: %t\n", arg);
  return (RS_RTypeColumnTypes)NULL;
}

/**
 * Set the tail of a RS_RTypeColumnTypes. The precondition being that this RS_RTypeColumnTypes actually has a tail
 * \param[in] arg input RS_RTypeColumnTypes
 * \param[in] tail new RS_RTypeColumnTypes to set in #arg
 * \return A new RS_RTypeColumnTypes with tail at the right place, or a core dump if #arg did not have a tail
 */
RS_RTypeColumnTypes RS_setRTypeColumnTypesTail(RS_RTypeColumnTypes arg, RS_RTypeColumnTypes tail) {
  if (RS_isRTypeColumnTypesMany(arg)) {
    return (RS_RTypeColumnTypes)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("RTypeColumnTypes has no Tail: %t\n", arg);
  return (RS_RTypeColumnTypes)NULL;
}

/**
 * Assert whether a RS_RTupleRtuples is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_RTupleRtuples
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidRTupleRtuples(RS_RTupleRtuples arg) {
  if (RS_isRTupleRtuplesEmpty(arg)) {
    return ATtrue;
  }
  else if (RS_isRTupleRtuplesSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRTupleRtuplesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTupleRtuples is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the RS_RTupleRtuples
 * \param[in] arg input RS_RTupleRtuples
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool RS_isRTupleRtuplesEmpty(RS_RTupleRtuples arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTupleRtuples is a single by checking against the following ATerm pattern: [<head(RTuple)>]. May not be used to assert correctness of the RS_RTupleRtuples
 * \param[in] arg input RS_RTupleRtuples
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool RS_isRTupleRtuplesSingle(RS_RTupleRtuples arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTupleRtuples is a many by checking against the following ATerm pattern: [<head(RTuple)>,<[tail(RTuple-rtuples)]>]. May not be used to assert correctness of the RS_RTupleRtuples
 * \param[in] arg input RS_RTupleRtuples
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool RS_isRTupleRtuplesMany(RS_RTupleRtuples arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTupleRtuples has a head. 
 * \param[in] arg input RS_RTupleRtuples
 * \return ATtrue if the RS_RTupleRtuples had a head, or ATfalse otherwise
 */
ATbool RS_hasRTupleRtuplesHead(RS_RTupleRtuples arg) {
  if (RS_isRTupleRtuplesSingle(arg)) {
    return ATtrue;
  }
  else if (RS_isRTupleRtuplesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_RTupleRtuples has a tail. 
 * \param[in] arg input RS_RTupleRtuples
 * \return ATtrue if the RS_RTupleRtuples had a tail, or ATfalse otherwise
 */
ATbool RS_hasRTupleRtuplesTail(RS_RTupleRtuples arg) {
  if (RS_isRTupleRtuplesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head RS_RTuple of a RS_RTupleRtuples. Note that the precondition is that this RS_RTupleRtuples actually has a head
 * \param[in] arg input RS_RTupleRtuples
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
RS_RTuple RS_getRTupleRtuplesHead(RS_RTupleRtuples arg) {
  if (RS_isRTupleRtuplesSingle(arg)) {
    return (RS_RTuple)ATgetFirst((ATermList)arg);
  }
  else 
    return (RS_RTuple)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail RS_RTupleRtuples of a RS_RTupleRtuples. Note that the precondition is that this RS_RTupleRtuples actually has a tail
 * \param[in] arg input RS_RTupleRtuples
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
RS_RTupleRtuples RS_getRTupleRtuplesTail(RS_RTupleRtuples arg) {
  
    return (RS_RTupleRtuples)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a RS_RTupleRtuples. The precondition being that this RS_RTupleRtuples actually has a head
 * \param[in] arg input RS_RTupleRtuples
 * \param[in] head new RS_RTuple to set in #arg
 * \return A new RS_RTupleRtuples with head at the right place, or a core dump if #arg did not have a head
 */
RS_RTupleRtuples RS_setRTupleRtuplesHead(RS_RTupleRtuples arg, RS_RTuple head) {
  if (RS_isRTupleRtuplesSingle(arg)) {
    return (RS_RTupleRtuples)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (RS_isRTupleRtuplesMany(arg)) {
    return (RS_RTupleRtuples)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RTupleRtuples has no Head: %t\n", arg);
  return (RS_RTupleRtuples)NULL;
}

/**
 * Set the tail of a RS_RTupleRtuples. The precondition being that this RS_RTupleRtuples actually has a tail
 * \param[in] arg input RS_RTupleRtuples
 * \param[in] tail new RS_RTupleRtuples to set in #arg
 * \return A new RS_RTupleRtuples with tail at the right place, or a core dump if #arg did not have a tail
 */
RS_RTupleRtuples RS_setRTupleRtuplesTail(RS_RTupleRtuples arg, RS_RTupleRtuples tail) {
  if (RS_isRTupleRtuplesMany(arg)) {
    return (RS_RTupleRtuples)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("RTupleRtuples has no Tail: %t\n", arg);
  return (RS_RTupleRtuples)NULL;
}

/**
 * Assert whether a RS_StrChar is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_StrChar
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidStrChar(RS_StrChar arg) {
  if (RS_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_StrChar is a StrChar by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input RS_StrChar
 * \return ATtrue if #arg corresponds to the signature of a StrChar, or ATfalse otherwise
 */
inline ATbool RS_isStrCharStrChar(RS_StrChar arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_StrChar has a string. 
 * \param[in] arg input RS_StrChar
 * \return ATtrue if the RS_StrChar had a string, or ATfalse otherwise
 */
ATbool RS_hasStrCharString(RS_StrChar arg) {
  if (RS_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a RS_StrChar. Note that the precondition is that this RS_StrChar actually has a string
 * \param[in] arg input RS_StrChar
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* RS_getStrCharString(RS_StrChar arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a RS_StrChar. The precondition being that this RS_StrChar actually has a string
 * \param[in] arg input RS_StrChar
 * \param[in] string new const char* to set in #arg
 * \return A new RS_StrChar with string at the right place, or a core dump if #arg did not have a string
 */
RS_StrChar RS_setStrCharString(RS_StrChar arg, const char* string) {
  if (RS_isStrCharStrChar(arg)) {
    return (RS_StrChar)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrChar has no String: %t\n", arg);
  return (RS_StrChar)NULL;
}

/**
 * Assert whether a RS_StrCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_StrCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidStrCon(RS_StrCon arg) {
  if (RS_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_StrCon is a StrCon by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input RS_StrCon
 * \return ATtrue if #arg corresponds to the signature of a StrCon, or ATfalse otherwise
 */
inline ATbool RS_isStrConStrCon(RS_StrCon arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_StrCon has a string. 
 * \param[in] arg input RS_StrCon
 * \return ATtrue if the RS_StrCon had a string, or ATfalse otherwise
 */
ATbool RS_hasStrConString(RS_StrCon arg) {
  if (RS_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a RS_StrCon. Note that the precondition is that this RS_StrCon actually has a string
 * \param[in] arg input RS_StrCon
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* RS_getStrConString(RS_StrCon arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a RS_StrCon. The precondition being that this RS_StrCon actually has a string
 * \param[in] arg input RS_StrCon
 * \param[in] string new const char* to set in #arg
 * \return A new RS_StrCon with string at the right place, or a core dump if #arg did not have a string
 */
RS_StrCon RS_setStrConString(RS_StrCon arg, const char* string) {
  if (RS_isStrConStrCon(arg)) {
    return (RS_StrCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrCon has no String: %t\n", arg);
  return (RS_StrCon)NULL;
}

/**
 * Assert whether a RS_BoolCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_BoolCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidBoolCon(RS_BoolCon arg) {
  if (RS_isBoolConTrue(arg)) {
    return ATtrue;
  }
  else if (RS_isBoolConFalse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_BoolCon is a true by checking against the following ATerm pattern: true. May not be used to assert correctness of the RS_BoolCon
 * \param[in] arg input RS_BoolCon
 * \return ATtrue if #arg corresponds to the signature of a true, or ATfalse otherwise
 */
inline ATbool RS_isBoolConTrue(RS_BoolCon arg){
  /* checking for: true */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun16) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_BoolCon is a false by checking against the following ATerm pattern: false. May not be used to assert correctness of the RS_BoolCon
 * \param[in] arg input RS_BoolCon
 * \return ATtrue if #arg corresponds to the signature of a false, or ATfalse otherwise
 */
inline ATbool RS_isBoolConFalse(RS_BoolCon arg){
  /* checking for: false */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun17) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_NatCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_NatCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidNatCon(RS_NatCon arg) {
  if (RS_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_NatCon is a NatCon by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input RS_NatCon
 * \return ATtrue if #arg corresponds to the signature of a NatCon, or ATfalse otherwise
 */
inline ATbool RS_isNatConNatCon(RS_NatCon arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_NatCon has a string. 
 * \param[in] arg input RS_NatCon
 * \return ATtrue if the RS_NatCon had a string, or ATfalse otherwise
 */
ATbool RS_hasNatConString(RS_NatCon arg) {
  if (RS_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a RS_NatCon. Note that the precondition is that this RS_NatCon actually has a string
 * \param[in] arg input RS_NatCon
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* RS_getNatConString(RS_NatCon arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a RS_NatCon. The precondition being that this RS_NatCon actually has a string
 * \param[in] arg input RS_NatCon
 * \param[in] string new const char* to set in #arg
 * \return A new RS_NatCon with string at the right place, or a core dump if #arg did not have a string
 */
RS_NatCon RS_setNatConString(RS_NatCon arg, const char* string) {
  if (RS_isNatConNatCon(arg)) {
    return (RS_NatCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("NatCon has no String: %t\n", arg);
  return (RS_NatCon)NULL;
}

/**
 * Assert whether a RS_IdCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_IdCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidIdCon(RS_IdCon arg) {
  if (RS_isIdConIdCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_IdCon is a IdCon by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input RS_IdCon
 * \return ATtrue if #arg corresponds to the signature of a IdCon, or ATfalse otherwise
 */
inline ATbool RS_isIdConIdCon(RS_IdCon arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_IdCon has a string. 
 * \param[in] arg input RS_IdCon
 * \return ATtrue if the RS_IdCon had a string, or ATfalse otherwise
 */
ATbool RS_hasIdConString(RS_IdCon arg) {
  if (RS_isIdConIdCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a RS_IdCon. Note that the precondition is that this RS_IdCon actually has a string
 * \param[in] arg input RS_IdCon
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* RS_getIdConString(RS_IdCon arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a RS_IdCon. The precondition being that this RS_IdCon actually has a string
 * \param[in] arg input RS_IdCon
 * \param[in] string new const char* to set in #arg
 * \return A new RS_IdCon with string at the right place, or a core dump if #arg did not have a string
 */
RS_IdCon RS_setIdConString(RS_IdCon arg, const char* string) {
  if (RS_isIdConIdCon(arg)) {
    return (RS_IdCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("IdCon has no String: %t\n", arg);
  return (RS_IdCon)NULL;
}

/**
 * Assert whether a RS_Integer is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_Integer
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidInteger(RS_Integer arg) {
  if (RS_isIntegerNatCon(arg)) {
    return ATtrue;
  }
  else if (RS_isIntegerPositive(arg)) {
    return ATtrue;
  }
  else if (RS_isIntegerNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Integer is a nat-con by checking against the following ATerm pattern: nat-con(<"NatCon"(int)>). May not be used to assert correctness of the RS_Integer
 * \param[in] arg input RS_Integer
 * \return ATtrue if #arg corresponds to the signature of a nat-con, or ATfalse otherwise
 */
inline ATbool RS_isIntegerNatCon(RS_Integer arg){
  /* checking for: nat-con */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun18) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Integer is a positive by checking against the following ATerm pattern: positive(<"integer"("Integer")>). May not be used to assert correctness of the RS_Integer
 * \param[in] arg input RS_Integer
 * \return ATtrue if #arg corresponds to the signature of a positive, or ATfalse otherwise
 */
inline ATbool RS_isIntegerPositive(RS_Integer arg){
  /* checking for: positive */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun19) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Integer is a negative by checking against the following ATerm pattern: negative(<"integer"("Integer")>). May not be used to assert correctness of the RS_Integer
 * \param[in] arg input RS_Integer
 * \return ATtrue if #arg corresponds to the signature of a negative, or ATfalse otherwise
 */
inline ATbool RS_isIntegerNegative(RS_Integer arg){
  /* checking for: negative */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun20) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Integer has a NatCon. 
 * \param[in] arg input RS_Integer
 * \return ATtrue if the RS_Integer had a NatCon, or ATfalse otherwise
 */
ATbool RS_hasIntegerNatCon(RS_Integer arg) {
  if (RS_isIntegerNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Integer has a integer. 
 * \param[in] arg input RS_Integer
 * \return ATtrue if the RS_Integer had a integer, or ATfalse otherwise
 */
ATbool RS_hasIntegerInteger(RS_Integer arg) {
  if (RS_isIntegerPositive(arg)) {
    return ATtrue;
  }
  else if (RS_isIntegerNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the NatCon int of a RS_Integer. Note that the precondition is that this RS_Integer actually has a NatCon
 * \param[in] arg input RS_Integer
 * \return the NatCon of #arg, if it exist or an undefined value if it does not
 */
int RS_getIntegerNatCon(RS_Integer arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the integer RS_Integer of a RS_Integer. Note that the precondition is that this RS_Integer actually has a integer
 * \param[in] arg input RS_Integer
 * \return the integer of #arg, if it exist or an undefined value if it does not
 */
RS_Integer RS_getIntegerInteger(RS_Integer arg) {
  if (RS_isIntegerPositive(arg)) {
    return (RS_Integer)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_Integer)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Set the NatCon of a RS_Integer. The precondition being that this RS_Integer actually has a NatCon
 * \param[in] arg input RS_Integer
 * \param[in] NatCon new int to set in #arg
 * \return A new RS_Integer with NatCon at the right place, or a core dump if #arg did not have a NatCon
 */
RS_Integer RS_setIntegerNatCon(RS_Integer arg, int NatCon) {
  if (RS_isIntegerNatCon(arg)) {
    return (RS_Integer)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(NatCon)), 0);
  }

  ATabort("Integer has no NatCon: %t\n", arg);
  return (RS_Integer)NULL;
}

/**
 * Set the integer of a RS_Integer. The precondition being that this RS_Integer actually has a integer
 * \param[in] arg input RS_Integer
 * \param[in] integer new RS_Integer to set in #arg
 * \return A new RS_Integer with integer at the right place, or a core dump if #arg did not have a integer
 */
RS_Integer RS_setIntegerInteger(RS_Integer arg, RS_Integer integer) {
  if (RS_isIntegerPositive(arg)) {
    return (RS_Integer)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) integer), 0);
  }
  else if (RS_isIntegerNegative(arg)) {
    return (RS_Integer)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) integer), 0);
  }

  ATabort("Integer has no Integer: %t\n", arg);
  return (RS_Integer)NULL;
}

/**
 * Assert whether a RS_Location is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_Location
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidLocation(RS_Location arg) {
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

/**
 * Assert whether a RS_Location is a file by checking against the following ATerm pattern: file(<"filename"(str)>). May not be used to assert correctness of the RS_Location
 * \param[in] arg input RS_Location
 * \return ATtrue if #arg corresponds to the signature of a file, or ATfalse otherwise
 */
inline ATbool RS_isLocationFile(RS_Location arg){
  /* checking for: file */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun21) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Location is a area by checking against the following ATerm pattern: area(<"Area"("Area")>). May not be used to assert correctness of the RS_Location
 * \param[in] arg input RS_Location
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool RS_isLocationArea(RS_Location arg){
  /* checking for: area */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun22) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Location is a area-in-file by checking against the following ATerm pattern: area-in-file(<"filename"(str)>,<"Area"("Area")>). May not be used to assert correctness of the RS_Location
 * \param[in] arg input RS_Location
 * \return ATtrue if #arg corresponds to the signature of a area-in-file, or ATfalse otherwise
 */
inline ATbool RS_isLocationAreaInFile(RS_Location arg){
  /* checking for: area-in-file */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun23) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Location has a filename. 
 * \param[in] arg input RS_Location
 * \return ATtrue if the RS_Location had a filename, or ATfalse otherwise
 */
ATbool RS_hasLocationFilename(RS_Location arg) {
  if (RS_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Location has a Area. 
 * \param[in] arg input RS_Location
 * \return ATtrue if the RS_Location had a Area, or ATfalse otherwise
 */
ATbool RS_hasLocationArea(RS_Location arg) {
  if (RS_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the filename char* of a RS_Location. Note that the precondition is that this RS_Location actually has a filename
 * \param[in] arg input RS_Location
 * \return the filename of #arg, if it exist or an undefined value if it does not
 */
char* RS_getLocationFilename(RS_Location arg) {
  if (RS_isLocationFile(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the Area RS_Area of a RS_Location. Note that the precondition is that this RS_Location actually has a Area
 * \param[in] arg input RS_Location
 * \return the Area of #arg, if it exist or an undefined value if it does not
 */
RS_Area RS_getLocationArea(RS_Location arg) {
  if (RS_isLocationArea(arg)) {
    return (RS_Area)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (RS_Area)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the filename of a RS_Location. The precondition being that this RS_Location actually has a filename
 * \param[in] arg input RS_Location
 * \param[in] filename new const char* to set in #arg
 * \return A new RS_Location with filename at the right place, or a core dump if #arg did not have a filename
 */
RS_Location RS_setLocationFilename(RS_Location arg, const char* filename) {
  if (RS_isLocationFile(arg)) {
    return (RS_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return (RS_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (RS_Location)NULL;
}

/**
 * Set the Area of a RS_Location. The precondition being that this RS_Location actually has a Area
 * \param[in] arg input RS_Location
 * \param[in] Area new RS_Area to set in #arg
 * \return A new RS_Location with Area at the right place, or a core dump if #arg did not have a Area
 */
RS_Location RS_setLocationArea(RS_Location arg, RS_Area Area) {
  if (RS_isLocationArea(arg)) {
    return (RS_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 0);
  }
  else if (RS_isLocationAreaInFile(arg)) {
    return (RS_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (RS_Location)NULL;
}

/**
 * Assert whether a RS_Area is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input RS_Area
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool RS_isValidArea(RS_Area arg) {
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Area is a area by checking against the following ATerm pattern: area(<"begin-line"(int)>,<"begin-column"(int)>,<"end-line"(int)>,<"end-column"(int)>,<"offset"(int)>,<"length"(int)>). Always returns ATtrue
 * \param[in] arg input RS_Area
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool RS_isAreaArea(RS_Area arg){
  /* checking for: area */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == RS_afun24) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        ATerm arg_arg2 = ATgetArgument(arg, 2);
        if (ATgetType((ATerm)arg_arg2) == AT_INT) {
          ATerm arg_arg3 = ATgetArgument(arg, 3);
          if (ATgetType((ATerm)arg_arg3) == AT_INT) {
            ATerm arg_arg4 = ATgetArgument(arg, 4);
            if (ATgetType((ATerm)arg_arg4) == AT_INT) {
              ATerm arg_arg5 = ATgetArgument(arg, 5);
              if (ATgetType((ATerm)arg_arg5) == AT_INT) {
                return ATtrue;
              }
            }
          }
        }
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Area has a begin-line. 
 * \param[in] arg input RS_Area
 * \return ATtrue if the RS_Area had a begin-line, or ATfalse otherwise
 */
ATbool RS_hasAreaBeginLine(RS_Area arg) {
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Area has a begin-column. 
 * \param[in] arg input RS_Area
 * \return ATtrue if the RS_Area had a begin-column, or ATfalse otherwise
 */
ATbool RS_hasAreaBeginColumn(RS_Area arg) {
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Area has a end-line. 
 * \param[in] arg input RS_Area
 * \return ATtrue if the RS_Area had a end-line, or ATfalse otherwise
 */
ATbool RS_hasAreaEndLine(RS_Area arg) {
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Area has a end-column. 
 * \param[in] arg input RS_Area
 * \return ATtrue if the RS_Area had a end-column, or ATfalse otherwise
 */
ATbool RS_hasAreaEndColumn(RS_Area arg) {
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Area has a offset. 
 * \param[in] arg input RS_Area
 * \return ATtrue if the RS_Area had a offset, or ATfalse otherwise
 */
ATbool RS_hasAreaOffset(RS_Area arg) {
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a RS_Area has a length. 
 * \param[in] arg input RS_Area
 * \return ATtrue if the RS_Area had a length, or ATfalse otherwise
 */
ATbool RS_hasAreaLength(RS_Area arg) {
  if (RS_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the begin-line int of a RS_Area. Note that the precondition is that this RS_Area actually has a begin-line
 * \param[in] arg input RS_Area
 * \return the begin-line of #arg, if it exist or an undefined value if it does not
 */
int RS_getAreaBeginLine(RS_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the begin-column int of a RS_Area. Note that the precondition is that this RS_Area actually has a begin-column
 * \param[in] arg input RS_Area
 * \return the begin-column of #arg, if it exist or an undefined value if it does not
 */
int RS_getAreaBeginColumn(RS_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the end-line int of a RS_Area. Note that the precondition is that this RS_Area actually has a end-line
 * \param[in] arg input RS_Area
 * \return the end-line of #arg, if it exist or an undefined value if it does not
 */
int RS_getAreaEndLine(RS_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/**
 * Get the end-column int of a RS_Area. Note that the precondition is that this RS_Area actually has a end-column
 * \param[in] arg input RS_Area
 * \return the end-column of #arg, if it exist or an undefined value if it does not
 */
int RS_getAreaEndColumn(RS_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 3));
}

/**
 * Get the offset int of a RS_Area. Note that the precondition is that this RS_Area actually has a offset
 * \param[in] arg input RS_Area
 * \return the offset of #arg, if it exist or an undefined value if it does not
 */
int RS_getAreaOffset(RS_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 4));
}

/**
 * Get the length int of a RS_Area. Note that the precondition is that this RS_Area actually has a length
 * \param[in] arg input RS_Area
 * \return the length of #arg, if it exist or an undefined value if it does not
 */
int RS_getAreaLength(RS_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 5));
}

/**
 * Set the begin-line of a RS_Area. The precondition being that this RS_Area actually has a begin-line
 * \param[in] arg input RS_Area
 * \param[in] beginLine new int to set in #arg
 * \return A new RS_Area with beginLine at the right place, or a core dump if #arg did not have a beginLine
 */
RS_Area RS_setAreaBeginLine(RS_Area arg, int beginLine) {
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginLine)), 0);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (RS_Area)NULL;
}

/**
 * Set the begin-column of a RS_Area. The precondition being that this RS_Area actually has a begin-column
 * \param[in] arg input RS_Area
 * \param[in] beginColumn new int to set in #arg
 * \return A new RS_Area with beginColumn at the right place, or a core dump if #arg did not have a beginColumn
 */
RS_Area RS_setAreaBeginColumn(RS_Area arg, int beginColumn) {
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginColumn)), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (RS_Area)NULL;
}

/**
 * Set the end-line of a RS_Area. The precondition being that this RS_Area actually has a end-line
 * \param[in] arg input RS_Area
 * \param[in] endLine new int to set in #arg
 * \return A new RS_Area with endLine at the right place, or a core dump if #arg did not have a endLine
 */
RS_Area RS_setAreaEndLine(RS_Area arg, int endLine) {
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (RS_Area)NULL;
}

/**
 * Set the end-column of a RS_Area. The precondition being that this RS_Area actually has a end-column
 * \param[in] arg input RS_Area
 * \param[in] endColumn new int to set in #arg
 * \return A new RS_Area with endColumn at the right place, or a core dump if #arg did not have a endColumn
 */
RS_Area RS_setAreaEndColumn(RS_Area arg, int endColumn) {
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endColumn)), 3);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (RS_Area)NULL;
}

/**
 * Set the offset of a RS_Area. The precondition being that this RS_Area actually has a offset
 * \param[in] arg input RS_Area
 * \param[in] offset new int to set in #arg
 * \return A new RS_Area with offset at the right place, or a core dump if #arg did not have a offset
 */
RS_Area RS_setAreaOffset(RS_Area arg, int offset) {
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(offset)), 4);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (RS_Area)NULL;
}

/**
 * Set the length of a RS_Area. The precondition being that this RS_Area actually has a length
 * \param[in] arg input RS_Area
 * \param[in] length new int to set in #arg
 * \return A new RS_Area with length at the right place, or a core dump if #arg did not have a length
 */
RS_Area RS_setAreaLength(RS_Area arg, int length) {
  if (RS_isAreaArea(arg)) {
    return (RS_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 5);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (RS_Area)NULL;
}

/**
 * Apply functions to the children of a RS_RElem. 
 * \return A new RS_RElem with new children where the argument functions might have applied
 */
RS_RElem RS_visitRElem(RS_RElem arg, RS_Integer (*acceptInteger)(RS_Integer), char* (*acceptStrCon)(char*), RS_BoolCon (*acceptBoolCon)(RS_BoolCon), RS_Location (*acceptLocation)(RS_Location), RS_RElemElements (*acceptElements)(RS_RElemElements)) {
  if (RS_isRElemInt(arg)) {
    return RS_makeRElemInt(
        acceptInteger ? acceptInteger(RS_getRElemInteger(arg)) : RS_getRElemInteger(arg));
  }
  if (RS_isRElemStr(arg)) {
    return RS_makeRElemStr(
        acceptStrCon ? acceptStrCon(RS_getRElemStrCon(arg)) : RS_getRElemStrCon(arg));
  }
  if (RS_isRElemBool(arg)) {
    return RS_makeRElemBool(
        acceptBoolCon ? acceptBoolCon(RS_getRElemBoolCon(arg)) : RS_getRElemBoolCon(arg));
  }
  if (RS_isRElemLoc(arg)) {
    return RS_makeRElemLoc(
        acceptLocation ? acceptLocation(RS_getRElemLocation(arg)) : RS_getRElemLocation(arg));
  }
  if (RS_isRElemSet(arg)) {
    return RS_makeRElemSet(
        acceptElements ? acceptElements(RS_getRElemElements(arg)) : RS_getRElemElements(arg));
  }
  if (RS_isRElemBag(arg)) {
    return RS_makeRElemBag(
        acceptElements ? acceptElements(RS_getRElemElements(arg)) : RS_getRElemElements(arg));
  }
  if (RS_isRElemTuple(arg)) {
    return RS_makeRElemTuple(
        acceptElements ? acceptElements(RS_getRElemElements(arg)) : RS_getRElemElements(arg));
  }
  ATabort("not a RElem: %t\n", arg);
  return (RS_RElem)NULL;
}
/**
 * Apply functions to the children of a RS_RType. 
 * \return A new RS_RType with new children where the argument functions might have applied
 */
RS_RType RS_visitRType(RS_RType arg, RS_RTypeColumnTypes (*acceptColumnTypes)(RS_RTypeColumnTypes), RS_IdCon (*acceptTypeName)(RS_IdCon), RS_IdCon (*acceptParameterName)(RS_IdCon)) {
  if (RS_isRTypeInt(arg)) {
    return RS_makeRTypeInt();
  }
  if (RS_isRTypeBool(arg)) {
    return RS_makeRTypeBool();
  }
  if (RS_isRTypeStr(arg)) {
    return RS_makeRTypeStr();
  }
  if (RS_isRTypeLoc(arg)) {
    return RS_makeRTypeLoc();
  }
  if (RS_isRTypeTuple(arg)) {
    return RS_makeRTypeTuple(
        acceptColumnTypes ? acceptColumnTypes(RS_getRTypeColumnTypes(arg)) : RS_getRTypeColumnTypes(arg));
  }
  if (RS_isRTypeSet(arg)) {
    return RS_makeRTypeSet(
        RS_visitRType(RS_getRTypeElementType(arg), acceptColumnTypes, acceptTypeName, acceptParameterName));
  }
  if (RS_isRTypeBag(arg)) {
    return RS_makeRTypeBag(
        RS_visitRType(RS_getRTypeElementType(arg), acceptColumnTypes, acceptTypeName, acceptParameterName));
  }
  if (RS_isRTypeRelation(arg)) {
    return RS_makeRTypeRelation(
        acceptColumnTypes ? acceptColumnTypes(RS_getRTypeColumnTypes(arg)) : RS_getRTypeColumnTypes(arg));
  }
  if (RS_isRTypeUserDefined(arg)) {
    return RS_makeRTypeUserDefined(
        acceptTypeName ? acceptTypeName(RS_getRTypeTypeName(arg)) : RS_getRTypeTypeName(arg));
  }
  if (RS_isRTypeParameter(arg)) {
    return RS_makeRTypeParameter(
        acceptParameterName ? acceptParameterName(RS_getRTypeParameterName(arg)) : RS_getRTypeParameterName(arg));
  }
  ATabort("not a RType: %t\n", arg);
  return (RS_RType)NULL;
}
/**
 * Apply functions to the children of a RS_RTuple. 
 * \return A new RS_RTuple with new children where the argument functions might have applied
 */
RS_RTuple RS_visitRTuple(RS_RTuple arg, RS_IdCon (*acceptVariable)(RS_IdCon), RS_RType (*acceptRtype)(RS_RType), RS_RElem (*acceptValue)(RS_RElem)) {
  if (RS_isRTupleRtuple(arg)) {
    return RS_makeRTupleRtuple(
        acceptVariable ? acceptVariable(RS_getRTupleVariable(arg)) : RS_getRTupleVariable(arg),
        acceptRtype ? acceptRtype(RS_getRTupleRtype(arg)) : RS_getRTupleRtype(arg),
        acceptValue ? acceptValue(RS_getRTupleValue(arg)) : RS_getRTupleValue(arg));
  }
  ATabort("not a RTuple: %t\n", arg);
  return (RS_RTuple)NULL;
}
/**
 * Apply functions to the children of a RS_RStore. 
 * \return A new RS_RStore with new children where the argument functions might have applied
 */
RS_RStore RS_visitRStore(RS_RStore arg, RS_RTupleRtuples (*acceptRtuples)(RS_RTupleRtuples)) {
  if (RS_isRStoreRstore(arg)) {
    return RS_makeRStoreRstore(
        acceptRtuples ? acceptRtuples(RS_getRStoreRtuples(arg)) : RS_getRStoreRtuples(arg));
  }
  ATabort("not a RStore: %t\n", arg);
  return (RS_RStore)NULL;
}
/**
 * Apply functions to the children of a RS_RElemElements. 
 * \return A new RS_RElemElements with new children where the argument functions might have applied
 */
RS_RElemElements RS_visitRElemElements(RS_RElemElements arg, RS_RElem (*acceptHead)(RS_RElem)) {
  if (RS_isRElemElementsEmpty(arg)) {
    return RS_makeRElemElementsEmpty();
  }
  if (RS_isRElemElementsSingle(arg)) {
    return RS_makeRElemElementsSingle(
        acceptHead ? acceptHead(RS_getRElemElementsHead(arg)) : RS_getRElemElementsHead(arg));
  }
  if (RS_isRElemElementsMany(arg)) {
    return RS_makeRElemElementsMany(
        acceptHead ? acceptHead(RS_getRElemElementsHead(arg)) : RS_getRElemElementsHead(arg),
        RS_visitRElemElements(RS_getRElemElementsTail(arg), acceptHead));
  }
  ATabort("not a RElemElements: %t\n", arg);
  return (RS_RElemElements)NULL;
}
/**
 * Apply functions to the children of a RS_RTypeColumnTypes. 
 * \return A new RS_RTypeColumnTypes with new children where the argument functions might have applied
 */
RS_RTypeColumnTypes RS_visitRTypeColumnTypes(RS_RTypeColumnTypes arg, RS_RType (*acceptHead)(RS_RType)) {
  if (RS_isRTypeColumnTypesEmpty(arg)) {
    return RS_makeRTypeColumnTypesEmpty();
  }
  if (RS_isRTypeColumnTypesSingle(arg)) {
    return RS_makeRTypeColumnTypesSingle(
        acceptHead ? acceptHead(RS_getRTypeColumnTypesHead(arg)) : RS_getRTypeColumnTypesHead(arg));
  }
  if (RS_isRTypeColumnTypesMany(arg)) {
    return RS_makeRTypeColumnTypesMany(
        acceptHead ? acceptHead(RS_getRTypeColumnTypesHead(arg)) : RS_getRTypeColumnTypesHead(arg),
        RS_visitRTypeColumnTypes(RS_getRTypeColumnTypesTail(arg), acceptHead));
  }
  ATabort("not a RTypeColumnTypes: %t\n", arg);
  return (RS_RTypeColumnTypes)NULL;
}
/**
 * Apply functions to the children of a RS_RTupleRtuples. 
 * \return A new RS_RTupleRtuples with new children where the argument functions might have applied
 */
RS_RTupleRtuples RS_visitRTupleRtuples(RS_RTupleRtuples arg, RS_RTuple (*acceptHead)(RS_RTuple)) {
  if (RS_isRTupleRtuplesEmpty(arg)) {
    return RS_makeRTupleRtuplesEmpty();
  }
  if (RS_isRTupleRtuplesSingle(arg)) {
    return RS_makeRTupleRtuplesSingle(
        acceptHead ? acceptHead(RS_getRTupleRtuplesHead(arg)) : RS_getRTupleRtuplesHead(arg));
  }
  if (RS_isRTupleRtuplesMany(arg)) {
    return RS_makeRTupleRtuplesMany(
        acceptHead ? acceptHead(RS_getRTupleRtuplesHead(arg)) : RS_getRTupleRtuplesHead(arg),
        RS_visitRTupleRtuples(RS_getRTupleRtuplesTail(arg), acceptHead));
  }
  ATabort("not a RTupleRtuples: %t\n", arg);
  return (RS_RTupleRtuples)NULL;
}
/**
 * Apply functions to the children of a RS_StrChar. 
 * \return A new RS_StrChar with new children where the argument functions might have applied
 */
RS_StrChar RS_visitStrChar(RS_StrChar arg, char* (*acceptString)(char*)) {
  if (RS_isStrCharStrChar(arg)) {
    return RS_makeStrCharStrChar(
        acceptString ? acceptString(RS_getStrCharString(arg)) : RS_getStrCharString(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (RS_StrChar)NULL;
}
/**
 * Apply functions to the children of a RS_StrCon. 
 * \return A new RS_StrCon with new children where the argument functions might have applied
 */
RS_StrCon RS_visitStrCon(RS_StrCon arg, char* (*acceptString)(char*)) {
  if (RS_isStrConStrCon(arg)) {
    return RS_makeStrConStrCon(
        acceptString ? acceptString(RS_getStrConString(arg)) : RS_getStrConString(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (RS_StrCon)NULL;
}
/**
 * Apply functions to the children of a RS_BoolCon. 
 * \return A new RS_BoolCon with new children where the argument functions might have applied
 */
RS_BoolCon RS_visitBoolCon(RS_BoolCon arg) {
  if (RS_isBoolConTrue(arg)) {
    return RS_makeBoolConTrue();
  }
  if (RS_isBoolConFalse(arg)) {
    return RS_makeBoolConFalse();
  }
  ATabort("not a BoolCon: %t\n", arg);
  return (RS_BoolCon)NULL;
}
/**
 * Apply functions to the children of a RS_NatCon. 
 * \return A new RS_NatCon with new children where the argument functions might have applied
 */
RS_NatCon RS_visitNatCon(RS_NatCon arg, char* (*acceptString)(char*)) {
  if (RS_isNatConNatCon(arg)) {
    return RS_makeNatConNatCon(
        acceptString ? acceptString(RS_getNatConString(arg)) : RS_getNatConString(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (RS_NatCon)NULL;
}
/**
 * Apply functions to the children of a RS_IdCon. 
 * \return A new RS_IdCon with new children where the argument functions might have applied
 */
RS_IdCon RS_visitIdCon(RS_IdCon arg, char* (*acceptString)(char*)) {
  if (RS_isIdConIdCon(arg)) {
    return RS_makeIdConIdCon(
        acceptString ? acceptString(RS_getIdConString(arg)) : RS_getIdConString(arg));
  }
  ATabort("not a IdCon: %t\n", arg);
  return (RS_IdCon)NULL;
}
/**
 * Apply functions to the children of a RS_Integer. 
 * \return A new RS_Integer with new children where the argument functions might have applied
 */
RS_Integer RS_visitInteger(RS_Integer arg, int (*acceptNatCon)(int)) {
  if (RS_isIntegerNatCon(arg)) {
    return RS_makeIntegerNatCon(
        acceptNatCon ? acceptNatCon(RS_getIntegerNatCon(arg)) : RS_getIntegerNatCon(arg));
  }
  if (RS_isIntegerPositive(arg)) {
    return RS_makeIntegerPositive(
        RS_visitInteger(RS_getIntegerInteger(arg), acceptNatCon));
  }
  if (RS_isIntegerNegative(arg)) {
    return RS_makeIntegerNegative(
        RS_visitInteger(RS_getIntegerInteger(arg), acceptNatCon));
  }
  ATabort("not a Integer: %t\n", arg);
  return (RS_Integer)NULL;
}
/**
 * Apply functions to the children of a RS_Location. 
 * \return A new RS_Location with new children where the argument functions might have applied
 */
RS_Location RS_visitLocation(RS_Location arg, char* (*acceptFilename)(char*), RS_Area (*acceptArea)(RS_Area)) {
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
/**
 * Apply functions to the children of a RS_Area. 
 * \return A new RS_Area with new children where the argument functions might have applied
 */
RS_Area RS_visitArea(RS_Area arg, int (*acceptBeginLine)(int), int (*acceptBeginColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptOffset)(int), int (*acceptLength)(int)) {
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

