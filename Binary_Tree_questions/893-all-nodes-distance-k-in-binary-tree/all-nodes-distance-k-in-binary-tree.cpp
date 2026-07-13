class Solution {
    void parenttrack(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parentTrack;
        parenttrack(root, parentTrack);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int curr = 0;

        while(!q.empty()) {

            if(curr++ == k)
                break;

            int size = q.size();

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                if(node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                if(parentTrack.count(node) && !visited[parentTrack[node]]) {
                    visited[parentTrack[node]] = true;
                    q.push(parentTrack[node]);
                }
            }
        }

        vector<int> result;

        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};