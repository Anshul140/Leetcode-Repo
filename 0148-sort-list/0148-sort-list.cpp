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
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* temp = new ListNode(0);
        ListNode* dummy = temp;

        while(left && right) {
            if(left->val <= right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if(left) temp->next = left;
        else temp->next = right;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) {
            return head;
        }

        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;

        mid->next = nullptr;
        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};