// lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iomanip>
#include <ostream>
#include "gameBase.h"

using namespace std;

//TicTacToe::TicTacToe() :boardWidth(5), boardHeight(5), piece('X'), playerX({}), playerO({}), moves_num(0), winner(' ') {}

static GameBase* checkArg(int argc, char* argv[]) {
    GameBase* game = 0;
    if (argc == 2) {
        if (argv[1] == "TicTacToe") {
            game = new TicTacToe();
        }
        else if (argv[1] == "Gomoku") {
            game = new GomokuGame();
        }
    }
    return game;
}


//prints the board
ostream& operator<<(ostream& out, const TicTacToe& game) {
    //if there has been no moves made by any players, then fill the game board with empty cells.
    if (game.moves_num == 0) {
        for (int i = game.boardHeight - 1; i >= 0; i--)
        {
            for (int j = 0; j <= game.boardWidth - 1; j++)
            {
                int index = game.boardWidth * i + j;
                gamePiece piece;
                piece.boardDisplay = ' ';
                game.pieceList.push_back(piece);
            }
        }
    }

    //print out game pieces on the board.
    for (int i = game.boardHeight - 1; i >= 0; i--) {
        cout << i << ""; //print out vertical label
        for (int j = 0; j <= game.boardWidth - 1; j++) {
            int index = game.boardWidth * i + j;
            /*using setw manipulator for the spacings between displayed pieces*/
            cout << setw(game.longestDispLen) << game.pieceList[index].boardDisplay;
        }
        // same spacing for displayed pieces for horizontal alignment
        for (int i = 0; i < game.boardHeight - 1; i++) {
            cout << endl;
        }
    }

    //print out horizontal label
    cout << 0;
    for (int i = 1; i <= game.boardWidth; i++) {
        cout << setw(game.longestDispLen) << i;
    }
    return out;
}

ostream& operator<<(ostream& out, const GomokuGame& game) {
    //if there has been no moves made by any players, then fill the game board with empty cells.
    if (game.moves_num == 0) {
        for (int i = game.boardHeight - 1; i >= 0; i--)
        {
            for (int j = 0; j <= game.boardWidth - 1; j++)
            {
                int index = game.boardWidth * i + j;
                gamePiece piece;
                piece.boardDisplay = ' ';
                game.pieceList.push_back(piece);
            }
        }
    }

    //print out game pieces on the board.
    for (int i = game.boardHeight - 1; i >= 0; i--) {
        cout << i << ""; //print out vertical label
        for (int j = 0; j <= game.boardWidth - 1; j++) {
            int index = game.boardWidth * i + j;
            /*using setw manipulator for the spacings between displayed pieces*/
            cout << setw(game.longestDispLen) << game.pieceList[index].boardDisplay;
        }
        // same spacing for displayed pieces for horizontal alignment
        for (int i = 0; i < game.boardHeight - 1; i++) {
            cout << endl;
        }
    }

    //print out horizontal label
    cout << 0;
    for (int i = 1; i <= game.boardWidth; i++) {
        cout << setw(game.longestDispLen) << i;
    }
    return out;
}
int main(int argc, char* argv[])
{
    //shared_ptr<GameBase*> x = make_shared<GameBase*>(checkArg(argc, argv));

    GameBase* game = checkArg(argc, argv);
    if (game != 0) {
        return game->play();
    }  
    return userMessage(); 
}