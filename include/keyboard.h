#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <SDL3/SDL.h>
#include <stdbool.h>

extern bool w_pressed;
extern bool s_pressed;
extern bool up_pressed;
extern bool down_pressed;

void handleKeypress(SDL_Event *event);

#endif