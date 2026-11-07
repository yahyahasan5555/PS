// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
       bool is_leaf(TreeNode* node) const { // O(1) time and memory
              return node && !node->left && !node->right;
       }

       bool isCompleteTree(TreeNode* root) { // O(n) time and memory complexity
              if(!root) return true;

              queue<TreeNode*> q;
              q.push(root);

              bool still_works {true};
              while(!q.empty()) {
                     int siz {(int)q.size()};
                     
                     while(siz--) {
                            auto cur {q.front()};
                            q.pop();

                            if(!is_leaf(cur) && !still_works || !cur->left && cur->right)
                                   return false; // Not complete;

                            if(cur->left) q.push(cur->left);
                            else still_works = false;

                            if(cur->right) q.push(cur->right);
                            else still_works = false;
                     }
              }
              return true;
       }
};