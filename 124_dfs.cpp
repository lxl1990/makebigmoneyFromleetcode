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

/*
    递归函数返回包含自身节点的单路径和；但递归的同时，更新最大路径和
*/
class Solution {
private:
    int ans = 1 << 31;
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        maxPatialSum(root);
        return ans;
    }
    int maxPatialSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_max = maxPatialSum(root->left);
        int right_max = maxPatialSum(root->right);
        ans = max(ans, root->val + max(left_max, 0) + max(right_max, 0));
        return root->val + max(max(left_max, right_max), 0);
    }
};
