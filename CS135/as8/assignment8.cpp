/*Name: Eduardo Salazar
 NSHE ID: 5005695833
 Course: CS 135-1004
 Assignment: assignment 8
 Description: input data from txt file and output onto terminal or txt file
 input: data from txt file
 output: data onto terminal or other txt files*/
#include <cmath> //preprocessor directive
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const double MIN_CRATE = 1;	 // Minimum size a shipping crate can be (in feet)
const double MAX_CRATE = 5;	 // Maximum size a shipping crate can be (in feet)
const double MIN_ROOM = 10;	 // Minimum size a storage room can be (in feet)
const double MAX_ROOM = 100; // Maximum size a storage room can be (in feet)

const double S_BOX_RATE = 2.5;	  // Cost to ship crate 1-40 cubic feet
const double M_BOX_RATE = 3.0;	  // Cost to ship crate 40-80 cubic feet
const double L_BOX_RATE = 3.5;	  // Cost to ship crate 80+ cubic feet
const double S_ROOM_RATE = 0.12;  // Cost to ship in room 1,000-250,000 cubic feet
const double M_ROOM_RATE = 0.09;  // Cost to ship in room 250,000-500,000 cubic feet
const double L_ROOM_RATE = 0.07;  // Cost to ship in room 500,000-750,000 cubic feet
const double XL_ROOM_RATE = 0.05; // Cost to ship in room 750,000+ cubic feet

void showMenu(void); //function to display menu
bool check_string(string str);

void crateCalculations(void); //function to calculate crates
void storageSpaceCalculations(void); //function to calculate storage space
void totalVolumeAndCostCalculations(void); //function to calculate total
void displayFile(string line); //function to display txt file

double CrateVolume(double crateLength, double crateWidth, double crateHeight); //calculate crate volume
double CrateSurfaceArea(double crateLength, double crateWidth, double crateHeight); //calculate crate surface area
double CrateDiagonal(double crateLength, double crateWidth, double crateHeight); //calculate crate diagonal

double StorageVolume(double storageLength, double storageWidth, double storageHeight); //calculate storage volume
double StorageSurfaceArea(double storageLength, double storageWidth, double storageHeight); //calculate storage surface area
double StorageDiagonal(double storageLength, double storageWidth, double storageHeight); //calculate storage diagonal

double TotalCrates(double crateLength, double crateWidth, double crateHeight, double storageLength, double storageWidth, double storageHeight);
double CrateMultiplier(double crateVolume); //value of crates
double storageMultiplier(double storageVolume); //value of storage
double crateCost(double total_crates, double crate_multiplier); 
double storageCost(double storageVolume, double storage_multiplier);

int main()
{
	string crates_file;
	string line;
	ifstream inFile;
	string fileName;
	bool repeat=true;

	char selection;
	do
	{
		showMenu();
        cout<<"Enter your selection"<<endl;
		cin >> selection; //input selection

		switch (selection)
		{
		case 'D': //if selection is D
		case 'd':
			cout << "You selected D" << endl;
			cout<<"Enter the filename to open: "; //statement
                cin>>fileName; //input filename
                inFile.open(fileName); //open file
                while (!inFile.is_open()){ //while file is not open
                    cout<<"Enter the filename to open: ";
                    cin.clear(); //clear failed input
                    cin.ignore(1000,'\n');
                    cin>>fileName; //input filename again
                    inFile.open(fileName); //open file
                    cout<<endl;
                }
				cout<<"#################################"<<endl;
                cout<<"File Opened Succesfully"<<endl;
                cout<<"#################################"<<endl;
                while (!inFile.eof()){ //while does not reach end of file
                    getline(inFile,line); //getline for each line
                    displayFile(line);
                }
                inFile.close(); //close file
			break;
		case 'C': //if selection is C
		case 'c':
			cout << "You selected C" << endl;
			crateCalculations(); //call function
			break;
		case 'S': //if selection is S
		case 's':
			cout << "You selected S" << endl;
			storageSpaceCalculations(); //call function
			break;

		case 'T': //if selection is T
		case 't':
			cout << "You selected T" << endl;
			totalVolumeAndCostCalculations(); //call function
			break;

		case 'Q': //if selection is Q
		case 'q':
			cout << "You selected to quit the program" << endl;
			repeat=false;
			break;
		default:
			cout << "Invalid selection" << endl; //error statement
            cin.clear(); //clear input
            cin.ignore(1000,'\n');
			break;
		} 
	} while (repeat);

	return 0;
}

