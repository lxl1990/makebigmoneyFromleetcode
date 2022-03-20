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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum - root->val == 0;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};


// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if (root == nullptr) return false;
//         //前序遍历
//         stack<TreeNode*> stk;
//         TreeNode* pre = nullptr;
//         while (root != nullptr || !stk.empty()) {
//             while (root != nullptr) {
//                 stk.push(root);
//                 targetSum -= root->val;
//                 // std::cout << "push: " << root->val << ", cur_tar: " << targetSum << "\n";
//                 root = root->left;
//             }
//             root = stk.top();
//             if (root->right == nullptr || root->right == pre) {
//                 if (root->right == nullptr && root->left == nullptr && targetSum == 0) return true;
//                 targetSum += root->val;
//                 // std::cout << "pop: " << root->val << ", cur_tar: " << targetSum << "\n";
//                 pre = root;
//                 root = nullptr;
//                 stk.pop();
//             } else {
//                 root = root->right;
//             } 
//         }
//         return false;
//     }
// };
