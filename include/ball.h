#ifndef BALL_H
#define BALL_H

#include <stdbool.h>

typedef struct Ball {
    float x, y;
    int speed_x, speed_y;
    int radius;
} Ball;

void UpdateBall(Ball *ball, bool player1Turn);

#endif