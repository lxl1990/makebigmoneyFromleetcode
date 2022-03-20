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
//     int sumNumbers(TreeNode* root) {
//         if (root == nullptr) return 0;
//         return sumNumbers(root, 0);
//     }
//     int sumNumbers(TreeNode* root, int val) {
//         val = root->val + 10 * val;
//         if (root->left == nullptr && root->right == nullptr) return val;
//         int ret = 0;
//         if (root->left != nullptr) {
//             ret += sumNumbers(root->left, val);
//         }
//         if (root->right != nullptr) {
//             ret += sumNumbers(root->right, val);
//         }
//         return ret;
//     }
// };

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        int ret = 0, val = 0;
        //后序遍历
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                val = 10 * val + root->val;
                root = root->left;
            }
            root = stk.top();
            if (root->right == nullptr || root->right == pre) {
                stk.pop();
                pre = root;
                if (root->right == nullptr && root->left == nullptr) {
                    ret += val;
                }
                val = (val - root->val) / 10;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return ret;
    }
};
