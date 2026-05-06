#pragma once

#include "MovableObject.h";

class Player: public MovableObject {
public:
	Player() { gObjType = Type_Player; }
};
