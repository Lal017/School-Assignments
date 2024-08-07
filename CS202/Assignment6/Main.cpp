/*
Name: (YOUR NAME)
Description: This program reads in a treasure map file, starting with a starting position
and direction to face, and then a series of instructions on how to reach a treasure.

The two instructions are to pace (walk directly forward) and to turn.
These two instructions will be implemented using a custom ComplexNumber class,
representing a complex number in 2D space and having three operations:
An operation to multiply two ComplexNumbers (rotate)
An operation to multiply a scalar by a ComplexNumber (travel some distance in a direction)
An operation to add two ComplexNumber (adjust a position by a vector)

This main file will do error checking, read in the treasure map using the >> overload,
find the treasure by following the instructions, and then print the results using the << overload

Input: File name of the map to read and use
Output: Steps of the map to reach the treasure
*/

//	C++ program to implement a virtual craps game.

#include <iostream>
#include <fstream>
#include "TreasureMap.h"

using namespace std;

int main(int argc, char** argv)
{
	//Make sure that the program was used correctly
	if (argc != 2)
	{
		cout << "Incorrect usage. Usage: \n ./treasure <filename>" << endl;
		return 1;
	}

	//Open the file and read from it
	ifstream infile(argv[1]);
	if (!infile.good()) //If the file did not open, print a message
	{
		cout << "Could not open file " << argv[1] << endl <<
			"Is it in the correct directory?" << endl;
		return 1;
	}

	//Read the map from the file
	TreasureMap map;
	infile >> map;

	//Follow the instructions to find the treasre
	map.findTreasure();

	//Print the results of finding the treasure
	cout << map;

	return 0;
}