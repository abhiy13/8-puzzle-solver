#include "./includes/Board.h"

Board::Board() {
  board.resize(3, vector<int>(3));
}

Board::Board(vector<vector<int>> other) {
  assert(other.size() == (size_t) 3);
  assert(other[0].size() == (size_t) 3);
  board = other;
}

pair<int, int> Board::get_free_tile() {
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      if(board[i][j] == 0) {
        return pair<int, int>(i, j);
      }
    }
  }
  return pair<int, int>{-1, -1};
}

int Board::getHval(const Board& final) {
  int h = 0;
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      if(board[i][j] != final.board[i][j]) h++;
    }
  }
  return h;
}

vector<Board> Board::getNeigbors() {
  pair<int, int> free = get_free_tile();
  assert(free.first != -1);
  vector<Board> neighbors;
  for(int iter = 0; iter < 4; ++iter) {
    int x = free.first + dx[iter], y = free.second + dy[iter];
    if(x < 0 || x >= 3 || y < 0 || y >= 3) {
      continue;
    }
    std::swap(board[x][y], board[free.first][free.second]);
    neighbors.push_back(Board(board));
    std::swap(board[x][y], board[free.first][free.second]);
  }
  return neighbors;
} 

bool operator== (Board b, Board other) {
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      if(b.board[i][j] != other.board[i][j]) {
        return false;
      }
    }
  }
  return true;
}

u64 Board::get_hash() {
  u64 hash = 0;
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      hash = hash * 10 + board[i][j];
    }
  }
  return hash;
}

Board get_from_hash(u64 hash) {
  vector<vector<int>> b(3, vector<int>(3, 0));
  for(int i = 2; i >= 0; --i) {
    for(int j = 2; j >= 0; --j) {
      b[i][j] = hash % 10;
      hash /= 10;
    }
  }
  return Board(b);
}

std::ostream& operator << (std::ostream& out, const Board& b) {
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 7; ++j) {
      out << "- ";
    }
    out << std::endl;
    out << "| ";  
    for(int j = 0; j < 3; ++j) {
      out << b.board[i][j] << " | ";
    }
    out << std::endl;
  }
  for(int j = 0; j < 7; ++j) {
    out << "- ";
  }
  return out;
}

std::istream& operator >> (std::istream& in, Board &b) {
  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      in >> b.board[i][j];
    }
  }
  return in;
}
