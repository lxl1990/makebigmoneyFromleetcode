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
 1、recursion
    for each node, we return the length of sampe path begin with node;
    leftLength = dfs(left)
    rightLength = dfs(right)
    ret = 1 + max(left == root ? leftlength : 0, right == root ? rightLength : 0)
    and update the longestUnivaluePath val;
 2、Iteration
    postorder traversal
    push the tuple of node and its length of longest path begin with itself
*/

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        stack<tuple<TreeNode*, int>> stk;
        TreeNode* pre = nullptr;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push({root, 1});
                root = root->left;
            }
            auto [node, samelen] = stk.top();
            if (node->right == nullptr || node->right == pre) {
                stk.pop();
                pre = node;
                ans = max(ans, samelen - 1);
                if (!stk.empty()) {
                    auto& [pointer, tosamelen] = stk.top();
                    if (node->val == pointer->val) {
                        ans = max(ans, samelen + tosamelen - 1);
                        tosamelen = max(tosamelen, samelen + 1);
                    }
                }
                root = nullptr;
            } else {
                root = node->right;
            }
        }
        return ans;
    }
};
