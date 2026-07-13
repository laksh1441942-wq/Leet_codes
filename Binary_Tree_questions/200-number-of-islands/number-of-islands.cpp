class Solution {

    void bfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>&grid){
        vis[r][c] = 1;
        queue<pair<int,int>> que;
        que.push({r, c});
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};
        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            for(int i =0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 && nrow <n && ncol >=0 && ncol <m){
                    if(grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        que.push({nrow, ncol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};