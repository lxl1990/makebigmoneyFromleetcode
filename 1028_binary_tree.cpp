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
//     TreeNode* recoverFromPreorder(string traversal) {
//         //1-401--349---90--88
//         //1-2--3---4-5--6---7
//         stack<TreeNode*> stk;
//         int value = 0;
//         int depth = 0;
//         int i = 0;
//         while (i < traversal.size()) {
//             while (traversal[i] == '-') {
//                 depth += 1;
//                 i++;
//             }
//             while (i <  traversal.size() && traversal[i] != '-') {
//                 value = value * 10 + (traversal[i] - '0');
//                 i++;
//             }
//             TreeNode* next = new TreeNode(value);
//             // std::cout << "i: " << i << ", value: " << value << ", depth: " << depth << "\n";
//             if (stk.size() == depth && depth != 0) {
//                 stk.top()->left = next;
//             } else if (!stk.empty()) {
//                 while (stk.size() != depth) {
//                     stk.pop();
//                 }
//                 stk.top()->right = next;
//             }
//             stk.push(next);
//             value = 0;
//             depth = 0;
//         }
//         while (stk.size() > 1) {
//             stk.pop();
//         }
//         return stk.top();
//     }
// };

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        //1-401--349---90--88
        //1-2--3---4-5--6---7
        return recoverFromPreorder(traversal, 0);
    }
    TreeNode* recoverFromPreorder(string &traversal, int depth) {
        if (index == traversal.size()) return nullptr;
        for (int i = 0; i < depth; i++) {
            if (traversal[index + i] != '-') {
                return nullptr;
            }
        }
        index += depth;
        int val = 0;
        while (index < traversal.size() && traversal[index] != '-') {
            val = val * 10 + (traversal[index++] - '0');
        }
        TreeNode* root = new TreeNode(val);
        root->left = recoverFromPreorder(traversal, depth + 1);
        root->right = recoverFromPreorder(traversal, depth + 1);
        return root;
    }
private:
    int index = 0;
};
