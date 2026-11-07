#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<int> color; // used as vis & color

bool bfs(int start) {
       queue<int> q;

       q.push(start);
       color[start] = 1;

       while(!q.empty()) {
              int cur {q.front()};
              q.pop();

              // in this case will be there is a number that repeated twice in such group.
              if(adj[cur].size() > 2) 
                     return false;

              for(int ch: adj[cur])
                     if(!color[ch])
                            color[ch] = 3 - color[cur], q.push(ch);
                     else if(color[ch] == color[cur])
                            return false;
       } return true;
}

void testCase(void) {
       int n; cin >> n;
       adj.assign(n+1, {}); color.assign(n+1, 0);

       for(int i {}; i < n; ++i) {
              int u, v; cin >> u >> v;
              adj[u].push_back(v), adj[v].push_back(u);
       }

       bool good {true};
       for(int i {1}; i <= n && good; ++i)
              if(!color[i])
                     good &= bfs(i);

       cout << (good ? "YES" : "NO") << '\n';
}

signed main() {
       ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
       #ifndef ONLINE_JUDGE
              freopen("cpp.in", "rt", stdin);
       #endif

       int t; cin >> t; while(t--)
       testCase();
       return 0;
}