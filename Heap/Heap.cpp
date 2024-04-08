#include <algorithm>
#include <iostream>

using namespace std;


class Heap {
	private:
		int * container;
		int size ;
	public:
		Heap(){
			container = new int[100];
			size = 0;
			container[0] = -1;
		}
	void insert(int value){
		int index = ++size;
		container[index] = value;
		int parent = index/2;
		while(parent>=1){
			if(container[parent] < container[index] ){
				swap(container[index] , container[parent]);
				index = parent;
			}
			parent /= 2;
		}
	}
	
	void print(){
		for(int i = 1 ; i<=size ; i++){
			cout<<container[i]<<" ";
		}
		cout<<endl;
	}
};