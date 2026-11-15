// https://leetcode.com/problems/sqrtx/
using ll = long long;
class Solution {
public:
       // Time: O(log x)
       // Space: O(1) extra space
       int mySqrt(int x) {
              if(x <= 1) return x;
              // Searched for the first/smallest i where i*i > x
              ll l {}, r {x}, mid, ans {};
              while(l <= r) {
                     mid = l + (r - l) / 2;
                     if(mid * mid > x)
                            ans = mid, r = mid - 1;
                     else l = mid + 1;
              } 

              if(ans*ans == x) return ans;
              return ans - 1;
       }
};
