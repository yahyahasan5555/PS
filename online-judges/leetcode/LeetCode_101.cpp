// https://leetcode.com/problems/symmetric-tree/

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
       bool isSymmetric(TreeNode* root) {
              return isSymmetric(root->left, root->right);
       }

       // Think like 'preorder-traversal'
       bool isSymmetric(TreeNode* left, TreeNode* right) const { // O(n) time
              if(!left && !right) return true;

              // there is one sub-tree only, or different values.
              if(left && !right || right && !left || left->val != right->val) return false;

              // 2 trees 'll 've 4 sub-trees, so we need to make sure of 2 mirroring
              return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
       }
};