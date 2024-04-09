#include "raylib.h"
#include "Ball.h"
#include "GameManager.h"
#include <iostream>

const int WIDTH = 1080;
const int HEIGHT = 720;

GameManager gm = GameManager(WIDTH, HEIGHT);

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
    gm.CreateGame();
}

void Update()
{
    gm.Update();
}

void Draw()
{
    BeginDrawing();
    ClearBackground(WHITE);
    gm.Draw();
    EndDrawing();
}

void Unload()
{
    CloseWindow();
}
