#include "NQueenProblem.cpp"
#include <iostream>
using namespace std;

int main(){
	nQueen q;
	q.printAllPossibleSol(4);
	
	cout<<endl<<endl;
	
	q.printAllPossibleSol(6);
	
	return 0;
}