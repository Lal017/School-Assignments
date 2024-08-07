// Name: Eduardo Salazar
// NSHE: 5005695833
// Assignment: 3
// Description: use threading to add two large numbers together.
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

vector<short> prompt();                                             // prompts to enter a number as a string and stores in vector as a short
void print(vector<short>);                                          // prints out whats stored in a vector
void add(int,int);                                                  // adds two vectors together
void addCarry();                                                    // adds the carrys to the answer

vector<short> num1;                                                 // vector to store first number and also the answer
vector<short> num2;                                                 // vector to store second number
vector<short> carry;                                                // stores the carrys
bool front_Carry = false;                                           // sets true if there is a carry at the beggining of the vectors

int main()
{
    int digitCount;
    num1 = prompt();
    num2 = prompt();

    digitCount = num1.size() / 8;                                   // sets how many digits per thread to pass into the function

    for(int i = 0; i < num1.size(); i++)                            // populate the carry vector with 0s to match the size of the other vectors
        carry.push_back(0);
    
    thread T1(add, 0, digitCount-1);                                // thread functions
    thread T2(add, digitCount, digitCount*2-1);
    thread T3(add, digitCount*2, digitCount*3-1);
    thread T4(add, digitCount*3, digitCount*4-1);
    thread T5(add, digitCount*4, digitCount*5-1);
    thread T6(add, digitCount*5, digitCount*6-1);
    thread T7(add, digitCount*6, digitCount*7-1);
    thread T8(add, digitCount*7, digitCount*8-1);

    T1.join();                                                      // join threads
    T2.join();
    T3.join();
    T4.join();
    T5.join();
    T6.join();
    T7.join();
    T8.join();

    addCarry();                                                     // call function to add carrys

    if(front_Carry == true)                                         // increments vectors by 1 and adds a 1 to the begging of the vector
    {
        num1.push_back(0);
        for(int i = num1.size()-1; i > 0; i--)
            num1[i] = num1[i-1];
        num1[0] = 1;
    }

    cout << endl << "Result = ";
    print(num1);

    return 0;
}

void add(int i_Start, int i_End)
{
    short digit;
    short car = 0;

    for(int i = i_End; i >= i_Start; i--)                           // loop through the indexes passed to the function
    {
        digit = num1[i] + num2[i];                                  // adds the two numbers at the current index together
        if(car == 1)                                                // adds any carries from previous iterations
        {
            digit += car;
            car = 0;
        }
        if(digit > 9)                                               // if the number was larger than 9, set the carry and take the digit in the ones place
        {
            digit = digit % 10;
            car++;
        }
        num1[i] = digit;                                            // set the digit in the ones place without a carry
    }
    if(i_Start == 0 && car == 1)                                    // sets the front_carry bool to true to add a carry in main
        front_Carry = true;
    else if(car == 1)
        carry[i_Start-1] = car;
}

void addCarry()
{
    short digit;
    short car = 0;

    for(int i = num1.size()-1; i >= 0; i--)
    {
        digit = num1[i] + carry[i];
        if(car == 1)
        {
            front_Carry = true;
            digit += car;
            car = 0;
        }
        if(digit > 9)
        {
            digit = digit % 10;
            car++;
        }
        num1[i] = digit;
    }
}

vector<short> prompt()
{
    vector<short> vec;
    string num;

    cout << "Enter a number: ";
    cin >> num;
    cout << endl;

    for(int i = 0; i < num.length(); i++)                       // convert char numbers to ints
        vec.push_back(num[i] - '0');

    return vec;
}

void print(vector<short> vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i];

    cout << endl;
}