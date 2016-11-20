#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

void generatePossibleMovesKing(board_t board, int x, int y,
    std::vector<move_t> possibleMoves) {
  // king can move in any direction
  // x == x1, y == y1
  move_t m1, m2, m3, m4, m5, m6, m7, m8;
  m1 = malloc(sizeof(struct move));
  m2 = malloc(sizeof(struct move));
  m3 = malloc(sizeof(struct move));
  m4 = malloc(sizeof(struct move));
  m5 = malloc(sizeof(struct move));
  m6 = malloc(sizeof(struct move));
  m7 = malloc(sizeof(struct move));
  m8 = malloc(sizeof(struct move));
  m1->x1 = x;
  m1->y1 = y;
  m2->x1 = x;
  m2->y1 = y;
  m3->x1 = x;
  m3->y1 = y;
  m4->x1 = x;
  m4->y1 = y;
  m5->x1 = x;
  m5->y1 = y;
  m6->x1 = x;
  m6->y1 = y;
  m7->x1 = x;
  m7->y1 = y;
  m8->x1 = x;
  m8->y1 = y;

  m1->x2 = x + 1;
  m1->y2 = y;

  m2->x2 = x + 1;
  m2->y2 = y - 1;

  m3->x2 = x + 1;
  m3->y2 = y + 1;

  m4->x2 = x;
  m4->y2 = y - 1;

  m5->x2 = x;
  m5->y2 = y + 1;

  m6->x2 = x - 1;
  m6->y2 = y;

  m7->x2 = x - 1;
  m7->y2 = y - 1;

  m8->x2 = x - 1;
  m8->y2 = y + 1;

  if (isLegalMove(m1, board)) {
    possibleMoves.push_back(m1);
  } else {
    free(m1);
  }
  if (isLegalMove(m2, board)) {
    possibleMoves.push_back(m2);
  } else {
    free(m2);
  }
  if (isLegalMove(m3, board)) {
    possibleMoves.push_back(m3);
  } else {
    free(m3);
  }
  if (isLegalMove(m4, board)) {
    possibleMoves.push_back(m4);
  } else {
    free(m4);
  }
  if (isLegalMove(m5, board)) {
    possibleMoves.push_back(m5);
  } else {
    free(m5);
  }
  if (isLegalMove(m6, board)) {
    possibleMoves.push_back(m6);
  } else {
    free(m6);
  }
  if (isLegalMove(m7, board)) {
    possibleMoves.push_back(m7);
  } else {
    free(m7);
  }
  if (isLegalMove(m8, board)) {
    possibleMoves.push_back(m8);
  } else {
    free(m8);
  }
}


void generatePossibleMovesQueen(board_t board, int x, int y,
    std::vector<move_t> possibleMoves) {

  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_WIDTH; col++) {
      move_t curMove = malloc(sizeof(struct move));
      curMove->x1 = x;
      curMove->y1 = y;
      curMove->x2 = col;
      curMove->y2 = row;
      if (isLegalMove(curMove, board)) {
        possibleMoves.push_back(curMove);
      } else {
        free(curMove);
      }
    }
  }

}

void generatePossibleMovesBishop(board_t board, int x, int y,
    std::vector<move_t> possibleMoves) {

  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_WIDTH; col++) {
      if (row - col == y - x || (row + col) == x + y) {
        move_t curMove = malloc(sizeof(struct move));
        curMove->x1 = x;
        curMove->y1 = y;
        curMove->x2 = col;
        curMove->y2 = row;
        if (isLegalMove(curMove, board)) {
          possibleMoves.push_back(curMove);
        } else {
          free(curMove);
        }
      }
    }
  }

}

void generatePossibleMovesKnight(board_t board, int x, int y,
    std::vector<move_t> possibleMoves) {
  // x == x1, y == y1
  move_t m1, m2, m3, m4, m5, m6, m7, m8;
  m1 = malloc(sizeof(struct move));
  m2 = malloc(sizeof(struct move));
  m3 = malloc(sizeof(struct move));
  m4 = malloc(sizeof(struct move));
  m5 = malloc(sizeof(struct move));
  m6 = malloc(sizeof(struct move));
  m7 = malloc(sizeof(struct move));
  m8 = malloc(sizeof(struct move));
  m1->x1 = x;
  m1->y1 = y;
  m2->x1 = x;
  m2->y1 = y;
  m3->x1 = x;
  m3->y1 = y;
  m4->x1 = x;
  m4->y1 = y;
  m5->x1 = x;
  m5->y1 = y;
  m6->x1 = x;
  m6->y1 = y;
  m7->x1 = x;
  m7->y1 = y;
  m8->x1 = x;
  m8->y1 = y;

  m1->x2 = x + 2;
  m1->y2 = y - 1;

  m2->x2 = x + 2;
  m2->y2 = y + 1;

  m3->x2 = x - 2;
  m3->y2 = y - 1;

  m4->x2 = x - 2;
  m4->y2 = y + 1;

  m5->x2 = x + 1;
  m5->y2 = y - 2;

  m6->x2 = x - 1;
  m6->y2 = y - 2;

  m7->x2 = x + 1;
  m7->y2 = y + 2;

  m8->x2 = x - 1;
  m8->y2 = y + 2;

  if (isLegalMove(m1, board)) {
    possibleMoves.push_back(m1);
  } else {
    free(m1);
  }
  if (isLegalMove(m2, board)) {
    possibleMoves.push_back(m2);
  } else {
    free(m2);
  }
  if (isLegalMove(m3, board)) {
    possibleMoves.push_back(m3);
  } else {
    free(m3);
  }
  if (isLegalMove(m4, board)) {
    possibleMoves.push_back(m4);
  } else {
    free(m4);
  }
  if (isLegalMove(m5, board)) {
    possibleMoves.push_back(m5);
  } else {
    free(m5);
  }
  if (isLegalMove(m6, board)) {
    possibleMoves.push_back(m6);
  } else {
    free(m6);
  }
  if (isLegalMove(m7, board)) {
    possibleMoves.push_back(m7);
  } else {
    free(m7);
  }
  if (isLegalMove(m8, board)) {
    possibleMoves.push_back(m8);
  } else {
    free(m8);
  }

}

