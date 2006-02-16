# $Id$

pkgdata_DATA = relation-stores.jar 

EXTRA_DIST = relation-stores.jar 

lib_LIBRARIES = libRStoreAPI.a 

include_HEADERS = \
	RStores.h \
	RStores_dict.h \
	ParsedRStore.h \
	ParsedRStore_dict.h 

libRStoreAPI_a_SOURCES = \
	RStore.c \
	RStore_dict.c \
	ParsedRStore.c \
	ParsedRStore_dict.c 

INCLUDES = -I${ATERM}/include

if MAINTAINER_MODE
#CFLAGS += -DDISABLE_DYNAMIC_CHECKING

BASIC_MODULES = RStores StrCon NatCon Whitespace Locations Areas

api: parsed-api imploded-api # java-api

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

# The java API can not be generated yet because of a bug in apigen
# java-api: RStores.def Makefile
# 	sdf2-to-java \
# 		--imploded \
# 		--input $< \
# 		--name relationstores \
# 		--package nl.cwi.sen1 \
# 		--output . \
# 		--version ${VERSION}
# 	mv relation-stores-${VERSION}.jar relation-stores.jar

endif
