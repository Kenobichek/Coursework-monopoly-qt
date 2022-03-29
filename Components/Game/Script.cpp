#include "Script.h"

Script::Script(QWidget* parent)
	: QMainWindow(parent)
{
	ui_.setupUi(this);
	QIcon winIcon("images/icon.png");
	this->setWindowIcon(winIcon);
	ui_.tmpMap->setPixmap(QString::fromStdString("images/icon.png"));
	ui_.buttonAction->setText("START THE GAME!!!");
	connect(ui_.buttonAction, SIGNAL(released()), this, SLOT(startGame()));
	connect(ui_.buttonBuy, SIGNAL(released()), this, SLOT(playerBuy()));
	connect(ui_.buttonTax, SIGNAL(released()), this, SLOT(playerTax()));
	connect(ui_.buttonSkip, SIGNAL(released()), this, SLOT(skip()));
	connect(ui_.horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(slider()));
	connect(ui_.buttonMinus, SIGNAL(released()), this, SLOT(pushMinus()));
	connect(ui_.buttonPlus, SIGNAL(released()), this, SLOT(pushPlus()));
	connect(ui_.buttonTrade, SIGNAL(released()), this, SLOT(trade()));
	connect(ui_.player1, SIGNAL(released()), this, SLOT(pushPlayer1()));
	connect(ui_.player2, SIGNAL(released()), this, SLOT(pushPlayer2()));
	connect(ui_.player3, SIGNAL(released()), this, SLOT(pushPlayer3()));
	connect(ui_.player4, SIGNAL(released()), this, SLOT(pushPlayer4()));

}

void Script::setMap() {
	map_.push_back(ui_.map0);
	map_.push_back(ui_.map1);
	map_.push_back(ui_.map2);
	map_.push_back(ui_.map3);
	map_.push_back(ui_.map4);
	map_.push_back(ui_.map5);
	map_.push_back(ui_.map6);
	map_.push_back(ui_.map7);
	map_.push_back(ui_.map8);
	map_.push_back(ui_.map9);
	map_.push_back(ui_.map10);
	map_.push_back(ui_.map11);
	map_.push_back(ui_.map12);
	map_.push_back(ui_.map13);
	map_.push_back(ui_.map14);
	map_.push_back(ui_.map15);
	map_.push_back(ui_.map16);
	map_.push_back(ui_.map17);
	map_.push_back(ui_.map18);
	map_.push_back(ui_.map19);

}

void Script::setCost() {
	cost_.push_back(ui_.cost0);
	cost_.push_back(ui_.cost1);
	cost_.push_back(ui_.cost2);
	cost_.push_back(ui_.cost3);
	cost_.push_back(ui_.cost4);
	cost_.push_back(ui_.cost5);
	cost_.push_back(ui_.cost6);
	cost_.push_back(ui_.cost7);
	cost_.push_back(ui_.cost8);
	cost_.push_back(ui_.cost9);
	cost_.push_back(ui_.cost10);
	cost_.push_back(ui_.cost11);
	cost_.push_back(ui_.cost12);
	cost_.push_back(ui_.cost13);
	cost_.push_back(ui_.cost14);
	cost_.push_back(ui_.cost15);
	cost_.push_back(ui_.cost16);
	cost_.push_back(ui_.cost17);
	cost_.push_back(ui_.cost18);
	cost_.push_back(ui_.cost19);

	for (int i = 0; i < 20; i++) {
		if (mapMonopoly_[i]->isBusiness()) { cost_[i]->setText(QString::number(mapMonopoly_[i]->getCost())); cost_[i]->setFrameStyle(QFrame::Box); }
	}
}

void Script::setPlayers() {
	playersLabel_.push_back(ui_.player1);
	playersLabel_.push_back(ui_.player2);
	playersLabel_.push_back(ui_.player3);
	playersLabel_.push_back(ui_.player4);

	for (int i = 0; i < 4; i++) {
		playersLabel_[i]->setStyleSheet("background-color: " + colors_[i] + ";"); 
		playersLabel_[i]->setEnabled(true);
	}
}

void Script::setScriptPlayer(std::vector<std::shared_ptr<IPlayer>> players) {
	players_ = players;
}

void Script::setScriptMap(std::vector<std::shared_ptr<Cell>> map) {
	mapMonopoly_ = map;
}

