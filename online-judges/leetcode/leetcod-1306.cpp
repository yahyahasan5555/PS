// https://leetcode.com/problems/jump-game-iii/
// O(N) time and memory
class Solution {
private:
       static bool is_valid(int idx, int n) {
              return idx >= 0 && idx < n;
       }

       bool bfs_can_reach(vector<int>& arr, int start) const {
              if(arr[start] == 0)  
                     return true; // special case.

              int sz {(int) arr.size()};

              vector<bool> vis(sz); // initially falses
              queue<int> q;

              q.push(start);
              vis[start] = true; 

              while(!q.empty()) {
                     int cur {q.front()};
                     q.pop();

                     // there are 2 neighbors only:
                     int n1 {cur + arr[cur]}, n2 {cur - arr[cur]};
                     if(is_valid(n1, sz) && !vis[n1]) {
                            if(arr[n1] == 0) 
                                   return true;

                            q.push(n1);
                            vis[n1] = true;
                     }

                     if(is_valid(n2, sz) && !vis[n2]) {
                            if(arr[n2] == 0) 
                                   return true;

                            q.push(n2);
                            vis[n2] = true;
                     }
              }
              return false;
       }
public:
    bool canReach(vector<int>& arr, int start) {
       return bfs_can_reach(arr, start);
    }
};