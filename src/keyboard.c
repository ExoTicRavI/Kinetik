#include <keyboard.h>
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <render.h>
#include <window_resize.h>
#include <setup.h>

bool w_pressed = false;
bool s_pressed = false;
bool up_pressed = false;
bool down_pressed = false;

void handleKeypress(SDL_Event *event) {
    SDL_KeyboardEvent *key_event = (SDL_KeyboardEvent *)event;
    SDL_Keycode key = key_event->key;

    if (event->type == SDL_EVENT_KEY_DOWN) {
        switch (key)
        {
        case 119:
            w_pressed = true;
            break;
        case 115:
            s_pressed = true;
            break;
        case 1073741906:
            up_pressed = true;
            break;
        case 1073741905:
            down_pressed = true;
            break;
        default:
            break;
        }   
    }
    if (event->type == SDL_EVENT_KEY_UP) {
        switch (key)
        {
        case 119:
            w_pressed = false;
            break;
        case 115:
            s_pressed = false;
            break;
        case 1073741906:
            up_pressed = false;
            break;
        case 1073741905:
            down_pressed = false;
            break;
        default:
            break;
        }   
    }

}