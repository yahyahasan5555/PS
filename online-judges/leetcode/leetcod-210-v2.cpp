#include<bits/stdc++.h>

#define Fast                ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define print(v)            for(auto& x: v) cout << x << ' '; cout << endl;
#define read(v)             for(auto& x: v) cin >> x;
#define sz(v)               ((int)((v).size()))
#define all(v)              ((v).begin()), ((v).end())
#define pb                  push_back

//    /\_/\
//   (= ._.)
//   / >  \>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

using Graph = vector<vi>;

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
}

vector<int> topological_sort(const Graph& graph) {
       int sz {(int) graph.size()};
       vector<int> in_degree(sz);

       for(auto neighbors: graph)
              for(int n: neighbors)
                     ++in_degree[n];

       queue<int> ready;
       for(int node {}; node < sz; ++node)
              if(!in_degree[node])
                     ready.push(node);

       vector<int> ordering;
       while(!ready.empty()) {
              int cur {ready.front()};
              ready.pop();

              ordering.push_back(cur);
              for(int neighbor: graph[cur])
                     if(!--in_degree[neighbor])
                            ready.push(neighbor);
       }

       if((int) ordering.size() != sz)
              return {}; // empty vector.
       
       return ordering;
}

class Solution {
public:
       vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
              Graph graph(numCourses);
              for(auto& vec: prerequisites)
                     add_directed_edge(graph, vec[1], vec[0]);
                     
              return topological_sort(graph);
       }
};

void testCase(void) {
       int numCourses = 2;
       vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
       print(Solution().findOrder(numCourses, prerequisites));
}

signed main() {
       Fast

       testCase();
       return 0;
}