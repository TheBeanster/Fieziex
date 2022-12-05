#include "object.h"

#include <stdlib.h>
#include <stdio.h>

#include "random.h"



Vector physobjects = { 0 };

int InitObjects()
{
	InitVector(&physobjects, 2000);

	for (int i = 1; i < 1200; i++)
	{
		CreatePhysObject(
			RandomRange(10, 600),
			RandomRange(10, 300),
			RandomRange(-1, 1),
			RandomRange(-1, 1),
			RandomRange(4, 7)
		);
	}

	PhysObject* cursorobj = physobjects.items[0];
	cursorobj->x = 0;
	cursorobj->y = 0;
	cursorobj->velx = 0;
	cursorobj->vely = 0;
	cursorobj->radius = 50;

	return 0;
}



PhysObject* CreatePhysObject(const double x, const double y, const double velx, const double vely, const double radius)
{
	PhysObject* obj = malloc(sizeof(PhysObject));
	obj->x = x;
	obj->y = y;
	obj->velx = velx;
	obj->vely = vely;
	obj->newx = 0.0;
	obj->newy = 0.0;
	obj->newvelx = 0.0;
	obj->newvely = 0.0;
	obj->collisioncount = 0;
	obj->radius = radius;
	PushFrontVector(&physobjects, obj);
	return obj;
}
