/*
Name: (YOUR NAME)
Description: <Description here>
Input: File name of the map to read and use
Output: Steps of the map to reach the treasure
*/

#include "TreasureMap.h"
#include <string>

//#define DEBUG true //Uncomment this to turn on debugging messages

using namespace std;

//TODO: Finish TreasureMap related functions

//------------ Treasure Map Implementations ------------

/*The main portion of our program. This will go through the set
of instructions that the map has and follow them to get from 
the starting point to where the treasure is. Also keeps a log
of all the actions that can printed later */
void TreasureMap::findTreasure()
{
	//Grab this right now to avoid doing multiple calls
	int instructionCount = instructions.getCount(); 

	//Log some info at the beginning
	#ifdef DEBUG //Debug prints for your convenience
	cout << "Read " << instructionCount << " instructions" << endl;
	cout << "Starting position: " << position.toString() << endl;
	cout << "Starting direction: " << to_string(direction.getDegrees()) << endl;
	#endif // DEBUG

	log.addElement("Map: " + to_string(instructionCount) + " instructions");
	log.addElement("Starting position: " + position.toString());
	log.addElement("Starting direction: " + to_string(direction.getDegrees()));

	//Go through all the instructions
	for (int i = 0; i < instructionCount; i++) 
	{
		log.addElement("\n------ Instruction " + to_string(i) + " ------");
		instructions[i]->followInstruction(this); //Follow the instruction

		#ifdef DEBUG //Some debug print messages for your convenience
		cout << instructions[i]->toString() << endl << "Position: " << position.toString() << endl <<
			"Direction: " << to_string(direction.getDegrees()) << endl;
		#endif

		//Record the message for this step in our log
		log.addElement(instructions[i]->toString());
		log.addElement("Position: " + position.toString());
		log.addElement("Direction: " + to_string(direction.getDegrees()));
	}

	log.addElement("We've reached the treasure at " + position.toString() + "!");
}

//Operator overloads

/**/
istream& operator >> (istream& in, TreasureMap& map)
{
	//Read in the starting point and the starting direction using the 
	//ComplexNumber >> overload

	//TODO: Read the position then the direction

	//TODO: Finish the rest of the read to read in the instruction
	//character, followed by reading the data into the correct instruction type
	//Read until you are at the end of the in stream
		//If the character is a P, make a new PaceInstruction and add it to the 
		//map's instructions list after reading in the distance to pace.
		// 
		//If the character is a T, make a new TurnInstruction and add it to the 
		//map's instructions list after reading the ComplexNumber for the rotationDirection

	//Variables to read into
	char instructionType;
	float tempDistance;
	ComplexNumber tempComplex;

	in >> instructionType; //Read the first instruction
	while (!in.eof())
	{
		switch (instructionType)
		{
			case 'P': //Pace case 
				//TODO Do something similar for the pace case as the turn case
				break;
			case 'T': //Turn case (provided for you as an example)
				in >> tempComplex; //Read the ComplexNumber rotation argument after the 'T'
				map.instructions.addElement(new TurnInstruction(tempComplex)); //Add a new turn instruction to the list
				break;
			default:
				break;
		}
		in >> instructionType; //Preemptively read the next char command so we can trigger eof before looping
	}

	map.direction.normalize(); //Make sure the direction is normalized before we start

	return in;
}

/**/
ostream& operator << (ostream& out, const TreasureMap& map)
{
	//Print all the messages from the log
	int logCount = map.log.getCount(); //Get how many entries are in the log

	//TODO: Print all the messages to the out stream with a linefeed

	return out;
}

//------------ Turn Instruction Implementations ------------

//Performs a turn instruction on the given map and updates its
//direction field
void TurnInstruction::followInstruction(TreasureMap* map)
{
	//Rotate the direction being faced in the map by the rotation amount
	map->direction = map->direction * this->rotationAmount; 
	map->direction.normalize(); //Normalize the direction vector
}

//Returns a string version of the TurnInstruction
string TurnInstruction::toString()
{
	return "Turned by " + to_string(rotationAmount.getDegrees())  + " degrees";
}

//------------ Pace Instruction Implementations ------------

//Performs a pace instruction on the given map and updates its
//position field by walking in the given direction by the 
//instruction's distance
void PaceInstruction::followInstruction(TreasureMap* map)
{
	map->position = map->position + (distance * map->direction);
}

//Returns a string version of the PaceInstruction
string PaceInstruction::toString()
{
	return "Paced " + to_string(distance) + " meters";
}

//------------- Treasure Map destructor -----------------
TreasureMap::~TreasureMap() 
{
	//Make sure to free all of the instruction pointers
	for(int i = 0; i < instructions.getCount(); i++)
		delete instructions[i];
}