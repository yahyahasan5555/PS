// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1285
// Topic: Backtracking.
// This is vecsion# 1 of the problem.

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

bool is_possible(unordered_multiset<int>& s, int sum) {
       if(s.empty())
              return sum == 23;

       vector<int> choices(s.begin(), s.end());
       for(int x: choices) {
             s.erase(s.find(x));
             
             if(is_possible(s, sum + x) || is_possible(s, sum * x) || is_possible(s, sum - x))
                     return true;
              
              s.emplace(x); // undo
       } return false;
}

void testCase(void) {
       while(true) {
              int arr[5];
              for(int& i: arr) {
                     cin >> i;
                     if(!i) return;
              }       


              bool ok {false};
              for(int i {}; i < 5; ++i) {
                     unordered_multiset<int> s;
                     for(int j {}; j < 5; ++j)
                            if(j != i) s.emplace(arr[j]);
                                          
                     ok |= is_possible(s, arr[i]);
                     if(ok) break;
              } cout << (ok ? "Possible" : "Impossible") << endl;
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