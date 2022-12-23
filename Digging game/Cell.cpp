//
// Created by MohamedShehata on 12/21/2022.
//

#include "Cell.h"

Cell::Cell(SolidPiece* piece) : piece(piece) {
	position = nullptr;
}

Position* Cell::getPosition() const {
	return position;
}

void Cell::setPosition(Position* position) {
	Cell::position = position;
}

SolidPiece* Cell::getPiece() const {
	return piece;
}

void Cell::setPiece(SolidPiece* piece) {
	Cell::piece = piece;
}

void Cell::setPlayerExists(bool playerExists) {
	this->playerExists = playerExists;
}

bool Cell::isPlayerExists() const {
	return playerExists;
}
