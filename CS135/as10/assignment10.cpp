/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: assignment 10
 Description: set up and play a game
 input: game set up data
 output: a game for up to 4 players*/
#include <iostream> //preprocessor directive
#include <fstream> //preprocessor directive
#include <sstream> //preprocessor directive
#include <cstdlib> //preprocessor directive
#include <ctime> //preprocessor directive
using namespace std;

const int items=5; //constant integer

void displayGameMenu(); //displat game menu
void displayTokens(); //display available tokens
void displayStartMenu(); //display start menu
void displayFile(ifstream&); //display file function
void displaySolution(int[],string[],string[],string[]); //display solution
void loadGameData(ifstream&,string[],string[],string[]); //load game data file
void getRandom(int[]); //get random number
int gameSetUp(ofstream&,int[][2],int[],string[],string[],string[]);
int guessItem(string[],int);
int playGame(ifstream&,ofstream&,int[][2],int[],int,string[],string[],string[]);
bool compareGuessToSolution(int[],int[]);

int main(){
    char setUp; //menu selection
    string tokens[items]; //tokens array
    string rooms[items]; //rooms array
    string topics[items]; //topics array
    int x; 
    int players[4][2]; //players array
    int solution[3]; //solution array
    ifstream inFile; //read in file
    ofstream outFile; //write to file
    srand(time(0)); //randon number declaration

    while(1){ //loop endlessly
        displayGameMenu(); //call display game menu function
        cin>>setUp; //input selection
        cout<<endl;
        switch(setUp){
            case 'G': //if g is selected
            case 'g':
                loadGameData(inFile,tokens,rooms,topics); //call load game data function
                x=gameSetUp(outFile,players,solution,tokens,rooms,topics); //call game setup function
                break;
            case 'Q': //if q is selected 
            case 'q':
                cout<<"Thanks for playing!"<<endl; //quit statement
                exit(0); //exit program
                break;
            default:
                cout<<"Error: invalid selection"<<endl; //error statement
                cin.clear(); //clear input
                cin.ignore(1000,'\n');
                continue; //restart loop
        }
    playGame(inFile,outFile,players,solution,x,tokens,rooms,topics); //call playgame function
    }
    return 0; //return
}

void displayGameMenu(){
    cout<<"Please choose from the menu"<<endl;
    cout<<"[G]ame Set up"<<endl;
    cout<<"[Q]uit"<<endl;
    cout<<"Selection: ";
}

void loadGameData(ifstream& inFile,string tokens[],string rooms[],string topics[]){
    string text;
    string header;
    int i=0;

    inFile.open("gamesetup.txt"); //open file
    getline(inFile,header); //get header line
    while(1){ //loop endlessly
        getline(inFile,text); //get line of text
        stringstream ss(text); 
        getline(ss, tokens[i], ','); //store line in tokens array
        getline(ss, topics[i], ','); //store line in topics array
        getline(ss, rooms[i], ' '); //store line in rooms array
        i++; //increment
        if(inFile.eof()){
            break;
        }
    }
    inFile.close(); //close file 

}

