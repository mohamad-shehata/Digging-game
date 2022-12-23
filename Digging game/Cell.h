//
// Created by MohamedShehata on 12/21/2022.
//
#include "Position.h"
#include "SolidPiece.h"
#ifndef DIGGING_GAME_CELL_H
#define DIGGING_GAME_CELL_H


class Cell {
private:
	bool playerExists;
	Position* position;
	SolidPiece* piece;
public:
	Cell(SolidPiece* piece);

	Position* getPosition() const;

	void setPosition(Position* position);

	SolidPiece* getPiece() const;

	void setPiece(SolidPiece* piece);

	bool isPlayerExists() const;

	void setPlayerExists(bool playerExists);
};


#endif //DIGGING_GAME_CELL_H
