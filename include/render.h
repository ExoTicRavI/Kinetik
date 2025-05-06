#ifndef RENDER_H
#define RENDER_H
#include <SDL3/SDL.h>
#include <stdbool.h>

extern SDL_FRect GAME_BOX;
extern SDL_FRect MENU_TOGGLE_BUTTON;
extern bool PAUSE_MENU_SHOWN;

void RENDER_GameBox(void);
void RENDER_MenuIcon(void);
void RENDER_PauseMenu(void);

#endif