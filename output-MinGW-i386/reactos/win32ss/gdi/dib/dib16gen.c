/* This is a generated file. Please do not edit */

#include <win32k.h>

static unsigned Shift1Bpp[] =
{
    0,
    24, 25, 26, 27, 28, 29, 30, 31, 16, 17, 18, 19, 20, 21, 22, 23,
    8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7
};
static unsigned Shift4Bpp[] =
{
    0,
    24, 28, 16, 20, 8, 12, 0, 4
};
static unsigned Shift8Bpp[] =
{
    0,
    24, 16, 8, 0
};
static unsigned Shift16Bpp[] =
{
    0,
    16, 0
};

static void
DIB_16BPP_BitBlt_Generic(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    LONG PatternX =0, PatternY = 0, BasePatternX = 0;
    ULONG Source = 0, Pattern = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    BOOLEAN UsesSource, UsesPattern;
    
    UsesSource = ROP4_USES_SOURCE(BltInfo->Rop4);
    UsesPattern = ROP4_USES_PATTERN(BltInfo->Rop4);
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    if (UsesPattern && NULL != BltInfo->PatternSurface)
    {
        if (UsesSource)
        {
            switch (BltInfo->SourceSurface->iBitmapFormat)
            {
                case BMF_1BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
                    BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                               BltInfo->PatternSurface->sizlBitmap.cy;
                    BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                               BltInfo->PatternSurface->sizlBitmap.cx;
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        PatternX = BasePatternX;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                            SourcePixels--;
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 32;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 32;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 32;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                            SourcePixels--;
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                        {
                            PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                        }
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
                case BMF_4BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
                    BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                               BltInfo->PatternSurface->sizlBitmap.cy;
                    BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                               BltInfo->PatternSurface->sizlBitmap.cx;
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        PatternX = BasePatternX;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                            SourcePixels--;
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 8;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 8;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 8;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                            SourcePixels--;
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                        {
                            PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                        }
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
                case BMF_8BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x) & ~ 0x3);
                    BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                               BltInfo->PatternSurface->sizlBitmap.cy;
                    BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                               BltInfo->PatternSurface->sizlBitmap.cx;
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        PatternX = BasePatternX;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                            SourcePixels--;
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 4;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 4;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 4;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                            SourcePixels--;
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                        {
                            PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                        }
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
                case BMF_16BPP:
                {
                    if (NULL == BltInfo->XlateSourceToDest ||
                        0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
                    {
                        if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                        {
                            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                         BltInfo->SourcePoint.y *
                                         BltInfo->SourceSurface->lDelta +
                                         ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                            BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                       BltInfo->DestRect.top *
                                       BltInfo->DestSurface->lDelta +
                                       BltInfo->DestRect.left * 2;
                            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                           LeftCount) / 2;
                            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                          LeftCount - 2 * CenterCount);
                            PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                                       BltInfo->PatternSurface->sizlBitmap.cy;
                            BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                       BltInfo->PatternSurface->sizlBitmap.cx;
                            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                            {
                                SourcePtr = (PULONG) SourceBase;
                                RawSource = *SourcePtr++;
                                SourcePixels = BaseSourcePixels;
                                DestPtr = (PULONG) DestBase;
                                PatternX = BasePatternX;
                                
                                if (0 != LeftCount)
                                {
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                for (i = 0; i < CenterCount; i++)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                    SourcePixels--;
                                    
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                                    
                                    DestPtr++;
                                }
                                
                                if (0 != RightCount)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                                {
                                    PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                                }
                                SourceBase += BltInfo->SourceSurface->lDelta;
                                DestBase += BltInfo->DestSurface->lDelta;
                            }
                        }
                        else
                        {
                            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                         (BltInfo->SourcePoint.y +
                                          BltInfo->DestRect.bottom -
                                          BltInfo->DestRect.top - 1) *
                                         BltInfo->SourceSurface->lDelta +
                                         ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                            BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                       (BltInfo->DestRect.bottom - 1) *
                                       BltInfo->DestSurface->lDelta +
                                       BltInfo->DestRect.left * 2;
                            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                           LeftCount) / 2;
                            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                          LeftCount - 2 * CenterCount);
                            PatternY = (BltInfo->DestRect.bottom - 1 -
                                        BltInfo->BrushOrigin.y) %
                                       BltInfo->PatternSurface->sizlBitmap.cy;
                            BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                       BltInfo->PatternSurface->sizlBitmap.cx;
                            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                            {
                                SourcePtr = (PULONG) SourceBase;
                                RawSource = *SourcePtr++;
                                SourcePixels = BaseSourcePixels;
                                DestPtr = (PULONG) DestBase;
                                PatternX = BasePatternX;
                                
                                if (0 != LeftCount)
                                {
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                for (i = 0; i < CenterCount; i++)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                    SourcePixels--;
                                    
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                                    
                                    DestPtr++;
                                }
                                
                                if (0 != RightCount)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                if (0 == PatternY--)
                                {
                                    PatternY = BltInfo->PatternSurface->sizlBitmap.cy - 1;
                                }
                                SourceBase -= BltInfo->SourceSurface->lDelta;
                                DestBase -= BltInfo->DestSurface->lDelta;
                            }
                        }
                    }
                    else
                    {
                        if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                        {
                            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                         BltInfo->SourcePoint.y *
                                         BltInfo->SourceSurface->lDelta +
                                         ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                            BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                       BltInfo->DestRect.top *
                                       BltInfo->DestSurface->lDelta +
                                       BltInfo->DestRect.left * 2;
                            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                           LeftCount) / 2;
                            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                          LeftCount - 2 * CenterCount);
                            PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                                       BltInfo->PatternSurface->sizlBitmap.cy;
                            BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                       BltInfo->PatternSurface->sizlBitmap.cx;
                            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                            {
                                SourcePtr = (PULONG) SourceBase;
                                RawSource = *SourcePtr++;
                                SourcePixels = BaseSourcePixels;
                                DestPtr = (PULONG) DestBase;
                                PatternX = BasePatternX;
                                
                                if (0 != LeftCount)
                                {
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                for (i = 0; i < CenterCount; i++)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                    SourcePixels--;
                                    
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                                    
                                    DestPtr++;
                                }
                                
                                if (0 != RightCount)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                                {
                                    PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                                }
                                SourceBase += BltInfo->SourceSurface->lDelta;
                                DestBase += BltInfo->DestSurface->lDelta;
                            }
                        }
                        else
                        {
                            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                         (BltInfo->SourcePoint.y +
                                          BltInfo->DestRect.bottom -
                                          BltInfo->DestRect.top - 1) *
                                         BltInfo->SourceSurface->lDelta +
                                         ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                            BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                       (BltInfo->DestRect.bottom - 1) *
                                       BltInfo->DestSurface->lDelta +
                                       BltInfo->DestRect.left * 2;
                            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                           LeftCount) / 2;
                            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                          LeftCount - 2 * CenterCount);
                            PatternY = (BltInfo->DestRect.bottom - 1 -
                                        BltInfo->BrushOrigin.y) %
                                       BltInfo->PatternSurface->sizlBitmap.cy;
                            BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                       BltInfo->PatternSurface->sizlBitmap.cx;
                            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                            {
                                SourcePtr = (PULONG) SourceBase;
                                RawSource = *SourcePtr++;
                                SourcePixels = BaseSourcePixels;
                                DestPtr = (PULONG) DestBase;
                                PatternX = BasePatternX;
                                
                                if (0 != LeftCount)
                                {
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                for (i = 0; i < CenterCount; i++)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                    SourcePixels--;
                                    
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                                    
                                    DestPtr++;
                                }
                                
                                if (0 != RightCount)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                    {
                                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                    }
                                    
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                if (0 == PatternY--)
                                {
                                    PatternY = BltInfo->PatternSurface->sizlBitmap.cy - 1;
                                }
                                SourceBase -= BltInfo->SourceSurface->lDelta;
                                DestBase -= BltInfo->DestSurface->lDelta;
                            }
                        }
                    }
                    break;
                }
                case BMF_24BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 BltInfo->SourcePoint.x * 3;
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                               BltInfo->PatternSurface->sizlBitmap.cy;
                    BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                               BltInfo->PatternSurface->sizlBitmap.cx;
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        DestPtr = (PULONG) DestBase;
                        PatternX = BasePatternX;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                            SourcePtr = (PULONG)((char *) SourcePtr + 3);
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                            SourcePtr = (PULONG)((char *) SourcePtr + 3);
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                            SourcePtr = (PULONG)((char *) SourcePtr + 3);
                            
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                            SourcePtr = (PULONG)((char *) SourcePtr + 3);
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                        {
                            PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                        }
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
                case BMF_32BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 BltInfo->SourcePoint.x * 4;
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                               BltInfo->PatternSurface->sizlBitmap.cy;
                    BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                               BltInfo->PatternSurface->sizlBitmap.cx;
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        DestPtr = (PULONG) DestBase;
                        PatternX = BasePatternX;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                            
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                            Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                            if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                            {
                                PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                            }
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                        {
                            PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                        }
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
            }
        }
        else
        {
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                       BltInfo->PatternSurface->sizlBitmap.cy;
            BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                       BltInfo->PatternSurface->sizlBitmap.cx;
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                DestPtr = (PULONG) DestBase;
                PatternX = BasePatternX;
                
                if (0 != LeftCount)
                {
                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                    {
                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                    }
                    
                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                    {
                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                    }
                    Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                    {
                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                    }
                    
                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                    if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                    {
                        PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                    }
                    
                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                {
                    PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                }
                DestBase += BltInfo->DestSurface->lDelta;
            }
        }
    }
    else
    {
        if (UsesPattern)
        {
            if (!BltInfo->Brush)
            {
                Pattern = 0;
            }
            else
            {
                Pattern = BltInfo->Brush->iSolidColor |
                          (BltInfo->Brush->iSolidColor << 16);
            }
        }
        if (UsesSource)
        {
            switch (BltInfo->SourceSurface->iBitmapFormat)
            {
                case BMF_1BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
                    BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                            SourcePixels--;
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 32;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 32;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 32;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                            SourcePixels--;
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
                case BMF_4BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
                    BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                            SourcePixels--;
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 8;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 8;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 8;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                            SourcePixels--;
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
                case BMF_8BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x) & ~ 0x3);
                    BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                            SourcePixels--;
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 4;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 4;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 4;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                            SourcePixels--;
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
                case BMF_16BPP:
                {
                    if (NULL == BltInfo->XlateSourceToDest ||
                        0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
                    {
                        if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                        {
                            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                         BltInfo->SourcePoint.y *
                                         BltInfo->SourceSurface->lDelta +
                                         ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                            BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                       BltInfo->DestRect.top *
                                       BltInfo->DestSurface->lDelta +
                                       BltInfo->DestRect.left * 2;
                            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                           LeftCount) / 2;
                            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                          LeftCount - 2 * CenterCount);
                            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                            {
                                SourcePtr = (PULONG) SourceBase;
                                RawSource = *SourcePtr++;
                                SourcePixels = BaseSourcePixels;
                                DestPtr = (PULONG) DestBase;
                                
                                if (0 != LeftCount)
                                {
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                for (i = 0; i < CenterCount; i++)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                    SourcePixels--;
                                    
                                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                                    
                                    DestPtr++;
                                }
                                
                                if (0 != RightCount)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                SourceBase += BltInfo->SourceSurface->lDelta;
                                DestBase += BltInfo->DestSurface->lDelta;
                            }
                        }
                        else
                        {
                            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                         (BltInfo->SourcePoint.y +
                                          BltInfo->DestRect.bottom -
                                          BltInfo->DestRect.top - 1) *
                                         BltInfo->SourceSurface->lDelta +
                                         ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                            BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                       (BltInfo->DestRect.bottom - 1) *
                                       BltInfo->DestSurface->lDelta +
                                       BltInfo->DestRect.left * 2;
                            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                           LeftCount) / 2;
                            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                          LeftCount - 2 * CenterCount);
                            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                            {
                                SourcePtr = (PULONG) SourceBase;
                                RawSource = *SourcePtr++;
                                SourcePixels = BaseSourcePixels;
                                DestPtr = (PULONG) DestBase;
                                
                                if (0 != LeftCount)
                                {
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                for (i = 0; i < CenterCount; i++)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                    SourcePixels--;
                                    
                                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                                    
                                    DestPtr++;
                                }
                                
                                if (0 != RightCount)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                    SourcePixels--;
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                SourceBase -= BltInfo->SourceSurface->lDelta;
                                DestBase -= BltInfo->DestSurface->lDelta;
                            }
                        }
                    }
                    else
                    {
                        if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                        {
                            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                         BltInfo->SourcePoint.y *
                                         BltInfo->SourceSurface->lDelta +
                                         ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                            BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                       BltInfo->DestRect.top *
                                       BltInfo->DestSurface->lDelta +
                                       BltInfo->DestRect.left * 2;
                            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                           LeftCount) / 2;
                            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                          LeftCount - 2 * CenterCount);
                            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                            {
                                SourcePtr = (PULONG) SourceBase;
                                RawSource = *SourcePtr++;
                                SourcePixels = BaseSourcePixels;
                                DestPtr = (PULONG) DestBase;
                                
                                if (0 != LeftCount)
                                {
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                for (i = 0; i < CenterCount; i++)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                    SourcePixels--;
                                    
                                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                                    
                                    DestPtr++;
                                }
                                
                                if (0 != RightCount)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                SourceBase += BltInfo->SourceSurface->lDelta;
                                DestBase += BltInfo->DestSurface->lDelta;
                            }
                        }
                        else
                        {
                            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                         (BltInfo->SourcePoint.y +
                                          BltInfo->DestRect.bottom -
                                          BltInfo->DestRect.top - 1) *
                                         BltInfo->SourceSurface->lDelta +
                                         ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                            BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                       (BltInfo->DestRect.bottom - 1) *
                                       BltInfo->DestSurface->lDelta +
                                       BltInfo->DestRect.left * 2;
                            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                           LeftCount) / 2;
                            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                          LeftCount - 2 * CenterCount);
                            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                            {
                                SourcePtr = (PULONG) SourceBase;
                                RawSource = *SourcePtr++;
                                SourcePixels = BaseSourcePixels;
                                DestPtr = (PULONG) DestBase;
                                
                                if (0 != LeftCount)
                                {
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                for (i = 0; i < CenterCount; i++)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                    SourcePixels--;
                                    
                                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                                    
                                    DestPtr++;
                                }
                                
                                if (0 != RightCount)
                                {
                                    if (0 == SourcePixels)
                                    {
                                        RawSource = *SourcePtr++;
                                        SourcePixels = 2;
                                    }
                                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                    SourcePixels--;
                                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                                    
                                    DestPtr = (PULONG)((char *) DestPtr + 2);
                                }
                                
                                SourceBase -= BltInfo->SourceSurface->lDelta;
                                DestBase -= BltInfo->DestSurface->lDelta;
                            }
                        }
                    }
                    break;
                }
                case BMF_24BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 BltInfo->SourcePoint.x * 3;
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                            SourcePtr = (PULONG)((char *) SourcePtr + 3);
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                            SourcePtr = (PULONG)((char *) SourcePtr + 3);
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                            SourcePtr = (PULONG)((char *) SourcePtr + 3);
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                            SourcePtr = (PULONG)((char *) SourcePtr + 3);
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
                case BMF_32BPP:
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 BltInfo->SourcePoint.x * 4;
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                            
                            *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                            
                            *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                    break;
                }
            }
        }
        else
        {
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    *DestPtr = DIB_DoRop(BltInfo->Rop4, *DestPtr, Source, Pattern);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    *((PUSHORT) DestPtr) = (USHORT) DIB_DoRop(BltInfo->Rop4, *((PUSHORT) DestPtr), Source, Pattern);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                DestBase += BltInfo->DestSurface->lDelta;
            }
        }
    }
}

