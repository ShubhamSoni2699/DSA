#include <bits/stdc++.h>
using namespace std;

void print2DVector (vector<vector<int>>&grid ,int ans){
	for(int i = 0 ; i<grid.size() ; i++ ){
		cout<<"   [";
		for(int j = 0 ; j<grid[0].size(); j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<"]"<<endl;
	}
	cout<<"ans :--> "<<ans<<endl<<endl;
}

int binaryToDecimal(vector<vector<int>> &grid) {
  int ans = 0;
  for (int row = 0; row < grid.size(); row++) {
    int rowSum = 0;
    int i = 0;
    for (int col = grid[0].size() - 1; col >= 0; col--) {
      rowSum += pow(2, i++) * grid[row][col];
    }
    ans += rowSum;
  }
  return ans;
}

void flipCol(int col, vector<vector<int> >& grid)
{
    for (int j = 0; j < grid.size(); j++) {
        grid[j][col] ^= 1;
    }
}

void flipRow(int row, vector<vector<int> >& grid)
{
    for (int i = 0; i < grid[0].size(); i++) {
        grid[row][i] ^= 1;
    }
}

//This algo from geeksforgeeks :- https://www.geeksforgeeks.org/maximize-score-of-binary-matrix-by-flipping-a-row-or-column-each-time/
int solve(vector<vector<int>> &grid) {
  int n = grid.size();
    int m = grid[0].size();
    // MSB should be 1 of 0th column
    // to get the maximum value
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 0) {
            flipRow(i, grid);
        }
    }
    // cheacking which column has more 0's than 1's
    // and toggling them.
    for (int j = 0; j < m; j++) {
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 0)
                zeros++;
        }
        if (zeros > (n - zeros)) {
            flipCol(j, grid);
        }
    }
    // Calculate the answer
    int sum = binaryToDecimal(grid);
    return sum;
}

int main(){
	vector<vector<int>> grid {{0,1},{1,1},{0,0},{0,1},{1,1}};
	int ans = solve(grid);
	cout<<"ans :--> "<<ans;
	cout<<endl;
	return 0;
}