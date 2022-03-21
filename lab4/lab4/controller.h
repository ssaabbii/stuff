#pragma once
#include "game_model.h"
#include "player_interface_model.h"

class GameController {
public:
	GameController(GameModel* model, PlayerInterfaceModel* player);
	void start();

private:
	GameModel* _gameModel;
	PlayerInterfaceModel* _player;
};