void Script::setScriptBusiness(std::vector<std::vector<std::shared_ptr<Cell>>> business) {
	business_ = business;
}

void Script::startGame() {
	ui_.textBrowser->insertPlainText("> Welcome to the best monopoly\n");
	ui_.textBrowser->setTextColor(QColor(colors_[activePlayer_]));
	ui_.idMap->setEnabled(true);
	ui_.horizontalSlider->setEnabled(true);
	int notPlayers = 4 - players_.size();
	int id = 3;
	while (notPlayers != 0) {
		playersLabel_[id]->setEnabled(false);
		playersLabel_[id]->setStyleSheet("background-color: #c8c8c8;");
		id--;
		notPlayers--;
	}
	numberPlayers_ = players_.size();
	if (numberPlayers_ <= 1) gameOver();
	else {
		disconnect(ui_.buttonAction, SIGNAL(released()), this, SLOT(startGame()));
		playerTurn();
	}
}


void Script::playerTurn() {
	infoPlayer();
	ui_.buttonAction->setText("ROLL DICE");
	ui_.tmpMap->setPixmap(QPixmap(QString::fromStdString(mapMonopoly_[players_[activePlayer_]->getPosition()]->getImage())));
	changeSlider();
	connect(ui_.buttonAction, SIGNAL(released()), this, SLOT(rollDice()));
	disconnect(ui_.buttonAction, SIGNAL(released()), this, SLOT(playerTurn()));
	enableField();
}

void Script::rollDice() {
	disableField();
	ui_.textBrowser->insertPlainText("> The player rolled the die and the die came up with a " + QString::number(players_[activePlayer_]->rollDices()) + ".\n");
	ui_.textBrowser->insertPlainText("> Player position is now " + QString::fromStdString(mapMonopoly_[players_[activePlayer_]->getPosition()]->getName()) + ".\n");
	ui_.tmpMap->setPixmap(QPixmap(QString::fromStdString(mapMonopoly_[players_[activePlayer_]->getPosition()]->getImage())));
	changeSlider();
	enableField();
	fieldAction();
	ui_.buttonAction->setText("NEXT PLAYER");
	connect(ui_.buttonAction, SIGNAL(released()), this, SLOT(nextPlayer()));
	disconnect(ui_.buttonAction, SIGNAL(released()), this, SLOT(rollDice()));
}

void Script::nextPlayer() {
	disableField();
	ui_.buttonTrade->setEnabled(false);
	activePlayer_++;
	activePlayer_ %= players_.size();
	if (!players_[activePlayer_]->getInGame()) nextPlayer();
	ui_.textBrowser->setTextColor(QColor(colors_[activePlayer_]));
	connect(ui_.buttonAction, SIGNAL(released()), this, SLOT(rollDice()));
	disconnect(ui_.buttonAction, SIGNAL(released()), this, SLOT(nextPlayer()));
	playerTurn();
}

void Script::infoPlayer() {
	ui_.textBrowser->insertPlainText("> PLAYER INFORMATION\n  id: " + QString::number(players_[activePlayer_]->getID())
		+ "\n  money: " + QString::number(players_[activePlayer_]->getMoney())
		+ "\n  position: " + QString::fromStdString(mapMonopoly_[players_[activePlayer_]->getPosition()]->getName()) + "\n");
}

void Script::enableField() {
	mapMonopoly_[players_[activePlayer_]->getPosition()]->getMap()->setFrameStyle(QFrame::Panel | QFrame::Plain);
	mapMonopoly_[players_[activePlayer_]->getPosition()]->getMap()->setStyleSheet("QLabel {"
		"border-style: solid;"
		"border-width: 6px;"
		"border-color: " + colors_[activePlayer_] + "; "
		"}");
}

void Script::disableField() {
	mapMonopoly_[players_[activePlayer_]->getPosition()]->getMap()->setStyleSheet("QLabel {"
		"}");
	mapMonopoly_[players_[activePlayer_]->getPosition()]->getMap()->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	mapMonopoly_[players_[activePlayer_]->getPosition()]->getMap()->setLineWidth(6);
}

