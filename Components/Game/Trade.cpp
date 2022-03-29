#include "Trade.h"

Trade::Trade(QWidget* parent)
	: QMainWindow(parent)
{
	tradeUI_.setupUi(this);
	QIcon winIcon("images/icon.png");
	this->setWindowIcon(winIcon);
	connect(tradeUI_.buttonOK, SIGNAL(released()), this, SLOT(pushOK()));
}

void Trade::pushOK() {
	int cash1 = tradeUI_.CashLineEdit1->text().toInt();
	int cash2 = tradeUI_.CashLineEdit2->text().toInt();

	player1_->setMoney(player1_->getMoney() + cash2 - cash1);
	player2_->setMoney(player2_->getMoney() + cash1 - cash2);

	for (int i = 0; i < checkBox_.size(); i++) {
		if (checkBox_[i]->isChecked()) {
			mapMonopoly_[i]->setBought(player2_->getID());
			mapMonopoly_[i]->setPlayerBought(player2_);
		}
	}

	for (int i = 0; i < checkBox2_.size(); i++) {
		if (checkBox2_[i]->isChecked()) {
			mapMonopoly_[i]->setBought(player1_->getID());
			mapMonopoly_[i]->setPlayerBought(player1_);
		}
	}

}

void Trade::setPlayers(std::shared_ptr<IPlayer> player1, std::shared_ptr<IPlayer> player2) {
	player1_ = player1;
	player2_ = player2;

	tradeUI_.player1->setText(QString::fromStdString("Player ") + QString::number(player1_->getID()));
	tradeUI_.player2->setText(QString::fromStdString("Player ") + QString::number(player2_->getID()));

	for (int i = 0; i < checkBox_.size(); i++) {
		if (!mapMonopoly_[i]->isBusiness()) checkBox_[i]->setEnabled(false);
		else if (mapMonopoly_[i]->isBusiness() && mapMonopoly_[i]->getBought() != player1_->getID()) checkBox_[i]->setEnabled(false);
		else checkBox_[i]->setEnabled(true);
	}

	for (int i = 0; i < checkBox2_.size(); i++) {
		if (!mapMonopoly_[i]->isBusiness()) checkBox2_[i]->setEnabled(false);
		else if (mapMonopoly_[i]->isBusiness() && mapMonopoly_[i]->getBought() != player2_->getID()) checkBox2_[i]->setEnabled(false);
		else checkBox2_[i]->setEnabled(true);
	}

}

void Trade::setMap(std::vector<std::shared_ptr<Cell>> mapMonopoly) {
	mapMonopoly_ = mapMonopoly;

	for (int i = 0; i < checkBox_.size(); i++) {
		checkBox_[i]->setChecked(false);
	}

	for (int i = 0; i < checkBox2_.size(); i++) {
		checkBox2_[i]->setChecked(false);
	}
}

void Trade::setCheckBox() {
	checkBox_.push_back(tradeUI_.checkBox);
	checkBox_.push_back(tradeUI_.checkBox2);
	checkBox_.push_back(tradeUI_.checkBox3);
	checkBox_.push_back(tradeUI_.checkBox4);
	checkBox_.push_back(tradeUI_.checkBox5);
	checkBox_.push_back(tradeUI_.checkBox6);
	checkBox_.push_back(tradeUI_.checkBox7);
	checkBox_.push_back(tradeUI_.checkBox8);
	checkBox_.push_back(tradeUI_.checkBox9);
	checkBox_.push_back(tradeUI_.checkBox10);
	checkBox_.push_back(tradeUI_.checkBox11);
	checkBox_.push_back(tradeUI_.checkBox12);
	checkBox_.push_back(tradeUI_.checkBox13);
	checkBox_.push_back(tradeUI_.checkBox14);
	checkBox_.push_back(tradeUI_.checkBox15);
	checkBox_.push_back(tradeUI_.checkBox16);
	checkBox_.push_back(tradeUI_.checkBox17);
	checkBox_.push_back(tradeUI_.checkBox18);
	checkBox_.push_back(tradeUI_.checkBox19);
	checkBox_.push_back(tradeUI_.checkBox20);


	checkBox2_.push_back(tradeUI_.checkBox_3);
	checkBox2_.push_back(tradeUI_.checkBox2_3);
	checkBox2_.push_back(tradeUI_.checkBox3_3);
	checkBox2_.push_back(tradeUI_.checkBox4_3);
	checkBox2_.push_back(tradeUI_.checkBox5_3);
	checkBox2_.push_back(tradeUI_.checkBox6_3);
	checkBox2_.push_back(tradeUI_.checkBox7_3);
	checkBox2_.push_back(tradeUI_.checkBox8_3);
	checkBox2_.push_back(tradeUI_.checkBox9_3);
	checkBox2_.push_back(tradeUI_.checkBox10_3);
	checkBox2_.push_back(tradeUI_.checkBox11_3);
	checkBox2_.push_back(tradeUI_.checkBox12_3);
	checkBox2_.push_back(tradeUI_.checkBox13_3);
	checkBox2_.push_back(tradeUI_.checkBox14_3);
	checkBox2_.push_back(tradeUI_.checkBox15_3);
	checkBox2_.push_back(tradeUI_.checkBox16_3);
	checkBox2_.push_back(tradeUI_.checkBox17_3);
	checkBox2_.push_back(tradeUI_.checkBox18_3);
	checkBox2_.push_back(tradeUI_.checkBox19_3);
	checkBox2_.push_back(tradeUI_.checkBox20_3);

	for (int i = 0; i < checkBox_.size(); i++) {
		checkBox_[i]->setText(QString::fromStdString(mapMonopoly_[i]->getName()));
	}

	for (int i = 0; i < checkBox_.size(); i++) {
		checkBox2_[i]->setText(QString::fromStdString(mapMonopoly_[i]->getName()));
	}
}