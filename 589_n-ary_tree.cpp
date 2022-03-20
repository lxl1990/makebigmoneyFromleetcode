/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        //迭代
        vector<int> ret;
        stack<pair<Node*, int>> stk;
        int index = 0;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                ret.push_back(root->val);
                stk.push(make_pair(root, index));
                root = (root->children.size() > 0) ? root->children[0] : nullptr;
                index = 0;
            }
            root = stk.top().first;
            index = stk.top().second;
            stk.pop();
            if (stk.empty() || stk.top().first->children.size() == index + 1) {
                root = nullptr;
            } else {
                root = stk.top().first->children[++index];
            }
        }
        return ret;
    }
};
