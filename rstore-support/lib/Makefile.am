# $Id$

include $(top_srcdir)/Makefile.meta

lib_LTLIBRARIES = libRStoreAPI.la 

include_HEADERS = \
	RStore.h \
	RStore_dict.h \
	ParsedRStore.h \
	ParsedRStore_dict.h \
	RStore-utils.h

libRStoreAPI_la_SOURCES = \
	RStore.c \
	RStore_dict.c \
	ParsedRStore.c \
	ParsedRStore_dict.c  \
	lower.c \
	lift.c

libRStoreAPI_la_CPPFLAGS = $(ATERM_CFLAGS)
libRStoreAPI_la_LDFLAGS  = -avoid-version -no-undefined $(AM_LDFLAGS)
libRStoreAPI_la_LIBADD = $(ATERM_LIBS)

if MAINTAINER_MODE
#CFLAGS += -DDISABLE_DYNAMIC_CHECKING

BASIC_MODULES = RStores StrCon BoolCon NatCon IdentifierCon IntCon Whitespace Locations Areas

api: parsed-api imploded-api 

ABS_MODULES = \
	$(foreach i, \
	${BASIC_MODULES} ${ERROR_MODULES} ${LOCATION_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

RStores.def: Makefile
	@(echo "definition"; cat ${ABS_MODULES}) > $@

parsed-api: RStores.def Makefile  
	sdf2-to-c --input $< --prefix PRS_ --output ParsedRStore
	indent ParsedRStore.h

imploded-api: RStores.def Makefile 
	sdf2-to-c --imploded --input $< --prefix RS_ --output RStore
	indent RStore.h

endif
