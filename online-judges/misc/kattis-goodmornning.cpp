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

// Preprocessing all the cases, then binary search on each case.
vector<vector<int>> vec {
       {1, 2, 3},
       {4, 5, 6},
       {7, 8, 9},
       {-1, 0, -1}
};

set<int> s;

void collect(int r, int c, int sum) {
       if(r > 3 || c > 2 || vec[r][c] == -1 || sum >= 200) {
              s.insert(sum);
              return;
       }

       // leave to right:
       collect(r, c + 1, sum);
       
       // leave to down:
       collect(r + 1, c, sum);

       // take then --> to right
       collect(r, c + 1, sum * 10 + vec[r][c]);

       // take then --> to down
       collect(r + 1, c, sum * 10 + vec[r][c]);

       // Take it many times:
       if(sum || vec[r][c]) collect(r, c, sum * 10 + vec[r][c]);
}

void testCase(void) {
       int k; cin >> k;

       // while k > 0 and 0 is already in the set,
       // then no need to ckeck if current iterator = begin or not (always not).
       // The same with it = end (always no, because max k = 200)
       auto it {s.lower_bound(k)};
       if(*it == k) return void(cout << k << '\n');

       int upper {*it};
       
       --it;
       int lower {*it};

       if(abs(upper - k) < abs(lower - k)) cout << upper << '\n';
       else cout << lower << '\n';

}

signed main() {
       Fast

       collect(0, 0, 0);
       int t; cin >> t; while(t--)
       testCase();
       return 0;
}