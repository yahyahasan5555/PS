
#include<bits/stdc++.h>
 
#define Fast                ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define print(v)            for(auto& x: v) cout << x << ' '; cout << endl;
#define read(v)             for(auto& x: v) cin >> x;
#define sz(v)               ((int)((v).size()))
#define pb                  push_back
 
//    /\_/\
//   (= ._.)
//   / >  \>
using namespace std;
using ll = long long;
using vi = vector<int>;
 
void testCase(void) {
       int n; cin >> n;
       vi apples(n);
       read(apples);

       ll diff {INT_MAX};
       for(int mask {}; mask < 1 << n; ++mask) {
              // 'i' here will try all permutations.
              // in case 0 add to group 1 else add to group 2
              ll g1 {}, g2 {};
              for(int i {}; i < n; ++i) 
                     if((mask>>i) & 1) // group 1
                            g1 += apples[i];
                     else g2 += apples[i];
              
              diff = min(diff, abs(g1 - g2));
       }

       cout << diff << endl;
}
 
signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
              freopen("output.txt", "w", stdout);
       #endif
       Fast

       testCase();
       return 0;
}