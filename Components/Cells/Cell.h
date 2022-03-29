#pragma once
#include <iostream>
#include <QLabel>
#include <QString>
#include <QTextBrowser>

#include "../../lib/json.hpp"

#include "../Player/IPlayer.h"

class Cell {
public:
	void setMap(QLabel* map);
	QLabel* getMap();

	virtual void deserialize(const json& data) = 0;

	virtual bool isBusiness() = 0;
	virtual bool isQuestion() = 0;

	virtual int getNumberBusiness() = 0;
	std::string getName();
	std::string getImage();

	virtual int getBought() = 0;
	virtual int getCost() = 0;
	virtual int getTax() = 0;

	virtual void setTax(int tax) = 0;
	virtual void setBought(int bought) = 0;

	virtual void buyCell(std::shared_ptr<IPlayer> iplayer) = 0;
	virtual bool improveCell(std::shared_ptr<IPlayer> iplayer) = 0;
	virtual bool disimproveCell(std::shared_ptr<IPlayer> iplayer) = 0;

	virtual std::shared_ptr<IPlayer> getPlayerBought() = 0;
	virtual void setPlayerBought(std::shared_ptr<IPlayer> iplayer) = 0;

	virtual void action(QTextBrowser* textBrowser, std::shared_ptr<IPlayer> iplayer) = 0;

protected:
	int id_ = 0;
	std::string name_;
	std::string image_;
	QLabel* map_;
};