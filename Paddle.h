#pragma once
#include "raylib.h"
class Paddle
{
private:
	Rectangle mPaddleRectangle;
	Vector2 mPaddleSpeed = { 350, 0 };
public:
	Paddle(Rectangle paddlePos);
	~Paddle();
	void Move(float deltaTime, const int WIDTH);
	void Update(const int WIDTH);
	void DrawPaddle();
	Rectangle GetPaddleRect();
};
