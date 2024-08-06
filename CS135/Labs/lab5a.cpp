/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab5a
 Description: print out a range of numbers depending on the inputs
 input: starting number, ending number and increment number
 output: range between the start and end number depending on increment number*/
#include <iostream> //preprocessor directive
using namespace std;

int main(){
    int startNum=0; //start number placeholder
    int endNum=0; //end number placeholder
    int increment; 

    cout<<"Enter a starting Number"<<endl; //statement asking for input
    cout<<"**";
    cin>>startNum; //input starting number
    cout<<endl;

    if (cin.fail()){ //if input is invalid
        cout<<"Error: invalid entry."<<endl; //error statement
        exit (0); //exit the program
    }

    cout<<"Enter an ending number"<<endl; //statement asking for second number
    cout<<"**";
    cin>>endNum; //input ending number
    cout<<endl;

    if (cin.fail()){ //if input is invalid
        cout<<"Error: invalid entry."<<endl; //error statement
        exit (0); //quit program
    }
    else if (endNum<startNum){ //if end number is less than start number
        cout<<"Error: end must be greater than start."<<endl; //error statement
        exit (0); //exit program
    }

    cout<<"Enter a value to increment by"<<endl; //statement asking for increment
    cout<<"**";
    cin>>increment; //input increment
    cout<<endl;

    if (cin.fail()){ //if input is invalid
        cout<<"Error: invalid entry."<<endl; //error statement
        exit (0); //exit program
    }

    while (startNum<=endNum){ 
        cout<<startNum<<" "; //output starting number
        startNum=startNum+increment-1; //add increment
        startNum++; //increment starting number
    }
    cout<<endl;
    return 0; //return
}