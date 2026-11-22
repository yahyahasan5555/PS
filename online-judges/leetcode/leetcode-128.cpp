// https://leetcode.com/problems/longest-consecutive-sequence/
typedef unordered_map <int, vector<int>> Graph;

class Solution {
       int dfs(int node, Graph& graph) {
              int cnt_nodes {1};
              for(int ch: graph[node]) 
                     cnt_nodes += dfs(ch, graph);
              
              return cnt_nodes;
       }

       int dfs_iterative(int node, Graph& graph) {
              int cnt {1};
              
              while(!graph[node].empty())
                     ++cnt, node = graph[node][0];
              return cnt;
       }
public:
       int longestConsecutive(vector<int>& nums) {
              // build the graph.
              // first each node individually and then another loop to connect between.
              Graph graph;
              for(int x: nums) graph[x]; // initialize it

              for(auto& [node, neighbors]: graph) 
                     if(graph.count(node + 1))
                            graph[node].push_back(node + 1); // add directed edge.                            

              int mx {};
              for(auto& [node, neighbor]: graph) 
                     if(!graph.count(node - 1)) // if this is the first/smallest node in its CC! 
                            mx = max(mx, dfs_iterative(node, graph));
                     
              return mx; // at least 0 in case empty list
       }
}; 