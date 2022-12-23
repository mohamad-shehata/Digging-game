//
// Created by MohamedShehata on 12/21/2022.
//
#include "MovablePiece.h"

#ifndef DIGGING_GAME_DIAMOND_H
#define DIGGING_GAME_DIAMOND_H

class Diamond : public MovablePiece {
public:
	Diamond();

	void draw(std::vector<std::vector<std::pair<int, char>>>& drawMatrix, Position* position) override;
};


#endif //DIGGING_GAME_DIAMOND_H
