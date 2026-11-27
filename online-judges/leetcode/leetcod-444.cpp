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

/*
 * We know there can be many topological sort
 * Can we know if there is a SINGLE UNIQE ordering?
 * Yes trivial. The queue MUST always have a single node.
 * 		This means in every step, we can only choose this node
 */

typedef unordered_map<int, vector<int>> Graph;

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
}

class Solution {
public:
	bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
              Graph graph;
              unordered_map<int, int> in_degree;

              for(auto& vec: seqs) {
                     // handle the edge case seq = 1 element only:
                     if((int) vec.size() == 1)   
                            graph[vec[0]]; // just add to the graph with no neighbors.
                     else {
                            for(int i {}; i < (int) vec.size() - 1; ++i)
                                   add_directed_edge(graph, vec[i], vec[i + 1]),
                                   in_degree[vec[i + 1]]++;
                     }
              }

              queue<int> q;
              for(auto& [node, neighbors]: graph)
                     if(!in_degree.count(node))
                            q.push(node);

              vector<int> res;
              while(!q.empty()) {
                     if((int) q.size() > 1)
                            return false; // once found multiple starting points, then: false

                     int cur {q.front()};
                     q.pop();
                     res.push_back(cur);

                     for(int neighbor: graph[cur])
                            if(!--in_degree[neighbor])  
                                   q.push(neighbor);
              }
              return res == org;
	}
};



void testCase(void) {
       vi org {4,1,5, 2, 6, 3}; vvi seqs = {{5,2,6,3}, {4,1,5,2}};
       cout << boolalpha;
       cout << Solution().sequenceReconstruction(org, seqs) << endl;
       
       vi org2 {1, 2, 3}; vvi seqs2 = {{1, 2}, {1, 3}};
       cout << boolalpha;
       cout << Solution().sequenceReconstruction(org2, seqs2) << endl;
}

signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast


       testCase();
       return 0;
}