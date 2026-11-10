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

vector<bool> taken(17); // initially 'False'
vector<int> cur;
int n;

bool is_prime(int n) {
       if(n <= 1) return false;
       for(int i {2}; i * i <= n; ++i)
              if(n % i == 0)
                     return false;
       return true;
}

void go(int i, int last) {
       if(i == n) {
              if(is_prime(last + 1)) {
                     for(int x: cur) {
                            cout << x;
                            if(x != cur.back()) cout << ' ';
                     }  cout << endl;
              } 

              return;
       }

       for(int j {1}; j <= n; ++j) {
              if(!taken[j] && is_prime(j + last)) {
                     taken[j] = true;
                     cur.pb(j);

                     go(i+1, j);

                     taken[j] = false;
                     cur.pop_back();
              }
       }
}

void testCase(void) {
       int tc {1};
       while(cin >> n) {
              if(tc != 1) cout << endl;
              cout << "Case " << tc++ << ":\n";

              taken.assign(n+1, false);

              taken[1] = true;
              cur.pb(1);
              go(1, 1);
              taken[1] = false;
              cur.pop_back();
       }
}

signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast


       testCase();
       return 0;
}