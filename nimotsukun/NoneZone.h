#pragma once
#include "GameObject.h"

class NoneZone : public GameObject {
public:
	NoneZone() { gObjType = Type_NoneZone; }
};