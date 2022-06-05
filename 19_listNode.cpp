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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* quick = head;
        for (int i = 0; i < n; i++) {
            quick = quick->next;
        }
        while (quick != nullptr) {
            slow = slow->next;
            quick = quick->next;
        }
        slow->next = slow->next->next;
        auto ret = dummy->next;
        delete dummy;
        return ret;
    }
};
