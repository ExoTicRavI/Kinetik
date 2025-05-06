#include <setup.h>
#include <SDL3/SDL.h>
#include <stdint.h>
#include <window_resize.h>
#include <render.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int setup() {
    SDL_SetAppMetadata("Kinetik", "1.0", "kinetik.com");

    const int MIN_WIN_WIDTH = 800;
    const int MIN_WIN_HEIGHT = 500;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initilize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Kinetic", MIN_WIN_WIDTH, MIN_WIN_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
    }

    SDL_SetWindowAspectRatio(window, 16.0f / 10.0f, 16.0f / 10.0f);
    SDL_SetWindowMinimumSize(window, MIN_WIN_WIDTH, MIN_WIN_HEIGHT);

    SET_NEW_WINDOW_DIMENSIONS();


    return SDL_APP_CONTINUE;
}