void Script::fieldAction() {
	if (mapMonopoly_[players_[activePlayer_]->getPosition()]->isBusiness()) { // business
		if (mapMonopoly_[players_[activePlayer_]->getPosition()]->getBought() == -1) {
			buyField();
		}
		else {
			if (mapMonopoly_[players_[activePlayer_]->getPosition()]->getBought() != players_[activePlayer_]->getID()) {
				taxField();
			}
			else {
				ui_.textBrowser->insertPlainText("> The player goes to his field\n");
			}
		}
	}
	else {
		if (mapMonopoly_[players_[activePlayer_]->getPosition()]->isQuestion()) { // question
			mapMonopoly_[players_[activePlayer_]->getPosition()]->action(ui_.textBrowser, players_[activePlayer_]);
		}
		else {
			// portal
		}
	}
}

void Script::buyField() {
	if (players_[activePlayer_]->isBot()) {
		ui_.buttonBuy->setEnabled(true);
		ui_.buttonSkip->setEnabled(true);
		ui_.buttonAction->setEnabled(false);
	}
	else {
		playerBuy();
	}
}

void Script::taxField() {
	if (players_[activePlayer_]->isBot()) {
		ui_.buttonTax->setEnabled(true);
		ui_.buttonAction->setEnabled(false);
	}
	else {
		playerTax();
	}
}

void Script::skip() {
	ui_.buttonBuy->setEnabled(false);
	ui_.buttonSkip->setEnabled(false);
	ui_.buttonAction->setEnabled(true);
}

void Script::playerBuy() {
	if (players_[activePlayer_]->buyCell(mapMonopoly_[players_[activePlayer_]->getPosition()]->getCost())) {
		mapMonopoly_[players_[activePlayer_]->getPosition()]->buyCell(players_[activePlayer_]);
		ui_.textBrowser->insertPlainText("> The player bought the field\n");
		cost_[players_[activePlayer_]->getPosition()]->setStyleSheet("background-color: " + colors_[activePlayer_] + ";");
		cost_[players_[activePlayer_]->getPosition()]->setText(QString::number(mapMonopoly_[players_[activePlayer_]->getPosition()]->getTax()));
	}
	else {
		ui_.textBrowser->insertPlainText("> The player does not have enough money to buy a field\n");
	}
	ui_.buttonBuy->setEnabled(false);
	ui_.buttonSkip->setEnabled(false);
	ui_.buttonAction->setEnabled(true);
}

void Script::playerTax() {
	if (players_[activePlayer_]->taxCell(mapMonopoly_[players_[activePlayer_]->getPosition()]->getTax(), mapMonopoly_[players_[activePlayer_]->getPosition()]->getPlayerBought())) {
		ui_.textBrowser->insertPlainText("> The player paid the tax for the field\n");
		ui_.buttonTax->setEnabled(false);
		ui_.buttonAction->setEnabled(true);
	}
	else {
		ui_.textBrowser->insertPlainText("> The player left the game\n");
		playerLost();
	}
}

void Script::playerLost() {
	players_[activePlayer_]->setInGame(false);
	numberPlayers_--;
	for (int i = 0; i < mapMonopoly_.size(); i++) {
		if (mapMonopoly_[i]->isBusiness() && mapMonopoly_[i]->getBought() == players_[activePlayer_]->getID()) {
			cost_[i]->setStyleSheet("background-color: #fff;");
			mapMonopoly_[i]->setTax(0);
			cost_[i]->setText(QString::number(mapMonopoly_[i]->getCost()));
			mapMonopoly_[i]->setBought(-1);
		}
	}
	playersLabel_[players_[activePlayer_]->getID()]->setEnabled(false);
	playersLabel_[players_[activePlayer_]->getID()]->setStyleSheet("background-color: #c8c8c8;");

	if (numberPlayers_ <= 1) gameOver();
}

void Script::gameOver() {
	ui_.textBrowser->insertPlainText("> Game Over\n");
	ui_.buttonBuy->setEnabled(false);
	ui_.buttonTax->setEnabled(false);
	ui_.buttonAction->setEnabled(false);
}

