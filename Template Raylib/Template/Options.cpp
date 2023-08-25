#include "Options.h"

namespace Options
{

    void InitOptions() // Init
    {

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
 
    }
}
