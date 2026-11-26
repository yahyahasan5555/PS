// https://leetcode.com/problems/stepping-numbers/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

class Solution {
private:

public:
       vector<int> countSteppingNumbers(ll low, ll high) {
              // there is no need to visited array cause each number has only one parent.
              // unordered_set<int> vis; 
              queue<ll> q;
              vector<int> res;
              if(low == 0) res.push_back(0);

              for(int i {1}; i <= 9; ++i)
                     q.push(i);

              while(!q.empty()) {
                     ll cur {q.front()};
                     q.pop();

                     if(cur > high) continue; // too high.
                     if(cur >= low) res.push_back(cur);

                     // has 2 neighbors (one time last_digit + 1, and the other -1):
                     int mod {(int) cur % 10};
                     if(mod != 0) q.push(cur * 10 + (mod - 1));
                     if(mod != 9) q.push(cur * 10 + (mod + 1));
              }
              
              // sort(res.begin(), res.end());
              return res;
       }
};

void test_case(void) {

       for(int x: Solution().countSteppingNumbers(100, 200))
              cout << x << ' ';
       cout << endl;
}

int main() {
       test_case();
       return 0;
}
