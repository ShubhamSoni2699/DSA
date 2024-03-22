#include <iostream>
#include <queue>
using namespace std;

class Node{
	public:
		int data;
		Node *right;
		Node *left;
	Node(int data){
		this->data = data;
		right = nullptr;
		left = nullptr;
	}
};





