// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
       vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
              /* For code this problem:
               * lets imagine we need one level proceeded with a normal queue
               * but it's next level proceeded with a stack (reverse left with right nodes in both push and pop proceses)
               * so the dequeue data structure will be perfect, 
               * cause it's allows both proceses easily (stack + queue).
               * The time complexcity analysis: O(n).
               */

              vector<vector<int>> res;
              deque<TreeNode*> dq;

              if(!root) // root == nullptr
                     return res;

              dq.push_back(root);
              bool forward_level {true};

              while(!dq.empty()) {
                     int sz {(int)dq.size()};
                     vector<int> cur_level;
                     TreeNode* cur {};

                     while(sz--) {
                            if(forward_level) { // Generate from front:
                                   // Usual queue style: pop from queue front, push in queue rear, left then right:
                                   cur = dq.front();
                                   dq.pop_front();

                                   if(cur->left) dq.push_back(cur->left);
                                   if(cur->right) dq.push_back(cur->right);
                            } else {
                                   // Reversed step (like a stack)
                                   // pop from stack end, push into stack front, right then left.
                                   cur = dq.back();
                                   dq.pop_back();

                                   if(cur->right) dq.push_front(cur->right);
                                   if(cur->left) dq.push_front(cur->left);
                            }
                            cur_level.push_back(cur->val);
                     } 
                     res.push_back(cur_level);
                     forward_level = !forward_level;
              }
              return res;
       }      
};q