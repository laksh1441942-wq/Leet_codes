class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        queue<pair<int,int>> q;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int initialcolor = image[sr][sc];
        image[sr][sc]=color;
        vis[sr][sc]=1;
        int drow[4] = {0, 0, 1, -1};
        int dcol[4] = {1, -1, 0, 0};
        q.push({sr,sc});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int row = r + drow[i];
                int col = c + dcol[i];
                if(row >= 0 && row<n && col>=0 && col<m && image[row][col]==initialcolor && !vis[row][col]){
                    image[row][col]=color;
                    vis[row][col]=1;
                    q.push({row,col});
            }
            }
        }
        return image;
    }
};