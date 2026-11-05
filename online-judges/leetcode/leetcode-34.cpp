// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Time: O(log n)
// Space: O(1)
class Solution {
public:
       static vector<int> searchRange(vector<int>& nums, int target) {
              auto it {lower_bound(nums.begin(), nums.end(), target)};
              if(it == nums.end() || nums[(int)(it - nums.begin())] != target)
                     return {-1, -1};

              auto it2 {upper_bound(nums.begin(), nums.end(), target)};
              return {(int)(it - nums.begin()), (int)(it2 - nums.begin()) - 1};
       }
};