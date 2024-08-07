#ifndef COMPLEX_H
#define COMPLEX_H true

#include <iostream>
#include <string>

using namespace std;

const double PI = 3.141592653589793;

//Class that represents a 2D complex number of the form a + bi
struct ComplexNumber
{
	double real, imaginary;
	//Helper functions
	double magnitude();
	void normalize();
	string toString() const;
	double getDegrees() const;

	//Constructor
	ComplexNumber(double a = 0.0, double b = 0.0) { real = a; imaginary = b; }

	//Operator overloads
	friend ComplexNumber operator + (ComplexNumber left, ComplexNumber right);
	friend ComplexNumber operator * (ComplexNumber left, ComplexNumber right);
	friend ComplexNumber operator * (double scalar, ComplexNumber right);
	friend ostream& operator << (ostream& out, const ComplexNumber& cn);
	friend istream& operator >> (istream& in, ComplexNumber& cn);
};

#endif