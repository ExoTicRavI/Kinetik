#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdint.h>
#include <setup.h>
#include <keyboard.h>
#include <mouse.h>
#include <render.h>


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    (void)appstate;
    (void)argc;
    (void)argv;

    setup();
    SDL_RenderClear(renderer);

    RENDER_GameBox();
    RENDER_MenuIcon();

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    (void)appstate;
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS; // end the program, reporting success to the os
    }

    if (event->type == SDL_EVENT_WINDOW_RESIZED) {
        
    }

    if (event->type == SDL_EVENT_KEY_DOWN || event->type == SDL_EVENT_KEY_UP) {
        handleKeypress(event);
    }

    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        check_hover();
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        if (event->button.button == SDL_BUTTON_LEFT && SDL_PointInRectFloat(&mousePosition, &MENU_TOGGLE_BUTTON)) {
            SDL_RenderClear(renderer);
            RENDER_PauseMenu();
            SDL_RenderPresent(renderer);
            PAUSE_MENU_SHOWN = !PAUSE_MENU_SHOWN;
        }
        
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