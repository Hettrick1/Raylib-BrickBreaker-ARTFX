#include "Brick.h"

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

void Brick::Update()
{
}

void Brick::Draw()
{
	DrawRectangle(mBrickRectangle.x, mBrickRectangle.y, mBrickRectangle.width, mBrickRectangle.height, mColor);
}

void Brick::LooseLife()
{
	mLife -= 1;
	if (mLife <= 0) {
		mIsDestroyed = true;
	}
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
