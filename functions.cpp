#include "Tic-Tac-Toe.h"
#include "Pieces.h"
#include "General.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include<sstream>
#include <string>

using namespace std;

int TicTacToe::index(int x, int y) {
	int i = 5*y + x;
	return i;
}

//check if there are diagonally, horizontally, or vertically 3 Xs or Os in a row
bool TicTacToe::done() {
	bool isDone = false;
	//vertical check:
	for (int index = 16; index <=18; index++) {
		char p1 = TicTacToe::pieces[index].pieceType;
		char p2 = TicTacToe::pieces[index - 5].pieceType;
		char p3 = TicTacToe::pieces[index - 10].pieceType;
		if ((p1 != ' ') && (p2 != ' ') &&( p3 != ' ')) {
			if (p1 == p2 && p2 == p3) {
				isDone = true;
				if (p1 == 'X') {
					winningPlayer = 'X';
				}
				else {
					winningPlayer = 'O';
				}
				return isDone;
			}
		}
	}
	//horizontal check
	for (int index = 6; index < 17; index+=5) {
		char p1 = TicTacToe::pieces[index].pieceType;
		char p2 = TicTacToe::pieces[index + 1].pieceType;
		char p3 = TicTacToe::pieces[index + 2].pieceType;
		if (p1 != ' ' && p2 != ' ' && p3 != ' ') {
			if (p1 == p2 && p2 == p3) {
				isDone = true;
				if (p1 == 'X') {
					winningPlayer = 'X';
				}
				else {
					winningPlayer = 'O';
				}
				return isDone;
			}
		}
	}

	//diagnoal check
	int topLeft = 16;
	int mid = 12;
	int bottomLeft = 6;
	int topRight = 18;
	int bottomRight = 8;

	char L1 = TicTacToe::pieces[topLeft].pieceType;
	char L2 = TicTacToe::pieces[bottomLeft].pieceType;
	char M = TicTacToe::pieces[mid].pieceType;
	char R1 = TicTacToe::pieces[topRight].pieceType;
	char R2 = TicTacToe::pieces[bottomRight].pieceType;
	//left diagonal check:
	if (L1 == R2 && R2 == M && M != ' ') {
		isDone = true;
		if (L2 == 'X') {
			winningPlayer = 'X';
		}
		else {
			winningPlayer = 'O';
		}
	}
	//right diagonal check:
	if (R1 == L2 && L2 == M && M!= ' ') {
		isDone = true;
		if (L2 == 'X') {
			winningPlayer = 'X';
		}
		else {
			winningPlayer = 'O';
		}
	}

	return isDone;
	
}

bool TicTacToe::draw() {
	if (done()) {
		return false;
	}
	else if (movesLeft != 0) {
		return false;
	}
	else {
		return true;
	}

}

int TicTacToe::prompt(unsigned int& x_coordinate, unsigned int& y_coordinate) {
	cout << *this << endl;
	cout << "Options:" << endl;
	cout<< "1.  enter move (ie 2, 3) " << endl;
	cout << "2.  'quit' to stop playing" << endl;
	cout << endl;

	string input;
	cin >> input;
	if (input.length() < 3 || input.length() > 4) {
		cout << "Not a valid input, please try again" << endl;
		unsigned int redo = 5;
		prompt(redo, redo);
		return InvalidInput;
	}
	if (input == "quit") {
		movesLeft = 0;
		cout << "User quit game" << endl;
	}
	else if (input.at(1) != ',' ) {
		cout << "Not a valid input, please try again." << endl;
		unsigned int redo = 5;
		prompt(redo, redo);
		return InvalidInput;
	}
	else {
		char x = input.at(0);
		char y = input.at(2);
		stringstream xc;
		xc << x;
		unsigned int x_coord;
		xc >> x_coord;
		stringstream yc;
		yc << y;
		unsigned int y_coord;
		yc >> y_coord;

		
			if (x_coord < 1 || x_coord >3 || y_coord < 1 || y_coord >3) {
				cout << "Invalid coordinates, please try again (ie 1,1)." << endl;
				unsigned int redo = 5;
				prompt(redo, redo);
				return InvalidInput;
			}
			else {
				int i = index(x_coord, y_coord); // create new index for piece
				
					if (TicTacToe::pieces[i].pieceType == ' ') {
						movesLeft--;
						Pieces p;
						p.x = x_coord;
						p.y = y_coord;
						if (TicTacToe::currentPlayer == 'X') {
							p.pieceType = 'X';
							pieces.push_back(p);
							TicTacToe::pieces[i].pieceType = 'X';
							TicTacToe::pieces[i].x = x_coord;
							TicTacToe::pieces[i].y = y_coord;
						}
						else {
							p.pieceType = 'O';
							pieces.push_back(p);
							TicTacToe::pieces[i].pieceType = 'O';
							TicTacToe::pieces[i].x = x_coord;
							TicTacToe::pieces[i].y = y_coord;
						}
					}
					else {
						cout << "The spot you chose has already been taken. Please fill an empty spot (ie 1,2)" << endl;
						unsigned int redo = 5;
						prompt(redo, redo);
						return InvalidInput;
					}
			}
		

	}



	return Success;
}

int TicTacToe::turn() {
	unsigned int redo = 5;
	if (currentPlayer == 'O') {
		cout << "Current player is O" << endl;
		prompt(redo, redo);
		currentPlayer = 'X';

	}
	else {
		cout << "Current player is X" << endl;
		prompt(redo, redo);
		currentPlayer = 'O';
	}
	return Success;
}

int TicTacToe::play(){
	cout << *this << endl;
	while (!done() && !draw()) {
		turn();
	}
	if (done()) {
		cout << *this;
		cout << winningPlayer << " is the winner!" << endl;
		return Success;
	}
	else if (draw()) {
		cout << *this << endl;
		cout << "Tie Game!" << endl;
		return Success;
	}
	return Success;
}