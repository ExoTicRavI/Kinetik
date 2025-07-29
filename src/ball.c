#include"ball.h"
#include <stdbool.h>

void UpdateBall(Ball *ball, bool player1Turn){
    if (player1Turn) {
        ball->x -= ball->speed_x;
    } else {
        ball->x += ball->speed_x;
    }

    ball->y += ball->speed_y;
}

