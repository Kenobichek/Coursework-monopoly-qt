#pragma once
#include <QtWidgets/QMainWindow>
#include <QCheckBox>
#include <memory>

#include "../Cells/Cell.h"

#include "../Player/IPlayer.h" 

#include "ui_Trade.h"

class Trade : public QMainWindow {
	Q_OBJECT
public:
	Trade(QWidget* parent = Q_NULLPTR);
	void setPlayers(std::shared_ptr<IPlayer> player1, std::shared_ptr<IPlayer> player2);
	void setMap(std::vector<std::shared_ptr<Cell>> mapMonopoly);
	void setCheckBox();

	Ui::trade tradeUI_;


public slots:
	void pushOK();
	void backGame();

private:
	std::vector<std::shared_ptr<Cell>> mapMonopoly_;
	std::vector<QCheckBox*> checkBox_;
	std::vector<QCheckBox*> checkBox2_;

	std::shared_ptr<IPlayer> player1_;
	std::shared_ptr<IPlayer> player2_;
};