static void
DIB_16BPP_BitBlt_BLACKNESS(PBLTINFO BltInfo)
{
    DIB_16BPP_ColorFill(BltInfo->DestSurface, &BltInfo->DestRect, 0x0);
}

static void
DIB_16BPP_BitBlt_NOTSRCERASE(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    ULONG Source = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    switch (BltInfo->SourceSurface->iBitmapFormat)
    {
        case BMF_1BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
            BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = ~(*DestPtr | Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_4BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
            BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = ~(*DestPtr | Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_8BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x) & ~ 0x3);
            BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = ~(*DestPtr | Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_16BPP:
        {
            if (NULL == BltInfo->XlateSourceToDest ||
                0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = ~(*DestPtr | Source);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = ~(*DestPtr | Source);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            else
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = ~(*DestPtr | Source);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = ~(*DestPtr | Source);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            break;
        }
        case BMF_24BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 3;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *DestPtr = ~(*DestPtr | Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_32BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 4;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                    
                    *DestPtr = ~(*DestPtr | Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = ~(*((PUSHORT) DestPtr) | (USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
    }
}

static void
DIB_16BPP_BitBlt_NOTSRCCOPY(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    ULONG Source = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    switch (BltInfo->SourceSurface->iBitmapFormat)
    {
        case BMF_1BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
            BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = ~Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_4BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
            BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = ~Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_8BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x) & ~ 0x3);
            BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = ~Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_16BPP:
        {
            if (NULL == BltInfo->XlateSourceToDest ||
                0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = ~Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = ~Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            else
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = ~Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = ~Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = ~(USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            break;
        }
        case BMF_24BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 3;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *DestPtr = ~Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_32BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 4;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                    
                    *DestPtr = ~Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = ~(USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
    }
}

static void
DIB_16BPP_BitBlt_SRCERASE(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    ULONG Source = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    switch (BltInfo->SourceSurface->iBitmapFormat)
    {
        case BMF_1BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
            BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = (~*DestPtr) & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_4BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
            BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = (~*DestPtr) & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_8BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x) & ~ 0x3);
            BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = (~*DestPtr) & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_16BPP:
        {
            if (NULL == BltInfo->XlateSourceToDest ||
                0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = (~*DestPtr) & Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = (~*DestPtr) & Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            else
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = (~*DestPtr) & Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = (~*DestPtr) & Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            break;
        }
        case BMF_24BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 3;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *DestPtr = (~*DestPtr) & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_32BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 4;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                    
                    *DestPtr = (~*DestPtr) & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = (~*((PUSHORT) DestPtr)) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
    }
}

static void
DIB_16BPP_BitBlt_DSTINVERT(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    char *DestBase;
    PULONG DestPtr;
    ULONG LeftCount, CenterCount, RightCount;
    
    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
               BltInfo->DestRect.top *
               BltInfo->DestSurface->lDelta +
               BltInfo->DestRect.left * 2;
    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                   LeftCount) / 2;
    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                  LeftCount - 2 * CenterCount);
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
    {
        DestPtr = (PULONG) DestBase;
        
        if (0 != LeftCount)
        {
            *((PUSHORT) DestPtr) = ~*((PUSHORT) DestPtr);
            
            DestPtr = (PULONG)((char *) DestPtr + 2);
        }
        
        for (i = 0; i < CenterCount; i++)
        {
            *DestPtr = ~*DestPtr;
            
            DestPtr++;
        }
        
        if (0 != RightCount)
        {
            *((PUSHORT) DestPtr) = ~*((PUSHORT) DestPtr);
            
            DestPtr = (PULONG)((char *) DestPtr + 2);
        }
        
        DestBase += BltInfo->DestSurface->lDelta;
    }
}

static void
DIB_16BPP_BitBlt_PATINVERT(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    LONG PatternX =0, PatternY = 0, BasePatternX = 0;
    ULONG Pattern = 0;
    char *DestBase;
    PULONG DestPtr;
    ULONG LeftCount, CenterCount, RightCount;
    
    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
               BltInfo->DestRect.top *
               BltInfo->DestSurface->lDelta +
               BltInfo->DestRect.left * 2;
    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                   LeftCount) / 2;
    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                  LeftCount - 2 * CenterCount);
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    if (NULL != BltInfo->PatternSurface)
    {
        PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                   BltInfo->PatternSurface->sizlBitmap.cy;
        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                   BltInfo->PatternSurface->sizlBitmap.cx;
        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
        {
            DestPtr = (PULONG) DestBase;
            PatternX = BasePatternX;
            
            if (0 != LeftCount)
            {
                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                {
                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                }
                
                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Pattern;
                
                DestPtr = (PULONG)((char *) DestPtr + 2);
            }
            
            for (i = 0; i < CenterCount; i++)
            {
                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                {
                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                }
                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                {
                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                }
                
                *DestPtr = *DestPtr ^ Pattern;
                
                DestPtr++;
            }
            
            if (0 != RightCount)
            {
                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                {
                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                }
                
                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Pattern;
                
                DestPtr = (PULONG)((char *) DestPtr + 2);
            }
            
            if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
            {
                PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
            }
            DestBase += BltInfo->DestSurface->lDelta;
        }
    }
    else
    {
        if (!BltInfo->Brush)
        {
            Pattern = 0;
        }
        else
        {
            Pattern = BltInfo->Brush->iSolidColor |
                      (BltInfo->Brush->iSolidColor << 16);
        }
        if (0 == Pattern)
        {
            return;
        }
        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
        {
            DestPtr = (PULONG) DestBase;
            
            if (0 != LeftCount)
            {
                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Pattern;
                
                DestPtr = (PULONG)((char *) DestPtr + 2);
            }
            
            for (i = 0; i < CenterCount; i++)
            {
                *DestPtr = *DestPtr ^ Pattern;
                
                DestPtr++;
            }
            
            if (0 != RightCount)
            {
                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Pattern;
                
                DestPtr = (PULONG)((char *) DestPtr + 2);
            }
            
            DestBase += BltInfo->DestSurface->lDelta;
        }
    }
}

static void
DIB_16BPP_BitBlt_SRCINVERT(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    ULONG Source = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    switch (BltInfo->SourceSurface->iBitmapFormat)
    {
        case BMF_1BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
            BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr ^ Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_4BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
            BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr ^ Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_8BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x) & ~ 0x3);
            BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr ^ Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_16BPP:
        {
            if (NULL == BltInfo->XlateSourceToDest ||
                0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr ^ Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr ^ Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            else
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr ^ Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr ^ Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            break;
        }
        case BMF_24BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 3;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *DestPtr = *DestPtr ^ Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_32BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 4;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                    
                    *DestPtr = *DestPtr ^ Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) ^ (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
    }
}

static void
DIB_16BPP_BitBlt_SRCAND(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    ULONG Source = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    switch (BltInfo->SourceSurface->iBitmapFormat)
    {
        case BMF_1BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
            BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_4BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
            BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_8BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x) & ~ 0x3);
            BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_16BPP:
        {
            if (NULL == BltInfo->XlateSourceToDest ||
                0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr & Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr & Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            else
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr & Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr & Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            break;
        }
        case BMF_24BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 3;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *DestPtr = *DestPtr & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_32BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 4;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                    
                    *DestPtr = *DestPtr & Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) & (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
    }
}

