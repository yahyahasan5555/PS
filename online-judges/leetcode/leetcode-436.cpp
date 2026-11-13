// https://leetcode.com/problems/find-right-interval/
// Topic: Binary Search.

class Solution {
        // Time: O(log n)
        // Space: O(1)
        static int get_small_j_idx(vector<vector<int>>& intervals, int target) {
              int st {}, end {(int) intervals.size() - 1}, mid, ans {-1};
              while(st <= end) {
                     mid = st + (end - st) / 2;
                     if(intervals[mid][0] >= target)
                            ans = mid, end = mid - 1;
                     else st = mid + 1;
              }

              return ans;
       }

public:
        // Time: O(n log n)
        // space: O(n) extra space for result array.
       static vector<int> findRightInterval(vector<vector<int>>& intervals) {
              int sz {(int) intervals.size()};

              for(int i {}; i < sz; ++i)
                     intervals[i].push_back(i);
              
              sort(intervals.begin(), intervals.end());

              vector<int> res(sz);
              for(int i {}; i < sz; ++i) {
                     int j = get_small_j_idx(intervals, intervals[i][1]);

                     if(j != -1) j = intervals[j][2];
                     res[intervals[i][2]] = j;   
              }

            //   print(res);
              return res;
       }
};
