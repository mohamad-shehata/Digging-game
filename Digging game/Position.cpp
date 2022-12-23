//
// Created by MohamedShehata on 12/21/2022.
//

#include "Position.h"

Position::Position(int topRow, int leftColumn) : topRow(topRow), leftColumn(leftColumn) {}

Position::Position() {}

int Position::getTopRow() const {
	return topRow;
}

void Position::setTopRow(int topRow) {
	Position::topRow = topRow;
}

int Position::getLeftColumn() const {
	return leftColumn;
}

void Position::setLeftColumn(int leftColumn) {
	Position::leftColumn = leftColumn;
}