static void
DIB_16BPP_BitBlt_NOOP(PBLTINFO BltInfo)
{
    return;
}

static void
DIB_16BPP_BitBlt_MERGEPAINT(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    ULONG Source = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    switch (BltInfo->SourceSurface->iBitmapFormat)
    {
        case BMF_1BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
            BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr | (~Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_4BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
            BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr | (~Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_8BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x) & ~ 0x3);
            BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr | (~Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_16BPP:
        {
            if (NULL == BltInfo->XlateSourceToDest ||
                0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr | (~Source);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr | (~Source);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            else
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr | (~Source);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr | (~Source);
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            break;
        }
        case BMF_24BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 3;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *DestPtr = *DestPtr | (~Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_32BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 4;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                    
                    *DestPtr = *DestPtr | (~Source);
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source);
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
    }
}

static void
DIB_16BPP_BitBlt_MERGECOPY(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    LONG PatternX =0, PatternY = 0, BasePatternX = 0;
    ULONG Source = 0, Pattern = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    if (NULL != BltInfo->PatternSurface)
    {
        switch (BltInfo->SourceSurface->iBitmapFormat)
        {
            case BMF_1BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
                BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_4BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
                BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_8BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x) & ~ 0x3);
                BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_16BPP:
            {
                if (NULL == BltInfo->XlateSourceToDest ||
                    0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
                {
                    if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     BltInfo->SourcePoint.y *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   BltInfo->DestRect.top *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                                   BltInfo->PatternSurface->sizlBitmap.cy;
                        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                   BltInfo->PatternSurface->sizlBitmap.cx;
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            PatternX = BasePatternX;
                            
                            if (0 != LeftCount)
                            {
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                SourcePixels--;
                                
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *DestPtr = Source & Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                            {
                                PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                            }
                            SourceBase += BltInfo->SourceSurface->lDelta;
                            DestBase += BltInfo->DestSurface->lDelta;
                        }
                    }
                    else
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     (BltInfo->SourcePoint.y +
                                      BltInfo->DestRect.bottom -
                                      BltInfo->DestRect.top - 1) *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   (BltInfo->DestRect.bottom - 1) *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        PatternY = (BltInfo->DestRect.bottom - 1 -
                                    BltInfo->BrushOrigin.y) %
                                   BltInfo->PatternSurface->sizlBitmap.cy;
                        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                   BltInfo->PatternSurface->sizlBitmap.cx;
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            PatternX = BasePatternX;
                            
                            if (0 != LeftCount)
                            {
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                SourcePixels--;
                                
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *DestPtr = Source & Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            if (0 == PatternY--)
                            {
                                PatternY = BltInfo->PatternSurface->sizlBitmap.cy - 1;
                            }
                            SourceBase -= BltInfo->SourceSurface->lDelta;
                            DestBase -= BltInfo->DestSurface->lDelta;
                        }
                    }
                }
                else
                {
                    if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     BltInfo->SourcePoint.y *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   BltInfo->DestRect.top *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                                   BltInfo->PatternSurface->sizlBitmap.cy;
                        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                   BltInfo->PatternSurface->sizlBitmap.cx;
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            PatternX = BasePatternX;
                            
                            if (0 != LeftCount)
                            {
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                SourcePixels--;
                                
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *DestPtr = Source & Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                            {
                                PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                            }
                            SourceBase += BltInfo->SourceSurface->lDelta;
                            DestBase += BltInfo->DestSurface->lDelta;
                        }
                    }
                    else
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     (BltInfo->SourcePoint.y +
                                      BltInfo->DestRect.bottom -
                                      BltInfo->DestRect.top - 1) *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   (BltInfo->DestRect.bottom - 1) *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        PatternY = (BltInfo->DestRect.bottom - 1 -
                                    BltInfo->BrushOrigin.y) %
                                   BltInfo->PatternSurface->sizlBitmap.cy;
                        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                   BltInfo->PatternSurface->sizlBitmap.cx;
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            PatternX = BasePatternX;
                            
                            if (0 != LeftCount)
                            {
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                SourcePixels--;
                                
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *DestPtr = Source & Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            if (0 == PatternY--)
                            {
                                PatternY = BltInfo->PatternSurface->sizlBitmap.cy - 1;
                            }
                            SourceBase -= BltInfo->SourceSurface->lDelta;
                            DestBase -= BltInfo->DestSurface->lDelta;
                        }
                    }
                }
                break;
            }
            case BMF_24BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             BltInfo->SourcePoint.x * 3;
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_32BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             BltInfo->SourcePoint.x * 4;
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
        }
    }
    else
    {
        if (!BltInfo->Brush)
        {
            Pattern = 0;
        }
        else
        {
            Pattern = BltInfo->Brush->iSolidColor |
                      (BltInfo->Brush->iSolidColor << 16);
        }
        if (0 == Pattern)
        {
            DIB_16BPP_ColorFill(BltInfo->DestSurface, &BltInfo->DestRect, 0x0);
            return;
        }
        switch (BltInfo->SourceSurface->iBitmapFormat)
        {
            case BMF_1BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
                BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_4BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
                BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_8BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x) & ~ 0x3);
                BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_16BPP:
            {
                if (NULL == BltInfo->XlateSourceToDest ||
                    0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
                {
                    if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     BltInfo->SourcePoint.y *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   BltInfo->DestRect.top *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            
                            if (0 != LeftCount)
                            {
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                SourcePixels--;
                                
                                *DestPtr = Source & Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            SourceBase += BltInfo->SourceSurface->lDelta;
                            DestBase += BltInfo->DestSurface->lDelta;
                        }
                    }
                    else
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     (BltInfo->SourcePoint.y +
                                      BltInfo->DestRect.bottom -
                                      BltInfo->DestRect.top - 1) *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   (BltInfo->DestRect.bottom - 1) *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            
                            if (0 != LeftCount)
                            {
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                SourcePixels--;
                                
                                *DestPtr = Source & Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            SourceBase -= BltInfo->SourceSurface->lDelta;
                            DestBase -= BltInfo->DestSurface->lDelta;
                        }
                    }
                }
                else
                {
                    if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     BltInfo->SourcePoint.y *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   BltInfo->DestRect.top *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            
                            if (0 != LeftCount)
                            {
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                SourcePixels--;
                                
                                *DestPtr = Source & Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            SourceBase += BltInfo->SourceSurface->lDelta;
                            DestBase += BltInfo->DestSurface->lDelta;
                        }
                    }
                    else
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     (BltInfo->SourcePoint.y +
                                      BltInfo->DestRect.bottom -
                                      BltInfo->DestRect.top - 1) *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   (BltInfo->DestRect.bottom - 1) *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            
                            if (0 != LeftCount)
                            {
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                SourcePixels--;
                                
                                *DestPtr = Source & Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            SourceBase -= BltInfo->SourceSurface->lDelta;
                            DestBase -= BltInfo->DestSurface->lDelta;
                        }
                    }
                }
                break;
            }
            case BMF_24BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             BltInfo->SourcePoint.x * 3;
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_32BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             BltInfo->SourcePoint.x * 4;
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                        
                        *DestPtr = Source & Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        
                        *((PUSHORT) DestPtr) = (USHORT) Source & (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
        }
    }
}

