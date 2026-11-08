// https://leetcode.com/problems/arranging-coins/

// Time: O(log n)
// Space: O(1).
// Topic: Binary Search.
using ll = long long;

class Solution {
public:
    static bool isValidCoins(int n, int cur) {
        return ((ll)cur * (cur + 1)) / 2 <= n; 
    }

    static int arrangeCoins(int n) {
        int l {}, r {n}, mid, ans {};
        while(l <= r) {
            mid = l + (r - l) / 2;
              if(isValidCoins(n, mid))
                    ans = mid, l = mid + 1;
              else r = mid - 1;
        } return ans;
    }
};