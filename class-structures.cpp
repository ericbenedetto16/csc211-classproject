#include "lineType.h"

double lineType::Test(ifstream& infile) {

// This includes all of the libraries we need.
#include <iostream>
#include <cmath>
#include <iomanip>
// #include <string>
#include <fstream>

#define skip cout << endl;

using namespace std;

class lineType {
public:
	// Display the slope to make sure the slope value is correct.
	void getSlope(double);
	// Set the slope - X1, X2, Y1, Y2.
	void setSlope(double, double);
	// Boolean to check if the slope is perpendicular or not. False if it isn't.
	bool perpendicular();
	// Boolean to check if the slope if parallel or not. False if it isn't.
	bool parallel();
	// Boolean to check if the slopes are equal or not.
	bool equal();
	double findIntersection();
	double Test(ifstream&);
private:
	double slopeEquation();
	double a, b, c;
	double slope;
};

int main() {

	lineType lineOne;

	ifstream infile;
	infile.open("data.txt");
	if (!infile) {
		cout << "Error opening";
	}
	
	lineOne.Test(infile);
	lineOne.setSlope(10, 2);

	infile.close();

	system("pause");
	return 0;
}

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
