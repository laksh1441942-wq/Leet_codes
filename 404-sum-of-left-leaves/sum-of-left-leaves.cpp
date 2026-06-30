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
    int leafsum(TreeNode* root, int& leafSum){
        if(!root) return 0;

        if(root->left && !root->left->left && !root->left->right){
            leafSum += root->left->val;
        }
        leafsum(root->left,leafSum);
        leafsum(root->right,leafSum);
        return leafSum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int leafSum = 0;
        
        return leafsum(root, leafSum);
    }
};