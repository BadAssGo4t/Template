#include "Options.h"

namespace Options
{

    void InitOptions() // Init
    {
        curScreen.width = 600;
        curScreen.height = 800;
        curScreen.name = "Game - Options";

        InitWindow(curScreen.width, curScreen.height, curScreen.name);
    }

    void UpdateOptions()
    {
        DrawOptions();

    }

    void DrawOptions() {

        BeginDrawing();

        ClearBackground(GetColor(0x052c46ff));

        EndDrawing();
    }

    void UnloadOptions()
    {
        std::cout << "Options Unloaded." << '\n';
    }
}
