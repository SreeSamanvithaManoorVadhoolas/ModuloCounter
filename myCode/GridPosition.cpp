/**
 * @file GridPosition.cpp
 * @brief Implements the ConsoleView class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include <string>
#include "GridPosition.h"

/**
 * @brief Constructor for GridPosition class
 * @param int row : [IN] The row of grid position
 * @param int column : [IN] The column of grid position
 * @attention The constructor assigns rows and columns
 */
GridPosition::GridPosition(char inRow, int inColumn) :
		row(inRow), column(inColumn)
{
}

/**
 * @brief Constructor for GridPosition class from a string representation
 * @param string position : [IN] string representation of the grid position
 * @attention The constructor assigns rows and columns
 */
GridPosition::GridPosition(std::string position)
{
	this->row = position[0];
	if (isdigit(position[1]))
	{
		this->column = stoi(position.substr(1));
	}
	else
	{
		column = 0;
	}
}

/**
 * @brief Checks if grid position is valid
 * @return True if position is valid, false otherwise
 */
bool GridPosition::isValid() const
{
	return ('A' <= row && row <= 'Z') && (column > 0);
}

/**
 * @brief Getter function for row of the grid position
 * @return The row of grid position
 */
char GridPosition::getRow() const
{
	return this->row;
}

/**
 * @brief Getter function for column of the grid position
 * @return The column of grid position
 */
int GridPosition::getColumn() const
{
	return this->column;
}

/**
 * @brief Conversion operator to convert grid position
 * row & column to a string
 * @return The string representation of grid position
 */
GridPosition::operator std::string() const
{
	return getRow() + std::to_string(column);
}

/**
 * @brief Equality operator to check if two grid positions are equal
 * @param other : [IN] The other GridPosition to compare
 * @return True if the grid positions are equal, false otherwise
 */
bool GridPosition::operator ==(const GridPosition &other) const
{
	if (isValid() && other.isValid())
		return (getRow() == other.getRow())
				&& (getColumn() == other.getColumn());
	else
		return false;
}

/**
 * @brief Less than operator to compare two grid positions
 * @param other : [IN] The other GridPosition to compare
 * @return True if this grid position is less than other,
 * false otherwise
 */
bool GridPosition::operator <(const GridPosition &other) const
{
	if (isValid() && other.isValid())
		return (getRow() < other.getRow())
				|| (getRow() == other.getRow()
						&& getColumn() < other.getColumn());
	else
		return false;
}

/**
 * @brief Destructor for the GridPosition class
 */
GridPosition::~GridPosition()
{
}

