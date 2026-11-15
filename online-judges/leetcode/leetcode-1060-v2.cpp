// This is an optimized version
// Time: O(log n)
// Space: O(1) extra
// Topic: Binary Search
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
private:
       // Returns How many numbers are missing until nums[idx]
       int missing(int idx, vector<int>& nums) {
              return nums[idx] - nums[0] - idx;
       }

       // using the 'idx': return what's the kth missing number?
       int kth(int idx, vector<int>& nums, int k) {
              return nums[idx] + k - missing(idx, nums);     
       }
public:
       int missingElement(vector<int> nums, int k) {
              int sz {(int) nums.size()};

              if(k > missing(sz - 1, nums))
                     return kth(sz - 1, nums, k);

              int l {}, r {sz - 1}, mid, ans {-1};
              while(l <= r) {
                     mid = l + (r - l) / 2;
                     if(k <= missing(mid, nums))
                            ans = mid, r = mid - 1;     
                     else l = mid + 1;
              }

              // Use the prev idx to find the missing element:
              return kth(ans - 1, nums, k);
       }
};

void testCase(void) {
       cout(Solution().missingElement({4, 7, 9, 10}, 1));
       cout(Solution().missingElement({4, 7, 9, 10}, 3));
       cout(Solution().missingElement({1, 2, 4}, 3));
       cout(Solution().missingElement({3, 10, 11, 20}, 4));
       
}

signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast


       testCase();
       return 0;
}