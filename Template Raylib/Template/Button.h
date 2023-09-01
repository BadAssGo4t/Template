#pragma once
#include "ScreenManager.h"

namespace Button
{
    typedef struct   ButtonStruct
    {
        Texture2D Texture;
        float FrameHeight;
        Rectangle SourceRec;
        Rectangle Bounds;
        int State;
        bool Action;
    }newButton;
}
