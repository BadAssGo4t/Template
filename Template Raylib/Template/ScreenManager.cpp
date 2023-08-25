#include "ScreenManager.h"

namespace ScreenManagerNam
{
	

	GameScreen Screens;

	int ScreenManager()
	{
		SetTargetFPS(60);
		curScreen.width = 600;
		curScreen.height = 800;

		InitWindow(curScreen.width, curScreen.height, "GameName");

		Menu::InitMenu();

		while (!WindowShouldClose())
		{
			Change();
		}

		Menu::UnloadMenu();
		CloseWindow();

		return 0;
	} // SCreen MANAGER



  static void Change() 
  {
	switch (ScreensSwap)
	{

	  case Menu: {
			Menu::UpdateMenu();
	  } break;
	  case Game: 
	  {
		  Game::UpdateGame();
	  } break;
	  case Credits:
	  {
		  CreditsNmsp::UpdateCredits();
	  } break;
	  case Instructions:
	  {
		  Instructions::UpdateInstructions();
	  }break;

	}

  } // CHANGE END 
}