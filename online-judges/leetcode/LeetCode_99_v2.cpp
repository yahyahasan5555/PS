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

// This version is an optimization version of the previous code
// to be in O(h) instead of O(n) Space (space - memory complexity).
class Solution {
private:
       TreeNode* predecessor {nullptr};
       TreeNode *mn {nullptr}, *mx {nullptr};
public:
       void select(TreeNode* pred, TreeNode* cur) {
              if(!this->mn) 
                     this->mn = cur, this->mx = pred;
              else this->mn = cur;
       }

       void inorder(TreeNode* root) {
              if(!root) return;
              
              inorder(root->left);

              if(predecessor && predecessor->val > root->val)
                     select(predecessor, root);
              
              predecessor = root;

              inorder(root->right);
       }

       void recoverTree(TreeNode* root) {
              inorder(root);
              swap(this->mn->val, this->mx->val);
       }

};