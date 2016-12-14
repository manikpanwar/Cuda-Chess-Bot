#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <omp.h>
#include <cstring>
#include "chess.h"
#include "lib/CycleTimer.h"
#include "alphabeta.h"



using std::string;

int AI = 0;

// a lot of game implementation code taken from https://github.com/jordancunningham/Chess/blob/master/Chess_Shared/Chess_Shared/Chess_Shared.cpp


int getIndex(int col, int row) {
  return row * BOARD_WIDTH + col;
}

void initPlayers(board_t B) {
  // inits game board and player structs

  player_t w = (player_t)malloc(sizeof(struct player));
  player_t b = (player_t)malloc(sizeof(struct player));

  board_piece_t game_board = B->gameBoard;
  w->king = (pos_t)malloc(sizeof(struct pos));
  w->king->x = 4;     // x is columns, y is rows
  w->king->y = 0;
  w->king->active = true;
  w->king->type = KING;
  game_board[getIndex(4, 0)].piece = w->king;
  game_board[getIndex(4, 0)].player = WHITE;

  w->queen = (pos_t)malloc(sizeof(struct pos));
  w->queen->x = 3;
  w->queen->y = 0;
  w->queen->active = true;
  w->queen->type = QUEEN;
  game_board[getIndex(3, 0)].piece = w->queen;
  game_board[getIndex(3, 0)].player = WHITE;

  w->lbishop = (pos_t)malloc(sizeof(struct pos));
  w->lbishop->x = 2;
  w->lbishop->y = 0;
  w->lbishop->active = true;
  w->lbishop->type = BISHOP;
  game_board[getIndex(2, 0)].piece = w->lbishop;
  game_board[getIndex(2, 0)].player = WHITE;

  w->rbishop = (pos_t)malloc(sizeof(struct pos));
  w->rbishop->x = 5;
  w->rbishop->y = 0;
  w->rbishop->active = true;
  w->rbishop->type = BISHOP;
  game_board[getIndex(5, 0)].piece = w->rbishop;
  game_board[getIndex(5, 0)].player = WHITE;

  w->lknight = (pos_t)malloc(sizeof(struct pos));
  w->lknight->x = 1;
  w->lknight->y = 0;
  w->lknight->active = true;
  w->lknight->type = KNIGHT;
  game_board[getIndex(1, 0)].piece = w->lknight;
  game_board[getIndex(1, 0)].player = WHITE;

  w->rknight = (pos_t)malloc(sizeof(struct pos));
  w->rknight->x = 6;
  w->rknight->y = 0;
  w->rknight->active = true;
  w->rknight->type = KNIGHT;
  game_board[getIndex(6, 0)].piece = w->rknight;
  game_board[getIndex(6, 0)].player = WHITE;

  w->lrook = (pos_t)malloc(sizeof(struct pos));
  w->lrook->x = 0;
  w->lrook->y = 0;
  w->lrook->active = true;
  w->lrook->type = ROOK;
  game_board[getIndex(0, 0)].piece = w->lrook;
  game_board[getIndex(0, 0)].player = WHITE;

  w->rrook = (pos_t)malloc(sizeof(struct pos));
  w->rrook->x = 7;
  w->rrook->y = 0;
  w->rrook->active = true;
  w->rrook->type = ROOK;
  game_board[getIndex(7, 0)].piece = w->rrook;
  game_board[getIndex(7, 0)].player = WHITE;

  w->pawns = (pos_t)malloc(BOARD_WIDTH * sizeof(struct pos));
  for(int i = 0; i < BOARD_WIDTH; i++) {
    //w->pawns[i] = (pos_t)malloc(sizeof(struct pos));
    w->pawns[i].x = i;
    w->pawns[i].y = 1;
    w->pawns[i].active = true;
    w->pawns[i].type = PAWN;
    game_board[getIndex(i, 1)].piece = &w->pawns[i];
    game_board[getIndex(i, 1)].player = WHITE;

  }

  b->king = (pos_t)malloc(sizeof(struct pos));
  b->king->x = 4;
  b->king->y = 7;
  b->king->active = true;
  b->king->type = KING;
  game_board[getIndex(4, 7)].piece = b->king;
  game_board[getIndex(4, 7)].player = BLACK;

  b->queen = (pos_t)malloc(sizeof(struct pos));
  b->queen->x = 3;
  b->queen->y = 7;
  b->queen->active = true;
  b->queen->type = QUEEN;
  game_board[getIndex(3, 7)].piece = b->queen;
  game_board[getIndex(3, 7)].player = BLACK;

  b->lbishop = (pos_t)malloc(sizeof(struct pos));
  b->lbishop->x = 2;
  b->lbishop->y = 7;
  b->lbishop->active = true;
  b->lbishop->type = BISHOP;
  game_board[getIndex(2, 7)].piece = b->lbishop;
  game_board[getIndex(2, 7)].player = BLACK;

  b->rbishop = (pos_t)malloc(sizeof(struct pos));
  b->rbishop->x = 5;
  b->rbishop->y = 7;
  b->rbishop->active = true;
  b->rbishop->type = BISHOP;
  game_board[getIndex(5, 7)].piece = b->rbishop;
  game_board[getIndex(5, 7)].player = BLACK;

  b->lknight = (pos_t)malloc(sizeof(struct pos));
  b->lknight->x = 1;
  b->lknight->y = 7;
  b->lknight->active = true;
  b->lknight->type = KNIGHT;
  game_board[getIndex(1, 7)].piece = b->lknight;
  game_board[getIndex(1, 7)].player = BLACK;

  b->rknight = (pos_t)malloc(sizeof(struct pos));
  b->rknight->x = 6;
  b->rknight->y = 7;
  b->rknight->active = true;
  b->rknight->type = KNIGHT;
  game_board[getIndex(6, 7)].piece = b->rknight;
  game_board[getIndex(6, 7)].player = BLACK;

  b->lrook = (pos_t)malloc(sizeof(struct pos));
  b->lrook->x = 0;
  b->lrook->y = 7;
  b->lrook->active = true;
  b->lrook->type = ROOK;
  game_board[getIndex(0, 7)].piece = b->lrook;
  game_board[getIndex(0, 7)].player = BLACK;

  b->rrook = (pos_t)malloc(sizeof(struct pos));
  b->rrook->x = 7;
  b->rrook->y = 7;
  b->rrook->active = true;
  b->rrook->type = ROOK;
  game_board[getIndex(7, 7)].piece = b->rrook;
  game_board[getIndex(7, 7)].player = BLACK;

  b->pawns = (pos_t)malloc(BOARD_WIDTH * sizeof(struct pos));
  for(int i = 0; i < BOARD_WIDTH; i++) {
    b->pawns[i].x = i;
    b->pawns[i].y = 6;
    b->pawns[i].active = true;
    b->pawns[i].type = PAWN;
    game_board[getIndex(i, 6)].piece = &b->pawns[i];
    game_board[getIndex(i, 6)].player = BLACK;
  }

  B->white = w;
  B->black = b;
}

