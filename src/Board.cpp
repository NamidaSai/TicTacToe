#include "Board.hpp"
#include <iostream>
#include <string>

using namespace std;

Board::Board()
{
    SetUpNewBoard();
}

Board::~Board()
{
    for (int i = 0; i <_height; i++)
    {
        delete[] _board[i];
    }
    delete[] _board;
}


//* ----- PUBLIC FUNCTIONS ----- *//


void Board::SetUpNewBoard()
{
    SetBoardParams();
    InitBoard();
    ClearBoard();
    PrintBoard();
    DefineWinCondition();
}

bool Board::InputTokenAtPosition(int xPos, int yPos, char token)
{
    if (xPos > _width || yPos > _height)
    {
		cout << "Position is out of board range!\nPlease pick new position.\n";
        return false;
    }
    else if (_board[yPos-1][xPos-1] != '.')
    {
        cout << "Position is occupied.\nPlease pick new position.\n";
        return false;
    }
    else
    {
        _board[yPos-1][xPos-1] = token;
        return true;
    }
}

void Board::PrintBoard()
{
    cout << "\nHere's the board: \n";

    for (int x = 0; x < _width + 1; ++x)
    {
        if (x == 0)
        {
            cout << "   ";
            continue;
        }
        cout << " " << x << " ";
    }

    cout << endl;

    for (int y = 0; y < _height; ++y)
    {
        cout << y + 1 << " |";
        for (int x = 0; x < _width; ++x)
        {
            cout << " " << _board[y][x] << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

bool Board::CheckForWin(Player player)
{
    if (CheckRows() || CheckColumns() || CheckDiagonals())
    {
        PrintBoard();
        cout << player.GetName() << " has won this round!\n\n";
        return true;
    }
    else
    {
        return false;
    }
}

void Board::ClearBoard()
{
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            _board[y][x] = '.';
        }
    }
}


//* ----- PRIVATE FUNCTIONS ----- *//


void Board::SetBoardParams()
{
    _width = 1;
    _height = 1;

	cout << "\nLet's set up a new board!\n";

    bool paramsOutOfRange = true;

    while (paramsOutOfRange)
    {
        cout << "Board width (3-9): \n";
        cin >> _width;
        cout << "Board height (3-9): \n";
        cin >> _height;

        paramsOutOfRange = (_width <= 2) || (_width > 9) || (_height <= 2) || (_height > 9);

        if (paramsOutOfRange)
        {
            cout << "This board would not display correctly.\nPlease enter new parameters.\n";
        }
    }
}

void Board::InitBoard()
{
    _board = new char*[_height];
    for (int i = 0; i < _height; ++i)
    {
        _board[i] = new char[_width];
    }
}

void Board::DefineWinCondition()
{
	int maxGoal = max(_width, _height);

	cout << "How many aligned tokens are needed to win the game? (2-" << maxGoal << ")\n";
	cin >> _tokenGoal;

	while (_tokenGoal > maxGoal)
	{
		cout << "That number does not fit the current board!\nPlease pick again (2-" << maxGoal << "): \n";
		cin >> _tokenGoal;
	}

    cout << endl;
}

bool Board::CheckRows()
{
    for (int y = 0; y < _height; ++y)
    {
        int rowTokenCount = 1;

        for (int x = 0; x < _width; ++x)
        {
            if (x == 0) { continue; }

            if ((_board[y][x] != '.') && (_board[y][x] == _board[y][x-1]))
            {
                rowTokenCount++;
                if (rowTokenCount >= _tokenGoal)
                {
                    return true;
                }
            }
            else
            {
                rowTokenCount = 1;
            }
        }
    }
    
    return false;
}

bool Board::CheckColumns()
{
    for (int x = 0; x < _width; ++x)
    {
        int colTokenCount = 1;

        for (int y = 0; y < _height; ++y)
        {
            if (y == 0) { continue; }

            if ((_board[y][x] != '.') && (_board[y][x] == _board[y-1][x]))
            {
                colTokenCount++;
                if (colTokenCount >= _tokenGoal)
                {
                    return true;
                }
            }
            else
            {
                colTokenCount = 1;
            }
        }
    }
    
    return false;
}

bool Board::CheckDiagonals()
{
    return false;
}