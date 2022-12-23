//
// Created by MohamedShehata on 12/21/2022.
//

#include "SolidPiece.h"

SolidPiece::SolidPiece(bool gift, bool sand, bool movable) : gift(gift), sand(sand), movable(movable){}

bool SolidPiece::isGift() const {
	return gift;
}

bool SolidPiece::isSand() const {
	return sand;
}

bool SolidPiece::isMovable() const {
	return movable;
}
