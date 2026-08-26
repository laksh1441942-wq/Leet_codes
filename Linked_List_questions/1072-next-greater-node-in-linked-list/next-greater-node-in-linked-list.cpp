class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;

        // Convert linked list to vector
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(values.size(), 0);
        stack<int> st;

        for (int i = 0; i < values.size(); i++) {

            // Find the next greater element
            while (!st.empty() && values[i] > values[st.top()]) {
                ans[st.top()] = values[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};