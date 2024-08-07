/*
Name: Eduardo Salazar, 5005695833 ,Section 1003, Assignment 3
Description: put data pertaining to employees in classes
Input: names, ids and employee status
Output: pay stub for employees
*/
#include "wages.h"
#include <iostream>

using namespace std;

wages::wages(double payRate, double taxRate, double hoursWorked)
{
	setPayData(payRate);
	setTaxRate(taxRate);
	setHoursWorked(hoursWorked);

	//Initialize all of the class members. I suggest just calling other functions
	//that you have written

	//Call the setters to error check and set
}

//**** Getters ****
double wages::getPayData() const
{
	return payRate;
}

double wages::getTaxRate() const
{
	return taxRate;
}

double wages::getHoursWorked() const
{
	return hoursWorked;
}

//**** Setters ****

void wages::setPayData(double pay)
{
	if(pay >= 0 && pay <= MAX_PAY_RATE){
		payRate = pay;
	}
	else{
		cout << "Error:- invalid pay rate." << endl;
	}
	//Sets the payRate to be the passed pay if it is in the range [0, MAX_PAY_RATE]
	//Else prints an error message
}

void wages::setHoursWorked(double hours)
{
	if(hours >= 0 && hours <= MAX_HOURS){
		hoursWorked = hours;
	}
	else{
		cout << "Error:- invalid Hours worked." << endl;
	}
	//Sets the hoursWorked to be the passed pay if it is in the range [0, MAX_HOURS]
	//Else prints an error message
}

void wages::setTaxRate(double tax)
{
	if(tax >= 0 && tax <= MAX_TAX_RATE){
		taxRate = tax;
	}
	else{
		cout << "Error:- invalid tax rate." << endl;
	}
	//Sets the taxRate to be the passed pay if it is in the range [0, MAX_TAX_RATE]
	//Else prints an error message
}