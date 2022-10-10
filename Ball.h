#pragma once
#include "Framework.h"
#include "BreakoutTiles.h"
#include "MovingPlatform.h"

class Ball:public BreakoutTiles,public MovingPlatform{
public:
	Sprite* Ball;
	float xBall = 0;
	float yBall = 0;
	float ySpeed = 0;
	float xSpeed = 0;
	int destroyedTiles = 0;
	int xBallSpeedStart = 1;
	int yBallSpeedStart = 1;
	bool slowAbilityFound = false;
	bool fastAbilityFound = false;
	float ySlow = 1;
	float yFast = 1;
	virtual void createBall()
	{
		Ball = createSprite("D:\\BreakerGame\\Breaker\\data\\63-Breakout-Tiles.png");
	}

	virtual void setBallSize(int width, int height)
	{
		setSpriteSize(Ball, width, height);
	}

	virtual void initBallSpawnLocation(float/*int*/ xSpawnBallLocation, float/*int*/ ySpawnBallLocation)
	{
		xBall = xSpawnBallLocation;
		yBall = ySpawnBallLocation;
	}

	virtual void drawBall()
	{
		drawSprite(Ball, (int)xBall, (int)yBall);
	}

	virtual void moveBall(float xSpeed, float ySpeed)
	{
		xBall += xSpeed;
		yBall += ySpeed;
		drawBall();
	}
	virtual void moveAbility(float xSpeed, float ySpeed,int i)
	{
		Tiles[i].xPos += xSpeed;
		Tiles[i].yPos += ySpeed;
		drawSprite(BreakoutTile[i], (int)Tiles[i].xPos, (int)Tiles[i].yPos);
	}
	virtual void verifyMovingPlatformBallHit()
	{
		drawBall();
		if (xBall >= xMovingPlatform && xBall <= xMovingPlatform + xSpriteSize && yBall >= yMovingPlatform && yBall <= yMovingPlatform + ySpriteSize) {
			ySpeed = -ySpeed;
		}
		if (xBall >= xMovingPlatform && xBall <= (xMovingPlatform + xSpriteSize )/ 2 && yBall >= yMovingPlatform && yBall <= yMovingPlatform + ySpriteSize)
			xSpeed = xSpeed - 0.5;
		else
			if(xBall>=(xMovingPlatform+xSpriteSize)/2 && xBall<= xMovingPlatform + xSpriteSize && yBall >= yMovingPlatform && yBall <= yMovingPlatform + ySpriteSize)
			xSpeed = xSpeed + 0.5;
		moveBall(xSpeed, ySpeed);
	}
	virtual void verifyMovingPlatformAbilityHit(int i)
	{
		if (Tiles[i].xPos >= xMovingPlatform && Tiles[i].xPos <= xMovingPlatform + 200 && Tiles[i].yPos >= yMovingPlatform && Tiles[i].yPos<=yMovingPlatform+5)
		{
			Tiles[i].xPos = -100;
			if (i == 30)
			{
				ySpeed = 0.4 * ySpeed;
			}
			else
				if (i == 31)
				{
					ySpeed = ySpeed + 0.4 * ySpeed;
				}
			if (ySpeed < 0.5 * yBallSpeedStart)
				ySpeed = 0.5 * yBallSpeedStart;
			if (ySpeed > 2 * yBallSpeedStart)
				ySpeed = 2 * yBallSpeedStart;
		}
	}

