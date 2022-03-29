#include "IPlayer.h"

int IPlayer::rollDices() {
	int sum = 0;
	for (int i = 0; i < dices_.size(); i++) {
		sum += dices_[i].roll();
	}
	changePosition(sum);
	return sum;
}

int IPlayer::changePosition(int sum) {
	position_ += sum;
	position_ %= config_.getMapSize();
	return position_;
}

QString IPlayer::info() {
	return "PLAYER INFORMATION\n  id: " + QString::number(id_) + "\n  money: " + QString::number(money_) + "\n  position: " + QString::number(position_);
}

int IPlayer::getPosition() {
	return position_;
}

int IPlayer::getID() {
	return id_;
}

int IPlayer::getInGame() {
	return inGame_;
}

void IPlayer::setInGame(bool inGame) {
	inGame_ = inGame;
}

void IPlayer::setMoney(int money) {
	money_ = money;
}

int IPlayer::getMoney() {
	return money_;
}