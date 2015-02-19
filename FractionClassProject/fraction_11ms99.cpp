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
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int num) {
	numerator = num;
	denominator = 1;
}

Fraction::Fraction(int num, int denom) {
	int GCD = getGCD(num, denom);
	if (GCD != 1) {
		num /= GCD;
		denom /= GCD;
	}
	numerator = num;
	denominator = denom;
}

int Fraction::getNumerator() const {
	return numerator;
}

int Fraction::getDenominator() const {
	return denominator;
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

