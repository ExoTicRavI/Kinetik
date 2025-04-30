#include <keyboard.h>
#include <SDL3/SDL.h>
#include <stdbool.h>

bool w_pressed = false;
bool s_pressed = false;
bool up_pressed = false;
bool down_pressed = false;

void handleKeypress(SDL_Event *event) {
    SDL_KeyboardEvent *key_event = (SDL_KeyboardEvent *)event;
    SDL_Keycode key = key_event->key;

    // SDL_Log("%d", key);

    if (event->type == SDL_EVENT_KEY_DOWN) {
        switch (key)
        {
        case 119:
            SDL_Log("Pressed w");
            w_pressed = true;
            break;
        case 115:
            s_pressed = true;
            SDL_Log("Pressed s");
            break;
        case 1073741906:
            up_pressed = true;
            SDL_Log("Pressed uparrow");
            break;
        case 1073741905:
            down_pressed = true;
            SDL_Log("Pressed downarrow");
            break;
        default:
            break;
        }   
    }

    SDL_Log("W: %d, S: %d, UP: %d, DOWN: %d", w_pressed, s_pressed, up_pressed, down_pressed);
    if (event->type == SDL_EVENT_KEY_UP) {
        switch (key)
        {
        case 119:
            SDL_Log("Released w");
            w_pressed = false;
            break;
        case 115:
            s_pressed = false;
            SDL_Log("Released s");
            break;
        case 1073741906:
            up_pressed = false;
            SDL_Log("Released uparrow");
            break;
        case 1073741905:
            down_pressed = false;
            SDL_Log("Released downarrow");
            break;
        default:
            break;
        }   
    }

    SDL_Log("W: %d, S: %d, UP: %d, DOWN: %d", w_pressed, s_pressed, up_pressed, down_pressed);

}