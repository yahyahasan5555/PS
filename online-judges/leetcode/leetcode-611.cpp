// https://leetcode.com/problems/valid-triangle-number/

class Solution {
       // Time: O(log n), Space: O(1) extra space
       static int find_first_invalid_index(vector<int>& nums, int first_invalid_val) {
              //! Note: the array is sorted REVERSED.
              int l {}, r {(int) nums.size() - 1}, mid, ans {-1};
              while(l <= r) {
                     mid = l + (r - l) / 2;
                     if(nums[mid] <= first_invalid_val)
                            ans = mid, r = mid - 1;
                     else l = mid + 1;
              } return ans;
       }
public:
       // Time: O(n^2 log n), Space: O(1)
       static int triangleNumber(vector<int>& nums) {
              // The trivial way using 3 nested loops in O(N^3) time,
              // But we need more optimized ans.

              sort(nums.rbegin(), nums.rend());
              int sz {(int) nums.size()}, cnt {};

              for(int i {}; i < sz - 2; ++i) {
                     for(int j {i + 1}; j < sz - 1; ++j) {
                            if(nums[i] >= nums[j] + nums[j + 1]) 
                                   continue;

                            // lets found the first invalid number:
                            int invalid_idx {find_first_invalid_index(nums, nums[i] - nums[j])};
                            
                            if(invalid_idx == -1) invalid_idx = sz;
                            cnt += invalid_idx - (j + 1);
                     }
              } 

              return cnt;
       }
};