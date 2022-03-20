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
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == nullptr) {
//             return nullptr;
//         }
//         TreeNode* left = root->left;
//         TreeNode* right = root->right;
//         root->left = invertTree(right);
//         root->right = invertTree(left);
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            TreeNode* tmp = node->right;
            node->right = node->left;
            node->left = tmp;
            if (node->left != nullptr) {
                stk.push(node->left);
            }
            if (node->right != nullptr) {
                stk.push(node->right);
            }
        }
        return root;
    }
};
