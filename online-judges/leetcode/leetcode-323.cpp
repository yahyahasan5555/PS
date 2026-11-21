// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
typedef vector<vector<int>> GRAPH;

class Solution {
private:
       void add_undirected_edge(GRAPH &graph, int from, int to) {
              graph[from].push_back(to);
              graph[to].push_back(from);
       }

       void build_graph_from_edges_list(GRAPH &graph, vector<vector<int>> &edges) {
              for (int i = 0; i < (int) edges.size(); ++i)
                     add_undirected_edge(graph, edges[i][0], edges[i][1]);
       }

       void dfs(GRAPH &graph, int node, vector<bool> &visited) {
              visited[node] = true;
              for (int neighbour : graph[node])
                     if (!visited[neighbour])
                            dfs(graph, neighbour, visited);
       }

       int count_components(GRAPH &graph) {	// O(V+E)
              int nodes = graph.size();
              vector<bool> visited(nodes);	// shared among all nodes

              int counter = 0;
              for (int src = 0; src < nodes; ++src) {
                     if (!visited[src]) {
                            ++counter;
                            dfs(graph, src, visited);
                     }
              }
              return counter;
       }
public:
	int countComponents(int nodes, vector<vector<int>> &edges) {
		GRAPH graph(nodes);
		build_graph_from_edges_list(graph, edges);
		return count_components(graph);
	}
};
