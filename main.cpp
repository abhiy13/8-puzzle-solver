#include "./includes/Board.h"
#include "./includes/Solver.h"
#include <iostream>

using std::cin;
using std::cout;

const vector<vector<int>> default_final = {
  vector<int>{1, 2, 3},
  vector<int>{4, 5, 6},
  vector<int>{7, 8, 0}
};

const vector<vector<int>> default_start = {
  vector<int>{1, 2, 3},
  vector<int>{4, 6, 0},
  vector<int>{7, 5, 8}
};

void get_input(Board &initial, Board &final) {
  cout << "Enter initial state\n";
  cin >> initial;
  cout << "Enter Goal State\n";
  cin >> final;
}

int main() {

  Board initial(default_start);
  Board goal(default_final);

  get_input(initial, goal);

  vector<Board> solutionf = solve(initial, goal);
  if(solutionf.empty()) {
    cout << "Unable to find a Solution" << std::endl;
  } else {
    int sz = (int) solutionf.size();
    for(int i = sz - 1; i >= 0; --i) {
      cout << solutionf[i];
      if(i != 0) cout << "\nNext state:\n";
    }
    cout << std::endl;
  }
  return 0;
}
