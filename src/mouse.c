#include <render.h>
#include <SDL3/SDL.h>
#include <setup.h>

SDL_FPoint mousePosition;
bool cursor_on_menu = false;
bool clicked_menu = false;

void toggle_cursor(bool state) {
    if (state) {
        SDL_Cursor *cursor_pointer = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_POINTER);
        if (!cursor_pointer) {
            SDL_Log("Failed to create cursor: %s", SDL_GetError());
        }
        SDL_SetCursor(cursor_pointer);
    } else {
        SDL_Cursor *cursor_normal = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_DEFAULT);
        if (!cursor_normal) {
            SDL_Log("Failed to create cursor: %s", SDL_GetError());
        }
        SDL_SetCursor(cursor_normal);
    }
}

void check_hover() {
    SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
    cursor_on_menu = SDL_PointInRectFloat(&mousePosition, &MENU_TOGGLE_BUTTON);

    toggle_cursor(cursor_on_menu);
}