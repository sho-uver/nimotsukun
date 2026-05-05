#pragma once
class Point {
private:
	int x;
	int y;
public:
	void setX(int a) { x = a;}
	void setY(int b) { y = b; }
	void setPoint(int a, int b) { x = a; y = b; }
	int getX() { return x; }
	int getY() { return y; }
};