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
		Menu,
		Game,
		Instructions,
		Credits,
		End
	};
	GameScreen ScreensSwap;

	int ScreenManager();
}