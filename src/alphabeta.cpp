#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <limits.h>
#include "chess.h"
#include "alphabeta.h"


minimaxResult_t mini(int curDepth, int maxDepth,
                    int alpha, int beta, board_t board, int curPlayer,
                    std::vector<movesListElem_t> v);

minimaxResult_t maxi(int curDepth, int maxDepth,
                    int alpha, int beta, board_t board, int curPlayer,
                    std::vector<movesListElem_t> v);


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

  // if (curPlayer == BLACK) {
  //   player_t temp = white;
  //   white = black;
  //   black = temp;
  // }

  // NOW WHITE POINTS TO CURPLAYER

  // king
  int wka = white->king->active ? 1 : 0;
  // if (!wka) printf("So the king is not active...");
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
  // if (!wka) printf("and the score is %d\n", result);

  return -result;
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

void printMove(move_t m) {
  printf("col1: %d row1: %d col2: %d row2: %d\n", m->x1, m->y1, m->x2, m->y2);
}

int calcScore(board_t board, int curPlayer, std::vector<movesListElem_t> movesList) {
  for (std::vector<movesListElem_t>::iterator it = movesList.begin(); it != movesList.end(); it++)
  {
    movesListElem_t me = *it;
    // printf("player = %d movingpiecetype = %d",me->player, (board->gameBoard[getIndex(me->m->x1, me->m->y1)].piece->type));
    // printMove(me->m);
    me->startPiece = board->gameBoard[getIndex(me->m->x1, me->m->y1)];
    me->endPiece = board->gameBoard[getIndex(me->m->x2, me->m->y2)];
    applyMove(me->m, board, me->player);
    // if (!board->white->king->active) {
    //   blah = true;
    //   printf("after this one\n");
    // }
  }
  std::vector<move_t> possibleMoves = generatePossibleMoves(board, curPlayer);
  std::vector<move_t> possibleMovesOther = generatePossibleMoves(board, flipPlayer(curPlayer));
  int curScore = score(board, curPlayer, int(possibleMoves.size()), int(possibleMovesOther.size()));
  for (std::vector<movesListElem_t>::reverse_iterator it = movesList.rbegin(); it != movesList.rend(); it++)
  {
    movesListElem_t me = *it;
    // printf("player = %d ",me->player);
    // printMove(me->m);
    move_t m = me->m;
    int x1 = m->x1;
    int y1 = m->y1;
    int x2 = m->x2;
    int y2 = m->y2;
    board_piece startPiece = me->startPiece;
    board_piece endPiece = me->endPiece;
    undoMove(x1, y1, startPiece, x2, y2, endPiece, board, me->player);
    // if (endPiece.piece) {
    //   printf("type = %d col = %d, row = %d \n", endPiece.piece->type, endPiece.piece->x, endPiece.piece->y);
    // }
    // if (blah && board->white->king->active) {
    //   printf("AOK\n");
    // }
    // undoMove(board, m);
  }

  return curScore;
}

void freeElems(std::vector<movesListElem_t> movesList) {
  printf("in free elems\n");
  for (std::vector<movesListElem_t>::reverse_iterator it = movesList.rend(); 
    it != movesList.rbegin(); it++) {
    free((*it));
    break;
  }
  printf("freed elems\n");
}

minimaxResult_t maxi(int curDepth, int maxDepth, int alpha, int beta,
 board_t board, int curPlayer, std::vector<movesListElem_t> movesList) {
  // ENSURES: board struct remains the same as it was passed in when the function completes

  // printf("In maxi depth = %d\n", curDepth);
  if (maxDepth == curDepth || gameOver(board) != -1) {
    int curScore = calcScore(board, curPlayer, movesList);
    // int curScore = 42;
    minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
    res->bestRes = curScore;
    res->move = NULL;
    return res;
  }

  for (std::vector<movesListElem_t>::iterator it = movesList.begin(); it != movesList.end(); it++)
  {
    movesListElem_t me = *it;
    me->startPiece = board->gameBoard[getIndex(me->m->x1, me->m->y1)];
    me->endPiece = board->gameBoard[getIndex(me->m->x2, me->m->y2)];
    applyMove(me->m, board, me->player);
  }
  std::vector<move_t> possibleMoves = generatePossibleMoves(board, curPlayer);
  for (std::vector<movesListElem_t>::reverse_iterator it = movesList.rbegin(); it != movesList.rend(); it++)
  {
    movesListElem_t me = *it;
    move_t m = me->m;
    int x1 = m->x1;
    int y1 = m->y1;
    int x2 = m->x2;
    int y2 = m->y2;
    board_piece startPiece = me->startPiece;
    board_piece endPiece = me->endPiece;
    undoMove(x1, y1, startPiece, x2, y2, endPiece, board, me->player);
  }
  // printf("Made possible moves: Size = %d\n", int(possibleMoves.size()));

  // printf("Got possible moves. Len = %d\n", int(possibleMoves.size()));
  if (curDepth == 0) {
    std::random_shuffle(possibleMoves.begin(), possibleMoves.end());
  }

  move_t bestMove = NULL;
  int resS = NEGINF;


  for (std::vector<move_t>::iterator it = possibleMoves.begin(); it != possibleMoves.end(); it++) {

    move_t curMove = *it;
    int x1 = curMove->x1;
    int y1 = curMove->y1;
    board_piece startPiece = board->gameBoard[getIndex(x1, y1)];
    int x2 = curMove->x2;
    int y2 = curMove->y2;
    board_piece endPiece = board->gameBoard[getIndex(x2, y2)];

    // we know curMove is valid
    std::vector<movesListElem_t> curMovesList = movesList;  // hoping this is deep copy lmao
    movesListElem_t mle = (movesListElem_t)malloc(sizeof(struct movesListElem));
    mle->m = curMove;
    mle->startPiece = startPiece;
    mle->endPiece = endPiece;
    mle->player = curPlayer;
    curMovesList.push_back(mle);
    // applying move modifies the board

    minimaxResult_t curRes = mini(curDepth + 1, maxDepth, alpha, beta, board, 
      flipPlayer(curPlayer), curMovesList);
    resS = max(resS, curRes->bestRes);

    // now undo this move
    if (alpha <= curRes->bestRes && curRes->bestRes <= beta) {
      bestMove = curMove;
    }
    alpha = max(alpha, resS);

    if (beta <= alpha) {
      free(curRes);
      // freeElems(movesList);
      minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
      res->bestRes = alpha;  // TODO: Check value returned here
      res->move = bestMove;
      return res;
    }
    free(curRes);
  }
  // printf("returning from maxi\n");
  // freeElems(movesList);
  minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
  res->bestRes = resS;
  res->move = bestMove;
  return res;
}




