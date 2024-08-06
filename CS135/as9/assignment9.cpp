/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: assignment 9
 Description: output data from file with filters
 input: data from csv file
 output: data onto terminal*/
#include <iostream> //preprocessor directive
#include <fstream> //preprocessor directive
#include <sstream> //preprocessor directive
#include <string> //preprocessor directive
using namespace std;

void caseFoldString(string&); //changes characters to lowercase or uppercase
void printEntry(string,string,double,double,double,double,double,double,double); //prints out data
void filterString(bool&,string,int,string,int&); //searches for string in array
void filterLessThan(bool&,double,int,double,int&); //filters values less than a double
void filterGreaterThan(bool&,double,int,double,int&); //filters values greater than a double
void filterOutsideRange(bool&,double,double,int,double,int&); //filters values outside a range

int main(){
    string fileName; //string for file name input
    string text; //string to read line of text
    string header; //string for getline header
    string inputString; 
    string inputString2;
    string search; //input to search for string
    string search2; //input to search for second string
    string commonFishName2;
    string taxonomy2;
    string cfn;
    string tax;
    double size1;
    double minS;
    double maxS;
    double minT;
    double maxT;
    double minV;
    double minD;
    double minSize;
    double maxSize;
    double tankSalin;
    double minSalin;
    double maxSalin;
    double minTemp2;
    double maxTemp2;
    double size2;
    double minVolume2;
    double minDepth2;
    double tempInput;
    double depthInput;
    double volInput;
    bool checkString2;
    bool checkString3;
    bool checkString[100]; //array to print out if true
    int i=0;
    int result=0; 
    int reference=100; //number of results loaded
    int sizeOfArray=100; //size of the arrays
    bool term;
    char filter;
    char selection;
    string commonFishName[100]; //array of common fish names
    string taxonomy[100]; //array of taxonomy
    double size[100]; //array of sizes
    double minSalinity[100]; //array for minimum salinity
    double maxSalinity[100]; //array for maximum salinity
    double minTemp[100]; //array for minimum temperature
    double maxTemp[100]; //array for maximum temperature
    double minVolume[100]; //array for minimum volume
    double minDepth[100]; //array for minimum depth
    string line;

    ifstream inFile; //read in file

    do{ //do loop to enter file name
        cout<<"Enter a file to open: ";
        cin>>fileName; //input file name
        cout<<endl;
        inFile.open(fileName); //open file
        if(!inFile.is_open()){ //if infile does not open
            cout<<"Error: File not open"<<endl; //error statement
            cin.clear(); //clear input
            cin.ignore(1000,'\n');
        }
    }
    while(!inFile.is_open()); //do loop condition
    getline(inFile,header); //get first line in file
    while (1) {
        getline(inFile, text);     
        if (inFile.eof()) { //if file reaches the end
            break; //break loop
        }
        stringstream ss(text);
        
        getline(ss, commonFishName[i], ',');
        for(int r=0; r<100; r++){
            inputString=commonFishName[r];
            caseFoldString(inputString); //call function
            commonFishName[r]=inputString;
        }   
        getline(ss, taxonomy[i], ',');
        for(int t=0; t<100; t++){
            inputString2=taxonomy[t];
            caseFoldString(inputString2); //call function
            taxonomy[t]=inputString2;
        }   
        getline(ss, line, ',');
        size[i]=stod(line);
        getline(ss, line, ',');
        if(i!=3){
            minSalinity[i]=stod(line);
        }
        else{
            minSalinity[i]=0;
        }
        getline(ss, line, ',');
        maxSalinity[i]=stod(line);        
        getline(ss, line, ',');
        minTemp[i]=stod(line);
        getline(ss, line, ',');
        maxTemp[i]=stod(line);
        getline(ss, line, ',');
        minVolume[i]=stod(line);
        getline(ss, line, ' ');
        minDepth[i]=stod(line); 
        i++;
    }
    for(int b=0; b<100; b++){
        checkString[b]=true; //set all bool values to true
    }
    term=true;
    while(term==true){
        cout<<reference<<" fish records loaded"<<endl; //number of fish records loaded
        cout<<"Apply a filter - [A]"<<endl; 
        cout<<"Print results - [P]"<<endl;
        cout<<"Reset filters - [R]"<<endl;
        cout<<"Quit - [Q]"<<endl;
        cout<<endl;
        cout<<"Enter a selection: ";
        cin>>selection; //input selection
        cout<<endl;

        switch(selection){
            case 'A': //if A is chosen
            case 'a':
                do{
                    cout<<"Common Name Contains - [A]"<<endl;
                    cout<<"Scientific Name Contains - [B]"<<endl;
                    cout<<"Length Within Range - [C]"<<endl;
                    cout<<"Tank Salinity - [D]"<<endl;
                    cout<<"Tank Temperature - [E]"<<endl;
                    cout<<"Tank Volume - [F]"<<endl;
                    cout<<"Tank Depth - [G]"<<endl;
                    cout<<endl;
                    cout<<"Select a filter: ";
                    cin>>filter; //input filter type
                    cout<<endl;

                    switch(filter){
                        case 'A': //if A is chosen
                        case 'a':
                            cout<<"Enter a search word: ";
                            cin>>search; //enter a string to search for
                            cout<<endl;
                            caseFoldString(search); //call function
                            for(int o=0; o<sizeOfArray; o++){
                                if(checkString[o]==true){ //if checkstring is true
                                    checkString2=checkString[o];
                                    commonFishName2=commonFishName[o];
                                    filterString(checkString2,commonFishName2,sizeOfArray,search,reference); //call function
                                    checkString[o]=checkString2;
                                }
                            }
                            cout<<"Filter successful"<<endl; 
                            term=false;
                            break;
                        case 'B': //if B is chosen
                        case 'b':
                            cout<<"Enter a search word: ";
                            cin>>search2; //enter a string to search for
                            cout<<endl;
                            caseFoldString(search2); //call function
                            for(int w=0; w<sizeOfArray; w++){
                                if(checkString[w]==true){ //if checkstring is true
                                    checkString2=checkString[w];
                                    taxonomy2=taxonomy[w];
                                    filterString(checkString2,taxonomy2,sizeOfArray,search2,reference); //call function
                                    checkString[w]=checkString2;
                                }
                            }
                            cout<<"Filter successful"<<endl;
                            term=false;
                            break;
                        case 'C': //if C is chosen
                        case 'c':
                            cout<<"Minimum Size (cm): ";
                            cin>>minSize; //enter minimum size
                            cout<<endl;
                            cout<<"Maximum Size (cm): ";
                            cin>>maxSize; //enter maximum size
                            cout<<endl;
                            for(int v=0; v<sizeOfArray; v++){
                                if(checkString[v]==true){ //if checkstring is true
                                    checkString2=checkString[v];
                                    checkString3=checkString[v];
                                    size2=size[v];
                                    filterLessThan(checkString2,size2,sizeOfArray,maxSize,reference); //call less than function
                                    filterGreaterThan(checkString3,size2,sizeOfArray,minSize,reference); //call greater than function
                                    if(checkString2==true && checkString3==true){ //if both function checks are true
                                        checkString[v]=true; //checkstring is true
                                    }
                                    else{
                                        checkString[v]=false;
                                    }
                                }
                            }
                            cout<<"Filter successful"<<endl;
                            term=false;
                            break;
                        case 'D': //if D is chosen
                        case 'd':
                            do{
                                cout<<"Tank Salinity (ppt): ";
                                cin>>tankSalin; //enter tank salinity
                                cout<<endl;
                                if(cin.fail()){ //if input fails
                                    cout<<"Error: Invalid input"<<endl; //error statement
                                    cin.clear(); //clear input
                                    cin.ignore(1000,'\n');
                                }
                            }
                            while(cin.fail()); //do loop condition
                            for(int y=0; y<sizeOfArray; y++){
                                if(checkString[y]==true){ //if checkstring is true
                                    checkString2=checkString[y];
                                    minSalin=minSalinity[y];
                                    maxSalin=maxSalinity[y];
                                    filterOutsideRange(checkString2,minSalin,maxSalin,sizeOfArray,tankSalin,reference); //call outside range function
                                    checkString[y]=checkString2;
                                }
                            }
                            cout<<"Filter successful"<<endl;
                            term=false;
                            break;
                        case 'E': //if E is chosen
                        case 'e':
                            do{
                                cout<<"Tank Temperature (C): ";
                                cin>>tempInput; //enter temperature input
                                cout<<endl;
                                if(cin.fail()){ //if input fails
                                    cout<<"Error: Invalid input"<<endl; //error statement
                                    cin.clear(); //clear input
                                    cin.ignore(1000,'\n');
                                }
                            }
                            while(cin.fail()); //do loop condition
                            for(int y=0; y<sizeOfArray; y++){
                                if(checkString[y]==true){ //if checkstring is true
                                    checkString2=checkString[y];
                                    minTemp2=minTemp[y];
                                    maxTemp2=maxTemp[y];
                                    filterOutsideRange(checkString2,minTemp2,maxTemp2,sizeOfArray,tempInput,reference); //call outside range function
                                    checkString[y]=checkString2;
                                }
                            }
                            cout<<"Filter successful"<<endl;
                            term=false;
                            break;
                        case 'F': //if F is chosen
                        case 'f':
                            do{
                                cout<<"Tank Volume (gal): ";
                                cin>>volInput; //enter volume input
                                cout<<endl;
                                if(cin.fail()){ //if input fails
                                    cout<<"Error: Invalid input"<<endl; //error statement
                                    cin.clear(); //clear input
                                    cin.ignore(1000,'\n');
                                }
                            }
                            while(cin.fail()); //do loop condition
                            for(int y=0; y<sizeOfArray; y++){
                                if(checkString[y]==true){ //if checkstring is true
                                    checkString2=checkString[y];
                                    minVolume2=minVolume[y];
                                    filterLessThan(checkString2,minVolume2,sizeOfArray,volInput,reference); //call less than function
                                    checkString[y]=checkString2;
                                }
                            }
                            cout<<"Filter successful"<<endl;
                            term=false;
                            break;
                        case 'G': //if G is chosen
                        case 'g':
                            do{
                                cout<<"Tank Depth (m): ";
                                cin>>depthInput; //enter tank depth
                                cout<<endl;
                                if(cin.fail()){ //if input fails
                                    cout<<"Error: Invalid input"<<endl; //error statement
                                    cin.clear(); //clear input
                                    cin.ignore(1000,'\n');
                                }
                            }
                            while(cin.fail()); //do loop condition
                            for(int y=0; y<sizeOfArray; y++){
                                if(checkString[y]==true){ //if checkstring is true
                                    checkString2=checkString[y];
                                    minDepth2=minDepth[y];
                                    filterLessThan(checkString2,minDepth2,sizeOfArray,depthInput,reference); //call less than function
                                    checkString[y]=checkString2;
                                }
                            }
                            cout<<"Filter successful"<<endl;
                            term=false;
                            break;
                        default: //if no cases are chosen
                            cout<<"Error: invalid filter choice"<<endl; //error statement
                            cin.clear(); //clear input
                            cin.ignore(1000,'\n');
                            term=true;
                    }
                }
                while(term==true); //do loop condition
                term=true;
                break;
            case 'P': //if P is chosen
            case 'p':
                for(int y=0; y<100; y++){
                    if(checkString[y]==true){ //if checkstring is true
                        result=result+1;
                        cout<<"Result #"<<result<<endl; //output result number
                        cfn=commonFishName[y];
                        tax=taxonomy[y];
                        size1=size[y];
                        minS=minSalinity[y];
                        maxS=maxSalinity[y];
                        minT=minTemp[y];
                        maxT=maxTemp[y];
                        minV=minVolume[y];
                        minD=minDepth[y];
                        printEntry(cfn,tax,size1,minS,maxS,minT,maxT,minV,minD); //call print function
                    }
                }
                result=result-result; //reset result number
                term=true;
                break;
            case 'R': //if R is chosen
            case 'r':
                for(int b=0; b<100; b++){
                    checkString[b]=true; //reset checkstring values to true
                }
                reference=100; //reset reference to 100
                term=true; //reset term to true
                cout<<"Filters removed"<<endl; //output statement
                break;
            case 'Q': //if Q is chosen
            case 'q':
                cout<<"Thank you for using this program"<<endl; //thank you statement
                term=false;
                exit(0); //exit program
                break;
            default: //if no cases are chosen
                cout<<"Error: Invalid Entry"<<endl; //error statement
                cin.clear(); //clear input
                cin.ignore(1000,'\n');
                term=true;
        }
    }
    return 0; //return 
}

