#include <bits/stdc++.h>
using namespace std;

// Convert a BST to a sorted DLL:

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
       // the first = head  && second = tail
       pair<TreeNode*, TreeNode*> convertToDLL(TreeNode* root) {
              if(!root) return make_pair(nullptr, nullptr);

              auto left {convertToDLL(root->left)};
              bool is_left {left.first && left.second};

              auto right {convertToDLL(root->right)};
              bool is_right {right.first && right.second};

              if(!is_left && !is_right) {
                     root->left = nullptr;
                     root->right = nullptr;
                     return make_pair(root, root);
              }

              if(!is_left) {
                     root->left = nullptr; // prev
                     root->right = right.first;
                     right.first->left = root;
                     return make_pair(root, right.second);
              }

              if(!is_right) {
                     root->right = nullptr; // next
                     root->left = left.second;
                     left.second->right = root;
                     return make_pair(left.first, root);
              }

              // else: there is a left and right:
              root->left = left.second;
              left.second->right = root;

              root->right = right.first;
              right.first->left = root;

              return make_pair(left.first, right.second);
       } 


	TreeNode* treeToDoublyList(TreeNode* root) {
		if (!root)
			return root;

		pair<TreeNode*, TreeNode*> dll = convertToDLL(root);
		// Make it circular
		dll.first->left = dll.second;
		dll.second->right = dll.first;

		return dll.first;
	}
};
