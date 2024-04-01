#include "NQueenProblem.cpp"
#include "SudokuSolver.cpp"
#include <iostream>
using namespace std;

int main(){
//	nQueen q;
//	q.printAllPossibleSol(4);
//	
//	cout<<endl<<endl;
//	
//	q.printAllPossibleSol(6);
	
	vector<vector<int>> board {
		{6,0,0,1,0,0,0,0,0},
		{0,0,9,0,5,6,0,0,8},
		{0,3,0,0,0,0,0,4,0},
		{0,0,6,0,7,8,0,0,5},
		{0,0,0,0,0,2,0,0,0},
		{9,0,0,0,0,0,6,0,0},
		{0,0,0,9,0,0,0,0,1},
		{4,0,0,0,1,7,0,8,0},
		{0,0,7,2,0,0,0,0,0}
	};
	sudoku s;
	s.printSudoku(board);
	cout<<endl<<endl;
	board = s.solveSudoku(board);
	s.printSudoku(board);
	return 0;
}