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
			if (ball.GetPosition().x - ball.GetRadius() < mBrickRectangle.x) { // gauche
				mColor = RED;
				ball.SetPos(Vector2{ mBrickRectangle.x - ball.GetRadius() , ball.GetPosition().y });
				ball.SetSpeed(Vector2{ -ball.GetSpeed().x, ball.GetSpeed().y });
				LooseLife();
			}
			else if (ball.GetPosition().x + ball.GetRadius() > mBrickRectangle.x + mBrickRectangle.width) { // droite
				mColor = RED;
				ball.SetPos(Vector2{ mBrickRectangle.x + mBrickRectangle.width + ball.GetRadius() , ball.GetPosition().y });
				ball.SetSpeed(Vector2{ -ball.GetSpeed().x, ball.GetSpeed().y });
				LooseLife();
			}
			else if (ball.GetPosition().y - ball.GetRadius() < mBrickRectangle.y) { // haut
				mColor = RED;
				ball.SetPos(Vector2{ ball.GetPosition().x, mBrickRectangle.y - ball.GetRadius() });
				ball.SetSpeed(Vector2{ ball.GetSpeed().x, -ball.GetSpeed().y });
				LooseLife();
			}
			else if (ball.GetPosition().y + ball.GetRadius() > mBrickRectangle.y + mBrickRectangle.height) { // bas
				mColor = RED;
				ball.SetPos(Vector2{ ball.GetPosition().x, mBrickRectangle.y + mBrickRectangle.height + ball.GetRadius() });
				ball.SetSpeed(Vector2{ ball.GetSpeed().x, -ball.GetSpeed().y });
				LooseLife();
			}
			ball.AddScore(500);
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
