#include "linetype.h"

bool lineType::perpendicular(double slopeOne, double slopeTwo) {
	if (slopeOne*slopeTwo == -1)
		return true;
	else
		return false;

}
