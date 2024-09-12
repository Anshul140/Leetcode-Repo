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
    ListNode* reverse(ListNode* head){
        ListNode *cur = head, *prev = NULL, *nxt = NULL;

        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == NULL or head->next == NULL) return;
        ListNode* prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *l1 = head;

        while(fast != NULL and fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        ListNode* l2 = reverse(slow);

        merge(l1, l2);
    }

    void merge(ListNode* l1, ListNode* l2){
        while(l2 != NULL){
            ListNode* temp = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = temp;
        }
    }
};