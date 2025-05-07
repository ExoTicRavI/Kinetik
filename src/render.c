#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <setup.h>
#include <window_resize.h>
#include <keyboard.h>
#include <stdbool.h>

SDL_FRect GAME_BOX;
SDL_FRect MENU_TOGGLE_BUTTON;
SDL_FRect PAUSE_TOGGLE_BUTTON;
SDL_FRect MENU;
float BOARD_ONE_Y = 230; // y = (MIN_WINDOW_HEIGHT + HIT_BOARD_HEIGHT) / 2
float BOARD_TWO_Y = 230;
SDL_Point BALL_POS = {4 + 4 + 8 + 8, 248}; // x: margin + 4 + HIT_BOARD_WIDTH + ball radius

bool MENU_SHOWN = false;
static bool PLAYER_ONE_TURN = false;

const int margin = 4;

void RENDER_GameBox()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE); /* blue, full alpha */
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

void RENDER_MenuIcon()
{
    SDL_Texture *menu_toggle_button_texture = IMG_LoadTexture(renderer, "./src/assets/menu_icon.bmp");

    if (menu_toggle_button_texture == NULL)
    {
        SDL_Log("Couldn't create menu_toggle_button_texture: %s", SDL_GetError());
    }

    MENU_TOGGLE_BUTTON.x = GAME_BOX.w + margin - 35;
    MENU_TOGGLE_BUTTON.y = margin;
    MENU_TOGGLE_BUTTON.w = MENU_TOGGLE_BUTTON.h = 35;

    SDL_RenderTexture(renderer, menu_toggle_button_texture, NULL, &MENU_TOGGLE_BUTTON);
}

void RENDER_Menu()
{
    RENDER_GameBox();
    RENDER_MenuIcon();

    if (!MENU_SHOWN)
    {
        SDL_SetRenderDrawColor(renderer, 38, 70, 83, SDL_ALPHA_OPAQUE);
        MENU.w = MENU.h = 300;
        MENU.x = (WINDOW_DIMENSIONS.x - 300) / 2;
        MENU.y = (WINDOW_DIMENSIONS.y - 300) / 2;

        SDL_RenderFillRect(renderer, &MENU);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // set the render color back to black
    }
}


void RENDER_Ball() {
    const int radius = 8;

    if (PLAYER_ONE_TURN) {
        BALL_POS.x = margin + 4 + 8 + 8; // x: margin + 4 + HIT_BOARD_WIDTH + ball radius
        BALL_POS.y = 248;
    } else {
        BALL_POS.x = WINDOW_DIMENSIONS.x - ( margin + 4 + 8 + 8 ); // x: WINDOW_DIMENSIONS.x - ( margin + 4 + HIT_BOARD_WIDTH + ball radius + HIT_BOARD_WIDTH )
        BALL_POS.y = 248;
    }

    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                SDL_RenderPoint(renderer, BALL_POS.x + x, BALL_POS.y + y);
            }
        }
    }
}

void RENDER_HitBoards()
{
    RENDER_GameBox();

    SDL_Texture *pause_btn = IMG_LoadTexture(renderer, "./src/assets/pause_icon.png");

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    PAUSE_TOGGLE_BUTTON.x = GAME_BOX.w + margin - 35;
    PAUSE_TOGGLE_BUTTON.y = margin;
    PAUSE_TOGGLE_BUTTON.w = PAUSE_TOGGLE_BUTTON.h = 35;

    SDL_RenderTexture(renderer, pause_btn, NULL, &PAUSE_TOGGLE_BUTTON);

    float HIT_BOARD_WIDTH = 8;
    float HIT_BOARD_HEIGHT = 40;

    SDL_FRect HIT_BOARD_ONE = {margin + 4, BOARD_ONE_Y, HIT_BOARD_WIDTH, HIT_BOARD_HEIGHT};
    SDL_FRect HIT_BOARD_TWO = {WINDOW_DIMENSIONS.x - (margin + 4 + HIT_BOARD_WIDTH), BOARD_TWO_Y, HIT_BOARD_WIDTH, HIT_BOARD_HEIGHT};

    SDL_RenderFillRect(renderer, &HIT_BOARD_ONE);
    SDL_RenderFillRect(renderer, &HIT_BOARD_TWO);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

    RENDER_Ball();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void MOVE_HitBoards(double delta_time)
{
    const float board_speed = 200.0f; // pixels per second
    const float velocity = board_speed * delta_time;

    const float board_height = 40.0f; // Height of each paddle
    const float margin = 4.0f;        // Sacred boundary from top and bottom

    // Move BOARD_ONE
    if (w_pressed)
    {
        if (BOARD_ONE_Y - velocity >= margin)
        {
            BOARD_ONE_Y -= velocity;
        }
    }
    if (s_pressed)
    {
        if (BOARD_ONE_Y + board_height + velocity <= WINDOW_DIMENSIONS.y - margin)
        {
            BOARD_ONE_Y += velocity;
        }
    }

    // Move BOARD_TWO
    if (up_pressed)
    {
        if (BOARD_TWO_Y - velocity >= margin)
        {
            BOARD_TWO_Y -= velocity;
        }
    }
    if (down_pressed)
    {
        if (BOARD_TWO_Y + board_height + velocity <= WINDOW_DIMENSIONS.y - margin)
        {
            BOARD_TWO_Y += velocity;
        }
    }
}