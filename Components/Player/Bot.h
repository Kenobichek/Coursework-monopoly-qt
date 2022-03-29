#pragma once
#include "IPlayer.h"

class Bot : public IPlayer {
public:
	Bot(int id) : IPlayer(id) {}
	bool isBot();
	bool buyCell(int cost);
	bool taxCell(int tax, std::shared_ptr<IPlayer> iplayer);
};