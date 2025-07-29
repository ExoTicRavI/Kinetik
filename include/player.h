#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

typedef struct Player {
    char name[50];
    int score;
} Player;

extern Player player1;
extern Player player2;

#endif // PLAYER_H