#include "raylib.h"
#include <stdio.h>
#include "ball.h"
#include "collision.h"
#include "paddle.h"

void DrawBall(Ball ball) {
    DrawCircle((int)ball.x, (int)ball.y, ball.radius, WHITE);
}

int main(void) {
    printf("Starting the Game\n");

    const int screen_width = 1280;
    const int screen_height = 800;

    InitWindow(screen_width, screen_height, "KINETIK");
    SetTargetFPS(60);

    // Ball initialization
    Ball ball = {
        .x = screen_width / 2,
        .y = screen_height / 2,
        .radius = 20,
        .speed_x = 9,
        .speed_y = 9
    };

    // Paddles initialization
    Paddle player1 = { 15, screen_height / 2 - 60, 20, 120, 6 };
    Paddle player2 = { screen_width - 35, screen_height / 2 - 60, 20, 120, 6 };

    bool ballLaunched = false;

    while (!WindowShouldClose()) {
        // Input to launch the ball
        if (!ballLaunched && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_SPACE))) {
            ballLaunched = true;
        }

        // Update
        if (ballLaunched) {
            UpdateBall(&ball);
            CheckWallCollision(&ball, screen_width, screen_height);
            CheckPaddleCollision(&ball, player1);
            CheckPaddleCollision(&ball, player2);

        }

        UpdatePaddle(&player1, KEY_W, KEY_S, screen_height);
        UpdatePaddle(&player2, KEY_UP, KEY_DOWN, screen_height);

        
        BeginDrawing();
        ClearBackground(BLACK);

        
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, BLUE);

        DrawBall(ball);
        DrawPaddle(player1);
        DrawPaddle(player2);

        if (!ballLaunched) {
            DrawText("Click or press SPACE to launch the ball", screen_width / 2 - 200, screen_height / 2 - 100, 20, YELLOW);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
