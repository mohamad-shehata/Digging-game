//
// Created by MohamedShehata on 12/21/2022.
//

#include "Diamond.h"

Diamond::Diamond() : MovablePiece(true, false, true) {}

void Diamond::draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) {
	int startRow = position->getTopRow();
	int endRow = startRow + Piece::SIZE;
	int startCol = position->getLeftColumn();
	int endCol = startCol + Piece::SIZE;
	for (int i = startRow; i < endRow; ++i) {
		for (int j = startCol; j < endCol; ++j) {
			drawMatrix[i][j] = { 15, ' ' };
		}
	}

	for (int i = startCol; i < endCol; ++i) {
		drawMatrix[startRow + 2][i] = { 9, '=' };
	}

	for (int i = startCol + 1; i < endCol - 1; ++i) {
		drawMatrix[startRow + 3][i] = { 11, '*' };
	}
	drawMatrix[startRow + 4][startCol + 2] = { 11, '*' };
}
