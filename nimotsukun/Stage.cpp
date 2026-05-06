#include "Stage.h"
#include "Wall.h"
#include "Target.h"
#include "Player.h"
#include "Baggage.h"
#include "GameObject.h"

void Stage::init() {
	for (int h = 0; h < stageRow; h++) {
		for (int w = 0; w < stageColumn; w++) {
			noneZone[h * stageColumn + w].setPoint(w, h);
			goList[h][w] = &noneZone[h * stageColumn + w];
		}
	}

	// 壁を生成
	// 上辺と下辺
	for (int w = 0; w < stageColumn; w++) {
		wall[w].setPoint(w,0);
		wall[stageColumn + w].setPoint(w,stageRow-1);
		goList[0][w] = &wall[w];
		goList[stageRow - 1][w] = &wall[stageColumn + w];
	}
	 //横
	 //すでに上辺と下辺分はつくられているので省く
	for (int h = 0; h < stageRow - 2; h++) {
		wall[stageColumn * 2 + h].setPoint(0, h + 1);
		wall[stageColumn * 2 + stageRow + h].setPoint( stageColumn - 1, h + 1);
		goList[h + 1][0] = &wall[stageColumn * 2 + h];
		goList[h + 1][stageColumn - 1] = &wall[stageColumn * 2 + (stageRow - 2) + h];
	}

	// 目的地を生成
	target1.setPoint(2, 1);
	target2.setPoint(3, 1);
	goList[1][2] = &target1;
	goList[1][3] = &target2;

	// プレイヤーを生成
	player.setPoint(5, 1);
	goList[1][5] = &player;

	// 荷物を生成
	baggage1.setPoint(2, 2);
	baggage2.setPoint(3, 2);
	goList[2][2] = &baggage1;
	goList[2][3] = &baggage2;
}

void Stage::moveMovableObject(Point current, Point next) {
	GameObject* movableObj = goList[current.getY()][current.getX()];
	GameObject* targetObj = goList[next.getY()][next.getX()];
	
	goList[next.getY()][next.getX()] = movableObj;
	goList[next.getY()][next.getX()]->setPoint(Point(next.getX(), next.getY()));

	if (current == Point(Target::targetPoint1X, Target::targetPoint1Y)) {
		goList[current.getY()][current.getX()] = &target1;
	}
	else if (current == Point(Target::targetPoint2X, Target::targetPoint2Y))
	{
		goList[current.getY()][current.getX()] = &target2;
	}
	else
	{
		goList[current.getY()][current.getX()] = &noneZone[current.getY() * stageColumn + current.getX()];
	}
}

