#pragma once
#include "raylib.h"
#include "Paddle.h"
class Ball
{
private:
	Vector2 ballPos = { 400, 250 };
	Vector2 speed = { 200, 200 };
	Vector2 maxSpeed = { 200, 200 };
	const int BALLRADIUS = 10;
public:
	Ball();
	~Ball();
	void Update(const int WIDTH, const int HEIGHT, Paddle paddle);
	void Move(float deltaTime);
	void CheckCollision(const int WIDTH, const int HEIGHT, Paddle paddle);
	void DrawBall();
	void BounceX();
	void BounceY();
	int GetRadius();
	Vector2 GetPosition();
};

