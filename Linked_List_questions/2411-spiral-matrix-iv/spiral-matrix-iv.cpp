class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        ListNode* temp = head;

        while (temp && top <= bottom && left <= right) {

            // Left -> Right
            for (int j = left; j <= right && temp; j++) {
                ans[top][j] = temp->val;
                temp = temp->next;
            }
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom && temp; i++) {
                ans[i][right] = temp->val;
                temp = temp->next;
            }
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left && temp; j--) {
                    ans[bottom][j] = temp->val;
                    temp = temp->next;
                }
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top && temp; i--) {
                    ans[i][left] = temp->val;
                    temp = temp->next;
                }
                left++;
            }
        }

        return ans;
    }
};