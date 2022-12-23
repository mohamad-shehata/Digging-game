//
// Created by MohamedShehata on 12/21/2022.
//

#include <iostream>
#include "Character.h"
#include <conio.h>

//todo: use enum
#define KEY_UP 119 //W
#define KEY_DOWN 115 // S
#define KEY_LEFT 97 // A
#define KEY_RIGHT 100 // D

Character::Character(int currentPositionX, int currentPositionY) : currentPositionX(currentPositionX), currentPositionY(currentPositionY) {
	killed = false;
}

int Character::getCurrentPositionX() const {
	return currentPositionX;
}

void Character::setCurrentPositionX(int currentPositionX) {
	Character::currentPositionX = currentPositionX;
}

int Character::getCurrentPositionY() const {
	return currentPositionY;
}

void Character::setCurrentPositionY(int currentPositionY) {
	Character::currentPositionY = currentPositionY;
}

bool Character::isKilled() const {
	return killed;
}

void Character::setKilled(bool killed) {
	Character::killed = killed;
}

void Character::draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) {
	int startRow = position->getTopRow();
	int endRow = startRow + Piece::SIZE;
	int startCol = position->getLeftColumn();
	int endCol = startCol + Piece::SIZE;
	for (int i = startRow; i < endRow; ++i) {
		for (int j = startCol; j < endCol; ++j) {
			drawMatrix[i][j] = { 15, ' ' };
		}
	}
	drawMatrix[startRow + 1][startCol + 1] = { 15, '*' };
	drawMatrix[startRow + 1][startCol + 2] = { 15, '$' };
	drawMatrix[startRow + 1][startCol + 3] = { 15, '*' };
	drawMatrix[startRow + 2][startCol + 2] = { 15, '*' };
	drawMatrix[startRow + 3][startCol + 2] = { 15, '*' };
	drawMatrix[startRow + 4][startCol + 1] = { 15, '*' };
	drawMatrix[startRow + 4][startCol + 3] = { 15, '*' };
}

// if it returns true then the player got a gift
bool Character::move(std::vector<std::vector<Cell*>>& matrix) {
	// toDo: character move
	auto valid = [&](int x, int y) {
		return x >= 0 && x < matrix.size() && y >= 0 && y < matrix.size();
	};
	if (!valid(currentPositionX, currentPositionY)) {
		std::cerr << "the character's position is invalid" << std::endl;
		return false;
	}
	auto updateCell = [&](int x, int y, Cell* lstCell, Cell* nxtCell) {
		if (valid(x, y)) {
			auto cell = matrix[x][y];
			if (cell->getPiece() == nullptr) {
				lstCell->setPlayerExists(false);
				cell->setPlayerExists(true);
				setCurrentPositionX(x);
				setCurrentPositionY(y);
				return false;
			}
			if (!cell->getPiece()->isSand() && !cell->getPiece()->isGift()) {
				if (cell->getPiece()->isMovable()) {
					// then it is a rock
					if (nxtCell != nullptr && nxtCell->getPiece() == nullptr) {
						nxtCell->setPiece(cell->getPiece());
						cell->setPiece(nullptr);
						lstCell->setPlayerExists(false);
						cell->setPlayerExists(true);
					}
				}
				return false;
			}
			lstCell->setPlayerExists(false);
			cell->setPlayerExists(true);
			setCurrentPositionX(x);
			setCurrentPositionY(y);
			if (cell->getPiece()->isGift()) {
				cell->setPiece(nullptr);
				return true;
			}
			cell->setPiece(nullptr);
			return false;
		}
	};
	auto getNextCell = [&](int x, int y) -> Cell* {
		if (valid(x, y))
			return matrix[x][y];
		return nullptr;
	};
	int input = 0;
	switch ((input = _getch())) {
	case KEY_UP:
		return updateCell(currentPositionX - 1, currentPositionY, matrix[currentPositionX][currentPositionY], getNextCell(-1, -1)); // key up
		break;
	case KEY_DOWN:                                                                                                                                     // -1, -1 because he can't move rock upp and down
		return updateCell(currentPositionX + 1, currentPositionY, matrix[currentPositionX][currentPositionY], getNextCell(-1, -1));   // key down
		break;
	case KEY_LEFT:
		return updateCell(currentPositionX, currentPositionY - 1, matrix[currentPositionX][currentPositionY], getNextCell(currentPositionX, currentPositionY - 2));  // key left
		break;
	case KEY_RIGHT:
		return updateCell(currentPositionX, currentPositionY + 1, matrix[currentPositionX][currentPositionY], getNextCell(currentPositionX, currentPositionY + 2));  // key right
		break;
	default:
		return false;  // not arrow
		break;
	}
}

