/**
 * @file OpponentGrid.h
 * @brief Declares the OpponentGrid class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "Ship.h"
#include "Shot.h"
#include "GridPosition.h"

/**
 * @class OpponentGrid
 * @brief Represents the opponent grid in the Battleship game
 *
 * The OpponentGrid class manages opponent grid, keeping track of shot results,
 * sunken ships, and provides getter methods
 */
class OpponentGrid
{
private:
	/** Number of rows in opponent grid */
	int rows;

	/** Number of rows in opponent grid */
	int columns;

	/** Map to store count of ships based on their lengths */
	std::map<int, int> shipCounts;

	/** Vector to store sunken ships */
	std::vector<Ship> sunkenShips;

	/** Map to store shot results at different positions */
	std::map<GridPosition, Shot::Impact> shots;

	/**
	 * @brief Inserts sunken ships based on provided position
	 * @param GridPosition& position :
	 * [IN] The position where the ship is sunken
	 */
	void insertSunkenShips(const GridPosition &position);

public:
	/**
	 * @brief Constructor for OpponentGrid class
	 * @param int rows : [IN] Number of rows in opponent grid
	 * @param int columns : [IN] Number of columns in opponent grid
	 * @attention The constructor assigns rows, columns
	 *  and defines shipCounts
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * @brief Getter function for number of rows in opponent grid
	 * @return The number of rows in opponent grid
	 */
	int getRows() const;

	/**
	 * @brief Getter function for number of columns in opponent grid
	 * @return The number of columns in opponent grid
	 */
	int getColumns() const;

	/**
	 * @brief Processes the result of a shot on opponent grid
	 * @param Shot &shot : [IN] Shot object representing shot taken
	 * @param Shot::Impact impact : [IN] Impact of  shot
	 * (NONE, HIT, SUNKEN)
	 */
	void shotResult(const Shot &shot, Shot::Impact impact);

	/**
	 * @brief Getter function for shot results at different positions on opponent grid
	 * @return A constant reference to shots map
	 */
	const std::map<GridPosition, Shot::Impact>& getShotsAt() const;

	/**
	 * @brief Getter function for vector of sunken ships
	 * @return A constant reference to sunkenships vector
	 */
	const std::vector<Ship>& getSunkenShips() const;

	/**
	 * @brief Destructor for the OpponentGrid class
	 */
	~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
