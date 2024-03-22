#include <iostream>
using namespace std;


template <typename T>
class queue{
	private:
		T *container;
		T front;
		T  rear;
		int size;
	
	public:
		queue(int size = 10){
			this->size = size;
			container = new T[size];
			front = 0;
			rear = -1;
		}
		
		void push(T data){
			if(rear!=-1 && (rear+1)%size == front){ 
				cout<<"Container is Full You can't push element"<<endl;
			}else{
				rear = (rear+1)%size;
				container[rear] = data;
			}
		}
		
		void pop(){
			if(rear==-1){
				cout<<"Container is Empty You can't pop element"<<endl;
			}else{
				if(front==rear){
					front = 0;
					rear = -1;
				}
				else{
					front++;
				}
			}
		}
		
		void print(){
			if(rear==-1){
				cout<<"Nothing to print"<<endl;
				return;
			}
			if(front==rear){
				cout<<container[front]<<endl;
			}else{
				for(int i = front; i !=rear ; i = (i+1)%size){
					cout<<container[i]<<" ";
				}
				cout<<container[rear];
				cout<<endl;
				return;
			}
			
		}
};