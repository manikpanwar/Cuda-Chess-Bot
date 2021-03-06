#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <limits.h>
#include <pthread.h>
#include <omp.h>
#include "lib/CycleTimer.h"
#include "chess.h"
#include "alphabeta.h"


typedef struct threadStruct* threadStruct_t;

struct threadStruct {
  int curDepth;
  int maxDepth;
  int alpha;
  int beta;
  board_t board;
  int curPlayer;
  minimaxResult_t res;
};

void generatePossibleMovesKing(board_t board, int x, int y,
    std::vector<move_t>* possibleMoves, int curPlayer) {
  // king can move in any direction
  // x == x1, y == y1
  move_t m1, m2, m3, m4, m5, m6, m7, m8;
  m1 = (move_t)malloc(sizeof(struct move));
  m2 = (move_t)malloc(sizeof(struct move));
  m3 = (move_t)malloc(sizeof(struct move));
  m4 = (move_t)malloc(sizeof(struct move));
  m5 = (move_t)malloc(sizeof(struct move));
  m6 = (move_t)malloc(sizeof(struct move));
  m7 = (move_t)malloc(sizeof(struct move));
  m8 = (move_t)malloc(sizeof(struct move));
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

  if (isLegalMove(m1, board, curPlayer)) {
    (*possibleMoves).push_back(m1);
  } else {
    free(m1);
  }
  if (isLegalMove(m2, board, curPlayer)) {
    (*possibleMoves).push_back(m2);
  } else {
    free(m2);
  }
  if (isLegalMove(m3, board, curPlayer)) {
    (*possibleMoves).push_back(m3);
  } else {
    free(m3);
  }
  if (isLegalMove(m4, board, curPlayer)) {
    (*possibleMoves).push_back(m4);
  } else {
    free(m4);
  }
  if (isLegalMove(m5, board, curPlayer)) {
    (*possibleMoves).push_back(m5);
  } else {
    free(m5);
  }
  if (isLegalMove(m6, board, curPlayer)) {
    (*possibleMoves).push_back(m6);
  } else {
    free(m6);
  }
  if (isLegalMove(m7, board, curPlayer)) {
    (*possibleMoves).push_back(m7);
  } else {
    free(m7);
  }
  if (isLegalMove(m8, board, curPlayer)) {
    (*possibleMoves).push_back(m8);
  } else {
    free(m8);
  }
}


void generatePossibleMovesQueen(board_t board, int x, int y,
    std::vector<move_t>* possibleMoves, int curPlayer) {

  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_WIDTH; col++) {
      move_t curMove = (move_t)malloc(sizeof(struct move));
      curMove->x1 = x;
      curMove->y1 = y;
      curMove->x2 = col;
      curMove->y2 = row;
      if (isLegalMove(curMove, board, curPlayer)) {
        (*possibleMoves).push_back(curMove);
      } else {
        free(curMove);
      }
    }
  }

}

void generatePossibleMovesBishop(board_t board, int x, int y,
    std::vector<move_t>* possibleMoves, int curPlayer) {

  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_WIDTH; col++) {
      if (row - col == y - x || (row + col) == x + y) {
        move_t curMove = (move_t)malloc(sizeof(struct move));
        curMove->x1 = x;
        curMove->y1 = y;
        curMove->x2 = col;
        curMove->y2 = row;
        if (isLegalMove(curMove, board, curPlayer)) {
          (*possibleMoves).push_back(curMove);
        } else {
          free(curMove);
        }
      }
    }
  }

}

