#include <mouse.h>
#include <setup.h>
#include <SDL3/SDL.h>

SDL_FPoint mousePosition;

void check_hover() {
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

    if (SDL_PointInRectFloat(&mousePosition, &MENU_POSITION)) {
        SDL_Cursor *cursor_pointer = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_POINTER);
        if (!cursor_pointer) {
            SDL_Log("Failed to create cursor: %s", SDL_GetError());
            return;
        }
        SDL_SetCursor(cursor_pointer);
    } else {
        SDL_Cursor *cursor_normal = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_DEFAULT);
        if (!cursor_normal) {
            SDL_Log("Failed to create cursor: %s", SDL_GetError());
            return;
        }
        SDL_SetCursor(cursor_normal);
    }
}