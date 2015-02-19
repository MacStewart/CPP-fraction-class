#pragma once

#include <string>
#include <iostream>

using namespace std;

class FractionException {
public:
	FractionException(const string&);
	string& what();
private:
	string message;
};

class Fraction {
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);
	int numerator() const;
	int denominator() const;

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

ostream& operator<<(ostream& out, const Fraction& fraction);