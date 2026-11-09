// https://codeforces.com/gym/102697/problem/107
// Codeforces: The man machine
// N-queen problem
// Topic: Backtrakong

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
 
const int N {11};
int n;
vector<bool> rows(N), cols(N), main_diagonal(2 * N), anti_diagonal(2 * N); // Initially falses.

bool valid(int r, int c) {
       return !rows[r] && !cols[c] && !main_diagonal[r - c + N] && !anti_diagonal[r + c];
}

int cnt {};
int n_queens(int cur_r, int cur_c, int queens) { ++cnt;
       if(cur_r == n) // out of the grid
              return queens == n;

       if(cur_c == n) 
              return n_queens(cur_r+1, 0, queens);

       
       int ans {};
       
       // Take, if valid:
       if(valid(cur_r, cur_c)) {
              rows[cur_r] = cols[cur_c] = main_diagonal[cur_r - cur_c + N] = anti_diagonal[cur_r + cur_c] = true;
              ans += n_queens(cur_r + 1, 0, queens + 1);
              rows[cur_r] = cols[cur_c] = main_diagonal[cur_r - cur_c + N] = anti_diagonal[cur_r + cur_c] = false;
       }

       // leave:
       return ans + n_queens(cur_r, cur_c + 1, queens);
}

void testCase(void) {
       cin >> n;
       cout << n_queens(0, 0, 0) << endl;
       cout << cnt ;
}
 
signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
              freopen("output.txt", "w", stdout);
       #endif
       Fast
 
 
       // int t; cin >> t; while(t--)
       testCase();
       return 0;
}