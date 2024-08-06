/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab 4b
 Description: outputs grade ranges
 input: letter grade
 output: range of letter grade*/
#include <iostream> //preprocessor directive
#include <iomanip>
using namespace std;

int main(){
    char letterGrade; //letter grade input placeholder

    cout<<"Enter a letter grade"<<endl; //statement before input
    cout<<"**";
    cin>>letterGrade; //input letter grade
    cout<<endl;

    switch (letterGrade){ //switch statement for letter grade
        case 'A': 
        cout<<"Grade range is 90 - 100"<<endl; //output if input is A
        break;
        case 'a':
        cout<<"Grade range is 90 - 100"<<endl; //output if input is a
        break;
        case 'B':
        cout<<"Grade range is 80 - 89.99"<<endl; //output if input is B
        break;
        case 'b':
        cout<<"Grade range is 80 - 89.99"<<endl; //output if input is b
        break;
        case 'C':
        cout<<"Grade range is 70 - 79.99"<<endl; //output if input is C
        break;
        case 'c':
        cout<<"Grade range is 70 - 79.99"<<endl; //output if input is c
        break;
        case 'D':
        cout<<"Grade range is 60 - 69.99"<<endl; //output if input is D
        break;
        case 'd':
        cout<<"Grade range is 60 - 69.99"<<endl; //output if input is d
        break;
        case 'F':
        cout<<"Grade range is 0 - 59.99"<<endl; //output if input is F
        break;
        case 'f':
        cout<<"Grade range is 0 - 59.99"<<endl; //output if input is f
        break;
        default:
        cout<<"Error: \'"<<letterGrade<<"\' is not a valid letter grade"<<endl; //output if none of the case requirements are met
    }
    return 0; //return
}