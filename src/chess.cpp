#include <chess.h>


int getIndex(int col, int row) {
  return row * BOARD_WIDTH + col;
}

void initPlayers(board_t B) {
  // inits game board and player structs
  
  player_t w = malloc(sizeof(struct player));
  player_t b = malloc(sizeof(struct player));
  
  board_piece_t game_board = B->game_board;
  w->king = malloc(sizeof(struct pos));
  w->king->x = 3;     // x is columns, y is rows
  w->king->y = 0;
  w->king->active = true;
  game_board[getIndex(3, 0)]->piece = w->king;
  game_board[getIndex(3, 0)]->player = WHITE;
  
  w->queen = malloc(sizeof(struct pos));
  w->queen->x = 4;
  w->queen->y = 0;
  w->queen->active = true;
  game_board[getIndex(4, 0)]->piece = w->queen;
  game_board[getIndex(4, 0)]->player = WHITE;
  
  w->lbishop = malloc(sizeof(struct pos));
  w->lbishop->x = 2;
  w->lbishop->y = 0;
  w->lbishop->active = true;
  game_board[getIndex(2, 0)]->piece = w->lbishop;
  game_board[getIndex(2, 0)]->player = WHITE;
  
  w->rbishop = malloc(sizeof(struct pos));
  w->rbishop->x = 5;
  w->rbishop->y = 0;
  w->rbishop->active = true;
  game_board[getIndex(5, 0)]->piece = w->rbishop;
  game_board[getIndex(5, 0)]->player = WHITE;
  
  w->lknight = malloc(sizeof(struct pos));
  w->lknight->x = 1;
  w->lknight->y = 0;
  w->lknight->active = true;
  game_board[getIndex(1, 0)]->piece = w->lknight;
  game_board[getIndex(1, 0)]->player = WHITE;
  
  w->rknight = malloc(sizeof(struct pos));
  w->rknight->x = 6;
  w->rknight->y = 0;
  w->rknight->active = true;
  game_board[getIndex(6, 0)]->piece = w->rknight;
  game_board[getIndex(6, 0)]->player = WHITE;
  
  w->lrook = malloc(sizeof(struct pos));
  w->lrook->x = 0;
  w->lrook->y = 0;
  w->lrook->active = true;
  game_board[getIndex(0, 0)]->piece = w->lrook;
  game_board[getIndex(0, 0)]->player = WHITE;
  
  w->rrook = malloc(sizeof(struct pos));
  w->rrook->x = 7;
  w->rrook->y = 0;
  w->rrook->active = true;
  game_board[getIndex(7, 0)]->piece = w->rrook;
  game_board[getIndex(7, 0)]->player = WHITE;
  
  w->pawns = malloc(sizeof(pos_t));
  for(int i = 0; i < BOARD_WIDTH; i++) {
    w->pawns[i] = malloc(sizeof(struct pos));
    w->pawns[i]->x = i;
    w->pawns[i]->y = 1;
    w->pawns[i]->active = true;
    game_board[getIndex(1, i)]->piece = w->pawns[i];
    game_board[getIndex(1, i)]->player = WHITE;
    
  }

  b->king = malloc(sizeof(struct pos));
  b->king->x = 3;
  b->king->y = 7;
  b->king->active = true;
  game_board[getIndex(3, 7)]->piece = b->king;
  game_board[getIndex(3, 7)]->player = BLACK;

  b->queen = malloc(sizeof(struct pos));
  b->queen->x = 4;
  b->queen->y = 7;
  b->queen->active = true;
  game_board[getIndex(4, 7)]->piece = b->queen;
  game_board[getIndex(4, 7)]->player = BLACK;
  
  b->lbishop = malloc(sizeof(struct pos));
  b->lbishop->x = 2;
  b->lbishop->y = 7;
  b->lbishop->active = true;
  game_board[getIndex(2, 7)]->piece = b->lbishop;
  game_board[getIndex(2, 7)]->player = BLACK;
  
  b->rbishop = malloc(sizeof(struct pos));
  b->rbishop->x = 5;
  b->rbishop->y = 7;
  b->rbishop->active = true;
  game_board[getIndex(5, 7)]->piece = b->rbishop;
  game_board[getIndex(5, 7)]->player = BLACK;
  
  b->lknight = malloc(sizeof(struct pos));
  b->lknight->x = 1;
  b->lknight->y = 7;
  b->lknight->active = true;
  game_board[getIndex(1, 7)]->piece = b->lknight;
  game_board[getIndex(1, 7)]->player = BLACK;
  
  b->rknight = malloc(sizeof(struct pos));
  b->rknight->x = 6;
  b->rknight->y = 7;
  b->rknight->active = true;
  game_board[getIndex(6, 7)]->piece = b->rknight;
  game_board[getIndex(6, 7)]->player = BLACK;
  
  b->lrook = malloc(sizeof(struct pos));
  b->lrook->x = 0;
  b->lrook->y = 7;
  b->lrook->active = true;
  game_board[getIndex(0, 7)]->piece = b->lrook;
  game_board[getIndex(0, 7)]->player = BLACK;
  
  b->rrook = malloc(sizeof(struct pos));
  b->rrook->x = 7;
  b->rrook->y = 7;
  b->rrook->active = true;
  game_board[getIndex(7, 7)]->piece = b->rrook;
  game_board[getIndex(7, 7)]->player = BLACK;
  
  b->pawns = malloc(BOARD_WIDTH * sizeof(pos_t));
  for(int i = 0; i < BOARD_WIDTH; i++) {
    b->pawns[i] = malloc(sizeof(struct pos));
    b->pawns[i]->x = i;
    b->pawns[i]->y = 6;
    b->pawns[i]->active = true;
    game_board[getIndex(i, 7)]->piece = b->pawns[i];
    game_board[getIndex(i, 7)]->player = BLACK;
  }

  B->white = w;
  B->black = b;
}

void initGame(board_t B) {
  B->curPlayer = WHITE;
  initPlayers(B); // inits players and game board
}

int main() {
  board_t B = malloc(sizeof(struct board));
  B->game_board = malloc(BOARD_WIDTH * BOARD_HEIGHT * sizeof(struct board_piece_t));
  initGame(B);
  while(1) {
    // read input from cmdline (e.g. LK e 5, LB a 6, P1 b 3, etc...)
  }
}
