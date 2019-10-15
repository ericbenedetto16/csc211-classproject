#ifndef LINETYPE_H
#define LINETYPE_H
#define skip cout << endl;

// This includes all of the libraries we need.
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void initializeGui();

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

#endif