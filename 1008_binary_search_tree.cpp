o/**
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
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         //迭代
//         if (preorder.size() == 0) return nullptr;
//         int preIndex = 0;
//         TreeNode* root = new TreeNode(preorder[preIndex++]);
//         stack<TreeNode*> stk;
//         stk.push(root);
//         while (!stk.empty() && preIndex < preorder.size()) {
//             TreeNode* node = stk.top();
//             if (preorder[preIndex] < node->val) {
//                 node->left = new TreeNode(preorder[preIndex++]);
//                 node = node->left;
//                 stk.push(node);
//             } else {
//                 stk.pop();
//                 if (stk.empty() || stk.top()->val > preorder[preIndex]) {
//                     node->right = new TreeNode(preorder[preIndex++]);
//                     stk.push(node->right);
//                 }
//             }
//         }
//         return root;
//     }
// };
// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         //递归
//         return bstFromPreorder(preorder, 0, preorder.size() - 1);
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder, int begin, int end) {
//         if (begin > end) {
//             return nullptr;
//         }
//         int val = preorder[begin];
//         TreeNode* root = new TreeNode(val);
//         int privot = begin + 1;
//         while (privot <= end) {
//             if (preorder[privot] > val) break;
//             privot++;
//         }
//         std::cout<< "begin: " << val << ", privot: "<< privot << "\n";
//         root->left = bstFromPreorder(preorder, begin + 1, privot - 1);
//         root->right = bstFromPreorder(preorder, privot, end);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //迭代，第二版
        stack<TreeNode*> stk;
        TreeNode* root = nullptr;
        for (int i = 0; i < preorder.size(); i++) {
            int val = preorder[i];
            TreeNode* node = new TreeNode(val);
            if (stk.empty()) {
                root = node;
                stk.push(node);
            } else {
                TreeNode* top = stk.top();
                while (!stk.empty() && stk.top()->val < val) {
                    top = stk.top();
                    stk.pop(); 
                }
                if (top->val > val) {
                    top->left = node;
                } else {
                    top->right = node;
                }
                stk.push(node);
            }
        }
        return root;
    }
};
