#pragma once
#include "Cell.h"

class Question : public Cell {
public:
	void deserialize(const json& data);

	bool isBusiness();
	bool isQuestion();

	int getNumberBusiness();
	int getBought();
	int getCost();
	int getTax();

	void setTax(int tax);
	void setBought(int bought);

	void buyCell(std::shared_ptr<IPlayer> iplayer);
	bool improveCell(std::shared_ptr<IPlayer> iplayer);
	bool disimproveCell(std::shared_ptr<IPlayer> iplayer);

	std::shared_ptr<IPlayer> getPlayerBought();
	void setPlayerBought(std::shared_ptr<IPlayer> iplayer);

	void action(QTextBrowser* textBrowser, std::shared_ptr<IPlayer> iplayer);

private:
};