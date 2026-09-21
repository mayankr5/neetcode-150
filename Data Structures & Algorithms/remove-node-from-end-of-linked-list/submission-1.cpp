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
    ListNode* removeNthFromEnd(ListNode* head, int &n) {
        ListNode *prev = nullptr, *curr = head, *rm = head;
        while(n){
            curr = curr->next;
            n--;
        }
        while(curr){
            prev = rm;
            rm = rm->next;
            curr = curr->next;
        }


        if(prev == nullptr)
            return head->next;
        cout << prev->val << ' ';;
        prev->next = rm->next;

        return head;
    }
};
