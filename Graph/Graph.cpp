#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class graph{
	private:
		unordered_map<int,vector<int>> adjList;
		int nodes;
		
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
		
		void topSortDFS(int node,unordered_map<int,bool>&isVisited , stack<int>&st){
			isVisited[node] = true;
			for(auto neighbour:adjList[node]){
				if(!isVisited[neighbour]){
					topSortDFS(neighbour,isVisited,st);
				}
			}
			st.push(node);
		}
			
	public:
		
		graph(bool isDirected = false , int nodes = 0){
			this->isDirected = isDirected;
			this->nodes = nodes;
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
		
		vector<int> topologicalSortDFS(){
			vector<int>ans;
			if(!isDirected)
				return ans;
			unordered_map<int,bool> isVisited;
			stack<int>st;
			
			topSortDFS(0,isVisited,st);
			
			while(!st.empty()){
				ans.push_back(st.top());
				st.pop();
			}
			return ans;
		}
		
		vector<int> topologicalSortBFS(){
			vector<int> ans;
			if(!isDirected)
				return ans;
				
			vector<int>indegree(nodes,0);
			queue<int>q;
			
			for(auto map : adjList){
				for(auto neighbour : map.second){
					indegree[neighbour]++;
				}
			}
			
			for(int i= 0 ; i<nodes ; i++){
				if(indegree[i]==0){
					q.push(i);
				}
			}
			
			while(!q.empty()){
				int front = q.front();
				q.pop();
				ans.push_back(front);
				
				for(auto neighbour:adjList[front]){
					indegree[neighbour]--;
					if(indegree[neighbour]==0){
						q.push(neighbour);
					}
				}
				
			}
			return ans;
		}
		
		bool isCyclicDirectedBFS(){
			if(!isDirected)
				return isCyclicBFS();
				
			vector<int>indegree(nodes,0);
			queue<int>q;
			
			int countNode = 0;
			
			for(auto map : adjList){
				for(auto neighbour : map.second){
					indegree[neighbour]++;
				}
			}
			
			for(int i= 0 ; i<nodes ; i++){
				if(indegree[i]==0){
					q.push(i);
				}
			}
			
			while(!q.empty()){
				int front = q.front();
				q.pop();
				countNode++;
				
				for(auto neighbour:adjList[front]){
					indegree[neighbour]--;
					if(indegree[neighbour]==0){
						q.push(neighbour);
					}
				}
				
			}
			if(countNode == nodes){
				return false;
			}
			return true;
		}
};