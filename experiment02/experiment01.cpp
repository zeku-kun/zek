#include <iostream>
#include <raylib.h>
#include <cmath>
using namespace std;

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 600;
const char GAME_TITLE[] = "RANDOM THINGS";
const float gravity = 9.8;

class Ball{
    protected:
    static int obj_count;

    public:
    int pos_x;
    int pos_y;
    int radius;
    Color color;

    Ball(){
        obj_count++;
        cout<< "Ball " << obj_count << " Created\n";
    }
    
    void Boundary(){
        if(pos_y >= SCREEN_HEIGHT - radius){
            pos_y = SCREEN_HEIGHT - radius;
        }
    }

    void Draw(){
        DrawCircle(pos_x, pos_y, radius, color);
    }

    void Update(){
        pos_y += gravity, 2;
        Boundary();
    }
};

int Ball::obj_count = 0 ;
Ball ball;

int main(){
    

    // Ball
    ball.pos_x = SCREEN_WIDTH / 2;
    ball.pos_y = SCREEN_HEIGHT / 2;
    ball.radius = 20;
    ball.color = BLACK;

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        // Update
        ball.Update();

        // Draw
        ClearBackground(WHITE);
        ball.Draw();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}