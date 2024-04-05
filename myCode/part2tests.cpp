/**
 * @file part2tests.cpp
 * @brief Executes part 2 tests for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 *
 */
#include "testFiles.h"

using namespace std;

void part2tests()
{
	//part2tests

	// Blocked area
	//horizontal
	assertTrue((Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "B3" } }.blockedArea() == set<GridPosition>
	{ GridPosition
	{ "A1" }, GridPosition
	{ "A2" }, GridPosition
	{ "A3" }, GridPosition
	{ "A4" }, GridPosition
	{ "B1" }, GridPosition
	{ "B2" }, GridPosition
	{ "B3" }, GridPosition
	{ "B4" }, GridPosition
	{ "C1" }, GridPosition
	{ "C2" }, GridPosition
	{ "C3" }, GridPosition
	{ "C4" } }), "Blocked area for Ship(B2,B3) not correct");

	//vertical
	assertTrue((Ship
	{ GridPosition
	{ "G7" }, GridPosition
	{ "I7" } }.blockedArea() == set<GridPosition>
	{ GridPosition
	{ "F6" }, GridPosition
	{ "F7" }, GridPosition
	{ "F8" }, GridPosition
	{ "G6" }, GridPosition
	{ "G7" }, GridPosition
	{ "G8" }, GridPosition
	{ "H6" }, GridPosition
	{ "H7" }, GridPosition
	{ "H8" }, GridPosition
	{ "I6" }, GridPosition
	{ "I7" }, GridPosition
	{ "I8" }, GridPosition
	{ "J6" }, GridPosition
	{ "J7" }, GridPosition
	{ "J8" } }), "Blocked area for Ship(G7,I7) not correct");

	//Invalid lengths
	assertTrue(Ship
	{ GridPosition
	{ "I4" }, GridPosition
	{ "I4" } }.blockedArea() == set<GridPosition>
	{ }, "Ship of invalid length has an Occupied Area");
	assertTrue(Ship
	{ GridPosition
	{ "A6" }, GridPosition
	{ "F6" } }.blockedArea() == set<GridPosition>
	{ }, "Ship of invalid length has an Occupied Area");
	assertTrue(Ship
	{ GridPosition
	{ "B0" }, GridPosition
	{ "D0" } }.blockedArea() == set<GridPosition>
	{ }, "Ship with invalid bow and stern values has an Occupied Area");

	//ship placement
	Board b1(10, 10);

	//	Constructor, getRows, GetColumns
	assertTrue(b1.getOwnGrid().getRows() == 10, "Row is not 10");
	assertTrue(b1.getOwnGrid().getColumns() == 10, "Column is not 10");
	assertTrue(b1.getOpponentGrid().getRows() == 10, "Row is not 10");
	assertTrue(b1.getOpponentGrid().getColumns() == 10, "Column is not 10");

	//Placeship

	//Invalid ships
	Ship ship1(GridPosition("@1"), GridPosition("@5"));
	assertTrue(!(b1.getOwnGrid().placeShip(ship1)), "Invalid Ship placed");

	Ship ship2(GridPosition("H0"), GridPosition("H0"));
	assertTrue(!(b1.getOwnGrid().placeShip(ship2)), "Invalid Ship placed");

	Ship ship3(GridPosition("J10"), GridPosition("J11"));
	assertTrue(!(b1.getOwnGrid().placeShip(ship3)), "Invalid Ship placed");

	Ship ship4(GridPosition("E3"), GridPosition("E8"));
	assertTrue(!(b1.getOwnGrid().placeShip(ship4)), "Invalid Ship placed");

	//Valid ships
	Ship shipA(GridPosition("B2"), GridPosition("B4"));
	assertTrue(b1.getOwnGrid().placeShip(shipA),
			"Valid Ship of size not 3 placed");

	Ship shipB(GridPosition("D4"), GridPosition("G4"));
	assertTrue(b1.getOwnGrid().placeShip(shipB),
			"Valid Ship of size not 4 placed");

	Ship shipC(GridPosition("F6"), GridPosition("F9"));
	assertTrue(b1.getOwnGrid().placeShip(shipC),
			"Valid Ship of size not 4 placed");

	//Placing ship of exceeded length
	Ship shipD(GridPosition("A8"), GridPosition("D8"));
	assertTrue(!(b1.getOwnGrid().placeShip(shipD)),
			"Ship of limit exceeded size 4 placed");

	//Placing ship in blocked area of other ships
	Ship shipE(GridPosition("B5"), GridPosition("D5"));
	assertTrue(!(b1.getOwnGrid().placeShip(shipE)),
			"Ship of size 3 placed in blocked area of other ships");

	//valid ships
	Ship shipF(GridPosition("B6"), GridPosition("D6"));
	assertTrue(b1.getOwnGrid().placeShip(shipF),
			"Valid Ship of size not 3 placed");

	Ship shipG(GridPosition("C8"), GridPosition("C10"));
	assertTrue(b1.getOwnGrid().placeShip(shipG),
			"Valid Ship of size not 3 placed");

	Ship shipH(GridPosition("E1"), GridPosition("I1"));
	assertTrue(b1.getOwnGrid().placeShip(shipH),
			"Valid Ship of size not 5 placed");

	Ship shipI(GridPosition("H7"), GridPosition("I7"));
	assertTrue(b1.getOwnGrid().placeShip(shipI),
			"Valid Ship of size not 2 placed");

	Ship shipJ(GridPosition("I3"), GridPosition("I4"));
	assertTrue(b1.getOwnGrid().placeShip(shipJ),
			"Valid Ship of size not 2 placed");

	Ship shipK(GridPosition("J9"), GridPosition("J10"));
	assertTrue(b1.getOwnGrid().placeShip(shipK),
			"Valid Ship of size not 2 placed");

	Ship shipL(GridPosition("A9"), GridPosition("A10"));
	assertTrue(b1.getOwnGrid().placeShip(shipL),
			"Valid Ship of size not 2 placed");

	//Placing ship after all lengths are exhausted
	Ship shipM(GridPosition("H9"), GridPosition("H10"));
	assertTrue(!(b1.getOwnGrid().placeShip(shipM)),
			"Ship placed after all lengths exhausted");

}