bool check_string(string str)
{
	bool ret = true;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 48 && str[i] <= 57) ||
			(str[i] == 46))
		{
			continue;
		}
		else
		{
			ret = false;
		}
	}

	return ret;
}

void showMenu(){ //display menu function
		cout<<"***************************************"<<endl;
        cout<<"D/d - Display file data"<<endl;
        cout<<"C/c - Crate calculations"<<endl;
        cout<<"S/s - Storage space calculations"<<endl;
        cout<<"T/t - Total volume and cost calculations"<<endl;
        cout<<"Q/q - Quit the program"<<endl;
        cout<<"***************************************"<<endl;
}

void displayFile(string line) //display txt file function
{
	cout<<line<<endl; //output line
}

double CrateVolume(double crateLength, double crateWidth, double crateHeight){ //calculate crate volume
	double volume;
	volume=crateLength*crateWidth*crateHeight; //volume formula
	return volume; //return volume
}

double CrateSurfaceArea(double crateLength, double crateWidth, double crateHeight){ //calculate crate surface area
	double surfArea;
	surfArea=2*(crateWidth*crateLength+crateHeight*crateLength+crateHeight*crateWidth); //surface area formula
	return surfArea; //return surface area
}

double CrateDiagonal(double crateLength, double crateWidth, double crateHeight){ //calculate crate diagonal
	double diagonal;
	diagonal=sqrt(pow(crateLength,2.0)+pow(crateWidth,2.0)+pow(crateHeight,2.0)); //crate diagonal formula
	return diagonal; //return diagonal
}

double StorageVolume(double storageLength, double storageWidth, double storageHeight){ //calculate storage volume
	double volume;
	volume=storageLength*storageWidth*storageHeight; //storage volume formula
	return volume;//return volume
}

double StorageSurfaceArea(double storageLength, double storageWidth, double storageHeight){ //calculate storage surface area
	double surfArea;
	surfArea=2*(storageWidth*storageLength+storageHeight*storageLength+storageHeight*storageWidth); //surface area formula
	return surfArea; //return surface area
}

double StorageDiagonal(double storageLength, double storageWidth, double storageHeight){ //calculate storage diagonal
	double diagonal;
	diagonal=sqrt(pow(storageLength,2.0)+pow(storageWidth,2.0)+pow(storageHeight,2.0)); //diagonal formula
	return diagonal; //return diagonal
}

double TotalCrates(double crateLength, double crateWidth, double crateHeight, double storageLength, double storageWidth, double storageHeight){
	double total;
	total=floor((storageLength/crateLength))*floor((storageWidth/crateWidth))*floor((storageHeight/crateHeight)); //total crates formula
	return total; //return total crates
}

double CrateMultiplier(double crateVolume){
    double value=0;
	if (crateVolume>=1 && crateVolume<=40){
        value=value+S_BOX_RATE; //return value for small box
    }
    else if(crateVolume>40 && crateVolume<=80){
        value=value+M_BOX_RATE; //return value for medium box
    }
    else if(crateVolume>80){
        value=value+L_BOX_RATE; //return value for large box
    }
    return value; //return
}

double storageMultiplier(double storageVolume){
    double value=0;
	if (storageVolume>=1000 && storageVolume<=250000){
        value=value+S_ROOM_RATE; //return value for small room
    }
    else if(storageVolume>250000 && storageVolume<=500000){
        value=value+M_ROOM_RATE; //return value for medium room
    }
    else if(storageVolume>500000 && storageVolume<=750000){
        value=value+L_ROOM_RATE; //return value for large room
    }
    else if(storageVolume>750000){
        value=value+XL_ROOM_RATE; //return value for extra large room
    }
    return value; //return
}

