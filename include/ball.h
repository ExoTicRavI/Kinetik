#ifndef BALL_H
#define BALL_H

typedef struct Ball {
    float x, y;
    int speed_x, speed_y;
    int radius;
} Ball;

void UpdateBall(Ball *ball);

#endif