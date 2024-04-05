/**
 * @file OpponentGrid.cpp
 * @brief Declares the OpponentGrid class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include "OpponentGrid.h"

/**
 * @brief Constructor for OpponentGrid class
 * @param int rows : [IN] Number of rows in opponent grid
 * @param int columns : [IN] Number of columns in opponent grid
 * @attention The constructor assigns rows, columns
 *  and defines shipCounts
 */
OpponentGrid::OpponentGrid(int inRows, int inColumns) :
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
 * @brief Inserts sunken ships based on provided position
 * @param GridPosition& position :
 * [IN] The position where the ship is sunken
 */
void OpponentGrid::insertSunkenShips(const GridPosition &position)
{
	char row = position.getRow();
	int column = position.getColumn();

	std::map<GridPosition, Shot::Impact> shotsCopy = getShotsAt();

	// Check horizontally to the left
	int leftColumn = column;
	while (--leftColumn >= 1 && shotsCopy[
	{ row, leftColumn }] == Shot::Impact::HIT)
		;

	// Check horizontally to the right
	int rightColumn = column;
	while (++rightColumn <= getColumns() && shotsCopy[
	{ row, rightColumn }] == Shot::Impact::HIT)
		;

	// Check vertically upwards
	char upRow = row;
	while (--upRow >= 'A' && shotsCopy[
	{ upRow, column }] == Shot::Impact::HIT)
		;

	// Check vertically downwards
	char downRow = row;
	while (++downRow <= ('A' + getRows() - 1) && shotsCopy[
	{ downRow, column }] == Shot::Impact::HIT)
		;

	char newRow = upRow + 1;
	char newColumn = downRow - 1;
	GridPosition bow(newRow, leftColumn + 1);
	GridPosition stern(newColumn, rightColumn - 1);

	int shipLength = Ship(bow, stern).length();

	if ((row == bow.getRow() && row == stern.getRow())
			|| (column == bow.getColumn() && column == stern.getColumn()))
	{
		auto it = shipCounts.find(shipLength);
		if (it != shipCounts.end() && it->second > 0)
		{
			sunkenShips.emplace_back(bow, stern);
			it->second--;
		}
	}
	Ship s1
	{ bow, stern };
	std::set<GridPosition> sunkenShipsOccupied = s1.occupiedArea();
	for (auto &itr : sunkenShipsOccupied)
	{
		shots[itr] = Shot::Impact::SUNKEN;
	}

}
/**
 * @brief Getter function for number of rows in opponent grid
 * @return The number of rows in opponent grid
 */
int OpponentGrid::getRows() const
{
	return this->rows;
}

/**
 * @brief Getter function for shot results at different positions on opponent grid
 * @return A constant reference to shots map
 */
int OpponentGrid::getColumns() const
{
	return this->columns;
}

/**
 * @brief Processes the result of a shot on opponent grid
 * @param Shot &shot : [IN] Shot object representing shot taken
 * @param Shot::Impact impact : [IN] Impact of  shot
 * (NONE, HIT, SUNKEN)
 */
void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
	char maxRows = ('A' + getRows()) - 1;
	const GridPosition targetPosition = shot.getTargetPosition();
	if (targetPosition.isValid() && targetPosition.getRow() >= 'A'
			&& targetPosition.getRow() <= maxRows
			&& targetPosition.getColumn() >= 1
			&& targetPosition.getColumn() <= getColumns())
	{
		shots[targetPosition] = impact;

		if (impact == Shot::Impact::SUNKEN)
		{
			insertSunkenShips(targetPosition);
		}
	}

}
/**
 * @brief Getter function for shot results at different positions on opponent grid
 * @return A constant reference to shots map
 */
const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const
{
	return this->shots;
}

/**
 * @brief Getter function for vector of sunken ships
 * @return A constant reference to sunkenships vector
 */
const std::vector<Ship>& OpponentGrid::getSunkenShips() const
{
	return this->sunkenShips;
}

/**
 * @brief Destructor for the OpponentGrid class
 */
OpponentGrid::~OpponentGrid()
{
}
