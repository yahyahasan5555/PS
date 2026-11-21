#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// Adjacency list, but the keys comes from a hash table
typedef unordered_map<int, vector<int>> GRAPH;
class Solution {
private:
       void add_directed_edge(GRAPH &graph, int from, int to) {
              graph[from].push_back(to);
       }

       void build_graph_from_edges_list(GRAPH &graph, vector<int> &pid, vector<int> &ppid) {
              for (int i = 0; i < (int) pid.size(); ++i)
                     add_directed_edge(graph, ppid[i], pid[i]);
       }

       void dfs(GRAPH &graph, int node, unordered_set<int> &visited) {
              visited.insert(node);
              for (int neighbour : graph[node])
                     if (!visited.count(neighbour))
                            dfs(graph, neighbour, visited);
       }

       vector<int> reachability(GRAPH &graph, int node) {
              unordered_set<int> visited;
              dfs(graph, node, visited);
              return vector<int>(visited.begin(), visited.end());
       }
public:
	vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
		GRAPH graph;
		build_graph_from_edges_list(graph, pid, ppid);
		return reachability(graph, kill);
	}
};
