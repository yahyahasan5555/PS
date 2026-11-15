// This is version one for the answer
// Time: O(n)
// Space: O(1)
// Link: https://leetcode.com/problems/missing-element-in-sorted-array/

#include<bits/stdc++.h>

#define Fast                ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define print(v)            for(auto& x: v) cout << x << ' '; cout << endl;
#define read(v)             for(auto& x: v) cin >> x;
#define sz(v)               ((int)((v).size()))
#define all(v)              ((v).begin()), ((v).end())
#define pb                  push_back
#define cout(x)             cout << (x) << '\n'

//    /\_/\
//   (= ._.)
//   / >  \>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
       int missingElement(vector<int>& nums, int k) {
              int cnt {}; int idx {1}, sz {(int) nums.size()};
              while(idx < sz) {
                     int missing = nums[idx] - nums[idx - 1] - 1;

                     if(cnt + missing >= k) 
                            return nums[idx - 1] + (k - cnt);                     

                     cnt += missing;
                     ++idx;
              } 

              return nums.back() + k - cnt;
       }
};

void testCase(void) {
       // cout(Solution().missingElement({4, 7, 9, 10}, 1));
       // cout(Solution().missingElement({4, 7, 9, 10}, 3));
       // cout(Solution().missingElement({1, 2, 4}, 3));
       // cout(Solution().missingElement({3, 10, 11, 20}, 4));
}

signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast


       testCase();
       return 0;
}