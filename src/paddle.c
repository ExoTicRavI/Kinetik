#include "raylib.h"
#include "paddle.h"

void UpdatePaddle(Paddle *paddle, int upKey, int downKey, int screen_height) {
    if (IsKeyDown(upKey)) {
        paddle->y -= paddle->speed;
    }
    if (IsKeyDown(downKey)) {
        paddle->y += paddle->speed;
    }

    // Clamp paddle within screen bounds
    if (paddle->y < 0) {
        paddle->y = 0;
    }
    if (paddle->y + paddle->height > screen_height) {
        paddle->y = screen_height - paddle->height;
    }
}

void DrawPaddle(Paddle paddle) {
    DrawRectangle((int)paddle.x, (int)paddle.y, (int)paddle.width, (int)paddle.height, WHITE);
}
