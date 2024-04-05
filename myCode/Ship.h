/**
 * @file Ship.h
 * @brief Declares the Ship class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef SHIP_H_
#define SHIP_H_
#include<set>
#include"GridPosition.h"

/**
 * @class Ship
 * @brief Represents a ship in the Battleship game
 *
 * The Ship class defines a ship's position, length,
 * and occupied/blocked areas on the grid
 */
class Ship
{
private:
	/** The grid position of (front) of the ship */
	const GridPosition bow;

	/**< The grid position of stern (rear) of the ship */
	const GridPosition stern;
public:
	/**
	 * @brief Constructor for the Ship class
	 * @param GridPosition inBow : [IN]
	 * Grid position of bow (front) of the ship
	 * @param GridPosition inStern : [IN]
	 * Grid position of stern (rear) of the ship
	 * @attention The constructor assigns bow and stern
	 */
	Ship(const GridPosition &inBow, const GridPosition &inStren);

	/**
	 * @brief Checks if the ship is valid (has a valid bow,stern,length)
	 * @return True if ship is valid, false otherwise
	 */
	bool isValid() const;

	/**
	 * @brief Getter function for the grid position of the bow
	 * @return The grid position of the bow
	 */
	GridPosition getBow() const;

	/**
	 * @brief Getter function for the grid position of the stern
	 * @return The grid position of the stern
	 */
	GridPosition getStern() const;

	/**
	 * @brief Returns length of ship
	 * @return The length of ship
	 */
	int length() const;

	/**
	 * @brief Calculates and returns occupiedArea set
	 * @return OccupiedArea set
	 */
	std::set<GridPosition> occupiedArea() const;

	/**
	 * @brief Calculates and returns blockedArea set
	 * @return BlockedArea set
	 */
	std::set<GridPosition> blockedArea() const;

	/**
	 * @brief Destructor for the Ship class
	 */
	~Ship();
};

#endif /* SHIP_H_ */
