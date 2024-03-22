#include <iostream>
#include "queue.cpp"
using namespace std;

int main(){
	
	queue<int>q;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.print();
	
	q.pop();
	q.pop();
	
	q.push(6);
	q.push(7);
	q.print();
	
	
	
	return 0;
}