#include <iostream>
#include <raylib.h>
#include <cmath>
#include <vector>
#include <cstdlib>

// ONLY GOD KNOWS
class Box{
    protected:
    static int box_count;
    const float vec_mag = 1.4142136;
    float normal_vec_mag;
    Vector2 player_vec = {0, 0};

    public:
    float pos_x, pos_y;
    Vector2 prev_pos;
    Vector2 current_pos;
    float width, height;
    float speed;
    Color color;
    Box(){
        ++box_count;
        std::cout<<"Box "<< box_count << " Created" << std::endl;
    }

    
    void Boundary(){
        if(pos_x >= 900 - width){
            pos_x = 900 - width;
        }
        if(pos_x <= 0){
            pos_x = 0;
        }
        if(pos_y >= 600 - height){
            pos_y = 600 - height;
        }
        if(pos_y <= 0){
            pos_y = 0;
        }
    }
    
    void Movement(){
        if(IsKeyDown(KEY_UP)){
            player_vec.y = -1;
        } if (IsKeyReleased(KEY_UP)) {
            player_vec.y = 0;
        }

        if(IsKeyDown(KEY_DOWN)){
            player_vec.y = 1;
        } if (IsKeyReleased(KEY_DOWN)) {
            player_vec.y = 0;
        }
        
        if(IsKeyDown(KEY_LEFT)){
            player_vec.x = -1;
        } if (IsKeyReleased(KEY_LEFT)) {
            player_vec.x = 0;
        }
        
        if(IsKeyDown(KEY_RIGHT)){
            player_vec.x = 1;
        } if (IsKeyReleased(KEY_RIGHT)) {
            player_vec.x = 0;
        }

        if (player_vec.x != 0 && player_vec.y != 0) {
            player_vec.x = player_vec.x / vec_mag;
            player_vec.y = player_vec.y / vec_mag;
        }

        pos_x += player_vec.x * speed;
        pos_y += player_vec.y * speed;

        normal_vec_mag = std::sqrt(std::pow(player_vec.x, 2.0) + std::pow(player_vec.y, 2.0)); 
        //std::cout << normal_vec_mag << ": " << player_vec.x << "," << player_vec.y << "\n";
    }

    void Infinity(){
        DrawCircle(pos_x + (width / 2), pos_y + (height / 2), (width + height) * .75, GREEN);
    }

    void Draw(){
        DrawRectangle(pos_x, pos_y, width, height, color);
    }

    void Update(){
        Infinity();
        Boundary();
        Movement();
    }
};

class Raindrops{
    protected:
    static int obs_count;

    public:
    Rectangle rec;
    Vector2 orig;
    float rotation;
    Color color;
    float speed;
    
    // Parameterized Construct
    Raindrops(float x, float y, float w, float h, float rot, Color c, float spd)
            : rec{x, y, w, h}, rotation(rot), color (c), speed(spd) // initialzed variables
    {
        orig = {rec.width / 2, rec.height / 2};
        ++obs_count;
        std:: cout << "Obstacle " << obs_count << " created" << "\n";
        
    }

    void Draw(){
        DrawRectanglePro(rec, orig, rotation, color);
    }

    void Update(){
        rec.y += speed;

        if(rec.y > 600){
            rec.y = 0;
        }
    }
};

int Box::box_count = 0;
int Raindrops:: obs_count = 0;

Box box;
std::vector<Raindrops> raindropsList;
int main(){
    std::cout << "Starting Game...";

    const int SCREEN_WIDTH = 900;
    const int SCREEN_HEIGHT = 600;
    const char GAME_NAME[] = "Idk Game";
    
    const int NUM_DROPS = 100;
    for(int i = 0; i < NUM_DROPS; i++){
        float x = rand() % SCREEN_WIDTH;
        float y = rand() % SCREEN_HEIGHT;
        float speed = 3 + (rand() % 5);
        raindropsList.push_back(Raindrops(x, y, 4, 2, 45, BLACK, speed));
    }

    // Box
    box.width = 50;
    box.height = 50;
    box.pos_x = SCREEN_WIDTH/2-(box.width/2);
    box.pos_y = SCREEN_HEIGHT/2-(box.height/2);
    box.speed = 5;
    box.color = BLACK;

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        //Update
        for(auto &drop : raindropsList){
            drop.Update();
        }
        //Draw
        ClearBackground(WHITE);
        for(auto &drop : raindropsList){
            drop.Draw();
        }
        
        //DrawLine(SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT, BLACK); // center of the screen
        EndDrawing();
    }
    CloseWindow();
    return 0;
}