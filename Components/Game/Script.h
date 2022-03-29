#pragma once

#include <QtWidgets/QMainWindow>

#include "Trade.h"

#include "../Player/IPlayer.h"

#include "../Cells/Cell.h"

#include "ui_Monopoly.h"

class Script : public QMainWindow {
	Q_OBJECT
public:
	Script(QWidget* parent = Q_NULLPTR);

	void setScriptPlayer(std::vector<std::shared_ptr<IPlayer>> players);
	void setScriptMap(std::vector<std::shared_ptr<Cell>> map);
	void setScriptBusiness(std::vector<std::vector<std::shared_ptr<Cell>>> business);
	void setMap();
	void setCost();
	void setPlayers();

	Ui::monopoly ui_;

	std::vector<QLabel*> map_;
	std::vector<QLabel*> cost_;
	std::vector<QPushButton*> playersLabel_;

	Trade trade_;

	std::vector<QString> colors_ = { "#D91136", "#1821D9", "#BF0AA1", "#29A632" };

public slots:
	void startGame();
	void playerTurn();
	void nextPlayer();
	void rollDice();
	void playerBuy();
	void playerTax();
	void skip();
	void slider();
	void pushPlus();
	void pushMinus();
	void trade();
	void pushPlayer1();
	void pushPlayer2();
	void pushPlayer3();
	void pushPlayer4();
	void updateMap();

private:
	std::vector<std::shared_ptr<IPlayer>> players_;
	std::vector<std::shared_ptr<Cell>> mapMonopoly_;
	std::vector<std::vector<std::shared_ptr<Cell>>> business_;

	int activePlayer_ = 0;
	int numberPlayers_ = 0;

	void infoPlayer();
	void enableField();
	void disableField();
	void fieldAction();
	void buyField();
	void taxField();
	void changeSlider();
	void playerLost();
	void gameOver();
	bool checkFullBusiness();
};