#pragma once

#include "vector.h"



typedef struct
{
	double x;
	double y;
	double velx;
	double vely;

	double newx;
	double newy;
	double newvelx;
	double newvely;
	int collisioncount;

	double radius;
} PhysObject;

extern Vector physobjects;



int InitObjects();



PhysObject* CreatePhysObject(
	const double x,
	const double y,
	const double velx,
	const double vely,
	const double radius
);
