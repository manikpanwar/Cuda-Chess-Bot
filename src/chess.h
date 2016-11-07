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


struct player {
  pos_t king;   // king
  pos_t queen;   // queen
  pos_t lbishop, rbishop; // bishop
  pos_t lknight, rknight;
  pos_t lrook, rrook;
  pos_t* pawns;  // 8 element array
};

struct board {
  int curplayer;
  player_t black;
  player_t white;
};

struct pos {
  int x;
  int y;
  bool active;
};


#endif
