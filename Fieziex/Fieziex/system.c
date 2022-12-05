#include "system.h"

#include <stdio.h>
#include "input.h"





SDL_Window* main_window = NULL;
SDL_Renderer* main_renderer = NULL;
SDL_Texture* main_texture = NULL;

int screenwidth = 0;
int screenheight = 0;

int framecount = 0;





int SystemInit()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ShowSDLErrorbox();
		return 0;
	}



	// Open the main window
	main_window = SDL_CreateWindow(
		"Fieziex",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);

	// Check if it failed
	if (!main_window)
	{
		ShowSDLErrorbox();
		return 0;
	}





	// Create the main renderer
	main_renderer = SDL_CreateRenderer(
		main_window,
		-1,
		SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC |
		SDL_RENDERER_TARGETTEXTURE
	);

	// Check if it failed
	if (!main_renderer)
	{
		ShowSDLErrorbox();
		return 0;
	}





	// Create the main target texture
	main_texture = SDL_CreateTexture(
		main_renderer,
		SDL_PIXELFORMAT_RGB888,
		SDL_TEXTUREACCESS_TARGET,
		640,
		480
	);

	// Check if it failed
	if (!main_texture)
	{
		ShowSDLErrorbox();
		return 0;
	}

	screenwidth = 640;
	screenheight = 480;





	// Get pointer to the SDL keyboard inputs array
	keyboardinputs = SDL_GetKeyboardState(NULL);



	return 1;
}





void UpdateWindow()
{
	SDL_SetRenderTarget(main_renderer, NULL);
	SDL_RenderCopy(main_renderer, main_texture, NULL, NULL);
	SDL_RenderPresent(main_renderer);
}





void SystemQuit()
{
	SDL_DestroyTexture(main_texture);
	SDL_DestroyRenderer(main_renderer);
	SDL_DestroyWindow(main_window);

	SDL_Quit();
}





void ShowErrorbox(const char* title, const char* message)
{
	SDL_ShowSimpleMessageBox(
		SDL_MESSAGEBOX_ERROR,
		title,
		message,
		NULL);
}

void ShowSDLErrorbox()
{
	SDL_ShowSimpleMessageBox(
		SDL_MESSAGEBOX_ERROR,
		"SDL Error!",
		SDL_GetError(),
		NULL);
}