static void
DIB_16BPP_BitBlt_SRCCOPY(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    ULONG Source = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    switch (BltInfo->SourceSurface->iBitmapFormat)
    {
        case BMF_1BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
            BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_4BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
            BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_8BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x) & ~ 0x3);
            BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_16BPP:
        {
            if (NULL == BltInfo->XlateSourceToDest ||
                0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    CenterCount = 2 * (BltInfo->DestRect.right -
                                       BltInfo->DestRect.left);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        RtlMoveMemory(DestBase, SourceBase, CenterCount);
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    CenterCount = 2 * (BltInfo->DestRect.right -
                                       BltInfo->DestRect.left);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        RtlMoveMemory(DestBase, SourceBase, CenterCount);
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            else
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            break;
        }
        case BMF_24BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 3;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *DestPtr = Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_32BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 4;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                    
                    *DestPtr = Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
    }
}

static void
DIB_16BPP_BitBlt_SRCPAINT(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    ULONG Source = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    switch (BltInfo->SourceSurface->iBitmapFormat)
    {
        case BMF_1BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
            BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr | Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 32;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_4BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
            BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr | Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 8;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_8BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         ((BltInfo->SourcePoint.x) & ~ 0x3);
            BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                RawSource = *SourcePtr++;
                SourcePixels = BaseSourcePixels;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                    SourcePixels--;
                    
                    *DestPtr = *DestPtr | Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    if (0 == SourcePixels)
                    {
                        RawSource = *SourcePtr++;
                        SourcePixels = 4;
                    }
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                    SourcePixels--;
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_16BPP:
        {
            if (NULL == BltInfo->XlateSourceToDest ||
                0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr | Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr | Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            else
            {
                if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 BltInfo->SourcePoint.y *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               BltInfo->DestRect.top *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr | Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase += BltInfo->SourceSurface->lDelta;
                        DestBase += BltInfo->DestSurface->lDelta;
                    }
                }
                else
                {
                    SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                 (BltInfo->SourcePoint.y +
                                  BltInfo->DestRect.bottom -
                                  BltInfo->DestRect.top - 1) *
                                 BltInfo->SourceSurface->lDelta +
                                 ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                    BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                               (BltInfo->DestRect.bottom - 1) *
                               BltInfo->DestSurface->lDelta +
                               BltInfo->DestRect.left * 2;
                    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                   LeftCount) / 2;
                    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                  LeftCount - 2 * CenterCount);
                    for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                    {
                        SourcePtr = (PULONG) SourceBase;
                        RawSource = *SourcePtr++;
                        SourcePixels = BaseSourcePixels;
                        DestPtr = (PULONG) DestBase;
                        
                        if (0 != LeftCount)
                        {
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        for (i = 0; i < CenterCount; i++)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                            SourcePixels--;
                            
                            *DestPtr = *DestPtr | Source;
                            
                            DestPtr++;
                        }
                        
                        if (0 != RightCount)
                        {
                            if (0 == SourcePixels)
                            {
                                RawSource = *SourcePtr++;
                                SourcePixels = 2;
                            }
                            Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                            SourcePixels--;
                            *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                            
                            DestPtr = (PULONG)((char *) DestPtr + 2);
                        }
                        
                        SourceBase -= BltInfo->SourceSurface->lDelta;
                        DestBase -= BltInfo->DestSurface->lDelta;
                    }
                }
            }
            break;
        }
        case BMF_24BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 3;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *DestPtr = *DestPtr | Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                    SourcePtr = (PULONG)((char *) SourcePtr + 3);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
        case BMF_32BPP:
        {
            SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                         BltInfo->SourcePoint.y *
                         BltInfo->SourceSurface->lDelta +
                         BltInfo->SourcePoint.x * 4;
            DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                       BltInfo->DestRect.top *
                       BltInfo->DestSurface->lDelta +
                       BltInfo->DestRect.left * 2;
            LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
            CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                           LeftCount) / 2;
            RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                          LeftCount - 2 * CenterCount);
            for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
            {
                SourcePtr = (PULONG) SourceBase;
                DestPtr = (PULONG) DestBase;
                
                if (0 != LeftCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                for (i = 0; i < CenterCount; i++)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                    
                    *DestPtr = *DestPtr | Source;
                    
                    DestPtr++;
                }
                
                if (0 != RightCount)
                {
                    Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                    
                    *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (USHORT) Source;
                    
                    DestPtr = (PULONG)((char *) DestPtr + 2);
                }
                
                SourceBase += BltInfo->SourceSurface->lDelta;
                DestBase += BltInfo->DestSurface->lDelta;
            }
            break;
        }
    }
}

