// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Topic: Binary Search.

using ll = long long;

class Solution {
    // O(n) Time, O(1) space
    static bool possible(int num_days, int m, int k, vector<int>& bloom) {
        int bouquets {}, cur_flower {};
        for(int x: bloom) {
            if(x <= num_days) ++cur_flower;
            else cur_flower = 0;

            if(cur_flower == k) ++bouquets, cur_flower = 0;
            if(bouquets == m) return true;
        } 
        
        return false;
    } 
public:
    // O(n log max_element) time, O(1) extra space
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((ll) m * k > (int) bloomDay.size()) return -1;

        int l {1}, r {*max_element(bloomDay.begin(), bloomDay.end())}, mid, ans {};
        while(l <= r) {
            mid = l + (r - l) / 2;

            if(possible(mid, m, k, bloomDay))
                ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};
