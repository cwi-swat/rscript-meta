package nl.dancingbear.visbase.rstorecontainer;

// Java tool interface RStoreContainerTif
// This file is generated automatically, please do not edit!
// generation time: Feb 17, 2007 12:06:58 AM

import aterm.ATerm;

public interface RStoreContainerTif
{
    public ATerm rcGetFactData(int i0, int i1);

    public ATerm rcGetRstoreFacts(int i0);

    public ATerm rcLoadRstore(String s0);

    public void recTerminate(ATerm t0);
    
    public ATerm rcUnloadRstore(int i0);
    
    public void recAckEvent(ATerm t0);
}
