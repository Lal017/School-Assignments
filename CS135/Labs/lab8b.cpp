/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab8b
 Description: add and multiply numbers and strings
 input: two numbers and two strings
 output: sum and product of 2 numbers and 2 strings*/
#include <iostream> //preprocessor directive
using namespace std;

int add(int,int); //add function prototype
int multiply(int,int); //multiply function prototype
string add(string,string);
string multiply(string,int);

int main(){
    bool check; //bool check 
    int firstInt; 
    int secondInt;
    const int thousand=1000;
    const int fifty=50;
    string firstString;
    string secondString;

    do{
        cout<<"Enter an integer between 1 and 50"<<endl;
        cout<<"**";
        cin>>firstInt; //input first number
        cout<<endl;
        if (firstInt<1 || firstInt>fifty){
            cout<<"Error: Invalid input!"<<endl; //error
            cin.clear();
            cin.ignore(thousand,'\n');
            check=false;
        }
        else if(cin.fail()){
            cout<<"Error: Invalid input!"<<endl; //error
            cin.clear(); //clear input
            cin.ignore(thousand,'\n');
            check=false;
        }
        else{
            check=true;
        }
    }
    while(check==false);
    do{
        cout<<"Enter another integer between 1 and 50"<<endl;
        cout<<"**";
        cin>>secondInt; //input second number
        cout<<endl;
        if (secondInt<1 || secondInt>fifty){
            cout<<"Error: Invalid input!"<<endl; //error
            cin.clear();
            cin.ignore(thousand,'\n');
            check=false;
        }
        else if(cin.fail()){
            cout<<"Error: Invalid input!"<<endl; //error
            cin.clear(); //clear input
            cin.ignore(thousand,'\n');
            check=false;
        }
        else{
            check=true;
        }
    }
    while(check==false);
    
    cout<<"Enter a string"<<endl;
    cout<<"**";
    cin>>firstString; //input first string
    cout<<endl;

    cout<<"Enter another string"<<endl;
    cout<<"**";
    cin>>secondString; //input second string
    cout<<endl;

    cout<<firstInt<<" + "<<secondInt<<" = "; //add numbers
    cout<<add(firstInt,secondInt)<<endl; //call function
    cout<<firstString<<" + "<<secondString<<" = "; //add strings
    cout<<add(firstString,secondString)<<endl; //call function
    cout<<firstInt<<" * "<<secondInt<<" = "; //multiply numbers
    cout<<multiply(firstInt,secondInt)<<endl; //call function
    cout<<firstString<<" * "<<firstInt<<" = "; 
    multiply(firstString,firstInt); //call function
    cout<<secondString<<" * "<<secondInt<<" = ";
    multiply(secondString,secondInt); //call function
}

int add(int num1, int num2){
    int sum;
    sum=num1+num2; //add numbers
    return sum; //return sum
}

string add(string str1, string str2){
    string output;
    output=str1+str2; //add strings
    return output; //return output
}

int multiply(int num1, int num2){
    int product;
    product=num1*num2; //multiply numbers
    return product; //return product
}

string multiply(string str, int num){
    for (int i = 0; i < num; i++){ //loop string
        cout<<str; //output string
    }
    cout<<endl;
    return str; //return string
}