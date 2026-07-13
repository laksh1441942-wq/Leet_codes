class Solution {
    int height(TreeNode* node, int &diameter){
        if(node==NULL){
            return 0;
        }

        int lh=height(node->left,diameter);
        int rh=height(node->right,diameter);
        diameter=max(diameter,lh+rh);

        return max(lh,rh)+1;
    }
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};