#ifndef RENDER_H
#define RENDER_H
#include <SDL3/SDL.h>
#include <stdbool.h>

extern SDL_FRect GAME_BOX;
extern SDL_FRect MENU_TOGGLE_BUTTON;
extern bool MENU_SHOWN;
extern float BOARD_ONE_Y;
extern float BOARD_TWO_Y;
extern SDL_Point BALL_POS;

void RENDER_GameBox(void);
void RENDER_MenuIcon(void);
void RENDER_Menu(void);
void RENDER_HitBoards(void);
void MOVE_HitBoards(double delta);
void RENDER_Ball(void);

#endif