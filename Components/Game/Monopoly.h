#pragma once
#include <QtWidgets/QMainWindow>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <unordered_map>

#include "../Cells/Cell.h"

#include "../Player/Bot.h"
#include "../Player/IPlayer.h" 
#include "../Player/Player.h"

#include "../Factory/Factory.h"

#include "Script.h"

class Monopoly : public Script {
public:
	Monopoly() : business_(6, std::vector<std::shared_ptr<Cell>>()) {}

	void startGame(int player, int bot);

private:
	int numberPlayers_ = 0;
	int numberBots_ = 0;

	Ui::monopoly ui_;

	std::string path = "resourses/dataAttackTitans.json";

	std::vector<std::shared_ptr<IPlayer>> players_;
	std::vector<std::shared_ptr<Cell>> mapMonopoly_;
	std::vector<std::vector<std::shared_ptr<Cell>>> business_;

	std::vector<std::shared_ptr<Cell>> setFieldData();
	std::vector<std::shared_ptr<IPlayer>> setNumberPlayers();

};