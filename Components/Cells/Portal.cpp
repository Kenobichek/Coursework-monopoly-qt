#include "Portal.h"

void Portal::deserialize(const json& data) {
	data.at("id").get_to(id_);
	data.at("image").get_to(image_);
	map_->setPixmap(QPixmap(QString::fromStdString(data.at("image"))));
	name_ = "portal";
}

bool Portal::isBusiness() {
	return false;
}

bool Portal::isQuestion() {
	return false;
}

int Portal::getNumberBusiness() {
	throw "Business cannot be on the portal\n";
}

int Portal::getBought() {
	throw "A player cannot own a portal\n";
}

int Portal::getCost() {
	throw "There is no price on the portal";
}

void Portal::setTax(int tax) {
	throw "Cannot set a tax in a portal\n";
}

void Portal::setBought(int bought) {
	throw "Cannot set a bought in a portal\n";
}

void Portal::buyCell(std::shared_ptr<IPlayer> iplayer) {
	throw "Cannot buy a field with a portal\n";
}

bool Portal::improveCell(std::shared_ptr<IPlayer> iplayer) {
	throw "Portal cannot be upgraded\n";
}

bool Portal::disimproveCell(std::shared_ptr<IPlayer> iplayer) {
	throw "Portal cannot be worsen\n";
}

int Portal::getTax() {
	throw "Cannot tax a field with a portal\n";
}

std::shared_ptr<IPlayer> Portal::getPlayerBought() {
	throw "Unable to find the person who owns the field in the portal\n";
}

void Portal::setPlayerBought(std::shared_ptr<IPlayer> iplayer) {
	throw "Portal";
}

void Portal::action(QTextBrowser* textBrowser, std::shared_ptr<IPlayer> iplayer) {
	bool luck = rand() % 2;
	if (luck) {
		textBrowser->insertPlainText(QString::fromStdString("> You stepped on the portal leading to hell, looked aroundand and returned to the game\n"));
	}
	else {
		textBrowser->insertPlainText(QString::fromStdString("> You stepped on a portal leading to hell, and there you died\n"));
		iplayer->setInGame(false);
	}

}