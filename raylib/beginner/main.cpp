#include <cstdlib>
#include <ctime>
#include "raylib.h"
#include <iostream>
#include "main.h"
#include <vector>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------


int main(void)
{
    //RANDOM
    srand(time(0));
    int number, isPositive;
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Flappy Bird");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    //PILLARS INITIALISATION
    //--------------------------------------------------------------------------------------
    std::vector<Column> pillars;
    for(int i = 1; i <= 6; i++){
        Column pillar(i);
        pillars.push_back(pillar);
    }

    //PLAYER
    Sprite player(screenWidth/2,120,20);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            //bg
            ClearBackground(BLACK);

            //pillars
            for(int i = 0; i <= 5; i++ ){
                pillars.at(i).move();
                pillars.at(i).draw();
                pillars.at(i).reset();
            }
            
            player.gravity();
            player.goUp();       
            player.updateSprite();
            //fps
            DrawText(TextFormat("FPS: %i", GetFPS()), 350, 470, 20, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}