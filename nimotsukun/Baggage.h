#pragma once
#include "MovableObject.h";

class Baggage : public MovableObject {
public:
	Baggage() { gObjType = Type_Baggage; }
};