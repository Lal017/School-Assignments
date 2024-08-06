/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: assignment 4
 Description: create a chart that stores input and outputs data and prices for customers
 input: length width and height of the crates and storage space 
 output: volume, surface area, diagonal space, total crates and prices*/
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
    double cratePrice=0.0; //crate price placeholder
    double cubicFootPrice=0.0; //cubic foot price placeholder


    cout<<"SHIPPING CRATE"<<endl; //title statement
    cout<<"Enter length of the shipping crate"<<endl; //statement before input
    cout<<"**";
    cin>>length1; //asking for crate length value
    cout<<endl;

    if(length1>=1 && length1<=5){
        length1=length1;
    }
    else{
        cout<<"Error, must enter a number between 1 and 5"<<endl; //error message
        exit(0); //exits the program
    }

    cout<<"Enter width of the shipping crate"<<endl; //statement before input
    cout<<"**";
    cin>>width1; //asking for crate width value
    cout<<endl;

      if(width1>=1 && width1<=5){
        width1=width1;
    }
    else{
        cout<<"Error, must enter a number between 1 and 5"<<endl; //error message
        exit(0); //exits the program
    }

    cout<<"Enter height of the shipping crate"<<endl; //statement before input
    cout<<"**";
    cin>>height1; //asking for crate height value
    cout<<endl;

      if(height1>=1 && height1<=5){
        height1=height1; //true statement placeholder
    }
    else{
        cout<<"Error, must enter a number between 1 and 5"<<endl; //error message
        exit(0); //exits the program
    }

    cout<<"STORAGE SPACE"<<endl; //title statement
    cout<<"Enter length of storage space"<<endl; //statement before input
    cout<<"**";
    cin>>length2; //asking for storage length value
    cout<<endl;

      if(length2>=10 && length2<=100){
        length2=length2; //true statement placeholder
    }
    else{
        cout<<"Error, must enter a number between 1 and 5"<<endl; //error message
        exit(0); //exits the program
    }

    cout<<"Enter width of storage space"<<endl; //statement before input
    cout<<"**";
    cin>>width2; //asking for storage width value
    cout<<endl;

      if(width2>=10 && width2<=100){
        width2=width2;
    }
    else{
        cout<<"Error, must enter a number between 1 and 5"<<endl; //error message
        exit(0); //exits the program
    }

    cout<<"Enter height of storage space"<<endl; //statement before input
    cout<<"**";
    cin>>height2; //asking for storage height value
    cout<<endl;

      if(height2>=10 && height2<=100){

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
    cout<<endl;

        if (volume1>=1 && volume1<=40){
            cratePrice=2.50; //new crate value
            
        }
        else if(volume1>40 && volume1<=80){
            cratePrice=3.00; //new crate value
        }
        else if(volume1>80){
            cratePrice=3.50; //new crate value
        }

        if (volume2>=1000 && volume2<=250000){
            cubicFootPrice=0.12; //new cubic foot price value
        }
        else if(volume2>250000 && volume2<=500000){
            cubicFootPrice=0.09; //new cubic foot price value
        }
        else if(volume2>500000 && volume2<=750000){
            cubicFootPrice=0.07; //new cubic foot price value
        }
        else if(volume2>750000){
            cubicFootPrice=0.05; //new cubic foot price value
        }
    cout<<fixed<<showpoint; //show decimal values
    cout<<"Crate volume "<<setw(7)<<setprecision(2)<<volume1<<"cost................................$"<<cratePrice<<" per crate"<<endl; //outputs volume and crate price values
    cout<<"Price to ship "<<setw(8)<<total<<"crates............................$"<<cratePrice*total<<endl; //outputs total crates and total price for the crates.
    cout<<endl;
    cout<<"Storage rooms with volume "<<setw(11)<<volume2<<"cost...............$"<<cubicFootPrice<<" per cubic foot"<<endl; //outputs volume and cubic foot price
    cout<<setw(11)<<volume2<<"cubic feet storage room cost.................$"<<volume2*cubicFootPrice<<endl; //outputs volume and price for storage room per cubic foot total cost
    cout<<endl;
    cout<<"Total cost..............................................$"<<(cratePrice*total)+(volume2*cubicFootPrice)<<endl; //outputs total cost of both equations
      }
    else{
        cout<<"Error, must enter a number between 1 and 5"<<endl; //error message 
        exit(0); //exits the program
    }

    return 0; //return 
}
