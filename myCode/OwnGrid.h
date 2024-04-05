/**
 * @file OwnGrid.h
 * @brief Declares the OwnGrid class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include<iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "Ship.h"
#include "Shot.h"

/**
 * @class OwnGrid
 * @brief Represents own grid in Battleship game
 *
 * The OwnGrid class manages placing ships, taking blows from
 * opponent shots,and tracking shot results
 */
class OwnGrid
{
private:
	/** Number of rows in own grid */
	int rows;

	/** Number of columns in own grid */
	int columns;

	/** Vector to store ships */
	std::vector<Ship> ships;

	/** Map to store count of ships based on their lengths */
	std::map<int, int> shipCounts;

	/** Vector to store placed ships */
	std::vector<Ship> placedShips;

	/** Set to store the positions that have been shot at */
	std::set<GridPosition> shotAt;

public:

	/**
	 * @brief Constructor for the OwnGrid class
	 * @param int rows : [IN] Number of rows in own grid
	 * @param int columns : [IN] Number of columns in own grid
	 * @attention The constructor assigns rows, columns
	 * and defines shipCounts
	 */
	OwnGrid(int rows, int columns);

	/**
	 * @brief Getter function for the number of rows in own grid
	 * @return The number of rows in own grid
	 */
	int getRows() const;

	/**
	 * @brief Getter function for the number of columns in own grid
	 * @return The number of columns in own grid
	 */
	int getColumns() const;

	/**
	 * @brief Places a ship on own grid
	 * @param Ship& ship : [IN] The Ship object representing the ship to be placed
	 * @return True if the ship is successfully placed, false otherwise
	 */
	bool placeShip(const Ship &ship);

	/**
	 * @brief Getter function for vector of ships placed on own grid
	 * @return A constant reference ships vector
	 */
	const std::vector<Ship>& getShips() const;

	/**
	 * @brief Processes impact of a shot on own grid
	 * @param Shot& shot : [IN] The Shot object representing shot taken by opponent
	 * @return The impact of shot (NONE, HIT, SUNKEN)
	 */
	Shot::Impact takeBlow(const Shot &shot);

	/**
	 * @brief Getter function for set of positions that have been shot at
	 * @return A constant reference to set of shot positions
	 */
	const std::set<GridPosition>& getShotAt() const;

	/**
	 * @brief Destructor for OwnGrid class
	 */
	~OwnGrid();
};

#endif /* OWNGRID_H_ */
