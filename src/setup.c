#include <setup.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_main.h>
#include <stdint.h>

int WIN_WIDTH;
int WIN_HEIGHT;
SDL_FRect MENU_POSITION;

void setup(SDL_Window *window,SDL_Renderer *renderer) {
    SDL_GetWindowSize(window, &WIN_WIDTH, &WIN_HEIGHT);

    SDL_FRect GameBox;
    SDL_Texture *menuTexture;

    SDL_SetRenderDrawColor(renderer, 34, 139, 34, SDL_ALPHA_TRANSPARENT);
    
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_TRANSPARENT);  /* blue, full alpha */
    GameBox.w = WIN_WIDTH - 8;
    GameBox.h = WIN_HEIGHT - 8;
    GameBox.x = 4;

    GameBox.y = 4;

    SDL_RenderFillRect(renderer, &GameBox);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderLine(renderer, 4, 4, GameBox.w + 4, 4);
    SDL_RenderLine(renderer, 4, 4, 4, GameBox.h + 4);
    SDL_RenderLine(renderer, GameBox.w + 4, GameBox.h + 4, GameBox.w + 4, 4);
    SDL_RenderLine(renderer, GameBox.w + 4, GameBox.h + 4, 4, GameBox.h + 4);

    menuTexture = IMG_LoadTexture(renderer, "./src/menu_icon.bmp");

    if (menuTexture == NULL) {
        SDL_Log("Couldn't create menuTexutre: %s", SDL_GetError());
    }

    MENU_POSITION.x = GameBox.w + 4 -35;
    MENU_POSITION.y = 4;
    MENU_POSITION.w = MENU_POSITION.h = 35;

    SDL_RenderTexture(renderer, menuTexture, NULL, &MENU_POSITION);

    SDL_RenderPresent(renderer);

}

