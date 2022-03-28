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
    recursion: return depth of the deepest path consisting of current node, and update the current ans;
    
*/
class Solution {
private:
    int maxDepth = -1;
    TreeNode* node = nullptr;
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        helper(root, 0);
        return node;
    }
    int helper(TreeNode* root, int Depth) {
        if (root == nullptr) return Depth;
        int leftDepth = helper(root->left, Depth + 1);
        int rightDepth = helper(root->right, Depth + 1);
        if (leftDepth == rightDepth && leftDepth >= maxDepth) {
            node = root;
            maxDepth = leftDepth;
        } else if (leftDepth > rightDepth && leftDepth > maxDepth) {
            node = root->left;
            maxDepth = leftDepth;
        } else if (rightDepth > leftDepth && rightDepth > maxDepth) {
            node = root->right;
            maxDepth = rightDepth;
        }
        return max(leftDepth, rightDepth);
    }
};
