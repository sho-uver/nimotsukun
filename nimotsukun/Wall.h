#pragma once
#include "GameObject.h";

class Wall : public GameObject{
public:
	Wall() { gObjType = Type_Wall; }
};