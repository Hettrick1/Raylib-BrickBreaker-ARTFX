#include "raylib.h"
#include "Ball.h"
#include <iostream>

const int WIDTH = 1080;
const int HEIGHT = 720;

Ball ball;
Paddle paddle = Paddle(Rectangle{WIDTH/2, HEIGHT - HEIGHT/10, 120, 10});

void Load();
void Start();
void Update();
void Draw();
void Unload();


int main() {

    Load();
    Start();
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    Unload();
    return 0;
}
void Load()
{
    InitWindow(WIDTH, HEIGHT, "Make More!");
    SetTargetFPS(60);
}

void Start()
{
}

void Update()
{
    ball.Update(WIDTH, HEIGHT, paddle);
    paddle.Update(WIDTH);
}

void Draw()
{
    BeginDrawing();
    ClearBackground(WHITE);
    paddle.DrawPaddle();
    ball.DrawBall();
    EndDrawing();
}

void Unload()
{
    CloseWindow();
}
