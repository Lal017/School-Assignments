/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment #: lab2b
 Description: input four numbers to output a set of different equations
 input: two integers and two doubles
 output: sets of equations*/
#include <iostream> //preprocessor directive
using namespace std;

int main(){
    long int intNum1=0; //first integer placeholder
    long int intNum2=0; //second integer placeholder
    long double intNum3=0.0; //first double placeholder
    long double intNum4=0.0; //second double placeholder

    cout<< "Enter an integer"<<endl; //statement before entering integer
    cout<<"**";
    cin>> intNum1;
    cout<<endl;

    cout<< "Enter another integer"<<endl; //statement before entering second integer
    cout<<"**";
    cin>> intNum2;
    cout<<endl;

    cout<< intNum1<<" + "<<intNum2<<" = "; //equation
    cout<< intNum1+intNum2<<endl; //output to equation

    cout<< intNum1<<" - "<<intNum2<<" = "; //equation
    cout<< intNum1-intNum2<<endl; //output to equation

    cout<< intNum1<<" * "<<intNum2<<" = "; //equation
    cout<< intNum1*intNum2<<endl; //output to equation

    cout<< intNum1<<" / "<<intNum2<<" = "; //equation
    cout<< intNum1/intNum2<<endl; //output to equation

    cout<< intNum1<<" % "<<intNum2<<" = "; //equation
    cout<< intNum1%intNum2<<endl; //output to equation
    cout<<endl;
    cout<< "Enter a double"<<endl; //statement before entering double
    cout<<"**";
    cin>> intNum3; 
    cout<<endl;

    cout<< "Enter another double"<<endl; //statement before entering second double
    cout<<"**";
    cin>> intNum4;
    cout<<endl;

    cout<< intNum3<<" / "<<intNum4<<" = "; //equation
    cout<< intNum3 / intNum4 <<endl; //output to equation
    return 0;

}