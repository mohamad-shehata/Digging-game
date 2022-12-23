#include <iostream>
#include "Game.h"
#include "Sand.h"
#include "Rock.h"
#include "Diamond.h"
#include "Wall.h"
#include<windows.h>
using namespace std;

#define Empty nullptr

vector<vector<Cell*>> getLevel() {
	// number of rows must be equal to the number of columns
	return vector<vector<Cell*>>{
		{new Cell(Empty), new Cell(Empty), new Cell(Empty), new Cell(new Rock()), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Diamond())},
		{new Cell(Empty), new Cell(new Sand()), new Cell(new Wall()), new Cell(new Diamond()), new Cell(new Wall()), new Cell(new Sand()), new Cell(new Sand()), new Cell(Empty)},
		{new Cell(Empty), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Wall()), new Cell(new Sand()), new Cell(new Diamond()), new Cell(new Sand()), new Cell(Empty)},
		{new Cell(new Wall()), new Cell(new Rock()), new Cell(new Wall()), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Sand()), new Cell(Empty)},
		{new Cell(Empty), new Cell(new Sand()), new Cell(new Rock()), new Cell(new Sand()), new Cell(new Wall()), new Cell(new Sand()), new Cell(new Sand()), new Cell(Empty)},
		{new Cell(Empty), new Cell(new Wall()), new Cell(new Diamond()), new Cell(new Wall()), new Cell(new Diamond()), new Cell(new Sand()), new Cell(new Sand()), new Cell(Empty)},
		{new Cell(Empty), new Cell(new Sand()), new Cell(new Wall()), new Cell(new Diamond()), new Cell(new Wall()), new Cell(new Diamond()), new Cell(new Sand()), new Cell(Empty)},
		{new Cell(new Sand()), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Sand()), new Cell(new Sand()), new Cell(Empty)},
	};
}



int main() {
	cout << "press any Key to start" << endl;
	Character* character = new Character(7, 7);
	Game* game = new Game(new Board(character, getLevel()));
	game->startGame();
}