void initGame(board_t B) {
  B->curPlayer = WHITE;
  B->gameOver = false;
  initPlayers(B); // inits players and game board
}

// checks if the format of the move is valid
bool isValidMoveFormat(char move[]) {
  printf(move);
  if (std::strlen(move) != 6) {
    printf("length = %d", std::strlen(move));
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

  else if (move[2] != 't' && move[3] != 'o') {
    return false;
  }

  else if (move[4] != 'a' && move[4] != 'b' && move[4] != 'c' && move[4] != 'd' &&
      move[4] != 'e' && move[4] != 'f' && move[4] != 'g' && move[4] != 'h') {
    return false;
  }

  else if (move[5] != '0' && move[5] != '1' && move[5] != '2' && move[5] != '3' &&
      move[5] != '4' && move[5] != '5' && move[5] != '6' && move[5] != '7') {
    return false;
  }

  else return true;
}

void removeTakenPiece(player_t p, int startIndex, int endIndex, board_piece_t gameBoard, int curPlayer) {
  switch (gameBoard[endIndex].piece->type) {
    case PAWN: {for (int i = 0; i < 8; i++) {
                     if (p->pawns[i].active) {
                       p->pawns[i].active = false;
                       break;
                     }
                   }
                   break;}
    case BISHOP: {if (p->lbishop->active) {
                       p->lbishop->active = false;
                     }
                     else {
                       p->rbishop->active = false;
                     }
                     break;}
    case KNIGHT: {if (p->lknight->active) {
                       p->lknight->active = false;
                     }
                     else {
                       p->rknight->active = false;
                     }
                     break;}
    case ROOK: {if (p->lrook->active) {
                     p->lrook->active = false;
                   }
                   else {
                     p->rrook->active = false;
                   }
                   break;}
    case QUEEN: {p->queen->active = false;
                    break;}
    case KING: {p->king->active = false;
                   break;}
  }
  gameBoard[endIndex] = gameBoard[startIndex];
  gameBoard[startIndex].piece = NULL;
}

void movePiece(board_piece_t gameBoard, int startIndex, int endIndex, int curPlayer) {
  gameBoard[endIndex] = gameBoard[startIndex];
  gameBoard[startIndex].piece = NULL;
}

void undoMove(int x1, int y1, board_piece startPiece, int x2, int y2,
 board_piece endPiece, board_t B, int curPlayer) {
  int startIndex = getIndex(x1, y1);
  int endIndex = getIndex(x2, y2);

  board_piece_t gameBoard = B->gameBoard;

  gameBoard[startIndex] = startPiece;
  gameBoard[endIndex] = endPiece;

  // int curPlayer = B->curPlayer;
  player_t p;
  if (curPlayer == WHITE) {
    p = B->black;
  }
  else if (curPlayer == BLACK) {
    p = B->white;
  }

  // logic for bringing a piece back from the dead if it was taken
  if (gameBoard[endIndex].piece != NULL) {
    switch (gameBoard[endIndex].piece->type) {
      case PAWN: {for (int i = 0; i < 8; i++) {
                         if (!p->pawns[i].active) {
                           p->pawns[i].active = true;
                           break;
                         }
                       }
                       break;}
      case BISHOP: {if (!p->lbishop->active) {
                           p->lbishop->active = true;
                         }
                         else {
                           p->rbishop->active = true;
                         }
                         break;}
      case KNIGHT: {if (!p->lknight->active) {
                           p->lknight->active = true;
                         }
                         else {
                           p->rknight->active = true;
                         }
                         break;}
      case ROOK: {if (!p->lrook->active) {
                               p->lrook->active = true;
                             }
                             else {
                               p->rrook->active = true;
                             }
                             break;}
      case QUEEN: {p->queen->active = true;
                              break;}
      case KING: {p->king->active = true;
                       break;}
    }
  }
}

void applyMove(move_t move, board_t B, int curPlayer) {
  int x1 = move->x1;
  int x2 = move->x2;
  int y1 = move->y1;
  int y2 = move->y2;

  board_piece_t gameBoard = B->gameBoard;
  // int curPlayer = B->curPlayer;
  int startIndex = getIndex(x1, y1);
  int endIndex = getIndex(x2, y2);

  if (gameBoard[endIndex].piece != NULL && gameBoard[endIndex].player != curPlayer) {
    if (curPlayer == WHITE) {
      removeTakenPiece(B->black, startIndex, endIndex, gameBoard, curPlayer);
    }
    else {
      removeTakenPiece(B->white, startIndex, endIndex, gameBoard, curPlayer);
    }
  }
  else {
    movePiece(gameBoard, startIndex, endIndex, curPlayer);
  }
}

// check if the move is legal, if it is then complete the move
bool isLegalMove(move_t move, board_t B, int curPlayer) {

  int x1 = move->x1;
  int x2 = move->x2;
  int y1 = move->y1;
  int y2 = move->y2;

  if (!AI) printf("Move x1 = %d y1 = %d x2 = %d y2 = %d", x1, y1, x2, y2);

  if (x2 < 0 || x2 >= BOARD_WIDTH || y2 < 0 || y2 >= BOARD_HEIGHT) {
    if (!AI) printf("You can't move off the board plz\n");
    return false;
  }

  board_piece_t gameBoard = B->gameBoard;
  // int curPlayer = B->curPlayer;
  int startIndex = getIndex(x1, y1);
  int endIndex = getIndex(x2, y2);

  // check if there is a piece at starting location
  if (gameBoard[startIndex].piece == NULL) {
    if (!AI) printf("There is no piece at the specified location.\n");
    return false;
  }

  // check if player owns piece he's trying to move
  else if (gameBoard[startIndex].player != curPlayer) {
    if (!AI) printf("That is not your piece.\n");
    return false;
  }

  // check if player owns piece at end position
  else if (gameBoard[endIndex].player == curPlayer && gameBoard[endIndex].piece != NULL) {
    if (!AI) printf("You own the piece at end location.\n");
    return false;
  }

  int rowDiff = y1 - y2;
  int colDiff = x1 - x2;

  // check valid moves for WHITE pawns since it will differ depending on player
  if (gameBoard[startIndex].piece->type == PAWN && curPlayer == WHITE) {

    // if pawn is not in starting position, it can only move one space
    if (y1 != 1 && rowDiff <= -2) {
      if (!AI) printf("Pawns can only move 1 space after their first move.\n");
      return false;
    }

    // if pawn is in starting position, it can move up to 2 moves
    else if (y1 == 1 && rowDiff < -2) {
      if (!AI) printf("Pawns can only move 2 spaces on first move.\n");
      return false;
    }

    // pawns can only move forward, not sideways or backward
    else if (rowDiff >= 0) {
      if (!AI) printf("Pawns can only move forward.\n");
      return false;
    }

    // at max pawns can move one column over at a time
    else if (abs(colDiff) > 1) {
      if (!AI) printf("Pawns can't move that much horizontally.\n");
      return false;
    }

    // pawns can only move diagonally if there is an enemy piece there
    else if (abs(colDiff) == 1 and rowDiff == -1 && gameBoard[endIndex].piece == NULL) {
      if (!AI) printf("Pawns can only move diagonally if there is an enemy piece there.\n");
      return false;
    }

    // pawns can't move directly forward into an enemy piece
    else if (rowDiff == -1 && colDiff == 0 && gameBoard[endIndex].piece != NULL) {
      if (!AI) printf("Pawns can't move directly forward into an enemy piece.\n");
      return false;
    }

    else return true;

  }
  // check valid move for BLACK pawns
  else if (gameBoard[startIndex].piece->type == PAWN && curPlayer == BLACK) {

    // if pawn is not in starting position, it can only move one space
    if (y1 != 6 && rowDiff >= 2) {
      if (!AI) printf("Pawns can only move 1 space after their first move.\n");
      return false;
    }

    // if pawn is in starting position, it can move up to 2 moves
    else if (y1 == 6 && rowDiff > 2) {
      if (!AI) printf("Pawns can only move 2 spaces on first move.\n");
      return false;
    }

    // pawns can only move forward, not sideways or backward
    else if (rowDiff <= 0) {
      if (!AI) printf("Pawns can only move forward.\n");
      return false;
    }

    // at max pawns can move one column over at a time
    else if (abs(colDiff) > 1) {
      if (!AI) printf("Pawns can't move that much horizontally.\n");
      return false;
    }

    // pawns can only move diagonally if there is an enemy piece there
    else if (abs(colDiff) == 1 and rowDiff == 1 && gameBoard[endIndex].piece == NULL) {
      if (!AI) printf("Pawns can only move diagonally if there is an enemy piece there.\n");
      return false;
    }

    // pawns can't move directly forward into an enemy piece
    else if (rowDiff == 1 && colDiff == 0 && gameBoard[endIndex].piece != NULL) {
      if (!AI) printf("Pawns can't move directly forward into an enemy piece.\n");
      return false;
    }

    else return true;

   }

  else if (gameBoard[startIndex].piece->type == KING) {
    // kings can only move one space
    if (abs(rowDiff) > 1 || abs(colDiff) > 1) {
      if (!AI) printf("Kings an only move one space in any direction.\n");
      return false;
    }

    else return true;
  }

  else if (gameBoard[startIndex].piece->type == QUEEN) {
    if (abs(rowDiff) != abs(colDiff) && rowDiff != 0 && colDiff != 0) {
      if (!AI) printf("Queens can only move diagonally or straight.\n");
      return false;
    }
    // TIME TO CHECK ALL DA POSSIBLE BLOCKING PIECES
    if (rowDiff > 0 && colDiff > 0) {
      int j = x1;
      for (int i = y1-1; i > y2; i--) {
        j--;
        int tempIndex = getIndex(j, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff < 0 && colDiff < 0) {
      int j = x1;
      for (int i = y1+1; i < y2; i++) {
        j++;
        int tempIndex = getIndex(j, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff > 0 && colDiff < 0) {
      int j = x1;
      for (int i = y1-1; i > y2; i--) {
        j++;
        int tempIndex = getIndex(j, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff < 0 && colDiff > 0) {
      int j = x1;
      for (int i = y1+1; i < y2; i++) {
        j--;
        int tempIndex = getIndex(j, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff == 0 && colDiff > 0) {
      for (int i = x1-1; i > x2; i--) {
        int tempIndex = getIndex(i, y1);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff == 0 && colDiff < 0) {
      for (int i = x1+1; i < x2; i++) {
        int tempIndex = getIndex(i, y1);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff > 0 && colDiff == 0) {
      for (int i = y1-1; i > y2; i--) {
        int tempIndex = getIndex(x1, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff < 0 && colDiff == 0) {
      for (int i = y1+1; i < y2; i++) {
        int tempIndex = getIndex(x1, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }

    else return true;

  }

  else if (gameBoard[startIndex].piece->type == KNIGHT) {
    if (abs(rowDiff) * abs(colDiff) != 2) {
      if (!AI) printf("Illegal move for a knight.\n");
      return false;
    }

    else return true;

  }

  else if (gameBoard[startIndex].piece->type == BISHOP) {
    if (abs(rowDiff) != abs(colDiff)) {
      if (!AI) printf("Bishops can only move diagonally.\n");
      return false;
    }
    // check all the blocking pieces
    else if (rowDiff > 0 && colDiff > 0) {
      int j = x1;
      for (int i = y1-1; i > y2; i--) {
        j--;
        int tempIndex = getIndex(j, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff < 0 && colDiff < 0) {
      int j = x1;
      for (int i = y1+1; i < y2; i++) {
        j++;
        int tempIndex = getIndex(j, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff > 0 && colDiff < 0) {
      int j = x1;
      for (int i = y1-1; i > y2; i--) {
        j++;
        int tempIndex = getIndex(j, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff < 0 && colDiff > 0) {
      int j = x1;
      for (int i = y1+1; i < y2; i++) {
        j--;
        int tempIndex = getIndex(j, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }

    else return true;

  }

  else if (gameBoard[startIndex].piece->type == ROOK) {
    if (rowDiff != 0 && colDiff != 0) {
      if (!AI) printf("Rooks can only move directly forward or sideways.\n");
      return false;
    }
    // check for blocking pieces
    else if (rowDiff == 0 && colDiff > 0) {
      for (int i = x1-1; i > x2; i--) {
        int tempIndex = getIndex(i, y1);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff == 0 && colDiff < 0) {
      for (int i = x1+1; i < x2; i++) {
        int tempIndex = getIndex(i, y1);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff > 0 && colDiff == 0) {
      for (int i = y1-1; i > y2; i--) {
        int tempIndex = getIndex(x1, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }
    else if (rowDiff < 0 && colDiff == 0) {
      for (int i = y1+1; i < y2; i++) {
        int tempIndex = getIndex(x1, i);
        if (gameBoard[tempIndex].piece != NULL) {
          if (!AI) printf("There is a piece blocking your move.\n");
          return false;
        }
      }
    }

    else return true;
  }

  else return false;
}

move_t parseMove (string move) {
  int x1, y1, x2, y2;

  y1 = (int)move[1] - '0';
  y2 = (int)move[5] - '0';

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

  switch (move[4]) {
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

  move_t m = (move_t)malloc(sizeof(move));
  m->x1 = x1;
  m->y1 = y1;
  m->x2 = x2;
  m->y2 = y2;

  return m;
}

int gameOver(board_t B) {
  if (!B->white->king->active) {
    return BLACK;
  }
  else if (!B->black->king->active) {
    return WHITE;
  }
  else {
    return -1;
  }
}

int main() {
  board_t B = (board_t)malloc(sizeof(struct board));
  B->gameBoard = (board_piece_t)calloc(BOARD_WIDTH * BOARD_HEIGHT, sizeof(struct board_piece));
  initGame(B);
  char move[10];
  int numMoves = 0;

  #ifdef OMP
    omp_set_num_threads(OMPNUMTHREADS);
  #endif
  while(1) {
    numMoves++;
    move_t m;
    if (B->curPlayer == BLACK) {
      AI = 0;
      move[0] = '\0';
      std::cout << "Please enter a move: ";
      std::cin >> move;
      // read input from cmdline (e.g. LK e 5, LB a 6, P1 b 3, etc...)

      while(!isValidMoveFormat(move)) {
        move[0] = '\0';
        std::cout << "Please enter a move: ";
        // get move
        std::cin >> move;
      }

      m = parseMove(move);

      while (!isLegalMove(m, B, BLACK)) {
        move[0] = '\0';
        std::cout << "Please enter a move: ";
        std::cin >> move;
        while(!isValidMoveFormat(move)) {
          // get move
          move[0] = '\0';
          std::cout << "Please enter a move: ";
          std::cin >> move;
        }

        m = parseMove(move);
      }
    } else {
      // AI LES GOOO
      AI = 1;
      double min = 20000000.f;
      double startTime, endTime;
      startTime = CycleTimer::currentSeconds();
      m = nextMove(B, MAXI, WHITE);
      endTime = CycleTimer::currentSeconds();
      min = (endTime - startTime) * 1000.f;
      printf("AI (W) decided move col1 = %d row1 = %d: col2 = %d row2 = %d in min time = %.3f (ms)\n",
          m->x1, m->y1, m->x2, m->y2, min);
    }

    applyMove(m, B, B->curPlayer);
    // check game over
    if (gameOver(B) == WHITE) {
      B->gameOver = true;
      printf("White wins!\n");
      break;
    }

    else if (gameOver(B) == BLACK) {
      B->gameOver = true;
      printf("Black wins!\n");
      break;
    }
    if(numMoves > 100) {return 0;}

    B->curPlayer = (B->curPlayer == WHITE) ? BLACK : WHITE;
  }
  return 0;
}