static void
DIB_16BPP_BitBlt_PATCOPY(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    LONG PatternX =0, PatternY = 0, BasePatternX = 0;
    ULONG Pattern = 0;
    char *DestBase;
    PULONG DestPtr;
    ULONG LeftCount, CenterCount, RightCount;
    
    DestBase = (char *) BltInfo->DestSurface->pvScan0 +
               BltInfo->DestRect.top *
               BltInfo->DestSurface->lDelta +
               BltInfo->DestRect.left * 2;
    LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
    CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                   LeftCount) / 2;
    RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                  LeftCount - 2 * CenterCount);
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    if (NULL != BltInfo->PatternSurface)
    {
        PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                   BltInfo->PatternSurface->sizlBitmap.cy;
        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                   BltInfo->PatternSurface->sizlBitmap.cx;
        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
        {
            DestPtr = (PULONG) DestBase;
            PatternX = BasePatternX;
            
            if (0 != LeftCount)
            {
                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                {
                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                }
                
                *((PUSHORT) DestPtr) = (USHORT) Pattern;
                
                DestPtr = (PULONG)((char *) DestPtr + 2);
            }
            
            for (i = 0; i < CenterCount; i++)
            {
                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                {
                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                }
                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                {
                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                }
                
                *DestPtr = Pattern;
                
                DestPtr++;
            }
            
            if (0 != RightCount)
            {
                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                {
                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                }
                
                *((PUSHORT) DestPtr) = (USHORT) Pattern;
                
                DestPtr = (PULONG)((char *) DestPtr + 2);
            }
            
            if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
            {
                PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
            }
            DestBase += BltInfo->DestSurface->lDelta;
        }
    }
    else
    {
        if (!BltInfo->Brush)
        {
            Pattern = 0;
        }
        else
        {
            Pattern = BltInfo->Brush->iSolidColor |
                      (BltInfo->Brush->iSolidColor << 16);
        }
        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
        {
            DestPtr = (PULONG) DestBase;
            
            if (0 != LeftCount)
            {
                *((PUSHORT) DestPtr) = (USHORT) Pattern;
                
                DestPtr = (PULONG)((char *) DestPtr + 2);
            }
            
            for (i = 0; i < CenterCount; i++)
            {
                *DestPtr = Pattern;
                
                DestPtr++;
            }
            
            if (0 != RightCount)
            {
                *((PUSHORT) DestPtr) = (USHORT) Pattern;
                
                DestPtr = (PULONG)((char *) DestPtr + 2);
            }
            
            DestBase += BltInfo->DestSurface->lDelta;
        }
    }
}