minimaxResult_t mini(int curDepth, int maxDepth, int alpha, int beta, 
  board_t board, int curPlayer, std::vector<movesListElem_t> movesList) {
  // ENSURES: board struct remains the same as it was passed in when the function completes
  // printf("In mini depth = %d\n", curDepth);

  if (maxDepth == curDepth || gameOver(board) != -1) {
    int curScore = calcScore(board, curPlayer, movesList);
    // int curScore = 42;
    minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
    res->bestRes = curScore;
    res->move = NULL;
    return res;
  }

  for (std::vector<movesListElem_t>::iterator it = movesList.begin(); it != movesList.end(); it++)
  {
    movesListElem_t me = *it;
    me->startPiece = board->gameBoard[getIndex(me->m->x1, me->m->y1)];
    me->endPiece = board->gameBoard[getIndex(me->m->x2, me->m->y2)];
    applyMove(me->m, board, me->player);
  }
  std::vector<move_t> possibleMoves = generatePossibleMoves(board, curPlayer);
  for (std::vector<movesListElem_t>::reverse_iterator it = movesList.rbegin(); it != movesList.rend(); it++)
  {
    movesListElem_t me = *it;
    move_t m = me->m;
    int x1 = m->x1;
    int y1 = m->y1;
    int x2 = m->x2;
    int y2 = m->y2;
    board_piece startPiece = me->startPiece;
    board_piece endPiece = me->endPiece;
    undoMove(x1, y1, startPiece, x2, y2, endPiece, board, me->player);
  }

  if (curDepth == 0) {
    std::random_shuffle(possibleMoves.begin(), possibleMoves.end());
  }

  // printf("Mini Got possible moves. Len = %d\n", int(possibleMoves.size()));

  move_t bestMove = NULL;
  int resS = POSINF;
  for (std::vector<move_t>::iterator it = possibleMoves.begin(); it != possibleMoves.end(); it++) {
    move_t curMove = *it;
    int x1 = curMove->x1;
    int y1 = curMove->y1;
    board_piece startPiece = board->gameBoard[getIndex(x1, y1)];
    int x2 = curMove->x2;
    int y2 = curMove->y2;
    board_piece endPiece = board->gameBoard[getIndex(x2, y2)];

    std::vector<movesListElem_t> curMovesList = movesList;  // hoping this is deep copy lmao
    movesListElem_t mle = (movesListElem_t)malloc(sizeof(struct movesListElem));
    mle->m = curMove;
    mle->player = curPlayer;
    mle->startPiece = startPiece;
    mle->endPiece = endPiece;
    curMovesList.push_back(mle);

    // we know curMove is valid
    // applyMove(curMove, board, curPlayer);
    // applying move modifies the board

    minimaxResult_t curRes = maxi(curDepth + 1, maxDepth, alpha, beta,
     board, flipPlayer(curPlayer), curMovesList);
    resS = min(resS, curRes->bestRes);

    // now undo this move
    // undoMove(x1, y1, startPiece, x2, y2, endPiece, board, curPlayer);

    if (curRes->bestRes <= beta) {
      bestMove = curMove;
    }
    beta = min(resS, beta);
    // calculate new intervals | prune if applicable

    if (beta <= alpha) {
      // BELOW
      // maxi can already get alpha so no way it would get mini in a position to get a newAlpha
      // less than current alpha so prune
      free(curRes);
      // freeElems(movesList);
      minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
      res->bestRes = beta;  // TODO: Check value returned here
      res->move = bestMove;
      return res;
    }
    free(curRes);
  }
  // printf("returning from mini\n");
  // freeElems(movesList);
  minimaxResult_t res = (minimaxResult_t)malloc(sizeof(struct minimaxResult));
  res->bestRes = resS;
  res->move = bestMove;
  return res;
}

move_t nextMove(board_t board, int aiType, int curPlayer) {
  std::srand ( unsigned ( std::time(0) ) );
  // AI is called to help les goooooo!!!
  printf("In next move\n");
  minimaxResult_t res;
  std::vector<movesListElem_t> movesList;
  if (aiType == MAXI) {
    res = maxi(0, MAXDEPTH, NEGINF, POSINF, board, curPlayer, movesList);
  } else {
    res = mini(0, MAXDEPTH, NEGINF, POSINF, board, curPlayer, movesList);
  }
  move_t move = res->move;
  free(res);
  return move;
}
