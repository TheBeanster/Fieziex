#pragma once



typedef struct Vector
{
	void** items;
	int maxitems;
	int itemcount;
} Vector;



int InitVector(Vector* const vec, int maxitems);

int ResizeVector(Vector* const vec, int maxitems);

int PushFrontVector(Vector* const vec, const void* const item);
