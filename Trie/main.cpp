#include <iostream>
#include "Trie.cpp"
#include <vector>
#include <string>

using namespace std;

void getAllSuggestions(TrieNode * curr , vector<string>&temp , string prefix){
	if(curr->isTerminal){
		temp.push_back(prefix);
	}
	for(char ch = 'A' ; ch<='Z' ; ch++){
		TrieNode * next = curr->children[ch - 'A'];
		if(next!=nullptr){
			prefix.push_back(ch);
			getAllSuggestions(next,temp,prefix);
			prefix.pop_back();
		}
	}
}

void printSuggestions(vector<string> wordList, string queryStr){
	Trie * t = new Trie();
	int size = wordList.size();
	
	for(int i = 0 ; i<size ; i++){
		t->insertWord(wordList[i]);
	}
	
	TrieNode* pre = t->root;
	
	string prefix = "";
	vector<vector<string>> output;
	
	for(int i = 0 ; i<queryStr.size() ; i++){
		prefix.push_back(queryStr[i]);
		TrieNode *curr = pre->children[queryStr[i]-'A'];
		if(curr==nullptr){
			break;
		}
		vector<string>temp;
		getAllSuggestions(curr,temp,prefix);
		output.push_back(temp);
		temp.clear();
		pre = curr;
	}
	
	int vectorSize = output.size();
	for(int i = 0 ; i<vectorSize ; i++){
		for(int j = 0 ; j<output[i].size() ; j++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
}

int main(){
//	Trie *t = new Trie();
	
	//inserting
//	t->insertWord("HELLO");
//	t->insertWord("WATERMELON");
//	t->insertWord("ARM");
//	t->insertWord("ARE");
	
	//searching 
//	cout<<"HELLO "<<t->search("HELLO")<<endl;
//	cout<<"HE "<<t->search("HE")<<endl;
//	cout<<"WATER "<<t->search("WATER")<<endl;
//	cout<<"ARE "<<t->search("ARE")<<endl;
//	cout<<"ARM "<<t->search("ARM")<<endl;
	
	//deleting 
//	t->remove("ARE");
//	cout<<"ARE "<<t->search("ARE")<<endl;
//	cout<<"ARM "<<t->search("ARM")<<endl;


	
	vector<string> wordList {"CODING" , "CODE" , "NINJAS" , "CAP" , "CODER","NAP" , "CAT"};
	string queryStr = "CA";
	printSuggestions(wordList,queryStr);
	
	return 0;
}