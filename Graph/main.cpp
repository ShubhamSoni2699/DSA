#include <iostream>
#include <Graph.cpp>
using namespace std;

int main(){
	graph g;
	cout<<"Enter no of nodes :-"<<endl;
	int m,n = 0;
	cin>>n;
	cout<<"Enter no of edges :-"<<endl;
	cin>>m;
	
	for(int i = 0 ; i<m ; i++){
		cout<<"u,v :-";
		int u,v = 0;
		cin>>u>>v;
		g.addEdges(u,v);
	}
	
	g.printGraph();
	cout<<endl;
	//g.bfs();
	//cout<<endl;
	//g.dfs();

	cout<<g.isCyclicBFS()<<endl;
	
	return 0;
}