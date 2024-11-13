/**
 * @file ModuloDigit.cpp
 * @brief Implements the ModuloDigit class methods for single digit counting
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#include "ModuloDigit.h"
#include <iostream>

/**
 * @brief Parameterized Constructor for ModuloDigit class
 *
 * @param int max		: [IN] The maximum count value
 *
 * @attention The constructor assigns
 * the base value and current_count value
 */
ModuloDigit::ModuloDigit(int max)
{
	base = max;
	currentCount = 0;

}

/**
 * @brief Default constructor for ModuloDigit class
 *
 * @attention The constructor assigns the
 * base value and current_count value to null
 */
ModuloDigit::ModuloDigit()
{
	base = 0;
	currentCount = 0;
}

/**
 * @brief Counter method which increments the current count
 * and resets to 0 if the maximum count is reached
 *
 * @return True if the count overflows else false
 */
bool ModuloDigit::counter()
{
	currentCount++;
	if ((currentCount % base) == 0)
	{
		currentCount = 0;
		return true;
	}
	return false;

}

/**
 * @brief Getter method for the current counter value
 *
 * @return The current counter value
 */
int ModuloDigit::getCurrentCount() const
{
	return currentCount;
}

/**
 * @brief Prints the current count value in the
 * respective input base (binary, hex, octal, decimal)
 */
void ModuloDigit::print() const
{
	if (base == 16)
	{
		std::cout << std::hex << std::uppercase << currentCount << std::dec;
	}
	else
	{
		std::cout << currentCount;
	}
}

/**
 * @brief Destructor for ModuloDigit class.
 */
ModuloDigit::~ModuloDigit()
{

}

