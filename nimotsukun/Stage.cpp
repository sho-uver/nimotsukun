#include "Stage.h"
#include "Wall.h"
#include "Target.h"
#include "Player.h"
#include "Baggage.h"

void Stage::init() {
	// 壁を生成
	// 上辺と下辺
	for (int n = 0; n < stageColumn; n++) {
		Wall wall1,wall2;
		wall1.setPoint(0,n);
		wall2.setPoint(stageRow, n);
		goList[0][n] = &wall1;
		goList[stageRow][n] = &wall2;
	}
	// 横
	// すでに上辺と下辺分はつくられているので省く
	for (int n = 1; n < stageRow-1; n++) {
		Wall wall1;
		Wall wall2; wall1.setPoint(0, n);
		wall2.setPoint(stageRow, n);
		goList[n][0] = &wall1;
		goList[n][stageColumn] = &wall2;
	}

	// 目的地を生成
	Target target1,target2; 
	target1.setPoint(1, 1);
	target2.setPoint(1, 2);
	goList[1][1] = &target1;
	goList[1][2] = &target2;

	// プレイヤーを生成
	Player player;
	player.setPoint(1, 3);
	goList[1][3] = &player;

	// 荷物を生成
	Baggage baggage1, baggage2;
	baggage1.setPoint(2, 1);
	baggage2.setPoint(2, 2);
	goList[2][1] = &baggage1;
	goList[2][2] = &baggage2;

}