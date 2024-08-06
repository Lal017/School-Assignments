/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab3a
 Description: convert degrees to radians and output the sin cos and tan of that degree.
input: angle value in degrees output: radians, sin, cos and tan of a degree*/
#include <iostream> //preprocessor directive
#include <cmath>
using namespace std;

int main()
{
    double degree=0.0; //degree input placeholder
    double radians=0.0; //radians output placeholder
    const double pi=3.141592; //value for pi
    const int I80=180; //value for 180
    double sin1=0.0; //sin output placeholder
    double cos1=0.0; //cos output placeholder
    double tan1=0.0; //tan output placeholder

    cout<<"Enter an angle value, in degrees"<<endl; //statement before degrees input
    cout<<"**";
    cin>>degree; //input for degrees
    cout<<endl;

    radians=degree*pi/I80; //degrees to radians conversion formula
    sin1=sin(radians); //sin formula
    cos1=cos(radians); //cos formula
    tan1=tan(radians); //tan formula

    cout<<degree<<" degrees = "<<radians<<" radians"<<endl; //output statment for degrees and radians
    cout<<"sin("<<degree<<") = "<<sin1<<endl; 
    cout<<"cos("<<degree<<") = "<<cos1<<endl;
    cout<<"tan("<<degree<<") = "<<tan1<<endl;
    return 0; //return
}