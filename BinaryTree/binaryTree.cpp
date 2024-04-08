#include <iostream>

using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node<T> *left;
		Node<T> *right;
	public:
		Node(T data){
			this->data = data;
			left = nullptr;
			right = nullptr;
		}
};


template <class T>
class BinaryTree{
	private:
		Node<T>*root;
	public:
		BinaryTree(){
			root = nullptr;
		}
};

