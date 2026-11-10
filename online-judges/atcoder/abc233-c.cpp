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

#define int ll

int n, x;
vector<vector<int>> bags;

// calculate the number of multipliers ball = x
int go(int bag_idx = 0, int mul = 1) {
       if(mul > x)
              return 0;
       if(bag_idx == n) {
              return mul == x;
       }

       int cnt {};
       for(int ball: bags[bag_idx]) {
             cnt += go(bag_idx + 1, mul * ball);
       } return cnt;
}

void testCase(void) {
       cin >> n >> x;
       bags.resize(n, vector<int>());
       for(int bag {}; bag < n; ++bag) {
              int balls; cin >> balls;
              bags[bag].resize(balls);
              read(bags[bag]);
       }

       cout << go() << endl;
}

signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast


       testCase();
       return 0;
}