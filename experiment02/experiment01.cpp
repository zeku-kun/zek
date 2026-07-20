#include <iostream>
#include <raylib.h>
#include <cmath>
using namespace std;
class Game{
    public:
    double deltaTime;
    static inline const int SCREEN_WIDTH = 700;
    static inline const int SCREEN_HEIGHT = 600;
    const char GAME_TITLE[14] = "RANDOM THINGS";

    protected:
    static inline int gravMult = 2;
    static inline const float gravity = 9.81;
    
    class Mechanics{
        protected:
        Vector2 velocity = {0, 0};

        void Grav(float &pos_y, Game* g){
            if(pos_y <= SCREEN_HEIGHT){
                velocity.y += (gravity * gravMult) * g -> deltaTime;
                pos_y += velocity.y;
            }

            if(pos_y >= SCREEN_HEIGHT){
                velocity.y = 0;
            }
        }
    };
};



class Ball: public Game, protected Game::Mechanics{
    protected:
    static int objCount;

    public:
    Vector2 pos = {0 , 0};
    int radius;
    Color color;

    struct Walking{
        
    };

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
            velocity.y = -8;
            pos.y += velocity.y;
            
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
        Grav(pos.y, this);

        if(pos.y >= SCREEN_HEIGHT - radius){
            velocity.y = 0;
        }
    }

    void Update(){
        Gravity();
        Movement();
        Boundary();
    }
};

class Box{
    public:
    Rectangle rec;
    Vector2 origin;
    float rotation;
    Color color;

    void Draw(){
        DrawRectanglePro(rec, origin, rotation, color);
    }
};

int Ball::objCount = 0 ;
Ball ball;
Game game;

int main(){
    

    // Ball
    ball.pos = {static_cast<float>(game.SCREEN_WIDTH) / 2, static_cast<float>(game.SCREEN_HEIGHT) / 2};
    ball.radius = 20;
    ball.color = BLACK;

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(game.SCREEN_WIDTH, game.SCREEN_HEIGHT, game.GAME_TITLE);
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        ball.deltaTime = GetFrameTime();
        
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