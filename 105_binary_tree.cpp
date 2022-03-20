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
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int st = 0;
//         for (auto val: inorder) {
//             idx_map[val] = st++;
//         }
//         return helper(preorder, inorder, 0, preorder.size() -1);
//     }
//     TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int start, int end) {
//         if (start > end) return nullptr; 
//         int root_val = preorder[preIndex++];
//         TreeNode* root = new TreeNode(root_val);
//         int cur_idx = idx_map[root_val];
//         root->left = helper(preorder, inorder, start, cur_idx - 1);
//         root->right = helper(preorder, inorder, cur_idx + 1, end);
//         return root;
//     }
// private:
//     int preIndex = 0;
//     unordered_map<int, int> idx_map;
// };
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m_size = preorder.size();
        if (m_size == 0) return nullptr;
        int preIndex = 0, inIndex = 0;
        TreeNode* root = new TreeNode(preorder[preIndex]); 
        stack<TreeNode*> stk;
        stk.push(root);
        while (preIndex < m_size - 1) {
            TreeNode* node = stk.top();
            // std::cout << "inIndex: " << inIndex << ", preIndex: " << preIndex << "\n";
            while (node->val != inorder[inIndex]) {
                node->left = new TreeNode(preorder[++preIndex]);
                stk.push(node->left);
                node = node->left;
            }    
            node = stk.top();
            stk.pop();
            inIndex += 1;
            if (stk.empty() || stk.top()->val != inorder[inIndex]) {
                // std::cout << "inIndex: " << inIndex << ", preIndex: " << preIndex << "node: " << node->val << "\n";
                node->right = new TreeNode(preorder[++preIndex]);
                stk.push(node->right);
            }
        }
        return root; 
    }
};
