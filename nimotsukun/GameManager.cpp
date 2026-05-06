#include "GameManager.h"
#include "Stage.h"
#include "GameObjectType.h"
#include <iostream>
#include "Player.h"
#include "Baggage.h"
#include <string>
#include "InputCommand.h"

using namespace std;

void GameManager::start() {
	stage.init();
	draw();
}

void GameManager::update (InputCommand input) {
	if (isClear()) return;
	Point playerPoint = stage.getPlayer().getPoint();
	movePlayer(input, playerPoint);
}

// 配列はY,Xの順、各ゲームオブジェクトのポイントはX,Yの順
void GameManager::draw() {
	for (int h = 0; h < stage.stageRow; h++ ) {
		for (int w = 0; w < stage.stageColumn; w++) {
			GameObject* obj = stage.getPointOfGameObject(h, w);
			switch (obj->getGameObjectType()) {
			case Type_Player: {
				Player* p = dynamic_cast<Player*>(obj);
				if (p->getIsOnTarget()) {
					cout << "P";
				}
				else {
					cout << "p";
				}
				break;
			}
			case Type_Baggage: {
				Baggage* b = dynamic_cast<Baggage*>(obj);
				if (b->getIsOnTarget()) {
					cout << "O";
				}
				else {
					cout << "o";
				}
				break;
			}
			case Type_Wall:
				cout << "#";
				break;
			case Type_Target:
				cout << ".";
				break;
			case Type_NoneZone:
				cout << " ";
				break;
			}
		}
		cout << endl;
	}
	if (isClear()) cout << "ゲームクリア！" << endl << "おめでとう！";
}

InputCommand GameManager::toInputCommand(string str) {
	char input;
	if (str.length() != 1) {
		return Command_None;
	}
	else {
		input = str[0];
	}
	switch (input) {
	case 'w':
		return Command_Up;
	case 'a':
		return Command_Left;
	case 's':
		return Command_Right;
	case 'z':
		return Command_Down;
	case 'q':
		return Command_Quit;
	default:
		return Command_None;
	}
}

void GameManager::movePlayer(InputCommand input, Point playerPoint) {
	// 移動先の決定
	int playerX = playerPoint.getX();
	int playerY = playerPoint.getY();
	bool canMove = false;
	bool hasBaggage = false;
	Point destination;
	Point move;
	switch (input) {
	case Command_Up:
		move = Point(0, -1);
		break;
	case Command_Left:
		move = Point(-1, 0);
		break;
	case Command_Down:
		move = Point(0, 1);
		break;
	case Command_Right:
		move = Point(1, 0);
		break;
	}
	destination = playerPoint + move;
	
	// 移動先のゲームオブジェクトを取得し、移動可否と荷物の有無を確認
	GameObject* playerDestinationObj = stage.getPointOfGameObject(destination);
	switch (playerDestinationObj->getGameObjectType()) {
	case Type_Baggage: 
		hasBaggage = true;
		break;
	case Type_Wall:
		canMove = false;
		break;
	case Type_Target:
		canMove = true;
		break;
	case Type_NoneZone:
		canMove = true;
		break;
	}


	// 荷物を持っていた場合荷物の先に壁や荷物があれば進めないので確認する
	GameObject* beyondBaggageObj;
	if (hasBaggage) {
		beyondBaggageObj = stage.getPointOfGameObject(destination + move);
		switch (beyondBaggageObj->getGameObjectType()) {
		case Type_Baggage:
			canMove = false;
			break;
		case Type_Wall:
			canMove = false;
			break;
		case Type_Target:
			canMove = true;
			break;
		case Type_NoneZone:
			canMove = true;
			break;
		}
	}
	if (!canMove) {
		cout << "その方向には動けません" << endl;
		return;
	}
	if(hasBaggage) stage.moveMovableObject(destination, destination + move);
	stage.moveMovableObject(playerPoint, destination);
}