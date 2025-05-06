#ifndef SETUP_H
#define SETUP_H

#include <SDL3/SDL.h>
#include <stdint.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;

int setup(void);

#endif // SETUP_H