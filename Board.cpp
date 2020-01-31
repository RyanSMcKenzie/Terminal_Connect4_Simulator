#include "Board.hpp"

Board::Board() {
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            Board::connect_board[i][j] = 0;
        }
    }
}

void Board::displayBoard() {
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            std::cout << Board::connect_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::dropToken(int column, int token) {
    if ((0 < column) and (column < 8)) {
        int row = 5;
        int true_column = column - 1;
        while (Board::connect_board[row][true_column] != 0) {
            row--;
            }
        Board::connect_board[row][true_column] = token;

    }
    else {
        std::cout << "You threw your token off the board!" << std::endl;
    }
}

bool Board::horizontalWin() {
    int consecutive = 0;
    for (int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if ((Board::connect_board[i][j] == Board::connect_board[i][j+1])
            && (Board::connect_board[i][j] != 0)){
                consecutive++;
                if (consecutive == 3){
                    return true;
                }
            }
            else {
                consecutive = 0;
            }
        }
    }
}

bool Board::verticalWin() {
    int consecutive = 0;
    for (int j = 0; j < 7; j++){
        for(int i = 0; i < 6; i++){
            if ((Board::connect_board[i][j] == Board::connect_board[i-1][j])
            && (Board::connect_board[i][j] != 0)){
                consecutive++;
                if (consecutive == 3){
                    return true;
                }
            }
            else {
                consecutive = 0;
            }
        }
    }
}

bool Board::diagonalWin(){
    int consecutive = 0;
    for (int i = 0; i <= 13; i++){
        for (int j = 0; j <= i; j++){
            int k = i - j;
            if ((k < 6) && (j < 7)){
                if ((Board::connect_board[k][j] == Board::connect_board[k-1][j+1])
                && (Board::connect_board[k][j] != 0)){
                    consecutive++;
                    if (consecutive == 3){
                        return true;
                    }
                }
                else{
                    consecutive = 0;
                }
            }
        }
    }
    for (int i = 13; i >= 0; i--){
        for (int j = 0; j <= (13 - i); j++){
            int k = j + (i - 8);
            if ((k < 6) && (j < 7)){
                if ((Board::connect_board[k][j] == Board::connect_board[k+1][j+1])
                && (Board::connect_board[k][j] != 0)){
                    consecutive++;
                    if (consecutive == 3){
                        return true;
                    }
                }
                else{
                    consecutive = 0;
                }
            }
        }
    }
}
bool Board::winCheck() {
    if (Board::horizontalWin() || Board::verticalWin() || Board::diagonalWin()) {
        return true;
    }
    else {
        return false;
    }
}