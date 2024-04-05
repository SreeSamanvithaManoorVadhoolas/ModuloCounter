/**
 * @file TestFiles.h
 * @brief Declares test functions for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 */
#ifndef TESTFILES_H_
#define TESTFILES_H_

#include <iostream>
#include "Board.h"
#include "ConsoleView.h"
#include "GridPosition.h"
#include "OpponentGrid.h"
#include "OwnGrid.h"
#include "Ship.h"
#include "Shot.h"

/**
 * @brief Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, std::string failedMessage);

/**
 * @brief Executes part 1 tests for the Battleship game
 */
void part1tests();

/**
 * @brief Executes part 2 tests for the Battleship game
 */
void part2tests();

/**
 * @brief Executes part 3 tests for the Battleship game
 */
void part3tests();

#endif /* TESTFILES_H_ */
