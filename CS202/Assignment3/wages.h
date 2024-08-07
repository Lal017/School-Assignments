#ifndef WAGES_H
#define WAGES_H

#include <iostream>
#include <iomanip>
#include <string>


/**
 * @brief
 *
 */
class wages
{
    double payRate=0.0;
    double taxRate=0.0;
    double hoursWorked=0.0;

public:
    wages(double payRate = 0.0, double taxRate = 0.0, double hoursWorked = 0.0);
    double getPayData() const;
    double getTaxRate() const;
    double getHoursWorked() const;
    void setPayData(double);
    void setHoursWorked(double);
    void setTaxRate(double);
    static constexpr double MEDICARE_TAX = 1.45;
    static constexpr double SOCIAL_SECURITY_TAX = 6.2;
    static constexpr int MAX_HOURS = 80;
    static constexpr double MAX_PAY_RATE = 2500.0;
    static constexpr double MAX_TAX_RATE = 50.0;
};

#endif // WAGES_H