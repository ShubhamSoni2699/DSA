#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class graph
{
private:
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, vector<pair<int, int>>> weightedAdjList;
    int nodes;

    bool isDirected;
    bool isWeighted;
    void depthFirstSearch(unordered_map<int, bool>& isVisited, int node)
    {
        if(!isVisited[node]) {
            cout << node << " ";
            isVisited[node] = true;
            for(auto i : adjList[node]) {
                depthFirstSearch(isVisited, i);
            }
        }
    }
    bool isCDFS(int node, int parent, unordered_map<int, bool>& isVisited, unordered_map<int, bool>& dfsVisited)
    {
        isVisited[node] = true;

        if(isDirected)
            dfsVisited[node] = true;

        for(auto neighbour : adjList[node]) {
            if(!isVisited[neighbour]) {
                bool isCyclic = isCDFS(neighbour, node, isVisited, dfsVisited);
                if(isCyclic)
                    return true;
            } else {
                if(!isDirected) {
                    if(neighbour != parent) {
                        return true;
                    }
                } else {
                    if(dfsVisited[neighbour]) {
                        return true;
                    }
                }
            }
        }
        if(isDirected)
            dfsVisited[node] = false;
        return false;
    }

    void topSortDFS(int node, unordered_map<int, bool>& isVisited, stack<int>& st)
    {
        isVisited[node] = true;
        if(isWeighted) {
            for(auto neighbour : weightedAdjList[node]) {
                if(!isVisited[neighbour.first]) {
                    topSortDFS(neighbour.first, isVisited, st);
                }
            }
        } else {
            for(auto neighbour : adjList[node]) {
                if(!isVisited[neighbour]) {
                    topSortDFS(neighbour, isVisited, st);
                }
            }
        }
        st.push(node);
    }

public:
    graph(bool isDirected = false, int nodes = 0, bool isWeighted = false)
    {
        this->isDirected = isDirected;
        this->nodes = nodes;
        this->isWeighted = isWeighted;
    }

    void addEdges(int u, int v, int weight = 0)
    {
        if(!isWeighted) {
            adjList[u].push_back(v);
            if(!isDirected) {
                adjList[v].push_back(u);
            }
        } else {
            weightedAdjList[u].push_back(make_pair(v, weight));
            if(!isDirected) {
                weightedAdjList[v].push_back(make_pair(u, weight));
            }
        }
    }

    void printGraph()
    {
        if(isWeighted) {
            for(auto u : weightedAdjList) {
                cout << u.first << " -> ";
                for(auto v : u.second) {
                    cout << "[";
                    cout << v.first << ",";
                    cout << v.second << "],";
                }
                cout << endl;
            }
        } else {
            for(auto u : adjList) {
                cout << u.first << " ->";
                for(auto v : u.second) {
                    cout << v << ",";
                }
                cout << endl;
            }
        }
    }

    void bfs()
    {
        queue<int> q;
        unordered_map<int, bool> isVisited;
        q.push(0);

        while(!q.empty()) {
            int fNode = q.front();
            q.pop();
            cout << fNode << " ";
            isVisited[fNode] = true;

            for(auto i : adjList[fNode]) {
                if(!isVisited[i]) {
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void dfs()
    {
        unordered_map<int, bool> isVisited;
        depthFirstSearch(isVisited, 0);
        cout << endl;
    }

    bool isCyclicBFS()
    {
        unordered_map<int, bool> isVisited;
        unordered_map<int, int> parent;

        queue<int> q;

        q.push(0);
        isVisited[0] = true;
        parent[0] = -1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(auto neighbour : adjList[front]) {
                if(isVisited[neighbour] && neighbour != parent[front]) {
                    return true;
                } else if(!isVisited[neighbour]) {
                    q.push(neighbour);
                    isVisited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS()
    {
        unordered_map<int, bool> isVisited;
        unordered_map<int, bool> dfsVisited;
        return isCDFS(0, -1, isVisited, dfsVisited);
    }

    vector<int> topologicalSortDFS()
    {
        vector<int> ans;
        if(!isDirected)
            return ans;
        unordered_map<int, bool> isVisited;
        stack<int> st;

        topSortDFS(0, isVisited, st);

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    vector<int> topologicalSortBFS()
    {
        vector<int> ans;
        if(!isDirected)
            return ans;

        vector<int> indegree(nodes, 0);
        queue<int> q;

        if(!isWeighted) {
            for(auto map : adjList) {
                for(auto neighbour : map.second) {
                    indegree[neighbour]++;
                }
            }
        } else {
            for(auto map : weightedAdjList) {
                for(auto neighbour : map.second) {
                    indegree[neighbour.first]++;
                }
            }
        }

        for(int i = 0; i < nodes; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            if(!isWeighted) {
                for(auto neighbour : adjList[front]) {
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            } else {
                for(auto neighbour : weightedAdjList[front]) {
                    indegree[neighbour.first]--;
                    if(indegree[neighbour.first] == 0) {
                        q.push(neighbour.first);
                    }
                }
            }
        }
        return ans;
    }

    bool isCyclicDirectedBFS()
    {
        if(!isDirected)
            return isCyclicBFS();

        vector<int> indegree(nodes, 0);
        queue<int> q;

        int countNode = 0;

        for(auto map : adjList) {
            for(auto neighbour : map.second) {
                indegree[neighbour]++;
            }
        }

        for(int i = 0; i < nodes; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            countNode++;

            for(auto neighbour : adjList[front]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        if(countNode == nodes) {
            return false;
        }
        return true;
    }

    vector<int> shortestPathUndirected(int s, int t)
    {
        unordered_map<int, bool> isVisited;
        unordered_map<int, int> parent;
        queue<int> q;
        vector<int> ans;

        q.push(s);
        isVisited[s] = true;
        parent[s] = -1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(auto ele : adjList[front]) {
                if(!isVisited[ele]) {
                    q.push(ele);
                    isVisited[ele] = true;
                    parent[ele] = front;
                }
            }
        }

        int target = t;

        while(target != -1) {
            ans.push_back(target);
            target = parent[target];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    vector<int> shortestPathWeightedDirected(int src = 0)
    {
        vector<int> distance(this->nodes, INT_MAX);
        distance[src] = 0;
        vector<int> topSortBFS = topologicalSortBFS();

        for(auto i : topSortBFS) {
            if(i != INT_MAX) {
                for(auto neighbour : weightedAdjList[i]) {
                    if(distance[i] + neighbour.second < distance[neighbour.first]) {
                        distance[neighbour.first] = distance[i] + neighbour.second;
                    }
                }
            }
        }

        return distance;
    }

    vector<int> dijkstraShotestPath(int src = 0)
    {
        vector<int> distance(this->nodes, INT_MAX);
        set<pair<int, int>> st;

        distance[src] = 0;
        st.insert(make_pair(0, src));

        while(!st.empty()) {
            pair<int, int> top = *(st.begin());
            st.erase(st.begin());

            for(auto neighbour : weightedAdjList[top.second]){
				if(top.first + neighbour.second < distance[neighbour.first]){
					auto record = st.find(make_pair(distance[neighbour.first],neighbour.first));
					if(record!=st.end()){
						st.erase(record);
					}
					distance[neighbour.first] = top.first + neighbour.second;
					st.insert(make_pair(distance[neighbour.first],neighbour.first));
				}
			}
        }
        return distance;
    }
};