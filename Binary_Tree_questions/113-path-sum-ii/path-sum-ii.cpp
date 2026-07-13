/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void path(TreeNode* root, int targetSum, vector<vector<int>>& ans,
              vector<int>& curr, int sum) {

        if (!root) return;

        curr.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right && sum == targetSum) {
            ans.push_back(curr);
        }

        path(root->left, targetSum, ans, curr, sum);
        path(root->right, targetSum, ans, curr, sum);

        curr.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> curr;

        path(root, targetSum, ans, curr, 0);

        return ans;
    }
};