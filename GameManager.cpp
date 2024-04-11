#include "GameManager.h"

Ball ball;
Paddle paddle = Paddle();

int score = 0;


int colones = 5;

int index = 0;

Brick level1[5][10];
Brick level2[8][10];
Brick level3[11][10];
Brick level4[14][10];

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
	for (int i = 0; i < colones; i++) {
		for (int j = 0; j < 10; j++) {
			switch (index)
			{
			case 0:
				level1[i][j].Update(ball);
				break;
			case 1:
				level2[i][j].Update(ball);
				break;
			case 2:
				level3[i][j].Update(ball);
				break;
			case 3:
				level4[i][j].Update(ball);
				break;
			}
		}
	}
	paddle.Update(WIDTH);
	ball.Update(WIDTH, HEIGHT, paddle);
	if (IsEverythingDestroyed()) {
		if (colones < 12) {
			colones += 3;
			index += 1;
			InitializeGame();
		}
		else {
			colones = 5;
			index = 0;
			InitializeGame();
		}
	}
}

void GameManager::Draw()
{
	paddle.DrawPaddle();
	ball.DrawBall();
	for (int i = 0; i < colones; i++) {
		for (int j = 0; j < 10; j++) {
			switch (index)
			{
			case 0:
				level1[i][j].Draw();
				break;
			case 1:
				level2[i][j].Draw();
				break;
			case 2:
				level3[i][j].Draw();
				break;
			case 3:
				level4[i][j].Draw();
				break;
			};
		}
	}
}

void GameManager::CreateGame()
{
	paddle = Paddle(Rectangle{ (float)(WIDTH / 2.0 - 60), (float)(HEIGHT - HEIGHT / 10.0), 120, 10 });
	InitializeGame();
}

void GameManager::InitializeGame()
{
	Vector2 coordinates = { 40,0 };
	for (int i = 0; i < colones; i++) {
		coordinates.x = 40;
		coordinates.y += 22;
		for (int j = 0; j < 10; j++) {
			Brick brick = Brick(Rectangle{ coordinates.x, coordinates.y, 98.4, 20 }, Vector2{ (float)i, (float)j }, 1, BLUE);
			switch (index)
			{
			case 0:
				level1[i][j] = brick;
				break;
			case 1:
				level2[i][j] = brick;
				break;
			case 2:
				level3[i][j] = brick;
				break;
			case 3:
				level4[i][j] = brick;
				break;
			};
			coordinates.x += 100.4;
		}
	}
}

bool GameManager::IsEverythingDestroyed()
{
	for (int i = 0; i < colones; i++) {
		for (int j = 0; j < 10; j++) {
			
			switch (index)
			{
			case 0:
				if (level1[i][j].GetLife() != 0) {
					return false;
				}
				break;
			case 1:
				if (level2[i][j].GetLife() != 0) {
					return false;
				}
				break;
			case 2:
				if (level3[i][j].GetLife() != 0) {
					return false;
				}
				break;
			case 3:
				if (level4[i][j].GetLife() != 0) {
					return false;
				}
				break;
			};
		}
	}
	return true;
}
