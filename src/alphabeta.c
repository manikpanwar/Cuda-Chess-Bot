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

  if (isLegalMove(m1, board)) possibleMoves.push_back(m1);
  if (isLegalMove(m2, board)) possibleMoves.push_back(m2);
  if (isLegalMove(m3, board)) possibleMoves.push_back(m3);
  if (isLegalMove(m4, board)) possibleMoves.push_back(m4);
  if (isLegalMove(m5, board)) possibleMoves.push_back(m5);
  if (isLegalMove(m6, board)) possibleMoves.push_back(m6);
  if (isLegalMove(m7, board)) possibleMoves.push_back(m7);
  if (isLegalMove(m8, board)) possibleMoves.push_back(m8);

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
                      break;
                    }
        case BISHOP: {
                        break;
                     }
        case KNIGHT: {
                       break;
                     }
        case ROOK: {
                     break;
                   }
        case PAWN: {
                     break

                   }
      }
    }
  }

}

