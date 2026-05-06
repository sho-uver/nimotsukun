#pragma once
#include "GameObject.h"
#include "MovableObject.h"
#include "Stage.h"
#include "Wall.h"
#include "Target.h"
#include "Player.h"
#include "Baggage.h"
#include "NoneZone.h"

class Stage {
public:
	static const int stageRow = 5;
	static const int stageColumn = 8;
	static const int target1X = 3;
	static const int target1Y = 3;
	static const int target2X = 4;
	static const int target2Y = 3;
	void init();
	void moveMovableObject(Point current, Point next);
	void resetTarget();
	GameObject* getPointOfGameObject(int a, int b) { return goList[a][b]; };
	GameObject* getPointOfGameObject(Point p) { return goList[p.getY()][p.getX()]; };
	Player getPlayer() { return player; }
private:
	GameObject* goList[stageRow][stageColumn];
	Player player;
	Baggage baggage1;
	Baggage baggage2;
	Target target1;
	Target target2;
	Wall wall[stageRow * 2 + (stageColumn - 2) * 2];
	NoneZone noneZone[stageRow * stageColumn];
};