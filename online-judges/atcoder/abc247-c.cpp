// https://atcoder.jp/contests/abc247/tasks/abc247_c?lang=en
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

vector<int> get_order(int n) {
       if(n == 1) 
              return {1};
       
       
       auto left {get_order(n - 1)};
       int sz {(int) left.size()};
       
       left.pb(n);
       for(int i {sz - 1}; i >= 0; --i)
              left.pb(left[i]);

       return left;
} 

void testCase(void) {
       int n; cin >> n;

       print(get_order(n));
}
 
signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast
 
 
       testCase();
       return 0;
}