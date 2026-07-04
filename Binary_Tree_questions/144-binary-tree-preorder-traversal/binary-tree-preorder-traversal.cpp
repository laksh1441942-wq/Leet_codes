class Solution {
    void preord(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        preord(root->left, ans);
        preord(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        preord(root, ans);
        return ans;
    }
};