// https://leetcode.com/problems/course-schedule/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

class Solution {
public:
       bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
              Graph graph(numCourses);
              vector<int> in_degree(numCourses);

              for(auto& vec: prerequisites) {
                     // 2nd node points to the first one
                     // so first node has another in-degree
                     graph[vec[1]].push_back(vec[0]); // add directed edge from b to a
                     ++in_degree[vec[0]];
              }

              // DFS + Topological Sorting.
              queue<int> q; // put only the nodes with in-degree 0
              
              for(int node {}; node < numCourses; ++node)
                     if(!in_degree[node])
                            q.push(node);

              vector<int> res;
              while(!q.empty()) {
                     int cur {q.front()};
                     q.pop();

                     res.push_back(cur);

                     for(int neighbor: graph[cur])
                            if(in_degree[neighbor] > 0) // if 0, then its already putted and this is a cycle, will be detected later.
                                   if(!--in_degree[neighbor])
                                          q.push(neighbor);
              }

              return (int) res.size() == numCourses;
       }
};

void test_case(void) {
       int numCourses = 2;
       vector<vector<int>> prerequisites = {{1, 0}};

       cout << boolalpha;
       cout << Solution().canFinish(numCourses, prerequisites) << endl;
}

int main() {
       test_case();
       return 0;
}
