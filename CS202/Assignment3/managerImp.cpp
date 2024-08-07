/*
Name: Eduardo Salazar, 5005695833 ,Section 1003, Assignment 3
Description: put data pertaining to employees in classes
Input: names, ids and employee status
Output: pay stub for employees
*/
#include "manager.h"
#include <string>

using namespace std;

manager::manager(string first, string last, double pyRt, string empId,
	eStats es, double  taxRt, double bonus) : employee(first, last, pyRt, empId, es, taxRt)
	//TODO: Call the base class constructor here (before the function body)
{
    setBonusPct(bonus);
	//All that needs initialized in the body is the newly 
	//added bonusPercentage member
}

double manager::grossPay() const
{
	double normalHours = wagesObj.getHoursWorked();
    double payRate = wagesObj.getPayData();

    double gross;
	
	if(normalHours <= 0){
		return 0;
	}
	else{
		gross = (normalHours * payRate);

    	return gross;
	}
	//Find gross pay in a similar way to the 
	//employee, except always assume the manager worked 40 hours.
	//Remember that you can find the money earned by multiplying the hourly wage
	//by the hours worked
	//If they worked 0, just return 0
}

double manager::takeHomePay()
{
	double gPay = this->grossPay(); //Grab the gross pay once
    double total;

    medicare = gPay / 100.0 * wages::MEDICARE_TAX; //Constants belong to wages class

    socialSecurity = gPay / 100.0 * wages::SOCIAL_SECURITY_TAX;

    federalTax = gPay / 100.0 * wagesObj.getTaxRate();

    total = gPay - medicare - socialSecurity - federalTax;

    return total;
	//This should be the exact same code as the employee version.
	//Since we're not using virtuals, you do have to rewrite the exact
	//Same function to get the overloaded functionality
}

double manager::bonusPay() const
{
	return getPayRate();
	//Directly returns the result of calling the employee base class's
	//getPayRate() function?
}

void manager::showPayStub()
{
	double takeHome = takeHomePay(); //Get the take home pay first

    //Print all of the member variables and relevant data
    cout << setw(DASH_LENGTH) << setfill('-') << "" << endl << setfill(' ');
    cout << "Name: " << getLastName() << ", " << getFirstName() << setw(30) << right << "Status: "
    << employmentStatusToString(getEmploymentStatus()) << endl;
    cout << setw(LEFT_WIDTH) << left << "Manager Gross Pay:" << setprecision(2) << fixed << grossPay() << endl;
    cout << setw(LEFT_WIDTH) << left << "GetHoursWorked: " << wagesObj.getHoursWorked() << endl;
    cout << setw(TAB_LENGTH) << left << "" << "Withholding" << endl;
    cout << setw(2 * TAB_LENGTH) << "" << setw(LEFT_WIDTH) << left << "Medicare:"
    << setprecision(2) << fixed << medicare << endl;
    cout << setw(2 * TAB_LENGTH) << "" << setw(LEFT_WIDTH) << left << "Social Security:"
    << setprecision(2) << fixed <<  socialSecurity << endl;
    cout << setw(2 * TAB_LENGTH) << "" << setw(LEFT_WIDTH) << left << "Federal Tax:" 
    << setprecision(2) << fixed << federalTax << endl;
    cout << setw(TAB_LENGTH) << "" << setw(LEFT_WIDTH + TAB_LENGTH) << left << "Take Home Pay:"
    << setprecision(2) << fixed <<  takeHome << endl;

	cout << "Bonus Amount:" << setw(14) << right << getBonusPct() << endl;
	cout << setw(TAB_LENGTH) << left << "" << "Witholding" << endl;
	cout << setw(2 * TAB_LENGTH) << "" << setw(LEFT_WIDTH) << left << "Federal Tax:" 
    << setprecision(2) << fixed << ((getBonusPct()/100)*BONUS_TAX_RATE) << endl;
	cout << setw(2 * TAB_LENGTH) << "" << setw(LEFT_WIDTH) << left << "Bonus Check Amount:" 
    << setprecision(2) << fixed << getBonusPct()-((getBonusPct()/100)*BONUS_TAX_RATE) << endl;
	//Should show the employee pay stub with some extra info added on
	//Unfortunately, since we are not using virtuals and the manager
	//Has a different grossPay, you will need to copy-paste the same
	//code instead of just using the function call...
	
	//Note that the bonus amount is a percentage of the gross pay.
	//Use the manager bonusPercentage member to find this (divide by 100 for percents)
	//Then use this with the tax rate for the rest of the calculations (also divide by 100)
}

//Setter for our new class member, the bonus percent
void manager::setBonusPct(double bonus)
{
	if(bonus >= 0 && bonus <= MAX_BONUS_PCT){
		bonusPercentage = bonus;
	}
	else{
		cout << "Error :- Invalid Bonus Percentage." << endl;
	}
	//Set the bonusPercentage if it is in the range [0, MAX_BONUS_PCT]
	//Else print an error message
}

double manager::getBonusPct() const
{
	double total;

	total = grossPay() * bonusPercentage;

	total = total / 100;

	return total;
}

void manager::setHoursWorked(double hrs)
{
	//Sets the manager hours to 40.0 regardless of how many hours they actually worked
	//Unless they worked 0 hours, in which case set it to 0

	if(hrs != 0){
		wagesObj.setHoursWorked(40.0);
	}
	else{
		wagesObj.setHoursWorked(0);
	}

	//TODO: Finish this function
}
