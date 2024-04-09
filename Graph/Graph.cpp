#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class graph{
	private:
		unordered_map<int,vector<int>> adjList;
		bool isDirected ;
		void depthFirstSearch(unordered_map<int,bool>& isVisited,int node){
			if(!isVisited[node]){
				cout<<node<<" ";
				isVisited[node] = true;
				for(auto i: adjList[node]){
					depthFirstSearch(isVisited,i);
				}
			}
		}
		bool isCDFS(int node , int parent , unordered_map<int,bool> &isVisited ,unordered_map<int,bool> &dfsVisited){
			isVisited[node] = true;
			
			if(isDirected)
				dfsVisited[node] = true;
			
			for(auto neighbour: adjList[node]){
				if(!isVisited[neighbour]){
					bool isCyclic = isCDFS(neighbour , node , isVisited,dfsVisited);
					if(isCyclic)
						return true;
				}else{
					if(!isDirected){
						if(neighbour!=parent){
							return true;
						}
					}else{
						if(dfsVisited[neighbour]){
							return true;
						}
					}
				}
			}
			if(isDirected)
				dfsVisited[node] = false;
			return false;
		}
			
	public:
		
		graph(bool isDirected = false){
			this->isDirected = isDirected;
		}
		
		void addEdges(int u , int v ){
			adjList[u].push_back(v);
			if(!isDirected){
				adjList[v].push_back(u);
			}
		}
		
		void printGraph(){
			for(auto u : adjList){
				cout<<u.first<<" ->";
				for(auto v: u.second){
					cout<<v<<",";
				}
				cout<<endl;
			}
		}
		
		void bfs(){
			queue<int> q;
			unordered_map<int,bool> isVisited;
			q.push(0);
			
			while(!q.empty()){
				int fNode = q.front();
				q.pop();
				cout<<fNode<<" ";
				isVisited[fNode] = true;
				
				for(auto i: adjList[fNode]){
					if(!isVisited[i]){
						q.push(i);
					}
				}
			}
			cout<<endl;
		}
		
		void dfs(){
			unordered_map<int,bool> isVisited;
			depthFirstSearch(isVisited , 0);
			cout<<endl;
		}
		
		bool isCyclicBFS(){
			unordered_map<int,bool> isVisited;
			unordered_map<int,int> parent;
			
			queue<int> q;
			
			q.push(0);
			isVisited[0] = true;
			parent[0] = -1;
			
			while(!q.empty()){
				int front = q.front();
				q.pop();
				
				for(auto neighbour: adjList[front]){
					if(isVisited[neighbour] && neighbour != parent[front]){
						return true;
					}else if(!isVisited[neighbour]){
						q.push(neighbour);
						isVisited[neighbour] = true;
						parent[neighbour] = front;
					}
				}
			}
			return false;
		}
		
		bool isCyclicDFS(){
			unordered_map<int,bool> isVisited;
			unordered_map<int,bool> dfsVisited;
			return isCDFS(0,-1,isVisited,dfsVisited);
		}
};