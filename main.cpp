#include "Board.cpp"

int turn(int player_turn){
    if (player_turn == 1){
        player_turn = 2;
        return player_turn;
    }
    else {
        player_turn = 1;
        return player_turn;
    }
};

int main() {
    Board myBoard = Board();
    myBoard.displayBoard();
    int Player = 1;
    int column;
    while (myBoard.winCheck() != true){
        std::cout << "Player " << Player << std::endl;
        std::cout << "Where will you drop your token?" << std::endl;
        std::cin >> column;
        myBoard.dropToken(column, Player);
        Player = turn(Player);
        myBoard.displayBoard();
    }
    Player = turn(Player);
    std::cout << "Player " << Player << " wins!" << std::endl;
    return 0;
}