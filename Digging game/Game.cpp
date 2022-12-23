//
// Created by MohamedShehata on 12/22/2022.
//
#include <windows.h>
#include <iostream>
#include "Game.h"
#include <thread>

Game::Game(Board* board) : board(board) {
	score = 0;
}


void Game::startGame() {
	while (true) {
		board->update(score);
		board->showBoardOnScreen();
		if (board->getCharacter()->isKilled() || board->getNumOfGifts() == 0) {
			endGame(board->getCharacter()->isKilled());
			return;
		}
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Game::endGame(bool killed) const {
	system("CLS");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (killed) {
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Sorry you was killed :(\n";
	}
	else {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "Congrats you win!!! :)\n";
	}
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "Your score is \" " << score << " \"." << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
	system("pause");
	exit(0);
}
