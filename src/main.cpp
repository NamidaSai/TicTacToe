#include <iostream>
#include <string>
#include <algorithm>

#include "Board.hpp"
#include "Player.hpp"

using namespace std;

void GameLoop(Player player1, Player player2, Board &board);
void SwitchCurrentPlayer(Player player1, Player player2, Player &currentPlayer);
void PlayerTurn(Player player, Board &board);

int main()
{
	cout << "\n\n ***** TIC TAC TOE ***** \n\n";
	cout << "This is a simple game of Tic Tac Toe.\n\n";
	cout << "IMPORTANT: Please note that this program may not have full error handling\nPlease carefully follow input instructions.\nPress Enter after input.\n";

	cout << "\nYou will need two players.\n";
	cout << "Player 1 name: \n";
	Player player1;
	cout << "Player 2 name: \n";
	Player player2;

	player1.SetToken();
	player2.SetToken();

	Board board;

	bool keepPlaying = true;

	while (keepPlaying)
	{
		cout << "\nWe're now ready to start!\n\n";
		GameLoop(player1, player2, board);

		cout << "\nWant to play again? (Y/N)\n";
		char playerResponse;
		cin >> playerResponse;
		if (playerResponse == 'N')
		{
			keepPlaying = false;
			break;
		}

		cout << "\nDo you want to keep the same board? (Y/N)\n";
		cin >> playerResponse;
		if (playerResponse == 'Y')
		{
			board.ClearBoard();
		}
		else
		{
			board.SetUpNewBoard();
		}
	}

	cout << "\nThanks for playing!\nEnd of Game.\n";
	system("PAUSE");
	return 0;
}

void GameLoop(Player player1, Player player2, Board &board)
{
	bool isPlayingRound = true;
	Player currentPlayer = player1;
	int turns = 0;
	int maxTurns = board.GetNumberOfCells();

	while (isPlayingRound)
	{
		turns++;
		if (turns > maxTurns)
		{
			board.PrintBoard();
			cout << "\nIt's a tie!\n";
			isPlayingRound = false;
			break;
		}

		PlayerTurn(currentPlayer, board);
		isPlayingRound = !board.CheckForWin(currentPlayer);
		SwitchCurrentPlayer(player1, player2, currentPlayer);
	}
}

void SwitchCurrentPlayer(Player player1, Player player2, Player &currentPlayer)
{
	if (currentPlayer.GetToken() == player1.GetToken())
	{
		currentPlayer = player2;
	}
	else
	{
		currentPlayer = player1;
	}
	
}

void PlayerTurn(Player player, Board &board)
{
	int xTargetPosition = 0;
	int yTargetPosition = 0;
	bool isAvailablePosition = false;

	board.PrintBoard();
	cout << "It's " << player.GetName() << "'s turn.\nWhere would you like to play?\n";

	while (!isAvailablePosition)
	{
		cout << "Column number: \n";
		cin >> xTargetPosition;
		cout << "Row number: \n";
		cin >> yTargetPosition;

		isAvailablePosition = board.InputTokenAtPosition(xTargetPosition, yTargetPosition, player.GetToken());
	}
}