#include "Credits.h"

namespace CreditsNmsp
{

    void InitCredits() // Init
    {

    }

    void UpdateCredits()
    {
        DrawCredits();

    }

    void DrawCredits() {

        BeginDrawing();

        ClearBackground(GetColor(0x052c46ff));

        EndDrawing();
    }

    void UnloadCredits()
    {

    }
}
