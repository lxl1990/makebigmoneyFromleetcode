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
    return the length of path in two direction
    leftLen = f(root->left);
    rightLen = f(root->right);
    rootLen = (1 + leftLen[1], 1 + rightLen[0]) 
    后续调整思路，由后序改为前序，即将结果下传
*/

// class Solution {
// private:
//     int ans = 0;
// public:
//     int longestZigZag(TreeNode* root) {
//         dfs(root);
//         return ans;
//     }
//     vector<int> dfs(TreeNode* root) {
//         if (root == nullptr) {
//             return vector<int>{0, 0};
//         }
//         vector<int> leftLen = dfs(root->left);
//         vector<int> rightLen = dfs(root->right);
//         vector<int> ret(2, 0);
//         ret[0] = (1 + leftLen[1]);
//         ret[1] = (1 + rightLen[0]);
//         ans = max(ans, max(ret[0], ret[1]) - 1);
//         return ret;
//     }
// };

// class Solution {
// public:
//     unordered_map <TreeNode*, int> f, g;
    
//     queue <pair <TreeNode *, TreeNode *>> q;
    
//     void dp(TreeNode *o) {
//         f[o] = g[o] = 0;
//         q.push({o, nullptr});
//         while (!q.empty()) {
//             auto y = q.front(); q.pop();
//             auto x = y.second, u = y.first;
//             f[u] = g[u] = 0;
//             if (x) {
//                 if (x->left == u) f[u] = g[x] + 1;
//                 if (x->right == u) g[u] = f[x] + 1;
//             }
//             if (u->left) q.push({u->left, u});
//             if (u->right) q.push({u->right, u});
//         }
//     }
    
//     int longestZigZag(TreeNode* root) {
//         dp(root);
//         int maxAns = 0;
//         for (const auto &u: f) maxAns = max(maxAns, max(u.second, g[u.first]));
//         return maxAns;
//     }
// };


class Solution {
public:
    int maxAns;

    /* 0 => left, 1 => right */
    void dfs(TreeNode* o, bool dir, int len) {
        maxAns = max(maxAns, len);
        if (!dir) {
            if (o->left) dfs(o->left, 1, len + 1);
            if (o->right) dfs(o->right, 0, 1);
        } else {
            if (o->right) dfs(o->right, 0, len + 1);
            if (o->left) dfs(o->left, 1, 1);
        }
    } 

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        maxAns = 0;
        dfs(root, 0, 0);
        dfs(root, 1, 0);
        return maxAns;
    }
};
