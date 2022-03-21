#pragma once
#include "game_model.h"

class Game {
public:
	enum class GameMode {
		HUMAN,
		BOT
	};

	void run();

private:
	GameMode _gameMode;
	void setGameMode();
};
