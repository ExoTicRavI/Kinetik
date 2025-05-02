#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdint.h>
#include <setup.h>
#include <keyboard.h>
#include <mouse.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    (void)appstate;
    (void)argc;
    (void)argv;

    const int MIN_WIN_WIDTH = 800;
    const int MIN_WIN_HEIGHT = 500;

    SDL_SetAppMetadata("Kinetik", "1.0", "kinetik.com");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initilize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Kinetic", MIN_WIN_WIDTH, MIN_WIN_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
    }

    SDL_SetWindowAspectRatio(window, 16.0f / 10.0f, 16.0f / 10.0f);
    SDL_SetWindowMinimumSize(window, MIN_WIN_WIDTH, MIN_WIN_HEIGHT);

    setup(window, renderer);

    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    (void)appstate;
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS; // end the program, reporting success to the os
    }

    if (event->type == SDL_EVENT_WINDOW_RESIZED) {
        setup(window, renderer);
    }

    if (event->type == SDL_EVENT_KEY_DOWN || event->type == SDL_EVENT_KEY_UP) {
        handleKeypress(event);
    }

    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        check_hover();
    }

    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void *appstate) {
    (void)appstate;

    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    (void)appstate;
    (void)result;
    // SDL will clean up the window/renderer for us
}