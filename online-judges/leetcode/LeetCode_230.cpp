// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
       int kthSmallest(TreeNode* root, int k) {
              return kthSmallestHelper(root, k /*passed as a value so there is a copy here*/);
       }

       // The idea is to keep doing inorder traversal in the tree
	   // but maintain &k to know if you find it
	   // Order is O(n)
	   // The interesting inside idea is doing this partial inorder traversal
       int kthSmallestHelper(TreeNode* root, int& k) {
              if(!k) return -12345; // A dummy val represents that there's no answer (k).

              if(root->left) {
                     int res = kthSmallestHelper(root->left, k);
                     if(!k) return res;
              }

              --k; // count this root's val
              if(!k) return root->val;

              if(root->right) return kthSmallestHelper(root->right, k);
              return -12345; // Dummy              
       }
};