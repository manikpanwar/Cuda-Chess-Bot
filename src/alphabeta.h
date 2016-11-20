#ifndef ALPHABETA_H
#define ALPHABETA_H

#define POSINF INT_MAX     // may need to include <limits.h>
#define NEGINF INT_MIN

typedef struct minimaxResult* minimaxResult_t;

struct minimaxResult {
  int alpha;
  int beta;
  move_t move;
}

#endif
