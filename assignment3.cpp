/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: assignment 3
 Description: create a chart that stores input and output data
input: length width and height of the crates and storage space output: volume, surface area, diagonal space, total crates*/
#include <iostream> //preprocessor directive
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    double length1=0.0; //crate length placeholder
    double height1=0.0; //crate height placeholder
    double width1=0.0; //crate width placeholder
    double length2=0.0; //storage length placeholder
    double height2=0.0; //storage height placeholder
    double width2=0.0; //storage width placeholder
    double volume1=0.0; //crate volume output placeholder
    double surfArea1=0.0; //crate surface area output placeholder
    double diag1=0.0; //crate diagonal space output placeholder
    double volume2=0.0; //storage volume output placeholder
    double surfArea2=0.0; //storage surface area output placeholder
    double diag2=0.0; //storage diagonal space output placeholder
    double total=0.0; //total placeholder

    cout<<"SHIPPING CRATE"<<endl; //title statement
    cout<<"Enter length of the shipping crate"<<endl; //statement before input
    cout<<"**";
    cin>>length1; //asking for crate length value
    cout<<endl;

    cout<<"Enter width of the shipping crate"<<endl; //statement before input
    cout<<"**";
    cin>>width1; //asking for crate width value
    cout<<endl;

    cout<<"Enter height of the shipping crate"<<endl; //statement before input
    cout<<"**";
    cin>>height1; //asking for crate height value
    cout<<endl;

    cout<<"STORAGE SPACE"<<endl; //title statement
    cout<<"Enter length of storage space"<<endl; //statement before input
    cout<<"**";
    cin>>length2; //asking for storage length value
    cout<<endl;

    cout<<"Enter width of storage space"<<endl; //statement before input
    cout<<"**";
    cin>>width2; //asking for storage width value
    cout<<endl;

    cout<<"Enter height of storage space"<<endl; //statement before input
    cout<<"**";
    cin>>height2; //asking for storage height value
    cout<<endl;

    //Volume = width * height * length
    volume1=width1*height1*length1; //crate volume formula
    volume2=width2*height2*length2; //storage volume formula
    //Surface area = 2(width * length + height * length + height * width)
    surfArea1=2*(width1*length1+height1*length1+height1*width1); //crate surface area formula
    surfArea2=2*(width2*length2+height2*length2+height2*width2); //storage surface area formula
    //Space diagonal = sqrt/length^2+width^2+height^2
    diag2=sqrt(pow(length2,2.0)+pow(width2,2.0)+pow(height2,2.0)); //storage diagonal space formula 
    diag1=sqrt(pow(length1,2.0)+pow(width1,2.0)+pow(height1,2.0)); //crate diagonal space formula
    //#ofshippingcrates = ( spaceL / crateL ) * ( spaceW / crateW ) * ( spaceH / crateH )
    total=floor((length2)/(length1))*floor((width2)/(width1))*floor((height2/height1)); //total crates formula
    cout<<endl;
    cout<<fixed<<showpoint; //showpoint to show decimal values
    cout<<"+-------+--------+-------+--------+-----------+--------------+----------+"<<endl; //chart lines
    cout<<"| TYPE  | LENGTH | WIDTH | HEIGHT |  VOLUME   | SURFACE AREA | DIAGONAL |"<<endl; //chart labels
    cout<<"+-------+--------+-------+--------+-----------+--------------+----------+"<<endl; //chart lines
    cout<<"| Crate "<<"| "<<left<<setw(7)<<setprecision(1)<<length1;
    cout<<"| "<<left<<setw(6)<<setprecision(1)<<width1;
    cout<<"| "<<left<<setw(7)<<setprecision(1)<<height1;
    cout<<"| "<<left<<setw(10)<<setprecision(1)<<volume1;
    cout<<"| "<<left<<setw(13)<<setprecision(1)<<surfArea1;
    cout<<"| "<<left<<setw(9)<<setprecision(1)<<diag1;
    cout<<"|"<<endl;
    cout<<"+-------+--------+-------+--------+-----------+--------------+----------+"<<endl; //chart lines
    cout<<"| Space "<<"| "<<left<<setw(7)<<setprecision(1)<<length2;
    cout<<"| "<<left<<setw(6)<<setprecision(1)<<width2;
    cout<<"| "<<left<<setw(7)<<setprecision(1)<<height2;
    cout<<"| "<<left<<setw(10)<<setprecision(1)<<volume2;
    cout<<"| "<<left<<setw(13)<<setprecision(1)<<surfArea2;
    cout<<"| "<<left<<setw(9)<<setprecision(1)<<diag2;
    cout<<"|"<<endl;
    cout<<"+-------+--------+-------+--------+-----------+--------------+----------+"<<endl; //chart lines
    cout<<endl;
    cout<<floor(total)<<" crates can fit in the storage space."<<endl; //total crates in storage statement
    return 0; //return 
}