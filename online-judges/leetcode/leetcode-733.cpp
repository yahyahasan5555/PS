class Solution {
private:
       int cnt {};
       const int dir_rows[4] = {1, -1, 0, 0};
       const int dir_cols[4] = {0, 0, 1, -1};

       static bool is_valid_pos(int r, int c, int rows, int cols) {
              return r >= 0 && r < rows && c >= 0 && c < cols;
       }

       void dfs(int r, int c, int color, int init_c, vector<vector<int>>& img) {
              // if this pos is not valid or visited before: go back!
              if(!is_valid_pos(r, c, (int) img.size(), (int) img[0].size()) || img[r][c] == color || img[r][c] != init_c)
                     return;

              img[r][c] = color;
              for(int d {}; d < 4; ++d) 
                     dfs(r + dir_rows[d], c + dir_cols[d], color, init_c, img);     
       }
public:
       vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
              int init_color {image[sr][sc]};
              dfs(sr, sc, color, init_color, image);
              return image;
       }
};

