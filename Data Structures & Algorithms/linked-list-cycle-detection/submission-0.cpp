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
    bool hasCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return false;

        ListNode *slw = head, *fst = head->next;
        while(fst != nullptr && fst->next != nullptr){
            if(slw == fst)
                return true;
            slw = slw->next;
            fst = fst->next->next;
        }
        return false;
    }
};
