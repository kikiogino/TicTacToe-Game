#pragma once

#include "Pieces.h"
#include <vector>
#include <iostream>

 

class TicTacToe {
private:
	int height; 
	int width; 
	char pieceType;
	char currentPlayer;
	char winningPlayer;
	std::vector<std::pair<int, int>> moves_x;
	std::vector<std::pair<int, int>> moves_o;
	int movesLeft;
public:
	TicTacToe();
	mutable std::vector<Pieces> pieces;
	int index(int x, int y);
	bool done();
	bool draw();
	int prompt(unsigned int & x_coordinate, unsigned int & y_coordinate);
	int turn();
	int play();
	
friend std::ostream & operator <<(std::ostream & output, const TicTacToe & gameBoard);
};


