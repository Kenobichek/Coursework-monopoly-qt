#include "Player.h"

bool Player::isBot() {
	return false;
}

bool Player::buyCell(int cost) {


	//	the player chooses an action

	if (money_ >= cost) {
		money_ -= cost;
		return true;
	}
	return false;
}

bool Player::taxCell(int tax, std::shared_ptr<IPlayer> iplayer) {
	/*std::cout << "1. Pay\n"
				<< "2. Lose\n\n";

	the player chooses an action

	*/

	if (money_ >= tax) {
		this->money_ -= tax;
		int isBoughtMoney = iplayer->getMoney();
		isBoughtMoney += tax;
		iplayer->setMoney(isBoughtMoney);
		return true;
	}
	return false;
}