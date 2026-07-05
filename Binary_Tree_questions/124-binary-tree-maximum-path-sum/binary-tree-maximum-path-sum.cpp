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
    int PathSum(TreeNode* node, int& maxi){
        if(node == NULL) return 0;
        int lf = max(0, PathSum(node->left, maxi));
        int rt = max(0, PathSum(node->right, maxi));
        maxi = max(maxi, lf+rt+node->val);
        return max(lf,rt)+node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        PathSum(root, maxi);
        return maxi;
    }
};