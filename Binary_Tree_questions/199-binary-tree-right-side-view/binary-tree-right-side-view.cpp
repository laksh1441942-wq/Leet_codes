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
    void rightview(TreeNode* node, vector<int>& ans, int level){
        if(node == NULL) return ;
        if(level==ans.size()){
            ans.push_back(node->val);
        } 
        rightview(node->right, ans, level+1);
        rightview(node->left, ans, level+1);
        
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL ) return ans;
        rightview(root, ans, 0);
        return ans;
        
    }
};