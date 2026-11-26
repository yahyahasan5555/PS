
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
private:
       const int dr[4] {-1, 1, 0, 0};
       const int dc[4] {0, 0, -1, 1};
       
       static bool valid(int r, int c, int rows, int cols) {
              return r >= 0 && r < rows && c >= 0 && c < cols;
       }

public:
       vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
              int rows {(int) heights.size()}, cols {(int) heights[0].size()};
              
              vector<vector<bool>> vis1(rows, vector<bool>(cols));
              queue<int> qr, qc;
              for(int r {}; r < rows; ++r) 
                     qr.push(r), qc.push(cols - 1), vis1[r][cols - 1] = true;
              for(int c {}; c < cols - 1; ++c)
                     qr.push(rows - 1), qc.push(c), vis1[rows - 1][c] = true;

              while(!qr.empty()) {
                     int r {qr.front()}, c {qc.front()};
                     qr.pop(), qc.pop();

                     for(int d {}; d < 4; ++d) {
                            int new_r {r + dr[d]}, new_c {c + dc[d]};
                            if(valid(new_r, new_c, rows, cols) && heights[new_r][new_c] >= heights[r][c] && !vis1[new_r][new_c]) {
                                   vis1[new_r][new_c] = true;
                                   qr.push(new_r), qc.push(new_c);
                            }
                     }
              }
              
              // -------------BFS 2------
              vector<vector<bool>> vis2(rows, vector<bool>(cols));
              queue<int> qr2, qc2;
              
              for(int r {1}; r < rows; ++r) 
                     qr2.push(r), qc2.push(0), vis2[r][0] = true;
              for(int c {}; c < cols; ++c)
                     qr2.push(0), qc2.push(c), vis2[0][c] = true;

              while(!qr2.empty()) {
                     int r {qr2.front()}, c {qc2.front()};
                     qr2.pop(), qc2.pop();

                     for(int d {}; d < 4; ++d) {
                            int new_r {r + dr[d]}, new_c {c + dc[d]};
                            if(valid(new_r, new_c, rows, cols) && heights[new_r][new_c] >= heights[r][c] && !vis2[new_r][new_c]) {
                                   vis2[new_r][new_c] = true;
                                   qr2.push(new_r), qc2.push(new_c);
                            }
                     }
              }

              vector<vector<int>> res;
              for(int r {}; r < rows; ++r) 
                     for(int c {}; c < cols; ++c) 
                            if(vis1[r][c] && vis2[r][c]) 
                                   res.push_back({r, c});  
              return res;
       }
};

void test_case(void) {
       vector<vector<int>> heights = {
              {1, 2, 2, 3, 5}, 
              {3, 2, 3, 4, 4}, 
              {2, 4, 5, 3, 1}, 
              {6, 7, 1, 4, 5}, 
              {5, 1, 1, 2, 4}
       };

       auto vec {Solution().pacificAtlantic(heights)};
       for(auto& vecc: vec) {
              for(int x: vecc) cout << x << ' ';
              cout << endl;
       }
}

int main() {
       test_case();
       return 0;
}
