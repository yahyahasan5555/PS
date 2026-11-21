// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
/*
 * if we've an array of pairs: (1, 2) (2, 3) (3, 4) (4, 5)
 * if we converted this pairs to a graph will be undirected un-weighted chain graph
 * and if begin with a node of the 2 boundary nodes (ONLY will be 2 nodes have one edge, and other nodes will have 2 edges)
 * this means this is 2 possible arrays [1, 2, 3, 4, 5] OR [5, 4, 3, 2, 1]
 * Both are original.
 * NOTE: we don't need to visited array here cause each node has maximum 2 neighbors (its parent and its child if found)
 * so for avoid cycles should handle the parent case ONLY.
 * 
 * so, THIS IS THE ANS:
 */

using Graph = unordered_map<int, vector<int>>;

void add_undirected_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
       graph[to].push_back(from);
}

class Solution {
private:
       void dfs(int cur_node, int parent, Graph& adj, vector<int>& original) {
              original.push_back(cur_node);

              for(int child: adj[cur_node]) 
                     if(child != parent)
                            dfs(child, cur_node, adj, original);
       }
public:
       vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
              // lets build our graph:
              Graph adj;
              for(auto& vec: adjacentPairs)
                     add_undirected_edge(adj, vec[0], vec[1]);

              // we should determine the start point/node
              // start node --> appears one time in the adjPairs matrix cause it's on the boundaries
              vector<int> original;
              for(auto& [node, neighbors]: adj) {
                     if(neighbors.size() == 1) {
                            // choose impossible parent for first node
                            dfs(node, 1e6, adj, original);
                            break;
                     }
              }

              return original;
       }
};
