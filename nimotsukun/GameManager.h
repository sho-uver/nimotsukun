#pragma once
// Gameの進行役
// Stageの状態を毎ターン確認してクリア判定をする
// mainからコマンドを受け取って各ゲームオブジェクトに通知する
// startgameで初期化処理

#include "Stage.h"
#include "InputCommand.h"
#include <string>
using namespace std;

class GameManager {
private:
	Stage stage;
public:
	void start();
	void update(string str);
	void draw();
};