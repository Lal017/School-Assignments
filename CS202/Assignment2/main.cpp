/*
Name: Kishore Chidella, NSHE, CLASS-SECTION, ASSIGNMENT 2
Description: <Craps Game Simulation>
Input: <bet amount>
Output: <Game log for the game play>
*/
//  CS 202
//  Provided Main Program
//  Assignment #2 - Craps Game

//	C++ program to implement a virtual craps game.

// ********************************************************************

#include <cstdlib>
#include <iostream>
#include <string>
#include "crapsType.h"

using namespace std;

void showSummary(crapsType myGame, int w, int l, int r, string title);

// ********************************************************************

/**
 * @brief Main function
 *
 * @return int
 */
int main(int argc, char **argv)
{
	if(argc != 2){
		return 0;
	}

	srand(stoi(string(argv[1])));

	crapsType gameA;
	int wins = 0, losses = 0, rounds = 0;
	int myBet = 100, balance;
	string gameAtitle = "Game Example A (w/display)";
	string bars = "---------------------------";

	cout << bars << endl;
	cout << "CS 202 Assignment #2" << endl;
	cout << "Craps Game Simulation." << endl;
	cout << endl;
	cout << bars << endl;
	cout << gameAtitle << endl;
	gameA.readStake();
	gameA.setDisplay(true);

	cout << bars << endl;
	while (true)
	{
		if (gameA.playCraps(myBet))
			wins++;
		else
			losses++;

		rounds++;
		balance = gameA.getCurrentBalance();
		if (balance <= myBet)
			break;

		if (balance >= (gameA.getStake() * 4))
			break;
	}
	showSummary(gameA, wins, losses, rounds, gameAtitle);

	//****************************************************************

	crapsType game1;
	int wins1 = 0, losses1 = 0, rounds1 = 0;
	int myBet1 = 100, balance1;

	game1.setStake(1); // note, invalid
	game1.setStake(1000);
	game1.setDisplay(false);

	game1.playCraps(5); // note, invalid

	while (true)
	{
		if (game1.playCraps(myBet1))
			wins1++;
		else
			losses1++;

		rounds1++;
		balance1 = game1.getCurrentBalance();
		if (balance1 <= myBet1)
			break;

		if (balance1 >= (game1.getStake() * 4))
			break;
	}
	showSummary(game1, wins1, losses1, rounds1, 
		"Game Example 1 (wo/display)");

	return 0;
}

/**
 * @brief Simple function to display game summary.
 *
 * @param myGame
 * @param w
 * @param l
 * @param r
 * @param title
 */
void showSummary(crapsType myGame, int w, int l, int r, string title)
{
	string stars = "************************************************";
	string spc = "   ";

	cout << endl
		 << stars << endl;

	cout << "Game Results:" << endl;
	cout << spc << "Game Title: " << title << endl;
	cout << spc << "Wins = " << w << endl;
	cout << spc << "Losses = " << l << endl;
	cout << spc << "Rounds = " << r << endl;
	cout << spc << "Original Stake:  $" 
	<< myGame.getStake() << ".00" << endl;
	cout << spc << "Final Balance:  $" 
	<< myGame.getCurrentBalance() << ".00" << endl;

	if (myGame.getCurrentBalance() > myGame.getStake())
		cout << spc << "Winner!!" << endl;
	else
		cout << spc << "Loser." << endl;

	cout << stars << endl
		 << endl;
}