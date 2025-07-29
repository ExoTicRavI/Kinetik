#ifndef STATE_H
#define STATE_H

typedef enum {
    STATE_HOME,
    STATE_GAME,
} STATE_APP;

typedef enum {
    STATE_BEGIN,
    STATE_SCORE,
    STATE_END,
} STATE_PLAY;

extern STATE_APP StateApp;
extern STATE_PLAY StatePlay;

#endif // STATE_H