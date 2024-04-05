/**
 * @file part1tests.cpp
 * @brief Executes part 1 tests for the Battleship game
 * Created on: 02-Jan-2024
 * Author: Sree Samanvitha Manoor Vadhoolas
 *
 */
#include "testFiles.h"

using namespace std;
/**
 * @brief Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage)
{
	if (!condition)
	{
		cout << failedMessage << endl;
	}
}

/**
 * @brief Executes part 1 tests for the Battleship game
 */
void part1tests()
{
	// Test GridPosition constructor
	assertTrue(GridPosition
	{ 'A', 1 }.isValid(), "A1 not considered valid");
	assertTrue(GridPosition
	{ "A1" }.isValid(), "A1 not considered valid");
	assertTrue(!GridPosition
	{ "AA" }.isValid(), "AA considered valid");
	assertTrue(!GridPosition
	{ 'A', -1 }.isValid(), "A-1 considered valid");
	assertTrue(!GridPosition
	{ '@', 1 }.isValid(), "@1 considered valid");
	GridPosition fromRowCol
	{ 'A', 1 };
	GridPosition fromString
	{ "A1" };
	assertTrue(
			fromRowCol.getRow() == fromString.getRow()
					&& fromRowCol.getColumn() == fromString.getColumn(),
			"different constructors return different objects");

	// Test getters and cast to string
	GridPosition pos1 = GridPosition
	{ 'B', 13 };
	assertTrue(pos1.getRow() == 'B',
			"GridPosition::GridPosition doesn't set row properly.");
	assertTrue(pos1.getColumn() == 13,
			"GridPosition::GridPosition doesn't set column properly.");

	assertTrue((string) pos1 == "B13", "Conversion to string fails.");

	// Test comparison
	assertTrue(!(GridPosition
	{ "A1" } < GridPosition
	{ "A1" }), "Same positions considered different by '<'");
	assertTrue(GridPosition
	{ "A1" } < GridPosition
	{ "B1" }, "Position with bigger row not considered greater");
	assertTrue(GridPosition
	{ "A1" } < GridPosition
	{ "A2" }, "Position with bigger column not considered greater");
	assertTrue(GridPosition
	{ "C21" } == GridPosition
	{ "C21" }, "Equal positions not considered equal.");
	assertTrue(!(GridPosition
	{ "@1" } < GridPosition
	{ "@2" }), "Invalid grid values are compared");
	assertTrue(!(GridPosition
	{ "@1" } == GridPosition
	{ "@1" }), "Invalid grid values are compared");

	// Test Ship Constructor
	assertTrue(!Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "C3" } }.isValid(), "Can create non-aligned ship.");
	assertTrue(!Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "B2" } }.isValid(), "Can create ship of size 1.");
	assertTrue(!Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "B7" } }.isValid(), "Can create ship of size 6.");

	// Length
	assertTrue(Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "B4" } }.length() == 3, "Length is not 3");
	assertTrue(Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "E2" } }.length() == 4, "Length is not 4");

	assertTrue(Ship
	{ GridPosition
	{ "A0" }, GridPosition
	{ "D0" } }.length() == 0,
			"Length is calculated for ship with invalid bow and stern values");

	// Occupied area
	assertTrue(Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "B5" } }.occupiedArea() == set<GridPosition>
	{ GridPosition
	{ "B2" }, GridPosition
	{ "B3" }, GridPosition
	{ "B4" }, GridPosition
	{ "B5" } }, "Occupied area not correct");

	// Occupied area
	assertTrue(Ship
	{ GridPosition
	{ "A1" }, GridPosition
	{ "A2" } }.occupiedArea() == set<GridPosition>
	{ GridPosition
	{ "A1" }, GridPosition
	{ "A2" } }, "Occupied area not correct");

	std::set<GridPosition> expectedPositions = Ship
	{ GridPosition
	{ "A1" }, GridPosition
	{ "A2" } }.occupiedArea();

	assertTrue(Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "E2" } }.occupiedArea() == set<GridPosition>
	{ GridPosition
	{ "B2" }, GridPosition
	{ "C2" }, GridPosition
	{ "D2" }, GridPosition
	{ "E2" } }, "Occupied area not correct");
	assertTrue(Ship
	{ GridPosition
	{ "B2" }, GridPosition
	{ "B5" } }.occupiedArea() == set<GridPosition>
	{ GridPosition
	{ "B2" }, GridPosition
	{ "B3" }, GridPosition
	{ "B4" }, GridPosition
	{ "B5" } }, "Occupied area not correct");
	assertTrue(Ship
	{ GridPosition
	{ "A1" }, GridPosition
	{ "A1" } }.occupiedArea() == set<GridPosition>
	{ }, "Ship of invalid length has an Occupied Area");
	assertTrue(Ship
	{ GridPosition
	{ "A1" }, GridPosition
	{ "A6" } }.occupiedArea() == set<GridPosition>
	{ }, "Ship of invalid length has an Occupied Area");
	assertTrue(Ship
	{ GridPosition
	{ "@1" }, GridPosition
	{ "@4" } }.occupiedArea() == set<GridPosition>
	{ }, "Ship with invalid bow and stern values has an Occupied Area");

}
