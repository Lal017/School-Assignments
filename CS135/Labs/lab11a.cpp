/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: lab11a
 Description: input name and score, output grade
 input: name and grade
 output: grade data*/
#include <iostream> //preprocessor directive
using namespace std;

struct studentType{ //struct
    string firstName; //first name string
    string lastName; //last name string
    int grade; //grade score 
    char letterGrade; //grade letter
};

void getStudentData(studentType&); //get student data
void getLetterGrade(studentType&); //get letter grade
void printStudentData(studentType&); //print data

int main(){
    studentType studentStruct; //declare struct

    getStudentData(studentStruct); //call function
    getLetterGrade(studentStruct); //call function
    printStudentData(studentStruct); //call function

    return 0; //return

}

void getStudentData(studentType& student){
    const int thousand=1000;
    bool repeat;

    cout<<"Enter a first name"<<endl;
    cout<<"**";
    cin>>student.firstName; //enter first name
    cout<<endl;
    cout<<"Enter a last name"<<endl;
    cout<<"**";
    cin>>student.lastName; //enter last name
    cout<<endl;
    do{ //do loop
        cout<<"Enter a grade"<<endl;
        cout<<"**";
        cin>>student.grade; //enter score
        cout<<endl;
        repeat=false;
        if(cin.fail() || student.grade>4 || student.grade<0){
            cout<<"Error: Invalid grade"<<endl; //error
            cin.clear(); //clear input
            cin.ignore(thousand,'\n');
            repeat=true;
        }
    }
    while(repeat==true); //loop condition

}

void getLetterGrade(studentType& student){
    if(student.grade==0){
        student.letterGrade='F';
    } //grade is F
    else if(student.grade==1){
        student.letterGrade='D';
    } //grade is D
    else if(student.grade==2){
        student.letterGrade='C';
    } //grade is C
    else if(student.grade==3){
        student.letterGrade='B';
    } //grade is B
    else if(student.grade==4){
        student.letterGrade='A';
    } //grade is A
}

void printStudentData(studentType& student){
    cout<<"Data Entered"<<endl; //header
    cout<<"  student.firstName   = "<<student.firstName<<endl;
    //output first name
    cout<<"  student.lastName    = "<<student.lastName<<endl;
    //output last name
    cout<<"  student.grade       = "<<student.grade<<endl;
    //output score
    cout<<"  student.letterGrade = "<<student.letterGrade<<endl;
    //output grade
}