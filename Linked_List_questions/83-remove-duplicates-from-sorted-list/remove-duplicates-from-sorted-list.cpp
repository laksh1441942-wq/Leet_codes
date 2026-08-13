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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        set<int>st;
        ListNode* temp = head->next;
        ListNode* prev = head;
        st.insert(head->val);
        while(temp){
            if(st.contains(temp->val)){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{
                st.insert(temp->val);
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};