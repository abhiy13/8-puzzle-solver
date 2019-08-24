#ifndef SOLVER
#define SOLVER
#include <vector>
using std::vector;
#include "Board.h"

vector<Board> solve(Board initial, Board goal);
bool dfs(Board initial, Board final);

#endif