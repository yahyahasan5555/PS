using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
       bool dfs(int node, vvi& graph, vi& colors, int assign_color) {
              if(colors[node] != 0) // visited before:
                     return colors[node] == assign_color;

              colors[node] = assign_color; // mark as visited and give it a color

              // in case color1 = 1 and color2 = 2 then the number 3 gets the opposite color
              // opposite of 2 = '3' - 2  && opposite of 1 = '3' - 1
              for(int child: graph[node])
                     if(!dfs(child, graph, colors, 3 - assign_color))
                            return false;
              
              return true;
       }
public:
       bool isBipartite(vector<vector<int>>& graph) {
              int nodes {(int) graph.size()};
              
              // the graph nodes from 0 to n-1
              vi colors(nodes);
              for(int i {}; i < nodes; ++i) 
                     if(!colors[i] && !dfs(i, graph, colors, 1))
                            return false; 
              
              return true;
       }
};
