/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab6b
 Description: check for input failstate
 input: text files
 output: numbers in text file and total of numbers*/
#include <iostream> //preprocessor directive
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    string fileName; //string for file name
    double firstNum=0; //first number placeholder
    double secondNum=0; //second number placeholder
    double thirdNum=0; //third number placeholder
    double total=0; //total number placeholder
    const int thousand=1000;
    ifstream inFile; 

    cout<<"Enter file name"<<endl; //statement before input
    cout<<"**"; 
    cin>>fileName; //input file name
    cout<<endl;

    inFile.open(fileName); //open file

    while (!inFile.is_open()){ //loop if file is not open
        cout<<"Error: Invalid file name"<<endl; //error 
        cin.clear(); //clear input
        cin.ignore(thousand,'\n'); //ignore input characters
        cout<<"Enter file name"<<endl; 
        cout<<"**";
        cin>>fileName; //input again
        cout<<endl;
        inFile.open(fileName); //open file
    }

    while (!inFile.eof()){ //loop until reaches end of file
        inFile>>firstNum>>secondNum; //input numbers into doubles
        if (inFile.fail()){ //if input fails
            cout<<"Error in line"<<endl; //error
            inFile.clear(); //clear input
            inFile.ignore(thousand,'\n'); //ignore input characters
        }
        else { //if input does not fail
            thirdNum=firstNum+secondNum; //formula for sum of two numbers
            cout<<fixed<<setprecision(0);
            cout<<firstNum<<" + "<<secondNum<<" = "<<thirdNum<<endl;
            total=total+thirdNum; //add sum to total
        }
    }
    cout<<endl;
    cout<<fixed;
    cout<<"Running total = "<<setprecision(0)<<total<<endl; //output total

    return 0; //return
}