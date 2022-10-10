#pragma once
#include "Tiles.h"
#include <cstdlib>
class Level1:public Tiles{
public:
	Tiles Tiles[50];
	int marked[50];
	int numberOfRows = 3;
	int numberOfTilesPerRow = 9;
	int numberOfTiles = numberOfRows*numberOfTilesPerRow;
	int xUpperBorderSpriteSize = 1000;
	int yUpperBorderSpriteSize = 20;
	int xLeftBorderSpriteSize = 20;
	int xRightBorderSpriteSize = 20;
	int yLeftBorderSpriteSize = 680;
	int yRightBorderSpriteSize = 680;
	int UpperBorderNumber = numberOfTiles;
	int LeftBorderNumber = numberOfTiles + 1;
	int RightBorderNumber = numberOfTiles + 2;
	int numberOfAbilities = 2;
	int xSpriteSize = 100;
	int ySpriteSize = 50;

	virtual void createTiles1() {
		for (int i = 0; i < numberOfTiles; i++)
			marked[i] = 0;
		int x = 0;
		int y = 50;
		for (int i = 0; i < numberOfTiles;i++)
		{
			srand(i);
			int colorType = rand()%9+1;
			x += 50;
			if (x >= 900)
			{
				x = 50;
				y += 50;
			}
			Tiles[i].xPos = x;
			Tiles[i].yPos = y;
			Tiles[i].type = colorType;
			Tiles[i].xRightPos = Tiles[i].xPos + xSpriteSize;
			Tiles[i].yLowerPos = Tiles[i].yPos + ySpriteSize;
			x += 50;
			Tiles[i].numberOrder = i;
		}

		Tiles[UpperBorderNumber].xPos = 0;
		Tiles[UpperBorderNumber].yPos = 0;
		Tiles[UpperBorderNumber].type = 11;
		Tiles[UpperBorderNumber].xRightPos = Tiles[UpperBorderNumber].xPos + xUpperBorderSpriteSize;
		Tiles[UpperBorderNumber].yLowerPos = Tiles[UpperBorderNumber].yPos + yUpperBorderSpriteSize;

		Tiles[LeftBorderNumber].xPos = 0;
		Tiles[LeftBorderNumber].yPos = 20;
		Tiles[LeftBorderNumber].type = 12;
		Tiles[LeftBorderNumber].xRightPos = Tiles[LeftBorderNumber].xPos + xLeftBorderSpriteSize;
		Tiles[LeftBorderNumber].yLowerPos = Tiles[LeftBorderNumber].yPos + yLeftBorderSpriteSize;

		Tiles[RightBorderNumber].xPos = 980;
		Tiles[RightBorderNumber].yPos = 20;
		Tiles[RightBorderNumber].type = 13;
		Tiles[RightBorderNumber].xRightPos = Tiles[RightBorderNumber].xPos + xRightBorderSpriteSize;
		Tiles[RightBorderNumber].yLowerPos = Tiles[RightBorderNumber].yPos + yRightBorderSpriteSize;
	}
	virtual void createAbility1(){
		Tiles[30].xPos = 50;
		Tiles[31].xPos = 250;
		Tiles[30].yPos = 50;
		Tiles[31].yPos = 100;
		Tiles[30].type = 14;
		Tiles[31].type = 15;
		Tiles[30].xRightPos = Tiles[30].xPos + xSpriteSize;
		Tiles[31].xRightPos = Tiles[31].xPos + xSpriteSize;
		Tiles[30].yLowerPos = Tiles[30].yPos + ySpriteSize;
		Tiles[31].yLowerPos = Tiles[31].yPos + ySpriteSize;
		Tiles[30].numberOrder = 0;
		Tiles[31].numberOrder = 11;
	}
};