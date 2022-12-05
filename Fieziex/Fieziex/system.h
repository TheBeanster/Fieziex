#pragma once

#include <SDL.h>



extern SDL_Window* main_window;
extern SDL_Renderer* main_renderer;
extern SDL_Texture* main_texture;

extern int screenwidth;
extern int screenheight;

extern int framecount;



// Initialize system setup
// \returns 1 on success, 0 on failure
int SystemInit();

void UpdateWindow();

void SystemQuit();

void ShowErrorbox(const char* title, const char* message);
void ShowSDLErrorbox();
