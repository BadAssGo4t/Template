#include "Credits.h"

namespace CreditsNmsp
{
    Texture2D backgroundCred;
    Texture2D logoTex;
    static Vector2 mousePoint; 
    static Image creditsImg;
    static Image logo;
    static Return rtrn;
    int amountOfCredits = 0;


    void InitCredits() // Init
    {
        amountOfCredits = 3;
        curScreen.width = 600;
        curScreen.height = 800;

        creditsImg = LoadImage("../Resources/Credits/CreditsGray.png");
        ImageResize(&creditsImg, curScreen.width, curScreen.height);

        logo = LoadImage("../Resources/Useful/SymBlack.png");
        ImageResize(&logo, 50, 50);

        backgroundCred = LoadTextureFromImage(creditsImg);

        logoTex = LoadTextureFromImage(logo);

        rtrn.button = LoadTexture("../Resources/Button/Return.png");
        rtrn.frameHeight = (float)rtrn.button.height / NUM_FRAMES;
        rtrn.sourceRec = { 0, 0, (float)rtrn.button.width, rtrn.frameHeight };

        // Define button bounds on screen
        rtrn.btnBounds = { curScreen.width - rtrn.button.width * 3 / 2.0f, curScreen.height - rtrn.button.height * 3 / NUM_FRAMES / 2.0f, (float)rtrn.button.width, rtrn.frameHeight };
        rtrn.btnState = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        rtrn.btnAction = false;

    }

    void UpdateCredits()
    {
        DrawCredits();

        mousePoint = GetMousePosition();

        if (CheckCollisionPointRec(mousePoint, rtrn.btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) rtrn.btnState = 2;
            else rtrn.btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) rtrn.btnAction = true;
        }
        else rtrn.btnState = 0;

        if (rtrn.btnAction)
        {
            std::cout << "boton Credits precionado" << "\n";
            rtrn.btnAction = false;
            ScreenManagerNam::Screens = ScreenManagerNam::Menu;
        }
    }

    void DrawCredits() {
        BeginDrawing();

        ClearBackground(GetColor(0x052c46ff));

        DrawTexture(backgroundCred, 0, 0, WHITE);
        DrawTexture(logoTex, 0 + logoTex.width, curScreen.height - logoTex.height*2, WHITE);

        DrawTextureRec(rtrn.button, rtrn.sourceRec, Vector2{ rtrn.btnBounds.x, rtrn.btnBounds.y }, WHITE);

        EndDrawing();
    }

    void UnloadCredits()
    {
        UnloadTexture(backgroundCred);
        UnloadImage(creditsImg);
        std::cout << "Credits Unloaded." << '\n';
    }
}
