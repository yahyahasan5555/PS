using vi = vector<int>;
using vvi = vector<vi>;

using Graph = vector<vi>;

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
}

// DFS ans instead of TS (topo-sort)
class Solution {
private:
       // returns true in case there are cycles:
       bool dfs(int node, Graph& graph, vi& res_order, vi& start_time, vi& end_time, int& time) {
              start_time[node] = time++;

              for(int neighbor: graph[node]) {
                     if(start_time[neighbor] == -1) {
                            if(dfs(neighbor, graph, res_order, start_time, end_time, time))
                                   return true; // my neighbor detected a cycle!
                     } else if(end_time[neighbor] == -1){ // 
                            // my neighbors started but still didn't finishes, so this is a back edge:
                            return true;
                     }
              }
              
              res_order.push_back(node);
              end_time[node] = time++;
              return false; // no cycles
       }
public:
       vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
              Graph graph(numCourses);

              // build the graph:
              for(auto& vec: prerequisites)
                     add_directed_edge(graph, vec[1], vec[0]);
              
              vi start_time(numCourses, -1), end_time(numCourses, -1), result;
              int time {1};
              for(int node {}; node < numCourses; ++node)      
                     if(start_time[node] == -1)
                            if(dfs(node, graph, result, start_time, end_time, time))
                                   return {};

              reverse(result.begin(), result.end()); // DFS returned TS's result but in reversed order, so unreverse to get the same.
              return result;
       }
};
