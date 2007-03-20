package nl.dancingbear.visbase.rstorecontainer;

// Java tool bridge RStoreContainerBridge
// This file is generated automatically, please do not edit!
// generation time: Feb 17, 2007 12:06:58 AM

import aterm.*;

public class RStoreContainerBridge extends RStoreContainerTool
{
    private RStoreContainerTif tool;

    public RStoreContainerBridge(ATermFactory factory, RStoreContainerTif tool)
    {
        super(factory);
        this.tool = tool;
    }

    public ATerm rcGetFactData(int i0, int i1)
    {
        if (tool != null)
        {
            return tool.rcGetFactData(i0, i1);
        }
        throw new UnsupportedOperationException("method `rcGetFactData' not supported.");
    }

    public ATerm rcGetRstoreFacts(int i0)
    {
        if (tool != null)
        {
            return tool.rcGetRstoreFacts(i0);
        }
        throw new UnsupportedOperationException("method `rcGetRstoreFacts' not supported.");
    }

    public ATerm rcLoadRstore(String s0)
    {
        if (tool != null)
        {
            return tool.rcLoadRstore(s0);
        }
        throw new UnsupportedOperationException("method `rcLoadRstore' not supported.");
    }

    public void recTerminate(ATerm t0)
    {
        if (tool != null)
        {
            tool.recTerminate(t0);
        }
        else
        {
            throw new UnsupportedOperationException("method `recTerminate' not supported.");
        }
    }
    
    public ATerm rcUnloadRstore(int i0)
    {
        if (tool != null)
        {
            return tool.rcUnloadRstore(i0);
        }
        throw new UnsupportedOperationException("method `rcUnloadRstore' not supported.");
    }
    
    public void recAckEvent(ATerm t0)
    {
      if (tool != null) {
        tool.recAckEvent(t0);
      }
      else {
        throw new UnsupportedOperationException("method `recAckEvent' not supported.");
      }
    }
}