void printEntry(string commonFishName,string taxonomy,double size,double minSalinity,double maxSalinity,double minTemp,double maxTemp,double minVolume,double minDepth){
    cout<<commonFishName<<"("<<taxonomy<<")"<<endl; //output common fish name and taxonomy
    cout<<"Length: "<<size<<" cm"<<endl; //output length
    cout<<"Tolerable Salinity: "<<minSalinity<<"-"<<maxSalinity<<" ppt"<<endl; //output Salinity
    cout<<"Tolerable Temperature: "<<minTemp<<"-"<<maxTemp<<" C"<<endl; //output temperature
    cout<<"Minimum Tank Size: "<<minVolume<<" gallons"<<endl; //output volume
    cout<<"Minimum Tank Depth: "<<minDepth<<" meters"<<endl; //output depth
    cout<<endl;
    
}

void filterString(bool &checkString,string commonFishName,int sizeOfArray,string search,int &reference){
    int i=0;
    int found;
    found=commonFishName.find(search, i); //search for string
    if(found!=-1){ //if string is found
        checkString=true; //checkstring true
    }
    else{
        checkString=false; //checkstring false
        reference=reference-1;
    }
}

void caseFoldString(string & check){
    int length;
    length=check.length();
    for(int i=0; i<length; i++){
        check[i]=tolower(check[i]); //lowercase string
    }
}

void filterLessThan(bool& checkstring,double num,int sizeOfArray,double minValue,int &reference){
    if(num<minValue){
        checkstring=true; //checkstring is true
    }
    else{
        checkstring=false; //checkstring is false
        reference=reference-1;
    }
}

void filterGreaterThan(bool& checkstring,double num,int sizeOfArray,double maxValue,int &reference){
    if(num>maxValue){
        checkstring=true; //checkstring is true
    }
    else{
        checkstring=false; //checkstring is false
        reference=reference-1;
    }
}

void filterOutsideRange(bool& checkstring,double minVal,double maxVal,int sizeOfArray,double check,int& reference){
    if(minVal<check && check<maxVal){
        checkstring=true; //checkstring is true
    }
    else{
        checkstring=false; //checkstring is false
        reference=reference-1;
    }
}