class Solution {
    int ans = 0;

    void solve(TreeNode* root, int k, int &cnt) {
        if (!root) return;

        solve(root->left, k, cnt);

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        solve(root->right, k, cnt);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        solve(root, k, cnt);
        return ans;
    }
};