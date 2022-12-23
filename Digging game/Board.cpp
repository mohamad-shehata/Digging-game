//
// Created by MohamedShehata on 12/21/2022.
//

#include <windows.h>
#include <iostream>
#include "Board.h"
#include "MovablePiece.h"

Board::Board(Character* character, const std::vector<std::vector<Cell*>>& matrix) : matrix(matrix), character(character) {
	this->drawMatrix = std::vector<std::vector<std::pair<int, char>>>(matrix.size() * Piece::SIZE, std::vector<std::pair<int, char>>(matrix.size() * Piece::SIZE));
	matrix[character->getCurrentPositionX()][character->getCurrentPositionY()]->setPlayerExists(true);
	matrix[character->getCurrentPositionX()][character->getCurrentPositionY()]->setPiece(nullptr);
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix.size(); ++j) {
			matrix[i][j]->setPosition(new Position(i * Piece::SIZE, j * Piece::SIZE));
		}
	}
}

Character* Board::getCharacter() const {
	return character;
}

int Board::getNumOfGifts() const {
	return numOfGifts;
}

void Board::updateMove() {
	numOfGifts = 0;
	// must start first loop from bottom to top to make a valid falling
	for (int i = int(matrix.size()) - 1; i >= 0; --i) {
		for (int j = 0; j < matrix.size(); ++j) {
			if (matrix[i][j]->getPiece() != nullptr) {
				if (matrix[i][j]->getPiece()->isGift())
					++numOfGifts;
				if (matrix[i][j]->getPiece()->isMovable()) {
					try {
						// if true then the player was killed
						if (dynamic_cast<MovablePiece*>(matrix[i][j]->getPiece())->moveDown(matrix, i, j)) {
							character->setKilled(true);
						}
					}
					catch (...) {
						std::cerr << "Error occurred.\n you try to move unmovable Piece";
						exit(0);
					}
				}
			}
		}
	}
}

void Board::updateDraw() {
	this->drawMatrix = std::vector<std::vector<std::pair<int, char>>>(matrix.size() * Piece::SIZE, std::vector<std::pair<int, char>>(matrix.size() * Piece::SIZE, { 15, ' ' }));
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix.size(); ++j) {
			if (matrix[i][j]->getPiece() != nullptr) {
				matrix[i][j]->getPiece()->draw(drawMatrix, matrix[i][j]->getPosition());
			}
		}
	}
}

void Board::update(int& score) {
	score += character->move(matrix);
	updateMove();
	updateDraw();
	character->draw(drawMatrix, matrix[character->getCurrentPositionX()][character->getCurrentPositionY()]->getPosition());
}

void Board::showBoardOnScreen() {
	system("CLS");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < drawMatrix.size(); ++i) {
		for (int j = 0; j < drawMatrix.size(); ++j) {
			SetConsoleTextAttribute(hConsole, drawMatrix[i][j].first);
			std::cout << drawMatrix[i][j].second;
		}
		std::cout << '\n';
	}
	SetConsoleTextAttribute(hConsole, 15);
	std::cout.flush();
}
