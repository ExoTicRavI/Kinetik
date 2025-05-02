#ifndef MOUSE_H
#define MOUSE_H

#include <SDL3/SDL.h>
#include <stdbool.h>

extern SDL_FPoint mousePosition;
extern bool cursor_on_menu;
extern bool clicked_menu;

void check_hover(void);
void check_click(SDL_Event *event);

#endif