//
// Created by MohamedShehata on 12/21/2022.
//
#include "SolidPiece.h"
#include "Board.h"
#include "Cell.h"

#ifndef DIGGING_GAME_MOVABLEPIECE_H
#define DIGGING_GAME_MOVABLEPIECE_H


class MovablePiece : public SolidPiece {
private:
	bool falling;
public:
	MovablePiece(bool gift, bool sand, bool movable);

	bool isFalling() const;

	void setFalling(bool falling);

	virtual bool moveDown(std::vector<std::vector<Cell*>>& matrix, int posX, int posY);
};


#endif //DIGGING_GAME_MOVABLEPIECE_H
