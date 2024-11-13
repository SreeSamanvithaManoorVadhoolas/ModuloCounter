/**
 * @file ModuloDigit.h
 * @brief Declares the ModuloDigit class for single digit counting
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef MODULODIGIT_H_
#define MODULODIGIT_H_

/**
 * @class ModuloDigit
 *
 * @brief This class represents single digit counting operation
 */
class ModuloDigit
{
private:

	/** The input type (binary, hex, octal, decimal which is the maximum count*/
	int base;

	/** The current count value*/
	int currentCount;

public:
	/**
	 * @brief Parameterized Constructor for ModuloDigit class
	 *
	 * @param int max		: [IN] The maximum count value
	 *
	 * @attention The constructor assigns
	 * the base value and currentCount value
	 */
	ModuloDigit(int max);

	/**
	 * @brief Default constructor for ModuloDigit class
	 *
	 * @attention The constructor assigns the
	 * base value and currentCount value to null
	 */
	ModuloDigit();

	/**
	 * @brief Counter method which increments the current count
	 * and resets to 0 if the maximum count is reached
	 *
	 * @return True if the count overflows else false
	 */
	bool counter();

	/**
	 * @brief Getter method for the current counter value
	 *
	 * @return The current counter value
	 */
	int getCurrentCount() const;

	/**
	 * @brief Prints the current count value in the
	 * respective input base (binary, hex, octal, decimal)
	 */
	void print() const;

	/**
	 * @brief Destructor for ModuloDigit class.
	 */
	~ModuloDigit();
};

#endif /* MODULODIGIT_H_ */

