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

vector<Board> bfs(Board initial, Board final) {
  queue<pair<Board, vector<Board>>> q;
  q.emplace(initial, vector<Board>({initial}));
  while(!q.empty()) {
    auto curr = q.front();
    q.pop();
    if(curr.first == final) return curr.second;
    for(Board n: curr.first.getNeigbors()) {
      bool ok = false;
      for(Board old: visited) {
        if(old == n) {
          ok = true;
          break;
        }
      }
      if(ok) continue;
      curr.second.push_back(n);
      q.emplace(n, curr.second);
      curr.second.pop_back();
    }
  }
  return vector<Board>();
}

template<typename T>
using minpq = priority_queue<T, vector<T>, std::greater<T>>;

vector<Board> Astar(Board initial, Board final) {
  vector<Board> ans;
  minpq<pair<int, u64>> Q;
  Q.push({initial.getHval(final), initial.get_hash()}); 
  map<u64, u64> par;
  par[initial.get_hash()] = initial.get_hash();
  set<u64> visited;
  while(!Q.empty()) {
    auto t = Q.top();
    Q.pop();
    Board b = get_from_hash(t.second);
    std::cout << b << '\n';
    if(b == final) {
      break;
    }
    u64 par_hash = b.get_hash();
    visited.insert(par_hash);
    for(Board x: b.getNeigbors()) {
      u64 my_hash = x.get_hash();
      if(visited.count(my_hash)) continue;
      par[my_hash] = par_hash;
      Q.push({x.getHval(final), x.get_hash()});
    }
  }
  vector<Board> path;
  u64 curr = final.get_hash();
  while(par[curr] != curr) {
    path.push_back(get_from_hash(curr));
    curr = par[curr];
  }
  return path;
}

vector<Board> solve(Board initial, Board final) {
//  visited.clear();
//  solution.clear();
//  solution.push_back(initial);
//  dfs(initial, final);
// return bfs(initial, final);
  return Astar(initial, final);
}
