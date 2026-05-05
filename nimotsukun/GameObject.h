#pragma once
#include "Point.h";
#include "GameObjectType.h"

class GameObject {
protected:
	Point point;
	GameObjectType gObjType = Type_None;
public:
	Point getPoint() { return point; }
	void setPoint(int a, int b) { point.setX(a); point.setY(b); }
	GameObjectType getGameObjectType() { return gObjType; }
	void setGameObjectType(GameObjectType type) { gObjType = type; }
	virtual ~GameObject() {}
};