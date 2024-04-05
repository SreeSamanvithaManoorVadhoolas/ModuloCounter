/**
 * @file ConsoleView.cpp
 * @brief Implements the ConsoleView class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include "ConsoleView.h"

/**
 * @brief Constructor for the ConsoleView class
 * @param board  : [IN] Pointer to the Board object
 */
ConsoleView::ConsoleView(Board *inBoard) :
		board(inBoard)
{
}

/**
 * @brief Displays the current state of the game board in the console
 */
void ConsoleView::print()
{
	const int rows = board->getRows();
	const int columns = board->getColumns();

	//For tens place print of own grid
	int ownGridCount = 0;
	int opponentGridCount = 0;
	std::cout << "  ";
	for (int col = 1; col <= columns; ++col)
	{
		if (col % 10 == 0)
		{
			ownGridCount++;
		}
		if (ownGridCount == 0)
			std::cout << "  ";
		else
			std::cout << ownGridCount << ' ';
	}
	std::cout << "    ";
	//For tens place print of opponent grid
	for (int col = 1; col <= columns; ++col)
	{
		if (col % 10 == 0)
		{
			opponentGridCount++;
		}
		if (opponentGridCount == 0)
			std::cout << "  ";
		else
			std::cout << opponentGridCount << ' ';
	}
	std::cout << std::endl;

	//For ones place print of own grid
	std::cout << "  ";
	for (int col = 1; col <= columns; ++col)
	{
		std::cout << col % 10 << ' ';
	}
	std::cout << "    ";

	//For ones place print of opponent grid
	for (int col = 1; col <= columns; ++col)
	{
		std::cout << col % 10 << ' ';
	}
	std::cout << std::endl;

	//Printing rows for both grids side by side
	for (char row = 'A'; row < 'A' + rows; ++row)
	{
		//Print row value
		std::cout << row << ' ';

		//Print the cells for own grid
		for (int col = 1; col <= columns; ++col)
		{
			GridPosition currentPosition(row, col);

			//Check if the current position has a placed ship
			bool hasShip = false;
			bool isHit = false;
			bool isMiss = false;

			std::vector<Ship> ships = board->getOwnGrid().getShips();
			std::set<GridPosition> shots = board->getOwnGrid().getShotAt();

			//Check for hasShip
			for (auto &itr : ships)
			{
				if (itr.occupiedArea().count(currentPosition) > 0)
				{
					hasShip = true;
					break;
				}

			}

			//Check for isHit
			if (shots.count(currentPosition) > 0)
			{
				if (hasShip)
				{
					isHit = true;
				}
				else
				{
					isMiss = true;
				}
			}

			std::cout << (hasShip ? (isHit ? 'O' : '#') : (isMiss ? '^' : '~'))
					<< ' ';

		}

		//Separation for own grid and opponent grid
		std::cout << "    ";

		//Print the cells for opponent grid
		for (int col = 1; col <= columns; ++col)
		{
			GridPosition currentPosition(row, col);

			bool isOpponentHit = false;
			bool isOpponentMiss = false;
			bool isSunkenShip = false;

			std::map<GridPosition, Shot::Impact> opponentShots =
					board->getOpponentGrid().getShotsAt();
			const std::vector<Ship> &opponentSunkenShips =
					board->getOpponentGrid().getSunkenShips();

			//Check for isOpponentHit and isSunkenShip
			if (opponentShots.count(currentPosition) > 0)
			{
				if (opponentShots.at(currentPosition) == Shot::Impact::HIT)
				{
					isOpponentHit = true;

					for (const auto &ship : opponentSunkenShips)
					{
						if (ship.occupiedArea().count(currentPosition) > 0)
						{
							isSunkenShip = true;
							break;
						}
					}
				}
				//Check for isSunkenShip
				else if (opponentShots.at(currentPosition)
						== Shot::Impact::SUNKEN)
				{
					for (const auto &ship : opponentSunkenShips)
					{
						if (ship.occupiedArea().count(currentPosition) > 0)
						{
							isSunkenShip = true;
							break;
						}
					}
				}
				//Check for isOpponentMiss
				else if (opponentShots.at(currentPosition)
						== Shot::Impact::NONE)
				{
					isOpponentMiss = true;
				}
			}

			char output = '~';
			if (isOpponentHit)
			{
				output = 'O';
			}
			if (isSunkenShip)
			{
				output = '#';
			}
			if (isOpponentMiss)
			{
				output = '^';
			}
			std::cout << output << ' ';

		}

		std::cout << std::endl;
	}
}

/**
 * @brief Destructor for the ConsoleView class
 */
ConsoleView::~ConsoleView()
{
}

