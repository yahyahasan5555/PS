// https://leetcode.com/problems/valid-triangle-number/
class Solution {
public:
       // Time: O(n ^ 2)
       // Space: O(1) extra, sorting in place, 
       // while std::sort take O(log n) space of stack calls but i ignored it.
       static int triangleNumber(vector<int>& nums) {
              sort(nums.begin(), nums.end());

              int sz {(int) nums.size()}, cnt {};
              for(int i {sz - 1}; i >= 2; --i) {
                     int k {i - 1};
                     int j {};

                     while(j < k) {
                            if(nums[i] < nums[j] + nums[k])
                                   cnt += k - j, --k;
                            else ++j;
                     }
              } 
              
              return cnt;
       }
};