#include "linetype.h"
#include <windows.h>

bool lineType::parallelTesting(float slopeOne, float slopeTwo) {
	if (slopeOne == slopeTwo) {
		return true;
	}
	else {
		return false;
	}
}

void initializeGui() {
	SetConsoleTitle("Classes Project"); 
}
