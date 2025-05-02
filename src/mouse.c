#include <mouse.h>
#include <setup.h>
#include <SDL3/SDL.h>

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
    cursor_on_menu = SDL_PointInRectFloat(&mousePosition, &MENU);

    toggle_cursor(cursor_on_menu);
}

void check_click(SDL_Event *event) {
    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        if (event->button.button == SDL_BUTTON_LEFT){
            clicked_menu = !clicked_menu;
        }
    }
}