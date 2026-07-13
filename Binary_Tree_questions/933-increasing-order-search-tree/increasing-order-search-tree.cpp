 class Solution {
    TreeNode* prev;
    TreeNode* head;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (!head)
            head = root;

        if (prev)
            prev->right = root;

        root->left = NULL;
        prev = root;

        inorder(root->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        prev = NULL;
        head = NULL;

        inorder(root);

        return head;
    }
};