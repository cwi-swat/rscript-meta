include $(top_srcdir)/Makefile.java.meta

ACLOCAL_AMFLAGS = -I .

if MAINTAINER_MODE

BASIC_MODULES = RStores StrCon BoolCon NatCon IdentifierCon IntCon Whitespace Locations Areas

api: java-api

ABS_MODULES = \
	$(foreach i, \
	${BASIC_MODULES} ${ERROR_MODULES} ${LOCATION_MODULES}, \
	${top_srcdir}/../sdf-library/library/basic/$i.sdf)

RStores.def: Makefile
	@(echo "definition"; cat ${ABS_MODULES}) > $@


# The java API can not be generated yet because of a bug in apigen
# Also doesn't work because this currently generates a jar instead of
# a source directory.
java-api: RStores.def Makefile
	sdf2-to-java \
		--imploded \
		--verbose \
		--input $< \
		--name relationstores \
		--package nl.cwi.sen1 \
		--output . \
		--version ${VERSION}
	mv relationstores-${VERSION}.jar relationstores.jar

endif