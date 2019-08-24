#include "./includes/Solver.h"

vector<Board> visited;
vector<Board> solution;
const int INF = (int) 1e7;

bool dfs(Board current, Board final) {
  if(current == final) {
    solution.emplace_back(current);
    return true;
  }  
  for(Board old: visited) {
    if(old == current) {
      return false;
    }
  }
  visited.push_back(current);
  auto next = current.getNeigbors();
  for(Board n: next) {
    if(dfs(n, final)) {
      solution.push_back(n);
      return true;
    }
  }
  return false;
}

vector<Board> solve(Board initial, Board final) {
  visited.clear();
  solution.clear();
  solution.push_back(initial);
  dfs(initial, final);
  return solution;
}
