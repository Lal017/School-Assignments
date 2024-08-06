/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab9a
 Description: output numbers from an array
 input: txt file into array
 output: data from array*/
#include <iostream> //preprocessor directive
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    string fileName; //file name string
    double array[100]; //array
    int total=0; //total inputs
    int i=0;
    int thousand=1000;
    ifstream inFile; //input stream
    double sum; //sum of inputs
    double smallest=0; //smallest value
    double largest; //largest value
    int arrayLength=0; 
    int arrayLength2;
    double failedInput=0;

    do{ //do loop for input
        cout<<"Enter a file name"<<endl;
        cout<<"**";
        cin>>fileName; //input file name
        cout<<endl;
        inFile.open(fileName); //open file
        if (!inFile.is_open()){ //if file is not open
            cout<<"Error: Invalid file name."<<endl; //error
            inFile.clear(); //clear input
            inFile.ignore(thousand,'\n');
        }}
    while(!inFile.is_open()); //while file is not open

    while(!inFile.eof()){ //while does not reach end of file
        inFile>>array[i]; //input into array
        i++; //increment
        if (inFile.fail()){
            inFile.clear(); //clear input
            inFile.ignore(thousand,'\n');
            failedInput=failedInput+1;
        }
        else{
            total=total+1; //total
        }
        arrayLength=arrayLength+1;
    }
    arrayLength=arrayLength-1;
    arrayLength2=arrayLength-1;
    
    for(int f=0; f<arrayLength; f++){ //sum of array
        sum=sum+array[f];
    }
    smallest=array[0];
    for(int c=0; c<arrayLength; c++){ //smallest value
        if(smallest>array[c] && array[c]!=0){
            smallest=smallest-smallest;
            smallest=smallest+array[c];
        }
    }
    for(int d=0; d<arrayLength; d++){ //largest value
        if(largest<array[d]){
            largest=array[d];
        }
    }
    for(int g=1; g<failedInput; g++){
        cout<<"Error: Invalid input in file."<<endl; //error statement
    }
    cout<<endl;
    cout<<fixed<<showpoint;
    cout<<"Amount of elements read in: "<<setprecision(2)<<total<<endl; 
    cout<<"Forwards: "; 
    for(int a=0; a<arrayLength;a++){ //read array forwards
        if(array[a]!=0){
            cout<<setprecision(2)<<array[a];
            if(a<arrayLength2){
            cout<<", ";
            }
        }
    }
    cout<<endl;
    cout<<"Backwards: ";
    for(int b=arrayLength2; b>=0;b=b-1){ //read array backwards
        if(array[b]!=0){
            cout<<setprecision(2)<<array[b];
            if(b>0){
            cout<<", ";
            }
        }
    }
    cout<<endl;
    cout<<"Minimum: "<<setprecision(2)<<smallest<<endl; //minimum value
    cout<<"Maximum: "<<setprecision(2)<<largest<<endl; //maximum value
    cout<<"Sum: "<<setprecision(2)<<sum<<endl; //sum of array
    cout<<"Average: "<<setprecision(2)<<sum/total<<endl; //average 
    return 0; //return 
}