class Solution {
    void preord(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        preord(root->left, ans);
        preord(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        preord(root, ans);
        return ans;
    }
};