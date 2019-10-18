#include "linetype.h"

void lineType::setSlope(double a, double b)
{
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
		slope = a * -1 / b;
		// cout << slope;
		skip;
	}
}

// This function returns and displays the slope.
void lineType::getSlope() {
	cout << "This is your slope: ";
	skip;
	cout << slope;
	skip;
	cout << "Y = " << slope << "x + " << c;
}
