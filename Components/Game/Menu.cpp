#include "Menu.h"

Menu::Menu(QWidget* parent)
	: QMainWindow(parent)
{
	ui_.setupUi(this);
	QIcon winIcon("images/icon.png");
	this->setWindowIcon(winIcon);
	this->setStyleSheet("background-image: url(images/background_menu.jpg);");
	connect(ui_.playerSpinBox, SIGNAL(valueChanged(int)), this, SLOT(pushPlayerSpinBox()));
	connect(ui_.botSpinBox, SIGNAL(valueChanged(int)), this, SLOT(pushBotSpinBox()));
	connect(ui_.pushButtonPlay, SIGNAL(released()), this, SLOT(play()));
}

void Menu::pushPlayerSpinBox() {
	numberPlayers_ = ui_.playerSpinBox->value();
	ui_.botSpinBox->setMaximum(maximumAllowed_ - numberPlayers_);
}

void Menu::pushBotSpinBox() {
	numberBots_ = ui_.botSpinBox->value();
	ui_.playerSpinBox->setMaximum(maximumAllowed_ - numberBots_);
}

int Menu::getNumberPlayers() {
	return numberPlayers_;
}

int Menu::getNumberBots() {
	return numberBots_;
}

int Menu::getMaximumAllowed() {
	return maximumAllowed_;
}

int Menu::getTotal() {
	return numberPlayers_ + numberBots_;
}

void Menu::play() {
	game_.startGame(numberPlayers_, numberBots_);
	game_.show();
	//game_.updateGame();
	this->close();
}