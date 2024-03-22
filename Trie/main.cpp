#include <iostream>
#include "Trie.cpp"
using namespace std;

int main(){
	Trie *t = new Trie();
	
	//inserting
	t->insertWord("HELLO");
	t->insertWord("WATERMELON");
	
	//searching 
	cout<<"HELLO"<<t->search("HELLO")<<endl;
	cout<<"HE"<<t->search("HE")<<endl;
	cout<<"WATER"<<t->search("WATER")<<endl;
	return 0;
}