#include "Ball.h"
#include "Paddle.h"
#include <iostream>

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::Update(const int WIDTH, const int HEIGHT, Paddle paddle)
{
    Move(GetFrameTime());
    CheckCollision(WIDTH, HEIGHT, paddle);
}

void Ball::Move(float deltaTime)
{
    mBallPos.x += mSpeed.x * deltaTime;
    mBallPos.y += mSpeed.y * deltaTime;
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

        float newSpeedY = mSpeed.x * std::abs(collisionPosition) / (paddle.GetPaddleRect().width / 2);

        mSpeed.x = newSpeedY;
        BounceY();
    }
    if (mBallPos.y > paddle.GetPaddleRect().y) {
        mBallPos = { 400, 250 };
        mSpeed = { 200, 200 };
    }
}

void Ball::DrawBall()
{
    DrawCircle(mBallPos.x, mBallPos.y, BALLRADIUS, RED);
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

Vector2 Ball::GetSpeed()
{
    return mSpeed;
}

Vector2 Ball::GetPosition()
{
    return mBallPos;
}