void generatePossibleMovesKnight(board_t board, int x, int y,
    std::vector<move_t>* possibleMoves, int curPlayer) {
  // x == x1, y == y1
  move_t m1, m2, m3, m4, m5, m6, m7, m8;
  m1 = (move_t)malloc(sizeof(struct move));
  m2 = (move_t)malloc(sizeof(struct move));
  m3 = (move_t)malloc(sizeof(struct move));
  m4 = (move_t)malloc(sizeof(struct move));
  m5 = (move_t)malloc(sizeof(struct move));
  m6 = (move_t)malloc(sizeof(struct move));
  m7 = (move_t)malloc(sizeof(struct move));
  m8 = (move_t)malloc(sizeof(struct move));
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

  if (isLegalMove(m1, board, curPlayer)) {
    // printf("adding knight move\n");
    (*possibleMoves).push_back(m1);
  } else {
    free(m1);
  }
  if (isLegalMove(m2, board, curPlayer)) {
    // printf("adding knight move\n");
    (*possibleMoves).push_back(m2);
  } else {
    free(m2);
  }
  if (isLegalMove(m3, board, curPlayer)) {
    // printf("adding knight move\n");
    (*possibleMoves).push_back(m3);
  } else {
    free(m3);
  }
  if (isLegalMove(m4, board, curPlayer)) {
    // printf("adding knight move\n");
    (*possibleMoves).push_back(m4);
  } else {
    free(m4);
  }
  if (isLegalMove(m5, board, curPlayer)) {
    // printf("adding knight move\n");
    (*possibleMoves).push_back(m5);
  } else {
    free(m5);
  }
  if (isLegalMove(m6, board, curPlayer)) {
    // printf("adding knight move\n");
    (*possibleMoves).push_back(m6);
  } else {
    free(m6);
  }
  if (isLegalMove(m7, board, curPlayer)) {
    // printf("adding knight move\n");
    (*possibleMoves).push_back(m7);
  } else {
    free(m7);
  }
  if (isLegalMove(m8, board, curPlayer)) {
    // printf("adding knight move\n");
    (*possibleMoves).push_back(m8);
  } else {
    free(m8);
  }

}

void generatePossibleMovesRook(board_t board, int x, int y,
    std::vector<move_t>* possibleMoves, int curPlayer) {
  // printf("Finding for rook at col = %d row = %d\n", x, y);
  for (int row = 0; row < BOARD_HEIGHT; row++) {
    int col = x;  // col stays the same TODO: confirm
    move_t curMove = (move_t)malloc(sizeof(struct move));
    curMove->x1 = x;
    curMove->y1 = y;
    curMove->x2 = col;
    curMove->y2 = row;
    if (isLegalMove(curMove, board, curPlayer)) {
      // printf("Adding to rook \n");
      (*possibleMoves).push_back(curMove);
    } else {
      free(curMove);
    }
  }
  for (int col = 0; col < BOARD_WIDTH; col++) {
    int row = y;  // row stays the same TODO: confirm
    move_t curMove = (move_t)malloc(sizeof(struct move));
    curMove->x1 = x;
    curMove->y1 = y;
    curMove->x2 = col;
    curMove->y2 = row;
    if (isLegalMove(curMove, board, curPlayer)) {
      (*possibleMoves).push_back(curMove);
    } else {
      free(curMove);
    }
  }
}

void generatePossibleMovesPawn(board_t board, int x, int y,
    std::vector<move_t>* possibleMoves, int curPlayer) {
  int mf = (curPlayer == WHITE) ? 1 : -1;  // multFactor
  move_t m1, m2, m3, m4;
  m1 = (move_t)malloc(sizeof(struct move));
  m2 = (move_t)malloc(sizeof(struct move));
  m3 = (move_t)malloc(sizeof(struct move));
  m4 = (move_t)malloc(sizeof(struct move));

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

  if (isLegalMove(m1, board, curPlayer)) {
    (*possibleMoves).push_back(m1);
  } else {
    free(m1);
  }
  if (isLegalMove(m2, board, curPlayer)) {
    (*possibleMoves).push_back(m2);
  } else {
    free(m2);
  }
  if (isLegalMove(m3, board, curPlayer)) {
    (*possibleMoves).push_back(m3);
  } else {
    free(m3);
  }
  if (isLegalMove(m4, board, curPlayer)) {
    (*possibleMoves).push_back(m4);
  } else {
    free(m4);
  }
}

std::vector<move_t> generatePossibleMoves(board_t board, int curPlayer) {
  // given current state of board, generate all possible moves
  std::vector<move_t> possibleMoves;

  if (gameOver(board) != -1) {
    return possibleMoves;
  }

  for (int row = 0; row < BOARD_HEIGHT; row++) {
    for (int col = 0; col < BOARD_WIDTH; col++) {
      pos_t piece = (board->gameBoard[getIndex(col, row)]).piece;
      int playerForPiece = (board->gameBoard[getIndex(col, row)]).player;

      // int curPlayer = board->curPlayer;
      if (piece == NULL || (playerForPiece != curPlayer)) {
        // nothing at this position on the board
        // printf("NULL curPlayer  = %d playerForPiece = %d row = %d col = %d\n", curPlayer, playerForPiece, row, col);
        // or current position is for a player who doesn't have a turn right now
        continue;
      }
      // printf("curPlayer  = %d row = %d col = %d type = %d\n", curPlayer, row, col, piece->type);

      int x = col;
      int y = row;

      switch (piece->type) {
        case KING: {
                     generatePossibleMovesKing(board, x, y, &possibleMoves, curPlayer);
                     break;
                   }
        case QUEEN: {
                      generatePossibleMovesQueen(board, x, y, &possibleMoves, curPlayer);
                      break;
                    }
        case BISHOP: {
                       generatePossibleMovesBishop(board, x, y, &possibleMoves, curPlayer);
                       break;
                     }
        case KNIGHT: {
                       generatePossibleMovesKnight(board, x, y, &possibleMoves, curPlayer);
                       break;
                     }
        case ROOK: {
                     generatePossibleMovesRook(board, x, y, &possibleMoves, curPlayer);
                     break;
                   }
        case PAWN: {
                     generatePossibleMovesPawn(board, x, y,
                         &possibleMoves, curPlayer);
                     break;
                   }
      }
    }
  }
  // printf("Done making moves: Made %zu moves\n", possibleMoves.size());
  return possibleMoves;

}


