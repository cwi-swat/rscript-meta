include $(top_srcdir)/Makefile.meta

bin_PROGRAMS=lift-rstore

AM_CPPFLAGS += \
	-I${top_srcdir}/lib \
	${TOOLBUSLIB_CFLAGS}
	${ATERM_CFLAGS}

lift_rstore_SOURCES=\
	lift-rstore.isrc \
	main.c 

lift_rstore_LDADD=\
	-L${top_builddir}/lib -lRStoreAPI \
	${TOOLBUSLIB_LIBS} \
	${ATERM_LIBS}

pkgdata_DATA = lift-rstore.idef

ERRORS=
EXTRA_DIST+=$(wildcard *.ref) $(wildcard *.tree) 

GENERATED_BY_TESTS = 

CLEANFILES += $(TESTS) $(GENERATED_BY_TESTS)

TESTS=$(foreach e, ${ERRORS}, $e.sh)

%.sh: Makefile
	@(	echo "#! /bin/sh";\
		echo "set -e";\
		echo "./lift-rstore -i ${srcdir}/$*.tree -o $*.trm";\
		echo "${ATERM_PREFIX}/bin/atdiff ${srcdir}/$*.ref $*.trm"\
	) > $@ && chmod +x $@	

