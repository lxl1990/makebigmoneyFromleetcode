/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         string ret = "";
//         queue<TreeNode*> que;
//         if(root != NULL) que.push(root);
//         while (!que.empty()) {
//             root = que.front();
//             que.pop();
//             if(root != NULL) {
//                 ret += std::to_string(root->val) + ",";
//                 que.push(root->left);
//                 que.push(root->right);
//             } else {
//                 ret += "null,";
//             }
//         }
//         // std::cout << "serialize, " << ret << "\n";
//         return ret;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         list<string> node;
//         string str = "";
//         for (char c: data) {
//             if (c == ',') {
//                 node.emplace_back(str);
//                 // std::cout << "deserialize, string split," << str << "\n";
//                 str.clear();
//             } else {
//                 str += c;
//             }
//         }
//         queue<TreeNode*> que;
//         TreeNode* root = NULL;
//         if (node.size() == 0) {
//             // std::cout << "deserialize, node size: " << node.size() << "\n";
//             return root;
//         }
//         auto itor = node.begin();
//         if (*itor == "null") {
//             return NULL;
//         }
//         root = new TreeNode(std::stoi(*itor));
//         que.push(root);
//         while (!que.empty()) {
//             TreeNode* node = que.front();
//             que.pop();
//             // std::cout << "deserialize,  node: " << node->val << "\n";
//             if(*++itor != "null") {
//                 node->left = new TreeNode(std::stoi(*itor));
//                 que.push(node->left);
//             } else {
//                 // std::cout << "deserialize, left null" << "\n";
//                 node->left = NULL;
//             }
//             if (*++itor != "null") {
//                 node->right = new TreeNode(std::stoi(*itor));
//                 que.push(node->right);
//             } else {
//                 node->right = NULL;
//                 // std::cout << "deserialize, right null" << "\n";
//             }
//         }
//         return root;
//     }
// };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        serialize(root, ret);
        return ret;
    }

    void serialize(TreeNode* root,string & ret) {
        if (root == NULL) {
            ret += "#,";
            return;
        }
        ret += std::to_string(root->val) + ",";
        serialize(root->left, ret);
        serialize(root->right,ret);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        list<string> node;
        string str = "";
        for (char c: data) {
            if (c == ',') {
                node.emplace_back(str);
                // std::cout << "deserialize, string split," << str << "\n";
                str.clear();
            } else {
                str += c;
            }
        }
        TreeNode* root = deserialize(node);
        return root;
    }
    TreeNode* deserialize(list<string>& node) {
        string str = node.front();
        node.pop_front();
        if (str == "#") {
            return NULL;
        }
        TreeNode * root = new TreeNode(std::stoi(str));
        root->left = deserialize(node);
        root->right = deserialize(node);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
