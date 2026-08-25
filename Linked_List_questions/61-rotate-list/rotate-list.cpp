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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0 || !head->next) return head;

        ListNode* temp = head;

        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        if(k%cnt == 0) return head;
        for(int i=1; i<cnt-(k%cnt); i++){
            temp = temp->next;
        }
        ListNode* curr = temp->next;
        ListNode* newHead = temp->next;
        temp->next = NULL;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = head;
        return newHead;
    }
};