GENERATED_TBSCRIPTS = \
	start-rci.tb

EXTRA_DIST = \
	$(foreach i, $(GENERATED_TBSCRIPTS), $i.src) \
	rci.tb \
	rci-test.tb

CLEANFILES = \
	$(GENERATED_TBSCRIPTS) 

pkgdata_DATA = \
	$(GENERATED_TBSCRIPTS) \
	rci.tb \
	rci-test.tb

%.tb : %.tb.src Makefile
	sed "s@__PKGDATA__@${datadir}@g; \
	     s@__LOCAL_JARS__@${LOCAL_JARS}@g; \
	     s@__EXTERNAL_JARS__@${EXTERNAL_JARS}@g; \
	     s@__JARFILE__@${JAVA_JAR}@g;" \
	     < $< \
	     > $@
