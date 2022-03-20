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
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         postorderTraversal(root, res);
//         return res;
//     }
//     void postorderTraversal(TreeNode* root, vector<int>& res) {
//         if (root == nullptr) {
//             return;
//         }
//         postorderTraversal(root->left, res);
//         postorderTraversal(root->right, res);
//         res.emplace_back(root->val);
//     }
// };

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            if (root->right == nullptr || root->right == pre) {
                res.emplace_back(root->val);
                stk.pop();
                pre = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return res;
    }
};
