#ifndef SOLVER
#define SOLVER
#include <vector>
#include <queue>
using std::vector;
using std::queue;
#include "Board.h"

vector<Board> solve(Board initial, Board goal);
bool dfs(Board initial, Board final);
vector<Board> bfs(Board initial, Board final);

#endif
