/*
Mac Stewart - 11ms99 - 10043669
Compiled in Visual Studio 2013 on Windows 8.1
*/

using namespace std;

#include "fraction_11ms99.h"

FractionException::FractionException(const string& msg) : message(msg) {

}

string& FractionException::what() {
	return message;
}

Fraction::Fraction() {
	mNumerator = 0;
	mDenominator = 1;
}

Fraction::Fraction(int num) {
	mNumerator = num;
	mDenominator = 1;
}

Fraction::Fraction(int num, int denom) {
	if (denom == 0) {
		throw FractionException("Denominator cannot be zero");
	}
	mNumerator = num;
	mDenominator = denom;
	normalizeFraction();
}

int Fraction::numerator() const {
	return mNumerator;
}

int Fraction::denominator() const {
	return mDenominator;
}

int Fraction::getGCD(int first, int second) const {
	if (second <= first && first%second == 0) {
		return second;
	}
	else if (second > first) {
		return getGCD(second, first);
	}
	else {
		return getGCD(second, first%second);
	}
}

void Fraction::normalizeFraction() {
	if (mDenominator < 0) {		//If both are negative, both are flipped (both to positive). If only denom is negative, both are also flipped (num to negative, denom to positive).
		mNumerator = -mNumerator;
		mDenominator = -mDenominator;
	}
	int GCD = getGCD(abs(mNumerator), mDenominator);
	if (GCD != 1) {
		mNumerator /= GCD;
		mDenominator /= GCD;
	}
}

Fraction& Fraction::operator+=(const Fraction& rhs) {
	int numToAdd = rhs.mNumerator*mDenominator;
	mNumerator = mNumerator*rhs.mDenominator + numToAdd;
	mDenominator = mDenominator*rhs.mDenominator;
	normalizeFraction();
	return *this;
}

Fraction& Fraction::operator++() {
	mNumerator++;
	normalizeFraction();
	return *this;
}

Fraction Fraction::operator++(int unused) {
	Fraction copy(mNumerator, mDenominator);
	mNumerator++;
	normalizeFraction();
	return copy;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	int numerator = (lhs.numerator()*rhs.denominator()) + (rhs.numerator()*lhs.denominator());
	int denominator = lhs.denominator()*rhs.denominator();
	return Fraction(numerator, denominator);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
	int numerator = (lhs.numerator()*rhs.denominator()) - (rhs.numerator()*lhs.denominator());
	int denominator = lhs.denominator()*rhs.denominator();
	return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	int numerator = lhs.numerator()*rhs.numerator();
	int denominator = lhs.denominator()*rhs.denominator();
	return Fraction(numerator, denominator);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
	int numerator = lhs.numerator()*rhs.denominator();
	int denominator = lhs.denominator()*rhs.numerator();
	return Fraction(numerator, denominator);
}


ostream& operator<<(ostream& out, const Fraction& fraction) {
	out << fraction.numerator() << "/" << fraction.denominator();
	return out;
}



