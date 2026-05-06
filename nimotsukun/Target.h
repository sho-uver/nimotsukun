#pragma once
#include "GameObject.h";
#include "Point.h"

class Target : public GameObject {

public:
	const static int targetPoint1X = 2;
	const static int targetPoint1Y = 1;
	const static int targetPoint2X = 3;
	const static int targetPoint2Y = 1;
	Target() { gObjType = Type_Target; }
};