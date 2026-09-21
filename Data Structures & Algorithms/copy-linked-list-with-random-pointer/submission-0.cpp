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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mp;
        Node *curr = head, *res = new Node(0);
        Node *curr2 = res;
        while(curr){
            Node *node = new Node(curr->val);
            mp[curr] = node;
            curr2->next = node;
            curr = curr->next;
            curr2 = curr2->next;
        }

        curr = head;
        curr2 = res->next;
        while(curr){
            curr2->random = mp[curr->random];
            curr = curr->next;
            curr2 = curr2->next;
        }
        return res->next;
    }
};
