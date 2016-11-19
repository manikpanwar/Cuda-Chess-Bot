#include <chess.h>
#include <stdio.h>
#include <string>


using std::string;

// a lot of game implementation code taken from https://github.com/jordancunningham/Chess/blob/master/Chess_Shared/Chess_Shared/Chess_Shared.cpp


int getIndex(int col, int row) {
  return row * BOARD_WIDTH + col;
}

void initPlayers(board_t B) {
  // inits game board and player structs
  
  player_t w = malloc(sizeof(struct player));
  player_t b = malloc(sizeof(struct player));
  
  board_piece_t game_board = B->gameBoard;
  w->king = malloc(sizeof(struct pos));
  w->king->x = 3;     // x is columns, y is rows
  w->king->y = 0;
  w->king->active = true;
  w->king->type = KING;
  game_board[getIndex(3, 0)]->piece = w->king;
  game_board[getIndex(3, 0)]->player = WHITE;
  
  w->queen = malloc(sizeof(struct pos));
  w->queen->x = 4;
  w->queen->y = 0;
  w->queen->active = true;
  w->queen->type = QUEEN;
  game_board[getIndex(4, 0)]->piece = w->queen;
  game_board[getIndex(4, 0)]->player = WHITE;
  
  w->lbishop = malloc(sizeof(struct pos));
  w->lbishop->x = 2;
  w->lbishop->y = 0;
  w->lbishop->active = true;
  w->lbishop->type = BISHOP;
  game_board[getIndex(2, 0)]->piece = w->lbishop;
  game_board[getIndex(2, 0)]->player = WHITE;
  
  w->rbishop = malloc(sizeof(struct pos));
  w->rbishop->x = 5;
  w->rbishop->y = 0;
  w->rbishop->active = true;
  w->rbishop->type = BISHOP;
  game_board[getIndex(5, 0)]->piece = w->rbishop;
  game_board[getIndex(5, 0)]->player = WHITE;
  
  w->lknight = malloc(sizeof(struct pos));
  w->lknight->x = 1;
  w->lknight->y = 0;
  w->lknight->active = true;
  w->lknight->type = KNIGHT;
  game_board[getIndex(1, 0)]->piece = w->lknight;
  game_board[getIndex(1, 0)]->player = WHITE;
  
  w->rknight = malloc(sizeof(struct pos));
  w->rknight->x = 6;
  w->rknight->y = 0;
  w->rknight->active = true;
  w->rknight->type = KNIGHT;
  game_board[getIndex(6, 0)]->piece = w->rknight;
  game_board[getIndex(6, 0)]->player = WHITE;
  
  w->lrook = malloc(sizeof(struct pos));
  w->lrook->x = 0;
  w->lrook->y = 0;
  w->lrook->active = true;
  w->lrook->type = ROOK;
  game_board[getIndex(0, 0)]->piece = w->lrook;
  game_board[getIndex(0, 0)]->player = WHITE;
  
  w->rrook = malloc(sizeof(struct pos));
  w->rrook->x = 7;
  w->rrook->y = 0;
  w->rrook->active = true;
  w->rrook->type = ROOK;
  game_board[getIndex(7, 0)]->piece = w->rrook;
  game_board[getIndex(7, 0)]->player = WHITE;
  
  w->pawns = malloc(sizeof(pos_t));
  for(int i = 0; i < BOARD_WIDTH; i++) {
    w->pawns[i] = malloc(sizeof(struct pos));
    w->pawns[i]->x = i;
    w->pawns[i]->y = 1;
    w->pawns[i]->active = true;
    w->pawns[i]->type = PAWN;
    game_board[getIndex(1, i)]->piece = w->pawns[i];
    game_board[getIndex(1, i)]->player = WHITE;
    
  }

  b->king = malloc(sizeof(struct pos));
  b->king->x = 3;
  b->king->y = 7;
  b->king->active = true;
  b->king->type = KING:
  game_board[getIndex(3, 7)]->piece = b->king;
  game_board[getIndex(3, 7)]->player = BLACK;

  b->queen = malloc(sizeof(struct pos));
  b->queen->x = 4;
  b->queen->y = 7;
  b->queen->active = true;
  b->queen->type = QUEEN:
  game_board[getIndex(4, 7)]->piece = b->queen;
  game_board[getIndex(4, 7)]->player = BLACK;
  
  b->lbishop = malloc(sizeof(struct pos));
  b->lbishop->x = 2;
  b->lbishop->y = 7;
  b->lbishop->active = true;
  b->lbishop->type = BISHOP;
  game_board[getIndex(2, 7)]->piece = b->lbishop;
  game_board[getIndex(2, 7)]->player = BLACK;
  
  b->rbishop = malloc(sizeof(struct pos));
  b->rbishop->x = 5;
  b->rbishop->y = 7;
  b->rbishop->active = true;
  b->rbishop->type = BISHOP;
  game_board[getIndex(5, 7)]->piece = b->rbishop;
  game_board[getIndex(5, 7)]->player = BLACK;
  
  b->lknight = malloc(sizeof(struct pos));
  b->lknight->x = 1;
  b->lknight->y = 7;
  b->lknight->active = true;
  b->lknight->type = KNIGHT;
  game_board[getIndex(1, 7)]->piece = b->lknight;
  game_board[getIndex(1, 7)]->player = BLACK;
  
  b->rknight = malloc(sizeof(struct pos));
  b->rknight->x = 6;
  b->rknight->y = 7;
  b->rknight->active = true;
  b->rknight->type = KNIGHT;
  game_board[getIndex(6, 7)]->piece = b->rknight;
  game_board[getIndex(6, 7)]->player = BLACK;
  
  b->lrook = malloc(sizeof(struct pos));
  b->lrook->x = 0;
  b->lrook->y = 7;
  b->lrook->active = true;
  b->lrook->type = ROOK;
  game_board[getIndex(0, 7)]->piece = b->lrook;
  game_board[getIndex(0, 7)]->player = BLACK;
  
  b->rrook = malloc(sizeof(struct pos));
  b->rrook->x = 7;
  b->rrook->y = 7;
  b->rrook->active = true;
  b->rrook->type = ROOK;
  game_board[getIndex(7, 7)]->piece = b->rrook;
  game_board[getIndex(7, 7)]->player = BLACK;
  
  b->pawns = malloc(BOARD_WIDTH * sizeof(pos_t));
  for(int i = 0; i < BOARD_WIDTH; i++) {
    b->pawns[i] = malloc(sizeof(struct pos));
    b->pawns[i]->x = i;
    b->pawns[i]->y = 6;
    b->pawns[i]->active = true;
    b->pawns[i]->type = PAWN;
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

// checks if the format of the move is valid
bool isValidMoveFormat(string move) {
  if (move.length != 8) {
    return false;
  }

  else if (move[0] != 'a' && move[0] != 'b' && move[0] != 'c' && move[0] != 'd' && 
      move[0] != 'e' && move[0] != 'f' && move[0] != 'g' && move[0] != 'h') {
    return false;
  }

  else if (move[1] != '0' && move[1] != '1' && move[1] != '2' && move[1] != '3' &&
      move[1] != '4' && move[1] != '5' && move[1] != '6' && move[1] != '7') {
    return false;
  }

  else if (move[3] != 't' && move[4] != 'o') {
    return false;
  }

  else if (move[6] != 'a' && move[6] != 'b' && move[6] != 'c' && move[6] != 'd' && 
      move[6] != 'e' && move[6] != 'f' && move[6] != 'g' && move[6] != 'h') {
    return false;
  }

  else if (move[7] != '0' && move[7] != '1' && move[7] != '2' && move[7] != '3' &&
      move[7] != '4' && move[7] != '5' && move[7] != '6' && move[7] != '7') {
    return false;
  }

  else return true;
}

// check if the move is legal, if it is then complete the move
bool isValidMove(move_t move, board_t B) {
  
  int x1 = move->x1;
  int x2 = move->x2;
  int y1 = move->y1;
  int y2 = move->y2;
  
  board_piece_t gameBoard = B->gameBoard;
  int curPlayer = B->curPlayer;
  int startIndex = getIndex(x1, y1);
  int endIndex = getIndex(x2, y2);

  // check if there is a piece at starting location
  if (gameBoard[startIndex] == NULL) {
    printf("There is no piece at the specified location.\n");
    return false;
  }

  // check if player owns piece he's trying to move
  else if (gameBoard[startIndex]->player != curPlayer) {
    printf("That is not your piece.\n");
    return false;
  }

  // check if player owns piece at end position
  else if (gameBoard[endIndex]->player == curPlayer) {
    printf("You own the piece at end location.\n");
    return false;
  }

  int rowDiff = y1 - y2;
  int colDiff = x1 - x2;

  if (gameBoard[startIndex]->

}

move_t parseMove (string move) {
  int x1, y1, x2, y2;

  y1 = atoi(move[1].c_str());
  y2 = atoi(move[7].c_str());

  switch (move[0]) {
    case 'a': x1 = 0;
              break;
    case 'b': x1 = 1;
              break;
    case 'c': x1 = 2;
              break;
    case 'd': x1 = 3;
              break;
    case 'e': x1 = 4;
              break;
    case 'f': x1 = 5;
              break;
    case 'g': x1 = 6;
              break;
    case 'h': x1 = 7;
              break;
  }

  switch (move[6]) {
    case 'a': x2 = 0;
              break;
    case 'b': x2 = 1;
              break;
    case 'c': x2 = 2;
              break;
    case 'd': x2 = 3;
              break;
    case 'e': x2 = 4;
              break;
    case 'f': x2 = 5;
              break;
    case 'g': x2 = 6;
              break;
    case 'h': x2 = 7;
              break;
  }

  move_t m = malloc(sizeof(move));
  m->x1 = x1;
  m->y1 = y1;
  m->x2 = x2;
  m->y2 = y2;
  
  return m;
}

int main() {
  board_t B = malloc(sizeof(struct board));
  B->gameBoard = calloc(BOARD_WIDTH * BOARD_HEIGHT, sizeof(struct board_piece_t));
  initGame(B);
  while(1) {
    // read input from cmdline (e.g. LK e 5, LB a 6, P1 b 3, etc...)
    
    while(!isValidMoveFormat(move)) {
      printf("Invalid move format!");
      // get move
    }
    
    move_t m = parseMove(move);

    B->curPlayer = (B->curPlayer == WHITE) ? BLACK : WHITE;
  }
}
