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
        if (root == NULL) return NULL;
        Node* leftMostNode = root;
        while (leftMostNode->left != NULL) {
            Node* head = leftMostNode;
            while (head != NULL) {
                head->left->next = head->right;
                if (head->next != NULL) head->right->next = head->next->left;
                head = head->next;
            }
            leftMostNode = leftMostNode->left;
        }
        return root;
    }
};
