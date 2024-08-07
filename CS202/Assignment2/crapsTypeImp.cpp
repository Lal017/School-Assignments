/*
Name: Eduardo Salazar, 5005695833 ,Section 1003, Assignment 2
Description: write functions to play craps game
Input: bet amount
Output: Game log for the game play
*/
#include "crapsType.h" 
#include <iostream> //preprocessor directive
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

//Header file is generally used for declarations (Kind of like prototypes)
//Corresponding source .cpp files are then used to define those declarations.
//In other words, most actual code should go in the source file, the header is for names
//For this assignment, all your code goes here

//TODO: Write all the function bodies

/************ crapsType function definitions ************/

crapsType::crapsType() //constructor 
{
    originalStake = 0;
    cashOnHand = 0;
    display = true;
    die1 = 0;
    die2 = 0;
	//Constructors generally initialize variables
	//Set the int members to 0 and the display boolean to true
}

void crapsType::readStake() //read and input stake amount
{
    int stake; //stake input

    while(true){
        cout << "Enter stake amount: ";
        cin >> stake;
        cout << endl;
        cout << endl;

        if(cin.fail() || stake < MINSTAKE || stake > MAXSTAKE){ //sets boundaries
            cout << "Error, invalid entry. ";
            cout << "must be between 50 and 10000 inclusive." << endl;
            cout << "Please re-enter." <<endl;
            cin.clear(); //clear input if fails
            cin.ignore(1000,'\n');
        }
        else{
            break; //break loop
        }
    }

    setStake(stake); //call set stake function

    //Read an input until we get a valid number for the original stake
    //You can use cin.clear() and cin.ignore() to fix the buffer after bad reads
    //It's also suggested to use cin.fail() to check if the read was successful
    
    //After a successful read, need to make sure that the value is in the range
    //[MIN_STAKE, MAX_STAKE]

    //Loop indefinitely. You can change this if you like.
    //My solution involved looping until a
    //valid input was given and then returning
}

int crapsType::getStake() const //get stake function
{
    //Just returns the original stake. This is an accessor/getter
    return originalStake; //return original stake private variable
}

void crapsType::setStake(int stake) //set stake function
{
    if(stake >= MINSTAKE || stake <= MAXSTAKE){ //checks boundaries
        originalStake = stake; //sets stake to original stake
        cashOnHand = stake;
    }
    //Just sets the originalStake. This is a mutator/setter
    //Make sure that the stake is within the range
    //[MIN_STAKE, MAX_STAKE] first
}

int crapsType::getCurrentBalance() const 
{
    //Just returns the cashOnHand
    return cashOnHand; //returns cash on hand private variable
}

void crapsType::setDisplay(bool display_set) //sets display bool
{
    display = display_set;
    //Just sets the display member variable to the passed param
}

bool crapsType::playCraps(int bet) //plays a game of craps
{
    int roll1, roll2, sum; //varaible declaration
    int point; //variable declaration

    while(true){ //loop
        if(bet >= MINBET && bet <= MAXBET){ //checks boundaries
            break; //break loop
        }
        else{
            cout << "Error, Invalid Stake Amount" <<endl; //error message
            cout << "Error, Invalid Bet" <<endl;
            return false; //return false
        }
    }

    roll1 = (rand() % 6 + 1); //gets random number between 1-6
    roll2 = (rand() % 6 + 1); //gets random number between 1-6

    if(display == true){ //if display bool is true
        displayRoll(roll1, roll2); //calls display function
    }

    sum = roll1 + roll2; //adds two rolls together

    if(sum == 7 || sum == 11){ //checks sum value
        if(display == true){ //if display bool is true
            cout << "Won" << endl; //won game display
        }
        cashOnHand = cashOnHand + bet; //sets new cash on hand
        return true; //return true
    }
    else if(sum == 2 || sum == 3 || sum == 12){ //checks sum value
        cashOnHand = cashOnHand - bet; //sets new cash on hand 
        return false; //return false
    }
    else{
        point = sum; //sets point value
        if(display == true){
            cout << "Point: " << point << endl; 
        }
    }

    while(true){ //loop 
        roll1 = (rand() % 6 + 1); //gets random number between 1-6
        roll2 = (rand() % 6 + 1); //gets random number between 1-6

        sum = roll1 + roll2; //sets sum value

        if(display == true){
            displayRoll(roll1, roll2); //calls display function
        }

        if(sum == point){
            cashOnHand = cashOnHand + bet; //sets cash on hand
            if(display == true){
                cout << "Won" << endl; 
                cout << "Current Balance : $" << cashOnHand << endl; //displays balance
                cout << "---------------------------" << endl;
            }
            return true; //returns true
        }
        else if(sum == 7){
            cashOnHand = cashOnHand - bet; //sets new cash on hand
            return false; //returns false
        }
    }

    //The meat of the program is here. 
    //Plays a round of craps. Returns a boolean on whether or not the round was won
    //If the game was game was won, the player gets the bet as money via cashOnHand, 
    //if they lose the cashonHand goes down by that much

    //Make sure that the bet is valid and in the range [MIN_BET, MAX_BET]
    //If it's invalid, print an error message and return

    //Roll two random numbers using rand() and store them in the dice members.
    //Limit them to be between 1 and 6
    //Note that rand is seeded in main, so you should always get the same numbers

    //Find the sum
    //If the sum is 7 or 11, the person automatically wins
    //If the sum is 2, 3, or 12, the person automatically loses
    //Else if the sum is anything else, the sum is the point value
        //The player needs to keep re-rolling and printing until they either:
        //Hit the point value and win
        //Roll a 7 and lose
}

void crapsType::displayRoll(int die1, int die2)
{
    cout << "Die 1: " << die1 << "   Die 2: " << die2;
    cout << "   Sum: " << die1 + die2;
    cout << setw(21) << moveNames[die1-1][die2-1] << endl;

    //Displays the die rolls, their sum, and the name. 
    //See the rubric for a formatting example
    //You can use the static moveNames string array from crapsType.h
    //to get the name more easily.
    //This function is private and can only be used by other crapsType member functions
}