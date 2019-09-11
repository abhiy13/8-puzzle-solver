#ifndef SOLVER
#define SOLVER

#include <vector>
#include <queue>
#include <set>
#include <map>

using std::vector;
using std::queue;
using std::set;
using std::map;
using std::priority_queue;
#include "Board.h"

vector<Board> solve(Board initial, Board goal);
bool dfs(Board initial, Board final);
vector<Board> bfs(Board initial, Board final);
vector<Board> Astar(Board initial, Board final);

#endif
