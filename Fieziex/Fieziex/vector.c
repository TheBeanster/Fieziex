#include "vector.h"

#include <stdlib.h>



int InitVector(Vector* const vec, int maxitems)
{
	vec->maxitems = 1000;
	vec->items = malloc(vec->maxitems * sizeof(void*));
	vec->itemcount = 0;
	return 1;
}



int ResizeVector(Vector* const vec, int maxitems)
{
	void** items = realloc(vec->items, sizeof(void*) * maxitems);
	vec->items = items;
	vec->maxitems = maxitems;
	return 1;
}



int PushFrontVector(Vector* const vec, const void* const item)
{
	if (vec->itemcount == vec->maxitems)
	{
		ResizeVector(vec, vec->maxitems * 2);
		vec->items[vec->itemcount++] = item;
	} else
	{
		vec->items[vec->itemcount++] = item;
	}
	return 1;
}
