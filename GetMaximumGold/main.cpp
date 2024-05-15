#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int solveMem(vector<vector<int>> &grid, int &row, int &col, int i, int j, int gold,
          vector<vector<int>> &dp) {

  if ((i >= row || j >= col) || (i < 0 || j < 0)) {
    return 0;
  }

  if (grid[i][j] == 0) {
    return 0;
  }
  if (dp[i][j] != 0) {
    return dp[i][j];
  }

  int value = grid[i][j];
  grid[i][j] = 0;

  int down = value + solveMem(grid, row, col, i + 1, j, gold, dp);
  int right = value + solveMem(grid, row, col, i, j + 1, gold, dp);
  int left = value + solveMem(grid, row, col, i, j - 1, gold, dp);
  int up = value + solveMem(grid, row, col, i - 1, j, gold, dp);

  grid[i][j] = value;

  dp[i][j] = max(max(down, right), max(left, up));
  cout << "down right left up :--> " << down << right << left << up
       << " ans :-->> " << dp[i][j] << endl;
  return dp[i][j];
}

int solve(vector<vector<int>> &grid, int &row, int &col, int i, int j, int gold) {

  if ((i >= row || j >= col) || (i < 0 || j < 0)) {
    return 0;
  }

  if (grid[i][j] == 0) {
    return 0;
  }

  int value = grid[i][j];
  grid[i][j] = 0;

  int down = value + solve(grid, row, col, i + 1, j, gold);
  int right = value + solve(grid, row, col, i, j + 1, gold);
  int left = value + solve(grid, row, col, i, j - 1, gold);
  int up = value + solve(grid, row, col, i - 1, j, gold);

  grid[i][j] = value;


  cout << "down right left up :--> " << down << right << left << up
       << " ans :-->> " << max(max(down, right), max(left, up)) << endl;
  return max(max(down, right), max(left, up));;
}

int main() {

  vector<vector<int>> grid{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};

  int row = grid.size();
  int col = grid[0].size();
  int ans = INT_MIN;

  vector<vector<int>> dp(row, vector<int>(col, 0));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] != 0)
        ans = max(ans, solve(grid, row, col, i, j, 0));
    }
  }

  cout << "Ans :--> " << ans << endl;

  return 0;
}