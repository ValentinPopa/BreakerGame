#pragma once
#include "Framework.h"

class MovingPlatform
{
public:
	Sprite* MovingPlatform;
	int xMovingPlatform = 0;
	int yMovingPlatform = 0;

	virtual void createMovingPlatform()
	{
		MovingPlatform = createSprite("D:\\BreakerGame\\Breaker\\data\\56-Breakout-Tiles.png");
	}
	virtual void setMovingPlatformSize(int width, int height)
	{
		setSpriteSize(MovingPlatform, width, height);
	}
	virtual void initMovingPlatformSpawnLocation(int xSpawnMovingPlatformLocation, int ySpawnMovingPlatformLocation)
	{
		xMovingPlatform = xSpawnMovingPlatformLocation;
		yMovingPlatform = ySpawnMovingPlatformLocation;
	}
	virtual void drawMovingPlatform()
	{
		drawSprite(MovingPlatform, xMovingPlatform, yMovingPlatform);
	}
	virtual void moveMovingPlatform(int xSpeed,int ySpeed)
	{
		xMovingPlatform += xSpeed;
		yMovingPlatform += ySpeed;
	}
};