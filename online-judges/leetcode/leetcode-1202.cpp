// https://leetcode.com/problems/smallest-string-with-swaps/

using Graph = vector<vector<int>>;
void add_undirected_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
       graph[to].push_back(from);
}

class Solution {
private:
       static void dfs(int idx, Graph& graph, vector<bool>& vis, vector<int>& butch) {      
              vis[idx] = true;
              butch.push_back(idx);

              for(int ch: graph[idx])
                     if(!vis[ch])
                            dfs(ch, graph, vis, butch);
       }

public:
       string smallestStringWithSwaps(string& s, vector<vector<int>>& pairs) {
              int nodes {(int) s.size()};
              
              // lets build the graph:
              Graph adj(nodes);
              for(const auto& vec: pairs) 
                     add_undirected_edge(adj, vec[0], vec[1]);

              vector<bool> visited(nodes); // initially falses

              // Time: O(E + V) without sorting.
              for(int node {}; node < nodes; ++node) {
                     if(!visited[node]) {
                            vector<int> butch;
                            dfs(node, adj, visited, butch);

                            // now I've all the indexes in this CC, lets convert to letters and sort the letters
                            string tmp;
                            for(int idx: butch) 
                                   tmp.push_back(s[idx]);

                            sort(tmp.begin(), tmp.end());
                            sort(butch.begin(), butch.end());


                            for(int i {}; i < (int) butch.size(); ++i)
                                   s[butch[i]] = tmp[i];
                     }
              }
              
              return s;
       }
};