void Script::slider() {
	ui_.idMap->setText(QString::number(ui_.horizontalSlider->value()));
	ui_.tmpMap->setPixmap(QString::fromStdString(mapMonopoly_[ui_.horizontalSlider->value()]->getImage()));
	if (mapMonopoly_[ui_.horizontalSlider->value()]->isBusiness() && checkFullBusiness()) {
		ui_.buttonPlus->setEnabled(true);
		ui_.buttonMinus->setEnabled(true);
	}
	else {
		ui_.buttonPlus->setEnabled(false);
		ui_.buttonMinus->setEnabled(false);
	}
	ui_.buttonBuy->setEnabled(false);
	ui_.buttonTax->setEnabled(false);
	if (ui_.horizontalSlider->value() == players_[activePlayer_]->getPosition()) {
		if (!ui_.buttonAction->isEnabled()) {
			fieldAction();
		}
	}
}

void Script::changeSlider() {
	ui_.idMap->setText(QString::number(players_[activePlayer_]->getPosition()));
	ui_.horizontalSlider->setValue(players_[activePlayer_]->getPosition());
}

bool Script::checkFullBusiness() {
	int numberBusiness = mapMonopoly_[ui_.horizontalSlider->value()]->getNumberBusiness();
	for (int i = 0; i < business_[numberBusiness - 1].size(); i++) {
		if (business_[numberBusiness - 1][i]->getBought() != players_[activePlayer_]->getID()) {
			return false;
		}
	}
	return true;
}

void Script::pushMinus() {
	if (mapMonopoly_[ui_.horizontalSlider->value()]->disimproveCell(players_[activePlayer_])) {
		ui_.textBrowser->insertPlainText("> The field has deteriorated, now money = " + QString::number(players_[activePlayer_]->getMoney()) + "\n");
		cost_[ui_.horizontalSlider->value()]->setText(QString::number(mapMonopoly_[ui_.horizontalSlider->value()]->getTax()));
	}
	else {
		ui_.textBrowser->insertPlainText("> The field has not deteriorated\n");
	}
}

void Script::pushPlus() {
	if (mapMonopoly_[ui_.horizontalSlider->value()]->improveCell(players_[activePlayer_])) {
		ui_.textBrowser->insertPlainText("> Field improved, now money = " + QString::number(players_[activePlayer_]->getMoney()) + "\n");
		cost_[ui_.horizontalSlider->value()]->setText(QString::number(mapMonopoly_[ui_.horizontalSlider->value()]->getTax()));
	}
	else {
		ui_.textBrowser->insertPlainText("> Field not improved\n");
	}
}

void Script::trade() {
	ui_.buttonTrade->setEnabled(false);
	trade_.show();
	ui_.buttonAction->setText(ui_.buttonAction->text() + QString::fromStdString(" + UPDATE MAP"));
	connect(ui_.buttonAction, SIGNAL(released()), this, SLOT(updateMap()));
}

void Script::pushPlayer1() {
	if (activePlayer_ != 0 && players_[0]->getInGame()) {
		trade_.setMap(mapMonopoly_);
		trade_.setPlayers(players_[activePlayer_], players_[0]);
		ui_.buttonTrade->setEnabled(true);
	}
}

void Script::pushPlayer2() {
	if (activePlayer_ != 1 && players_[1]->getInGame()) {
		trade_.setMap(mapMonopoly_);
		trade_.setPlayers(players_[activePlayer_], players_[1]);
		ui_.buttonTrade->setEnabled(true);
	}
}

void Script::pushPlayer3() {
	if (activePlayer_ != 2 && players_[2]->getInGame()) {
		trade_.setMap(mapMonopoly_);
		trade_.setPlayers(players_[activePlayer_], players_[2]);
		ui_.buttonTrade->setEnabled(true);
	}
}

void Script::pushPlayer4() {
	if (activePlayer_ != 3 && players_[3]->getInGame()) {
		trade_.setMap(mapMonopoly_);
		trade_.setPlayers(players_[activePlayer_], players_[3]);
		ui_.buttonTrade->setEnabled(true);
	}
}

void Script::updateMap() {
	disconnect(ui_.buttonAction, SIGNAL(released()), this, SLOT(updateMap()));
	for (int i = 0; i < mapMonopoly_.size(); i++) {
		if (mapMonopoly_[i]->isBusiness() && mapMonopoly_[i]->getBought() != -1) {
			cost_[i]->setStyleSheet("background-color: " + colors_[mapMonopoly_[i]->getBought()] + ";");
		}
	}
}