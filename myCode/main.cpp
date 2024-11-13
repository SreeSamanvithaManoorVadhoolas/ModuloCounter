/**
 * @file main.cpp
 * @brief Main program for a Modulo N Counter Demonstration
 * Created on: 20-Nov-2023
 * Author: Sree Samanvitha Manoor Vadhoolas
 *
 *
 * This program demonstrates the functionality of a modulo counter. Users can
 * input the base (2/8/10/16) and the number of digits for the counter. The program
 * then creates a modulo N-digit counter and performs normal counting as well as
 * pre-increment and post-increment operations using operator overloading.
 * The counter's state is displayed after each operation, and the program continues
 * until an invalid base or number of digits are entered.
 *
 * @return 0 upon successful completion.
 */

// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"
#include "ModuloNCounter.h"

// Main program
int main()
{
	while (1)
	{
		int digits = 0;
		int base = 0;
		string type = " ";

		cout << "Please enter the parameters of your counter: " << endl;
		cout << "number of digits: ";
		cin >> digits;

		if (digits > 0)
		{
			cout << "Please enter the base (2/8/10/16): " << endl;
			cin >> base;

			if (base == 2 || base == 8 || base == 10 || base == 16)
			{
				type = (base == 2) ? "binary" : (base == 8) ? "octal" :
						(base == 10) ? "decimal" :
						(base == 16) ? "hexadecimal" : "invalid";
				cout << digits << " digit " << type << " counter" << endl;
				ModuloNCounter counter(digits, base);
				counter.normalCounter();

				cout << "Pre-increment using operator overloading for "
						<< digits << " digit " << type << " counter" << endl;
				++counter;

				cout << "Post-increment using operator overloading for "
						<< digits << " digit " << type << " counter" << endl;
				counter++;
			}
			else{
				cout << "Invalid base! Exiting!" << endl;
				break;
			}
		}
		else
		{
			cout << "Invalid number of digits! Exiting!" << endl;
			break;
		}
	}

	return 0;
}

