#include "physics.h"

#include "system.h"
#include "graphics.h"
#include "input.h"



double gravity = 0.1;

double bounce = -0.1;



void UpdatePhysics()
{
	PhysObject* cursorobj = physobjects.items[0];
	cursorobj->x = mouse_position_x;
	cursorobj->y = mouse_position_y;

	UpdateMovement();
	UpdateCollision();
}



void UpdateMovement()
{
	for (int i = 1; i < physobjects.itemcount; i++)
	{
		PhysObject* obj = physobjects.items[i];

		if(obj->velx > obj->radius) obj->velx = obj->radius;
		if(obj->vely > obj->radius) obj->vely = obj->radius;
		if(obj->velx < -obj->radius) obj->velx = -obj->radius;
		if(obj->vely < -obj->radius) obj->vely = -obj->radius;

		obj->vely += gravity;
		obj->x += obj->velx;
		obj->y += obj->vely;

		if (obj->y + obj->radius >= screenheight)
		{
			obj->y = screenheight - obj->radius;
			obj->vely = obj->vely * bounce;
		}
		if (obj->x + obj->radius >= screenwidth)
		{
			obj->x = screenwidth - obj->radius;
			obj->velx = obj->velx * bounce;
		}
		if (obj->y - obj->radius <= 0)
		{
			obj->y = obj->radius;
			obj->vely = obj->vely * bounce;
		}
		if (obj->x - obj->radius <= 0)
		{
			obj->x = obj->radius;
			obj->velx = obj->velx * bounce;
		}

	}
}



void UpdateCollision()
{
	for (int i = 1; i < physobjects.itemcount; i++)
	{
		PhysObject* obj = physobjects.items[i];
		obj->newx = 0.0;
		obj->newy = 0.0;
		obj->newvelx = 0.0;
		obj->newvely = 0.0;
		obj->collisioncount = 0;
	}

	for (int i = 0; i < physobjects.itemcount; i++)
	{
		PhysObject* a = physobjects.items[i];

		for (int j = i + 1; j < physobjects.itemcount; j++)
		{
			PhysObject* b = physobjects.items[j];

			double dx = a->x - b->x;
			double dy = a->y - b->y;

			// Distance squared
			double d = dx * dx + dy * dy;

			// Combined radius
			double r = a->radius + b->radius;

			// If intersecting
			if (d < r * r)
			{
				d = sqrtf(d);
				dx /= d;
				dy /= d;
				d = r - d;

				double pi = d * (b->radius / r);
				double pj = d * (a->radius / r);

				a->newx += dx * pi;
				a->newy += dy * pi;

				b->newx -= dx * pj;
				b->newy -= dy * pj;

				a->collisioncount++;
				b->collisioncount++;
			}
		}

		a->newvelx = a->velx + a->newx * 1.0;
		a->newvely = a->vely + a->newy * 1.0;

		if (a->collisioncount > 0)
		{
			a->newx /= a->collisioncount;
			a->newy /= a->collisioncount;
		}
	}

	for (int i = 1; i < physobjects.itemcount; i++)
	{
		PhysObject* obj = physobjects.items[i];
		obj->x += obj->newx;
		obj->y += obj->newy;
		obj->velx = obj->newvelx;
		obj->vely = obj->newvely;
	}
}



void DrawScene()
{
	SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255);
	for (int i = 0; i < physobjects.itemcount; i++)
	{
		PhysObject* obj = physobjects.items[i];

		DrawCircle(obj->x, obj->y, obj->radius);
	}
}
