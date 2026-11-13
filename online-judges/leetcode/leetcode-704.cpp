// https://leetcode.com/problems/binary-search/
// Time: O(log n)
// Space: (1)
class Solution {
public:
    static int search(vector<int>& nums, int target) {
        int l {}, r {(int) nums.size() - 1}, mid, ans {};
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(nums[mid] >= target)
                ans = mid, r = mid - 1;
            else l = mid + 1;
        }

        return nums[ans] == target ? ans : -1;
    }
};
