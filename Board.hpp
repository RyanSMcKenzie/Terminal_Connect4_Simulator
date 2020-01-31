#include <iostream>

// Board class declaration
class Board{
    private:
        // Board is a 6 x 7 grid
        int connect_board[6][7];
    public:
        Board();

        void displayBoard();

        void dropToken(int row, int token);

        bool horizontalWin();

        bool verticalWin();

        bool diagonalWin();
        
        bool winCheck();

};