#include <iostream>
#include <raylib.h>
#include <cmath>
using namespace std;

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 600;
const char GAME_TITLE[] = "RANDOM THINGS";
int gravMult = 1;
const float gravity = 9.81;
double deltaTime;


class Ball{
    protected:
    static int objCount;

    public:
    Vector2 pos = {0 , 0};
    int radius;
    Color color;
    float velocityY = 0;


    Ball(){
        objCount++;
        cout<< "Ball " << objCount << " Created\n";
    }
    
    void Movement(){
        if(IsKeyDown(KEY_D)){
            pos.x += 5;
        }
        if(IsKeyDown(KEY_A)){
            pos.x += -5;
        }
        if(IsKeyDown(KEY_SPACE) && pos.y >= SCREEN_HEIGHT - radius){
            velocityY = -9.8;
            pos.y += velocityY;
        }
    }

    void Boundary(){
        if(pos.y >= SCREEN_HEIGHT - radius){
            pos.y = SCREEN_HEIGHT - radius;

        }
    }

    void Draw(){
        DrawCircleV(pos, radius, color);
    }

    void Gravity(){
        if(pos.y <= SCREEN_HEIGHT){
            velocityY += (gravity * gravMult) * (deltaTime);
            pos.y += velocityY;
        }
        /*if(pos.y >= SCREEN_HEIGHT - radius){
            velocityY = 0;
        }*/
    }

    void Update(){
        Gravity();
        Movement();
        Boundary();
    }
};

int Ball::objCount = 0 ;
Ball ball;

int main(){
    

    // Ball
    ball.pos = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    ball.radius = 20;
    ball.color = BLACK;

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        deltaTime = GetFrameTime();
        cout << ball.velocityY << ":"<< ball.pos.y << "\n";
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