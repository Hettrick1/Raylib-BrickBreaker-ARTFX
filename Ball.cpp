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
    ballPos.x += speed.x * deltaTime;
    ballPos.y += speed.y * deltaTime;
}

void Ball::CheckCollision(const int WIDTH, const int HEIGHT, Paddle paddle)
{
    if (ballPos.x - BALLRADIUS < 0 || ballPos.x + BALLRADIUS > WIDTH) {
        BounceX();
    }
    else if (ballPos.y - BALLRADIUS < 0 || ballPos.y + BALLRADIUS > HEIGHT) {
        BounceY();
    }
    if (ballPos.y + BALLRADIUS / 2 >= paddle.GetPaddleRect().y && ballPos.x - BALLRADIUS / 2 > paddle.GetPaddleRect().x && ballPos.x + BALLRADIUS / 2 < paddle.GetPaddleRect().x + paddle.GetPaddleRect().width)
    {
        float collisionPosition = (ballPos.x - (paddle.GetPaddleRect().x + paddle.GetPaddleRect().width/2));

        float newSpeedY = speed.x * std::abs(collisionPosition) / paddle.GetPaddleRect().width / 2;

        speed.x = newSpeedY *10;
        BounceY();
    }
    if (ballPos.y - BALLRADIUS / 2 > paddle.GetPaddleRect().y) {
        ballPos = { 400, 250 };
        speed = { 200, 200 };
    }
}

void Ball::DrawBall()
{
    DrawCircle(ballPos.x, ballPos.y, BALLRADIUS, RED);
}

void Ball::BounceX()
{
    speed.x *= -1;
}

void Ball::BounceY()
{
    speed.y *= -1;
}

int Ball::GetRadius()
{
    return BALLRADIUS;
}

Vector2 Ball::GetPosition()
{
    return ballPos;
}