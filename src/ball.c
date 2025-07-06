#include"ball.h"

void UpdateBall(Ball *ball){
    ball->x += ball->speed_x;
    ball->y += ball->speed_y;
}

