/**
 * @file main.cpp
 * @brief Main program for Battleship game game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 *
 * Runs different test function for
 * different parts of the task
 *
 * @return 0 upon successful completion
 */
// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required

using namespace std;

// Add your project's header files here
#include "testFiles.h"

// Main program
int main()
{
	cout << "battleship started." << endl << endl;
	part1tests();
	part2tests();
	part3tests();

	Board b1(10, 10);
	ConsoleView view(&b1);
	//placing valid ships
	Ship shipA(GridPosition("B2"), GridPosition("B4"));
	Ship shipB(GridPosition("D4"), GridPosition("G4"));
	Ship shipC(GridPosition("F6"), GridPosition("F9"));
	b1.getOwnGrid().placeShip(shipA);
	b1.getOwnGrid().placeShip(shipB);
	b1.getOwnGrid().placeShip(shipC);
	b1.getOwnGrid().takeBlow(GridPosition("B3"));
	b1.getOwnGrid().takeBlow(GridPosition("B4"));
	b1.getOwnGrid().takeBlow(GridPosition("B5"));

	b1.getOpponentGrid().shotResult(GridPosition("C3"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("C4"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("C5"), Shot::Impact::SUNKEN);
	b1.getOpponentGrid().shotResult(GridPosition("C2"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("F5"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("G4"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("G5"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("G6"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("I6"), Shot::Impact::NONE);

	view.print();

	std::cout << std::endl;
	return 0;
}
