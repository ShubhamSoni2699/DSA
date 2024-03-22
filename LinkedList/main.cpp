#include <iostream>
#include "SinglyLinkedList.cpp"

using namespace std;

int main(){
	singlyLinkedList<int> list(10);
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.deleteNode();
	list.deleteNode();
	list.print();
	return 0;
}