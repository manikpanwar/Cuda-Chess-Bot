#ifndef ALPHABETA_H
#define ALPHABETA_H

#define POSINF INT_MAX     // may need to include <limits.h>
#define NEGINF INT_MIN

typedef struct abParams* abParams_t;

struct abParams {
  int maxDepth;
  int alpha;
  int beta;
};

#endif
