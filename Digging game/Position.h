//
// Created by MohamedShehata on 12/21/2022.
//

#ifndef DIGGING_GAME_POSITION_H
#define DIGGING_GAME_POSITION_H


class Position {
private:
	int topRow, leftColumn;
public:
	Position();

	Position(int topRow, int leftColumn);

	int getTopRow() const;

	void setTopRow(int topRow);

	int getLeftColumn() const;

	void setLeftColumn(int topColumn);
};


#endif //DIGGING_GAME_POSITION_H
