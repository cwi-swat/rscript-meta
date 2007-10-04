// Java tool interface class RStoreContainerTool
// This file is generated automatically, please do not edit!
// generation time: Aug 14, 2007 5:22:04 PM

package nl.cwi.sen1.visbase.rstorecontainer;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

import toolbus.AbstractTool;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;

abstract public class RStoreContainerTool
  extends AbstractTool
  implements RStoreContainerTif
{
  // This table will hold the complete input signature
  private Set<ATerm> sigTable = new HashSet<ATerm>();

  // Patterns that are used to match against incoming terms
  private ATerm PrcUnloadRstore0;
  private ATerm PrcGetFactData0;
  private ATerm PrcGetRstore0;
  private ATerm PrcGetRstoreFacts0;
  private ATerm PrcLoadRstore0;
  private ATerm PrcLoadRstore1;
  private ATerm PrecAckEvent0;
  private ATerm PrecTerminate0;

  // Mimic the constructor from the AbstractTool class
  protected RStoreContainerTool(ATermFactory factory)
  {
    super(factory);
    initSigTable();
    initPatterns();
  }

  // This method initializes the table with input signatures
  private void initSigTable()
  {
    sigTable.add(factory.parse("rec-eval(<rStoreContainer>,rc-load-rstore(<str>))"));
    sigTable.add(factory.parse("rec-eval(<rStoreContainer>,rc-load-rstore(<str>,<term>))"));
    sigTable.add(factory.parse("rec-ack-event(<rStoreContainer>,<term>)"));
    sigTable.add(factory.parse("rec-eval(<rStoreContainer>,rc-get-rstore(<int>))"));
    sigTable.add(factory.parse("rec-eval(<rStoreContainer>,rc-get-rstore-facts(<int>))"));
    sigTable.add(factory.parse("rec-eval(<rStoreContainer>,rc-get-fact-data(<int>,<int>))"));
    sigTable.add(factory.parse("rec-eval(<rStoreContainer>,rc-unload-rstore(<int>))"));
    sigTable.add(factory.parse("rec-terminate(<rStoreContainer>,<term>)"));
  }

  // Initialize the patterns that are used to match against incoming terms
  private void initPatterns()
  {
    PrcUnloadRstore0 = factory.parse("rec-eval(rc-unload-rstore(<int>))");
    PrcGetFactData0 = factory.parse("rec-eval(rc-get-fact-data(<int>,<int>))");
    PrcGetRstore0 = factory.parse("rec-eval(rc-get-rstore(<int>))");
    PrcGetRstoreFacts0 = factory.parse("rec-eval(rc-get-rstore-facts(<int>))");
    PrcLoadRstore0 = factory.parse("rec-eval(rc-load-rstore(<str>))");
    PrcLoadRstore1 = factory.parse("rec-eval(rc-load-rstore(<str>,<term>))");
    PrecAckEvent0 = factory.parse("rec-ack-event(<term>)");
    PrecTerminate0 = factory.parse("rec-terminate(<term>)");
  }

  // The generic handler calls the specific handlers
  public ATerm handler(ATerm term)
  {
    List<?> result;

    result = term.match(PrcUnloadRstore0);
    if (result != null) {
      return rcUnloadRstore(((Integer)result.get(0)).intValue());
    }
    result = term.match(PrcGetFactData0);
    if (result != null) {
      return rcGetFactData(((Integer)result.get(0)).intValue(), ((Integer)result.get(1)).intValue());
    }
    result = term.match(PrcGetRstore0);
    if (result != null) {
      return rcGetRstore(((Integer)result.get(0)).intValue());
    }
    result = term.match(PrcGetRstoreFacts0);
    if (result != null) {
      return rcGetRstoreFacts(((Integer)result.get(0)).intValue());
    }
    result = term.match(PrcLoadRstore0);
    if (result != null) {
      return rcLoadRstore((String)result.get(0));
    }
    result = term.match(PrcLoadRstore1);
    if (result != null) {
      return rcLoadRstore((String)result.get(0), (ATerm)result.get(1));
    }
    result = term.match(PrecAckEvent0);
    if (result != null) {
      recAckEvent((ATerm)result.get(0));
      return null;
    }
    result = term.match(PrecTerminate0);
    if (result != null) {
      recTerminate((ATerm)result.get(0));
      return null;
    }

    notInInputSignature(term);
    return null;
  }

  // Check the input signature
  public void checkInputSignature(ATermList sigs)
  {
    while(!sigs.isEmpty()) {
      ATermAppl sig = (ATermAppl)sigs.getFirst();
      sigs = sigs.getNext();
      if (!sigTable.contains(sig)) {
        // Sorry, but the term is not in the input signature!
        notInInputSignature(sig);
      }
    }
  }

  // This function is called when an input term
  // was not in the input signature.
  void notInInputSignature(ATerm t)
  {
    throw new RuntimeException("term not in input signature: " + t);
  }
}
