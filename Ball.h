#pragma once
#include "raylib.h"
#include "Paddle.h"
class Ball
{
private:
	Vector2 mBallPos = { 400, 250 };
	Vector2 mSpeed = { 200, 200 };
	Vector2 mMaxSpeed = { 200, 200 };
	const int BALLRADIUS = 10;
public:
	Ball();
	~Ball();
	void Update(const int WIDTH, const int HEIGHT, Paddle paddle);
	void Move();
	void CheckCollision(const int WIDTH, const int HEIGHT, Paddle paddle);
	void DrawBall();
	void BounceX();
	void BounceY();
	int GetRadius();
	void SetSpeed(Vector2 speed);
	void SetPos(Vector2 position);
	Vector2 GetSpeed();
	Vector2 GetPosition();
};

