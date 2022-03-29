#pragma once
#include <stdlib.h>
#include <ctime>

class Dice {
public:
	int roll();
private:
	int value_ = 0;
	int numberFaces_ = 6;
};