#include <string>

using namespace std;

class TrieNode {
	public:
		char character;
		TrieNode * children[26];
		bool isTerminal;
	public:
		TrieNode(char c){
			this->character = c;
			for(int i = 0 ; i<26 ; i++){
				children[i] = nullptr;
			}
			isTerminal = false;
		}
};

class Trie {
	public:
		TrieNode* root;
	
	Trie(){
		this->root = new TrieNode('0');
	}
	private:
	void insertUtil(TrieNode* root , string word){
		if(word.length()==0){
			root->isTerminal = true;
			return;
		}
		int index = word[0]-'A';
		TrieNode* child = nullptr;
		
		if(root->children[index] != nullptr){
			child = root->children[index];
		}else{
			root->children[index] = new TrieNode(word[0]);
			child = root->children[index];
		}
		
		insertUtil(child,word.substr(1));
	}
	public:
	void insertWord(string word){
		insertUtil(root,word);
	}
	private:
	bool searchUtil(TrieNode* root , string word){
		if(word.length()==0){
			return root->isTerminal;
		}
		int index = word[0]-'A';
		TrieNode* child = nullptr;
		
		if(root->children[index] != nullptr ){
			child = root->children[index];
		}else{
			return false;
		}
		return searchUtil(child,word.substr(1));
	}
	
	public:
		bool search(string word){
			return searchUtil(root,word);
		}
		
	private:
		void removeUtil(TrieNode* root ,string word){
			if(root->isTerminal){
				root->isTerminal = false;
				return;
			}
			int index = word[0]-'A';
			TrieNode* child = nullptr;
			
			if(root->children[index]!=nullptr){
				child = root->children[index];
			}else{
				return;
			}
			removeUtil(child , word.substr(1));
		}
	
	public:
		void remove(string word){
			removeUtil(root,word);
		}
};