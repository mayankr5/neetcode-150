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
    void reverse(ListNode *head, ListNode *prev, ListNode *nxt){
        ListNode *curr = head, *currNxt = head, *currPrev = nullptr;
        while(curr != nxt){
            currNxt = curr->next;
            curr->next = currPrev;
            currPrev = curr;
            curr = currNxt;
        }
        head->next = nxt;
        prev->next = currPrev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1 || head == nullptr || head->next == nullptr)
            return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curr = head, *prev = dummy, *nxt = head, *currHead = head;

        int currSz = 0;
        while(curr){
            nxt = curr->next;
            currSz++;
            if(currSz == k){
                reverse(currHead, prev, nxt);
                prev = currHead;
                currHead = nxt;
                currSz = 0;
            }
            curr = nxt;
        }
        return dummy->next;
    }
};
