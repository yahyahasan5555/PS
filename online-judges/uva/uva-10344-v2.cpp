// This is Version to of the problem (more easear answer):
// Time: about O(!n * 3^(n-1)) in case "Impossible" like the first case (all ones)
// Where is the number of n's fixed (5) the exactly number of calls = 13565 (in first test case).
// Note the above analysis is per one test case, 
// so the final complexity analysis is O(T . !n . 3^(n - 1)) time, O(n) extra space.
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

int arr[5];
bool taked[5];
int cnt; // for count number of calls in worst case
bool possible(int sum, int num_of_taked) {
       // ++cnt;
       if(num_of_taked == 5) return sum == 23;

       for(int i {}; i < 5; ++i) {
              if(!taked[i]) { // take it:
                     taked[i] = true;
                    
                     if(    possible(sum + arr[i], num_of_taked + 1) || 
                            possible(sum * arr[i], num_of_taked + 1) || 
                            possible(sum - arr[i], num_of_taked + 1)) 
                            return true;
                     
                     taked[i] = false;
              }
       } 
       return false;
}

void testCase(void) {
       while(true) {
              // Read the array:
              for(int i {}; i < 5; ++i) cin >> arr[i], taked[i] = false;
              if(!arr[0]) return;

              bool ok {false};
              for(int i {}; i < 5; ++i) {
                     taked[i] = true;
                     ok |= possible(arr[i], 1);
                     taked[i] = false;

                     if(ok) break;
              }

              cout << (ok ? "Possible" : "Impossible") << endl;
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