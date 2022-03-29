#include "Monopoly.h"

void Monopoly::startGame(int player, int bot) {

    numberPlayers_ = player;
    numberBots_ = bot;

    setMap();
    setFieldData();
    setNumberPlayers();

    setScriptPlayer(players_);
    setScriptMap(mapMonopoly_);
    setScriptBusiness(business_);
    setCost();
    setPlayers();

    trade_.setMap(mapMonopoly_);
    trade_.setCheckBox();
}

std::vector<std::shared_ptr<Cell>> Monopoly::setFieldData() {
    std::unordered_map<std::string, std::shared_ptr<CellFactory>> map{
        make_pair("Portal", std::make_shared<PortalFactory>()),
        make_pair("Business", std::make_shared<BusinessFactory>()),
        make_pair("Question", std::make_shared<QuestionFactory>())
    };

    std::ifstream fin(path);
    json data = json::parse(fin);
    fin.close();

    for (json& fieldData : data) {
        std::shared_ptr<Cell> tmp = map[fieldData.at("class")]->createField();
        tmp->setMap(map_[mapMonopoly_.size()]);
        tmp->deserialize(fieldData.at("properties"));
        mapMonopoly_.push_back(tmp);
        if (mapMonopoly_[mapMonopoly_.size() - 1]->isBusiness()) {
            int thisBusiness = mapMonopoly_[mapMonopoly_.size() - 1]->getNumberBusiness() - 1;
            business_[thisBusiness].push_back(tmp);
        }
    }
    return mapMonopoly_;
}

std::vector<std::shared_ptr<IPlayer>> Monopoly::setNumberPlayers() {
    int idIPlayer = 0;

    for (int i = 0; i < numberBots_; i++) {
        players_.push_back(std::make_unique<Bot>(idIPlayer++));
    }
    
    for (int i = 0; i < numberPlayers_; i++) {
        players_.push_back(std::make_unique<Player>(idIPlayer++));
    }

    return players_;
}
