/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//         queue<Node*> que;
//         if (root != NULL) que.push(root);
//         while (!que.empty()) {
//             int m_size = que.size();
//             for (int i = 0; i < m_size; i++) {
//                 Node* cur = que.front();
//                 que.pop();
//                 if (i != m_size - 1) cur->next = que.front();
               
//                 if (cur->left != NULL) que.push(cur->left);
//                 if (cur->right != NULL) que.push(cur->right);
//             }
//         }
//         return root;
//     }
// };
class Solution {
public:
    Node* connect(Node* root) {
        Node* leftMost = root;
        while (leftMost != NULL) {
            //遍历上层，输出下层的next关系，并返回最左侧节点
            Node* head = leftMost;
            Node* pre = NULL, *nextLeftMost = NULL;
            while (head != NULL) {
                if (head->left != NULL) {
                    if (pre != NULL) {
                        pre->next = head->left;      
                    } else {
                        nextLeftMost = head->left;
                    }
                    pre = head->left; 
                }
                if (head->right != NULL) {
                    if (pre != NULL) {
                        pre->next = head->right;
                    } else {
                        nextLeftMost = head->right;
                    }
                    pre = head->right;
                }
                head = head->next;
            }
            leftMost = nextLeftMost;
        }
        return root;
    }
};
