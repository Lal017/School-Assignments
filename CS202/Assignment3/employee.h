#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "wages.h"
#include <string>

using namespace std;

// common function
/**
 * @brief
 *
 */

//Enumeration for the status of an employee
enum eStats
{
    FULLTIME,
    PARTTIME,
    CASUAL,
    NONE
};


/**
 * @brief
 *
 */
class employee
{
    string lastName, firstName;
    string employeeID;
    eStats employementStatus;
    
    bool checkID(string) const;

protected:
    //ADDED: Not in rubric
    //Used to avoid doing extra calculations after take home pay function is called
    //Use these in takeHomePay rather than making locals
    double medicare, socialSecurity, federalTax;

    //Formatting constants for your convenience
    const int DASH_LENGTH = 70; //Number of dashes at beginning of pay stub print
    const int LEFT_WIDTH = 25; //Constant for formatting text to the left
    const int TAB_LENGTH = 5; //Can be used to space things out consistently


public:
    wages wagesObj;

    employee(string last = "", string first = "", double pyRt = 0.0,
             string empID = "", eStats es = NONE, double taxRt = 0.0);

    string getLastName() const;
    string getFirstName() const;
    double getPayRate() const;
    string getEmployeeID() const;
    eStats getEmploymentStatus() const;
    double getTaxRate() const;
    double getHoursWorked() const;
    void setEmployeeName(string lst, string frst);
    void setPayRate(double newPayRate);
    void setEmployeeID(string newID);
    void setEmploymentStatus(eStats newStat);
    void setTaxRate(double newRate);
    void setHoursWorked(double hrs);
    double grossPay() const;
    double takeHomePay();
    void showPayStub();
    //Helper function to get eStats enum as a string
    string employmentStatusToString(eStats status);
};

#endif // EMPLOYEE_H