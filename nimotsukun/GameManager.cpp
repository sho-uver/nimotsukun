#include "GameManager.h"
#include "Stage.h"
#include "GameObjectType.h"
#include <iostream>
#include "Player.h"
#include "Baggage.h"

using namespace std;

void GameManager::start() {
	stage.init();
	draw();
}

void GameManager::update (string str) {

}

void GameManager::draw() {
	for (int n = 0; n < stage.stageRow; n++ ) {
		for (int i = 0; i < stage.stageColumn; i++) {
			GameObject* obj = stage.getPointOfGameObject(n, i);
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
			}
		}
		cout << endl;
	}
}