#include <iostream>
#include "raylib.h"

using namespace std;

int player_score = 0;
int cpu_score = 0;

class Ball{
    public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw(){
        DrawCircle(x, y, radius, WHITE);
    }

    void Update(){
        x += speed_x;
        y += speed_y;

        if(y + radius >= GetScreenHeight() || y - radius <= 0){
            speed_y *= -1;
        }
        if(x + radius >= GetScreenWidth()){
            cpu_score ++;
            ResetBall();
        } 
        
        if(x - radius <= 0){
            player_score ++;
            ResetBall();
        }
    }

    void ResetBall(){
        x = GetScreenWidth()/2;
        y = GetScreenHeight()/2;

        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0,1)];
        speed_y *= speed_choices[GetRandomValue(0,1)];
    }
};

class Paddle{
    protected:
    void LimitMovement(){
        if(pos_y <= 0){
            pos_y = 0;
        }
        if(pos_y + height >= GetScreenHeight()){
            pos_y = GetScreenHeight() - height; 
        }
    }
    public:
    float pos_x, pos_y;
    float width, height;
    int speed;

    void Draw(){
        DrawRectangle(pos_x, pos_y, width, height, WHITE);
    }

    void Update(){
        if(IsKeyDown(KEY_UP)){
            pos_y = pos_y - speed;
        }
        if(IsKeyDown(KEY_DOWN)){
            pos_y = pos_y + speed; 
        }

        LimitMovement();
    }
};

class CpuPaddle: public Paddle{
    public:

    void Update(int ball_y){
        if(pos_y + height/2 > ball_y){
            pos_y = pos_y - speed;
        }
        if(pos_y + height/2 <= ball_y){
            pos_y = pos_y + speed;
        }

        LimitMovement();
    }
};

Ball ball;
Paddle player;
CpuPaddle cpu;

int main(){
    cout << "Starting game" << endl;
    //Window
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 640;
    const char GAME_NAME[] = "PING PONG";


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 15;
    player.height = 90;
    player.pos_x = SCREEN_WIDTH - player.width - 5;
    player.pos_y = SCREEN_HEIGHT / 2 - player.height / 2 ;
    player.speed = 8;

    cpu.width = 15;
    cpu.height = 90;
    cpu.pos_x = 5;
    cpu.pos_y = SCREEN_HEIGHT / 2 - cpu.height / 2;
    cpu.speed = 8;

    while(!WindowShouldClose()){
        BeginDrawing();

        //Update
        ball.Update();
        player.Update();
        cpu.Update(ball.y);

        //Checking Collisions
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.pos_x, player.pos_y, player.width, player.height})){
            ball.speed_x *= -1;
        }
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.pos_x, cpu.pos_y, cpu.width, cpu.height})){
            ball.speed_x *= -1;
        }

        //Drawing
        ClearBackground(BLACK);
        DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
        ball.Draw();
        cpu.Draw();
        player.Draw();
        DrawText(TextFormat("%i",cpu_score), SCREEN_WIDTH / 4 - 5, 5, 80, WHITE);
        DrawText(TextFormat("%i",player_score), 3 * SCREEN_WIDTH / 4 - 5, 5, 80, WHITE);

        EndDrawing();
    }


    CloseWindow();
    return 0;
}