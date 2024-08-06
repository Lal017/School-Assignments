/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment #: Assignment 2
 Description: calculate the parameters of a ship 
 input: Length, width and height of the ship 
 output: Sea surface area and volume of the ship*/
#include <iostream>
#include <cmath>
using namespace std;
//Volume - 4/3*pi*w*h*l
//Area - pi*w*h
int main()
{
    double pi=3.14159265358;//pi value
    double w=0.0;//place holder for width
    double h=0.0;//place holder for height
    double l=0.0;//place holder for length
    double a=1.3333333333333333;//value for 4/3
    double y=0.0;//output statement for volume
    double z=0.0;//output statement for area

    cout <<"***************"<<endl;
    cout <<"Ship Calculator"<<endl;//intro message
    cout <<"***************"<<endl;

    cout <<"Enter the width of the ship:";
    cin >>w;
    cout <<endl;

    cout <<"Enter the length of the ship:";
    cin >>l;
    cout <<endl;

    cout <<"Enter the height of the ship:";
    cin >>h;
    cout <<endl;

    y=a*pi*w*h*l;//formula for volume
    z=pi*w*l;//formula for area

    cout <<"Results"<<endl;
    cout <<"Calculations for a ship:"<<w<<"W x "<<l<<"L x "<<h<<"H"<<endl; //statement with dimensions of the ship
    cout <<"Sea surface area:"<<z<< " square feet"<<endl; //output statement and value for sea surface area
    cout <<"Volume is:"<<y<< " cubic feet"<<endl; //output statement and value for volume

    cout <<"Thank you for using the Ship Calculator"<<endl;//thank you message.
    return 0; //return
}