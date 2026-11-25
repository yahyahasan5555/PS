// https://leetcode.com/problems/graph-valid-tree/

/*
 * Valid Tree rules:
       - 1 Connected Component.
       - # of edges = # of nodes - 1
       - no cycles or self loops (depending on the first 2 rules).
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> Graph;

void add_undirected_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
       graph[to].push_back(from);
}

class Solution {
private:
       void build_graph(const vector<vector<int>>& edges, Graph& graph) {
              for(auto& vec: edges) 
                     add_undirected_edge(graph, vec[0], vec[1]);
       }

       // BFS
       bool has_cycles(Graph& graph, vector<bool>& visited ,int start) {
              // In an undirected graph, ignore the parent edge.
              // Any other edge leading to an already visited node indicates a cycle.
              vector<int> parent(graph.size(), -1);
              queue<int> q;

              q.push(start);
              visited[start] = true;

              while(!q.empty()) {
                     int cur {q.front()};
                     q.pop();

                     for(int neighbor: graph[cur]) {
                            if(neighbor == parent[cur]) 
                                   continue;

                            if(visited[neighbor])
                                   return true; // this graph has a cycle.
                            
                            visited[neighbor] = true;
                            q.push(neighbor);
                            parent[neighbor] = cur;
                     }
              } return false;
       }

public:
       bool validTree(int nodes, vector<vector<int>> &edges) {
              if(nodes != (int) edges.size() + 1)
                     return false; // Case#1: nodes = edges + 1
                     
              vector<bool> visited(nodes);
              Graph graph(nodes);
              build_graph(edges, graph);

              if(has_cycles(graph, visited, 0))
                     return false; // this is not a tree.

              // this loop for check from forset graph (multiple CCs)
              for(int node {}; node < nodes; ++node) 
                     if(!visited[node])
                            return false; // if there is an un-reachable node from the first search then this is not a tree.

              // otherwise this is a tree.
              return true;
       }
};

void test_case(void) {
       vector<vector<int>> edges = {{0,1}, {0,2},{0,3}, {1,4}};

       cout << boolalpha;
       cout << Solution().validTree(5, edges) << endl;
}

int main() {
       test_case();
       return 0;
}
