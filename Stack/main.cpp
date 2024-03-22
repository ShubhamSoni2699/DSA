#include <iostream>
#include "stack.cpp"

using namespace std;

int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	
	cout<<s.peek()<<endl;
	s.pop();
	cout<<s.peek()<<endl;
	s.pop();
	cout<<s.peek()<<endl;
}