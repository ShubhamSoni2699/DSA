#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class graph{
	private:
		unordered_map<int,vector<int>> adjList;
		void depthFirstSearch(unordered_map<int,bool>& isVisited,int node){
			if(!isVisited[node]){
				cout<<node<<" ";
				isVisited[node] = true;
				for(auto i: adjList[node]){
					depthFirstSearch(isVisited,i);
				}
			}
		}
	public:
		void addEdges(int u , int v , bool isDirected = false){
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
};