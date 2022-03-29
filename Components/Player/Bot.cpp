#include "Bot.h"

bool Bot::isBot() {
	return true;
}

bool Bot::buyCell(int cost) {

	//	if there is enough money, the bot always buys the field

	if (money_ >= cost) {
		money_ -= cost;
		return true;
	}
	return false;
}

bool Bot::taxCell(int tax, std::shared_ptr<IPlayer> iplayer) {
	if (money_ >= tax) {
		money_ -= tax;
		int isBoughtMoney = iplayer->getMoney();
		isBoughtMoney += tax;
		iplayer->setMoney(isBoughtMoney);
		return true;
	}
	return false;
}