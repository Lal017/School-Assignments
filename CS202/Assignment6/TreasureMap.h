#ifndef TREASURE_H
#define TREASURE_H true

#include "List.h"
#include "ComplexNumber.h"
#include <iostream>

using namespace std;

class TreasureMap; //Forward Declaration of TreasureMap class

//Base class for the types of MapInstructions
struct MapInstruction 
{
public:
	MapInstruction() {} //Default constructor that does nothing
	virtual void followInstruction(TreasureMap* map) = 0;
	virtual string toString() = 0;
	virtual ~MapInstruction() {}
};

//Map instruction to turn by some amount
struct TurnInstruction : public MapInstruction
{
	ComplexNumber rotationAmount;
public:
	void followInstruction(TreasureMap* map);
	string toString();

	TurnInstruction(ComplexNumber rotation) { this->rotationAmount = rotation; rotationAmount.normalize(); }
};

//Map instruction to pace in the current direction for some distance
struct PaceInstruction : public MapInstruction
{
	double distance;
public:
	void followInstruction(TreasureMap* map);
	string toString();

	PaceInstruction(double distance) { this->distance = distance; }
};

class TreasureMap
{
	List<MapInstruction*> instructions; //Set of instructions read from a file
	List <string> log; //Log of messages from following instructions
	ComplexNumber direction; //Current direction you are facing
	ComplexNumber position; //Current position in the world

public:
	void findTreasure();
	TreasureMap() {} //Default constructor
	~TreasureMap(); //Destructor, written for you since it isn't in the rubric

	//Mark Pace and Turn functions as friends so that they can update the map
	friend void PaceInstruction::followInstruction(TreasureMap* map);
	friend void TurnInstruction::followInstruction(TreasureMap* map);

	//Operator overloads
	friend istream& operator >> (istream& in, TreasureMap& map);
	friend ostream& operator << (ostream& out, const TreasureMap& map);
};

#endif
