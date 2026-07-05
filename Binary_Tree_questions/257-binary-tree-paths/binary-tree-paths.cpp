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
    void solve(TreeNode* node, vector<string>& path, string crr){
        if(node == NULL) return;
        crr = crr + to_string(node->val);
        if(!node->left && !node->right){
            path.push_back(crr);
            return;
        }
        crr += "->";
        solve(node->left, path, crr );
        solve(node->right, path, crr );
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        solve(root, ans, "");
        return ans;
    }
};