double crateCost(double total_crates, double crate_multiplier){
	double cost;
	cost=total_crates*crate_multiplier; //cost for crate formula
	return cost; //return cost
}

double storageCost(double storageVolume, double storage_multiplier){
	double cost;
	cost=storageVolume*storage_multiplier; //cost for storage formula
	return cost; //return cost
}

void totalVolumeAndCostCalculations(void){ //total calculation
	
	string fileName;
	string header;
	double crateLength;
	double crateWidth;
	double crateHeight;
	double storageLength;
	double storageWidth;
	double storageHeight;
	double storageVolume;
	double crateVolume;
	double storageSurfArea;
	double crateSurfArea;
	double storageDiagonal;
	double crateDiagonal;
	double total;
	double storCost;
	double crtCost;
	double crateMult;
	double storageMult;
	int numOfLines=1;
	ifstream inFile;
	ofstream outFile;

	cout<<"Enter the filename to open: ";
	cin>>fileName; //input file name
	cout<<endl;

	inFile.open(fileName); //open file
    while (!inFile.is_open()){ //while file is not open
        cout<<"Enter the filename to open: ";
        cin.clear(); //clear failed input
        cin.ignore(1000,'\n');
        cin>>fileName; //input filename again
        inFile.open(fileName); //open file
        cout<<endl;
    }
    cout<<"#################################"<<endl;
    cout<<"File Opened Succesfully"<<endl;
    cout<<"#################################"<<endl;
	outFile.open("Total_volume_cost_output.txt"); //open file
	getline(inFile,header); //get header

	while (!inFile.eof()){ //while does not reach end of file
        outFile<<"Dataset: "<<numOfLines<<endl; //display number of lines
        outFile<<"LC            WC            HC            LS            WS            ";
        outFile<<"HS            CV            CS            CD            SV            ";
        outFile<<"SS            SD            Total Cost"<<endl;
        outFile<<fixed<<showpoint<<setprecision(1); //show decimal values

        inFile>>crateLength; //input crate length
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid crate length"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (crateLength<MIN_CRATE || crateLength>MAX_CRATE){
            outFile<<"Error: invalid crate length"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>crateWidth>>crateHeight>>storageLength>>storageWidth>>storageHeight; //input other variables in same line
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<crateLength; //output if no errors
        }
        inFile>>crateWidth; //input crate width
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid shipping crate width"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (crateWidth<MIN_CRATE || crateWidth>MAX_CRATE){
            outFile<<"Error: invalid shipping crate width"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>crateHeight>>storageLength>>storageWidth>>storageHeight; //input other variables in line
            inFile.clear(); //clear failed inputs
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<crateWidth; //output if no errors
        }
        inFile>>crateHeight; //input crate height
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid shipping crate height"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (crateHeight<MIN_CRATE || crateHeight>MAX_CRATE){
            outFile<<"Error: invalid shipping crate height"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>storageLength>>storageWidth>>storageHeight; //input other variables in line
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<crateHeight; //output if no errors
        }
        inFile>>storageLength; //input storage length
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid storage length"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (storageLength<MIN_ROOM || storageLength>MAX_ROOM){
            outFile<<"Error: invalid storage length"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>storageWidth>>storageHeight; //input other variables in line
            inFile.clear(); //clear failed inputs
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<storageLength; //output if no errors
        }
        inFile>>storageWidth; //input storage width
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid storage width"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (storageWidth<MIN_ROOM || storageWidth>MAX_ROOM){
            outFile<<"Error: invalid storage width"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>storageHeight; //input other variables in line
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<storageWidth; //output if no errors
        }
        inFile>>storageHeight; //input storage height
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid storage height"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');                   
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (storageHeight<MIN_ROOM || storageHeight>MAX_ROOM){
            outFile<<"Error: invalid storage height"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear loop
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<storageHeight; //output if no errors
			numOfLines=numOfLines+1;
		}

		crateVolume=CrateVolume(crateLength,crateWidth,crateHeight); //call crate volume function
		storageVolume=StorageVolume(storageLength,storageWidth,storageHeight); //call storage volume function
		crateSurfArea=CrateSurfaceArea(crateLength,crateWidth,crateHeight); //call crate surface area function
		storageSurfArea=StorageSurfaceArea(storageLength,storageWidth,storageHeight); //call storage surface area function
		crateDiagonal=CrateDiagonal(crateLength,crateWidth,crateHeight); //call crate diagonal function
		storageDiagonal=StorageDiagonal(storageLength,storageWidth,storageHeight); //call storage diagonal function
		total=TotalCrates(crateLength,crateWidth,crateHeight,storageLength,storageWidth,storageHeight); //call total crates function
		storageMult=storageMultiplier(storageVolume);
		crateMult=CrateMultiplier(crateVolume);
		storCost=storageCost(storageVolume,storageMult);
		crtCost=crateCost(total,crateMult);

		outFile<<left<<setw(14)<<crateVolume<<left<<setw(14)<<crateSurfArea<<left<<setw(14)<<crateDiagonal; //output crate values
		outFile<<left<<setw(14)<<storageVolume<<left<<setw(14)<<storageSurfArea<<left<<setw(14)<<storageDiagonal; //output storage values
        outFile<<left<<setw(14)<<total<<endl; //output total
		outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
		outFile<<"Crate volume "<<setprecision(2)<<crateVolume<<" and the cost per crate...................$"<<crateMult<<endl;
        outFile<<"Price to ship "<<total<<" crates...................................$"<<crtCost<<endl;
        outFile<<"Storage rooms with volume "<<storageVolume<<" and the cost per cubic foot................$"<<storageMult<<endl;
        outFile<<storageVolume<<" cubic feet storage room cost.................$"<<storCost<<endl;
        outFile<<"Total cost...........................................$"<<(crateMult*total)+(storageVolume*storageMult)<<endl;
        outFile<<"---------+---------+---------+---------+---------+---------+----------+----------+"<<endl;
    }
    inFile.close(); //close file
    outFile.close(); //close file
}

