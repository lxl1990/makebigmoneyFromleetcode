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
    每个节点返回以该节点为起始节点的，最长连续序列；
 */
// class Solution {
// private:
//     int ans = 1;
// public:
//     int longestConsecutive(TreeNode* root) {
//         if (root == nullptr) return 0;
//         helper(root);
//         return ans;  
//     }
//     int helper(TreeNode* root) {
//         if (root == nullptr) return 0;
//         int leftmax = helper(root->left);
//         int rightmax = helper(root->right);
//         // cout << "root: " << root->val << ", leftmax: " << leftmax << ",rightmax: " << rightmax << endl;
//         int ret = 1;
//         if (root->right != nullptr && root->right->val == root->val + 1) {
//             ans = max(ans, rightmax + 1);
//             ret = max(ret, rightmax + 1);
//         }
//         if (root->left != nullptr && root->left->val == root->val + 1) {
//             ans = max(ans, leftmax + 1);
//             ret = max(ret, leftmax + 1);
//         }
//         return ret;
//     }
// };


class Solution
{
public:
    int longestConsecutive(TreeNode *root)
    {
        dfs(root, nullptr, 1);
        return sum;
    }
    int sum=1;
    //sum初始为1 ，边界情况只有一个根节点的情况。
    void dfs(TreeNode *root, TreeNode *p, int cnt)
    {
        if (!root)
            return;
        if (p)
        {
            if (p->val + 1 == root->val)
                cnt++;
            else
                cnt = 1;
            if (cnt > sum)
                sum = cnt;
        }
        dfs(root->left, root, cnt);
        dfs(root->right, root, cnt);
    }
};
