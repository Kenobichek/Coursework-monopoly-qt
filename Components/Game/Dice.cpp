#include "Dice.h"

int Dice::roll() {
	srand(time(NULL));
	value_ = (rand() % numberFaces_) + 1;
	return value_;
}