#ifndef CHESS_H
#define CHESS_H

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8
#define WHITE 0
#define BLACK 1

#define KING 2
#define QUEEN 3
#define BISHOP 4
#define KNIGHT 5
#define ROOK 6
#define PAWN 7

typedef struct player* player_t;
typedef struct board* board_t;
typedef struct pos* pos_t;
typedef struct board_piece* board_piece_t;
typedef struct move* move_t;

struct player {
  pos_t king;   // king
  pos_t queen;   // queen
  pos_t lbishop, rbishop; // bishop
  pos_t lknight, rknight; // knight
  pos_t lrook, rrook; // rook
  pos_t pawns;  // 8 element array
};

struct board_piece {
  pos_t piece;
  int player;
}

struct board {
  board_piece_t gameBoard;
  int curplayer;
  player_t black;
  player_t white;
  bool gameOver;
};

struct pos {
  int type;
  int x;
  int y;
  bool active;
};

struct move {
  // x cols, y rows
  int x1, y1;
  int x2, y2;
};


/* ai needs in interface
 * getIndex
 * isLegalMove
 */

#endif
