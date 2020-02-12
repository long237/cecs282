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

    char test1 = '-1';
    char test2 = '1';
    if (test1 == test2) {
        cout << "they are equal" << endl;
    }

    if (test2 == 1) {
        cout << "1 char is equal to 1 char" << endl;
    }

    int turn = 1;
    int row;
    int col;
    bool validity = false;
    //keep asking for input if moveisvalid return false
    for (int i = 0; i < 9; i++) {
        PrintBoard(game_board);
        bool validity = false;
        while (!validity) {
            cout << "Player" << turn << endl;
            GetMove(row, col);
            validity = MoveIsValid(game_board, row, col);
        }
        if (turn == 1) {
            game_board[row][col] = '1';
            cout << "player" << turn << "move" << endl;
            turn++;
        }
        else {
            game_board[row][col] = '-1';
            cout << "player" << turn << "move" << endl;
            turn = -1;
        }
    }

    char test3 = '-5';
    cout << "this is the char " << test3 << endl;

}
