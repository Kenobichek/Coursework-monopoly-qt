#pragma once

class Config {
public:
	int getMapSize();
	int getMaximumAllowedPlayer();
	int getNumberDice();
	int getMoneyStart();
	int getMoneyRound();

private:
	int mapSize_ = 20;
	int maximumAllowedPlayer_ = 4;
	int numberDice_ = 1;
	int moneyStart_ = 1500;
	int moneyRound_ = 200;
};