/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab6a
 Description: make a pyramid as high as input number
 input: number between 2 and 20
 output: pyramid of stars*/
#include <iostream> //preprocessor directive
using namespace std;

int main(){
    int firstNum=0; //first number placeholder
    int secondNum=0; //second number placeholder
    int thirdNum=0; //third number placeholder
    int fourthNum=0; //fourth number placeholder
    const int twenty=20;
    const int thousand=1000;
    string amountOfStars; //string for stars

    do { //do loop
        cout<<"Enter a count between 2 and 20"<<endl; //first statement 
        cout<<"**";
        cin>>firstNum; //input number
        cout<<endl;
        if (firstNum<=1 || firstNum>twenty){ //if fail statement
            cout<<"Error: Invalid entry, please retry"<<endl; //error
            cin.clear(); //clear failed input
            cin.ignore(thousand,'\n'); //ignore failed input characters
        }
    }
    while (firstNum<=1 || firstNum>twenty); //do loop condition
    
    fourthNum=fourthNum+firstNum; //holding value of input for later

    for (amountOfStars=firstNum; 1<=firstNum; firstNum=firstNum-1){ 
        secondNum=secondNum+firstNum+firstNum;
        while (firstNum<secondNum){ //loop for stars
            secondNum=secondNum-1;
            amountOfStars="*"; //string
            cout<<amountOfStars; //output string
        }
        secondNum=secondNum*0; //reset value for second number
        cout<<endl; //next line for pyramid
    }
    firstNum=firstNum+fourthNum; //reset value for first number
    secondNum=secondNum+firstNum; 
    
    while (firstNum>=secondNum && secondNum>=0){
        thirdNum=thirdNum+1;
        secondNum=secondNum-thirdNum;
        while (firstNum>secondNum && secondNum>=0){
            secondNum=secondNum+1; //increment for loop
            cout<<amountOfStars; //output string
        }
        cout<<endl; //next line in pyramid
    }
    return 0; //return
}