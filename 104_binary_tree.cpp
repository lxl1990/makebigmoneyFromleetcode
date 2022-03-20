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
//后序遍历
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if (root == nullptr) return 0;
//         return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//     }
// };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<TreeNode*> nodeStk;
        TreeNode* pre = nullptr;
        int depth = 0, ret = 0;
        while (!nodeStk.empty() || root != nullptr) {
            // std::cout << "cur" << root->val << ", depth: " << depth << "!\n";
            while (root != nullptr) {
                depth += 1;
                nodeStk.push(root);
                // std::cout << "push" << root->val << ", depth: " << depth << "!\n";
                root = root->left;
                ret = max(ret, depth);
            }
            root = nodeStk.top();
            if (root->right == nullptr || root->right == pre) {
                nodeStk.pop();
                pre = root;
                depth -= 1;
                // std::cout << "pop" << root->val << ", depth: " << depth << "!\n";
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return ret;
    }
};

//前序遍历
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         return maxDepth(root, 0);
//     }
//     int maxDepth(TreeNode* root, int depth) {
//         if (root == nullptr) {
//             return depth;
//         }
//         return max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
//     }
// };

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if (root == nullptr) return 0;
//         stack<TreeNode*> nodeStk;
//         stack<int> depthStk;
//         int depth = 0, ret = 0;
//         while (!nodeStk.empty() || root != nullptr) {
//             while (root != nullptr) {
//                 depth += 1;
//                 // std::cout << "push:" << root->val << ", depth: " << depth + 1 << "!\n"; 
//                 nodeStk.push(root);
//                 depthStk.push(depth);
//                 root = root->left;
//             }
//             root = nodeStk.top();
//             depth = depthStk.top();
//             nodeStk.pop();
//             depthStk.pop();
//             // std::cout << "pop:" << root->val << ", depth: " << depth << "!\n"; 
//             ret = max(ret, depth);
//             root = root->right;
//         }
//         return ret;
//     }
// };
