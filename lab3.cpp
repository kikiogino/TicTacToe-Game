// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Tic-Tac-Toe.h"
#include "Pieces.h"
#include "General.h"
#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;


//constructing class
TicTacToe::TicTacToe()
    : height(5),width(5), pieceType(' '), currentPlayer('O'), winningPlayer(' '), movesLeft(9)
{}

//inseertion operator 
ostream & operator <<(ostream & output, const TicTacToe & gameBoard){ 
    //create gameboard
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int index = 5 * i + j;
            Pieces piece;
            piece.x = 0;
            piece.y = 0;
            piece.pieceType = ' ';
            gameBoard.pieces.push_back(piece);
        }
    }

    //print gameboard
    for (int i = 4; i >=0; i--) {
        cout << i << " ";
        for (int j = 0; j <=4; j++) {

            int index = 5 * i + j;
            gameBoard.pieces[index].x = j;
            gameBoard.pieces[index].y = i;

            cout << gameBoard.pieces[index].pieceType << " ";
        }
        cout << endl;
    }

    cout << " 0 1 2 3 4 " << endl;
    return output;
}


int main(int argc, char*argv[])
{
    if (argc != NumArgs) {
        cout << "Please input two arguments, the program name and file name." << endl;
        return InvalidNumArgs;
    }
    string s = argv[1];
    if (s != "TicTacToe") {
        cout << "The game input should be: 'TicTacToe' " << endl;
        return InvalidNumArgs;
    }
    else {
        TicTacToe gameBoard;
        return gameBoard.play();
    }
    
}