void storageSpaceCalculations(void){ //storage calculation function

	string fileName;
	string header;
	string crateLength;
	string crateWidth;
	string crateHeight;
	double storageLength;
	double storageWidth;
	double storageHeight;
	double storageVolume;
	double storageSurfArea;
	double storageDiagonal;
	int numOfLines=1;
	ifstream inFile;
	ofstream outFile;

	cout<<"Enter the filename to open: ";
	cin>>fileName; //input file name
	cout<<endl;

	inFile.open(fileName);
    while (!inFile.is_open()){ //while file is not open
        cout<<"Enter the filename to open: ";
        cin.clear(); //clear failed input
        cin.ignore(1000,'\n');
        cin>>fileName; //input filename again
        inFile.open(fileName); //open file
        cout<<endl;
    }
    cout<<"#################################"<<endl;
    cout<<"File Opened Succesfully"<<endl;
    cout<<"#################################"<<endl;
	outFile.open("storage_space_output.txt");
	getline(inFile,header); //input file header

	while(!inFile.eof()){
		outFile<<"Dataset: "<<numOfLines<<endl; //line number being read
		outFile<<"LS            WS            HS            SV            SS            SD"<<endl;
		outFile<<fixed<<showpoint<<setprecision(1); //show decimal values

		inFile>>crateLength>>crateHeight>>crateWidth; //input crate values
        inFile>>storageLength; //input storage length
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid storage length"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (storageLength<MIN_ROOM || storageLength>MAX_ROOM){
            outFile<<"Error: invalid storage length"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>storageWidth>>storageHeight; //input other variables in line
            inFile.clear(); //clear failed inputs
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<storageLength; //output if no errors
        }
        inFile>>storageWidth; //input storage width
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid storage width"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (storageWidth<MIN_ROOM || storageWidth>MAX_ROOM){
            outFile<<"Error: invalid storage width"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>storageHeight; //input other variables in line
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<storageWidth; //output if no errors
        }
        inFile>>storageHeight; //input storage height
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid storage height"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');                   
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (storageHeight<MIN_ROOM || storageHeight>MAX_ROOM){
            outFile<<"Error: invalid storage height"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear loop
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<storageHeight; //output if no errors
			numOfLines=numOfLines+1;
		}

		storageVolume=StorageVolume(storageLength,storageWidth,storageHeight); //call storage volume function
		storageSurfArea=StorageSurfaceArea(storageLength,storageWidth,storageHeight); //call storage surface area function
		storageDiagonal=StorageDiagonal(storageLength,storageWidth,storageHeight); //call storage diagonal function

		outFile<<left<<setw(14)<<storageVolume; //output volume
		outFile<<left<<setw(14)<<storageSurfArea; //output surface area
		outFile<<left<<setw(14)<<storageDiagonal<<endl; //output diagonal
		outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
	}
    inFile.close(); //close file
    outFile.close(); //close file
}

