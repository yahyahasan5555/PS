// https://leetcode.com/problems/flip-equivalent-binary-trees/

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
       string _parenthesize_canonical(TreeNode* root) const {
              if(!root) return "()";

              string res = "(" + to_string(root->val);
              
              vector<string> vec;

              if(root->left)       
                     vec.push_back(_parenthesize_canonical(root->left));
              else 
                     vec.push_back("()");

              if(root->right)      
                     vec.push_back(_parenthesize_canonical(root->right));
              else 
                     vec.push_back("()");

              sort(vec.begin(), vec.end());
              for(string& s: vec)
                     res += s;
              
              res += ")";
              return res;
       }
       bool flipEquiv(TreeNode* root1, TreeNode* root2) {
              //  This is a direct canonical problem!
              return _parenthesize_canonical(root1) == _parenthesize_canonical(root2);
       }
};