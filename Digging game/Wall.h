//
// Created by MohamedShehata on 12/21/2022.
//
#include "SolidPiece.h"

#ifndef DIGGING_GAME_WALL_H
#define DIGGING_GAME_WALL_H


class Wall : public SolidPiece {
public:
	Wall();

	void draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) override;
};


#endif //DIGGING_GAME_WALL_H
