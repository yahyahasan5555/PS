// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
       TreeNode* _sortedArrayToBST(vector<int>& nums, int start_idx, int end_idx) {
              if(start_idx > end_idx) return nullptr;
              if(start_idx == end_idx) return new TreeNode(nums[start_idx]);

              int mid {(start_idx + end_idx) / 2}; // Integer division.
              
              TreeNode* root {new TreeNode(nums[mid])};
              root->left = _sortedArrayToBST(nums, start_idx, mid - 1);
              root->right = _sortedArrayToBST(nums, mid + 1, end_idx);
              return root;
       }

       TreeNode* sortedArrayToBST(vector<int>& nums) {
              return _sortedArrayToBST(nums, 0, (int)nums.size() - 1);
       }      
};



// // More slow solution is to convert the array into two physical arrays and copy the left ans right contents.
// TreeNode* sortedArrayToBST(vector<int>& nums) {
//        if(nums.empty()) return nullptr;
//        if(nums.size() == 1) return new TreeNode(nums.front());

//        int mid {(int)nums.size() / 2}; // integer division

//        vector<int> left_vec, right_vec;
//        for(int i {}; i < mid; ++i) left_vec.push_back(nums[i]);
//        for(int i {mid+1}; i < (int) nums.size(); ++i) right_vec.push_back(nums[i]);

//        TreeNode* root {new TreeNode(nums[mid])};
//        root->left = sortedArrayToBST(left_vec);
//        root->right = sortedArrayToBST(right_vec);
//        return root;
// }