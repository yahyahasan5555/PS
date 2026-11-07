//https://leetcode.com/problems/path-sum/

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

       bool hasPathSum(TreeNode* root, int targetSum, int sum_so_far = 0) const { // O(n) time and memory
              if(!root) 
                     return false;

              sum_so_far += root->val;

              if(is_leaf(root))
                     return targetSum == sum_so_far;

              return hasPathSum(root->left, targetSum, sum_so_far) || hasPathSum(root->right, targetSum, sum_so_far);
       }
};