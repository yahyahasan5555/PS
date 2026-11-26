class Solution {
private:
       char next_dig(const char ch) const {
              return ch == '9'? '0' : ch + 1;
       }
       
       char prev_dig(const char ch) const {
              return ch == '0' ? '9' : ch - 1;
       }

       int bfs_operations(const string& target, unordered_map<string, bool> visited) {
              string start {"0000"};
              if(target == start)
                     return 0;

              queue<string> q;

              q.push(start);
              visited[start] = true;

              int level {};
              int sz {1};
              
              while(!q.empty()) {
                     while(sz--) {
                            string cur {q.front()};
                            q.pop();
                            cout << "CUR " << cur << endl;

                            // there are 8 neighbors:
                            for(int i {}; i < 4; ++i) {
                                   string next = cur;
                                   next[i] = next_dig(next[i]);
                                   if(!visited[next]) {
                                          if(next == target)
                                                 return level + 1;
                                          
                                          visited[next] = true;
                                          q.push(next);
                                   }

                                   string prev = cur;
                                   prev[i] = prev_dig(prev[i]);
                                   if(!visited[prev]) {
                                          if(prev == target)
                                                 return level + 1;

                                          visited[prev] = true;
                                          q.push(prev);
                                   }
                            }
                     }
                     sz = q.size();
                     ++level;
              }
              return -1;
       }
public:
       int openLock(vector<string>& deadends, const string& target) {
              unordered_map<string, bool> vis;
              for(const string& str: deadends)
                     vis[str] = true;

              return bfs_operations(target, vis);
       }
};