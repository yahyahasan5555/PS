// https://leetcode.com/problems/minimum-operations-to-convert-number/
class Solution {
private:
       bool is_valid(int idx) const {
              return idx >= 0 && idx <= 1000;
       }

       int bfs_op(vector<int>& nums, int start, int goal) {
              int num_sz {(int) nums.size()};

              vector<bool> vis(1001); // the range in [0, 1000] is 1001 number, distinct.
              queue<int> q;
              
              q.push(start);
              vis[start] = true;

              int level {};
              
              while(!q.empty()) {
                     int sz {(int) q.size()}; // current queue size
                     while(sz--) {
                            int cur {q.front()};
                            q.pop();

                            if(!is_valid(cur))
                                   continue;

                            // What if valid? do the 3 operations:
                            for(int x: nums) {
                                   int op1 {cur - x}, op2 {cur + x}, op3 {cur ^ x};
                                   if(op1 == goal || op2 == goal || op3 == goal)
                                          return level + 1;
                                   
                                   if(is_valid(op1)&& !vis[op1]) 
                                          vis[op1] = true, q.push(op1);
                                   
                                   if(is_valid(op2) && !vis[op2]) 
                                                 vis[op2] = true, q.push(op2);
                                   
                                   if(is_valid(op3) && !vis[op3]) 
                                                 vis[op3] = true, q.push(op3);
                            }
                     }
                     ++level;
              }
              return -1;
       }
public:
       int minimumOperations(vector<int>& nums, int start, int goal) {
              return bfs_op(nums, start, goal);
       }
};