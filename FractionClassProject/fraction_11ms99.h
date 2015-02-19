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
	int getNumerator() const;
	int getDenominator() const;

	Fraction& operator+=(const Fraction& rhs);
	Fraction& operator++();		//Pre Increment
	Fraction operator++(int);	//Post Incrememnt

private:
	int numerator;
	int denominator;
	int getGCD(int first, int second) const;
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs);
Fraction operator-(const Fraction& lhs, const Fraction& rhs);
Fraction operator*(const Fraction& lhs, const Fraction& rhs);
Fraction operator/(const Fraction& lhs, const Fraction& rhs);
ostream& operator<<(ostream& out, const Fraction& fraction);