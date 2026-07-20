class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        vector<vector<int>> adj(N);

        // Build graph
        for (int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        // Compute indegree
        vector<int> indeg(N, 0);

        for (int i = 0; i < N; i++) {
            for (int it : adj[i]) {
                indeg[it]++;
            }
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        int cnt = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (int it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }

        return cnt == N;
    }
};