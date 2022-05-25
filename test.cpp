// Example program
#include <iostream>
#include <string>
#include <list>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        serialize(root, ret);
        return ret;
    }
    void serialize(TreeNode* root, string& ret) {
        if (root == nullptr) {
            ret += "#,";
            return;
        }
        ret += to_string(root->val) + ",";
        serialize(root->left, ret);
        serialize(root->right, ret);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //解析数据
        // cout << "deserialize data: " << data << endl;
        list<string> dataArray;
        string str;
        for (char c: data) {
            if (c == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(c);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return deserialize(dataArray);
    }
    
    TreeNode* deserialize(list<string>& dataArray) {
        if (dataArray.empty()) {
            cout << "error" << endl;
            return nullptr;
        }
        if (dataArray.front() == "#") {
            dataArray.pop_front();
            return nullptr;
        } else {
            TreeNode* root = new TreeNode(stoi(dataArray.front()));
            dataArray.pop_front();
            root->left = deserialize(dataArray);
            root->right = deserialize(dataArray);
            return root;
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
  std::string name;
  std::cout << "What is your name? " << endl;
//   getline (std::cin, name);
//   std::cout << "Hello, " << name << "!\n";
  Codec A = Codec();
  string str = "1,2,#,#,3,4,#,#,5,#,#,";
  cout << "input: " << str << endl;
  TreeNode* root = A.deserialize(str);
  std::cout << "output: " << A.serialize(root) << endl;
  
}


