class Solution {
    
    ListNode* merge(ListNode* left, ListNode* right) {
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        while (left && right) {
            
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }
            
            curr = curr->next;
        }
        
        if (left)
            curr->next = left;
        
        if (right)
            curr->next = right;
        
        return dummy.next;
    }
    
    ListNode* mergesort(ListNode* head) {
        
        // 0 or 1 node is already sorted
        if (!head || !head->next)
            return head;
        
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split into two lists
        ListNode* right = slow->next;
        slow->next = nullptr;
        
        // Sort both halves
        ListNode* left = mergesort(head);
        right = mergesort(right);
        
        // Merge sorted halves
        return merge(left, right);
    }

public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};