#include "Ball.h"
#include "Paddle.h"
#include <iostream>

Ball::Ball()
{
    mScore = 0;
}

Ball::~Ball()
{
}

void Ball::Update(const int WIDTH, const int HEIGHT, Paddle paddle)
{
    Move();
    CheckCollision(WIDTH, HEIGHT, paddle);
}

void Ball::Move()
{
    mBallPos.x += mSpeed.x * GetFrameTime();
    mBallPos.y += mSpeed.y * GetFrameTime();
}

void Ball::CheckCollision(const int WIDTH, const int HEIGHT, Paddle paddle)
{
    if (mBallPos.x - BALLRADIUS < 0 || mBallPos.x + BALLRADIUS > WIDTH) {
        BounceX();
    }
    else if (mBallPos.y - BALLRADIUS < 0 || mBallPos.y + BALLRADIUS > HEIGHT) {
        BounceY();
    }
    if (mBallPos.y + BALLRADIUS / 2 >= paddle.GetPaddleRect().y && mBallPos.x - BALLRADIUS / 2 > paddle.GetPaddleRect().x && mBallPos.x + BALLRADIUS / 2 < paddle.GetPaddleRect().x + paddle.GetPaddleRect().width)
    {
        float collisionPosition = (mBallPos.x - (paddle.GetPaddleRect().x + paddle.GetPaddleRect().width/2));

        float newSpeedY = mMaxSpeed.x * collisionPosition / (paddle.GetPaddleRect().width / 2);

        mSpeed.x = newSpeedY;
        BounceY();
    }
    if (mBallPos.y > paddle.GetPaddleRect().y) {
        mBallPos = { 400, 250 };
        mSpeed = mMaxSpeed;
    }
}

void Ball::DrawBall()
{
    DrawCircle(mBallPos.x, mBallPos.y, BALLRADIUS, RED);
    DrawText(TextFormat("%i", mScore), 10, 20, 20, BLACK);
}

void Ball::BounceX()
{
    mSpeed.x *= -1;
}

void Ball::BounceY()
{
    mSpeed.y *= -1;
}

int Ball::GetRadius()
{
    return BALLRADIUS;
}

void Ball::SetSpeed(Vector2 speed)
{
    mSpeed = speed;
}

void Ball::SetPos(Vector2 position)
{
    mBallPos = position;
}

Vector2 Ball::GetSpeed()
{
    return mSpeed;
}

Vector2 Ball::GetPosition()
{
    return mBallPos;
}
int Ball::GetScore()
{
    return mScore;
}

void Ball::AddScore(int score)
{
    mScore += score;
}
