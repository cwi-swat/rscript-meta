# $Id: Makefile.am 21533 2007-02-23 13:48:57Z kooiker $

EXTRA_DIST = $(wildcard *.src)

bin_SCRIPTS = \
	      rscript-meta

CLEANFILES = \
	     rscript-meta

% : %.sh.src Makefile
	sed "s@__EXTERNAL_JARS__@$(EXTERNAL_JARS)@g;\
             s@__PREFIX__@$(prefix)@g;\
	     s@__CONFIG_MANAGER__@${CONFIG_MANAGER_PREFIX}@g;\
	     s@__CONSOLE_GRABBER__@${CONSOLE_GRABBER_PREFIX}@g;\
	     s@__TBSCRIPTS__@$(TOOLBUSFLAGS) -I${prefix}/share/rscript-meta@g;" < $< > $@ && chmod +x $@
