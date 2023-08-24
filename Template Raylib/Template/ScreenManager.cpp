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
		//Controls::initControls();
		//Credits::InitCredits();
		


		//Gameplay::UpdateGame();


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

	  /*
	  case Controls: {
			Controls::UpdateControls();
	  } break;

	  case Credits: {
		  Credits::UpdateCredits();
	  } break;

	  case Game: {
		  Gameplay::UpdateGame();
	  } break;
	  */
	}

  } // CHANGE END 
}