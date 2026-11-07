//https://leetcode.com/problems/cousins-in-binary-tree/
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
       TreeNode* get_parent(TreeNode* root, int child) {
              if(!root) return root; // null
              if(    root->left && (root->left->val == child) ||
                     root->right && (root->right->val == child))
                     return root; // the parent

              auto left_parent {get_parent(root->left, child)}, right_parent {get_parent(root->right, child)};
              return (left_parent == nullptr && right_parent == nullptr) ? nullptr : left_parent ? left_parent : right_parent;
       }
       
       int get_node_depth(TreeNode* root, int node_val, int cur_depth = 0) {
              if(!root) return 0;

              if(node_val == root->val) return cur_depth;
              int left_depth {get_node_depth(root->left, node_val, cur_depth+1)};
              return (left_depth? left_depth : get_node_depth(root->right, node_val, cur_depth+1));
       }

       bool isCousins(TreeNode* root, int x, int y) {
              TreeNode* parent_x {get_parent(root, x)};
              TreeNode* parent_y {get_parent(root, y)};
              if(parent_x == parent_y) return false;

              return get_node_depth(root, x) == get_node_depth(root, y);
       }
};