/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Title Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"
#include <stdio.h>

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
    // TODO: Initialize TITLE screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
    // TODO: Update TITLE screen variables here!

    // Press enter or tap to change to GAMEPLAY screen
    /*if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))*/
    /*{*/
    /*    //finishScreen = 1;   // OPTIONS*/
    /*    finishScreen = 2;   // GAMEPLAY*/
    /*    PlaySound(fxCoin);*/
    /*}*/
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        
        Rectangle colorButton = {360, 220, 100, 35};
        if (CheckCollisionPointRec(mousePos, colorButton))
        {
          finishScreen =2;
          PlaySound(fxCoin);
        }

    }
  
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{  
    // order of drawing is very important
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GOLD);
    // TODO: Draw TITLE screen here!
    const int padding = 10;
    const int buttonWidth = 100;
    const int buttonHeight = 30;
    
    Vector2 colorButtonPos = {padding + 350 ,padding + 210};
    DrawRectangleRec((Rectangle){colorButtonPos.x, colorButtonPos.y, buttonWidth, buttonHeight}, GRAY);
    DrawText("START", colorButtonPos.x + buttonWidth / 2 - MeasureText("Snow Color", 10) / 2, colorButtonPos.y + buttonHeight / 2 - 5, 15, WHITE);




    //Vector2 fps = {10, 10};
    DrawFPS(10, 10);
    Vector2 pos = { 150, 190 };
    DrawTextEx(font, "CYPHER THE LOST CODECS", pos, font.baseSize*3.0f, 4, WHITE);
    DrawText(TextFormat("Mouse: %.1f, %.1f", GetMousePosition().x, GetMousePosition().y), 400, 10, 20, RED);
}

// Title Screen Unload logic
void UnloadTitleScreen(void)
{
    // TODO: Unload TITLE screen variables here!
}

// Title Screen should finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}
