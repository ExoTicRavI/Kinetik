#include "raylib.h"
#include <stdio.h>
#include "ball.h"
#include "collision.h"
#include "paddle.h"
#include "state.h"
#include "player.h"
#include <stdbool.h>
#include <stdlib.h> // Added for file operations

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

Paddle Player1_paddle = { 15, screen_height / 2 - 60, 20, 120, 6 };
Paddle Player2_paddle = { screen_width - 35, screen_height / 2 - 60, 20, 120, 6 };


void SaveScoresToFile(int score1, int score2) {
    printf("Attempting to save scores...\n"); 
    FILE *file = fopen("scores.txt", "a");
    if (file != NULL) {
        fprintf(file, "Player 1: %d | Player 2: %d\n", score1, score2);
        fclose(file);
        printf("Scores saved successfully.\n"); 
    } else {
        printf("Failed to open scores.txt for writing.\n");
    }
}


void intializeGame() {
    if (!ballLaunched && IsKeyPressed(KEY_SPACE)) {
        ballLaunched = true;
    }

    if (ballLaunched) {
        framecounter++;
        if (framecounter >= 180) {
            UpdateBall(&ball, player1Turn);
            CheckWallCollision(&ball, screen_width, screen_height);
            CheckPaddleCollision(&ball, Player1_paddle);
            CheckPaddleCollision(&ball, Player2_paddle);
        } else {
            if (framecounter <= 60) {
                DrawText("Starts in: 3", screen_width / 2 - 80, screen_height / 2 - 80, 35, GREEN);
            } else if (framecounter <= 120) {
                DrawText("Starts in: 2", screen_width / 2 - 80, screen_height / 2 - 80, 35, GREEN);
            } else {
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

    Vector2 mousePoint = { 0.0f, 0.0f };

    while (!WindowShouldClose()) {
        if (StatePlay == STATE_BEGIN || StatePlay == STATE_SCORE) {
            intializeGame();
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch (StateApp) {
            case STATE_HOME:
                framecounter++;
                if (framecounter <= 90) {
                    DrawText("Welcome to KINETIK", screen_width / 2 - 180, screen_height / 2 - 100, 42, RED);
                    DrawText("<Click Spacebar to start the game>", screen_width / 2 - 222, screen_height / 2 - 50, 30, BLUE);
                } else if (framecounter <= 110) {
                    DrawText("Welcome to KINETIK", screen_width / 2 - 180, screen_height / 2 - 100, 42, RED);
                } else {
                    framecounter = 0;
                }

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

                char player1Score[10];
                char player2Score[10];

                sprintf(player1Score, "Score: %d", player1.score);
                sprintf(player2Score, "Score: %d", player2.score);

                DrawText(player1Score, 10, 10, 20, BLUE);
                DrawText(player2Score, screen_width - 130, 10, 20, RED);

                if (StatePlay == STATE_END) {
                    if (player1.score > player2.score) {
                        DrawText("Player 1 won the game", screen_width / 2 - 180, screen_height / 2 - 200, 35, GREEN);
                    } else if (player2.score > player1.score) {
                        DrawText("Player 2 won the game", screen_width / 2 - 180, screen_height / 2 - 200, 35, GREEN);
                    } else {
                        DrawText("It's a draw!", screen_width / 2 - 100, screen_height / 2 - 200, 35, GREEN);
                    }

                    
                    SaveScoresToFile(player1.score, player2.score);

                    Rectangle replayBtn = { screen_width / 2 - 50, screen_height / 2 - 20, 100, 40 };
                    mousePoint = GetMousePosition();

                    if (CheckCollisionPointRec(mousePoint, replayBtn)) {
                        DrawRectangleRec(replayBtn, DARKGREEN);  // Hover color
                        SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);

                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                            StateApp = STATE_HOME;
                            StatePlay = STATE_BEGIN;
                            player1.score = 0;
                            player2.score = 0;
                            player1Turn = false;
                            ballLaunched = false;
                            framecounter = 0;
                            Player1_paddle.y = screen_height / 2 - 60;
                            Player2_paddle.y = screen_height / 2 - 60;
                            ball.x = screen_width / 2;
                            ball.y = screen_height / 2;
                            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                        }
                    } else {
                        DrawRectangleRec(replayBtn, GREEN);  // Normal color
                        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                    }

                    DrawText("Replay", screen_width / 2 - 38, screen_height / 2 - 10, 24, WHITE);
                }

                if (StatePlay == STATE_SCORE) {
                    Player1_paddle.y = screen_height / 2 - 60;
                    Player2_paddle.y = screen_height / 2 - 60;
                    ball.x = screen_width / 2;
                    ball.y = screen_height / 2;

                    ballLaunched = false;
                    framecounter = 0;
                    StatePlay = STATE_BEGIN;
                    player1Turn = !player1Turn;
                }

                if (StatePlay == STATE_BEGIN && ballLaunched == false) {
                    DrawText("Click Spacebar to start the game", screen_width / 2 - 222, screen_height / 2 - 80, 30, BLUE);
                }
                break;

            default:
                break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
