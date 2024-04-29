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
    //  p1 -> p2 -> p3 -> p4
    /*
       x <- p1 <- p2
    */
    ListNode* reverse(ListNode* head){
        ListNode* curr = head, *prev = NULL, *nxt = NULL;
       
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* s1, ListNode* s2) {
        // ListNode *s1 = reverse(l1), *s2 = reverse(l2);
        // print(s1);
        // print(s2);
        ListNode *res = NULL;
        int carry = 0;
        while(s1 and s2){
            int x = s1->val + s2->val + carry;
            int cur = x % 10;
            carry = x/10;
            ListNode* temp = new ListNode(cur);
            temp->next = res;
            res = temp;
            s1 = s1->next;
            s2 = s2->next;
        } 
        
        while(s1) {
            int x = s1->val + carry;
            int cur = x % 10;
            carry = x/10;
            ListNode* temp = new ListNode(cur);
            temp->next = res;
            res = temp;
            s1 = s1->next;
        }
        
        while(s2) {
            int x = s2->val + carry;
            int cur = x % 10;
            carry = x/10;
            ListNode* temp = new ListNode(cur);
            temp->next = res;
            res = temp;
            s2 = s2->next;
        }
        
        if(carry) {
            ListNode* temp = new ListNode(carry);
            temp->next = res;
            res = temp;
        }
        
        return reverse(res);
    }
};