/**
 * @file Ship.cpp
 * @brief Declares the Ship class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include "Ship.h"
#include <iostream>

/**
 * @brief Constructor for the Ship class
 * @param GridPosition inBow : [IN]
 * Grid position of bow (front) of the ship
 * @param GridPosition inStern : [IN]
 * Grid position of stern (rear) of the ship
 * @attention The constructor assigns bow and stern
 */
Ship::Ship(const GridPosition &inBow, const GridPosition &inStren) :
		bow(inBow), stern(inStren)
{
}

/**
 * @brief Checks if the ship is valid (has a valid bow,stern,length)
 * @return True if ship is valid, false otherwise
 */
bool Ship::isValid() const
{
	return getBow().isValid() && getStern().isValid()
			&& (length() >= 2 && length() <= 5)
			&& (getBow().getRow() == getStern().getRow()
					|| getBow().getColumn() == getStern().getColumn());
}

/**
 * @brief Getter function for the grid position of the bow
 * @return The grid position of the bow
 */
GridPosition Ship::getBow() const
{
	return this->bow;
}

/**
 * @brief Getter function for the grid position of the stern
 * @return The grid position of the stern
 */
GridPosition Ship::getStern() const
{
	return this->stern;
}

/**
 * @brief Returns length of ship
 * @return The length of ship
 */
int Ship::length() const
{
	int length = 0;
	if (getBow().isValid() && getStern().isValid())
	{
		if (getBow().getRow() == getStern().getRow())
			length = abs(getStern().getColumn() - getBow().getColumn()) + 1;
		else if (getBow().getColumn() == getStern().getColumn())
			length = abs(getStern().getRow() - getBow().getRow()) + 1;
	}

	return length;
}

/**
 * @brief Calculates and returns occupiedArea set
 * @return OccupiedArea set
 */
std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> occupiedSet;
	if (isValid())
	{
		if (getBow().getRow() == getStern().getRow())
		{
			for (int col = getBow().getColumn(); col <= getStern().getColumn();
					col++)
			{
				occupiedSet.insert(GridPosition(getBow().getRow(), col));
			}
		}
		else if (getBow().getColumn() == getStern().getColumn())
		{

			for (int row = getBow().getRow(); row <= getStern().getRow(); row++)
			{
				occupiedSet.insert(GridPosition(row, bow.getColumn()));
			}
		}
	}

	return occupiedSet;
}

/**
 * @brief Calculates and returns blockedArea set
 * @return BlockedArea set
 */
std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> blockedAreaSet;
	std::set<GridPosition> occupiedSet = occupiedArea();
	for (auto itr = occupiedSet.begin(); itr != occupiedSet.end(); itr++)
	{
		for (int r = -1; r <= 1; r++)
		{
			for (int c = -1; c <= 1; c++)
			{
				if (GridPosition(itr->getRow() + r, itr->getColumn() + c).isValid())
				{
					blockedAreaSet.insert(
							GridPosition(itr->getRow() + r,
									itr->getColumn() + c));
				}
			}
		}
	}
	return blockedAreaSet;
}

/**
 * @brief Destructor for the Ship class
 */
Ship::~Ship()
{
}

