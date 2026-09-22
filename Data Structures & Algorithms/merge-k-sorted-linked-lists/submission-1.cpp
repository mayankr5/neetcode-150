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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr || list2 == nullptr){
            return list1 == nullptr ? list2 : list1;
        }

        ListNode *resLst = new ListNode();
        ListNode *head = resLst;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                resLst->next = list1;
                list1 = list1->next;
            }else{
                resLst->next = list2;
                list2 = list2->next;
            }
            resLst = resLst->next;
        }
        if(list1 != nullptr)
            resLst->next = list1;
        
        if(list2 != nullptr)
            resLst->next = list2;
        
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }
};
