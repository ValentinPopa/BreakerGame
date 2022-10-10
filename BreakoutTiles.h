#pragma once
#include "Framework.h"
#include "Level1.h"
#include <iostream>
class BreakoutTiles :public Level1
{
public:;
	int xTileSize = 0;
	int yTileSize = 0;
	Sprite* BreakoutTile[100];

	virtual void createBreakoutTiles()
	{
		createTiles1();
		createAbility1();
		for (int i = 0; i < numberOfTiles + 3 + numberOfAbilities; i++) {
			
			switch (Tiles[i].type)
			{
			case 1:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\01-Breakout-Tiles.png");
				break;
			case 2:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\03-Breakout-Tiles.png");
				break;
			case 3:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\05-Breakout-Tiles.png");
				break;
			case 4:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\07-Breakout-Tiles.png");
				break;
			case 5:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\09-Breakout-Tiles.png");
				break;
			case 6:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\11-Breakout-Tiles.png");
				break;
			case 7:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\13-Breakout-Tiles.png");
				break;
			case 8:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\15-Breakout-Tiles.png");
				break;
			case 9:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\17-Breakout-Tiles.png");
				break;
			case 10:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\19-Breakout-Tiles.png");
				break;
			case 11:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\57-Breakout-Tiles.png");
				break;
			case 12:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\61-Breakout-Tiles.png");
				break;
			case 13:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\61-Breakout-Tiles.png");
				break;
			case 14:
				BreakoutTile[i]= createSprite("D:\\BreakerGame\\Breaker\\data\\41-Breakout-Tiles.png");
				break;
			case 15:
				BreakoutTile[i] = createSprite("D:\\BreakerGame\\Breaker\\data\\42-Breakout-Tiles.png");
				break;
			}
		}
	}
	virtual void setBreakoutTilesSize(Sprite* Sprite, int width, int height)
	{
		setSpriteSize(Sprite, width, height);
	}
	virtual void drawBreakoutTiles(Sprite* Sprite, int xSpawnBreakoutTilesLocation, int ySpawnBreakoutTilesLocation)
	{
		drawSprite(Sprite, xSpawnBreakoutTilesLocation, ySpawnBreakoutTilesLocation);
	}
	virtual void spawnTiles1()
	{
		setSpriteSize(BreakoutTile[30], xSpriteSize, ySpriteSize);
		drawSprite(BreakoutTile[30], Tiles[30].xPos, Tiles[30].yPos);
		setSpriteSize(BreakoutTile[31], xSpriteSize, ySpriteSize);
		drawSprite(BreakoutTile[31], Tiles[31].xPos, Tiles[31].yPos);
		for (int i = 0; i < numberOfTiles; i++) {
			setSpriteSize(BreakoutTile[i], xSpriteSize, ySpriteSize);
			drawSprite(BreakoutTile[i], Tiles[i].xPos, Tiles[i].yPos);
		}
		setSpriteSize(BreakoutTile[UpperBorderNumber], xUpperBorderSpriteSize, yUpperBorderSpriteSize);
		drawSprite(BreakoutTile[UpperBorderNumber], Tiles[UpperBorderNumber].xPos, Tiles[UpperBorderNumber].yPos);
		setSpriteSize(BreakoutTile[LeftBorderNumber], xLeftBorderSpriteSize, yLeftBorderSpriteSize);
		drawSprite(BreakoutTile[LeftBorderNumber], Tiles[LeftBorderNumber].xPos, Tiles[LeftBorderNumber].yPos);
		setSpriteSize(BreakoutTile[RightBorderNumber], xRightBorderSpriteSize, yRightBorderSpriteSize);
		drawSprite(BreakoutTile[RightBorderNumber], Tiles[RightBorderNumber].xPos, Tiles[RightBorderNumber].yPos);
	}
};