// heuristic taken from https://chessprogramming.wikispaces.com/Evaluation
int score(board_t board, int curPlayer, int mobility, int mobilityOther) {
  // Minimax usually associates the white side with the max-player and black
  // with the min-player and always evaluates from the white point of view

  player_t white = board->white;
  player_t black = board->black;

  // king
  int wka = white->king->active ? 1 : 0;
  int bka = black->king->active ? 1 : 0;
  int result = 2000 * (wka - bka);

  // queen
  int wqa = white->queen->active ? 1 : 0;
  int bqa = black->queen->active ? 1 : 0;
  result += 9 * (wqa - bqa);

  // rooks
  int wra = ((int)white->lrook->active ? 1 : 0) + ((int)white->rrook->active ? 1 : 0);
  int bra = ((int)black->lrook->active ? 1 : 0) + ((int)black->rrook->active ? 1 : 0);
  result += 5 * (wra - bra);


  // bishops and knights
  int wbka = ((int)white->lbishop->active ? 1 : 0) + ((int)white->rbishop->active ? 1 : 0);
  wbka = ((int)white->lknight->active ? 1 : 0) + ((int)white->rknight->active ? 1 : 0);

  int bbka = ((int)black->lbishop->active ? 1 : 0) + ((int)black->rbishop->active ? 1 : 0);
  bbka = ((int)black->lknight->active ? 1 : 0) + ((int)black->rknight->active ? 1 : 0);
  result += 3 * (wbka - bbka);

  // pawns
  int wpawns = 0;
  int bpawns = 0;
  for (int i = 0; i < BOARD_WIDTH; i++) {
    if ((white->pawns[i]).active) wpawns += 1;
    if ((black->pawns[i]).active) bpawns += 1;
  }
  result += 1 * (wpawns - bpawns);

  result += .1 * (mobility - mobilityOther);

  return result;
}

int flipPlayer(int player) {
  return player == WHITE ? BLACK : WHITE;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int min(int a, int b) {
  return a > b ? b : a;
}

void deepFreeBoard (board_t B) {
  B->gameBoard = (board_piece_t)calloc(BOARD_WIDTH * BOARD_HEIGHT, sizeof(struct board_piece));
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      //printf("aewfadsfadsfasdf\n");
      int index = getIndex(i, j);
      free(B->gameBoard[index].piece);
    }
  }
  free(B->gameBoard);


  free(B->black->king);
  free(B->black->queen);
  free(B->black->lbishop);
  free(B->black->rbishop);
  free(B->black->lknight);
  free(B->black->rknight);
  free(B->black->lrook);
  free(B->black->rrook);
  free(B->black->pawns);
  free(B->black);

  free(B->white->king);
  free(B->white->queen);
  free(B->white->lbishop);
  free(B->white->rbishop);
  free(B->white->lknight);
  free(B->white->rknight);
  free(B->white->lrook);
  free(B->white->rrook);
  free(B->white->pawns);
  free(B->white);

  free(B);
}

