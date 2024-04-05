/**
 * @file GridPosition.h
 * @brief Declares the ConsoleView class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_
#include<iostream>

/**
 * @class GridPosition
 * @brief Represents a position on the grid in the Battleship game
 *
 * The GridPosition class manages grid locations with methods for
 * validity, row/column retrieval, and string conversion
 */
class GridPosition
{
private:
	/** The row of the grid position */
	char row;

	/** The column of the grid position */
	int column;

public:
	/**
	 * @brief Constructor for GridPosition class
	 * @param int row : [IN] The row of grid position
	 * @param int column : [IN] The column of grid position
	 * @attention The constructor assigns rows and columns
	 */
	GridPosition(char row, int column);

	/**
	 * @brief Constructor for GridPosition class from a string representation
	 * @param string position : [IN] string representation of the grid position
	 * @attention The constructor assigns rows and columns
	 */
	GridPosition(std::string position);

	/**
	 * @brief Checks if grid position is valid
	 * @return True if position is valid, false otherwise
	 */
	bool isValid() const;

	/**
	 * @brief Getter function for row of the grid position
	 * @return The row of grid position
	 */
	char getRow() const;

	/**
	 * @brief Getter function for column of the grid position
	 * @return The column of grid position
	 */
	int getColumn() const;

	/**
	 * @brief Conversion operator to convert grid position
	 * row & column to a string
	 * @return The string representation of grid position
	 */
	operator std::string() const;

	/**
	 * @brief Equality operator to check if two grid positions are equal
	 * @param other : [IN] The other GridPosition to compare
	 * @return True if the grid positions are equal, false otherwise
	 */
	bool operator==(const GridPosition &other) const;

	/**
	 * @brief Less than operator to compare two grid positions
	 * @param other : [IN] The other GridPosition to compare
	 * @return True if this grid position is less than other,
	 * false otherwise
	 */
	bool operator<(const GridPosition &other) const;

	/**
	 * @brief Destructor for the GridPosition class
	 */
	~GridPosition();
};

#endif /* GRIDPOSITION_H_ */
