/**
 * @file Shot.cpp
 * @brief Declares the Shot class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include "Shot.h"

Shot::Shot(const GridPosition &inTargetPosition) :
		targetPosition(inTargetPosition)
{
}

GridPosition Shot::Shot::getTargetPosition() const
{
	return this->targetPosition;
}

Shot::~Shot()
{
}

