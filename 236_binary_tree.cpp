/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* common1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* common2 = lowestCommonAncestor(root->right, p, q);
        if (common1 != nullptr && common2 != nullptr) return root;
        if (common1 == nullptr) return common2;
        if (common2 == nullptr) return common1;
        return nullptr;
    }
};
