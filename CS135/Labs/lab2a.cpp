/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment #: lab2a
 Description: output formulas
 input: none
 output: equations */
#include <iostream> //preprocessor directive
using namespace std;

int main(){
    const int a=5; //value for a
    int b=2; //value for b
    const double c=5.0; //value for c
    const double d=2.0; //value for d

    cout<< "5 + 2 = "; //statment
    cout<< a+b <<endl; //formula output

    cout<< "5 - 2 = ";//statement
    cout<< a-b <<endl;//formula output

    cout<< "5 * 2 = ";//statement
    cout<< a*b <<endl;//formula output

    cout<< "5 / 2 = ";//statement
    cout<< a/b <<endl;//formula output

    cout<< "5 % 2 = ";//statement
    cout<< a%b <<endl;//formula output

    cout<< "5.0 / 2.0 = ";//statement
    cout<< c/d <<endl;//formula output

    return 0;//return
}