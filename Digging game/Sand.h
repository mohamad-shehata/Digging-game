//
// Created by MohamedShehata on 12/21/2022.
//
#include "SolidPiece.h"

#ifndef DIGGING_GAME_SAND_H
#define DIGGING_GAME_SAND_H


class Sand : public SolidPiece {
public:
	Sand();

	void draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) override;
};


#endif //DIGGING_GAME_SAND_H
