#pragma once
class Point {
private:
	int x = 0;
	int y = 0;
public:
	void setX(int a) { x = a;}
	void setY(int b) { y = b; }
	int getX() { return x; }
	int getY() { return y; }
	Point(int a = 0, int b = 0) { x = a; y = b;};
	friend Point operator+(Point p1,Point p2) { return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY()); }
	friend bool operator==(Point p1, Point p2) {return p1.getX() == p2.getX() && p1.getY() == p2.getY();}
};