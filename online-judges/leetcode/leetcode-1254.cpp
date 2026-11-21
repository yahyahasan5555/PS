class Solution {
private:
       const int dir_rows[4] {1, -1, 0, 0};
       const int dir_cols[4] {0, 0, -1, 1};

       static bool is_valid(int r, int c, const vector<vector<int>>& grid) {
              return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
       }

       bool is_closed(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
              if(grid[r][c] == 1)
                     return true;

              vis[r][c] = true;

              // shouldn't be boundary
              bool closed {r != 0 && r != (int) grid.size() - 1 && c != 0 && c != (int) grid[0].size() - 1};

              for(int d {}; d < 4; ++d) {
                     int new_r {r + dir_rows[d]}, new_c {c + dir_cols[d]};
                     if(is_valid(new_r, new_c, grid) && !vis[new_r][new_c]) {

                            // we don't need to return at first false, to mark all this CC as visited before.
                            closed &= is_closed(new_r, new_c, vis, grid);
                     }  
              } 
              
              return closed;
       }
public:
       int closedIsland(vector<vector<int>>& grid) {
              int rows {(int) grid.size()}, cols {(int) grid[0].size()};

              vector<vector<bool>> visited(rows, vector<bool>(cols));
              int cnt_closed {};
              for(int r {}; r < rows; ++r)
                     for(int c {}; c < cols; ++c)
                            if(!visited[r][c] && !grid[r][c])
                                   cnt_closed += is_closed(r, c, visited, grid);
              
              return cnt_closed;
       }
};