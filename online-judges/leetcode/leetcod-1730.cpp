
// https://leetcode.com/problems/shortest-path-to-get-food/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
       const int dr[4] {-1, 1, 0, 0};
       const int dc[4] {0, 0, -1, 1};

       static bool is_valid(int r, int c, vector<vector<char>>& mat) {
              return r >= 0 && r < (int) mat.size() && c >= 0 && c < mat[0].size();
       }

       int bfs(vector<vector<char>>& mat, int sr, int sc) {
              if(mat[sr][sc] == '#')
                     return 0;  // the shortest path's length = 0

              vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size()));
              queue<int> rows, cols;
              
              rows.push(sr), cols.push(sc);
              visited[sr][sc] = true;
              
              int level {};
              int sz {1};

              while(!rows.empty()) {
                     while(sz--) {
                            int cur_r {rows.front()}; rows.pop();
                            int cur_c {cols.front()}; cols.pop();

                            for(int d {}; d < 4; ++d) {
                                   int new_r {cur_r + dr[d]}, new_c {cur_c + dc[d]};

                                   if(is_valid(new_r, new_c, mat) && !visited[new_r][new_c] && mat[new_r][new_c] != 'X') {
                                          if(mat[new_r][new_c] == '#') {
                                                 return level + 1;
                                          }

                                          rows.push(new_r);
                                          cols.push(new_c);
                                          visited[new_r][new_c] = true;
                                   }
                            }              
                     }
                     
                     ++level;
                     sz = rows.size();
              }
              return -1;
       }
public:
       int getFood(vector<vector<char>> &matrix) {
              int rows {(int) matrix.size()}, cols {(int) matrix[0].size()};

              for(int r {}; r < rows; ++r)
                     for(int c {}; c < cols; ++c)
                            if(matrix[r][c] == '*')
                                   return bfs(matrix, r, c);

              return -1;
       }
};

void test_case(void) {
       vector<vector<char>> vec  {
              {'X', 'X', 'X', 'X', 'X', 'X'},
              {'X', '*', '0', '0', '0', 'X'},
              {'X', '0', '0', '#', '0', 'X'},
              {'X', 'X', 'X', 'X', 'X', 'X'}
       };

       cout << Solution().getFood(vec) << endl;
}

int main() {
       test_case();
       return 0;
}
