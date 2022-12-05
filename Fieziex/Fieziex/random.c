#include "random.h"

#include <stdlib.h>

double RandomRange(double min, double max)
{
	double n = (double)(rand()) / 32786.0;
	n *= (max - min);
	n += min;
	return n;
}
