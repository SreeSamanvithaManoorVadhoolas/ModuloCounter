/**
 * @file Board.h
 * @brief Declares the Board class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * @class Board
 * @brief Represents game board in Battleship game
 *
 * Board class consists both player's own grid and
 * opponent's grid, along with dimensions of board
 */

class Board
{
private:
	/** Player's own grid */
	OwnGrid ownGrid;

	/** Opponent's grid */
	OpponentGrid opponentGrid;

	/** Number of rows in the board */
	int rows;

	/** Number of columns in the board */
	int columns;

public:
	/**
	 * @brief Parameterized Constructor for the Board class
	 * @param int rows : [IN] Number of rows
	 * @param int columns : [IN] Number of columns
	 * @attention The constructor assigns rows and columns
	 */
	Board(int rows, int columns);

	/**
	 * @brief Getter function for the number of rows in the board
	 * @return The number of rows in the board
	 */
	int getRows() const;

	/**
	 * @brief Getter function for the number of columns in the board
	 * @return The number of columns in the board
	 */
	int getColumns() const;

	/**
	 * @brief Getter function for the player's own grid
	 * @return Reference to the player's own grid
	 */
	OwnGrid& getOwnGrid();

	/**
	 * @brief Getter function for the opponent's grid
	 * @return Reference to the opponent's grid
	 */
	OpponentGrid& getOpponentGrid();

	/**
	 * @brief Destructor for the Board class
	 */
	~Board();
};

#endif /* BOARD_H_ */