board_t deepCopyBoard (board_t B) {
  double st, et;
  st = CycleTimer::currentSeconds();
  board_t ret = (board_t)malloc(sizeof(struct board));
  ret->gameBoard = (board_piece_t)calloc(BOARD_WIDTH * BOARD_HEIGHT, sizeof(struct board_piece));
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      int index = getIndex(i, j);
      ret->gameBoard[index].piece = (pos_t)malloc(sizeof(struct pos));
      if (B->gameBoard[index].piece) {
        *(ret->gameBoard[index].piece) = *(B->gameBoard[index].piece); //check that this works as i would expect
      } else ret->gameBoard[index].piece = NULL;
      ret->gameBoard[index].player = B->gameBoard[index].player;
    }
  }

  ret->curPlayer = B->curPlayer;
  ret->black = (player_t)malloc(sizeof(struct player));
  ret->black->king = (pos_t)malloc(sizeof(struct pos));
  ret->black->queen = (pos_t)malloc(sizeof(struct pos));
  ret->black->lbishop = (pos_t)malloc(sizeof(struct pos));
  ret->black->rbishop = (pos_t)malloc(sizeof(struct pos));
  ret->black->lknight = (pos_t)malloc(sizeof(struct pos));
  ret->black->rknight = (pos_t)malloc(sizeof(struct pos));
  ret->black->lrook = (pos_t)malloc(sizeof(struct pos));
  ret->black->rrook = (pos_t)malloc(sizeof(struct pos));
  ret->black->pawns = (pos_t)malloc(BOARD_WIDTH * sizeof(struct pos));
  *(ret->black->king) = *(B->black->king);
  *(ret->black->queen) = *(B->black->queen);
  *(ret->black->lbishop) = *(B->black->lbishop);
  *(ret->black->rbishop) = *(B->black->rbishop);
  *(ret->black->lknight) = *(B->black->lknight);
  *(ret->black->rknight) = *(B->black->rknight);
  *(ret->black->lrook) = *(B->black->lrook);
  *(ret->black->rrook) = *(B->black->rrook);
  for (int i = 0; i < BOARD_WIDTH; i++) {
    (ret->black->pawns[i]) = (B->black->pawns[i]);
  }
  ret->white = (player_t)malloc(sizeof(struct player));
  ret->white->king = (pos_t)malloc(sizeof(struct pos));
  ret->white->queen = (pos_t)malloc(sizeof(struct pos));
  ret->white->lbishop = (pos_t)malloc(sizeof(struct pos));
  ret->white->rbishop = (pos_t)malloc(sizeof(struct pos));
  ret->white->lknight = (pos_t)malloc(sizeof(struct pos));
  ret->white->rknight = (pos_t)malloc(sizeof(struct pos));
  ret->white->lrook = (pos_t)malloc(sizeof(struct pos));
  ret->white->rrook = (pos_t)malloc(sizeof(struct pos));
  ret->white->pawns = (pos_t)malloc(BOARD_WIDTH * sizeof(struct pos));
  *(ret->white->king) = *(B->white->king);
  *(ret->white->queen) = *(B->white->queen);
  *(ret->white->lbishop) = *(B->white->lbishop);
  *(ret->white->rbishop) = *(B->white->rbishop);
  *(ret->white->lknight) = *(B->white->lknight);
  *(ret->white->rknight) = *(B->white->rknight);
  *(ret->white->lrook) = *(B->white->lrook);
  *(ret->white->rrook) = *(B->white->rrook);
  for (int i = 0; i < BOARD_WIDTH; i++) {
    (ret->white->pawns[i]) = (B->white->pawns[i]);
  }
  ret->gameOver = B->gameOver;
  et = CycleTimer::currentSeconds();
  // printf("Deep Copy took %.3f (ms)\n", (et-st) * 1000.f);
  return ret;
}


minimaxResult_t alphabetaSearch(int curDepth, int maxDepth, int alpha, int beta,
 board_t board, int curPlayer) {

  // ENSURES: board struct remains the same as it was passed in when the function completes
  double st, et;
  st = CycleTimer::currentSeconds();
  if (curDepth == maxDepth|| gameOver(board) != -1) {
    int curScore = score(board, curPlayer, 0, 0);
    minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
    res->bestRes = curScore;
    res->move = NULL;
    return res;
  }

  std::vector<move_t> possibleMoves = generatePossibleMoves(board, curPlayer);
  if (curDepth == 0) {
    std::random_shuffle(possibleMoves.begin(), possibleMoves.end());
  }

  move_t bestMove = NULL;


  for (std::vector<move_t>::iterator it = possibleMoves.begin(); it != possibleMoves.end(); it++) {

    move_t curMove = *it;
    int x1 = curMove->x1;
    int y1 = curMove->y1;
    board_piece startPiece = board->gameBoard[getIndex(x1, y1)];
    int x2 = curMove->x2;
    int y2 = curMove->y2;
    board_piece endPiece = board->gameBoard[getIndex(x2, y2)];

    // we know curMove is valid

    applyMove(curMove, board, curPlayer);
    // applying move modifies the board

    minimaxResult_t curRes = alphabetaSearch(curDepth + 1, maxDepth, -beta, -alpha, board,
      flipPlayer(curPlayer));
    int resS = -(curRes->bestRes);

    // now undo this move
    undoMove(x1, y1, startPiece, x2, y2, endPiece, board, curPlayer);

    if (beta <= resS) {
      free(curRes);
      minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
      res->bestRes = beta;  // returning alpha bc thats the max value (maxing in maxi and - in upper level is equiv to min'ing in mini)
      res->move = bestMove;
      return res;
    }
    if (alpha < resS) {
      bestMove = curMove;
      alpha = resS;
    }
    free(curRes);
  }
  minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
  res->bestRes = alpha;
  res->move = bestMove;
  et = CycleTimer::currentSeconds();
  // if (!curDepth)
  //   printf("Thread took time %.3f (ms) with curDepth = %d\n",
  //     (et - st) * 1000.f, curDepth);
  return res;
}


