#include "collision.h"
#include "paddle.h"

void CheckWallCollision(Ball *ball, int screen_width, int screen_height) {
    if (ball->y - ball->radius <= 0 || ball->y + ball->radius >= screen_height) {
        ball->speed_y *= -1;
    }
}

// Simple AABB vs Circle collision
void CheckPaddleCollision(Ball *ball, Paddle paddle) {
    // Find closest point on paddle rectangle to the ball center
    float closestX = ball->x;
    float closestY = ball->y;

    if (ball->x < paddle.x) closestX = paddle.x;
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

        // Optional: tweak Y speed based on where ball hits paddle
        float hitPos = (ball->y - paddle.y) / paddle.height; // 0.0 to 1.0
        ball->speed_y = 5 * (hitPos - 0.5f) * 2; // Speed between -5 and 5
    }
}
