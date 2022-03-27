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
    递归：
        计算root左右节点的最大深度，更新ret为 max(ret, left_depth + right_depth);
        计算子节点深度的时候同时更新ret

 */
// class Solution {
// private:
//     int ret = 0;
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         if (root == nullptr) return 0;
//         int left_depth = depth(root->left);
//         int right_depth = depth(root->right);
//         ret = max(ret, left_depth + right_depth);
//         return ret;
//     }
//     int depth(TreeNode * root) {
//         if (root == nullptr) return 0;
//         int left_depth = depth(root->left);
//         int right_depth = depth(root->right);
//         ret = max(ret, left_depth + right_depth);
//         return 1 + max(left_depth, right_depth);
//     }
// };

class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};
