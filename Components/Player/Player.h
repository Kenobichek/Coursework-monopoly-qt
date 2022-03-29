#pragma once
#include "IPlayer.h"

class Player : public IPlayer {
public:
	Player(int id) : IPlayer(id) {}
	bool isBot();
	bool buyCell(int cost);
	bool taxCell(int tax, std::shared_ptr<IPlayer> iplayer);
};