#include "raylib.h"
#include <stdio.h>
#include "ball.h"
#include "collision.h"
#include "paddle.h"
#include "state.h"
#include <stdbool.h>

void DrawBall(Ball ball) {
    DrawCircle((int)ball.x, (int)ball.y, ball.radius, WHITE);
}

static int framecounter = 0;
static bool player1Turn = false;



const int screen_width = 1280;
const int screen_height = 800;


bool ballLaunched = false;

Ball ball = {
    .x = screen_width / 2,
    .y = screen_height / 2,
    .radius = 20,
    .speed_x = 9,
    .speed_y = 9
};

// Paddles initialization
Paddle Player1_paddle = { 15, screen_height / 2 - 60, 20, 120, 6 };
Paddle Player2_paddle = { screen_width - 35, screen_height / 2 - 60, 20, 120, 6 };

void intializeGame() {
    // Input to launch the ball
        if (!ballLaunched && (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsKeyPressed(KEY_SPACE))) {
            ballLaunched = true;
        }

        // Update
        if (ballLaunched) {
            framecounter++;
            if (framecounter >= 180) { // wait for 3 seconds before starting game
                UpdateBall(&ball, player1Turn);
                CheckWallCollision(&ball, screen_width, screen_height);
                CheckPaddleCollision(&ball, Player1_paddle);
                CheckPaddleCollision(&ball, Player2_paddle);
            } else if (framecounter < 180) {
                if (framecounter >= 0 && framecounter <= 60) {
                    DrawText("Starts in: 3", screen_width / 2 - 80, screen_height / 2 - 80, 35, GREEN);
                } else if (framecounter > 60 && framecounter <= 120) {
                    DrawText("Starts in: 2", screen_width / 2 - 80, screen_height / 2 - 80, 35, GREEN);
                } else if (framecounter > 120 && framecounter <= 180) {
                    DrawText("Starts in: 1", screen_width / 2 - 80, screen_height / 2 - 80, 35, GREEN);
                }
            }

        }

        UpdatePaddle(&Player1_paddle, KEY_W, KEY_S, screen_height);
        UpdatePaddle(&Player2_paddle, KEY_UP, KEY_DOWN, screen_height);
}

int main(void) {
    printf("Starting the Game\n");

    InitWindow(screen_width, screen_height, "KINETIK");
    SetTargetFPS(60);

    


    while (!WindowShouldClose()) { // main game loop

        
        intializeGame();
        
        BeginDrawing();
        ClearBackground(BLACK);

        switch (StateApp)
        {
        case STATE_HOME:
            DrawText("Welcome to KINETIK", screen_width / 2 - 180, screen_height / 2 - 200, 35, YELLOW);
            DrawText("Click Spacebar or LeftClick to Launch the Ball", screen_width / 2 - 350, screen_height / 2 - 50, 30, YELLOW);
            
            if (ballLaunched) {
                StateApp = STATE_GAME;
                framecounter = 0;
            }
            break;
        case STATE_GAME:
            DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, BLUE);
            DrawBall(ball);
            DrawPaddle(Player1_paddle);
            DrawPaddle(Player2_paddle);
            break;

        case STATE_MENU:
            
            break;
        default:
            break;
        }


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
