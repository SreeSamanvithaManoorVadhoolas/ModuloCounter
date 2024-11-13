/**
 * @file ModuloNCounter.h
 * @brief Declares the ModuloNCounter class for for N digits counting
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef MODULO_N_COUNTER_H
#define MODULO_N_COUNTER_H

#include "ModuloDigit.h"

/**
 * @class ModuloNCounter
 *
 * @brief This class represents N digit counting operation
 */
class ModuloNCounter
{
private:
	/** Array of ModuloDigit objects representing individual digits in the counter*/
	ModuloDigit *countArr;

	/** Number of digits for which the counter should run*/
	int digits;

	/** base of the counter (2, 8, 10, or 16)*/
	int base;

	/**
	 * @brief Increments the counter, checks the overflow and
	 * resets counter if there is overflow
	 */
	void count();

	/**
	 * @brief Prints the current N counter value
	 */
	void print() const;

	/**
	 * @brief Check for counter overflow
	 *
	 * @return True if no overflow else false
	 */
	bool checkOverflow() const;

public:

	/**
	 * @brief Constructor for ModuloNCounter class
	 * It initializes values for the base and digits variables
	 * Creates an array of type ModuloDigit
	 *
	 * @param int inputDigits 		: [IN] Number of digits in the counter
	 * @param int inputBase			: [IN] Base of the counter (2, 8, 10, or 16)
	 */
	ModuloNCounter(int digit, int base);

	/**
	 * @brief Increments the N digit counter
	 * and prints the current count
	 */
	void normalCounter();

	/**
	 * @brief Prefix increment operator
	 * Increments the N digit counter and prints the current count
	 *
	 * @return Reference to the incremented ModuloNCounter object
	 */
	ModuloNCounter& operator++();

	/**
	 * @brief Postfix increment operator
	 * Post increments the N digit counter and prints the current count
	 *
	 * @param int a 		: [IN]  Unused parameter for postfix increment
	 *
	 * @return Reference to the incremented ModuloNCounter object
	 */
	ModuloNCounter& operator++(int);

	/**
	 * @brief Destructor for ModuloNCounter class
	 *
	 * @attention Deallocates memory for the array of ModuloDigit objects
	 * Reset member variables
	 */
	~ModuloNCounter();

};

#endif // MODULO_N_COUNTER_H
