class Solution {
private:
    bool dfs(int node, vector<int>&vis, vector<int>&pathvis,vector<vector<int>>& graph, vector<int>&check){
        vis[node]=1;
        pathvis[node]= 1;
        for(int it : graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathvis, graph, check)){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvis[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>check(n,0);
        vector<int> safenode;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, pathvis, graph, check);
            }
        }
        for(int i=0; i<n; i++){
            if(check[i]){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};