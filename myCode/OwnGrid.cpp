/**
 * @file OwnGrid.cpp
 * @brief Declares the OwnGrid class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include "OwnGrid.h"

/**
 * @brief Constructor for the OwnGrid class
 * @param int rows : [IN] Number of rows in own grid
 * @attention The constructor assigns rows, columns
 * and defines shipCounts
 */
OwnGrid::OwnGrid(int inRows, int inColumns) :
		rows(inRows), columns(inColumns)
{
	shipCounts =
	{
	{ 5, 1 },
	{ 4, 2 },
	{ 3, 3 },
	{ 2, 4 } };
}
/**
 * @brief Getter function for the number of rows in own grid
 * @return The number of rows in own grid
 */
int OwnGrid::getRows() const
{
	return this->rows;
}

/**
 * @brief Getter function for the number of columns in own grid
 * @return The number of columns in own grid
 */
int OwnGrid::getColumns() const
{
	return this->columns;
}

/**
 * @brief Places a ship on own grid
 * @param Ship& ship : [IN] The Ship object representing the ship to be placed
 * @return True if the ship is successfully placed, false otherwise
 */
bool OwnGrid::placeShip(const Ship &newShip)
{
	char maxRows = ('A' + getRows()) - 1;

	if (!newShip.isValid())
	{
		return false;
	}

	std::set<GridPosition> oldShipsArea;
	for (const auto &ship : ships)
	{
		for (const auto &pos : ship.blockedArea())
		{
			oldShipsArea.insert(pos);
		}
	}

	std::set<GridPosition> newShipArea;

	for (const auto &pos : newShip.occupiedArea())
	{
		newShipArea.insert(pos);
	}

	// Check if the ship is within the grid boundaries
	if (newShip.getBow().getRow() >= 'A' && newShip.getBow().getRow() <= maxRows
			&& newShip.getStern().getRow() >= 'A'
			&& newShip.getStern().getRow() <= maxRows
			&& newShip.getBow().getColumn() >= 1
			&& newShip.getBow().getColumn() <= getColumns()
			&& newShip.getStern().getColumn() >= 1
			&& newShip.getStern().getColumn() <= getColumns())
	{
		// Check if the new ship intersects with existing ships
		std::set<GridPosition> intersection;

		std::set_intersection(oldShipsArea.begin(), oldShipsArea.end(),
				newShipArea.begin(), newShipArea.end(),
				std::inserter(intersection, intersection.begin()));

// Check if there are enough ships of the given length
		if (intersection.empty())
		{
			int shipLength = newShip.length();
			if (shipCounts[shipLength] > 0)
			{
				--shipCounts[shipLength];

				ships.push_back(newShip);
				return true;
			}
		}
	}

	return false;
}

/**
 * @brief Getter function for vector of ships placed on own grid
 * @return A constant reference ships vector
 */
const std::vector<Ship>& OwnGrid::getShips() const
{
	return this->ships;
}

/**
 * @brief Processes impact of a shot on own grid
 * @param Shot& shot : [IN] The Shot object representing shot taken by opponent
 * @return The impact of shot (NONE, HIT, SUNKEN)
 */
Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	char maxRows = ('A' + getRows()) - 1;
	const GridPosition &targetPos = shot.getTargetPosition();
	if (targetPos.isValid() && targetPos.getRow() >= 'A'
			&& targetPos.getRow() <= maxRows && targetPos.getColumn() >= 1
			&& targetPos.getColumn() <= getColumns())
	{
		shotAt.insert(targetPos);

		for (auto &ship : getShips())
		{
			const std::set<GridPosition> shipOccupiedArea = ship.occupiedArea();
			if (ship.occupiedArea().count(targetPos) > 0)
			{
				std::set<GridPosition> intersection;
				std::set_intersection(shipOccupiedArea.begin(),
						shipOccupiedArea.end(), shotAt.begin(), shotAt.end(),
						std::inserter(intersection, intersection.begin()));

				if (intersection.size() == ship.occupiedArea().size())
				{
					return Shot::Impact::SUNKEN;
				}

				else
				{
					return Shot::Impact::HIT;
				}
			}

		}

	}
	return Shot::Impact::NONE;
}

/**
 * @brief Getter function for set of positions that have been shot at
 * @return A constant reference to set of shot positions
 */
const std::set<GridPosition>& OwnGrid::getShotAt() const
{
	return this->shotAt;
}

/**
 * @brief Destructor for OwnGrid class
 */
OwnGrid::~OwnGrid()
{
}

