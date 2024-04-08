#include <iostream>

using namespace std;

template <typename T>
class node{
	public:
		T data = 0;
		node* next = nullptr;
		
		node(T data){
			this->data = data;
			this->next = nullptr;
		}
};

template <typename T>
class singlyLinkedList{
	private:
		node<T> *head = nullptr;
		node<T> *tail = nullptr;
		
	public:
		singlyLinkedList(T data = 0){
			node<T> *temp = new node<T>(data);
			this->head = temp;
			this->tail = temp;
		}
		void insertAtHead(int data){
			node<T> *temp = new node<T>(data);
			temp->next = head;
			head = temp;
			temp = nullptr;
		}
		void insertAtTail(T data){
			node<T> *newNode = new node<T>(data);
			this->tail->next = newNode;
			tail = newNode;
		}
		void deleteNode(){
			
			if(head!=tail){
				node<T> *tempD = tail;
				node<T> *temp = head;
			
				while(temp->next!=tail){
					temp = temp->next;
				}
				tail = temp;
				tail->next = NULL;
				delete tempD;
				tempD = nullptr;
			}else{
				cout<<"only single node in linkedlist"<<endl;
			}
			
		}
		void print(){
			node<T>* temp = head;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		
		T at(int pos){
			node<T>* temp = head->next;
			int count = 0;
			while(count<pos){
				temp = temp->next;
				count++;
			}
			T data = temp->data;
			return data;
		}
};