#include <iostream>
#include "Trie.cpp"
using namespace std;

int main(){
	Trie *t = new Trie();
	
	//inserting
	t->insertWord("HELLO");
	t->insertWord("WATERMELON");
	t->insertWord("ARM");
	t->insertWord("ARE");
	
	//searching 
	cout<<"HELLO "<<t->search("HELLO")<<endl;
	cout<<"HE "<<t->search("HE")<<endl;
	cout<<"WATER "<<t->search("WATER")<<endl;
	cout<<"ARE "<<t->search("ARE")<<endl;
	cout<<"ARM "<<t->search("ARM")<<endl;
	
	//deleting 
	t->remove("ARE");
	cout<<"ARE "<<t->search("ARE")<<endl;
	cout<<"ARM "<<t->search("ARM")<<endl;
	return 0;
}