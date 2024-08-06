/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: assignment 5
 Description: output the costs to ship crates to different continents.
 input: destination, number of crates and types of crates.
 output: number of crate types, volume of crates, number of ships needed and total cost*/
#include <iostream> //preprocessor directive
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    string destination; //string for destination input
    double iterationNum=0; //placeholder for number of crates
    double minCost=0; //placeholder for minimum cost
    double medCost=0; //placeholder for medium cost
    double maxCost=0; //placeholder for maximum cost
    char crtType; //input for crate types
    int numShips=0; //placeholder for number of ships needed
    double num_a=0; //crate type A
    double num_b=0; //crate type b
    double num_c=0; //crate type c
    double volume=0; //placeholder for volume output
    const double a_volume=24.0; //volume of crate A
    const double b_volume=125.0; //volume of crate B
    const double c_volume=30.0; //volume of crate C
    double totalCost=0; //placeholder for the total cost
    int i=1;
    
    cout<<"Please select the destination continent:"<<endl; //statement before list
    cout<<"Africa                       (Af/af)"<<endl; //input for Africa
    cout<<"Asia                         (As/as)"<<endl; //input for Asia
    cout<<"Australia                    (Au/au)"<<endl; //input for Australia
    cout<<"Europe                       (Eu/eu)"<<endl; //input for Europe
    cout<<"The Americas                 (Am/am)"<<endl; //input for the Americas
    cout<<"Quit                         (Q/q)"<<endl; //input to quit
    cout<<endl;
    cin>>destination; //input destination
    cout<<endl; 

    if (destination=="Af" || destination=="af"){ //if input for destination is Africa
        cout<<"Welcome to Africa cargo shipping program."<<endl; //welcome statement
        minCost=minCost+4.0; //new value for minimum cost
        medCost=medCost+5.5; //new value for medium cost
        maxCost=maxCost+8.0; //new value for maximum cost
        
    }
    else if (destination=="As" || destination=="as"){ //if input for destination is Asia
        cout<<"welcome to Asia cargo shipping program."<<endl; //welcome statement
        minCost=minCost+4.0; //new value for minimum cost
        medCost=medCost+5.5; //new value for medium cost
        maxCost=maxCost+8.0; //new value for maximum cost
    }
    else if (destination=="Au" || destination=="au"){ //if input for destination is Australia
        cout<<"welcome to Australia cargo shipping program."<<endl; //welcome statement
        minCost=minCost+7.8; //new value for minimum cost
        medCost=medCost+5.7; //new value for medium cost
        maxCost=maxCost+10.0; //new value for maximum cost
    }
    else if (destination=="Eu" || destination=="eu"){ //if input for destination is Europe
        cout<<"Welcome to Europe cargo shipping program."<<endl; //welcome statement
        minCost=minCost+7.8; //new value for minimum cost
        medCost=medCost+5.7; //new value for medium cost
        maxCost=maxCost+10.0; //new value for maximum cost
    }
    else if (destination=="Am" || destination=="am"){ //if input for destination is the Americas
        cout<<"welcome to the Americas cargo shipping program."<<endl; //welcome statement
        minCost=minCost+2.5; //new value for minimum cost
        medCost=medCost+3.5; //new value for medium cost
        maxCost=maxCost+6.0; //new value for maximum cost
    } 
    else if (destination=="Q" || destination=="q"){ //if input is to quit the program
        cout<<"Thank you for using this program, goodbye!"<<endl; //statement before quitting
        exit (0); //exit the program
    }
    else { //if input for destination is invalid
        cout<<"Error, invalid input. Please try again and select a correct value."<<endl; //statement before quitting
        exit (0); //exit the program
    }

    cout<<"How many crates will be sent?"<<endl; //statement before inputing amount of crates
    cin>>iterationNum; //input amount of crates
    cout<<endl;

    while (cin.fail()){ //if input fails
    cout<<"Enter a number please, how many crates do you want to send?"<<endl; //statement error
    cin.clear(); //clear failed input
    cin.ignore(1000,'\n'); //ignore other variables
    cin>>iterationNum; //input amount of crates again
    cout<<endl;
    }

    while (i<=iterationNum){ //loop for crate types
        cout<<"What type of crate do you want to send? (a/b/c) just the first character will be accepted."<<endl;
        cin>>crtType; //input crate type
        cout<<endl;

        if (crtType=='a' || crtType=='b' || crtType=='c'){ //if crate type input is valid
            switch (crtType){ //switch for crate types
                case 'a':
                num_a=num_a+1; //add 1 to amount of a crates
                break;
                case 'b':
                num_b=num_b+1; //add 1 to amount of b crates
                break;
                case 'c':
                num_c=num_c+1; //add 1 to amount of c crates
                break;
        }}
        else {
            cout<<"Error, the selected crate's type is not available please select a, b or c."<<endl; //statement if crate type input is invalid
            cin.clear(); //clear input
            cin.ignore(1000,'\n'); //ignore other variables
            iterationNum=iterationNum+1; //add 1 to number of times loop repeats
        }
        i++;
        }
    
    volume=(num_a*a_volume)+(num_b*b_volume)+(num_c*c_volume); //volume formula
    numShips=ceil(volume/300); //formula for number of ships

    if (numShips>10){ //if number of ships is greater than 10
        cout<<"Error, number of cargo ships cannot excede 10."<<endl; //error statement
        exit(0); //quit the program
    }

    if (volume<40){ //total cost if minimum cost is required
        totalCost=volume*minCost+numShips*200;
    }
    else if (volume>=40 && volume<=80){ //total cost if medium cost is required
        totalCost=volume*medCost+numShips*200;
    }
    else if (volume>80){ //total cost if maximum cost is required
        totalCost=volume*maxCost+numShips*200;
    }

    cout<<"+---------------+---------+"<<endl;
    cout<<"| # Type      a | "<<left<<setw(7)<<num_a<<" |"<<endl; //number of a type crates
    cout<<"+---------------+---------+"<<endl;
    cout<<"| # Type      b | "<<left<<setw(7)<<num_b<<" |"<<endl; //number of b type crates
    cout<<"+---------------+---------+"<<endl;
    cout<<"| # Type      c | "<<left<<setw(7)<<num_c<<" |"<<endl; //number of c type crates
    cout<<"+---------------+---------+"<<endl;
    cout<<"| # Cargo Ships | "<<left<<setw(7)<<numShips<<" |"<<endl; //number of cargo ships needed
    cout<<"+---------------+---------+"<<endl;
    cout<<fixed<<showpoint; //show decimal values
    cout<<"| Total Volume  | "<<left<<setw(7)<<setprecision(1)<<volume<<" |"<<endl; //total volume with 1 decimal value
    cout<<"+---------------+---------+"<<endl;
    cout<<"| Total Costs   | "<<left<<setw(7)<<setprecision(1)<<totalCost<<" |"<<endl; //total cost with 1 decimal value
    cout<<"+---------------+---------+"<<endl;

return 0; //return
}