void generatePossibleMovesRook(board_t board, int x, int y,
    std::vector<move_t> possibleMoves) {

  for (int row = 0; row < BOARD_HEIGHT; row++) {
    int col = col;  // col stays the same
    move_t curMove = malloc(sizeof(struct move));
    curMove->x1 = x;
    curMove->y1 = y;
    curMove->x2 = col;
    curMove->y2 = row;
    if (isLegalMove(curMove, board)) {
      possibleMoves.push_back(curMove);
    } else {
      free(curMove);
    }
  }
  for (int col = 0; row < BOARD_WIDTH; col++) {
    int row = row;  // row stays the same
    move_t curMove = malloc(sizeof(struct move));
    curMove->x1 = x;
    curMove->y1 = y;
    curMove->x2 = col;
    curMove->y2 = row;
    if (isLegalMove(curMove, board)) {
      possibleMoves.push_back(curMove);
    } else {
      free(curMove);
    }
  }
}

void generatePossibleMovesPawn(board_t board, int x, int y,
    std::vector<move_t> possibleMoves, int curPlayer) {
  int mf = (curPlayer == WHITE) ? 1 : -1;  // multFactor
  move_t m1, m2, m3, m4;
  m1 = malloc(sizeof(struct move));
  m2 = malloc(sizeof(struct move));
  m3 = malloc(sizeof(struct move));
  m4 = malloc(sizeof(struct move));

  m1->x1 = x;
  m1->y1 = y;
  m2->x1 = x;
  m2->y1 = y;
  m3->x1 = x;
  m3->y1 = y;
  m4->x1 = x;
  m4->y1 = y;


  m1->x2 = x;
  m1->y2 = y + 1 * mf;

  m2->x2 = x;
  m2->y2 = y + 2 * mf;

  m3->x2 = x - 1;
  m3->y2 = y + 1 * mf;

  m4->x2 = x + 1;
  m4->y2 = y + 1 * mf;

  if (isLegalMove(m1, board)) {
    possibleMoves.push_back(m1);
  } else {
    free(m1);
  }
  if (isLegalMove(m2, board)) {
    possibleMoves.push_back(m2);
  } else {
    free(m2);
  }
  if (isLegalMove(m3, board)) {
    possibleMoves.push_back(m3);
  } else {
    free(m3);
  }
  if (isLegalMove(m4, board)) {
    possibleMoves.push_back(m4);
  } else {
    free(m4);
  }
}

std::vector<move_t> generatePossibleMoves(board_t board) {
  // given current state of board, generate all possible moves
  std::vector<move_t> possibleMoves;
  if (board->gameOver) {
    return possibleMoves;
  }

  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_WIDTH; col++) {
      pos_t piece = board->gameBoard[getIndex(col, row)];
      if (piece == NULL) {
        // nothing at this position on the board
        continue;
      }
      int x1 = piece->x;
      int y1 = piece->y;
      int curPlayer = board->curPlayer;
      switch (piece->type) {
        case KING: {
                     generatePossibleMovesKing(board, x, y, possibleMoves);
                     break;
                   }
        case QUEEN: {
                      generatePossibleMovesQueen(board, x, y, possibleMoves);
                      break;
                    }
        case BISHOP: {
                       generatePossibleMovesBishop(board, x, y, possibleMoves);
                       break;
                     }
        case KNIGHT: {
                       generatePossibleMovesKnight(board, x, y, possibleMoves);
                       break;
                     }
        case ROOK: {
                     generatePossibleMovesRook(board, x, y, possibleMoves);
                     break;
                   }
        case PAWN: {
                     generatePossibleMovesPawn(board, x, y,
                         possibleMoves, curPlayer);
                     break
                   }
      }
    }
  }

}


// heuristic taken from https://chessprogramming.wikispaces.com/Evaluation
int score(board_t board) {
  // Minimax usually associates the white side with the max-player and black
  // with the min-player and always evaluates from the white point of view

  player_t white = board->white;
  player_t black = board->black;

  // king
  int wka = white->king->active;
  int bka = black->king->active;
  int result = 200 * (wka - bka);

  // queen
  int wqa = white->queen->active;
  int bqa = black->queen->active;
  result += 9 * (wqa - bqa);

  // rooks
  int wra = (int)white->lrook->active + (int)white->rrook->active;
  int bra = (int)black->lrook->active + (int)black->rrook->active;
  result += 5 * (wra - bra);


  // bishops an knights
  int wbka = (int)white->lbishop->active + (int)white->rbishop->active;
  wbka = (int)white->lknight->active + (int)white->rknight->active;

  int bbka = (int)black->lbishop->active + (int)black->rbishop->active;
  bbka = (int)black->lknight->active + (int)black->rknight->active;
  result += 3 * (wbka - bbka);

  // pawns
  int wpawns = 0;
  int bpawns = 0;
  for (int i = 0; i < BOARD_WIDTH; i++) {
    if (white->pawns[i]->active) wpawns += 1;
    if (black->pawns[i]->active) bpawns += 1;
  }
  result += 1 * (wpawns - bpawns);

  // TODO: add mobility scoring to the result
  return result;

}
