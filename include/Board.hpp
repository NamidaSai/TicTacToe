#ifndef BOARD_HPP
#define BOARD_HPP

#include "Player.hpp"

class Board
{
    public:
        Board();
        ~Board();

        void SetUpNewBoard();
        bool InputTokenAtPosition(int xPos, int yPos, char marker);
        void PrintBoard();
        bool CheckForWin(Player player);
        void ClearBoard();
        int GetNumberOfCells();

    private:
        void SetBoardParams();
        void InitBoard();
        void DefineWinCondition();
        bool CheckRows();
        bool CheckColumns();
        bool CheckDiagonals();

        int _width;
        int _height;
        int _tokenGoal;
        char** _board;
};


#endif /* BOARD_HPP */