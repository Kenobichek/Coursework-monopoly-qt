#include "Business.h"

void Business::deserialize(const json& data) {
	data.at("id").get_to(id_);
	data.at("name").get_to(name_);
	data.at("cost").get_to(cost_);
	data.at("business").get_to(business_);
	data.at("image").get_to(image_);

	map_->setPixmap(QPixmap(QString::fromStdString(data.at("image"))));
}

bool Business::isBusiness() {
	return true;
}

bool Business::isQuestion() {
	return false;
}

int Business::getNumberBusiness() {
	return business_;
}

int Business::getBought() {
	return bought_;
}

int Business::getCost() {
	return cost_;
}

void Business::setTax(int tax) {
	tax_ = tax;
}

void Business::setBought(int bought) {
	bought_ = bought;
}

void Business::buyCell(std::shared_ptr<IPlayer> iplayer) {
	bought_ = iplayer->getID();
	isBought_ = iplayer;
	tax_ = cost_ * taxCoefficient;
}

bool Business::improveCell(std::shared_ptr<IPlayer> iplayer) {
	if (tax_ == 0) {
		if (iplayer->getMoney() >= (cost_ * taxCoefficient * 2)) {
			tax_ = cost_ * taxCoefficient;
			int playerMoney = iplayer->getMoney() - cost_ * taxCoefficient * 2;
			iplayer->setMoney(playerMoney);
			return true;
		}
	}
	else if (iplayer->getMoney() >= (tax_ * 2)) {
		tax_ += tax_;
		int playerMoney = iplayer->getMoney() - tax_ * 2;
		iplayer->setMoney(playerMoney);
		return true;
	}
	return false;
}

bool Business::disimproveCell(std::shared_ptr<IPlayer> iplayer) {
	if (tax_ != 0) {
		tax_ -= (cost_ * taxCoefficient);
		int playerMoney = iplayer->getMoney() + (cost_ * taxCoefficient);
		iplayer->setMoney(playerMoney);
		return true;
	}
	return false;
}

int Business::getTax() {
	return tax_;
}

std::shared_ptr<IPlayer> Business::getPlayerBought() {
	return isBought_;
}

void Business::setPlayerBought(std::shared_ptr<IPlayer> iplayer) {
	isBought_ = iplayer;
}

void Business::action(QTextBrowser* textBrowser, std::shared_ptr<IPlayer> iplayer) {

}