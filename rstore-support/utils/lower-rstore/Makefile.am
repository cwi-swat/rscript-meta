include $(top_srcdir)/Makefile.meta

bin_PROGRAMS=lower-rstore

AM_CPPFLAGS += \
	-I${top_srcdir}/lib \
	${TOOLBUSLIB_CFLAGS}
	${ATERM_CFLAGS}

lower_rstore_SOURCES=\
	lower-rstore.isrc \
	main.c 

lower_rstore_LDADD=\
	-L${top_builddir}/lib -lRStoreAPI \
	${TOOLBUSLIB_LIBS} \
	${ATERM_LIBS}

pkgdata_DATA = lower-rstore.idef

ERRORS=
EXTRA_DIST+=$(wildcard *.ref) $(wildcard *.tree) 

GENERATED_BY_TESTS = 

CLEANFILES += $(TESTS) $(GENERATED_BY_TESTS)

TESTS=$(foreach e, ${ERRORS}, $e.sh)

%.sh: Makefile
	@(	echo "#! /bin/sh";\
		echo "set -e";\
		echo "./lower-rstore -i ${srcdir}/$*.tree -o $*.trm";\
		echo "${ATERM_PREFIX}/bin/atdiff ${srcdir}/$*.ref $*.trm"\
	) > $@ && chmod +x $@	

