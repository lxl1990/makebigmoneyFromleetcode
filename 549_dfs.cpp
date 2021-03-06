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
//         //tuple????????????????????????,?????????????????????, increment??????decrement???
//         stack<tuple<TreeNode*, int, int, int>> stk;
//         //?????????,??????root??????nullptr,????????????
//         while(!stk.empty() || root != nullptr){
//             //?????????????????????,??????????????????,?????????????????????????????????
//             if(root != nullptr){
//                 stk.push({root, 1, 1, 1});
//                 //????????????
//                 //pre.push_back(root->val);
//                 root = root->left;
//             }
//             //??????????????????????????????,?????????????????????????????????????????????,????????????????????????,????????????+1,?????????????????????
//             else{
//                 auto& [CurNode, Curcnt, Curinc, Curdec] = stk.top();
//                 //????????????????????????
//                 if(Curcnt == 1){
//                     Curcnt = 2;
//                     //????????????
//                     //mid.push_back(CurNode->val);
//                     root = CurNode->right;
//                 }
//                 else{
//                     //????????????????????????????????????,????????????pop?????????????????????????????????
//                     maxLen = max(maxLen, (Curinc + Curdec - 1));
//                     stk.pop();
//                     //????????????
//                     //post.push_back(CurNode->val);
//                     //??????????????????,????????????????????????????????????inc???dec???????????????????????????
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
