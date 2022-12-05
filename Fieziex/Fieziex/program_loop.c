#include "program_main.h"

#include "system.h"
#include "input.h"



void program_loop()
{
	SDL_SetRenderTarget(main_renderer, main_texture);
	SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);
	SDL_RenderClear(main_renderer);


}