void crateCalculations(void){ //crate calculation function
	string fileName;
	string header;
	double crateLength;
	double crateWidth;
	double crateHeight;
	string storageLength;
	string storageWidth;
	string storageHeight;
	double crateVolume;
	double crateSurfArea;
	double crateDiagonal;
	int numOfLines=1;
	ifstream inFile;
	ofstream outFile;

	cout<<"Enter the filename to open: ";
	cin>>fileName; //input filename
	cout<<endl;

	inFile.open(fileName); //open file
    while (!inFile.is_open()){ //while file is not open
        cout<<"Enter the filename to open: ";
        cin.clear(); //clear failed input
        cin.ignore(1000,'\n');
        cin>>fileName; //input filename again
        inFile.open(fileName); //open file
        cout<<endl;
    }
    cout<<"#################################"<<endl;
    cout<<"File Opened Succesfully"<<endl;
    cout<<"#################################"<<endl;
	outFile.open("crate_output.txt"); //open file
	getline(inFile,header); //get header line

	while(!inFile.eof()){
		outFile<<"Dataset: "<<numOfLines<<endl; //display number of lines
        outFile<<"LC            WC            HC            CV            CS            CD"<<endl;
        outFile<<fixed<<showpoint<<setprecision(1); //show decimal values

		inFile>>crateLength; //input crate length
    	if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid crate length"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (crateLength<MIN_CRATE || crateLength>MAX_CRATE){
            outFile<<"Error: invalid crate length"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>crateWidth>>crateHeight>>storageLength>>storageWidth>>storageHeight; //input other variables in same line
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<crateLength; //output if no errors
        }
        inFile>>crateWidth; //input crate width
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid shipping crate width"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (crateWidth<MIN_CRATE || crateWidth>MAX_CRATE){
            outFile<<"Error: invalid shipping crate width"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>crateHeight>>storageLength>>storageWidth>>storageHeight; //input other variables in line
            inFile.clear(); //clear failed inputs
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<crateWidth; //output if no errors
        }
        inFile>>crateHeight; //input crate height
        if (inFile.fail()){ //if input fails
            outFile<<"Error: invalid shipping crate height"<<endl;
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else if (crateHeight<MIN_CRATE || crateHeight>MAX_CRATE){
            outFile<<"Error: invalid shipping crate height"<<endl; //error statement
            outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
            inFile>>storageLength>>storageWidth>>storageHeight; //input other variables in line
            inFile.clear(); //clear failed input
            inFile.ignore(1000,'\n');
            numOfLines=numOfLines+1;
            continue; //restart loop
        }
        else {
            outFile<<left<<setw(14)<<crateHeight; //output if no errors
			numOfLines=numOfLines+1;
		}
		inFile>>storageLength>>storageWidth>>storageHeight; //input storage values

		crateVolume=CrateVolume(crateLength,crateWidth,crateHeight); //call crate volume function
		crateSurfArea=CrateSurfaceArea(crateLength,crateWidth,crateHeight); //call surface area function
		crateDiagonal=CrateDiagonal(crateLength,crateWidth,crateHeight); //call crate diagonal function

		outFile<<left<<setw(14)<<crateVolume; //output volume
		outFile<<left<<setw(14)<<crateSurfArea; //output surface area
		outFile<<left<<setw(14)<<crateDiagonal<<endl; //output crate diagonal
		outFile<<"------------+------------+------------+------------+------------+------------+------------+------------+"<<endl;
	}
    inFile.close(); //close file
    outFile.close(); //close file
}