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
    int doubleNum(ListNode* temp){
        if(!temp){
            return 0;
        }
        int carry = doubleNum(temp->next);
        int val = (2*temp->val) + carry;
        temp->val = val%10;
        return val/10;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* newhead = new ListNode(doubleNum(head));
        newhead->next = head;
        if(newhead->val) return newhead;
        return head;
    }
};