minimaxResult_t PVSplit(int curDepth, int maxDepth, int alpha, int beta,
  board_t board, int curPlayer) {

  if (maxDepth == curDepth || gameOver(board) != -1) {
    int curScore = score(board, curPlayer, 0, 0);
    minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
    res->bestRes = curScore;
    res->move = NULL;
    return res;
  }

  std::vector<move_t> possibleMoves = generatePossibleMoves(board, curPlayer);

  if (curDepth == 0) {
    std::random_shuffle(possibleMoves.begin(), possibleMoves.end());
  }

  move_t bestMove = NULL;

  move_t firstMove = possibleMoves.at(0);
  int x1 = firstMove->x1;
  int y1 = firstMove->y1;
  board_piece startPiece = board->gameBoard[getIndex(x1, y1)];
  int x2 = firstMove->x2;
  int y2 = firstMove->y2;
  board_piece endPiece = board->gameBoard[getIndex(x2, y2)];

  // we know firstMove is valid

  applyMove(firstMove, board, curPlayer);
  // applying move modifies the board

  minimaxResult_t firstRes = PVSplit(curDepth + 1, maxDepth, -beta, -alpha, board, flipPlayer(curPlayer));
  firstRes->bestRes = -(firstRes->bestRes);
  int resS = firstRes->bestRes;

  // now undo this move
  undoMove(x1, y1, startPiece, x2, y2, endPiece, board, curPlayer);
  if (resS > beta) {
    free(firstRes);
    minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
    res->bestRes = beta;
    res->move = bestMove;
    return res;
  }
  if (alpha < resS) {
    bestMove = firstMove;
    alpha = resS;
  }

  pthread_t threads[int(possibleMoves.size()) - 1];

  int threadStatus;
  if (int(possibleMoves.size()) > 1)  {
    volatile bool flag = false;
    int i;
    #pragma omp parallel for default(shared) shared(flag, alpha, bestMove) private(i) schedule(dynamic)
    for (i = 1; i < possibleMoves.size(); i++) {

      if (flag) {
        continue;
      }
      else {
        move_t curMove = possibleMoves.at(i);
        int x1 = curMove->x1;
        int y1 = curMove->y1;
        board_piece startPiece = board->gameBoard[getIndex(x1, y1)];
        int x2 = curMove->x2;
        int y2 = curMove->y2;
        board_piece endPiece = board->gameBoard[getIndex(x2, y2)];

        board_t boardCopy = deepCopyBoard(board);
        // we know curMove is valid
        applyMove(curMove, boardCopy, curPlayer);
        minimaxResult_t curRes = alphabetaSearch(curDepth + 1, maxDepth, -beta, -alpha, boardCopy, flipPlayer(curPlayer));
        curRes->bestRes = -(curRes->bestRes);
        int iresS = curRes->bestRes;
        deepFreeBoard(boardCopy);


        if (iresS > beta) {
          free(curRes);
          minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
          res->bestRes = beta;
          res->move = bestMove;
          flag = true;
        }
        #pragma omp critical
          if (alpha < iresS) {
            bestMove = curMove;
            alpha = iresS;
          }
        }
    }
  }
  minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
  res->bestRes = alpha;
  res->move = bestMove;
  return res;
}

move_t nextMove(board_t board, int aiType, int curPlayer) {
  std::srand ( unsigned ( std::time(0) ) );
  // AI is called to help les goooooo!!!
  minimaxResult_t res;
  res = PVSplit(0, MAXDEPTH, NEGINF, POSINF, board, curPlayer);
  move_t move = res->move;
  free(res);
  return move;
}
