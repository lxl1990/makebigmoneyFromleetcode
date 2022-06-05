/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//merge
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         return merge(lists, 0, lists.size() - 1);
//     }
//     ListNode* merge(vector<ListNode*>& lists, int start, int end) {
//         if (start == end) {
//             return lists[start];
//         } else if (start > end) {
//             return nullptr;
//         }

//         int mid = start + ((end - start) >> 1);
//         return mergeTwo(merge(lists, start, mid), merge(lists, mid + 1, end));
//     }

//     ListNode* mergeTwo(ListNode* node1, ListNode* node2) {
        
//         ListNode* dummy = new ListNode(0);
//         ListNode* node = dummy;
//         while (node1 != nullptr && node2 != nullptr) {
//             if (node1->val > node2->val) {
//                 node->next = node2;
//                 node2 = node2->next;
//             } else {
//                 node->next = node1;
//                 node1 = node1->next;
//             }
//             node = node->next;
//         }
//         if (node1 == nullptr) node->next = node2;
//         if (node2 == nullptr) node->next = node1;
//         node = dummy->next;
//         delete dummy;
//         return node;
//     }
// };


//priority queue
typedef ListNode* ListNodePtr;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto myCmp = [](const ListNodePtr& node1, const ListNodePtr& node2) {
            return node1->val > node2->val;
        };
        priority_queue<ListNodePtr, vector<ListNodePtr>, decltype(myCmp)> pq(myCmp);
        int k = lists.size();
        if (k == 1) return lists[0];
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            node->next = cur;
            node = node->next;
            if (cur->next != nullptr) pq.push(cur->next);
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};
