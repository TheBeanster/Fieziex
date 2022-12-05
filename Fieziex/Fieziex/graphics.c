#include "graphics.h"

#include <SDL.h>
#include "system.h"

#define DRAWCIRCLE_RECTS 1

void DrawCircle(const double x, const double y, const double radius)
{
#if DRAWCIRCLE_RECTS
	SDL_Rect rect = { (int)(x - radius), (int)(y - radius), (int)radius * 2, (int)radius * 2 };
	SDL_RenderDrawRect(main_renderer, &rect);
#else
	int radiussq = radius * radius;
	for (int iy = -radius; iy < radius; iy++)
	{
		int iysq = iy * iy;
		for (int ix = -radius; ix < radius; ix++)
		{
			int d = ix * ix + iysq;
			if (d < radiussq)
			{
				SDL_RenderDrawPoint(main_renderer, x + ix, y + iy);
			}
		}
	}
#endif
}
