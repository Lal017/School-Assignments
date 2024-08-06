/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab10b
 Description: output low and high temperatures
 input: ifstream file
 output: average of temperatures*/
#include <iostream> //preprocessor directive
#include <fstream> //preprocessor directive
#include <iomanip>
using namespace std;

const int two=2; //const int value

void openFile(ifstream&,string); //open file function
void readFile(ifstream&,double[][two],int,int); //read file
float lowestTemp(double[][two],int,int); //find lowest temperature
float highestTemp(double[][two],int,int); //find highest temperature
float averageLowTemp(double[][two],int,int); //find average temperature
float averageHighTemp(double[][two],int,int); //find average temperature

int main(){
    string prompt="Enter file name\n**"; //prompt string
    ifstream inFile; //read infile
    const int rowCnt=12; //row int
    const int colCnt=2; //column int
    double arr[12][2]; //array decleration

    openFile(inFile,prompt); //call open file function
    readFile(inFile,arr,rowCnt,colCnt); //call read file function

    cout<<fixed<<showpoint; //show decimal values
    cout<<"Lowest temperature of the year was ";
    cout<<setprecision(2)<<lowestTemp(arr,rowCnt,colCnt)<<"° F."<<endl;
    cout<<"Highest temperature of the year was ";
    cout<<setprecision(2)<<highestTemp(arr,rowCnt,colCnt)<<"° F."<<endl;
    cout<<"Average low temperature of the year was ";
    cout<<averageLowTemp(arr,rowCnt,colCnt)<<"° F."<<endl;
    cout<<"Average high temperature of the year was ";
    cout<<averageHighTemp(arr,rowCnt,colCnt)<<"° F."<<endl;

    return 0; //return 
}

void openFile(ifstream& inFile,string prompt){
    string fileName; //input file name
    const int thousand=1000;
    
    do{ //do loop
        cout<<prompt;
        cin>>fileName; //input file name
        cout<<endl;
        inFile.open(fileName); //open file
        if(!inFile.is_open()){
            cout<<"Error: Invalid file name"<<endl; //error
            cin.clear(); //clear input
            cin.ignore(thousand,'\n');
        }
    }
    while(!inFile.is_open()); //do loop condition
}

void readFile(ifstream& inFile,double arr[][two],int rowCnt,int colCnt){
    string header; //header string
    getline(inFile,header); //get header
    cout<<header<<endl; //output header

    for(int i=0; i<rowCnt; i++){
        for(int k=0; k<colCnt; k++){
            inFile>>arr[i][k]; //read into array
        }
    }
}

float lowestTemp(double arr[][two],int rowCnt,int colCnt){
    float found=arr[0][0]; //return value

    for(int i=0; i<rowCnt; i++){
        if(arr[i][0]<found){
            found=arr[i][0]; //new return value
        }
    }
    return found; //return
}

float highestTemp(double arr[][two],int rowCnt,int colCnt){
    float found=arr[0][1]; //return value

    for(int i=0; i<rowCnt; i++){
        if(arr[i][1]>found){
            found=arr[i][1]; //new return value
        }
    }
    return found; //return
}

float averageLowTemp(double arr[][two],int rowCnt,int colCnt){
    double sum; //sum double
    float total; //return float

    for(int i=0; i<rowCnt; i++){
        sum=sum+arr[i][0]; //add values into sum
    }
    total=sum/rowCnt; //divide sum by row count
    
    return total; //return
}

float averageHighTemp(double arr[][two],int rowCnt,int colCnt){
    double sum; //sum double
    float total; //return float

    for(int i=0; i<rowCnt; i++){
        sum=sum+arr[i][1]; //add values into sum
    }
    total=sum/rowCnt; //divide sum by row count

    return total; //return
}