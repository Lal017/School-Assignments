/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab7a
 Description: make a pyramid as high as the input
 input: number and a character
 output: pyramid of a certain character*/
#include <iostream> //preprocessor directive
#include <cctype>
using namespace std;

int getIntegerInput(string, int, int); //int function prototype
char getCharacterInput(string); //char function prototype
void writeUpsideDownTriangle(int, char); //void function prototype
void writeRightSideUpTriangle(int, char); //void function prototype

int main(){ //main funtion
    string prompt="Enter a count between 2 and 20\n**"; //string 
    string prompt2="Enter a character\n**"; //string declaration
    int size; 
    char character;
    const int twenty=20;

    size=getIntegerInput(prompt, 2, twenty); //value for size
    character=getCharacterInput(prompt2); //char value
    writeUpsideDownTriangle(size, character); //call void function
    writeRightSideUpTriangle(size, character); //call void function
    return 0; //return
}

int getIntegerInput(string prompt, int min, int max){ //int function
    int firstNum=0; 
    const int thousand=1000;

    do{ //do loop
    cout<<prompt;
    cin>>firstNum; //input number
    cout<<endl;
        if (firstNum<min || firstNum>max){
            cout<<"Error: Invalid input!"<<endl; //error
            cin.clear(); //clear input
            cin.ignore(thousand,'\n'); 
        }}
    while (firstNum<min || firstNum>max);
    return firstNum; //return value
}

char getCharacterInput(string prompt){ //char function
    char character;

    cout<<prompt; //output string
    cin>>character; //input character
    cout<<endl;
    return character; //return character
}

void writeUpsideDownTriangle(int size, char character){ //void function
    int size2=0;
    while (size>0){
        size2=size2+size;
        while (size2>0){
            size2=size2-1;
            cout<<character; //output character
        }
    size=size-1; //decrement number of char outputed
    cout<<endl; //next line
        }
}

void writeRightSideUpTriangle(int size, char character){ //void function
    int size2=0;
    int size3=0;

    size2=size2+size;
    while (size>=size2 && size2>=0){
        size3=size3+1; //increment number of char outputed
        size2=size2-size3; 
        while (size>size2 && size2>=0){
            size2=size2+1; 
            cout<<character; //output character
        }
        if (size>=size2 && size2>0){
            cout<<endl; //next line
        }
    }
}