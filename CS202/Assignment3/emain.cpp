// CS 202
// Assignment #3 - Provided Main
// Uses and tests various functions from the employee class

#include <iostream>
#include <string>

#include "employee.h"

using namespace std;

/**
 * @brief
 *
 * @return int
 */
int main()
{
	// ----------------------------------------------------------------------
	//  Display a simple header...

	string bars = "----------------------------------------------------------------------";

	cout << endl
		 << bars << endl;
	cout << "CS 202 - Assignment #3" << endl;
	cout << "Employee Class Test Program." << endl
		 << endl;

	// ----------------------------------------------------------------------
	//  Declare some employees.

	employee simpson("Simpson", "Homer", 32.0, "E01254", FULLTIME, 23.5);
	employee leonard("Leonard", "Lenny", 33.0, "E18716", PARTTIME, 17.25);
	employee carlson("Carlson", "Carl", 31.0, "E18716", FULLTIME, 21.5);
	employee bouvier("Bouvier", "Selma", 25.0, "E18716", PARTTIME, 14.75);
	employee krabappel("Krabappel", "Edna", 35.0, "E21231", FULLTIME, 15.0);
	employee neahasapeemapetilon("Nahasapeemapetilon", "Apu", 16.0);
	employee groundskeeper("Groundskeeper", "Willie", 8.0, "E87290", FULLTIME, 29.0);
	employee riviera("Riviera", "Nick", 400.0, "E00666", FULLTIME, 22.25);

	employee tempWorker1;
	employee tempWorker2("Gumble", "Barney", 12.0);
	employee casualWorker1("Spuckler", "Cletus", 1.0, "E00000", CASUAL, 27.75);
	employee interviewee("Terwilliger", "Cecil");

	// ----------------------------------------------------------------------
	//  Enter data for temp/casual workers
	tempWorker1.setEmployeeName("Hutz", "Lionel");
	tempWorker1.setPayRate(12.5);
	tempWorker1.setEmployeeID("T12345");
	tempWorker1.setEmploymentStatus(PARTTIME);
	tempWorker1.setTaxRate(12.25);

	tempWorker2.setEmployeeID("T12345");
	tempWorker2.setEmploymentStatus(PARTTIME);
	tempWorker2.setTaxRate(19.5);

	interviewee.setPayRate(22.50);
	interviewee.setEmployeeID("E99999");
	interviewee.setTaxRate(15.5);

	// ----------------------------------------------------------------------
	//  Make some data updates...

	if (carlson.getEmployeeID() == "E18716" && bouvier.getEmployeeID() == "E18716")
		bouvier.setEmployeeID("E18717");

	if (leonard.getEmploymentStatus() == PARTTIME)
		leonard.setEmploymentStatus(FULLTIME);

	if (krabappel.grossPay() < 1500)
		krabappel.setPayRate(krabappel.getPayRate() + 5.0);

	if (carlson.takeHomePay() < 1000)
		carlson.setPayRate(krabappel.getPayRate() + 2.0);

	// ----------------------------------------------------------------------
	//  Enter hours for all workers

	simpson.setHoursWorked(32.0);
	leonard.setHoursWorked(40.0);
	carlson.setHoursWorked(40.0);
	bouvier.setHoursWorked(50.0);
	krabappel.setHoursWorked(40.0);
	neahasapeemapetilon.setHoursWorked(50.0);
	riviera.setHoursWorked(60.0);

	tempWorker1.setHoursWorked(40.0);
	tempWorker2.setHoursWorked(40.0);
	casualWorker1.setHoursWorked(5.0);

	// ----------------------------------------------------------------------
	//  Change name (due to marriage).

	bouvier.setEmployeeName("McClure", bouvier.getFirstName());
	bouvier.setTaxRate(bouvier.getTaxRate() + 2.0);

	// ----------------------------------------------------------------------
	//  Set Apu data and give him a raise.

	neahasapeemapetilon.setEmployeeID("T12345");
	neahasapeemapetilon.setEmploymentStatus(PARTTIME);
	neahasapeemapetilon.setTaxRate(19.5);
	neahasapeemapetilon.setPayRate(neahasapeemapetilon.getPayRate() * 1.2);

	// ----------------------------------------------------------------------
	//  Some error testing -> all of these should be errors...

	employee frink("Frink", "John", 20.0, "E01001", CASUAL, 20.0); // valid

	// id errors
	employee hoover("Hoover", "Elizabeth", 10.0, "a10000", NONE, 25.0);
	employee flanders2("Flanders", "Rod", 32.0, "E1254", FULLTIME, 23.5);
	employee flanders3("Flanders", "Todd", 32.0, "01254", FULLTIME, 25.0);
	frink.setEmployeeID("12345");
	frink.setEmployeeID("C12A45");

	// tax rate errors
	employee flanders4("Flanders", "Maude", 32.0, "E01254", FULLTIME, 93.5);
	frink.setTaxRate(77.25);

	// pay errors
	employee flanders1("Flanders", "Ned", 5000.0, "E01000", FULLTIME, 23.5);
	frink.setPayRate(5001.0);
	frink.setPayRate(-10.0);

	// hours worked errors
	frink.setHoursWorked(90.0);
	frink.setHoursWorked(-10.0);

	// ----------------------------------------------------------------------
	//  Do payroll for all employees

	tempWorker1.showPayStub();
	tempWorker2.showPayStub();
	casualWorker1.showPayStub();
	interviewee.showPayStub();

	simpson.showPayStub();
	leonard.showPayStub();
	carlson.showPayStub();
	bouvier.showPayStub();
	krabappel.showPayStub();
	neahasapeemapetilon.showPayStub();
	groundskeeper.showPayStub();
	riviera.showPayStub();
	return 0;
}
