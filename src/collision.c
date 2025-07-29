#include "collision.h"
#include "paddle.h"
#include <stdbool.h>
#include <stdio.h>
#include <state.h>
#include <player.h>

const win_score = 5;

void CheckWallCollision(Ball *ball, int screen_width, int screen_height) { // Check collision on top and bottom
    if (ball->y - ball->radius <= 0 || ball->y + ball->radius >= screen_height) {
        ball->speed_y *= -1;
    } else if (ball->x - ball->radius <= 0) {
        // Player 2 (Second player) scores a point
        printf("player 2 scores\n");
        player2.score++;

        if (player2.score == win_score) {
            StatePlay = STATE_END;
        } else {
            StatePlay = STATE_SCORE;
        }


    } else if (ball->x - ball->radius >= screen_width) {
        // Player 1 (Second player) scores a point
        printf("Player 1 scores\n");
        player1.score++;

        if (player1.score == win_score) {
            StatePlay = STATE_END;
        } else {
            StatePlay = STATE_SCORE;
        }
    }
}

// Simple AABB vs Circle collision
bool CheckPaddleCollision(Ball *ball, Paddle paddle) {
    // Find closest point on paddle rectangle to the ball center
    float closestX = ball->x;
    float closestY = ball->y;

    if (ball->x < paddle.x)closestX = paddle.x;
    else if (ball->x > paddle.x + paddle.width) closestX = paddle.x + paddle.width;

    if (ball->y < paddle.y) closestY = paddle.y;
    else if (ball->y > paddle.y + paddle.height) closestY = paddle.y + paddle.height;

    // Calculate distance from ball center to closest point
    float distX = ball->x - closestX;
    float distY = ball->y - closestY;
    float distanceSquared = distX * distX + distY * distY;

    if (distanceSquared < (ball->radius * ball->radius)) {
        // Collision detected, reverse X velocity
        ball->speed_x *= -1;

        float hitPos = (ball->y - paddle.y) / paddle.height; // 0.0 to 1.0
        ball->speed_y = 5 * (hitPos - 0.5f) * 2; // Speed between -5 and 5

        return true; // if collission is detected return true
    } else {
        return false; // if collision is not detected return false
    }
}
