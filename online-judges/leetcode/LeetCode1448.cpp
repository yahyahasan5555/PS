// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
       // We'll add more parameter for gives us a missing info. (maximum node value so far.)
       // We can instead of edit of the LeetCode function rename our function then call it inside LeetCode's one.
       int goodNodes(TreeNode* root, int greater_so_far = INT_MIN) {
              if(!root) return 0;

              int left_branch_good_nodes {goodNodes(root->left, max(greater_so_far, root->val))};
              int right_branch_good_nodes {goodNodes(root->right, max(greater_so_far, root->val))};
              return left_branch_good_nodes + right_branch_good_nodes + (root->val >= greater_so_far);
       }
};