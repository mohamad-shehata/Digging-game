//
// Created by MohamedShehata on 12/21/2022.
//
#include "Piece.h"

#ifndef DIGGING_GAME_SOLIDPIECE_H
#define DIGGING_GAME_SOLIDPIECE_H


class SolidPiece : public Piece {
private:
	bool gift, sand, movable;
public:
	SolidPiece(bool gift, bool sand, bool movable);

	bool isMovable() const;

	bool isGift() const;

	bool isSand() const;
};


#endif //DIGGING_GAME_SOLIDPIECE_H
