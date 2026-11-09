// https://cses.fi/problemset/task/1623
// Topic: Rescursion

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

ll min_diff(vi apples, int idx = 0, ll sum1 = 0, ll sum2 = 0) {
       if(idx == (int) apples.size()) // base case.
              return abs(sum1 - sum2);

       // There are 2 possible choices:
       // 1. put the current apple to group1
       ll g1 {min_diff(apples, idx + 1, sum1 + apples[idx], sum2)};
       
       // 2. put it into the g2
       ll g2 {min_diff(apples, idx + 1, sum1, sum2 + apples[idx])};

       // return the min diff:
       return min(g1, g2);
}

void testCase(void) {
       int n; cin >> n;
       vi vec(n); read(vec);
       cout << min_diff(vec) << endl;
}
 
signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast
 
 
       testCase();
       return 0;
}