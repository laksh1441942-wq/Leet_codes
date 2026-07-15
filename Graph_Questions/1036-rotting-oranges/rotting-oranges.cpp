class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        int tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm , t);
            q.pop();
            int drow[4] = {0,0,-1,1};
            int dcol[4] = {1,-1,0,0};
            for(int i =0; i<4; i++){
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row >= 0 && row <n && col >=0 && col < m){
                    if(grid[row][col]==1 && !vis[row][col]){
                        grid[row][col] = 2;
                        vis[row][col] = 1;
                        q.push({{row,col}, tm + 1} );
                        cntFresh--;
                    }
                }
            }
        }
        if(cntFresh) return -1;
        return tm;
    }
};