#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"


using namespace std;

/**
 * @brief
 *
 */
class manager : public employee
{
    double bonusPercentage=0.0;

public:
    manager(string = "", string = "", double = 0.0, string = "", eStats = NONE, double = 0.0, double = 0.0);

    double grossPay() const;
    double bonusPay() const;
    void showPayStub();
    void setBonusPct(double);
    double getBonusPct() const;
    void setHoursWorked(double hrs);
	double takeHomePay();
    static constexpr double BONUS_TAX_RATE = 25.0;
    static constexpr double MAX_BONUS_PCT = 100.0;
};
#endif // MANAGER_H