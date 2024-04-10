#include "Brick.h"

Brick::Brick()
{
	mBrickRectangle = Rectangle();
	mMapCoordinate = Vector2();
	mColor = Color();
	mLife = 0;
	mIsDestroyed = true;
}

Brick::Brick(Rectangle brickRectangle, Vector2 mapCoordinates, int lifes, Color color)
{
	mBrickRectangle = brickRectangle;
	mMapCoordinate = mapCoordinates;
	mColor = color;
	mLife = lifes;
	mIsDestroyed = false;
}

Brick::~Brick()
{
}

void Brick::Update(Ball& ball)
{
	if (!mIsDestroyed) {
		if (CheckCollisions(ball)) {
			mColor = RED;
			ball.BounceY();
			LooseLife();
		}
	}
}

void Brick::Draw()
{
	if (!mIsDestroyed) {
		DrawRectangle(mBrickRectangle.x, mBrickRectangle.y, mBrickRectangle.width, mBrickRectangle.height, mColor);
	}
}

void Brick::LooseLife()
{
	mLife -= 1;
	if (mLife <= 0) {
		mIsDestroyed = true;
	}
}

bool Brick::CheckCollisions(Ball ball)
{
	return ball.GetPosition().x - ball.GetRadius() < mBrickRectangle.x + mBrickRectangle.width && ball.GetPosition().x + ball.GetRadius() > mBrickRectangle.x && ball.GetPosition().y - ball.GetRadius() < mBrickRectangle.y + mBrickRectangle.height && ball.GetPosition().y + ball.GetRadius() > mBrickRectangle.y;
}

Rectangle Brick::GetBrickRectangle()
{
	return mBrickRectangle;
}

Vector2 Brick::GetMapCoordinates()
{
	return mMapCoordinate;
}

int Brick::GetLife()
{
	return mLife;
}
