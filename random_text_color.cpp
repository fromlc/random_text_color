//------------------------------------------------------------------------------
// random_text_color.cpp
// 
// Demos using ansi.h to display console text in a random color 
//------------------------------------------------------------------------------

// our own local header files are referenced FIRST in double quotes ""
#include "ansi_colors.h"		// for ANSI console text color escape sequences

// system header files are referenced in angle brackets <>
#include <iostream>		// for cin, cout
#include <cstdlib>		// for srand(), rand()
#include <ctime>		// for time()

//using namespace std;

//------------------------------------------------------------------------------
// random_text_color.cpp
// 
// Demos using ansi.h to display console text in a random color 
//------------------------------------------------------------------------------
int main()
{
	int random_color;				// which console text color to use
	bool color_supported = true;	// controls display

	//----------------------------------------------------------------------
	// rand() is a pseudo-ranmdom number generator. "Pseudo-random"
	// because every time rand() generates the same sequence of numbers.
	// 
	// To generate a different sequence each time this app runs,
	// call srand() to seed the sequence.
	// 
	// Standard practice: seed the random number generator with
	// the number of seconds since 00:00am on January 1, 1970
	// 
	// time(0)
	// 
	// This can cause compiler warnings about possible data loss.
	// The C++ type system is strict, but we as programmers can
	// overcome the type system with type casting. 
	// 
	// See if you can fix the warnings with type casting..
	//----------------------------------------------------------------------

	// use a variable so we can see the result in the debugger
	int seed = time(0);

	// set the starter "seed" value for random number generator
	srand(seed);

	// limit the random number range to 1 - NUM_COLORS
	random_color = rand() % NUM_COLORS + 1;

	if (random_color == 2)
		std::cout << FG_RED;

	else if (random_color == 3)
		std::cout << FG_GREEN;

	// further limit text color to not black (invisible)
	else if (random_color == 1 || random_color == 7)
		std::cout << FG_CYAN;

	// #TODO we don't check for all 8 color numbers yet so make everything else yellow for now
	else
	{
		color_supported = false;
		std::cout << FG_YELLOW;
	}

	// display the color number and appropriate message
	std::cout << "random_color = " << random_color << endl;

	if (color_supported)
		std::cout << "random text color\n";
	else
		std::cout << "unsupported color chosen\n";

	system("pause");

	return 0;
}