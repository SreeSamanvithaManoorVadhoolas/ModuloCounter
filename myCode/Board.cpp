/**
 * @file Board.cpp
 * @brief Implements the Board class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */
#include "Board.h"

/**
 * @brief Parameterized Constructor for the Board class
 * @param int rows : [IN] Number of rows
 * @param int columns : [IN] Number of columns
 * @attention The constructor assigns rows and columns
 */
Board::Board(int inRows, int inColumns) :
		ownGrid(inRows, inColumns), opponentGrid(inRows, inColumns), rows(
				inRows), columns(inColumns)
{
}

/**
 * @brief Getter function for the number of rows in the board
 * @return The number of rows in the board
 */
int Board::getRows() const
{
	return rows;
}

/**
 * @brief Getter function for the number of columns in the board
 * @return The number of columns in the board
 */
int Board::getColumns() const
{
	return columns;
}

/**
 * @brief Getter function for the player's own grid
 * @return Reference to the player's own grid
 */
OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

/**
 * @brief Getter function for the opponent's grid
 * @return Reference to the opponent's grid
 */
OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}

/**
 * @brief Destructor for the Board class
 */
Board::~Board()
{
}

