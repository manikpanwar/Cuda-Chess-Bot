#ifndef ALPHABETA_H
#define ALPHABETA_H

#define POSINF INT_MAX     // may need to include <limits.h>
#define NEGINF INT_MIN

#define MAXDEPTH 1000

#define MAXI 1
#define MINI 2

typedef struct minimaxResult* minimaxResult_t;

struct minimaxResult {
  int bestRes;
  move_t move;
};

#endif
