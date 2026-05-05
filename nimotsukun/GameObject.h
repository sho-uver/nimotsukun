#pragma once
#include "Point.h";

class GameObject {
protected:
	Point point;
public:
	Point getPoint() { return point; }
	void setPoint(int a, int b) { point.setX(a); point.setY(b); }
};