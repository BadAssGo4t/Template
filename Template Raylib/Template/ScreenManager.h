#pragma once
#include <iostream>
#include "raylib.h"

#include "Menu.h"
#include "Game.h"
#include "Options.h"
#include "Instructions.h"
#include "Credits.h"

typedef struct   Screen
{
    int width;
    int height;
} Screen;
static Screen curScreen;

namespace ScreenManagerNam
{
	static void Change();

	enum GameScreen
	{
		Menu = 0,
		Game = 1,
		Controls = 2,
		Credits = 3,
		End = 4
	};
	extern GameScreen ScreensSwap;

	int ScreenManager();
}