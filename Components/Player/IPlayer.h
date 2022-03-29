#pragma once
#include <iostream>
#include <vector>
#include <QString>

#include "../Game/Dice.h"
#include "../Game/Config.h"

class IPlayer {
public:
	IPlayer() : dices_(config_.getNumberDice(), Dice()) {}
	IPlayer(int id) : dices_(config_.getNumberDice(), Dice()),
				id_(id), money_(config_.getMoneyStart()), position_(0) {}

	QString info();


	int rollDices();
	int getID();
	int getPosition();
	int getMoney();
	int getInGame();
	void setInGame(bool inGame);
	void setMoney(int money);
	virtual bool isBot() = 0;
	virtual bool buyCell(int cost) = 0;
	virtual bool taxCell(int tax, std::shared_ptr<IPlayer> iplayer) = 0;

protected:
	Config config_;
	int id_ = 0;
	int money_ = 0;
	int position_ = 0;
	std::vector<Dice> dices_;
	bool inGame_ = true;
	int changePosition(int sum);
};