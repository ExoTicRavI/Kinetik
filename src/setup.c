#include <setup.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

const int BOARD_WIDTH = 1000;
const int BOARD_HEIGHT = 625;
static int WINDOW_WIDTH = 1000;
static int WINDOW_HEIGHT = 625;

void setup(SDL_Window *window,SDL_Renderer *renderer) {
    SDL_GetWindowSize(window, &WINDOW_WIDTH, &WINDOW_HEIGHT);

    SDL_FRect GameBox;

    SDL_SetRenderDrawColor(renderer, 34, 139, 34, SDL_ALPHA_TRANSPARENT);
    
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_TRANSPARENT);  /* blue, full alpha */
    GameBox.w = 992.0f;
    GameBox.h = 617.0f;
    GameBox.x = (WINDOW_WIDTH - GameBox.w) / 2.0f;
    GameBox.y = (WINDOW_HEIGHT - GameBox.h) / 2.0f;

    SDL_RenderFillRect(renderer, &GameBox);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderLine(renderer, GameBox.x, GameBox.y, 992.0f + GameBox.x, GameBox.y);
    SDL_RenderLine(renderer, GameBox.x, GameBox.y, GameBox.x, 617.0f + GameBox.y);
    SDL_RenderLine(renderer, 992.0f + GameBox.x, 617.0f + GameBox.y, 992.0f + GameBox.x, GameBox.y);
    SDL_RenderLine(renderer, 992.0f + GameBox.x, 617.0f + GameBox.y, GameBox.x, 617.0f + GameBox.y);

    
    SDL_RenderPresent(renderer);

}

