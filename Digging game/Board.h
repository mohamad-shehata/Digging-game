//
// Created by MohamedShehata on 12/21/2022.
//
#include <vector>
#include "Cell.h"
#include "Character.h"

#ifndef DIGGING_GAME_BOARD_H
#define DIGGING_GAME_BOARD_H


class Board {
private:
	int numOfGifts;
	Character* character;
	// first for cell color and second for char type
	std::vector<std::vector<std::pair<int, char>>> drawMatrix;
	std::vector<std::vector<Cell*>> matrix;
public:
	Board(Character* character, const std::vector<std::vector<Cell*>>& matrix);

	Character* getCharacter() const;

	int getNumOfGifts() const;

	void updateMove();

	void updateDraw();

	void update(int& score);

	void showBoardOnScreen();
};


#endif //DIGGING_GAME_BOARD_H
