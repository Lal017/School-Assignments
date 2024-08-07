
// Name: Eduardo Salazar
// NSHE ID: 5005695833
// Class: CS 302 - 1003
// Assignment: 4
// Description: Make a game of connect 4 using linked lists.
#include "LL.h"
#include <iostream>
#include <vector>
using namespace std;

int convCol(char let){                                          // function to convert char to int for index
    int ret;
    switch (let){
        case 'a':
            ret = 0;
            break;
        case 'b':
            ret = 1;
            break;
        case 'c':
            ret = 2;
            break;
        case 'd':
            ret = 3;
            break;
        case 'e':
            ret = 4;
            break;
        case 'f':
            ret = 5;
            break;
        case 'g':
            ret = 6;
        default:
            break;
    }

    return ret;
}

int prompt(string player){                                      // function to prompt the player for input
    char col;
    bool range = true;

    do{
        if(cin.fail() || range == false){
            cin.clear();                                        // clear cin.fail flag
            cin.ignore(100,'\n');                               // clear input
            cout << "Invalid Column" << endl;
        }
        cout << player << " Player Select a row: ";             // prompt
        cin >> col;                                             // user input
        
        switch (col)                                            // check input
        {
        case 'A': case 'a': case 'B': case 'b': case 'C':
        case 'c': case 'D': case 'd': case 'E': case 'e':
        case 'f': case 'F': case 'G': case 'g':
            range = true;                                       // valid input was entered
            break;
        default:
            range = false;                                      // invalid input was entered
            break;
        }
    }while(cin.fail() || range == false);                       // conditon for loop

    col = tolower(col);                                         // convert char to lowercase

    return convCol(col);                                        // convert char to int for index of board
}

void printBoard(LL<bool> board[]){                              // function to print the board
    LL<bool>::Iterator it[7];                                   // set array of iterator objects
    int size[7];                                                // int array to hold size of each object

    for(int j = 0; j < 7; j++){                                 // loop through number of rows 
        for(int i = 0; i < 7; i++){                             // loop through number of columns
            if(j == 0)                                          // if current index is 0
                size[i] = 7 - board[i].size();                  // set the size of the column
            if(size[i] <= 0){                                   // if size of column is less than or equal to 0
                if(size[i] == 0)
                    it[i] = board[i].begin();                   // set iterator object to first node
                if(*it[i] == true)                              // if current data is true
                    cout << " R ";                              // output R for red player
                else if(*it[i] == false)                        // if current data is false
                    cout << " B ";                              // output B for blue player
                it[i]++;                                        // move to next node
            }
            else                                                // if there no data
                cout << " - ";                                  // output "-"
            size[i]--;                                          // decrement size by 1
        }
        cout << endl;
    }
    cout << endl;
    cout << " A  B  C  D  E  F  G " << endl << endl;
}

bool vecCheck(vector<bool> check){                              // compare items inside vector.
    int count = 0;
    for(int i = 0; i < check.size(); i++){                      // loop until end of vector
        if(i == check.size()-1 || check[i] != check[i+1])
            count = 0;                                          // reset count if items are not the same
        else
            count++;                                            // increment count if items are the same
        if(count == 3)                                          // return true if count reaches 3
            return true;
    }
    return false;                                               // else return false
}

bool checkWin(LL<bool> board[]){
    LL<bool>::Iterator it[7];                                   // holds iterator object for each row on board
    vector<bool> check;                                         // vector to store nodes that will be checked.

    // Vertical check
    for(int i = 0; i < 7; i++){                                 // loop through number of rows
        if(board[i].size() >= 4){
            it[0] = board[i].begin();                           // set iterator to beginning of current board object
            check.clear();                                      // clear check vector
            while(it[0] != board[i].end()){                     // store elements in column in check vector
                check.push_back(*it[0]);
                it[0]++;
            }
            if(vecCheck(check) == true){                        // if vector had 4 of the same elements in a row
                return true;                                    // return true
            }
        }
    }

    // Horizontal check
    for(int k = 6; k >= 0; k--){                                // loop through number of columns
        check.clear();                                          // clear check vector
        for(int i = 0; i < 7; i++){                             // loop through number of rows
            if(k == 6){                                         // set each iterator object to bottom of the board
                it[i] = board[i].end();
                it[i]--;
            }
            else
                it[i]--;                                        // move up one position in the board
            if(board[i].size() < abs(k-7))                      // if current column is smaller than current row index
                check.clear();
            else
                check.push_back(*it[i]);                        // store current node in check vector
            if(vecCheck(check) == true)                         // if vector had 4 of the same elements in a row
                return true;                                    // return true
        }
    }

    return false;                                               // else return false
}

int main(){
    int index;                                                  // index of board
    int full = 0;                                               // count occupied spaces on board
    bool red = true;                                            // sets the current player
    const int SEVEN = 7;                                        // constant int
    LL<bool> board[SEVEN];                                      // array of objects for the board

    printBoard(board);                                          // prints the board

    while(1){
        for(int i = 0; i < 7; i++)
            full += board[i].size();                            // checks if every space is full
        if(full == 49){
            cout << endl << "Tie." << endl;                     // output if game ends in draw
            break;                                              // break out of loop
        }
        else
            full = 0;                                           // reset space count
        if(red == true){                                        // if it is red players turn
            index = prompt("Red");
            if(board[index].size() < 7){                        // if column is not full
                board[index].headInsert(true);                  // insert true into board index
                red = false;                                    // change to blue players turn
                printBoard(board);                              // call function to print the board
            }
            else                                                // if column is full
                cout << "Invalid Move" << endl;                 // error prompt
        }
        else{                                                   // if it is blue players turn
            index = prompt("Blue");
            if(board[index].size() < 7){                        // if column is not full
                cout << endl;
                board[index].headInsert(false);                 // insert true into board index
                red = true;                                     // change to blue players turn
                printBoard(board);                              // call function to print the board
            }
            else                                                // if column is full
                cout << "Invalid Move" << endl;                 // error prompt
        }
        if(checkWin(board) == true){                            // if a player has won
            if(red == true)
                cout << "Blue wins!" << endl;                   // blue wins
            else if(red == false)
                cout << "Red wins!" << endl;                    // red wins
            break;
        }
    }

    return 0;
}
