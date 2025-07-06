#ifndef PADDLE_H
#define PADDLE_H

typedef struct Paddle {
    float x, y;
    float width, height;
    float speed;
} Paddle;

void UpdatePaddle(Paddle *paddle, int upKey, int downKey, int screen_height);
void DrawPaddle(Paddle paddle);

#endif
