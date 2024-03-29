// Java tool interface RStoreContainerTif
// This file is generated automatically, please do not edit!
// generation time: Aug 14, 2007 5:22:04 PM

package nl.cwi.sen1.visbase.rstorecontainer;

import aterm.*;

public interface RStoreContainerTif
{
  public ATerm rcUnloadRstore(int i0);
  public ATerm rcGetFactData(int i0, int i1);
  public ATerm rcGetRstore(int i0);
  public ATerm rcGetRstoreFacts(int i0);
  public ATerm rcLoadRstore(String s0);
  public ATerm rcLoadRstore(String s0, ATerm t1);
  public void recAckEvent(ATerm t0);
  public void recTerminate(ATerm t0);
}
