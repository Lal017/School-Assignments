/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab7b
 Description: calculate circumference and area
 input: radius
 output: circumference and area*/
#include <iostream> //preprocessor directive
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;

double getDoubleInput(string,double,double); //double function prototype
bool checkFailure(double,double,double); //bool function prototype
double circumference(double); //double function prototype
double area(double); //double function prototype

int main(){ //main function
    string prompt="Enter a circle radius between 0.500000 and 20.500000\n**";
    const double min=0.5; //min value 
    const double max=20.5; //max value
    double radius; //radius 
    double cir; //circumference
    double area1; //area

    radius=getDoubleInput(prompt,min,max); //call function 
    cir=circumference(radius); //call circumferenece function
    area1=area(radius); //call area function
    
    cout<<fixed<<showpoint; //show decimal values
    cout<<"Radius: "<<setprecision(2)<<radius<<endl; //output radius
    cout<<"Circumference: "<<cir<<endl; //output circumference
    cout<<"Area: "<<area1<<endl; //output area
    return 0; //return
}

double getDoubleInput(string prompt,double min,double max){
    double radius; 
    bool check;
    do{ //do loop
        cout<<prompt; //output string
        cin>>radius; //input radius
        cout<<endl;
        check=checkFailure(radius,min,max); //call check function
    }
    while (check==false); //condition
    return radius; //return the radius
}

bool checkFailure(double input,double min, double max){
    const int thousand=1000;
    if (cin.fail()){ //if input fails
        cin.clear(); //clear input
        cin.ignore(thousand,'\n');
        cout<<"Error: Invalid radius!"<<endl; //error
        return false; //return false
    }
    else if(input<min || input>max){
        cin.clear(); //clear input
        cin.ignore();
        cout<<"Error: Invalid radius!"<<endl; //error
        return false; //return false
    }
    else{
        return true; //return true
    }
}

double circumference(double radius){
    double circumference=0; 
    const double pi=3.14159; //value for pi
    circumference=2*pi*radius; //circumeference equation
    return circumference; //return circumeference
}

double area(double radius){
    double area=0; 
    const double two=2.0;
    const double pi=3.14159; //value for pi
    area=pi*pow(radius,two); //area equation
    return area; //return area
}