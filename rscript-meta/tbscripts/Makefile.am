# $Id: Makefile.am 21430 2007-02-21 09:50:26Z kooiker $

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
	    parsetable-utils.tb \
	    rscript-module-actions.tb \
	    rscript-actions.tb \
	    rscript-editor-actions.tb \
	    rscript-editor-listeners.tb \
	    rscript-editor-utils.tb \
	    rscript-gui-listeners.tb \
	    rscript-listeners.tb \
	    rscript-meta.tb \
	    rscript-namespace.h \
	    rscript-progress-listener.tb \
	    rscript-transactions.tb \
	    rscript-utils.tb \
	    rscript-module-utils.tb
  
GENERATED_TBSCRIPTS = \
		      rscript-language.tb \
		      rscript-initialize.tb \
		      start-meta-studio.tb

EXTRA_DIST = \
	     $(TBSCRIPTS) \
	     $(GENERATED_TBSCRIPTS:.tb=.tb.src) \
	     standard.rscript.actions

CLEANFILES = \
	     $(GENERATED_TBSCRIPTS)

pkgdata_DATA = \
	       $(TBSCRIPTS) \
	       $(GENERATED_TBSCRIPTS) \
	       standard.rscript.actions

%.tb: %.tb.src Makefile
	sed "s@__RSCRIPTTABLE__@$(RSCRIPT_PREFIX)/share/rscript/rscript.trm.tbl@g; \
             s@__RSCRIPT_META__@$(prefix)/share/rscript-meta@g;" \
	    < $< > $@ 
