#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class sudoku{
	private:
		bool isRightVal(int row ,int col , int val , vector<vector<int>>&board ){
			for(int i = 0 ; i<9 ; i++){
				if(board[row][i]==val){
					return false;
				}
				if(board[i][col]==val){
					return false;
				}
				if( board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
					return false;
				}
			}
			return true;
		}
		
		bool solve( vector<vector<int>>&board ){
			for(int row = 0 ; row<9 ; row++){
				for(int col = 0 ; col<9 ; col++){
					if(board[row][col]==0){
						for(int val = 1 ; val<=9 ; val++){
							if(isRightVal(row,col,val,board)){
								board[row][col] = val;
								bool isPossibleSol = solve(board);
								if(isPossibleSol){
									return true;
								}else{
									board[row][col] = 0;
								}
							}
						}
						return false;
					}
				}
			}
			return true;
		}
		
	public:
		vector<vector<int>> solveSudoku(vector<vector<int>> board){
			solve(board);
			return board;
		}
		void printSudoku(vector<vector<int>>& board){
			for(int row = 0 ; row<9 ; row++){
				for(int col = 0 ; col<9 ; col++){
					cout<<board[row][col]<<" ";
				}
				cout<<endl;
			}
		}
};