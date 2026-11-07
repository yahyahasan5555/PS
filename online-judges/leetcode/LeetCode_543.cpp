// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int max_so_far {};
public:
    int max_depth(TreeNode* root) {
        if(!root) return 0;
        
        int left {max_depth(root->left)}, right {max_depth(root->right)};
        max_so_far = max(max_so_far, left+right);
        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        max_so_far = 0;
        max_depth(root);
        return max_so_far;
    }
};