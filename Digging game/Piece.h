//
// Created by MohamedShehata on 12/21/2022.
//
#include "Position.h"
#include <vector>

#ifndef DIGGING_GAME_PIECE_H
#define DIGGING_GAME_PIECE_H


class Piece {
private:
public:
	static const int SIZE = 5;
	virtual void draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) = 0;
};


#endif //DIGGING_GAME_PIECE_H
