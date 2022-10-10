#include "Framework.h"
#include "BreakoutTiles.h"
#include "MovingPlatform.h"
#include "Ball.h"
#include "Level1.h"

/* Test Framework realization */
class MyFramework : public Framework ,public Ball, public Level1{

public:
	int xMovingPlatformSpawn = 400;
	int yMovingPlatformSpawn = 600;
	int xBallSpawn = 500;
	int yBallSpawn = 590;
	int xMousePos = 0;
	int yMousePos = 0;
	bool isSpawned = false;
	bool end = false;
	int xPlatformSpriteSize = 200;
	int yPlatformSpriteSize = 50;

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 1000;
		height = 700;
		fullscreen = false;
	}

	virtual bool Init() {
		//creating the platform which the ball hits to bouce
		createBall();
		createBreakoutTiles();
		createMovingPlatform();
		setMovingPlatformSize(xPlatformSpriteSize, yPlatformSpriteSize);
		initBallSpawnLocation(xBallSpawn, yBallSpawn);
		initMovingPlatformSpawnLocation(xMovingPlatformSpawn, yMovingPlatformSpawn);
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
		//drawTestBackground();
		//spawning the platform which the ball hits to bouce
		drawMovingPlatform();
		spawnTiles1();
		verifyMovingPlatformBallHit();
		verifyBreakoutTilesBallHit();
		verifyGameEnd(end);
		
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		xMousePos = x;
		yMousePos = y;
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		switch (button)
		{
			case FRMouseButton::LEFT:
				ySpeed = -1;
				isSpawned = true;
				moveToCursor(xMousePos,yMousePos);
				break;
		}
	}

	virtual void onKeyPressed(FRKey k) {
		switch (k){
			case FRKey::RIGHT:
				moveMovingPlatform(20,0);
				if(isSpawned==false)
					movePreGameBall(20,0);
				break;
			case FRKey::LEFT:
				moveMovingPlatform(-20,0);
				if (isSpawned == false)
					movePreGameBall(-20,0);
				break;
			case FRKey::DOWN:
				moveMovingPlatform(0,0);
				if (isSpawned == false)
					movePreGameBall(0,0);
				break;
			case FRKey::UP:
				moveMovingPlatform(0,0);
				if (isSpawned == false)
					movePreGameBall(0,0);
				break;
		}
	}
	
	virtual void onKeyReleased(FRKey k) {
		switch (k) {
		case FRKey::RIGHT:
			moveMovingPlatform(20, 0);
			if (isSpawned == false)
				movePreGameBall(20, 0);
			break;
		case FRKey::LEFT:
			moveMovingPlatform(-20, 0);
			if (isSpawned == false)
				movePreGameBall(-20, 0);
			break;
		case FRKey::DOWN:
			moveMovingPlatform(0, 0);
			if (isSpawned == false)
				movePreGameBall(0, 0);
			break;
		case FRKey::UP:
			moveMovingPlatform(0, 0);
			if (isSpawned == false)
				movePreGameBall(0, 0);
			break;
		}
	}

	virtual const char* GetTitle() override{
		return "Arcanoid";
	}
};

int main(int argc, char* argv[])
{
	return run(new MyFramework);
}
