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
    int getDecimalValue(ListNode* head) {
        string num = "";
        while(head != NULL) {
            char ch = '0'+ head->val;
            num.push_back(ch);
            head = head->next;
        }
        
        cout<<num<<endl;
        
        int ul = bitset<32>(num).to_ulong();
        return ul;
    }
};