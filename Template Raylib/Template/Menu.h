#pragma once
#include "ScreenManager.h"

#define NUM_FRAMES  3 

typedef struct   Button
{
    Texture2D button;
    float frameHeight;
    Rectangle sourceRec;
    Rectangle btnBounds;
    int btnState;
    bool btnAction;
} Play, Controls, Credits, Return;


namespace Menu
{
    void InitMenu();
    void UpdateMenu();
    void DrawMenu();
    void UnloadMenu();

}