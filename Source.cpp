#include "linetype.h"
#include <iostream>

using namespace std;

int main() {

	LineType lineOne;

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