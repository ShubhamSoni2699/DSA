#include "Graph.cpp"

#include <iostream>

using namespace std;

int main()
{

    cout << "Enter no of nodes :-" << endl;
    int m, n = 0;
    cin >> n;
    cout << "Enter no of edges :-" << endl;
    cin >> m;

    graph directedWeightedGraph(true, n, true);

    for(int i = 0; i < m; i++) {
        cout << "u,v and w :-";
        int u, v, w = 0;
        cin >> u >> v >> w;
        // directedGraph.addEdges(u,v);
        directedWeightedGraph.addEdges(u, v, w);
    }

    cout << endl;

    // directedGraph.printGraph();
    // cout<<endl;
    // g.bfs();
    // cout<<endl;
    // g.dfs();

    directedWeightedGraph.printGraph();
    cout << endl;

    // cout<<"is cycle dfs direct:"<<directedGraph.isCyclicDFS()<<endl;
    // cout<<"is cycle dfs undirect:"<<unDirectedGraph.isCyclicDFS()<<endl;

    vector<int> topSortDFS = directedWeightedGraph.topologicalSortDFS();
    vector<int> topSortBFS = directedWeightedGraph.topologicalSortBFS();

    cout << "Top sort DFS :- ";
    for(auto i : topSortDFS) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Top sort BFS :- ";
    for(auto i : topSortBFS) {
        cout << i << " ";
    }
    cout << endl;
    // cout<<directedGraph.isCyclicDirectedBFS()<<endl;

    // vector<int> shortestPath = unDirectedGraph.shortestPathUndirected(0, 4);

    // for(auto i : shortestPath) {
    //     cout << i << " ";
    // }
    // cout << endl;

    vector<int> shotestPath = directedWeightedGraph.shortestPathWeightedDirected(0);

    cout << "Shotest Path Weighted Directed graph:- ";
    for(auto i : shotestPath) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}