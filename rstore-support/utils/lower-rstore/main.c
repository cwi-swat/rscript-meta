/* $Id: lower-error.c 12896 2004-03-11 12:21:39Z kooiker $ */

/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <aterm2.h>
#include <atb-tool.h>

#include "RStore-utils.h"
#include <ParsedRStore.h>
#include "lower-rstore.h"

/*}}}  */
/*{{{  globals */

static char myname[]    = "lower-error";
static char myversion[] = "1.1";
static char myarguments[] = "hi:o:tV";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
	"This tool lowers parsed rstores to abstract rstores\n"
        "Usage: %s -h -i arg -o arg -Vt . . .\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
	"\t-t              output textual instead of binary (default off)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

/*{{{  ATerm lower_rstore(int cid, ATerm in) */

ATerm lower_rstore(int cid, ATerm in)
{
  ATerm input = ATBunpack(in);
  RS_RStore result = RS_makeRStoreRstore(RS_makeRTupleRtuplesEmpty());

  if (PRS_isValidStart(PRS_StartFromTerm(input))) {
    PRS_RStore tmp = PRS_getStartTopRStore(PRS_StartFromTerm(input));
    result = RS_lowerRStore(tmp);
  }
  else if (PRS_isValidRStore(PRS_RStoreFromTerm(input))) {
    result = RS_lowerRStore(PRS_RStoreFromTerm(input));
  }

  return ATmake("snd-value(lowered-rstore(<term>))", result);
}

/*}}}  */

/*{{{  int rec_terminate(int cid) */

void rec_terminate(int cid, ATerm msg)
{
  exit(0);
}

/*}}}  */

/*{{{  int main (int argc, char *argv[]) */

int main (int argc, char *argv[])
{
  int c; 
  ATerm bottomOfStack;
  ATerm input = NULL;
  ATerm output = NULL;
  ATbool textual = ATfalse;
  char *input_file_name = "-";
  char *output_file_name = "-";
  int i;
  ATbool use_toolbus = ATfalse;

  ATinit(argc, argv, &bottomOfStack);
  RS_initRStoreApi();
  PRS_initParsedRStoreApi();

  for (i=1; !use_toolbus && i < argc; i++) {
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (use_toolbus) {
    int cid;
    ATBinit(argc, argv, &bottomOfStack);

    cid = ATBconnect(NULL, NULL, -1, lower_rstore_handler);
    ATBeventloop();
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != EOF)
      switch (c) {
	case 'h':  usage();                      exit(0);
	case 'i':  input_file_name  = optarg;    break;
	case 'o':  output_file_name = optarg;    break;
	case 't':  textual = ATtrue; break;
	case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
		   exit(0);
	default :  usage();                      exit(1);
      }

    input = ATreadFromNamedFile(input_file_name);

    if(input == NULL) {
      ATerror("%s: could not read term from input file %s\n", 
	      myname, input_file_name);
      return 1;
    }

    if (PRS_isValidRStore((PRS_RStoreFromTerm(input)))) {
      output = (ATerm) RS_lowerRStore(PRS_RStoreFromTerm(input));
    }
    else if (PRS_isValidStart(PRS_StartFromTerm(input))) {
      PRS_RStore tmp = PRS_getStartTopRStore(PRS_StartFromTerm(input));
      output = (ATerm) RS_lowerRStore(tmp);
    }

    if(output != NULL) {
      if (textual) {
	ATwriteToNamedTextFile(output, output_file_name);
      }
      else {
	ATwriteToNamedSAFFile(output, output_file_name);
      }
    }
    else {
      ATwarning("%s: something went wrong\n", myname);
      return 1;
    }
  }

  return 0;
}

/*}}}  */
