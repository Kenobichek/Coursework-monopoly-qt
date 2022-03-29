#include "Cell.h"

void Cell::setMap(QLabel* map) {
	map_ = map;
}

QLabel* Cell::getMap() {
	return map_;
}

std::string Cell::getName() {
	return name_;
}

std::string Cell::getImage() {
	return image_;
}