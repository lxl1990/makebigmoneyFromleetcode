// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
//  /*
//     use recursion, for each node, the function return two length of longest path increasing and decreasing
//     as we know, the result of left child node is (a1, a2), the result of right child node is (b1, b2);
//     then the result of the root node can be derived as follow
//     if root->val == root->left->val + 1, c11 = a1 + 1;
//     elif root->val == root->left->val - 1, c21 = a2 + 1;
//     if root->val == root->right->val + 1, c12 = b1 + 1;
//     elif root->val == root->right->val - 1, c22 = b2 + 1;
//     update ans then;
    
//  */
// class Solution {
// private:
//     int ans = 1;
// public:
//     int longestConsecutive(TreeNode* root) {
//         if (root == nullptr) return 0;
//         helper(root);
//         return ans;
//     }
//     vector<int> helper(TreeNode* root) {
//         if (root == nullptr) return vector<int>(2, 0);
//         vector<int> leftLen = helper(root->left);
//         vector<int> rightLen = helper(root->right);
//         vector<int> ret(2, 1);
//         if (root->left != nullptr && root->val == root->left->val + 1) {
//             ret[0] = leftLen[0] + 1;
//         } else if (root->left != nullptr && root->val == root->left->val - 1) {
//             ret[1] = leftLen[1] + 1;
//         }
//         if (root->right != nullptr && root->val == root->right->val + 1) {
//             ret[0] = max(ret[0], rightLen[0] + 1);
//         } else if (root->right != nullptr && root->val == root->right->val - 1) {
//             ret[1] = max(ret[1], rightLen[1] + 1);
//         }
//         ans = max(ans, ret[0] + ret[1] - 1);
//         return ret;
//     }
// };


// class Solution {
// public:
//     int maxLen;

// //  vector<int> pre;
// //  vector<int> mid;
// //  vector<int> post;

//     int longestConsecutive(TreeNode* root) {
//         //tuple的内容分别是节点,当前出栈的次数, increment数和decrement数
//         stack<tuple<TreeNode*, int, int, int>> stk;
//         //栈非空,或者root部位nullptr,继续循环
//         while(!stk.empty() || root != nullptr){
//             //当前节点不为空,压入当前节点,并且下个节点为其左节点
//             if(root != nullptr){
//                 stk.push({root, 1, 1, 1});
//                 //前序遍历
//                 //pre.push_back(root->val);
//                 root = root->left;
//             }
//             //取出栈中最顶端的节点,看看是第一次访问还是第二次访问,如果是第一次访问,访问次数+1,继续访问右节点
//             else{
//                 auto& [CurNode, Curcnt, Curinc, Curdec] = stk.top();
//                 //当前是第一次出栈
//                 if(Curcnt == 1){
//                     Curcnt = 2;
//                     //中序遍历
//                     //mid.push_back(CurNode->val);
//                     root = CurNode->right;
//                 }
//                 else{
//                     //已经是右节点返回的节点了,在该节点pop前统计该节点的最大次数
//                     maxLen = max(maxLen, (Curinc + Curdec - 1));
//                     stk.pop();
//                     //后续遍历
//                     //post.push_back(CurNode->val);
//                     //如果栈不为空,则将当前节点对其父节点的inc和dec影响数加到父节点上
//                     if(!stk.empty()){
//                         auto& [pointer, cnts, inc, dec] = stk.top();
//                         if(pointer->val == CurNode->val - 1)
//                             inc = max(Curinc + 1, inc);
//                         if(pointer->val == CurNode->val + 1)
//                             dec = max(Curdec + 1, dec);                        
//                     }                    
//                     root = nullptr;
//                 }
//             }
//         } 
//         return maxLen;
//     }
// };



class Solution {
public:
    int maxLen = 0;
    int longestConsecutive(TreeNode* root) {
        stack<tuple<TreeNode*, int, int>> stk;
        TreeNode* pre = nullptr;
        while(!stk.empty() || root != nullptr){
            while (root != nullptr){
                stk.push({root, 1, 1});
                root = root->left;
            }
            auto& [node, Curinc, Curdec] = stk.top();
            if (node->right == nullptr || node->right == pre) {
                stk.pop();
                maxLen = max(maxLen, Curinc + Curdec - 1);
                pre = node;
                if (!stk.empty()) {
                    auto& [pointer, inc, dec] = stk.top();
                    if (pointer->val == node->val + 1) {
                        inc = max(Curinc + 1, inc);
                    } else if (pointer->val == node->val - 1) {
                        dec = max(Curdec + 1, dec);
                    }
                }
                root = nullptr;
            } else {
                root = node->right;
            }
        } 
        return maxLen;
    }
};
