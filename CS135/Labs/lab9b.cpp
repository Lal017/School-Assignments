/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab9b
 Description: output names, scores and average
 input: file name and student name
 output: names, scores and average score*/
#include <iostream> //preprocessor directive
#include <fstream> //preprocessor directive
using namespace std;

const int hundred=100; //constant int
const int thousand=1000; //constant int

void readFile(ifstream&,string[hundred],double[hundred],int&); 
//reads file
void print(double[hundred],int&); //print function
void print(string[hundred],int&); //print function
void printReverse(double[hundred],int&); //print backwards function
void printReverse(string[hundred],int&); //print backwards function
double averageScore(string,string[hundred],double[hundred],int); 
//calculates average

int main(){
    string fileName; //enter file name
    string studentName; //enter students name
    string name[hundred]; //array of names
    double num[hundred]; //array of scores
    int count=-1;
    double average; //holds average

    ifstream inFile; 

    do{
        cout<<"Enter a file name"<<endl; 
        cout<<"**";
        cin>>fileName; //input filename
        cout<<endl; //newline
        inFile.open(fileName); //open file
        if(!inFile.is_open()){ //if infile is not open
            cout<<"Error: Invalid file name."<<endl; //error
            cin.clear(); //clear input
            cin.ignore(thousand,'\n'); //ignore input
        }
    }
    while(!inFile.is_open()); //do loop condition

    cout<<"Enter a student's name to"<<endl;
    cout<<" find the average score of"<<endl;
    cout<<"**";
    cin>>studentName; //input students name
    cout<<endl;

    readFile(inFile,name,num,count); //call read file function
    print(name,count); //call printing function
    print(num,count); //call printing function
    printReverse(name,count); //call backwards print function
    printReverse(num,count); //call backwards print function
    average=averageScore(studentName,name,num,count);
    //call average score function
    if(average!=-1){
        cout<<"Average score for "<<studentName<<": "; 
        //output average score statement
        cout<<fixed<<showpoint; //show decimal values
        cout<<average<<endl; //output average score
    }
    else{
        cout<<"Error: "<<studentName; //error
        cout<<" is not a student in the list"<<endl;
        //error
    }

    return 0;
}

void readFile(ifstream & iFile,string arr[],double scores[],int & count){
    int i=0;
    while(!iFile.eof()){ //while does not reach end of file
        iFile>>arr[i]>>scores[i];
        i++; //increment
        count=count+1; //counter
    }
    iFile.close(); //close file
}

void print(string arr[],int & count){
    int count2;

    count2=count-1;

    cout<<"Names Forward: "; 
    for(int i=0; i<count; i++){
        cout<<arr[i]; //print array of names
        if(i<count2){
            cout<<", ";
        }
    }
    cout<<endl;
}

void print(double arr[],int & count){
    int count2;

    count2=count-1;

    cout<<"Scores Forward: ";
    for(int i=0; i<count; i++){
        cout<<arr[i]; //print array of scores
        if(i<count2){
            cout<<", ";
        }
    }
    cout<<endl;
}

void printReverse(string arr[],int & count){
    cout<<"Names Reverse: ";
    for(int i=count-1; i>=0; i=i-1){
        cout<<arr[i]; //print array of names 
        if(i>0){
            cout<<", ";
        }
    }
    cout<<endl;
}

void printReverse(double arr[],int & count){
    cout<<"Scores Reverse: ";
    for(int i=count-1; i>=0; i=i-1){
        cout<<arr[i]; //print array of scores
        if(i>0){
            cout<<", ";
        }
    }
    cout<<endl;
}

double averageScore(string toFind,string names[],double scores[],int size){
    double found=0;
    double total=0;
    int counter=0;
    int a=0;

    for(int i=0; i<size; i++){ //read array
        found=names[i].find(toFind,a); 
        if(found==0){ 
            counter=counter+1;
            total=total+scores[i];
        }
    }
    if(total==0){
        return -1; //return -1
    }
    else{
        total=total/counter;
        return total; //return average score
    }
}