class Solution {
    int Height(TreeNode* node){
        if(node == NULL) return 0;

        return 1 + max(Height(node->left), Height(node->right));
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh = Height(root->left);
        int rh = Height(root->right);

        if(abs(lh-rh)>1) return false;

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        if(!l || !r) return false;

        return true; 
    }
};