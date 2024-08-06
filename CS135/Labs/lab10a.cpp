/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab10a
 Description: output sum of rows and columns in array
 input: ifstream file
 output: sum of txt file*/
#include <iostream> //preprocessor directive
#include <fstream> //preprocessor directive
#include <iomanip> //preprocsessor directive
using namespace std;

const int rowCnt=7; //constant int row size
const int colCnt=10; //constant int column size

void openFile(ifstream&,string); //open file function
void readFile(ifstream&,double[][colCnt],int,int);
void rowSumCalculator(double[][colCnt],int,int);
void columnSumCalculator(double[][colCnt],int,int);

int main(){
    string prompt="Enter a file name\n**"; //prompt string
    double arr[rowCnt][colCnt]; //array size declaration
    ifstream inFile; //read in file

    openFile(inFile,prompt); //call open file function
    readFile(inFile,arr,rowCnt,colCnt); //call read file function
    rowSumCalculator(arr,rowCnt,colCnt); //call row sum function
    columnSumCalculator(arr,rowCnt,colCnt); //call column sum function

    return 0; //return 
}

void openFile(ifstream& inFile,string prompt){
    string fileName; //input file name
    const int thousand=1000;

    do{ //do loop
        cout<<prompt; //output prompt string
        cin>>fileName; //input file name
        cout<<endl;
        inFile.open(fileName); //open file
        if(!inFile.is_open()){ //if file is not open
            cout<<"Error: Invalid file name"<<endl; //error
            cin.clear(); //clear input
            cin.ignore(thousand,'\n');
        }
    }
    while(!inFile.is_open()); //do loop condition
}

void readFile(ifstream& inFile,double arr[][colCnt],int rowCnt, int colCnt){
    while(!inFile.eof()){ //while does not reach end of file
        for(int i=0; i<rowCnt; i++){
            for(int k=0; k<colCnt; k++){ //nested loop
                inFile>>arr[i][k]; //read in file to array
            }
        }
    }
}

void rowSumCalculator(double arr[][colCnt],int rowCnt,int colCnt){
    double total[7]={0,0,0,0,0,0,0}; //declare array for total

    for(int i=0; i<rowCnt; i++){
        for(int k=0; k<colCnt; k++){ //nested loop
            total[i]=total[i]+arr[i][k]; //add total of row
        }
    }
    cout<<"ROW SUMS:"<<endl;
    cout<<fixed<<showpoint; //show decimal value
    for(int i=0; i<rowCnt; i++){
        for(int k=0; k<colCnt; k++){ //nested loop
            cout<<left<<setw(4)<<setprecision(1)<<arr[i][k]; //output array
            if(k<9){
                cout<<" + ";
            }
        }
        cout<<" = "<<total[i]<<endl; //output total
    }
}

void columnSumCalculator(double arr[][colCnt],int rowCnt,int colCnt){
    double total[10]={0,0,0,0,0,0,0,0,0,0}; //declare array

    for(int i=0; i<colCnt; i++){
        for(int k=0; k<rowCnt; k++){ //nested loop
            total[i]=total[i]+arr[k][i]; //total for column
        }
    }
    cout<<endl;
    cout<<"COLUMN SUMS:"<<endl;
    cout<<fixed<<showpoint; //show decimal value
    for(int i=0; i<colCnt; i++){
        for(int k=0; k<rowCnt; k++){ //nested loop
            cout<<left<<setw(4)<<setprecision(1)<<arr[k][i]; //output array
            if(k<6){
                cout<<" + ";
            }
        }
        cout<<" = "<<total[i]<<endl; //output total
    }
}