//
// Created by MohamedShehata on 12/21/2022.
//

#include "Rock.h"

Rock::Rock() : MovablePiece(false, false, true) {}


void Rock::draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) {
	int startRow = position->getTopRow();
	int endRow = startRow + Piece::SIZE;
	int startCol = position->getLeftColumn();
	int endCol = startCol + Piece::SIZE;
	for (int i = startRow; i < endRow; ++i) {
		for (int j = startCol; j < endCol; ++j) {
			drawMatrix[i][j] = {8, '+' };
		}
	}
	for (int i = startRow + 1; i < endRow - 1; ++i) {
		for (int j = startCol + 1; j < endCol - 1; ++j) {
			drawMatrix[i][j] = {15, ' ' };
		}
	}
}
