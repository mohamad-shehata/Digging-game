//
// Created by MohamedShehata on 12/21/2022.
//

#include "Wall.h"

Wall::Wall() : SolidPiece(false, false, false) {}

void Wall::draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) {
	int startRow = position->getTopRow();
	int endRow = startRow + Piece::SIZE;
	int startCol = position->getLeftColumn();
	int endCol = startCol + Piece::SIZE;
	for (int i = startRow; i < endRow; ++i) {
		for (int j = startCol; j < endCol; ++j) {
			drawMatrix[i][j] = {4, '#'};
		}
	}
}