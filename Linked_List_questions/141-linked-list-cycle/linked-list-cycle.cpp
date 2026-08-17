/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        while(temp){
            if(temp->val == INT_MIN){
                return true;
            }
            temp->val = INT_MIN;
            temp = temp->next;
        }
        return false;
    }
};