/**
 * @file part3tests.cpp
 * @brief Executes part 3 tests for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 *
 */
#include "testFiles.h"

using namespace std;

void part3tests()
{
	Board b1(10, 10);

	//placing valid ships
	Ship shipA(GridPosition("B2"), GridPosition("B4"));
	Ship shipB(GridPosition("D4"), GridPosition("G4"));
	Ship shipC(GridPosition("F6"), GridPosition("F9"));
	Ship shipD(GridPosition("B6"), GridPosition("D6"));
	Ship shipE(GridPosition("E1"), GridPosition("I1"));
	Ship shipF(GridPosition("J6"), GridPosition("J8"));
	assertTrue(b1.getOwnGrid().placeShip(shipA), "Ship of size 3 placed");
	assertTrue(b1.getOwnGrid().placeShip(shipB), "Ship of size 4 placed");
	assertTrue(b1.getOwnGrid().placeShip(shipC), "Ship of size 4 placed");
	assertTrue(b1.getOwnGrid().placeShip(shipD), "Ship of size 3 placed");
	assertTrue(b1.getOwnGrid().placeShip(shipF), "Ship of size 5 placed");

	//Taking blow in valid positions
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("B3")) == Shot::Impact::HIT,
			"Ship not hit @ B3");
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("B4")) == Shot::Impact::HIT,
			"Ship not hit @ B4");
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("F7")) == Shot::Impact::HIT,
			"Ship not hit @ F7");
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("C6")) == Shot::Impact::HIT,
			"Ship not hit @ C6");
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("D4")) == Shot::Impact::HIT,
			"Ship not hit @ D4");
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("J8")) == Shot::Impact::HIT,
			"Ship not hit @ J8");
	//sinking ship
	assertTrue(
			(b1.getOwnGrid().takeBlow(GridPosition("B2"))
					== Shot::Impact::SUNKEN), "Ship B2 B4 not sunken");

	//Taking blow at position with no ship
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("B5")) == Shot::Impact::NONE,
			"Miss @ B5");

	//Taking blow in invalid position
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("K11")) == Shot::Impact::NONE,
			"Ship hit at invalid position");

	//Taking blow at position with no ship
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("J10")) == Shot::Impact::NONE,
			"Miss not detected @ J10");
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("A1")) == Shot::Impact::NONE,
			"Miss not detected  @ A1");
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("A9")) == Shot::Impact::NONE,
			"Miss not detected  @ A9");
	assertTrue(
			b1.getOwnGrid().takeBlow(GridPosition("I5")) == Shot::Impact::NONE,
			"Miss not detected  @ I5");

	//opponent grid
	b1.getOpponentGrid().shotResult(GridPosition("C3"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("C4"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("C5"), Shot::Impact::SUNKEN);
	b1.getOpponentGrid().shotResult(GridPosition("C2"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("F5"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("G4"), Shot::Impact::NONE);
	b1.getOpponentGrid().shotResult(GridPosition("G5"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("G6"), Shot::Impact::HIT);
	b1.getOpponentGrid().shotResult(GridPosition("I6"), Shot::Impact::NONE);

	std::map<GridPosition, Shot::Impact> shots =
			b1.getOpponentGrid().getShotsAt();

	assertTrue(!(shots[GridPosition("C3")] != Shot::Impact::SUNKEN),
			"Should be sunken but not detected");
	assertTrue(!(shots[GridPosition("C4")] != Shot::Impact::SUNKEN),
			"Should be sunken but not detected");
	assertTrue(!(shots[GridPosition("G6")] != Shot::Impact::HIT),
			"Should be hit but not detected");
	assertTrue(!(shots[GridPosition("I6")] != Shot::Impact::NONE),
			"Should be miss but not detected");
}
