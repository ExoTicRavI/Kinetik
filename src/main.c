#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdint.h>
#include <setup.h>
#include <keyboard.h>
#include <mouse.h>
#include <render.h>
#include <window_resize.h>

int HIT_BOARD_SPEED = 5;
static Uint64 last_time = 0;
static Uint64 current_time = 0;
static double delta_time = 0.0;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    (void)appstate;
    (void)argc;
    (void)argv;

    setup();
    SDL_RenderClear(renderer);

    // RENDER_GameBox();
    // RENDER_MenuIcon();

    RENDER_HitBoards();

    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    (void)appstate;
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS; // end the program, reporting success to the os
    }

    if (event->type == SDL_EVENT_WINDOW_RESIZED)
    {
        SET_NEW_WINDOW_DIMENSIONS();
        MENU_SHOWN = true;
        SDL_RenderClear(renderer);
        RENDER_Menu();
        SDL_RenderPresent(renderer);
        MENU_SHOWN = false;
    }

    if (event->type == SDL_EVENT_KEY_DOWN || event->type == SDL_EVENT_KEY_UP)
    {
        handleKeypress(event);
    }

    if (event->type == SDL_EVENT_MOUSE_MOTION)
    {
        check_hover();
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN)
    {
        if (event->button.button == SDL_BUTTON_LEFT && SDL_PointInRectFloat(&mousePosition, &MENU_TOGGLE_BUTTON))
        {
            SDL_RenderClear(renderer);
            RENDER_Menu();
            SDL_RenderPresent(renderer);
            MENU_SHOWN = !MENU_SHOWN;
        }
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    current_time = SDL_GetPerformanceCounter();

    if (last_time == 0)
    {
        last_time = current_time;
    }

    delta_time = (double)(current_time - last_time) / SDL_GetPerformanceFrequency();
    last_time = current_time;

    // Pass delta_time to your movement
    MOVE_HitBoards(delta_time);

    (void)appstate;
    MOVE_HitBoards(delta_time);

    SDL_RenderClear(renderer);
    RENDER_HitBoards();
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    (void)appstate;
    (void)result;

    // SDL will clean up the window/renderer for us
}