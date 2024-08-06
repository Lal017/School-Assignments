/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab11b
 Description: output data from file to terminal
 input: data from csv file
 output: table with data*/
#include <iostream> //preprocessor directive
#include <fstream> //preprocessor directive
#include <string> //preprocessor directive
#include <iomanip> //preprocessor directive
using namespace std;

struct PurchaseType{ //struct
    string customerID; //customer
    string productName; //name of product
    double price; //price
    int qtyPurchased; //quantity
    double taxRate; //tax rate
};

const int size=10; //size of array

void openFile(ifstream&,string); //open file 
void readFile(ifstream&,PurchaseType[]); //read file
void printPurchaseData(PurchaseType[],int);

int main(){ //main function
    string prompt="Enter file name\n**";
    ifstream inFile; //declare ifstream
    PurchaseType purchase[size]; //struct

    openFile(inFile,prompt); //call function
    readFile(inFile,purchase); //call function
    printPurchaseData(purchase,size);

    return 0; //return
}

void openFile(ifstream& inFile,string prompt){
    string fileName; //input filename
    const int thousand=1000;

    do{ //do loop
        cout<<prompt;
        cin>>fileName; //input
        cout<<endl;
        inFile.open(fileName); //open file
        if(!inFile.is_open()){
            cout<<"Error: Invalid file"<<endl;
            cin.clear(); //clear input
            cin.ignore(thousand,'\n');
        }
    }
    while(!inFile.is_open()); //loop condition
}

void readFile(ifstream& inFile,PurchaseType purchases[]){
    string text; //getline string
    int i=0;
    int comma;

    while(!inFile.eof()){ //does not reach end of file
        getline(inFile,text); //get line
        comma=text.find(','); //find comma
        if(comma==-1){
            break; //exit loop
        }
        purchases[i].customerID=text.substr(0,comma);
        text=text.substr(comma+1,text.length());
        comma=text.find(',');
        purchases[i].productName=text.substr(0,comma);
        text=text.substr(comma+1,text.length());
        comma=text.find(',');
        purchases[i].price=stod(text.substr(0,comma));
        text=text.substr(comma+1,text.length());
        comma=text.find(',');
        purchases[i].qtyPurchased=stoi(text.substr(0,comma));
        text=text.substr(comma+1,text.length());
        comma=text.find(',');
        purchases[i].taxRate=stod(text.substr(0,comma));
        text=text.substr(comma+1,text.length());
        i++; //increment
    }
}

void printPurchaseData(PurchaseType purchases[],int size){
    double total[10]; //total array
    double average=0; //average double
    string prevUser; //holds previous user
    int userCount=1; //holds user count
    const int eight=8;
    const int hundred=100;
    const int eleven=11;
    const int twelve=12;
    const int five=5;
    const int six=6;

    cout<<"+-------------+--------------+----";
    cout<<"---+----------+----------+--------+"<<endl;
    cout<<"| Customer ID | Product Name ";
    cout<<"| Price | Quantity | Tax Rate | Total  |"<<endl;
    cout<<"+-------------+--------------+---";
    cout<<"----+----------+----------+--------+"<<endl;
    //header of table
    prevUser=purchases[0].customerID;
    for(int i=0; i<size; i++){ //for loop
        cout<<"| "<<setw(eleven)<<purchases[i].customerID<<" | ";
        cout<<setw(twelve)<<purchases[i].productName<<" | ";
        cout<<fixed<<showpoint; //show decimal value
        cout<<setw(five)<<setprecision(2)<<purchases[i].price<<" | ";
        cout<<setw(eight)<<purchases[i].qtyPurchased<<" | ";
        cout<<setw(eight)<<setprecision(2)<<purchases[i].taxRate*hundred<<" | ";
        total[i]=purchases[i].price*purchases[i].qtyPurchased*(purchases[i].taxRate+1);
        cout<<setw(six)<<setprecision(2)<<total[i]<<" |"<<endl;
        average=average+total[i];
        if(prevUser!=purchases[i].customerID){
            userCount++; //increment
        }
        prevUser=purchases[i].customerID;
    }
    average=average/size; //average total
    cout<<"+-------------+--------------+-------";
    cout<<"+----------+----------+--------+"<<endl;
    cout<<"Unique users:  "<<userCount<<endl; //output unique users
    cout<<"Average total: $"<<average<<endl; //output average
}