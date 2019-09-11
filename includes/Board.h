#ifndef BOARD
#define BOARD

#include <vector>
#include <cassert>
#include <iostream>

using std::vector;
using std::pair;
using u64 = unsigned long long;

class Board {

  const vector<int> dx = {0, 1, 0, -1};
  const vector<int> dy = {1, 0, -1, 0};

public:

  vector<vector<int>> board; 

  Board();
  Board(vector<vector<int>> other);

  pair<int, int> get_free_tile();
  vector<Board> getNeigbors();
  int getHval(const Board &final);
  u64 get_hash();

  friend std::ostream& operator << (std::ostream& out, const Board& b);
  friend std::istream& operator >> (std::istream& in, Board &b);
  friend bool operator ==(Board b, Board other);
  void operator =(const Board &other) {
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
        board[i][j] = other.board[i][j];
      }
    }
  }
};

Board get_from_hash(u64 hash);

#endif
