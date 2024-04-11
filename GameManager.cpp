#include "GameManager.h"

Ball ball;
Paddle paddle = Paddle();

Brick map[4][10];

GameManager::GameManager(int Width, int Height)
{
	WIDTH = Width;
	HEIGHT = Height;
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j].Update(ball);
		}
	}
	paddle.Update(WIDTH);
	ball.Update(WIDTH, HEIGHT, paddle);
}

void GameManager::Draw()
{
	paddle.DrawPaddle();
	ball.DrawBall();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j].Draw();
		}
	}
}

void GameManager::CreateGame()
{
	paddle = Paddle(Rectangle{ (float)(WIDTH / 2.0), (float)(HEIGHT - HEIGHT / 10.0), 120, 10 });
	Vector2 coordinates = { 40,0 };
	for (int i = 0; i < 4; i++) {
		coordinates.x = 40;
		coordinates.y += 50;
		for (int j = 0; j < 10; j++) {
			Brick brick = Brick(Rectangle{ coordinates.x, coordinates.y, 80, 30 }, Vector2{ (float)i, (float)j }, 2, BLUE);
			map[i][j] = brick;
			coordinates.x += 100;
		}
	}
}
