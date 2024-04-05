/**
 * @file Shot.h
 * @brief Declares the Shot class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef SHOT_H_
#define SHOT_H_
#include "GridPosition.h"

/**
 * @class Shot
 * @brief Represents a shot in the Battleship game
 *
 * The Shot class defines the characteristics of a shot, including its target position
 * and the possible impacts on a ship (NONE, HIT, SUNKEN).
 */
class Shot
{
private:
	/** The grid position targeted by the shot */
	GridPosition targetPosition;

public:
	/**
	 * @brief Enumeration representing the possible impacts of a shot on a ship
	 */
	typedef enum
	{
		NONE = 0, HIT = 1, SUNKEN = 2
	} Impact;

	/**
	 * @brief Constructor for the Shot class
	 * @param GridPosition& targetPosition : [IN]
	 * Grid position targeted by the shot
	 * @attention The constructor assigns targetPosition
	 */
	Shot(const GridPosition &targetPosition);
	/**
	 * @brief Getter function for the target position of the shot
	 * @return The grid position targeted by the shot
	 */
	GridPosition getTargetPosition() const;

	/**
	 * @brief Destructor for the Shot class
	 */
	~Shot();
};

#endif /* SHOT_H_ */
