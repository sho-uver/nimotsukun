#pragma once
#include "InputCommand.h";
#include "GameObject.h";

class MovableObject : GameObject{
private:
	bool isOnTarget = false;
public:
	Point move(InputCommand ic);
	bool getIsOnTarget() { return isOnTarget; }
	void setIsOnTarget(bool flg) { isOnTarget = flg; }
};
