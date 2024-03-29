#include "linetype.h"

double lineType::Test(ifstream& infile){
	infile >> a;
	infile >> b;
	infile >> c;
	cout << a;
	skip;
	cout << b;
	skip;
	cout << c;
	skip;
	return a, b, c;
}

void lineType::setSlope(double a, double b) {
	if (a == 0) {
		cout << "The slope is equal to 0";
		skip;
		slope = 0;
		cout << "Your slope is horizontal!";
		skip;
	}
	else if (b == 0) {
		cout << "Your slope is vertical!";
		skip;
	}
	else {
		cout << "This is your slope: ";
		slope = a * -1 / b;
		cout << slope;
		skip;
	}
}
