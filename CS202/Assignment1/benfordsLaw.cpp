/*Name: Eduardo Salazar, 5005695833 ,Section 1003, Assignment 1
Description: Make a program that incorporates benfords law
input: File name with data
output: Filtered data onto results file */
#include <iostream> //preprocessor directive
#include <iomanip>
#include <math.h>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

/**
 * @brief findFirstDigit : 
 * Calculate the first digit of the given number
 * @param number
 */

int findFirstDigit(int number) //function to find first digit
{
        int temp = number; //temporary variable

        while(1){ //while loop
                temp = temp / 10; //divide variable by 10
                if(temp != 0){ //temp does not equal 0
                        number = temp; 
                }
                else{
                        break; //break out loop
                }
        }
        return number;               // return first digit
}

/**
 * @brief findHundreds : Read the value from
 *  the second parameter and calculate the 
 * number of 100's of a given value
 *&param value- value passed from main() like the total count of 0's 
 * in the given input file
 * &param ofstream &resultFile- print the number of
 * asterisks(stars) based on the calculated value 
 * and also return value to the output file
 */
//find amount of times divisible by 100
int findHundreds(ofstream &resultFile, double value) 
{
        char a = '*'; 

        if(value > 99){ //if value is divisible by 100
                value = value / 100; //divide by 100
        }
        else{
                value = 0; //value is equal to 0
        }

        value = round(value); //round value to nearest whole number

        for(int i = 0; i < value; i++){ //for loop to print *
                resultFile << a ;
        }
        resultFile << "-";
        return value; 
        //return hundreds value; if value=220; then it should return 22
}
int main(int argc, char *argv[]) //main with command line arguments
{
        ofstream outFile; //output to file
        ifstream inFile; //read input file
        string line; //getline placeholder
        string text; //text placeholder
        int number; //number read from inFile
        int temp; //temp variable to hold return value
        int count = 0; //count total number of digits
        int arr[10]; //array to hold digits 0-9

        inFile.open(argv[1]); //open file
        
        while(!inFile.is_open()){ //if file is not open
                if(argv[1] == NULL || argv[2] != NULL){
                        cout << "Usage: ./benFordsLaw <base filename>.txt" << endl;
                        exit(0);
                }
                cout << "Error: You entered " << argv[1] <<endl; //error message
                cout << "Please re-enter valid filename: ";
                cin >> argv[1]; //input file name
                cout << endl;

                inFile.open(argv[1]); //open file
        }

        for(int i = 0; i < 5; i++){
                getline(inFile, line); //get first 5 lines
        }

        for(int j = 0; j < 10; j++){
                arr[j] = 0; //set values of array to 0
        }

        while(true){ 

                inFile >> text; //read in first line of text
                if(inFile.eof()){ //if reaches end of file
                        break; //break loop
                }
                inFile >> text; //read in second line of text
                inFile >> number; //read in number

                count++; //increment count
                
                temp = findFirstDigit(number); //call function

                if(temp == 0){
                        arr[0]++; //increment 
                }
                else if(temp == 1){
                        arr[1]++; //increment 
                }
                else if(temp == 2){
                        arr[2]++; //increment 
                }
                else if(temp == 3){
                        arr[3]++; //increment 
                }
                else if(temp == 4){
                        arr[4]++; //increment 
                }
                else if(temp == 5){
                        arr[5]++; //increment 
                }
                else if(temp == 6){
                        arr[6]++; //increment 
                }
                else if(temp == 7){
                        arr[7]++; //increment 
                }
                else if(temp == 8){
                        arr[8]++; //increment 
                }
                else if(temp == 9){
                        arr[9]++; //increment 
                }
        }

        inFile.close(); //close file

        string fileName;
        stringstream ss(argv[1]);

        getline(ss, fileName, '.');

        outFile.open(fileName+"_resultFile.txt"); //open new file

        outFile << "CS 202 - Assignment #1" << endl;
        outFile << "Benford's Law Program" << endl;
        outFile << "File Name: " << argv[1] << endl;
        outFile << endl;
        outFile << "---------------------------------" << endl;
        outFile << "Benford's Law - Test Results: " << endl;
        outFile << "Total Data Points: " << count << endl;
        outFile << "First Digit: " << endl;
        outFile << endl;
        outFile << "0" << setw(8) << arr[0] << "|";
        outFile << findHundreds(outFile, arr[0]) << endl;
        outFile << "1" << setw(8) << arr[1] << "|";
        outFile << findHundreds(outFile, arr[1]) << endl;
        outFile << "2" << setw(8) << arr[2] << "|";
        outFile << findHundreds(outFile, arr[2]) << endl;
        outFile << "3" << setw(8) << arr[3] << "|";
        outFile << findHundreds(outFile, arr[3]) << endl;
        outFile << "4" << setw(8) << arr[4] << "|";
        outFile << findHundreds(outFile, arr[4]) << endl;
        outFile << "5" << setw(8) << arr[5] << "|";
        outFile << findHundreds(outFile, arr[5]) << endl;
        outFile << "6" << setw(8) << arr[6] << "|";
        outFile << findHundreds(outFile, arr[6]) << endl;
        outFile << "7" << setw(8) << arr[7] << "|";
        outFile << findHundreds(outFile, arr[7]) << endl;
        outFile << "8" << setw(8) << arr[8] << "|";
        outFile << findHundreds(outFile, arr[8]) << endl;
        outFile << "9" << setw(8) << arr[9] << "|";
        outFile << findHundreds(outFile, arr[9]) << endl;

        outFile.close();

        return 0;
}
