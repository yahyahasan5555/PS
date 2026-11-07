#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
private:
       map<int, vector<int>> adj;
public:
       vector<int> restoreArray(vector<vector<int>>& Pairs) {
              for(auto vec: Pairs)
                     addUndirectedEdge(vec[0], vec[1]);

              int parent = 1e6;       
              vector<int> res;
              for(auto& [i, vec]: adj)
                     if(vec.size() == 1) {
                            dfs(res, i, parent);
                            break;
                     }
                     
              return res;
       }

       void dfs(vector<int>& res, int start, int parent) {
              res.push_back(start);
              for(int ch: adj[start])
                     if(ch != parent)
                            dfs(res, ch, start);
       }

       void addUndirectedEdge(int u, int v) {
              adj[u].push_back(v);
              adj[v].push_back(u);
       }      
};

void testCase(void) {       
       vector<vector<int>> vec {{2,1},{3,4},{3,2}};
       vector<int> res = Solution().restoreArray(vec);
       for(int x: res) cout << x << ' '; cout << endl;
}

signed main() {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       testCase();
       return 0;
}