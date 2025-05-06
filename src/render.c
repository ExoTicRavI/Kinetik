#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <setup.h>
#include <window_resize.h>
#include <stdbool.h>
SDL_FRect GAME_BOX;
SDL_FRect MENU_TOGGLE_BUTTON;
SDL_FRect MENU;
bool PAUSE_MENU_SHOWN = false;

const int margin = 4;

void RENDER_GameBox() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);  /* blue, full alpha */
    GAME_BOX.w = WINDOW_DIMENSIONS.x - margin * 2;
    GAME_BOX.h = WINDOW_DIMENSIONS.y - margin * 2;
    GAME_BOX.x = margin;

    GAME_BOX.y = margin;

    SDL_RenderFillRect(renderer, &GAME_BOX);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Black border
    SDL_RenderLine(renderer, margin, margin, GAME_BOX.w + margin, margin);
    SDL_RenderLine(renderer, margin, margin, margin, GAME_BOX.h + margin);
    SDL_RenderLine(renderer, GAME_BOX.w + margin, GAME_BOX.h + margin, GAME_BOX.w + margin, margin);
    SDL_RenderLine(renderer, GAME_BOX.w + margin, GAME_BOX.h + margin, margin, GAME_BOX.h + margin);
}

void RENDER_MenuIcon() {
    SDL_Texture *menu_toggle_button_texture = IMG_LoadTexture(renderer, "./src/assets/menu_icon.bmp");

    if (menu_toggle_button_texture == NULL) {
        SDL_Log("Couldn't create menu_toggle_button_texture: %s", SDL_GetError());
    }

    MENU_TOGGLE_BUTTON.x = GAME_BOX.w + margin - 35;
    MENU_TOGGLE_BUTTON.y = margin;
    MENU_TOGGLE_BUTTON.w = MENU_TOGGLE_BUTTON.h = 35;
    
    SDL_RenderTexture(renderer, menu_toggle_button_texture, NULL, &MENU_TOGGLE_BUTTON);
}

void RENDER_PauseMenu() {
    RENDER_GameBox();
    RENDER_MenuIcon();

    if (!PAUSE_MENU_SHOWN) {
        SDL_SetRenderDrawColor(renderer, 38, 70, 83, SDL_ALPHA_OPAQUE);

        MENU.w = MENU.h = 200;
        MENU.x = (WINDOW_DIMENSIONS.x - 200) / 2;
        MENU.y = (WINDOW_DIMENSIONS.y - 200) / 2;

        SDL_RenderFillRect(renderer, &MENU);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // set the render color back to black
    }
    
}