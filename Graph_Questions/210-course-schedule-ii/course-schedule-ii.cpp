class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
        vector<vector<int>>adj(N);
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indeg(N,0);
        for(int i=0; i<N; i++){
            for(int it : adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<N; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        if(topo.size() == N ) return topo;
        return {};
    }
};