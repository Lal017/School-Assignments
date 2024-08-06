/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab8a
 Description: add subtract multiply and divide 2 numbers
 input: 2 numbers
 output: sum, difference, product and quotient*/
#include <iostream> //preprocessor directive
#include <iomanip>
using namespace std;

double getDoubleInput(string, double, double); //function prototypes
bool checkFailure(double,double,double);
void getDoubleInputs(double&,double&);
void addSubtract(double&,double&);
void multiplyDivide(double&, double&);

int main(){
    double input1;
    double input2;

    getDoubleInputs(input1,input2); //call function
    double copy1=input1;
    double copy2=input2;
    addSubtract(input1, input2); //call addition subtraction function
    cout<<fixed<<showpoint; //show decimals
    cout<<setprecision(2)<<copy1<<" + "<<copy2<<" = "<<input1<<endl;
    cout<<setprecision(2)<<copy1<<" - "<<copy2<<" = "<<input2<<endl;
    input1=copy1;
    input2=copy2;
    multiplyDivide(input1, input2); //call multiply divide function
    cout<<setprecision(2)<<copy1<<" * "<<copy2<<" = "<<input1<<endl;
    cout<<setprecision(2)<<copy1<<" / "<<copy2<<" = "<<input2<<endl;
}

double getDoubleInput(string prompt,double min,double max){
    double input; 
    bool check;
    do{ //do loop
        cout<<prompt; //output string
        cin>>input; //input 
        cout<<endl;
        check=checkFailure(input,min,max); //call check function
    }
    while (check==false); //condition
    return input; //return the input
}

bool checkFailure(double input,double min, double max){
    const int thousand=1000;
    if (cin.fail()){ //if input fails
        cin.clear(); //clear input
        cin.ignore(thousand,'\n');
        cout<<"Error: Invalid input!"<<endl; //error
        return false; //return false
    }
    else if(input<min || input>max){
        cin.clear(); //clear input
        cin.ignore();
        cout<<"Error: Invalid input!"<<endl; //error
        return false; //return false
    }
    else{
        return true; //return true
    }
}

void getDoubleInputs(double& input1, double& input2){
    string prompt="Enter double between 0.500000 and 20.500000\n**"; //statement
    string prompt2="Enter another double between 0.500000 and 20.500000\n**";
    const double min=0.5; //min value  
    const double max=20.5; //max value


    input1=getDoubleInput(prompt, min, max); 
    input2=getDoubleInput(prompt2, min, max);

}

void addSubtract(double& num1, double& num2){
    double num3=0;
    double num4=0;

    num3=num1+num3;
    num4=num2+num4;

    num1=num3+num4; //add 2 numbers
    num2=num3-num4; //subtract 2 numbers

}

void multiplyDivide(double& num1, double& num2){
    double num3=0;
    double num4=0;

    num3=num1+num3;
    num4=num2+num4;

    num1=num3*num2; //multiply 2 numbers
    num2=num3/num4; //divide 2 numbers

}