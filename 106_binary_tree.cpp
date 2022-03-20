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
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
//     }
//     TreeNode* buildTree(vector<int>& inorder, int start_inorder, int end_inorder, vector<int>& postorder, int start_postorder, int end_postorder) {
//         if (start_inorder > end_inorder || start_postorder > end_postorder) return nullptr;
//         TreeNode* root = new TreeNode(postorder[end_postorder]);
//         int target_index = start_inorder;
//         while (target_index <= end_inorder) {
//             if (inorder[target_index] == postorder[end_postorder]) break;
//             target_index += 1;
//         }
//         root->left = buildTree(inorder, start_inorder, target_index - 1, postorder, start_postorder, start_postorder + target_index - 1 - start_inorder);
//         root->right = buildTree(inorder, target_index + 1, end_inorder, postorder, end_postorder - (end_inorder - target_index), end_postorder - 1);
//         return root;
//     }
// };

// class Solution {
//     unordered_map<int, int> idx_map;
//     int end_pos = 0;
// public:
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         for (int i = 0; i < inorder.size(); i++) {
//             idx_map[inorder[i]] = i;
//         }
//         end_pos = postorder.size() - 1;
//         return helper(inorder, postorder, 0, inorder.size()-1);
//     }
//     TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start, int end) {
//         if (start > end) return nullptr;
//         int root_val = postorder[end_pos--];
//         int target_index = idx_map[root_val];
//         TreeNode* root = new TreeNode(root_val);
//         root->right = helper(inorder, postorder, target_index + 1, end);
//         root->left = helper(inorder, postorder, start, target_index - 1);
//         return root;
//     }
// };
class Solution {
    unordered_map<int, int> idx_map;
    int end_pos = 0;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        if (postIndex < 0) return nullptr;
        //中序遍历
        int inorderIndex = inorder.size() - 1;
        TreeNode* node =  new TreeNode(postorder[postIndex]);
        stack<TreeNode*> stk;
        stk.push(node);
        TreeNode* root = node;
        while (postIndex > 0) {
            // std::cout << "root: " << root->val << ", inorderIndex: " << inorderIndex << ", postIndex: " << postIndex << "\n";
            while (root->val != inorder[inorderIndex]) {
                root->right = new TreeNode(postorder[--postIndex]);
                stk.push(root->right);
                root = stk.top();
            }
            root = stk.top();
            stk.pop();
            inorderIndex -= 1;
            if (stk.empty() || stk.top()->val != inorder[inorderIndex]) {
                root->left = new TreeNode(postorder[--postIndex]);
                stk.push(root->left); 
            }
            root = stk.top();
        }
        return node;

    }
};
