#include <iomanip>
#include <iostream>
#include "tictactoe.h"
using namespace std;

int main(int argc, char* argv[]) {
    std::array<std::array<char, 3>, 3> game_board = {0};
    game_board[0][0] = 0;
    game_board[0][1] = 0;
    game_board[0][2] = 0;
    game_board[1][0] = 0;
    game_board[1][1] = 0;
    game_board[1][2] = 0;
    game_board[2][0] = 0;
    game_board[2][1] = 0;
    game_board[2][2] = 0;

    //cout << "winner value" << CheckWinner(game_board) << endl;


    int turn = 1;
    int row;
    int col;
    bool validity = false;
    int winner;
    //Run the game for 9 loops.
    for (int i = 0; i < 9; i++) {
        PrintBoard(game_board);
        bool validity = false;

        //Check for the winner at every iteration
        winner = CheckWinner(game_board);
        if (winner != 0) {
            break;
        }

        //cheking for the user input
        while (!validity) {
            if (turn == 1) {
                cout << "X's turn "<< endl;
            }
            else {
                cout << "O's turn" << endl;
            }

            GetMove(row, col);
            validity = MoveIsValid(game_board, row, col);
            if (validity == false) {
                cout << "That space is taken or out of bound!!!" << endl;
            }
        }

        //change the elements value in the game board.
        //change to 1 if it is player X turn and decrease the counter
        if (turn == 1) {
            game_board[row][col] = 1;
            turn = turn + 1;
        }
        //change elements to -1 and increase counter turn.
        else {
            game_board[row][col] = -1;
            turn = turn - 1;
        }
        cout << "" << endl;
    }

    //check the board again in case of winning on last move
    winner = CheckWinner(game_board);
    PrintBoard(game_board);
    if (winner == 1) {
        cout << "Player X wins !!!" << endl;
    }
    else if (winner == -1){
        cout << "Player O wins !!!" << endl;
    }
    else {
        cout << "Draw !!!!" << endl;
    }
}
