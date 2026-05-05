#pragma once
#include "Point.h";

class GameObject {
private:
	Point point;
public:
	Point getPoint() { return point; }
	void setPoint(Point p) { point = p; }
	GameObject(int x, int y);
};