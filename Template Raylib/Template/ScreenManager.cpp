#include "ScreenManager.h"

namespace ScreenManagerNam
{
	static void Change();

	GameScreen Screens;

	int ScreenManager()
	{
		SetTargetFPS(60);
		curScreen.width = 600;
		curScreen.height = 800;

		InitWindow(curScreen.width, curScreen.height, "GameName");

		Menu::InitMenu();
		CreditsNmsp::InitCredits();



		//Gameplay::UpdateGame();


		while (!WindowShouldClose())
		{
			Change();
		}

		Menu::UnloadMenu();
		CreditsNmsp::UnloadCredits;
		CloseWindow();

		return 0;
	} // SCreen MANAGER



  static void Change() 
  {
	switch (Screens)
	{

	  case Menu: {
			Menu::UpdateMenu();
	  } break;

	  
	  case Instructions: {
			Instructions::UpdateInstructions();
	  } break;

	  case Credits: {
		  CreditsNmsp::UpdateCredits();
	  } break;

	  /*
	  * case Game: {
		  Gameplay::UpdateGame();
	  } break;
	  */
	}

  } // CHANGE END 
}