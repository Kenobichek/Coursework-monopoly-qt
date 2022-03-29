#include "Question.h"

void Question::deserialize(const json& data) {
	data.at("id").get_to(id_);
	data.at("image").get_to(image_);

	map_->setPixmap(QPixmap(QString::fromStdString(data.at("image"))));
	name_ = "question";
}

bool Question::isBusiness() {
	return false;
}

bool Question::isQuestion() {
	return true;
}

int Question::getNumberBusiness() {
	throw "Business cannot be on the question\n";
}

int Question::getBought() {
	throw "A player cannot own a portal\n";
}

int Question::getCost() {
	throw "There is no price on the portal";
}

void Question::setTax(int tax) {
	throw "Cannot set a tax in a portal\n";
}

void Question::setBought(int bought) {
	throw "Cannot set a bought in a question\n";
}

void Question::buyCell(std::shared_ptr<IPlayer> iplayer) {
	throw "Cannot buy a field with a portal\n";
}

bool Question::improveCell(std::shared_ptr<IPlayer> iplayer) {
	throw "Portal cannot be upgraded\n";
}

bool Question::disimproveCell(std::shared_ptr<IPlayer> iplayer) {
	throw "Portal cannot be worsen\n";
}

int Question::getTax() {
	throw "Cannot tax a field with a portal\n";
}

std::shared_ptr<IPlayer> Question::getPlayerBought() {
	throw "Unable to find the person who owns the field in the question\n";
}

void Question::setPlayerBought(std::shared_ptr<IPlayer> iplayer) {
	throw "Question";
}

void Question::action(QTextBrowser* textBrowser, std::shared_ptr<IPlayer> iplayer) {
	bool luck = rand() % 2;
	if (luck) {
		int bonus = rand() % 500;
		textBrowser->insertPlainText(QString::fromStdString("> Congratulations you are lucky you won ") + QString::number(bonus) + "$\n");
		iplayer->setMoney(iplayer->getMoney() + bonus);
		textBrowser->insertPlainText(QString::fromStdString("> Now the player has ") + QString::number(iplayer->getMoney()) + "$\n");
	}
	else {
		int bonus = rand() % 500;
		textBrowser->insertPlainText(QString::fromStdString("> Unfortunately the bank charges you ") + QString::number(bonus) + "$\n");
		iplayer->setMoney(iplayer->getMoney() - bonus);
		textBrowser->insertPlainText(QString::fromStdString("> Now the player has ") + QString::number(iplayer->getMoney()) + "$\n");
	}
}