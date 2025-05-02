#ifndef SETUP_H
#define SETUP_H

#include <SDL3/SDL.h>
#include <stdint.h>

extern int WIN_WIDTH;
extern int WIN_HEIGHT;
extern SDL_FRect GAME_BOX;
extern SDL_FRect MENU;

void setup(SDL_Window *window,SDL_Renderer *renderer);

#endif // SETUP_H