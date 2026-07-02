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