#ifndef COLLISION_H
#define COLLISION_H

#include "ball.h"
#include "paddle.h"

void CheckWallCollision(Ball *ball, int screen_width, int screen_height);
void CheckPaddleCollision(Ball *ball, Paddle paddle);


#endif
