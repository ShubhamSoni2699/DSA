#include <vector>
#include <iostream>
using namespace std;


class nQueen{
	public:
		void printAllPossibleSol(int n){
			vector<vector<int>> sol = solveNQueen(n);
			int rowSize = sol.size();
			for(int i = 0; i<rowSize ;i++){
				int colSize = sol[i].size();
				for(int j = 0 ; j<colSize ; j++){
					cout<<sol[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
	private:
		vector<vector<int>> solveNQueen(int size){
			vector<vector<int>>board (size, vector<int>(size,0));
			vector<vector<int>>ans;
			solve(0,ans,board,size);
			return ans;
		}
		void solve(int col , vector<vector<int>>& ans , vector<vector<int>>&board , int size){
			if(col == size){
				addToSol(ans,board,size);
				return;
			}
			for(int row = 0 ; row<size ; row++){
				if( isSafe(row,col,board,size)){
					board[row][col] = 1;
					solve(col+1 , ans,board,size);
					board[row][col] = 0;
				}
			}
		}
		
		void addToSol( vector<vector<int>> &ans ,vector<vector<int>> &board ,int size){
			vector<int>temp;
			for(int i = 0 ; i<size ; i++){
				for(int j = 0 ; j<size ; j++){
					temp.push_back( board[i][j] );
				}
			}
			ans.push_back(temp);
		}
		
		bool isSafe(int row , int col , vector<vector<int>> &board ,int size){
			int x = row;
			int y = col;

			while(y >=0){
				if(board[x][y]==1)
					return false;
				y--;    
			}

			x = row;
			y = col;

			while(x>=0 && y>=0){
				if(board[x][y]==1)
					return false;
				x--;
				y--;
			}

			x = row;
			y = col;

			while(x<size && y>=0){
				if(board[x][y]==1)
					return false;
				y--;
				x++;
			}

			return true;
		}

};