#include "Credits.h"

namespace CreditsNmsp
{
    Texture2D backgroundCred;
    static Vector2 mousePoint; 
    static Image creditsImg;
   

    void InitCredits() // Init
    {
        curScreen.width = 600;
        curScreen.height = 800;

        creditsImg = LoadImage("../Resources/Credits/CreditsGray.png");
        ImageResize(&creditsImg, curScreen.width, curScreen.height);

        backgroundCred = LoadTextureFromImage(creditsImg);

    }

    void UpdateCredits()
    {
        mousePoint = GetMousePosition();

        DrawCredits();    
    }

    void DrawCredits() {
        BeginDrawing();

        ClearBackground(GetColor(0x052c46ff));

        DrawTexture(backgroundCred, 0, 0, WHITE);

        EndDrawing();
    }

    void UnloadCredits()
    {
        UnloadTexture(backgroundCred);
        UnloadImage(creditsImg);
        std::cout << "Credits Unloaded.";
    }
}
