#include "Unloader.h"

namespace Unloader
{
	void UnloadMenu()
	{
		Menu::UnloadMenu();
		Options::UnloadOptions();
		CreditsNmsp::UnloadCredits();
		Instructions::UnloadInstructions();
	}

	void UnloadGame()
	{
		Game::UnloadGame();
	}

	void UnloadAll()
	{
		std::cout << "UNLOADER EXECUTED" << '\n';
		Game::UnloadGame();
		Menu::UnloadMenu();
		Options::UnloadOptions();
		CreditsNmsp::UnloadCredits();
		Instructions::UnloadInstructions();
	}
}
