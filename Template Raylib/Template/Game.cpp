#include "Game.h"

namespace Game
{

    void InitGame() // Init
    {

    }

    void UpdateGame()
    {
        DrawGame();

    }

    void DrawGame() {

        BeginDrawing();

        ClearBackground(GetColor(0x052c46ff));

        EndDrawing();
    }

    void UnloadGame()
    {
        std::cout << "Game Unloaded." << '\n';
    }
}
