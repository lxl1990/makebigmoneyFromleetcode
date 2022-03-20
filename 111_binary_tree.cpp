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
//     int minDepth(TreeNode* root) {
//         //后续遍历
//         if (root == NULL) {
//             return 0;
//         }
//         if (root->left == NULL && root->right == NULL) {
//             return 1;
//         }
        
//         return min((root->left != NULL) ? minDepth(root->left) : MAX_INT, (root->right != NULL) ? minDepth(root->right) : MAX_INT) + 1;
//     }
// private:
//     const int MAX_INT = 0x7fffffff;
//     const int MIN_INT = 0x80000000;
// };
// class Solution {
// public:
//     int minDepth(TreeNode* root, int depth) {
//         if (root->left == NULL && root->right == NULL) {
//             return depth + 1;
//         }
//         return min((root->left != NULL) ? minDepth(root->left, depth + 1) : MAX_INT, (root->right != NULL) ? minDepth(root->right, depth + 1) : MAX_INT);
//     }
//     int minDepth(TreeNode* root) {
//         //先序遍历
//         if (root == NULL) {
//             return 0;
//         }
//         return minDepth(root, 0);
//     }
// private:
//     const int MAX_INT = 0x7fffffff;
//     const int MIN_INT = 0x80000000;
// };
class Solution {
public:
    int minDepth(TreeNode* root) {
        //先序遍历
        int ret = MAX_INT;
        if (root == nullptr) {
            return 0;
        }
        stack<TreeNode*> nodeStk;
        stack<int> depthStk;
        int depth = 1;
        while (!nodeStk.empty() || root != nullptr) {
            while (root != nullptr) {
                nodeStk.push(root);
                root = root->left;
                depthStk.push(depth);
                depth += 1;
            }
            root = nodeStk.top();
            depth = depthStk.top();
            nodeStk.pop();
            depthStk.pop();
            if (root->right == nullptr) {
                // std::cout<< "root: " << root->val << ", depth: " << depth <<"\n";
                if (root->left == nullptr) ret = min(ret, depth);
                root = nullptr;
            } else {
                // std::cout<< "root: " << root->val << ", depth: " << depth <<"\n";
                root = root->right;
                depth += 1;
            }
        }
        return ret;
    }
private:
    const int MAX_INT = 0x7fffffff;
    const int MIN_INT = 0x80000000;
};
