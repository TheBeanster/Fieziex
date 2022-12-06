#include "program_main.h"

#include "system.h"
#include "input.h"
#include <stdio.h>
#include "utility.h"

#include "graphics.h"
#include "physics.h"



void ProgramLoop()
{
	SDL_SetRenderTarget(main_renderer, main_texture);
	SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);
	SDL_RenderClear(main_renderer);

	TIMER_START(physics);
	UpdatePhysics();
	TIMER_END(physics);
	PRINT_TIMER(physics);
	printf(", ");

	TIMER_START(render);
	DrawScene();
	TIMER_END(render);
	PRINT_TIMER(render);
	printf("\n");
}