int gameSetUp(ofstream& outFile,int players[][2],int solution[],string tokens[],string topics[],string rooms[]){
    int numOfPlayers; //number of players
    int returnVal; //return value 
    int i=0;
    string fileName[items]; //filename array
    char tokenSelection;
    bool tokenBool; 
    bool fileOpen[items]; //open file array

    do{ //do loop
        cout<<"Enter a number of players (up to 4)"<<endl;
        cout<<"Players: ";
        cin>>numOfPlayers; //input number of players
        cout<<endl;
        if(cin.fail() || numOfPlayers<1 || numOfPlayers>4){
            cout<<"Error: Invalid entry"<<endl; //error statement
            cin.clear(); //clear input
            cin.ignore(1000,'\n');
        }
    }
    while(cin.fail() || numOfPlayers<1 || numOfPlayers>4); //do loop condition
    returnVal=numOfPlayers; //return value is number of players

    do{ //do loop
        displayTokens(); //call display token function
        cout<<"Player "<<i+1<<": "; //display player
        cin>>tokenSelection; //input selection
        cout<<endl;
        switch(tokenSelection){
            case 'A': //if a is selected
            case 'a':
                players[i][0]={0}; 
                players[i][1]={0};
                fileName[i]="andro-vasko_guesses.txt";
                fileOpen[i]=true;
                numOfPlayers--; 
                tokenBool=false;
                i++; //increment
                break;
            case 'F': //if f is selected
            case 'f':
                players[i][0]={1};
                players[i][1]={1};
                fileName[i]="fonseca_guesses.txt";
                fileOpen[i]=true;
                numOfPlayers--;
                tokenBool=false;
                i++; //increment
                break;
            case 'J': //if j is selected
            case 'j':
                players[i][0]={2};
                players[i][1]={2};
                fileName[i]="jorgensen_guesses.txt";
                fileOpen[i]=true;
                numOfPlayers--;
                tokenBool=false;
                i++; //increment 
                break;
            case 'M': //if m is selected
            case 'm':
                players[i][0]={3};
                players[i][1]={3};
                fileName[i]="martin_guesses.txt";
                fileOpen[i]=true;
                numOfPlayers--;
                tokenBool=false;
                i++; //increment
                break;
            case 'R': //if r is selected
            case 'r':
                players[i][0]={4};
                players[i][1]={4};
                fileName[i]="rafalski_guesses.txt";
                fileOpen[i]=true;
                numOfPlayers--;
                tokenBool=false;
                i++; //increment
                break;
            default:
                cout<<"Error: invalid token selected"<<endl; //error
                cin.clear(); //clear input
                cin.ignore(1000,'\n');
                tokenBool=true; //tokenBool is equal to true
        }
    }
    while(tokenBool==true || numOfPlayers>0); //do loop condition

    int arr[5]; //random number array
    int arr2[5]; //random number array 2
    int arr3[5]; //random number array 3

    getRandom(arr); //call random number function
    getRandom(arr2); //call random number function
    getRandom(arr3); //call random number function
    
    for(int c=0; c<5; c++){
        if(fileOpen[c]==true){ //if file open is true
            outFile.open(fileName[c]); //open file
            outFile<<tokens[arr3[c]]<<endl;
            outFile<<topics[arr[c]]<<endl;
            outFile<<rooms[arr2[c]]<<endl;
            outFile.close(); //close file
        }
        else if(fileOpen[c]==false){ //if file open is false
            solution[0]=arr3[c]; 
            solution[1]=arr[c];
            solution[2]=arr2[c];
        }
    }

    return returnVal; //return number of players

}

void displayStartMenu(){
    cout<<"Make a selection"<<endl;
    cout<<"[D]isplay Guesses"<<endl;
    cout<<"[G]uess Solution"<<endl;
    cout<<"[E]nd Turn"<<endl;
    cout<<"[S]ee Solution and Quit"<<endl;
    cout<<"Selection: ";
}

void getRandom(int arr[]){
    int arr2[5]; //array of numbers
    int sum=0;

    for(int i=0; i<5; i++){
        arr[i]=-1;
    }
    
    for(int i=0; i<5; i++){
        sum=sum-sum;
        do{
            arr2[i]=rand()%6;
        }
        while(arr2[i]<0 || arr2[i]>4);
        for(int k=0; k<5; k++){
            if(arr[k]!=arr2[i]){
                sum=sum+1;
            }
        }
        if(sum==5){
            arr[i]=arr2[i];
        }
        else{
            i=i-1;
        }
    }
}

void displayTokens(){
    cout<<"Select a token"<<endl;
    cout<<"[A]ndro-Vasco"<<endl;
    cout<<"[F]onseca"<<endl;
    cout<<"[J]orgensen"<<endl;
    cout<<"[M]artin"<<endl;
    cout<<"[R]afalski"<<endl;
}

