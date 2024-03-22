#include <iostream>
#include <Heap.cpp>
using namespace std;

int main(){
	Heap * h = new Heap();
	h->insert(50);
	h->insert(55);
	h->insert(40);
	h->insert(70);
	
	h->print();
	
	return 0;
}