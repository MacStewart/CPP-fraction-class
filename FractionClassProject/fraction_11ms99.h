/*
Mac Stewart - 11ms99 - 10043669
Compiled in Visual Studio 2013 on Windows 8.1
*/

#pragma once

#include <string>
#include <iostream>

using namespace std;

class FractionException {		//Thrown when denominator of fraction is set to 0
public:
	FractionException(const string&);
	string& what();
private:
	string message;
};

class InputNotNumException {	//Throw when string to integer converter is unable to turn given input into an integer
public:
	InputNotNumException(const string&);
	string& what();
private:
	string message;
};

class Fraction {
public:
	Fraction();				//Default constructor sets fraction equal to 0/1
	Fraction(int);			//Sets numerator equal to given int, and denominator equal to 1
	Fraction(int, int);		//Sets fraction equal to first given int / second given int. Throws Fraction Exception if second given int is 0
	int numerator() const;	//accessor for numerator
	int denominator() const;	//accessor for denominator

	Fraction& operator+=(const Fraction& rhs);	
	Fraction& operator++();		//Pre Increment		
	Fraction operator++(int);	//Post Incrememnt	

private:
	int mNumerator;
	int mDenominator;
	int getGCD(int first, int second) const;	//Gets the greatest common denominator of the two given integers
	void normalizeFraction();					//Reduces fraction to atomic form, and ensures that if the fraction is negative, that the numerator is the negative value rather than the denominator.
};

Fraction operator-(const Fraction& fraction);

Fraction operator+(const Fraction& lhs, const Fraction& rhs);
Fraction operator-(const Fraction& lhs, const Fraction& rhs);
Fraction operator*(const Fraction& lhs, const Fraction& rhs);
Fraction operator/(const Fraction& lhs, const Fraction& rhs);

bool operator<(const Fraction& lhs, const Fraction& rhs);
bool operator<=(const Fraction& lhs, const Fraction& rhs);
bool operator==(const Fraction& lhs, const Fraction& rhs);
bool operator!=(const Fraction& lhs, const Fraction& rhs);
bool operator>=(const Fraction& lhs, const Fraction& rhs);
bool operator>(const Fraction& lhs, const Fraction& rhs);

istream& operator>>(istream& in, Fraction& fraction);
int stringToInt(const string& str);				//Converts given string into an integer. Throws InputNotNumException if it is unable to convert to integer.
ostream& operator<<(ostream& out, const Fraction& fraction);
