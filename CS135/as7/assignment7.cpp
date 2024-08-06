/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: assignment 7
 Description: input data from txt file and output onto terminal or txt file
 input: data from txt file
 output: data onto terminal or another txt file*/
#include <iostream> //preprocessor directive
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    string line; //string placeholder
    string fileName; //filename placeholder
    string oFile; //filename placeholder
    string header; //header placeholder
    double strL; //storage length
    double strW; //storage width
    double strH; //storage height
    double crtL; //crate length
    double crtH; //crate height
    double crtW; //crate width
    double volume1; //crate volume
    double volume2; //storage volume
    double surfArea1; //crate surface area
    double surfArea2; //storage surface area
    double diag1; //crate diagonal
    double diag2; //storage diagonal
    double total; //total number of shipping crates
    double cratePrice; 
    double cubicFootPrice;
    int a=1;
    int b=2;
    int c=2;
    int d=1;
    int numOfLines=1; //number of lines read
    char selection;

    ifstream inFile;
    ofstream outFile;

    while (c>d){
        cout<<"***************************************"<<endl;
        cout<<"D/d - Display file data"<<endl;
        cout<<"F/f - File read - cratedata.txt"<<endl;
        cout<<"Q/q - Quit the program"<<endl;
        cout<<"***************************************"<<endl;
        while (a<b){
            cout<<"Enter your selection"<<endl;
            cin>>selection; //input selection
            cout<<endl;

            switch (selection){ //switch for different selections
                case 'D': //display data
                cout<<"Enter the filename to open: "; //statement
                a=a+1;
                break;
                case 'd': //display data
                cout<<"Enter the filename to open: "; //statement
                a=a+1;
                break;
                case 'F': //read file
                cout<<"You selected F"<<endl;
                a=a+2;
                break;
                case 'f': //read file
                cout<<"You selected f"<<endl;
                a=a+2;
                break;
                case 'Q': //quit program
                exit (0); //exit
                break;
                case 'q': //quit program
                exit (0); //exit
                break;
                default:
                cout<<"Error: please try again"<<endl; //error statement
                cin.clear(); //clear error input
                cin.ignore(1000,'\n');
            }
        }

        if (a==b){
            cin>>fileName; //input filename
            inFile.open(fileName); //open file
            while (!inFile.is_open()){ //while file is not open
                cout<<"Please enter filename to open: ";
                cin.clear(); //clear failed input
                cin.ignore(1000,'\n');
                cin>>fileName; //input filename again
                inFile.open(fileName); //open file
                cout<<endl;
            }

            cout<<"#################################"<<endl;
            cout<<"File Opened Succesfully"<<endl;
            cout<<"#################################"<<endl;
            while (!inFile.eof()){ //while does not reach end of file
                getline(inFile,line); //getline for each line
                cout<<line<<endl; //output each line
            }
            a=a-1;
        }
        else if (a>b){
            cout<<"Please enter crateStorage file: ";
            cin>>fileName; //input filename
            cout<<endl;
            inFile.open(fileName); //open file
            while (!inFile.is_open()){ //while file is not open
                cout<<"Please enter crateStorage file: "; 
                cin.clear(); //clear failed input
                cin.ignore(1000,'\n');
                cin>>fileName; //input file name
                inFile.open(fileName); //open file
                cout<<endl;
            }
            getline(inFile,header); //getline for header
            cout<<"#################################"<<endl;
            cout<<"File Opened Succesfully"<<endl;
            cout<<"#################################"<<endl;
            oFile="outputfile_of_"; //declare oFile string
            outFile.open(oFile+fileName); //open file

            while (!inFile.eof()){
                outFile<<"Dataset: "<<numOfLines<<endl; //display number of lines
                outFile<<"LC            WC            HC            LS            WS            ";
                outFile<<"HS            CV            CS            CD            SV            ";
                outFile<<"SS            SD            Total Cost"<<endl;
                outFile<<fixed<<showpoint<<setprecision(1); //show decimal values

                inFile>>crtL; 
                if (inFile.fail()){ //if input fails
                    outFile<<"Error: invalid crate length"<<endl;
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else if (crtL<1 || crtL>5){
                    outFile<<"Error: invalid crate length"<<endl; //error statement
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile>>crtW>>crtH>>strL>>strW>>strH; //input other variables in same line
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else {
                    outFile<<left<<setw(14)<<crtL; //output if no errors
                }
                inFile>>crtW;
                if (inFile.fail()){ //if input fails
                    outFile<<"Error: invalid shipping crate width"<<endl;
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else if (crtW<1 || crtW>5){
                    outFile<<"Error: invalid shipping crate width"<<endl; //error statement
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile>>crtH>>strL>>strW>>strH; //input other variables in line
                    inFile.clear(); //clear failed inputs
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else {
                    outFile<<left<<setw(14)<<crtW; //output if no errors
                }
                inFile>>crtH;
                if (inFile.fail()){ //if input fails
                    outFile<<"Error: invalid shipping crate height"<<endl;
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else if (crtH<1 || crtH>5){
                    outFile<<"Error: invalid shipping crate height"<<endl; //error statement
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile>>strL>>strW>>strH; //input other variables in line
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else {
                    outFile<<left<<setw(14)<<crtH; //output if no errors
                }
                inFile>>strL;
                if (inFile.fail()){ //if input fails
                    outFile<<"Error: invalid storage length"<<endl;
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else if (strL<10 || strL>100){
                    outFile<<"Error: invalid storage length"<<endl; //error statement
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile>>strW>>strH; //input other variables in line
                    inFile.clear(); //clear failed inputs
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else {
                    outFile<<left<<setw(14)<<strL; //output if no errors
                }
                inFile>>strW;
                if (inFile.fail()){ //if input fails
                    outFile<<"Error: invalid storage width"<<endl;
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else if (strW<10 || strW>100){
                    outFile<<"Error: invalid storage width"<<endl; //error statement
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile>>strH; //input other variables in line
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else {
                    outFile<<left<<setw(14)<<strW; //output if no errors
                }
                inFile>>strH;
                if (inFile.fail()){ //if input fails
                    outFile<<"Error: invalid storage height"<<endl;
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile.clear(); //clear failed input
                    inFile.ignore(1000,'\n');                   
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else if (strH<10 || strH>100){
                    outFile<<"Error: invalid storage height"<<endl; //error statement
                    outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
                    inFile.clear(); //clear loop
                    inFile.ignore(1000,'\n');
                    numOfLines=numOfLines+1;
                    continue; //restart loop
                }
                else {
                    outFile<<left<<setw(14)<<strH; //output if no errors
                }

                if (!inFile.fail()){ //if input does not fail
                    
                    //Volume = width * height * length
                    volume1=crtW*crtH*crtL;
                    volume2=strW*strH*strL;
                    //Surface area = 2(width * length + height * length + height * width)
                    surfArea1=2*(crtW*crtL+crtH*crtL+crtH*crtW);
                    surfArea2=2*(strW*strL+strH*strL+strH*strW);
                    //Space diagonal = sqrt/length^2+width^2+height^2
                    diag1=sqrt(pow(crtL,2.0)+pow(crtW,2.0)+pow(crtH,2.0)); 
                    diag2=sqrt(pow(strL,2.0)+pow(strW,2.0)+pow(strH,2.0));
                    //#ofshippingcrates = ( spaceL / crateL ) * ( spaceW / crateW ) * ( spaceH / crateH )
                    total=floor((strL/crtL))*floor((strW/crtW))*floor((strH/crtH));
    
                    outFile<<left<<setw(14)<<volume1<<setw(14)<<surfArea1<<setw(14)<<diag1<<setw(14)<<volume2<<setw(14)<<surfArea2;
                    outFile<<left<<setw(14)<<diag2<<setw(14)<<total<<endl;
                    outFile<<"---------+---------+---------+---------+---------+---------+----------+----------+"<<endl;

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
                    outFile<<"Crate volume "<<setprecision(2)<<volume1<<" and the cost per crate...................$"<<cratePrice<<endl;
                    outFile<<"Price to ship "<<total<<" crates...................................$"<<cratePrice*total<<endl;
                    outFile<<"Storage rooms with volume "<<volume2<<" and the cost per cubic foot................$"<<cubicFootPrice<<endl;
                    outFile<<volume2<<" cubic feet storage room cost.................$"<<volume2*cubicFootPrice<<endl;
                    outFile<<"Total cost...........................................$"<<(cratePrice*total)+(volume2*cubicFootPrice)<<endl;
                    outFile<<"---------+---------+---------+---------+---------+---------+----------+----------+"<<endl;
                }
                numOfLines=numOfLines+1; //add number of lines
            }
            a=a-2;
            outFile.close(); //close file
        }
        inFile.close(); //close file
    }
    return 0; //return
}