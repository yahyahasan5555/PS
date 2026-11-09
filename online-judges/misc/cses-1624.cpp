// https://cses.fi/problemset/task/1624
// Topic: Rescursion - N-Queens problem

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

constexpr int N {8};
// free cell = true, otherwise false
vector<vector<bool>> free_cell(N, vector<bool>(N));
vector<int> rows(N), cols(N), main_diagonal(2*N), anti_diagonal(2*N);

bool valid(int r, int c) {
       return !rows[r] &&
              !cols[c] &&
              !main_diagonal[r - c + N] &&
              !anti_diagonal[r + c] &&
              free_cell[r][c];
}

int n_queens(int r = 0, int c = 0, int queens = 0) {
       if(r == N)
              return queens == N;
       if(c == N)
              return n_queens(r + 1, 0, queens);

       // To choices: 
       // 1, take if valid:
       int ans {}; 
       if(valid(r, c)) {
              rows[r] = cols[c] = main_diagonal[r - c + N] = anti_diagonal[r + c] = true; 
              ans += n_queens(r + 1, 0, queens + 1);
              rows[r] = cols[c] = main_diagonal[r - c + N] = anti_diagonal[r + c] = false;  
       }
       
       // 2. leave:
       return ans + n_queens(r, c + 1, queens);       
}


void testCase(void) {
       char c;
       for(int i {}; i < N; ++i)
              for(int j {}; j < N; ++j)
                     cin >> c, 
                     free_cell[i][j] = c == '.' ? true : false;

       cout << n_queens() << endl;
}
 
signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast
 
 
       testCase();
       return 0;
}