#include "utility.h"

#include <stdlib.h>
#include <time.h>



double get_time(clock_t start, clock_t end)
{
	long delta = end - start;
	return (delta) / (double)CLOCKS_PER_SEC;
}



double RandomRange(double min, double max)
{
	double n = (double)(rand()) / 32786.0;
	n *= (max - min);
	n += min;
	return n;
}
