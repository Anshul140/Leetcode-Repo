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
    ListNode* partition(ListNode* head, int x) {
        ListNode *t = head;
        ListNode *res = new ListNode(), *ref = res;
        while(t){
            if(t->val < x) {
                ListNode* temp = new ListNode(t->val);
                res->next = temp;
                res = temp;
            }
            t = t->next;
        }
        
        t = head;
        while(t){
            if(t->val >= x) {
                ListNode* temp = new ListNode(t->val);
                res->next = temp;
                res = temp;
            }
            t = t->next;
        }
        
        return ref->next;
    }
};