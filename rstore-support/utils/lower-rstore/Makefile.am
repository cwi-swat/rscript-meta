
bin_PROGRAMS=lower-rstore

AM_CPPFLAGS = \
	-I${top_srcdir}/lib \
	${TOOLBUSLIB_CFLAGS}
	${ATERM_CFLAGS}

lower_rstore_SOURCES=\
	lower-rstore.c \
	lower-rstore.tif.c 

noinst_HEADERS=\
	lower-rstore.tif.h

lower_rstore_LDADD=\
	-L${top_builddir}/lib -lRStoreAPI \
	${TOOLBUSLIB_LIBS} \
	${ATERM_LIBS}

pkgdata_DATA = lower-rstore.idef

ERRORS=
EXTRA_DIST=$(wildcard *.ref) $(wildcard *.tree) lower-rstore.idef.src

GENERATED_BY_TESTS = 

CLEANFILES = $(TESTS) $(GENERATED_BY_TESTS)

TESTS=$(foreach e, ${ERRORS}, $e.sh)

%.sh: Makefile
	@(	echo "#! /bin/sh";\
		echo "set -e";\
		echo "./lower-rstore -i ${srcdir}/$*.tree -o $*.trm";\
		echo "${ATERM_PREFIX}/bin/atdiff ${srcdir}/$*.ref $*.trm"\
	) > $@ && chmod +x $@	

%.idef: %.idef.src
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

if MAINTAINER_MODE

tif: lower-rstore.idef
	toolbus -gentifs $< 
	tifstoc -tool lower-rstore lower-rstore.idef.tifs
endif
