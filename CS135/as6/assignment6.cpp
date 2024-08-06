/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: assignment 6
 Description: input data from text file and output to terminal
 input: name of text file
 output: data from text file*/
#include <iostream> //preprocessor directive
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    
    ifstream inFile; 
    string fileName; //string to store file name
    string header; //string to read header
    double length=0; //length value placeholder
    double width=0; //width value placeholder
    double height=0; //height value placeholder
    double volume=0; //volume output placeholder
    double surfArea=0; //surface area output placeholder
    double diagonal=0; //diagonal value output placeholder
    double total_V_Crt=0; //total volume of crates
    double total_V_Strg=0; //total volume of storage room
    char type; //character variable to store crate or storage room
    bool isValid=true; 
    char cont;
    int a=2;
    int b=1;

    while (2>1){ //loop to come back to beggining if user wants to continue
    cout<<"Please enter the input file's name: "<<endl; //statement asking for file name
    cin>>fileName; //input file name
    cout<<endl;

    inFile.open(fileName); //open file

    while (!inFile.is_open()){ //loop if file does not open
        cout<<"The file name is wrong. Please try again."<<endl; //error statement
        cin.clear(); //clear input
        cin.ignore(1000,'\n'); //ignore characters
        cout<<"Please enter the input file's name: "<<endl; //statement asking for input
        cin>>fileName; //input file name
        cout<<endl;
        inFile.open(fileName); //open file
        }
    getline(inFile,header); //read header of text file

    cout<<"+-------+---------+--------+--------+------------+--------------+----------+"<<endl; 
    cout<<"| TYPE  | LENGTH  | WIDTH  | HEIGHT | VOLUME     | SURFACE AREA | DIAGONAL |"<<endl;
    cout<<"+-------+---------+--------+--------+------------+--------------+----------+"<<endl;

    while (!inFile.eof()){ 
        inFile>>type>>length>>width>>height; //input data into variables from text file
        isValid=true;
        switch (type){
            case 'C': //crate
                
                if (length>5 || length<1 || width>5 || width<1 || height>5 || height<1 ){ //crate restrictions
                    isValid=false;
                    break; 
                }
                // Volume = width * height * length
                volume=width*height*length;
                // Surface Area = 2(width * length + height * length + height * width)
                surfArea=2*(width*length+height*length+height*width);
                //Space diagonal = sqrt/length^2+width^2+height^2
                diagonal=sqrt(pow(length,2.0)+pow(width,2.0)+pow(height,2.0));

                total_V_Crt=total_V_Crt+volume; //calculating volume for valid crates
                break;
            case 'S': //storage room
                if (length>100 || length<10 || width>100 || width<10 || height>100 || height<10){ //storage restrictions
                    isValid=false;
                    break;
                }
                // Volume = width * height * length
                volume=width*height*length;
                // Surface Area = 2(width * length + height * length + height * width)
                surfArea=2*(width*length+height*length+height*width);
                //Space diagonal = sqrt/length^2+width^2+height^2
                diagonal=sqrt(pow(length,2.0)+pow(width,2.0)+pow(height,2.0));

                total_V_Strg=total_V_Strg+volume; //storage volume for valid rooms
                break;
            }

        cout<<fixed<<showpoint; //show decimal values
        if (isValid==true){
            cout<<"| "<<left<<setw(6)<<type<<"| "<<setw(8)<<setprecision(1)<<length<<"| ";
            cout<<setw(7)<<width<<"| "<<setw(7)<<height<<"| ";
            cout<<setw(11)<<volume<<"| "<<setw(13)<<surfArea<<"| "<<setw(9)<<diagonal<<"|"<<endl;
        }
        else { //if dimensions are invalid
            cout<<"| "<<left<<setw(6)<<type<<"| Inv     | Inv    | Inv    | ";
            cout<<"Inv        | Inv          | Inv      |"<<endl;
        }}

        cout<<"+-------+---------+--------+--------+------------+--------------+----------+"<<endl;
        cout<<"The total crate volume is:   ............................"<<total_V_Crt<<endl; //total crate volume
        cout<<"The total storage room volume is:  ......................"<<total_V_Strg<<endl; //total storage volume

        inFile.close(); //close file

        cout<<"Do you want to continue? (Y/N) : "<<endl; //statement asking if user wants to continue the program
        cin>>cont; //input yes or no
        cout<<endl;

        while (a>b){ 
            switch (cont){
                case 'Y':
                b=b+2;
                total_V_Crt=total_V_Crt-total_V_Crt;
                total_V_Strg=total_V_Strg-total_V_Strg;
                break;
                case 'y':
                b=b+2;
                total_V_Crt=total_V_Crt-total_V_Crt;
                total_V_Strg=total_V_Strg-total_V_Strg;
                break;
                case 'N':
                exit (0);
                break;
                case 'n':
                exit (0);
                break;
                default: //if input is not Y or N
                cout<<"Do you want to continue? (Y/N) : "<<endl;
                cin>>cont; //input yes or no again
                cout<<endl;
        }
        }
        if (b>a){ //reset value for b
            b=b-2;
        }
        
    }
    return 0;    
}