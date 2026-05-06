#pragma once
#include "InputCommand.h";
#include "GameObject.h";
#include "Point.h"
#include "Target.h"

class MovableObject : public GameObject{
protected:
	bool isOnTarget = false;
public:
	Point move(InputCommand ic);
	bool getIsOnTarget() { return point == Point(Target::targetPoint1X, Target::targetPoint1Y) || point == Point(Target::targetPoint2X, Target::targetPoint2Y);}
	void setIsOnTarget(bool flg) { isOnTarget = flg; }
};
