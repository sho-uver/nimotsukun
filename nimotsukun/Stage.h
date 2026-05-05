#pragma once
// ステージ上のゲームオブジェクトを二重配列で保持する
// 指定されたゲームオブジェクトのステージ上のゲームオブジェクトの位置を配置し直す
// 特定の位置のゲームオブジェクトを返却する
// ステージの壁と目的地だけ初期化
#include "GameObject.h"
#include "MovableObject.h"

class Stage {
public:
	static const int stageRow = 5;
	static const int stageColumn = 8;
	static const int target1X = 3;
	static const int target1Y = 3;
	static const int target2X = 4;
	static const int target2Y = 3;
	void init();
	void moveMovableObject(MovableObject mo);
	void resetTarget();
	GameObject* getPointOfGameObject(int a, int b) { return goList[a][b]; };
private:
	GameObject* goList[stageRow][stageColumn];
};