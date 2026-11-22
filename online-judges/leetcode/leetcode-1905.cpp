// https://leetcode.com/problems/count-sub-islands/
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
private:
       const int dir_rows[4] {1, -1, 0, 0};
       const int dir_cols[4] {0, 0, 1, -1};
       
       static bool is_valid(int r, int c, const vvi& grid) {
              return r >= 0 && r < (int) grid.size() && c >= 0 && c < (int) grid[0].size();
       } 

       bool dfs(int r, int c, vvi& g1, vvi& g2) {
              // I use the original array to mark as visited array.
              if(!is_valid(r, c, g2) || g2[r][c] == 0)
                     return true;

              if(g2[r][c] && !g1[r][c])   
                     return false;

              g2[r][c] = 0; // mark as visited
              bool ans {true};
              for(int d {}; d < 4; ++d)
                     ans &= dfs(r + dir_rows[d], c + dir_cols[d], g1, g2);
              
              return ans;
       }
public:
       int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
              int sz {(int) grid2.size()};      
              int count {};
              for(int r {}; r < sz; ++r) 
                     for(int c {}; c < (int) grid2[0].size(); ++c) 
                            if(grid2[r][c] == 1)
                                   count += dfs(r, c, grid1, grid2);
                     
              return count;
       }
};