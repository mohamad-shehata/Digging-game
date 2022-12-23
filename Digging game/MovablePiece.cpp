#include <iostream>
#include "SolidPiece.h"
#include "MovablePiece.h"

//
// Created by MohamedShehata on 12/22/2022.
//
MovablePiece::MovablePiece(bool gift, bool sand, bool movable) : SolidPiece(gift, sand, movable) {
	falling = false;
}

bool MovablePiece::isFalling() const {
	return falling;
}

void MovablePiece::setFalling(bool falling) {
	MovablePiece::falling = falling;
}

// if the function return "true" that means the player is killed
bool MovablePiece::moveDown(std::vector<std::vector<Cell*>>& matrix, int posX, int posY) {
	auto valid = [&](int x, int y) {
		return x >= 0 && x < matrix.size() && y >= 0 && y < matrix.size();
	};
	if (!valid(posX, posY)) {
		std::cerr << "the diamond's position is invalid" << std::endl;
		return false;
	}
	auto cell = matrix[posX][posY];
	if (posX + 1 < matrix.size()) {
		// if the bottom cells is empty move to it
		if (matrix[posX + 1][posY]->getPiece() == nullptr) {
			if (matrix[posX + 1][posY]->isPlayerExists()) {
				if (isFalling()) {
					// the player is killed
					return true;
				}
				else {
					return false;
				}
			}
			setFalling(true);
			matrix[posX + 1][posY]->setPiece(cell->getPiece());
			cell->setPiece(nullptr);
			return false;
		}
	}
	// if the right and the bottom right cells are empty move to the bottom right cell
	if (valid(posX + 1, posY + 1) && matrix[posX][posY + 1]->getPiece() == nullptr && !matrix[posX][posY + 1]->isPlayerExists() && matrix[posX + 1][posY + 1]->getPiece() == nullptr && !matrix[posX + 1][posY + 1]->isPlayerExists()) {
		matrix[posX + 1][posY + 1]->setPiece(cell->getPiece());
		cell->setPiece(nullptr);
		setFalling(true);
		return false;
	}
	// if the left and the bottom left cells are empty move to the bottom left cell
	if (valid(posX + 1, posY - 1) && matrix[posX][posY - 1]->getPiece() == nullptr && !matrix[posX][posY - 1]->isPlayerExists() && matrix[posX + 1][posY - 1]->getPiece() == nullptr && !matrix[posX + 1][posY - 1]->isPlayerExists()) {
		matrix[posX + 1][posY - 1]->setPiece(cell->getPiece());
		cell->setPiece(nullptr);
		setFalling(true);
		return false;
	}
	setFalling(false);
	return false;
}
