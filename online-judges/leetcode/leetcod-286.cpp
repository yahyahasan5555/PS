#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
       static bool valid(int r, int c, int rows, int cols) {
              return r >= 0 && r < rows && c >= 0 && c < cols;
       }
public:
       void wallsAndGates(vector<vector<int>>& rooms) {
              // BFS Multiple sources:
              queue<int> qr, qc;

              // multi-sources:
              int rows {(int) rooms.size()}, cols {(int) rooms[0].size()};
              for(int r {}; r < rows; ++r) 
                     for(int c {}; c < cols; ++c) 
                            if(rooms[r][c] == 0)
                                   qr.push(r), qc.push(c);
              
              vector<vector<bool>> vis(rows, vector<bool>(cols));
              int level {};

              const int dr[4] {1, -1, 0, 0};
              const int dc[4] {0, 0, -1, 1};
              const int INF {2147483647};

              while(!qr.empty()) {
                     int sz {(int) qr.size()};
                     while(sz--) {
                            int r {qr.front()}, c {qc.front()};
                            qr.pop(), qc.pop();

                            // there are 4 children
                            for(int d {}; d < 4; ++d) {
                                   int new_r {r + dr[d]}, new_c {c + dc[d]};
                                  
                                   if(valid(new_r, new_c, rows, cols) && rooms[new_r][new_c] != -1 && !vis[new_r][new_c]) {
                                          if(rooms[new_r][new_c] == INF) // first visit
                                                 rooms[new_r][new_c] = level + 1;

                                          qr.push(new_r), qc.push(new_c);
                                          vis[new_r][new_c] = true;
                                   }
                            }
                     }
                     ++level;
              }
       }
};

void test_case(void) {
       vector<vector<int>> vec {
              {2147483647, -1,0, 2147483647}, 
              {2147483647, 2147483647, 2147483647,-1},
              {2147483647,-1,2147483647,-1},
              {0, -1, 2147483647, 2147483647}
       };
       Solution().wallsAndGates(vec);

       for(auto& vecc: vec) {
              for(int x: vecc) cout << x << ' ';
              cout << endl;
       }
       

}

int main() {
       test_case();
       return 0;
}
