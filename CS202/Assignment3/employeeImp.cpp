/*
Name: Eduardo Salazar, 5005695833 ,Section 1003, Assignment 3
Description: put data pertaining to employees in classes
Input: names, ids and employee status
Output: pay stub for employees
*/
#include "employee.h"
#include "wages.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

employee::employee(string last, string first, double pyRt,
    string empID, eStats es, double taxRt)
{
    setEmployeeName(last,first);
    setEmploymentStatus(es);

    setEmployeeID(empID);

    wagesObj.setPayData(pyRt);
    wagesObj.setTaxRate(taxRt);
    wagesObj.setHoursWorked(0);

    //Initialize all variables. It's recommended to use existing setters

    //Initialize the first name, last name, and employment status

    //Set the members of the wageObj using the setters
    //pyRt is the payRate, taxRt is the tax rate, and the hours worked should be 0

    //Set the employee ID using the empID
}

//Checks if a string id is valid
bool employee::checkID(string id) const
{
    //Check the first character
    if (id[0] < 'A' || id[0] > 'Z' || id.length() != 6){
        return false;
    }

    //Make sure the next 5 characters are digits
    for (int i = 1; i < 6; i++){
        if (!isdigit(id[i])){
            return false;
        }
    }

    return true;
}

//**** Getters ****
string employee::getLastName() const
{
    return lastName;
}

string employee::getFirstName() const
{
    return firstName;
}

double employee::getPayRate() const
{
    return wagesObj.getPayData();
    //Return the pay rate from the wagesObj
    //Remember that its members are private; use an accessor
}

double employee::getTaxRate() const
{
    return wagesObj.getTaxRate();
}

double employee::getHoursWorked() const
{
    return wagesObj.getHoursWorked();
}

string employee::getEmployeeID() const
{
    return employeeID;
}

eStats employee::getEmploymentStatus() const
{
    return employementStatus;
}

//**** Setters ****
void employee::setEmployeeName(string lst, string frst)
{
    firstName = frst;
    lastName = lst;
}

void employee::setEmployeeID(string newID)
{
    if(checkID(newID) == true){
        employeeID = newID;
    }
    else{
        cout << "Error :- invalid EmployeeID" << endl;
    }
    //Check that the id is correct and if not print an error message, otherwise just set
}

void employee::setEmploymentStatus(eStats newStat)
{
    employementStatus = newStat;
}

void employee::setPayRate(double newPayRate)
{
    //Set the pay rate of the wagesObj using its setter
    wagesObj.setPayData(newPayRate);
}

void employee::setTaxRate(double newRate)
{
    wagesObj.setTaxRate(newRate);
}

void employee::setHoursWorked(double hrs)
{
    wagesObj.setHoursWorked(hrs);
}

double employee::grossPay() const
{
    double normalHours = wagesObj.getHoursWorked(); //50
    double payRate = wagesObj.getPayData(); // 25
    double extraHours = 0;
    double i = 0;
    double gross;

    while(normalHours > 40.0){
        normalHours--;
        i++;
    }

    extraHours = i;

    gross = ((normalHours * payRate) + (extraHours * (payRate / 2.0)));

    return gross;

    //TODO: Finish using the calculation from the rubric
}

double employee::takeHomePay()
{
    double gPay = this->grossPay(); //Grab the gross pay once
    double total;

    medicare = gPay / 100.0 * wages::MEDICARE_TAX; //Constants belong to wages class

    socialSecurity = gPay / 100.0 * wages::SOCIAL_SECURITY_TAX;

    federalTax = gPay / 100.0 * wagesObj.getTaxRate();

    total = gPay - medicare - socialSecurity - federalTax;

    return total;

    //TODO: Finish the caluclations
    //(gPay - medicare - socialSecurity - federalTax)
    //Medicare and ss taxes are constants in wages class, tax rate is stored in
    //a wages object

    //Then return the takeHomePay by taking parts out of the gross pay

}

 //Prints all of the class members using the format from the rubric
void employee::showPayStub()
{
    double takeHome = takeHomePay(); //Get the take home pay first

    //Print all of the member variables and relevant data
    cout << setw(DASH_LENGTH) << setfill('-') << "" << endl << setfill(' ');
    cout << "Name: " << lastName << ", " << firstName << setw(30) << right << "Status: "
    << employmentStatusToString(employementStatus) << endl;
    cout << setw(LEFT_WIDTH) << left << "Employee Gross Pay:" << setprecision(2) << fixed << grossPay() << endl;
    cout << setw(LEFT_WIDTH) << left << "GetHoursWorked: " << wagesObj.getHoursWorked() << endl;
    cout << setw(TAB_LENGTH) << left << "" << "Withholding" << endl;
    cout << setw(2 * TAB_LENGTH) << "" << setw(LEFT_WIDTH) << left << "Medicare:"
    << setprecision(2) << fixed << medicare << endl;
    cout << setw(2 * TAB_LENGTH) << "" << setw(LEFT_WIDTH) << left << "Social Security:"
    << setprecision(2) << fixed <<  socialSecurity << endl;
    cout << setw(2 * TAB_LENGTH) << "" << setw(LEFT_WIDTH) << left << "Federal Tax:" 
    << setprecision(2) << fixed << federalTax << endl;
    cout << setw(TAB_LENGTH) << "" << setw(LEFT_WIDTH + TAB_LENGTH) << left << "Take Home Pay:"
    << setprecision(2) << fixed << takeHome << endl;
}

//ADDED Helper function not from rubric to easily convert from employment
//status enum to a string
string employee::employmentStatusToString(eStats status)
{
    switch (status)
    {
        case eStats::FULLTIME:
            return "FULLTIME";
        case eStats::PARTTIME:
            return "PARTTIME";
        case eStats::CASUAL:
            return "CASUAL";
        case eStats::NONE:
            return "NONE";
        default:
            return "UNKNOWN";
    }
}