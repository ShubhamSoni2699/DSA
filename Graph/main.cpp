#include <iostream>
#include <Graph.cpp>
using namespace std;

int main(){
	graph directedGraph(true);
	graph unDirectedGraph;
	
	cout<<"Enter no of nodes :-"<<endl;
	int m,n = 0;
	cin>>n;
	cout<<"Enter no of edges :-"<<endl;
	cin>>m;
	
	for(int i = 0 ; i<m ; i++){
		cout<<"u,v :-";
		int u,v = 0;
		cin>>u>>v;
		directedGraph.addEdges(u,v);
		unDirectedGraph.addEdges(u,v);
	}
	
	directedGraph.printGraph();
	cout<<endl;
	//g.bfs();
	//cout<<endl;
	//g.dfs();
	
	unDirectedGraph.printGraph();
	cout<<endl;

	cout<<"is cycle dfs direct:"<<directedGraph.isCyclicDFS()<<endl;
	cout<<"is cycle dfs undirect:"<<unDirectedGraph.isCyclicDFS()<<endl;
	
	return 0;
}