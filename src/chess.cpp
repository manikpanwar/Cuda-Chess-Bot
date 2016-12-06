#include <chess.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>


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

void removeTakenPiece(player_t p, int startIndex, int endIndex, board_piece_t gameBoard, int curPlayer) {
  switch (gameBoard[endIndex]->piece->type) {
    case PAWN: for (int i = 0; i < 8; i++) {
                 if (p->pawns[i]->active) {
                   p->pawns[i]->active = false;
                   break;
                 }
               }
               break;
    case BISHOP: if (p->lbishop->active) {
                   p->lbishop->active = false;
                 }
                 else {
                   p->rbishop->active = false;
                 }
                 break;
    case KNIGHT: if (p->lknight->active) {
                   p->lknight->active = false;
                 }
                 else {
                   p->rknight->active = false;
                 }
                 break;
    case ROOK: if (p->lrook->active) {
                 p->lrook->active = false;
               }
               else {
                 p->rrook->active = false;
               }
               break;
    case QUEEN: p->queen->active = false;
                break;
    case KING: p->king->active = false;
               break;
  }
  gameBoard[endIndex]->piece->type = gameBoard[startIndex]->piece->type;
  gameBoard[endIndex]->player = curPlayer;
  gameBoard[startIndex] = NULL;
}

void movePiece(board_piece_t gameBoard, int startIndex, int endIndex, int curPlayer) {
  gameBoard[endIndex]->piece->type = gameBoard[startIndex]->piece->type;
  gameBoard[endIndex]->player = curPlayer;
  gameBoard[startIndex] = NULL;
}

