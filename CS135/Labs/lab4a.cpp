/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab 4a
 Description: identify which floating number and string is larger
 input: two floating numbers and two strings
 output: the largest floating number and string*/
#include <iostream> //preprocessor directive
using namespace std;

int main(){
    double firstNumber=0; //first number input placeholder
    double secondNumber=0; //second number input placeholder
    string firstString; //first string placeholder
    string secondString; //second string placeholder
    
    cout<<"Enter a floating point number"<<endl; //statement before floating number input
    cout<<"**"; 
    cin>>firstNumber; //first floating number input
    cout<<endl;

    cout<<"Enter another floating point number"<<endl; //statement before second floating number input
    cout<<"**";
    cin>>secondNumber; //second floating number input
    cout<<endl;

      if (firstNumber>secondNumber){ //output if first number is larger than second number
        cout<<"You entered "<<firstNumber<<" and "<<secondNumber<<endl; //statement repeating the two inputs
        cout<<"The largest is "<<firstNumber<<endl; //outputing the largest number
    }
    else if (firstNumber<secondNumber){ //output if second number is larger than first number
        cout<<"You entered "<<firstNumber<<" and "<<secondNumber<<endl; //statement repeating the two inputs
        cout<<"The largest is "<<secondNumber<<endl; //outputing the largest number
    }
    else { //output if numbers are equal
        cout<<"You entered "<<firstNumber<<" and "<<secondNumber<<endl; //statement repeating the two inputs
        cout<<"The largest is "<<secondNumber<<endl; //outputing the largest number
    }
    cout<<endl;
    cout<<"Enter a string"<<endl; //statement before inputing string
    cout<<"**";
    cin>>firstString; //input string
    cout<<endl;

    cout<<"Enter a second string"<<endl; //statement before inputing second string
    cout<<"**";
    cin>>secondString; //input second string
    cout<<endl;

    if (firstString>secondString){ //output if first string is larger than second string
        cout<<"You entered \""<<firstString<<"\" and \""<<secondString<<endl; //repeating both string inputs
        cout<<"The largest is \""<<firstString<<"\""<<endl; //outputing the largest string
    }
    else if(secondString>firstString){ //output if second string is larger than first string
        cout<<"You entered \""<<firstString<<"\" and \""<<secondString<<endl; //repeating both string inputs
        cout<<"The largest is \""<<secondString<<"\""<<endl; //outputing the largest string
    }
    else{ //output if strings are equal
        cout<<"You entered \""<<firstString<<"\" and \""<<secondString<<endl; //repeating both string inputs
        cout<<"The largest is \""<<secondString<<"\""<<endl; //outputing the largest string
    }
    return 0; //return
}