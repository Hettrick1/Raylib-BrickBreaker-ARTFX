#pragma once
#include "raylib.h"
class Brick
{
private:
	Rectangle mBrickRectangle;
	Vector2 mMapCoordinate;
	Color mColor;
	int mLife;
	bool mIsDestroyed;
public:
	Brick(Rectangle brickRectangle, Vector2 mapCoordinates, int lifes, Color color);
	~Brick();
	void Update();
	void Draw();
	void LooseLife();
	Rectangle GetBrickRectangle();
	Vector2 GetMapCoordinates();
	int GetLife();
};

