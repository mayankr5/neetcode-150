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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *res = new ListNode();
        ListNode *dummy = res;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;
            dummy->next = new ListNode(sum%10);
            carry = sum/10;
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            dummy->next = new ListNode((carry+l1->val)%10);
            carry = (carry+l1->val)/10;
            dummy = dummy->next;
            l1 = l1->next;
        }
        while(l2){
            dummy->next = new ListNode((carry+l2->val)%10);
            carry = (carry+l2->val)/10;
            dummy = dummy->next;
            l2 = l2->next;
        }

        if(carry)
            dummy->next = new ListNode(carry);

        return res->next;
    }
};
