#include<bits/stdc++.h>
#define Fast                ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//    /\_/\
//   (= ._.)
//   / >  \>
using namespace std;
using ll = long long;
using vi = vector<int>;
using Graph = vector<vector<int>>;

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
}

// Longest Path Problem
class Solution {
public:
       int minimumSemesters(int n, vector<vector<int>>& relations) {
              Graph graph(n + 1);
              vector<int> in_degree(n + 1);

              for(auto& vec: relations) 
                     add_directed_edge(graph, vec[0], vec[1]),
                     ++in_degree[vec[1]];

              queue<int> q;
              for(int node {1}; node <= n; ++node)
                     if(!in_degree[node])
                            q.push(node);

              int level {}; 
              int found_nodes {};

              while(!q.empty()) {
                     int sz {(int) q.size()};
                     while(sz--) {
                            int cur {q.front()}; q.pop();
                            ++found_nodes;

                            for(int neighbor: graph[cur])
                                   if(!--in_degree[neighbor])
                                          q.push(neighbor);
                     }
                     ++level;
              }

              return found_nodes == n ? level : -1;
       }
}; 

void testCase(void) {
       vector<vector<int>> vec {{1, 3}, {2, 3}};
       cout << Solution().minimumSemesters(3, vec) << endl;
}

signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast


       testCase();
       return 0;
}