//
// Created by MohamedShehata on 12/21/2022.
//
#include "Piece.h"
#include "Cell.h"

#ifndef DIGGING_GAME_CHARACTER_H
#define DIGGING_GAME_CHARACTER_H


class Character : public Piece {
private:
	bool killed;
	int currentPositionX, currentPositionY;
public:
	explicit Character(int currentPositionX, int currentPositionY);

	int getCurrentPositionX() const;

	void setCurrentPositionX(int currentPositionX);

	int getCurrentPositionY() const;

	void setCurrentPositionY(int currentPositionY);

	bool isKilled() const;

	void setKilled(bool killed);

	void draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) override;

	bool move(std::vector<std::vector<Cell*>>& matrix);
};


#endif //DIGGING_GAME_CHARACTER_H
