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
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         inorderTraversal(root, res);
//         return res;
//     }
//     void inorderTraversal(TreeNode* root, vector<int> & res) {
//         if (root == nullptr) {
//             return;
//         }
//         inorderTraversal(root->left, res);
//          res.emplace_back(root->val);
//         inorderTraversal(root->right, res);
//     }
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
//         stack<TreeNode*> stk;
//         while (!stk.empty() || root != nullptr) {
//             while (root != nullptr) {
//                 stk.push(root);
//                 root = root->left;
//             }
//             root = stk.top();
//             stk.pop();
//             res.emplace_back(root->val);
//             root = root->right;
//         }
//         return res;
//     }
// };


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* p1 = root, *p2 = nullptr;
        while (p1 != nullptr) {
            // std::cout << "cur, " << p1->val << "\n";
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue; 
                } else {
                    p2->right = nullptr;
                    // std::cout << "output, " << p1->val << "\n";
                    res.emplace_back(p1->val);
                }
            } else {
                // std::cout << "output, " << p1->val << "\n";
                res.emplace_back(p1->val);
            }
            p1 = p1->right;
        }
        return res;
    }
};
