#include <iostream>
#include <queue>
#include <vector>
#include "binaryTree.cpp"

using namespace std;


void inOrderTraversal(Node<int>*root){
	if(root==NULL){
		return ;
	}
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

void preOrderTraversal(Node<int>*root){
	if(root==NULL){
		return ;
	}
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(Node<int>*root){
	if(root==NULL){
		return ;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";
}


void levelOrderTraversal(Node<int>*root){
	queue<Node<int>*>q;
	q.push(root);
	q.push(nullptr);
	
	
	while(!q.empty()){
		if(q.front()==nullptr){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(nullptr);
			}
		}else{
			cout<<q.front()->data<<" ";
			if(q.front()->left){
				q.push(q.front()->left);
			}
			if(q.front()->right){
				q.push(q.front()->right);
			}
			q.pop();
		}
	}
}


Node<int>* buildTree(Node<int>*root) {
	cout<<"Enter data in node"<<endl;
	int data = 0;
	cin>>data;
	
	root = new Node<int>(data);
	
	if(data==-1){
		return nullptr;
	}
	
	cout<<"Enter data in left node of :"<< root->data <<endl;
	root->left = buildTree(root->left);
	
	cout<<"Enter data in right node of :"<<root->data <<endl;
	root->right = buildTree(root->right);
	
	return root;
	
}

void buildTreeLevelOrderTraversal(Node<int>*&root){
	queue<Node<int>*>q;
	cout<<"Enter data in root Node :"<<endl;
	int data = 0;
	cin>>data;
	root = new Node<int>(data);
	q.push(root);
	
	while(!q.empty()){
		cout<<"Enter data in left node of :"<<q.front()->data<<endl;
		cin>>data;
		if(data!=-1){
			q.front()->left = new Node<int>(data);
			q.push(q.front()->left);
		}
		
		cout<<"Enter data in right node of :"<<q.front()->data<<endl;
		cin>>data;
		if(data!=-1){
			q.front()->right = new Node<int>(data);
			q.push(q.front()->right);
		}
		q.pop();
	}
}

int findPos(int ele , vector<int>&in){
	for(int i = 0 ; i<in.size() ; i++){
		if(in[i]==ele){
			return i;
		}
	}
	return -1;
}

Node<int>* solveCreateTreeFromPreIn(vector<int>&pre , vector<int>&in , int &index , int s , int e,int size){
	if(index == size || s>e){
		return nullptr;
	}
	Node<int>* root = new Node<int>(pre[index]);
	int pos = findPos(pre[index++] , in);
	root->left = solveCreateTreeFromPreIn(pre,in,index,s,pos-1,size);
	root->right = solveCreateTreeFromPreIn(pre,in,index,pos+1,e,size);
	
	return root;
	
	
}

Node<int>* createTreeFromPreIn(vector<int>&pre , vector<int>&in){
	int index = 0;
	int size = in.size();
	return solveCreateTreeFromPreIn(pre,in,index,0,size-1,size);
}



int main(){
	
	//Node<int>*root = nullptr;
	
	//1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 -1 7 -1 -1
	//root = buildTree(root);
	
	//buildTreeLevelOrderTraversal(root);
	
	//cout<<endl<<endl<<endl;
	
	//cout<<"Inorder traversal"<<endl;
	//inOrderTraversal(root);
	
	
	
//	cout<<endl<<endl<<endl;
//	
//	cout<<"pre order traversal"<<endl;
//	preOrderTraversal(root);
	
	
	
	
//	cout<<endl<<endl<<endl;
//	
//	cout<<"post order traversal"<<endl;
//	postOrderTraversal(root);
//	
//	
//	
//	cout<<endl<<endl<<endl;
//	
//	cout<<"level order traversal"<<endl;
//	levelOrderTraversal(root);
//	
//	cout<<endl<<endl;
//	
//	
//	Node<int>* root = nullptr;
//	
//	vector<int>pre {1,2,4,5,3,6,7};
//	vector<int>in {4,2,5,1,6,3,7};
//	
//	root = createTreeFromPreIn(pre,in);
//	
//	levelOrderTraversal(root);

	

	return 0;
}