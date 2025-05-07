#include <SDL3/SDL.h>
#include <setup.h>

SDL_Point WINDOW_DIMENSIONS;

void SET_NEW_WINDOW_DIMENSIONS() {
    SDL_GetWindowSize(window, &WINDOW_DIMENSIONS.x, &WINDOW_DIMENSIONS.y);
}