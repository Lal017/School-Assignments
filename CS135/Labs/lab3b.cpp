/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab3b
 Description: find the circumference and area using the radius of a circle.
 input: radius of a circle
 output: circumference and area of a circle*/
#include <iostream> //preprocessor directive
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    const double pi=3.141592; //value for pi
    double radius=0.0; //radius input placeholder
    const double two=2.0; //value for 2
    double circumference=0.0; //circumference output placeholder
    double area=0.0; //area output placeholder
    const int seven=7; //value for 7
    const int fourteen=14; //value for 14
    const int eight=8; //value for 8

    cout<<"Enter the radius of a circle"<<endl; //statement before input
    cout<<"**";
    cin>>radius; //input radius
    cout<<endl;

    //circumference=2*pi*radius
    circumference=two*pi*radius; //formula for circumference
    //area=pi*radius^2
    area=pi*(pow(radius,two)); //formula for area

    cout<<fixed<<showpoint; //showpoint to show decimal values
    cout<<"+--------+---------------+---------+"<<endl; //chart lines
    cout<<"| radius | circumference | area    |"<<endl; //chart headers
    cout<<"+--------+---------------+---------+"<<endl; //chart lines
    cout<<"| ";
    cout<<left<<setw(seven)<<setprecision(2)<<radius; //display radius value with 2 decimal placements
    cout<<"| ";
    cout<<left<<setw(fourteen)<<circumference; //display circumference value with 2 decimal placements
    cout<<"| ";
    cout<<left<<setw(eight)<<area; //display area value with 2 decimal placments
    cout<<"|"<<endl;
    cout<<"+--------+---------------+---------+"<<endl; //chart lines
    return 0; //return

}