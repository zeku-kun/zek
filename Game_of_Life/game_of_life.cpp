#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main(){
    Color GREY = {29, 29, 29, 255};
    const int WINDOW_HEIGHT = 600;
    const int WINDOW_WIDTH = 1200;
    const int CELL_SIZE = 7;
    int FPS = 12;

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "GAME OF LIFE");
    SetTargetFPS(FPS);
    Simulation simulation{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
    
    while(!WindowShouldClose()){
        // event hadling

        // update
        simulation.update();
        // drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}