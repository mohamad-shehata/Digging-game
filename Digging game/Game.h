//
// Created by MohamedShehata on 12/22/2022.
//

#ifndef DIGGING_GAME_GAME_H
#define DIGGING_GAME_GAME_H


#include "Board.h"

class Game {
private:
	int score;
	Board* board;

public:
	explicit Game(Board* board);

	void startGame();

	void endGame(bool killed) const;
};


#endif //DIGGING_GAME_GAME_H