static void
DIB_16BPP_BitBlt_PATPAINT(PBLTINFO BltInfo)
{
    ULONG LineIndex, LineCount;
    ULONG i;
    LONG PatternX =0, PatternY = 0, BasePatternX = 0;
    ULONG Source = 0, Pattern = 0;
    char *DestBase;
    PULONG DestPtr;
    char *SourceBase;
    PULONG SourcePtr;
    ULONG RawSource;
    unsigned SourcePixels, BaseSourcePixels;
    ULONG LeftCount, CenterCount, RightCount;
    
    LineCount = BltInfo->DestRect.bottom - BltInfo->DestRect.top;
    
    if (NULL != BltInfo->PatternSurface)
    {
        switch (BltInfo->SourceSurface->iBitmapFormat)
        {
            case BMF_1BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
                BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_4BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
                BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_8BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x) & ~ 0x3);
                BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_16BPP:
            {
                if (NULL == BltInfo->XlateSourceToDest ||
                    0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
                {
                    if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     BltInfo->SourcePoint.y *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   BltInfo->DestRect.top *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                                   BltInfo->PatternSurface->sizlBitmap.cy;
                        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                   BltInfo->PatternSurface->sizlBitmap.cx;
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            PatternX = BasePatternX;
                            
                            if (0 != LeftCount)
                            {
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                SourcePixels--;
                                
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *DestPtr = *DestPtr | (~Source) | Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                            {
                                PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                            }
                            SourceBase += BltInfo->SourceSurface->lDelta;
                            DestBase += BltInfo->DestSurface->lDelta;
                        }
                    }
                    else
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     (BltInfo->SourcePoint.y +
                                      BltInfo->DestRect.bottom -
                                      BltInfo->DestRect.top - 1) *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   (BltInfo->DestRect.bottom - 1) *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        PatternY = (BltInfo->DestRect.bottom - 1 -
                                    BltInfo->BrushOrigin.y) %
                                   BltInfo->PatternSurface->sizlBitmap.cy;
                        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                   BltInfo->PatternSurface->sizlBitmap.cx;
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            PatternX = BasePatternX;
                            
                            if (0 != LeftCount)
                            {
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                SourcePixels--;
                                
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *DestPtr = *DestPtr | (~Source) | Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            if (0 == PatternY--)
                            {
                                PatternY = BltInfo->PatternSurface->sizlBitmap.cy - 1;
                            }
                            SourceBase -= BltInfo->SourceSurface->lDelta;
                            DestBase -= BltInfo->DestSurface->lDelta;
                        }
                    }
                }
                else
                {
                    if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     BltInfo->SourcePoint.y *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   BltInfo->DestRect.top *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                                   BltInfo->PatternSurface->sizlBitmap.cy;
                        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                   BltInfo->PatternSurface->sizlBitmap.cx;
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            PatternX = BasePatternX;
                            
                            if (0 != LeftCount)
                            {
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                SourcePixels--;
                                
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *DestPtr = *DestPtr | (~Source) | Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                            {
                                PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                            }
                            SourceBase += BltInfo->SourceSurface->lDelta;
                            DestBase += BltInfo->DestSurface->lDelta;
                        }
                    }
                    else
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     (BltInfo->SourcePoint.y +
                                      BltInfo->DestRect.bottom -
                                      BltInfo->DestRect.top - 1) *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   (BltInfo->DestRect.bottom - 1) *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        PatternY = (BltInfo->DestRect.bottom - 1 -
                                    BltInfo->BrushOrigin.y) %
                                   BltInfo->PatternSurface->sizlBitmap.cy;
                        BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                                   BltInfo->PatternSurface->sizlBitmap.cx;
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            PatternX = BasePatternX;
                            
                            if (0 != LeftCount)
                            {
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                SourcePixels--;
                                
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *DestPtr = *DestPtr | (~Source) | Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                                if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                                {
                                    PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                                }
                                
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            if (0 == PatternY--)
                            {
                                PatternY = BltInfo->PatternSurface->sizlBitmap.cy - 1;
                            }
                            SourceBase -= BltInfo->SourceSurface->lDelta;
                            DestBase -= BltInfo->DestSurface->lDelta;
                        }
                    }
                }
                break;
            }
            case BMF_24BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             BltInfo->SourcePoint.x * 3;
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_32BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             BltInfo->SourcePoint.x * 4;
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                PatternY = (BltInfo->DestRect.top - BltInfo->BrushOrigin.y) %
                           BltInfo->PatternSurface->sizlBitmap.cy;
                BasePatternX = (BltInfo->DestRect.left - BltInfo->BrushOrigin.x) %
                           BltInfo->PatternSurface->sizlBitmap.cx;
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    DestPtr = (PULONG) DestBase;
                    PatternX = BasePatternX;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                        
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        Pattern |= DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY) << 16;
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        Pattern = DIB_GetSourceIndex(BltInfo->PatternSurface, PatternX, PatternY);
                        if (BltInfo->PatternSurface->sizlBitmap.cx <= ++PatternX)
                        {
                            PatternX -= BltInfo->PatternSurface->sizlBitmap.cx;
                        }
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    if (BltInfo->PatternSurface->sizlBitmap.cy <= ++PatternY)
                    {
                        PatternY -= BltInfo->PatternSurface->sizlBitmap.cy;
                    }
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
        }
    }
    else
    {
        if (!BltInfo->Brush)
        {
            Pattern = 0;
        }
        else
        {
            Pattern = BltInfo->Brush->iSolidColor |
                      (BltInfo->Brush->iSolidColor << 16);
        }
        if ((~0) == Pattern)
        {
            DIB_16BPP_ColorFill(BltInfo->DestSurface, &BltInfo->DestRect, ~0);
            return;
        }
        switch (BltInfo->SourceSurface->iBitmapFormat)
        {
            case BMF_1BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x / 8) & ~ 0x3);
                BaseSourcePixels = 32 - (BltInfo->SourcePoint.x & 0x1f);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 32;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift1Bpp[SourcePixels]) & 0x1) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_4BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x / 2) & ~ 0x3);
                BaseSourcePixels = 8 - (BltInfo->SourcePoint.x & 0x7);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 8;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift4Bpp[SourcePixels]) & 0xf) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_8BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             ((BltInfo->SourcePoint.x) & ~ 0x3);
                BaseSourcePixels = 4 - (BltInfo->SourcePoint.x & 0x3);
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    RawSource = *SourcePtr++;
                    SourcePixels = BaseSourcePixels;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff)) << 16;
                        SourcePixels--;
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        if (0 == SourcePixels)
                        {
                            RawSource = *SourcePtr++;
                            SourcePixels = 4;
                        }
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift8Bpp[SourcePixels]) & 0xff) & 0xffff);
                        SourcePixels--;
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_16BPP:
            {
                if (NULL == BltInfo->XlateSourceToDest ||
                    0 != (BltInfo->XlateSourceToDest->flXlate & XO_TRIVIAL))
                {
                    if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     BltInfo->SourcePoint.y *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   BltInfo->DestRect.top *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            
                            if (0 != LeftCount)
                            {
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                SourcePixels--;
                                
                                *DestPtr = *DestPtr | (~Source) | Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            SourceBase += BltInfo->SourceSurface->lDelta;
                            DestBase += BltInfo->DestSurface->lDelta;
                        }
                    }
                    else
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     (BltInfo->SourcePoint.y +
                                      BltInfo->DestRect.bottom -
                                      BltInfo->DestRect.top - 1) *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   (BltInfo->DestRect.bottom - 1) *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            
                            if (0 != LeftCount)
                            {
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((RawSource >> Shift16Bpp[SourcePixels] & 0xffff)) << 16;
                                SourcePixels--;
                                
                                *DestPtr = *DestPtr | (~Source) | Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (RawSource >> Shift16Bpp[SourcePixels] & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            SourceBase -= BltInfo->SourceSurface->lDelta;
                            DestBase -= BltInfo->DestSurface->lDelta;
                        }
                    }
                }
                else
                {
                    if (BltInfo->DestRect.top < BltInfo->SourcePoint.y)
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     BltInfo->SourcePoint.y *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   BltInfo->DestRect.top *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            
                            if (0 != LeftCount)
                            {
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                SourcePixels--;
                                
                                *DestPtr = *DestPtr | (~Source) | Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            SourceBase += BltInfo->SourceSurface->lDelta;
                            DestBase += BltInfo->DestSurface->lDelta;
                        }
                    }
                    else
                    {
                        SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                                     (BltInfo->SourcePoint.y +
                                      BltInfo->DestRect.bottom -
                                      BltInfo->DestRect.top - 1) *
                                     BltInfo->SourceSurface->lDelta +
                                     ((BltInfo->SourcePoint.x * 2) & ~ 0x3);
                        BaseSourcePixels = 2 - (BltInfo->SourcePoint.x & 0x1);
                        DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                                   (BltInfo->DestRect.bottom - 1) *
                                   BltInfo->DestSurface->lDelta +
                                   BltInfo->DestRect.left * 2;
                        LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                        CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                       LeftCount) / 2;
                        RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                                      LeftCount - 2 * CenterCount);
                        for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                        {
                            SourcePtr = (PULONG) SourceBase;
                            RawSource = *SourcePtr++;
                            SourcePixels = BaseSourcePixels;
                            DestPtr = (PULONG) DestBase;
                            
                            if (0 != LeftCount)
                            {
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            for (i = 0; i < CenterCount; i++)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff)) << 16;
                                SourcePixels--;
                                
                                *DestPtr = *DestPtr | (~Source) | Pattern;
                                
                                DestPtr++;
                            }
                            
                            if (0 != RightCount)
                            {
                                if (0 == SourcePixels)
                                {
                                    RawSource = *SourcePtr++;
                                    SourcePixels = 2;
                                }
                                Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, (RawSource >> Shift16Bpp[SourcePixels]) & 0xffff) & 0xffff);
                                SourcePixels--;
                                *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                                
                                DestPtr = (PULONG)((char *) DestPtr + 2);
                            }
                            
                            SourceBase -= BltInfo->SourceSurface->lDelta;
                            DestBase -= BltInfo->DestSurface->lDelta;
                        }
                    }
                }
                break;
            }
            case BMF_24BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             BltInfo->SourcePoint.x * 3;
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff)) << 16;
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *(PUSHORT) SourcePtr + (*((PBYTE) SourcePtr + 2) << 16)) & 0xffff);
                        SourcePtr = (PULONG)((char *) SourcePtr + 3);
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
            case BMF_32BPP:
            {
                SourceBase = (char *) BltInfo->SourceSurface->pvScan0 +
                             BltInfo->SourcePoint.y *
                             BltInfo->SourceSurface->lDelta +
                             BltInfo->SourcePoint.x * 4;
                DestBase = (char *) BltInfo->DestSurface->pvScan0 +
                           BltInfo->DestRect.top *
                           BltInfo->DestSurface->lDelta +
                           BltInfo->DestRect.left * 2;
                LeftCount = ((ULONG_PTR) DestBase >> 1) & 0x01;
                CenterCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                               LeftCount) / 2;
                RightCount = (BltInfo->DestRect.right - BltInfo->DestRect.left -
                              LeftCount - 2 * CenterCount);
                for (LineIndex = 0; LineIndex < LineCount; LineIndex++)
                {
                    SourcePtr = (PULONG) SourceBase;
                    DestPtr = (PULONG) DestBase;
                    
                    if (0 != LeftCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    for (i = 0; i < CenterCount; i++)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        Source |= ((XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff)) << 16;
                        
                        *DestPtr = *DestPtr | (~Source) | Pattern;
                        
                        DestPtr++;
                    }
                    
                    if (0 != RightCount)
                    {
                        Source = (XLATEOBJ_iXlate(BltInfo->XlateSourceToDest, *SourcePtr++) & 0xffff);
                        
                        *((PUSHORT) DestPtr) = *((PUSHORT) DestPtr) | (~(USHORT) Source) | (USHORT) Pattern;
                        
                        DestPtr = (PULONG)((char *) DestPtr + 2);
                    }
                    
                    SourceBase += BltInfo->SourceSurface->lDelta;
                    DestBase += BltInfo->DestSurface->lDelta;
                }
                break;
            }
        }
    }
}

static void
DIB_16BPP_BitBlt_WHITENESS(PBLTINFO BltInfo)
{
    DIB_16BPP_ColorFill(BltInfo->DestSurface, &BltInfo->DestRect, ~0);
}

static void (*PrimitivesTable[256])(PBLTINFO) =
{
    DIB_16BPP_BitBlt_BLACKNESS,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_NOTSRCERASE,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_NOTSRCCOPY,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_SRCERASE,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_DSTINVERT,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_PATINVERT,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_SRCINVERT,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_SRCAND,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_NOOP,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_MERGEPAINT,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_MERGECOPY,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_SRCCOPY,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_SRCPAINT,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_PATCOPY,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_PATPAINT,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_Generic,
    DIB_16BPP_BitBlt_WHITENESS
};

BOOLEAN
DIB_16BPP_BitBlt(PBLTINFO BltInfo)
{
    PrimitivesTable[BltInfo->Rop4 & 0xff](BltInfo);
    
    return TRUE;
}
