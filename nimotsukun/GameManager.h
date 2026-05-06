#pragma once

#include "Stage.h"
#include "InputCommand.h"
#include <string>
#include "GameObject.h"
#include "Point.h"
using namespace std;

class GameManager {
private:
	Stage stage;
public:
	void start();
	void update(InputCommand input);
	void draw();
	InputCommand toInputCommand(string str);
	void movePlayer(InputCommand input, Point playerPoint);
	bool isClear() {
		return stage.getPointOfGameObject(Target::targetPoint1Y,Target::targetPoint1X)->getGameObjectType() == Type_Baggage
			&& stage.getPointOfGameObject(Target::targetPoint2Y, Target::targetPoint2X)->getGameObjectType() == Type_Baggage
			;
	}
};