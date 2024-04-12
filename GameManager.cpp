#include "GameManager.h"

Ball ball;
Paddle paddle = Paddle();

int colones = 5;
int index = 0;
int life = 5;

bool isAlreadyPlaying = false;
bool gameStarted = false;

Brick level1[5][9];
Brick level2[8][9];
Brick level3[11][9];
Brick level4[14][9];

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
	if (!gameStarted && IsKeyPressed(KEY_ENTER))
	{
		gameStarted = true;
		ball.SetSpeed({ 0, 300 });
	}

	for (int i = 0; i < colones; i++) {
		for (int j = 0; j < 9; j++) {
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
	if (ball.GetPosition().y > paddle.GetPaddleRect().y) {
		ball.SetPos({ 540, 600 });
		ball.SetSpeed({ 0, 300 });
		paddle.SetPos({ (float)(WIDTH / 2.0 - 60), (float)(HEIGHT - HEIGHT / 10.0) });
		if (life > 1) {
			life--;
		}
		else {
			life = 5;
			colones = 5;
			index = 0;
			ball.AddScore(-ball.GetScore());
			ball.SetSpeed({ 0, 0 });
			gameStarted = false;
			CreateGame();
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
		for (int j = 0; j < 9; j++) {
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
	DrawText(TextFormat("Lives : %i", life), 980, 680, 20, BLACK);
	if (!gameStarted) {
		DrawText("Press Enter to start...", 540 - MeasureText("Press Enter to start...", 30) / 2, 680, 30, GRAY);
	}
}

void GameManager::CreateGame()
{
	if (!isAlreadyPlaying) {
		paddle = Paddle(Rectangle{ (float)(WIDTH / 2.0 - 60), (float)(HEIGHT - HEIGHT / 10.0), 120, 10 });
	}
	InitializeGame();
}

void GameManager::InitializeGame()
{
	Vector2 coordinates = { 37,0 };
	for (int i = 0; i < colones; i++) {
		coordinates.x = 37;
		coordinates.y += 22;
		for (int j = 0; j < 9; j++) {
			Brick brick = Brick(Rectangle{ coordinates.x, coordinates.y, 110, 20 }, Vector2{ (float)i, (float)j }, 1, BLUE);
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
			coordinates.x += 112;
		}
	}
}

bool GameManager::IsEverythingDestroyed()
{
	for (int i = 0; i < colones; i++) {
		for (int j = 0; j < 9; j++) {
			
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
