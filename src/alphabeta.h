#ifndef ALPHABETA_H
#define ALPHABETA_H

#define POSINF INT_MAX     // may need to include <limits.h>
#define NEGINF INT_MIN

#define MAXDEPTH 8

#define MAXI 1
#define MINI 2

typedef struct minimaxResult* minimaxResult_t;
typedef struct movesListElem* movesListElem_t;

struct minimaxResult {
  int bestRes;
  move_t move;
};

struct movesListElem {
    move_t m;
    int player;
    board_piece startPiece;
    board_piece endPiece;
};

move_t nextMove(board_t board, int aiType, int curPlayer);

#endif
