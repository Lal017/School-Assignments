/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab5b
 Description: output sum of odd and even numbers
 input: number between 2 and 10000
 output: sum of odd and even numbers*/
#include <iostream> //preprocessor directive
using namespace std;

int main(){
    int firstNum=5; //placeholder for first number
    int a=1; //value for starting odd number
    int b=2; //value for starting even number
    int c=2;
    int d=10000; 
    int e=1000;
    int oddNum=0; //placeholder for odd number sum
    int evenNum=0; //placeholder for even number sum

    do { 
        if (cin.fail() || firstNum<c || firstNum>d){
            cin.clear(); //clear input if cin fails
            cin.ignore(e,'\n'); //ignore characters for cin
            cout<<"Error: invalid entry, please retry"<<endl;
            //error statement
        }
        cout<<"Enter a count between 2 and 10000"<<endl;
        //statement before input
        cout<<"**";
        cin>>firstNum; //input number
        cout<<endl;
    }
    while (cin.fail() || firstNum<c ||firstNum>d); 
    //condition for do while loop

    while (firstNum>=a){ //while loop
        oddNum=oddNum+a; //formula for sum of odd numbers
        a=a+2; //increment for a
    }

    for (b=2; firstNum>=b; b=b+2){ //for loop
        evenNum=evenNum+b; //formula for sum of even numbers
    }
    //output sum of even numbers
    cout<<"Sum of even numbers: "<<evenNum<<endl; 
    cout<<"Sum of odd numbers:  "<<oddNum<<endl;
    
    return 0; //return
}