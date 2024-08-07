// Name: Eduardo Salazar
// NSHE: 5005695833
// Assignment: 2
// Description: use recursion to find an optimal path in a 2d array map.
#include <iostream>
#include <fstream>
using namespace std;

int readFile(char[][7], ifstream&);
void printArr(char[][7]);
bool foo(char grid[][7], int, int, int);

int x_End;                                                              // global variable to hold the x end coordinate
int y_End;                                                              // global variable to hold the y end coordinate
int total_Count;                                                        // global to hold the total amount of spaces in the array

int main()
{
    char grid[7][7];
    int x_Start, y_Start;
    ifstream iFile;

    total_Count = readFile(grid, iFile);                                // call function to read file and set array

    cout << "Please enter starting coordinates: ";
    cin >> x_Start >> y_Start;
    
    cout << endl << "Please enter end coordinates: ";
    cin >> x_End >> y_End;
    cout << endl;

    if(foo(grid, x_Start, y_Start, 0) == true)
        printArr(grid);                                                 // call function to print array

    return 0;
}

bool foo(char grid[][7], int x, int y, int stepCounter)
{
    char incr = '0';                                                    // sets the offset to help print the stepcounter as a char
    if(stepCounter > 9)
        incr = '7';

    if(x == x_End && y == y_End && stepCounter+1 == total_Count){       // base case
        grid[x][y] = stepCounter + incr;
        return true;
    }

    if(x+1 < 7 && grid[x+1][y] == ' '){                                 // checks one space below
        grid[x][y] = stepCounter + incr;
        if(foo(grid, x+1, y, stepCounter+1) == false)
            grid[x][y] = ' ';                                           // resets current space back to blank if path was unsuccessful
        else
            return true;
    }
    
    if(x > 0 && grid[x-1][y] == ' '){                                   // checks one space above
        grid[x][y] = stepCounter + incr;
        if(foo(grid, x-1, y, stepCounter+1) == false)
            grid[x][y] = ' ';
        else
            return true;                                                // returns true if path was successful
    }

    if(y+1 < 7 && grid[x][y+1] == ' '){                                 // checks one space to the right
        grid[x][y] = stepCounter + incr;
        if(foo(grid, x, y+1, stepCounter+1) == false)
            grid[x][y] = ' ';
        else
            return true;
    }

    if(y > 0 && grid[x][y-1] == ' '){                                   // checks one space to the left
        grid[x][y] = stepCounter + incr;
        if(foo(grid, x, y-1, stepCounter+1) == false)
            grid[x][y] = ' ';
        else
            return true;
    }

    return false;                                                       // returns false if no paths were successful
}

int readFile(char grid[][7], ifstream& iFile)                           // function to read file and set array
{
    string fileName, text;
    int count = 0;                                                      // int to return count of spaces

    cout << "Enter config file: ";                                    // prompt to enter file name
    cin >> fileName;
    cout << endl;

    iFile.open(fileName);                                               // open file
    
    for(int i = 0; i < 7; i++)                                          // nested loop to read in file and set array
    {
        getline(iFile,text);                                            // get current line in file and set to text string
        for(int k = 0; k < 7; k++)
        {
            if(text[k] == '_')
                grid[i][k] = '_';
            else
            {
                grid[i][k] = ' ';
                count++;                                                // increment count if current char is a space
            }
        }
    }
    iFile.close();                                                      // close file

    return count;
}

void printArr(char grid[][7])                                           // function used to print array
{
    for(int i = 0; i < 7; i++)
    {
        for(int k = 0; k < 7; k++)
        {
            cout << grid[i][k] << " ";
        }
        cout << endl;
    }
}