// check if the move is legal, if it is then complete the move
bool isLegalMove(move_t move, board_t B) {
  
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

  // check valid moves for WHITE pawns since it will differ depending on player
  if (gameBoard[startIndex]->piece->type == PAWN && curPlayer == WHITE) {

    // if pawn is not in starting position, it can only move one space
    if (y1 != 1 && rowDiff <= 2) {
      printf("Pawns can only move 1 space after their first move.\n");
      return false;
    }

    // if pawn is in starting position, it can move up to 2 moves
    else if (y1 == 1 && rowDiff < 2) {
      printf("Pawns can only move 2 spaces on first move.\n");
      return false;
    }

    // pawns can only move forward, not sideways or backward
    else if (rowDiff >= 0) {
      printf("Pawns can only move forward.\n");
      return false;
    }

    // at max pawns can move one column over at a time
    else if (abs(colDiff) > 1) {
      printf("Pawns can't move that much horizontally.\n");
      return false;
    }

    // pawns can only move diagonally if there is an enemy piece there
    else if (abs(colDiff) == 1 and rowDiff == -1 && gameBoard[endIndex] == NULL) {
      printf("Pawns can only move diagonally if there is an enemy piece there.\n");
      return false;
    }

    // pawns can't move directly forward into an enemy piece
    else if (rowDiff == -1 && colDiff == 0 && gameBoard[endIndex] != NULL) {
      printf("Pawns can't move directly forward into an enemy piece.\n");
      return false;
    }

    // if you move the pawn diagonally and there is an enemy piece there
    else if (rowDiff == -1 && abs(colDiff) == 1) {
      removeTakenPiece(B->black, startIndex, endIndex, gameBoard, curPlayer);
      return true;
    }

    // if you move the pawn into an open space 
    else {
      movePiece(gameBoard, startIndex, endIndex, curPlayer);
      return true;
    }
  }
  // check valid move for BLACK pawns
  else if (gameBoard[startIndex]->piece->type == PAWN && curPlayer == BLACK) {

    // if pawn is not in starting position, it can only move one space
    if (y1 != 6 && rowDiff >= 2) {
      printf("Pawns can only move 1 space after their first move.\n");
      return false;
    }

    // if pawn is in starting position, it can move up to 2 moves
    else if (y1 == 6 && rowDiff > 2) {
      printf("Pawns can only move 2 spaces on first move.\n");
      return false;
    }

    // pawns can only move forward, not sideways or backward
    else if (rowDiff <= 0) {
      printf("Pawns can only move forward.\n");
      return false;
    }

    // at max pawns can move one column over at a time
    else if (abs(colDiff) > 1) {
      printf("Pawns can't move that much horizontally.\n");
      return false;
    }

    // pawns can only move diagonally if there is an enemy piece there
    else if (abs(colDiff) == 1 and rowDiff == 1 && gameBoard[endIndex] == NULL) {
      printf("Pawns can only move diagonally if there is an enemy piece there.\n");
      return false;
    }

    // pawns can't move directly forward into an enemy piece
    else if (rowDiff == 1 && colDiff == 0 && gameBoard[endIndex] != NULL) {
      printf("Pawns can't move directly forward into an enemy piece.\n");
      return false;
    }

    // if you move the pawn diagonally and there is an enemy piece there
    else if (rowDiff == 1 && abs(colDiff) == 1) {
      removeTakenPiece(B->white, startIndex, endIndex, gameBoard, curPlayer);
      return true;
    }

    // if you move the pawn into an open space 
    else {
      movePiece(gameBoard, startIndex, endIndex, curPlayer);
      return true;
    }
  }

  else if (gameBoard[startIndex]->piece->type == KING) {
    // kings can only move one space
    if (abs(rowDiff) > 1 || abs(colDiff) > 1) {
      printf("Kings an only move one space in any direction.\n");
      return false;
    }
    else if (gameBoard[endIndex] != NULL && gameBoard[endIndex]->player != curPlayer) {
      if (curPlayer == WHITE) {
        removeTakenPiece(B->black, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
      else {
        removeTakenPiece(B->white, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
    }
    else {
      movePiece(gameBoard, startIndex, endIndex, curPlayer);
      return true;
    }
  }

  else if (gameBoard[startIndex]->piece->type == QUEEN) {
    if (abs(rowDiff) != abs(colDiff) && rowDiff != 0 && colDiff != 0) {
      printf("Queens can only move diagonally or straight.\n");
      return false;
    }
    // TIME TO CHECK ALL DA POSSIBLE BLOCKING PIECES
    if (rowDiff > 0 && colDiff > 0) {
      for (int i = y1-1; i > y2; i--) {
        for (int j = x1-1; j > x2; j--) {
          int tempIndex = getIndex(j, i);
          if (gameBoard[tempIndex] != NULL) {
            printf("There is a piece blocking your move.\n");
            return false
          }
        }
      }
    }
    else if (rowDiff < 0 && colDiff < 0) {
      for (int i = y1+1; i < y2; i++) {
        for (int j = x1+1; j < x2; j++) {
          int tempIndex = getIndex(j, i);
          if (gameBoard[tempIndex] != NULL) {
            printf("There is a piece blocking your move.\n");
            return false
          }
        }
      }
    }
    else if (rowDiff > 0 && colDiff < 0) {
      for (int i = y1-1; i > y2; i--) {
        for (int j = x1+1; j < x2; j++) {
          int tempIndex = getIndex(j, i);
          if (gameBoard[tempIndex] != NULL) {
            printf("There is a piece blocking your move.\n");
            return false
          }
        }
      }
    }
    else if (rowDiff < 0 && colDiff > 0) {
      for (int i = y1+1; i < y2; i++) {
        for (int j = x1-1; j > x2; j--) {
          int tempIndex = getIndex(j, i);
          if (gameBoard[tempIndex] != NULL) {
            printf("There is a piece blocking your move.\n");
            return false
          }
        }
      }
    }
    else if (rowDiff == 0 && colDiff > 0) {
      for (int i = x1-1; i > x2; i--) {
        int tempIndex = getIndex(i, y1);
        if (gameBoard[tempIndex] != NULL) {
          printf("There is a piece blocking your move.\n");
          return false
        }
      }
    }
    else if (rowDiff == 0 && colDiff < 0) {
      for (int i = x1+1; i < x2; i++) {
        int tempIndex = getIndex(i, y1);
        if (gameBoard[tempIndex] != NULL) {
          printf("There is a piece blocking your move.\n");
          return false
        }
      }
    }
    else if (rowDiff > 0 && colDiff == 0) {
      for (int i = y1-1; i > y2; i--) {
        int tempIndex = getIndex(x1, i);
        if (gameBoard[tempIndex] != NULL) {
          printf("There is a piece blocking your move.\n");
          return false
        }
      }
    }
    else if (rowDiff < 0 && colDiff == 0) {
      for (int i = y1+1; i < y2; i++) {
        int tempIndex = getIndex(x1, i);
        if (gameBoard[tempIndex] != NULL) {
          printf("There is a piece blocking your move.\n");
          return false
        }
      }
    }
    else if (gameBoard[endIndex] != NULL && gameBoard[endIndex]->player != curPlayer) {
      if (curPlayer == WHITE) {
        removeTakenPiece(B->black, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
      else {
        removeTakenPiece(B->white, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
    }
    else {
      movePiece(gameBoard, startIndex, endIndex, curPlayer);
      return true;
    }
  }

  else if (gameBoard[startIndex]->piece->type == KNIGHT) {
    if (abs(rowDiff) * abs(colDiff) != 2) {
      printf("Illegal move for a knight.\n");
      return false;
    }
    else if (gameBoard[endIndex] != NULL && gameBoard[endIndex]->player != curPlayer) {
      if (curPlayer == WHITE) {
        removeTakenPiece(B->black, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
      else {
        removeTakenPiece(B->white, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
    }
    else {
      movePiece(gameBoard, startIndex, endIndex, curPlayer);
      return true;
    }
  }

  else if (gameBoard[startIndex]->piece->type == BISHOP) {
    if (abs(rowDiff) != abs(colDiff)) {
      printf("Bishops can only move diagonally.\n");
      return false;
    }
    // check all the blocking pieces
    else if (rowDiff > 0 && colDiff > 0) {
      for (int i = y1-1; i > y2; i--) {
        for (int j = x1-1; j > x2; j--) {
          int tempIndex = getIndex(j, i);
          if (gameBoard[tempIndex] != NULL) {
            printf("There is a piece blocking your move.\n");
            return false
          }
        }
      }
    }
    else if (rowDiff < 0 && colDiff < 0) {
      for (int i = y1+1; i < y2; i++) {
        for (int j = x1+1; j < x2; j++) {
          int tempIndex = getIndex(j, i);
          if (gameBoard[tempIndex] != NULL) {
            printf("There is a piece blocking your move.\n");
            return false
          }
        }
      }
    }
    else if (rowDiff > 0 && colDiff < 0) {
      for (int i = y1-1; i > y2; i--) {
        for (int j = x1+1; j < x2; j++) {
          int tempIndex = getIndex(j, i);
          if (gameBoard[tempIndex] != NULL) {
            printf("There is a piece blocking your move.\n");
            return false
          }
        }
      }
    }
    else if (rowDiff < 0 && colDiff > 0) {
      for (int i = y1+1; i < y2; i++) {
        for (int j = x1-1; j > x2; j--) {
          int tempIndex = getIndex(j, i);
          if (gameBoard[tempIndex] != NULL) {
            printf("There is a piece blocking your move.\n");
            return false
          }
        }
      }
    }
    else if (gameBoard[endIndex] != NULL && gameBoard[endIndex]->player != curPlayer) {
      if (curPlayer == WHITE) {
        removeTakenPiece(B->black, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
      else {
        removeTakenPiece(B->white, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
    }
    else {
      movePiece(gameBoard, startIndex, endIndex, curPlayer);
      return true;
    }
  }

  else if (gameBoard[startIndex]->piece->type == ROOK) {
    if (rowDiff != 0 && colDiff != 0) {
      printf("Rooks can only move directly forward or sideways.\n");
      return false;
    }
    // check for blocking pieces
    else if (rowDiff == 0 && colDiff > 0) {
      for (int i = x1-1; i > x2; i--) {
        int tempIndex = getIndex(i, y1);
        if (gameBoard[tempIndex] != NULL) {
          printf("There is a piece blocking your move.\n");
          return false
        }
      }
    }
    else if (rowDiff == 0 && colDiff < 0) {
      for (int i = x1+1; i < x2; i++) {
        int tempIndex = getIndex(i, y1);
        if (gameBoard[tempIndex] != NULL) {
          printf("There is a piece blocking your move.\n");
          return false
        }
      }
    }
    else if (rowDiff > 0 && colDiff == 0) {
      for (int i = y1-1; i > y2; i--) {
        int tempIndex = getIndex(x1, i);
        if (gameBoard[tempIndex] != NULL) {
          printf("There is a piece blocking your move.\n");
          return false
        }
      }
    }
    else if (rowDiff < 0 && colDiff == 0) {
      for (int i = y1+1; i < y2; i++) {
        int tempIndex = getIndex(x1, i);
        if (gameBoard[tempIndex] != NULL) {
          printf("There is a piece blocking your move.\n");
          return false
        }
      }
    }
    else if (gameBoard[endIndex] != NULL && gameBoard[endIndex]->player != curPlayer) {
      if (curPlayer == WHITE) {
        removeTakenPiece(B->black, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
      else {
        removeTakenPiece(B->white, startIndex, endIndex, gameBoard, curPlayer);
        return true;
      }
    }
    else {
      movePiece(gameBoard, startIndex, endIndex, curPlayer);
      return true;
    }
  }

  else return false;
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

int gameOver(board_t B) {
  if (!B->white->king->active) {
    return BLACK:
  }
  else if (!B->black->king->active) {
    return WHITE;
  }
  else {
    return -1;
  }
}

int main() {
  board_t B = malloc(sizeof(struct board));
  B->gameBoard = calloc(BOARD_WIDTH * BOARD_HEIGHT, sizeof(struct board_piece_t));
  initGame(B);
  char* move;
  while(1) {
    cout << "Please enter a move: ";
    cin >> move;
    // read input from cmdline (e.g. LK e 5, LB a 6, P1 b 3, etc...)
    
    while(!isValidMoveFormat(move)) {
      printf("Invalid move format!\n");
      // get move
      cout << "Please enter a move: ";
      cin >> move;
    }
    
    move_t m = parseMove(move);

    while (!isLegalMove(m, B)) {
      printf("Please enter a legal move.\n");
      cout << "Please enter a move: ";
      cin >> move;
      while(!isValidMoveFormat(move)) {
        printf("Invalid move format!\n");
        // get move
        cout << "Please enter a move: ";
        cin >> move;
      }
    
      m = parseMove(move);
    }

    // check game over
    if (gameOver(B) == WHITE) {
      printf("White wins!\n");
      break;
    }

    else if (gameOver(B) == BLACK) {
      printf("Black wins!\n");
      break;
    }

    B->curPlayer = (B->curPlayer == WHITE) ? BLACK : WHITE;
  }
}