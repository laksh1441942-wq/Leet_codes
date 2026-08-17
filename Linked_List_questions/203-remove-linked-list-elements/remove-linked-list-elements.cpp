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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){
            head = head->next;
        }
        if(!head){
            return head;
        }
        ListNode* curr = head;
        while(curr->next){
            if(curr->next->val == val){
                curr->next = curr->next->next;
                continue;
            }
            curr = curr->next;
        }
        if(!head->next && head->val == val){
            return nullptr;
        }
        return head;
        
    }
};