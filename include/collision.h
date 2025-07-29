#ifndef COLLISION_H
#define COLLISION_H

#include "ball.h"
#include "paddle.h"
#include <stdbool.h>

void CheckWallCollision(Ball *ball, int screen_width, int screen_height);
bool CheckPaddleCollision(Ball *ball, Paddle paddle);


#endif
