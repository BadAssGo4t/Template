#include "Credits.h"


namespace CreditsNmsp
{

    static Button::newButton returnBttn;
    static Button::NewCreditButton dev;
    static Button::NewCreditButton lib;

    static Image logo;
    static Image creditsImg;
    static Image background;

    static Texture2D backgroundCred;
    static Texture2D backgroundTex;
    static Texture2D logoTex;

    static Vector2 mousePoint;


    void InitCredits() // Init
    {
        curScreen.width = 600;
        curScreen.height = 800;
        curScreen.name = "Game - Credits";
        SetWindowSize(curScreen.width, curScreen.height);
        SetWindowTitle(curScreen.name);

        dev.Bounds.width = curScreen.width/1.2;
        dev.Bounds.height = curScreen.height / 14; // the screen is divided by the inteded amount of credit holders + 2 this leaves a margin 
        dev.Bounds.x = (curScreen.width / 2) - (dev.Bounds.width / 2);
        dev.Bounds.y = (curScreen.height / 15) * 4;
        dev.btnColor = { 80, 80, 80, 255 }; // DARKGRAY
        dev.name = "Game Made By: Estanislao";
        dev.btnUrl = "https://github.com/BadAssGo4t/Template";

        lib.Bounds.width = curScreen.width / 1.2;
        lib.Bounds.height = curScreen.height / 14; // the screen is divided by the inteded amount of credit holders + 2 this leaves a margin 
        lib.Bounds.x = (curScreen.width / 2) - (dev.Bounds.width / 2);
        lib.Bounds.y = (curScreen.height / 15) * 8;
        lib.btnColor = { 80, 80, 80, 255 }; // DARKGRAY
        lib.name = "Made Using: Raylib";
        lib.btnUrl = "https://www.raylib.com/index.html";


        background = LoadImage("../Resources/Images/bk.png");
        ImageResize(&background, curScreen.width, curScreen.height);
        backgroundTex = LoadTextureFromImage(background); // background
        UnloadImage(background);

        creditsImg = LoadImage("../Resources/Credits/CreditsWhite.png");
        ImageResize(&creditsImg, curScreen.width, curScreen.height);

        logo = LoadImage("../Resources/Images/SymBlack.png");
        ImageResize(&logo, 50, 50);

        backgroundCred = LoadTextureFromImage(creditsImg);

        logoTex = LoadTextureFromImage(logo);

        returnBttn.Texture = LoadTexture("../Resources/Button/Return.png");
        returnBttn.FrameHeight = (float)returnBttn.Texture.height / NUM_FRAMES;
        returnBttn.SourceRec = { 0, 0, (float)returnBttn.Texture.width, returnBttn.FrameHeight };

        // Define button bounds on screen
        returnBttn.Bounds = { curScreen.width - returnBttn.Texture.width * 3 / 2.0f, curScreen.height - returnBttn.Texture.height * 3 / NUM_FRAMES / 2.0f, (float)returnBttn.Texture.width, returnBttn.FrameHeight };
        returnBttn.State = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        returnBttn.Action = false;

    }

    void UpdateCredits()
    {
        DrawCredits();

        mousePoint = GetMousePosition();


        if (CheckCollisionPointRec(mousePoint, dev.Bounds)) //Checks state of the DEV BTTN
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) dev.btnColor = { 255, 203, 0, 255 };
            else dev.btnColor = { 200, 200, 200, 255 };

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) dev.Action = true;
        }
        else dev.btnColor = { 80, 80, 80, 255 };

        if (CheckCollisionPointRec(mousePoint, lib.Bounds)) //Checks state of the LIB BTTN
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) lib.btnColor = { 255, 203, 0, 255 };
            else lib.btnColor = { 200, 200, 200, 255 };

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) lib.Action = true;
        }
        else lib.btnColor = { 80, 80, 80, 255 };

        if (CheckCollisionPointRec(mousePoint, returnBttn.Bounds)) //Checks state of the RETURN BTTN
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) returnBttn.State = 2;
            else returnBttn.State = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) returnBttn.Action = true;
        }
        else returnBttn.State = 0;

        if (returnBttn.Action) // Button RETURN PRESSED
        {
            std::cout << "boton Credits pressed" << "\n";
            returnBttn.Action = false;
            ScreenManagerNam::Screens = ScreenManagerNam::Menu;
        }
        if (dev.Action) // Button DEV PRESSED
        {
            std::cout << "boton dev pressed" << "\n";
            dev.Action = false;
            OpenURL(dev.btnUrl);
        }
        if (lib.Action) // Button LIB PRESSED
        {
            std::cout << "boton lib pressed" << "\n";
            lib.Action = false;
            OpenURL(lib.btnUrl);
        }
    }

    void DrawCredits() 
    {
        BeginDrawing();

        ClearBackground(GetColor(0x052c46ff));

        DrawTexture(backgroundTex, 0.0f, 2.0f, WHITE);

        DrawTexture(backgroundCred, 0, 0, WHITE);
        DrawTexture(logoTex, 0 + logoTex.width, curScreen.height - logoTex.height*2, WHITE);

        DrawTextureRec(returnBttn.Texture, returnBttn.SourceRec, Vector2{ returnBttn.Bounds.x, returnBttn.Bounds.y }, WHITE);

        DrawRectangleRec(dev.Bounds, dev.btnColor);
        DrawRectangleLinesEx(dev.Bounds, lib.frame, BLACK);
        DrawText(dev.name, curScreen.width / 2 - MeasureText(dev.name, 30) / 2, dev.Bounds.y + 15/*the + 15 represents half of the text size*/, 30, BLACK);

        DrawRectangleRec(lib.Bounds, lib.btnColor);
        DrawRectangleLinesEx(lib.Bounds, lib.frame, BLACK);
        DrawText(lib.name, curScreen.width / 2 - MeasureText(lib.name, 30) / 2, lib.Bounds.y + 15, 30, BLACK); 

        EndDrawing();
    }

    void UnloadCredits()
    {
        UnloadTexture(returnBttn.Texture);
        UnloadTexture(backgroundCred);
        UnloadTexture(backgroundTex);
        UnloadTexture(logoTex);
        UnloadImage(creditsImg);
        std::cout << "Credits Unloaded." << '\n';
    }
}