int playGame(ifstream& inFile,ofstream& outFile,int players[][2],int solution[],int numOfPlayers,string tokens[],string rooms[],string topics[]){
    char selection;
    int i=0;
    string fileName; //input file name string
    string line; //read line string
    string inputSol; //input solution
    bool answer;
    int size=5; //size of array
    int choice[3]; //select a choice array

    numOfPlayers--;

    do{ //do loop
        cout<<"Player "<<tokens[players[i][0]]<<" is up!"<<endl;
        displayStartMenu(); //call display start menu function
        cin>>selection; //input selection
        cout<<endl;
        switch(selection){
            case 'D': //if d is selected
            case 'd':
                cout<<"Enter file: ";
                cin>>fileName; //input file name
                cout<<endl;
                inFile.open(fileName); //open file
                while(!inFile.eof()){
                    getline(inFile,line); //get line in file
                    cout<<line<<endl; //output line
                }
                inFile.close(); //close file
                break;
            case 'G': //if g is selected
            case 'g':
                choice[0]=guessItem(tokens,size); //call guess item function
                cout<<endl;
                
                if(choice[0]!=solution[0]){
                    outFile.open(tokens[players[i][0]]+"_guesses.txt", ios::app); //open file
                    outFile<<tokens[choice[0]]<<endl; //write to file
                    outFile.close(); //close file
                }

                choice[1]=guessItem(topics,size); //call guess item function
                cout<<endl;

                if(choice[1]!=solution[1]){
                    outFile.open(tokens[players[i][0]]+"_guesses.txt", ios::app); //open file
                    outFile<<topics[choice[1]]<<endl; //write to file
                    outFile.close(); //close file
                }
                
                choice[2]=guessItem(rooms,size); //call guess item function
                cout<<endl;
                
                if(choice[2]!=solution[2]){
                    outFile.open(tokens[players[i][0]]+"_guesses.txt", ios::app); //open file
                    outFile<<rooms[choice[2]]<<endl; //write to file
                    outFile.close(); //close file
                }

                answer=compareGuessToSolution(solution,choice); //call compare guess to solution function

                if(answer==true){
                    cout<<"All answers are true"<<endl;
                    cout<<tokens[players[i][0]]<<" Wins!"<<endl;
                    exit(0); //quit program
                }
                break;
            case 'E': //if e is selected
            case 'e':
                break;
            case 'S': //if s is selected
            case 's':
                displaySolution(solution,tokens,rooms,topics); //call display solution function
                exit(0); //quit program
                break;
            default:
                cout<<"Error: Invalid Selection"<<endl;
                cin.clear(); //clear input
                cin.ignore(1000,'\n');
                continue; //restart loop
        }
        if(i<numOfPlayers){
            i++; //increment
        }
        else{ 
            i=i-i;
        }
    }
    while(1); //loop endlessly 
    return 1; //return 
}

void displaySolution(int solution[],string tokens[],string rooms[],string topics[]){
    cout<<"Solution: "<<tokens[solution[0]]<<","<<topics[solution[1]]<<","<<rooms[solution[2]]<<endl;
    //display solution
}

bool compareGuessToSolution(int solution[],int guess[]){
    
    if(solution[0]==guess[0] && solution[1]==guess[1] && solution[2]==guess[2]){
        return true; //return true
    }
    else if(solution[0]!=guess[0] && solution[1]!=guess[1] && solution[2]!=guess[2]){
        cout<<"All solutions are wrong"<<endl;
        return false; //return false
    }
    else{
        cout<<"some solutions are correct"<<endl;
        return false; //return false
    }

}

int guessItem(string list[],int size){
    int choice;

    cout<<"Select a choice"<<endl;
    cout<<"Enter 0 for "<<list[0]<<endl;
    cout<<"Enter 1 for "<<list[1]<<endl;
    cout<<"Enter 2 for "<<list[2]<<endl;
    cout<<"Enter 3 for "<<list[3]<<endl;
    cout<<"Enter 4 for "<<list[4]<<endl;
    cout<<"Enter solution: ";
    cin>>choice; //enter selection
    cout<<endl;
    return choice; //return selection
}