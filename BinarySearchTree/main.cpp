#include <iostream>
#include "bst.cpp"
using namespace std;

void inOrderTraversal(Node*root){
	if(root==NULL){
		return ;
	}
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

Node* createBST(Node * root , int data){
	if(root==nullptr){
		root = new Node(data);
		return root;
	}
	if(data < root->data){
		root->left = createBST(root->left , data);
	}
	if(data > root->data){
		root->right = createBST(root->right , data);
	}
	
	return root;

}


int main(){
	cout<<"Enter data here & -1 to stop :"<<endl;
	int data = 0;
	cin>>data;
	Node *root = nullptr;
	while(data!=-1){
		root = createBST(root ,data);
		cin>>data;
	}
	
	inOrderTraversal(root);
	
	return 0;
}