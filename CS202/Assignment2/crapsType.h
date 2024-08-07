/*
Name: Kishore Chidella, NSHE, CLASS-SECTION, ASSIGNMENT 2
Description: <Craps Game Simulation>
Input: <bet amount>
Output: <Game log for the game play>
*/

#ifndef CRAPSTYPE_H
#define CRAPSTYPE_H
#include <string>

using namespace std;

/**
 * @brief crapsType Class
 *
 */
class crapsType
{
public:
    crapsType();
    void readStake();
    int getStake() const;
    void setStake(int);
    int getCurrentBalance() const;
    void setDisplay(bool);
    bool playCraps(int);

private:
    int originalStake;
    int cashOnHand;
    bool display;
    int die1, die2;
    string nickName;
    static const int MINSTAKE = 50;
    static const int MAXSTAKE = 10000;
    static const int MINBET = 10;
    static const int MAXBET = 1000;
    void displayRoll(int die1, int die2);
};

//For convenience, all the die combination names. Note that dies start at 1, but
//arrays start at 0, so all the indices are minus 1
const string moveNames[6][6] = {
    {"Snake Eyes", "Ace Deuce", "Easy Four", "Fever Five", "Easy Six", "Seven Out"},
    {"Ace Deuce", "Hard Four", "Fever Five", "Easy Six", "Seven Out", "Easy Eight"},
    {"Easy Four", "Fever Five", "Hard Six", "Seven Out", "Easy Eight", "Nina"},
    {"Fever Five", "Easy Six", "Seven Out", "Hard Eight", "Nina", "Easy Ten"},
    {"Easy Six", "Seven Out", "Easy Eight", "Nina", "Hard Ten", "Yo-leven"},
    {"Seven Out", "Easy Eight", "Nina", "Easy Ten", "Yo-leven", "Boxcars"}
};

#endif // CRAPSTYPE_H