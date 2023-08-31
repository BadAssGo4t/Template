#pragma once
#include <iostream>
#include "raylib.h"

#include "Menu.h"
#include "Game.h"
#include "Options.h"
#include "Instructions.h"
#include "Credits.h"

#include "Unloader.h"

typedef struct   Screen
{
    int width;
    int height;
} Screen;
static Screen curScreen;

namespace ScreenManagerNam
{
	enum GameScreen
	{
		Menu = 0,
		Game,
		Instructions,
		Credits,
		End
	};
	extern GameScreen Screens;

	int ScreenManager();
}