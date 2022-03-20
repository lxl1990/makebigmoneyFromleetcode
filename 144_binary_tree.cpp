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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     stack<TreeNode*> nodeStack;
    //     while (!nodeStack.empty() || root != nullptr) {
    //         while (root != nullptr) {
    //             nodeStack.push(root);
    //             result.emplace(result.end(), root->val);
    //             root = root->left;
    //         }
    //         root = nodeStack.top();
    //         nodeStack.pop();
    //         root = root->right;  
    //     }
    //     return result;
    // }

    //Morris遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                }
            } else {
                res.emplace_back(p1->val);
            }
            p1 = p1->right;
        }
        return res;
    }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     if (root == nullptr) {
    //         return res;
    //     }
    //     TreeNode *p1 = root, *p2 = nullptr;
    //     while (p1 != nullptr) {
    //         p2 = p1->left;
    //         if (p2 != nullptr) {
    //             while (p2->right != nullptr) {
    //                 p2 = p2->right;
    //             }
    //             if (p1->right != nullptr) p2->right = p1->right;
    //             p1->right = nullptr;
    //             res.emplace(res.end(), p1->val);
    //             p1 = p1->left;
    //             continue;
    //         } else {
    //             res.emplace(res.end(), p1->val);
    //             p1 = p1->right;
    //         }
    //     }
    //     return res;
    // }
};