	virtual void verifyBreakoutTilesBallHit()
	{
		if (slowAbilityFound == true) {
			if(Tiles[9].destroyed==true && Tiles[18].destroyed==true)
				moveAbility(0, ySlow, 30);
			verifyMovingPlatformAbilityHit(30);
		}
		if (fastAbilityFound == true) {
			if(Tiles[20].destroyed==true)
				moveAbility(0, yFast, 31);
			verifyMovingPlatformAbilityHit(31);
		}
		drawBall();
		for (int i = 0; i < numberOfTiles; i++)
		{	
				if (xBall >= Tiles[i].xPos - 1 && xBall <= Tiles[i].xRightPos + 1) {
					if (yBall >= Tiles[i].yPos && yBall <= Tiles[i].yLowerPos)
					{
						
						xSpeed = -(xSpeed-xSpeed*0.1);
						ySpeed = -(ySpeed-ySpeed*0.1);

						if (xSpeed < 0.4 * xBallSpeedStart)
							xSpeed = 0.4 * xBallSpeedStart;
						if (ySpeed < 0.4 * yBallSpeedStart)
							ySpeed = 0.4 * yBallSpeedStart;

						deSpawn(i);
						if (Tiles[i].type == 5)
							verifyOrangeTile(i);
						if (Tiles[i].numberOrder == Tiles[30].numberOrder)
							slowAbilityFound = true;	
						if (Tiles[i].numberOrder == Tiles[31].numberOrder)
							fastAbilityFound = true;	
						break;
					}	
				}	
		}
		if (xBall <= xLeftBorderSpriteSize && yBall >= yUpperBorderSpriteSize <= Tiles[LeftBorderNumber].yLowerPos)
			xSpeed = -(xSpeed+xSpeed*0.1);
		else
			if (xBall >= Tiles[RightBorderNumber].xPos && yBall >= yUpperBorderSpriteSize && yBall <= Tiles[RightBorderNumber].yLowerPos)
				xSpeed = -(xSpeed+xSpeed*0.1);
			else
				if (yBall<=yUpperBorderSpriteSize)
					ySpeed = -(ySpeed+0.1*ySpeed);
				else
					if (yBall >=599)
						ySpeed = -(ySpeed+ySpeed*0.1);

		if (xSpeed > 3 * xBallSpeedStart)
			xSpeed = 3 * xBallSpeedStart;
		if (ySpeed > 3 * yBallSpeedStart)
			ySpeed = 3 * yBallSpeedStart;
		moveBall(xSpeed, ySpeed);
	}

	virtual void movePreGameBall(int xMoveSpeed,int yMoveSpeed)
	{
		xBall += xMoveSpeed;
		yBall += yMoveSpeed;
	}

