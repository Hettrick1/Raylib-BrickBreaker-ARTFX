#include "Paddle.h"

Paddle::Paddle()
{
}

Paddle::Paddle(Rectangle paddlePos)
{
	mPaddleRectangle = paddlePos;
}

Paddle::~Paddle()
{
}

void Paddle::Move(float deltaTime, const int WIDTH)
{
	if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && mPaddleRectangle.x > 0) {
		mPaddleRectangle.x -= mPaddleSpeed.x * deltaTime;
	}
	if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && mPaddleRectangle.x < WIDTH - mPaddleRectangle.width) {
		mPaddleRectangle.x += mPaddleSpeed.x * deltaTime;
	}
}

void Paddle::Update(const int WIDTH)
{
	Move(GetFrameTime(), WIDTH);
}

void Paddle::DrawPaddle()
{
	DrawRectangle(mPaddleRectangle.x+2.5, mPaddleRectangle.y, mPaddleRectangle.width-5, mPaddleRectangle.height, BLACK);
}

Rectangle Paddle::GetPaddleRect()
{
	return mPaddleRectangle;
}

void Paddle::SetPos(Vector2 pos)
{
	mPaddleRectangle.x = pos.x;
	mPaddleRectangle.y = pos.y;
}
