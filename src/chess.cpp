#include <chess.h>

void initPlayers(board_t B) {
  player_t w = malloc(sizeof(struct player));
  player_t b = malloc(sizeof(struct player));
  w->king = malloc(sizeof(struct pos));
  w->king->x = 3;
  w->king->y = 0;
  w->king->active = true;
  w->queen = malloc(sizeof(struct pos));
  w->queen->x = 4;
  w->queen->y = 0;
  w->queen->active = true;
  w->lbishop = malloc(sizeof(struct pos));
  w->lbishop->x = 2;
  w->lbishop->y = 0;
  w->lbishop->active = true;
  w->rbishop = malloc(sizeof(struct pos));
  w->rbishop->x = 5;
  w->rbishop->y = 0;
  w->rbishop->active = true;
  w->lknight = malloc(sizeof(struct pos));
  w->lknight->x = 1;
  w->lknight->y = 0;
  w->lknight->active = true;
  w->rknight = malloc(sizeof(struct pos));
  w->rknight->x = 6;
  w->rknight->y = 0;
  w->rknight->active = true;
  w->lrook = malloc(sizeof(struct pos));
  w->lrook->x = 0;
  w->lrook->y = 0;
  w->lrook->active = true;
  w->rrook = malloc(sizeof(struct pos));
  w->rrook->x = 7;
  w->rrook->y = 0;
  w->rrook->active = true;
  w->pawns = malloc(sizeof(pos_t));
  for(int i = 0; i < BOARD_WIDTH; i++) {
    w->pawns[i] = malloc(sizeof(struct pos));
    w->pawns[i]->x = i;
    w->pawns[i]->y = 1;
    w->pawns[i]->active = true;
  }
  b->king = malloc(sizeof(struct pos));
  b->king->x = 3;
  b->king->y = 7;
  b->king->active = true;
  b->queen = malloc(sizeof(struct pos));
  b->queen->x = 4;
  b->queen->y = 7;
  b->queen->active = true;
  b->lbishop = malloc(sizeof(struct pos));
  b->lbishop->x = 2;
  b->lbishop->y = 7;
  b->lbishop->active = true;
  b->rbishop = malloc(sizeof(struct pos));
  b->rbishop->x = 5;
  b->rbishop->y = 7;
  b->rbishop->active = true;
  b->lknight = malloc(sizeof(struct pos));
  b->lknight->x = 1;
  b->lknight->y = 7;
  b->lknight->active = true;
  b->rknight = malloc(sizeof(struct pos));
  b->rknight->x = 6;
  b->rknight->y = 7;
  b->rknight->active = true;
  b->lrook = malloc(sizeof(struct pos));
  b->lrook->x = 0;
  b->lrook->y = 7;
  b->lrook->active = true;
  b->rrook = malloc(sizeof(struct pos));
  b->rrook->x = 7;
  b->rrook->y = 7;
  b->rrook->active = true;
  b->pawns = malloc(sizeof(pos_t));
  for(int i = 0; i < BOARD_WIDTH; i++) {
    b->pawns[i] = malloc(sizeof(struct pos));
    b->pawns[i]->x = i;
    b->pawns[i]->y = 6;
    b->pawns[i]->active = true;
  }

  B->white = w;
  B->black = b;
}

void initGame(board_t B) {
  B->curPlayer = WHITE;
  initPlayers(B);
}

int main() {
  board_t B = malloc(sizeof(struct board));
  initGame(B);
  while(1) {
    // read input from cmdline (e.g. LK e 5, LB a 6, P1 b 3, etc...)
  }
}
