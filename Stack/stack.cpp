#include <iostream>
#include "D:\Programming\C++\DSA\DSA\LinkedList\SinglyLinkedList.cpp"

using namespace std;

template <typename T>
class stack{
	private:
		T top;
		singlyLinkedList<int>* container;
		T size;
		
	public:
		stack(){
			this->top = -1;
			this->size = 0;
			this->container = new singlyLinkedList<int>(-1);
		}
		
		void push(T data){
			this->container->insertAtTail(data);
			this->top++;
			this->size++;
		}
		
		void pop(){
			if(size>0){
				this->container->deleteNode();
				this->top--;
				this->size--;
			}
			else{
				cout<<"Stack is already empty"<<endl;
			}
			
		}
		
		T peek(){
			if(this->top>=0){
				return this->container->at(this->top);
			}else{
				cout<<"stack is empty"<<endl;
				return -1;
			}
		}
		
		bool isEmpty(){
			return this->top==-1 ? true : false;
		}
		
		
		~stack(){
			delete []this->container;
		}
};