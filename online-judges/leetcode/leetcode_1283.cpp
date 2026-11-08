using ll = long long;

class Solution {

    // O(n) time, O(1) space.
    static pair<bool, int> possible(int divisor, vector<int>& vec, int threshold) {
        ll sum {};
        for(int num: vec) {
            sum += (num + divisor - 1) / divisor;

            if(sum > threshold) return {false, -1};
        }
        
        return {true, divisor};
    }
public:
    // O(n log r) time (r = MAX = 1e6), O(1) extra space
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l {1}, r {(int) 1e6+1}, mid, ans {};
    
        while(l <= r) {
            mid = l + (r - l) / 2;
        
            auto res {possible(mid, nums, threshold)};
            if(res.first)
                ans = res.second, r = mid - 1;
            else l = mid + 1;
        } 
        return ans;
    }
};
