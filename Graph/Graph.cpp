#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class graph{
	private:
		unordered_map<int,vector<int>> adjList;
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
};