#include <setup.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_main.h>
#include <stdint.h>

int WIN_WIDTH;
int WIN_HEIGHT;
SDL_FRect GAME_BOX;
SDL_FRect MENU;

void setup(SDL_Window *window,SDL_Renderer *renderer) {
    SDL_GetWindowSize(window, &WIN_WIDTH, &WIN_HEIGHT);

    SDL_Texture *menuTexture;

    SDL_SetRenderDrawColor(renderer, 34, 139, 34, SDL_ALPHA_TRANSPARENT);
    
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_TRANSPARENT);  /* blue, full alpha */
    GAME_BOX.w = WIN_WIDTH - 8;
    GAME_BOX.h = WIN_HEIGHT - 8;
    GAME_BOX.x = 4;

    GAME_BOX.y = 4;

    SDL_RenderFillRect(renderer, &GAME_BOX);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderLine(renderer, 4, 4, GAME_BOX.w + 4, 4);
    SDL_RenderLine(renderer, 4, 4, 4, GAME_BOX.h + 4);
    SDL_RenderLine(renderer, GAME_BOX.w + 4, GAME_BOX.h + 4, GAME_BOX.w + 4, 4);
    SDL_RenderLine(renderer, GAME_BOX.w + 4, GAME_BOX.h + 4, 4, GAME_BOX.h + 4);

    menuTexture = IMG_LoadTexture(renderer, "./src/menu_icon.bmp");

    if (menuTexture == NULL) {
        SDL_Log("Couldn't create menuTexutre: %s", SDL_GetError());
    }

    MENU.x = GAME_BOX.w + 4 -35;
    MENU.y = 4;
    MENU.w = MENU.h = 35;

    
    SDL_RenderTexture(renderer, menuTexture, NULL, &MENU);

    SDL_RenderPresent(renderer);

}

