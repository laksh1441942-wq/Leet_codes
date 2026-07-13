class Solution {
    TreeNode* parentmap(TreeNode* root, map<TreeNode*,TreeNode*>&mpp, int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) res = node;
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int maxtime(map<TreeNode*,TreeNode*>&mpp,TreeNode* target ){
        int maxi =0;
        map<TreeNode*, int> vis;
        vis[target]=1;
        queue<TreeNode*>q;
        q.push(target);
        while(!q.empty()){
            int sz = q.size();
            int fl = 0;
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    fl=1;
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && !vis[node->right]){
                    fl=1;
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(mpp[node] && !vis[mpp[node]]){
                    fl=1;
                    q.push(mpp[node]);
                    vis[mpp[node]]=1;
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mpp;
        TreeNode* target = parentmap(root, mpp, start);
        return maxtime(mpp, target);
    }
};