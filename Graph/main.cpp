#include <iostream>
#include <Graph.cpp>
using namespace std;

int main(){
	
	cout<<"Enter no of nodes :-"<<endl;
	int m,n = 0;
	cin>>n;
	cout<<"Enter no of edges :-"<<endl;
	cin>>m;
	
	graph unDirectedGraph(n);
	
	for(int i = 0 ; i<m ; i++){
		cout<<"u,v :-";
		int u,v = 0;
		cin>>u>>v;
		//directedGraph.addEdges(u,v);
		unDirectedGraph.addEdges(u,v);
	}
	
	cout<<endl;
	
	//directedGraph.printGraph();
	//cout<<endl;
	//g.bfs();
	//cout<<endl;
	//g.dfs();
	
	unDirectedGraph.printGraph();
	cout<<endl;

	//cout<<"is cycle dfs direct:"<<directedGraph.isCyclicDFS()<<endl;
	//cout<<"is cycle dfs undirect:"<<unDirectedGraph.isCyclicDFS()<<endl;
	
	//vector<int>topSort = directedGraph.topologicalSortDFS();
	//vector<int>topSortBFS = directedGraph.topologicalSortBFS();
	//
	//cout<<"Top sort DFS :- ";
	//for(auto i:topSort){
	//	cout<<i<<" ";
	//}
	//cout<<endl;
	//
	//cout<<"Top sort BFS :- ";
	//for(auto i:topSortBFS){
	//	cout<<i<<" ";
	//}
	//cout<<endl;
	//cout<<directedGraph.isCyclicDirectedBFS()<<endl;
	
	vector<int> shortestPath = unDirectedGraph.shortestPathUndirected(0,4);
	
	for(auto i : shortestPath){
		cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}