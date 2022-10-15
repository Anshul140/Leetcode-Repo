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
    ListNode* deleteMiddle(ListNode* head) {
        int sz = 0;
        ListNode* t = head;
        
        if(t->next == NULL) return NULL;
        
        while(t != NULL) {
            sz++;
            t = t->next;
        }
        
        t = head;
        int ctr = 0;
        
        while(ctr < (sz/2)-1) {
            t = t->next;
            ctr++;
        }
        
        t->next = t->next->next;
        return head;
    }
};