#include "raylib.h"
#include<stdio.h>
#include "ball.h"

void DrawBall(Ball ball){
    DrawCircle((int)ball.x, (int)ball.y, ball.radius, WHITE);
}

int main(void) {
    printf("Starting the Game\n");


    const int screen_width = 1280;
    const int screen_height = 800;


    InitWindow(screen_width, screen_height, "KINETIK");
    SetTargetFPS(60);

    Ball ball;
    ball.radius = 20;
    ball.x = screen_width /2;
    ball.y = screen_height /2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // Update and Draw ball
        UpdateBall(&ball);
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, BLUE);
        DrawBall(ball);

        // Draw Paddles
        DrawRectangle(15, screen_height/2 - 60, 20, 120, WHITE);
        DrawRectangle(screen_width - 35, screen_height/2 - 60, 20, 120, WHITE);
        EndDrawing();
    }


    CloseWindow();
    return 0;
}