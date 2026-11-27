#include<bits/stdc++.h>
#define Fast                ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//    /\_/\
//   (= ._.)
//   / >  \>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

using Graph = vector<vi>;

void add_undirected_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
       graph[to].push_back(from);
}

class Solution {
public:
       vi findMinHeightTrees(int n, vvi& edges) {
              if(n == 1)
                     return {0}; // special case.
                     
              Graph graph(n);
              vi in_degree(n);

              // implement the graph and increment nodes' in-degree
              for(auto& vec: edges)
                     add_undirected_edge(graph, vec[0], vec[1]),
                     ++in_degree[vec[0]],
                     ++in_degree[vec[1]];


              queue<int> q;
              // add the leaves only (leaf has in-degree = 1)
              for(int node {}; node < n; ++node)
                     if(in_degree[node] == 1)
                            q.push(node);


              int cnt_roots {n}; // initially all the nodes can be valid roots, then will decrement level-by-level:
              while(cnt_roots > 2) {
                     int level_sz {(int) q.size()};
                     // remove the leaves from cnt_roots because their cannot be valid roots:
                     cnt_roots -= level_sz;

                     while(level_sz--) { // level-by-level
                            int cur {q.front()}; q.pop();

                            for(int neighbor: graph[cur])
                                   if(--in_degree[neighbor] == 1) // if was a leaf after removing its link with 'cur'? add it
                                          q.push(neighbor);
                     }      
              }


              // now the answer size can be either 1 or 2 nodes only (1 in case odd diameter, 2 in even)
              vi res;
              while(!q.empty())
                     res.push_back(q.front()),
                     q.pop();
              
              return res;
       }
};

void testCase(void) {
       int n = 4;
       vvi edges = {{1, 0}, {1, 2}, {1, 3}};     
       
       for(int x: Solution().findMinHeightTrees(n, edges))
              cout << x << ' ';
       cout << endl;
}

signed main() {
       // freopen("in.txt", "r", stdin);
       Fast

       testCase();
       return 0;
}