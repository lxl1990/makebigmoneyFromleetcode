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
//     bool isSymmetric(TreeNode* root) {
//         return isSymmetric(root, root);
//     }
//     bool isSymmetric(TreeNode* root1, TreeNode* root2) {
//         if(root1 == nullptr && root2 == nullptr) {
//             return true;
//         }
//         if (root1 == nullptr || root2 == nullptr) {
//             return false;
//         }
//         return root1->val == root2->val && isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
//     }
// };
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root);
        que.push(root);
        while (!que.empty()) {
            TreeNode* cur1 = que.front();
            que.pop();
            TreeNode* cur2 = que.front();
            que.pop();
            if (cur1 == nullptr && cur2 == nullptr) continue;
            if (cur1 == nullptr || cur2 == nullptr) return false;
            if (cur1->val != cur2->val) return false;
            que.push(cur1->left);
            que.push(cur2->right);
            que.push(cur1->right);
            que.push(cur2->left);
        }
        return true;
    }
};
