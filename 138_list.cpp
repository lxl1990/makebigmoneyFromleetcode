/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// private:
//     unordered_map<Node*, Node*> cache;
// public:
//     Node* copyRandomList(Node* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }
//         if (!cache.count(head)) {
//             Node* newHead = new Node(head->val);
//             cache[head] = newHead;
//             newHead->next = copyRandomList(head->next);
//             newHead->random = copyRandomList(head->random); 
//         }
//         return cache[head];
//     }
// };


class Solution {
private:
    unordered_map<Node*, Node*> cache;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = new Node(node->val);
            nodeNew->next = node->next;
            node->next = nodeNew;
        }
        for (Node * node = head; node != nullptr; node = node->next->next) {
            node->next->random = (node->random == nullptr ? nullptr : node->random->next);
        }
        // cout << "dafsd" << endl;
        Node* headNew = head->next;
        for (Node* node = head; node != nullptr; node = node->next) {
            Node* nodeNew = node->next;
            node->next = node->next->next;
            if (nodeNew->next != nullptr) nodeNew->next = nodeNew->next->next;
        }
        return headNew;
    }
};
