#pragma once

#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class GameManager
{
private:
	int WIDTH;
	int HEIGHT;
public:
	GameManager(int Width, int Height);
	~GameManager();
	void Update();
	void Draw();
	void CreateGame();
};

