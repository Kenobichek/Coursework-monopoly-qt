#pragma once
#include <string>

#include "Cell.h"

#include "../../lib/json.hpp"

class Business : public Cell {
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
    int cost_ = 0;
    int business_ = -1;
    int tax_ = 0;
    int combinedBusiness_ = -1;
    std::shared_ptr<IPlayer> isBought_;
    int bought_ = -1;
    double taxCoefficient = 0.3;
};