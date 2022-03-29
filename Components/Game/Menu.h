#pragma once
#include <QtWidgets/QMainWindow>

#include "ui_Menu.h"
#include "Config.h"
#include "Monopoly.h"

class Menu : public QMainWindow {
	Q_OBJECT

public slots:
	void pushPlayerSpinBox();
	void pushBotSpinBox();
	void play();

public:
	Menu(QWidget* parent = Q_NULLPTR);

	int getNumberPlayers();
	int getNumberBots();
	int getMaximumAllowed();
	int getTotal();

private:
	Monopoly game_;
	Config config_;
	int numberPlayers_ = 0;
	int numberBots_ = 0;
	int maximumAllowed_ = config_.getMaximumAllowedPlayer();
	Ui::menu ui_;
};