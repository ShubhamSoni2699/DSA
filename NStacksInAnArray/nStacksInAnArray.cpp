#include <iostream>
using namespace std;

template <class T>
class nStacks{
	private:
		T *container;
		int *top;
		int *next;
		int size;
		int freeSpace;
	
	public:
		nStacks(int size , int nStacks){
			container = new T[size];
			top = new int[nStacks];
			next = new int[size];
			this->size = size;
			freeSpace = 0;
			
			for(int i = 0 ; i<nStacks; i++){
				top[i] = -1;
			}
			
			for(int i = 0 ; i<size-1; i++){
				next[i] = i+1;
			}
			next[size-1] = -1;
			
		}
		
		void push(int mthStack , int value){
			
			if(freeSpace==-1){
				cout<<"Stack is full "<<endl;
				return;
			}
			
			int index = freeSpace;
			freeSpace = next[index];
			container[index] = value;
			
			next[index] = top[mthStack-1];
			
			top[mthStack-1] = index;
			
		}
		
		int pop(int mthStack){
			if(top[mthStack-1]==-1){
				cout<<"Stack is Empty you can't pop"<<endl;
				return -1;
			}
			int index = top[mthStack-1];
			
			top[mthStack-1] = next[index];
			
			int value = container[index];
			next[index] = freeSpace;
			freeSpace = index;
			
			return value;
			
		}
};