	virtual void moveToCursor(float xMousePos,float yMousePos)
	{
		if (xBall > xMousePos)
			xSpeed = -1;
		else
			xSpeed = 1;
		ySpeed = -1;
		moveBall(xSpeed, ySpeed);
	}
	virtual void verifyGameEnd(bool end)
	{
		if (destroyedTiles == 27)
			end = true;
		if (yBall >= 710)
			end = true;
	}
	virtual void verifyOrangeTile(int i)
	{
		int up = -1;
		int down = -1;
		int left = -1;
		int right = -1;
		int rightDiagUp = -1;
		int rightDiagDown = -1;
		int leftDiagDown = -1;
		int leftDiagUp = -1;
		if (Tiles[i].numberOrder == numberOfTilesPerRow - 1) {
			int left = Tiles[i].numberOrder - 1;
			int down = Tiles[i].numberOrder + 9;
			int leftDiagDown = down - 1;
		}
		else
			if (Tiles[i].numberOrder == 0) {
				right = Tiles[i].numberOrder + 1;
				down = Tiles[i].numberOrder + 9;
				rightDiagDown = down + 1;
			}
			else
				if (Tiles[i].numberOrder == numberOfTiles - 1) {
					up = Tiles[i].numberOrder - 9;
					left = Tiles[i].numberOrder - 1;
					leftDiagUp = up - 1;
				}
				else
					if (Tiles[i].numberOrder == numberOfTiles - numberOfTilesPerRow)
					{
						up = Tiles[i].numberOrder - 9;
						right = Tiles[i].numberOrder + 1;
						rightDiagUp = up + 1;
					}
					else
						if (Tiles[i].numberOrder > numberOfTiles - numberOfTilesPerRow  && Tiles[i].numberOrder < numberOfTiles-1) {
							left = Tiles[i].numberOrder - 1;
							right = Tiles[i].numberOrder + 1;
							up = Tiles[i].numberOrder - 9;
							leftDiagUp = up - 1;
							rightDiagUp = up + 1;
						}
						else
							if (Tiles[i].numberOrder > 0 && Tiles[i].numberOrder < numberOfTilesPerRow-1)
							{
								left = Tiles[i].numberOrder - 1;
								down = Tiles[i].numberOrder + 9;
								right = Tiles[i].numberOrder + 1;
								leftDiagDown = down - 1;
								rightDiagDown = down + 1;
							}
							else
								if (Tiles[i].numberOrder % 9 == 0)
								{
									right = Tiles[i].numberOrder + 1;
									up = Tiles[i].numberOrder - 9;
									down = Tiles[i].numberOrder + 9;
									rightDiagUp = up + 1;
									rightDiagDown = down + 1;
								}
								else
									if ((Tiles[i].numberOrder+1) % 9  == 0)
									{
										left =Tiles[i].numberOrder - 1;
										down = Tiles[i].numberOrder + 9;
										up = Tiles[i].numberOrder - 9;
										leftDiagUp = up - 1;
										leftDiagDown = down - 1;
									}
									else
									{
										right = Tiles[i].numberOrder + 1;
										left = Tiles[i].numberOrder - 1;
										down = Tiles[i].numberOrder + 9;
										up = Tiles[i].numberOrder - 9;
										leftDiagUp = up - 1;
										leftDiagDown = down - 1;
										rightDiagUp = up + 1;
										rightDiagDown = down + 1;
									}
		
		if (left != -1) {
			if (Tiles[left].numberOrder == Tiles[30].numberOrder)
				slowAbilityFound = true;
			if (Tiles[left].numberOrder == Tiles[31].numberOrder)
				fastAbilityFound = true;
			deSpawn(left);
		}
		if (right != -1) {
			if (Tiles[right].numberOrder == Tiles[30].numberOrder)
				slowAbilityFound = true;
			if (Tiles[right].numberOrder == Tiles[31].numberOrder)
				fastAbilityFound = true;
			deSpawn(right);
		}
		if (down != -1) {
			if (Tiles[down].numberOrder == Tiles[30].numberOrder)
				slowAbilityFound = true;
			if (Tiles[down].numberOrder == Tiles[31].numberOrder)
				fastAbilityFound = true;
			deSpawn(down);
		}
		if (up != -1) {
			if (Tiles[up].numberOrder == Tiles[30].numberOrder)
				slowAbilityFound = true;
			if (Tiles[up].numberOrder == Tiles[31].numberOrder)
				fastAbilityFound = true;
			deSpawn(up);
		}
		if (leftDiagDown != -1) {
			if (Tiles[leftDiagDown].numberOrder == Tiles[30].numberOrder)
				slowAbilityFound = true;
			if (Tiles[leftDiagDown].numberOrder == Tiles[31].numberOrder)
				fastAbilityFound = true;
			deSpawn(leftDiagDown);
		}
		if (leftDiagUp != -1) {
			if (Tiles[leftDiagUp].numberOrder == Tiles[30].numberOrder)
				slowAbilityFound = true;
			if (Tiles[leftDiagUp].numberOrder == Tiles[31].numberOrder)
				fastAbilityFound = true;
			deSpawn(leftDiagUp);
		}
		if (rightDiagDown != -1) {
			if (Tiles[rightDiagDown].numberOrder == Tiles[30].numberOrder)
				slowAbilityFound = true;
			if (Tiles[rightDiagDown].numberOrder == Tiles[31].numberOrder)
				fastAbilityFound = true;
			deSpawn(rightDiagDown);
		}
		if (rightDiagUp != -1) {
			if (Tiles[rightDiagUp].numberOrder == Tiles[30].numberOrder)
				slowAbilityFound = true;
			if (Tiles[rightDiagUp].numberOrder == Tiles[31].numberOrder)
				fastAbilityFound = true;
			deSpawn(rightDiagUp);
		}
	}
	virtual void deSpawn(int i)
	{
		if (Tiles[i].destroyed == false) {
			destroySprite(BreakoutTile[i]);
			Tiles[i].xPos = -100;
			Tiles[i].xRightPos = -100;
			Tiles[i].yPos = -100;
			Tiles[i].yLowerPos = -100;
			destroyedTiles++;
			Tiles[i].destroyed = true;
		}
	}
};