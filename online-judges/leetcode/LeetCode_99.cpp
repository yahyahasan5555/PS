#include <bits/stdc++.h>
using namespace std;

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
private:
       void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
              if(!root) return;
              inorder(root->left, nodes);
              nodes.push_back(root);
              inorder(root->right, nodes);
       } 

public:

       void recoverTree(TreeNode* root) {
              vector<TreeNode*> vec;
              inorder(root, vec);

              TreeNode *mn {nullptr}, *mx {nullptr};
              for(int i {1}; i < (int) vec.size(); ++i) {
                     if(vec[i]->val < vec[i-1]->val) {
                            if(!mn) 
                                   mn = vec[i], mx = vec[i-1];
                            else {
                                   mn = vec[i];
                                   break;
                            }
                     }
              }

              swap(mn->val, mx->val);
       }
};

void testCase(void) {

}

signed main() {
       testCase();
       return 0;
}