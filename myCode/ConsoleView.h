/**
 * @file ConsoleView.h
 * @brief Declares the ConsoleView class for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

/**
 * @class ConsoleView
 * @brief Represents console view for Battleship game
 *
 * ConsoleView class is responsible for displaying the game board
 * It takes a pointer to the Board class
 */
class ConsoleView
{
private:
	/** Pointer to the game board */
	Board *board;

public:
	/**
	 * @brief Constructor for the ConsoleView class
	 * @param board  : [IN] Pointer to the Board object
	 */
	ConsoleView(Board *board);

	/**
	 * @brief Displays the current state of the game board in the console
	 */
	void print();

	/**
	 * @brief Destructor for the ConsoleView class
	 */
	~ConsoleView();
};

#endif /* CONSOLEVIEW_H_ */
