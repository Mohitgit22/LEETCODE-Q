class Solution {
public:
    void dfs(int i ,int j,vector<vector<int>>& vis,vector<vector<char>>& grid ) {
        
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = 1;

        int dx[4] = { 0 ,0 ,-1, 1};
        int dy[4] = {-1, 1, 0, 0};

         for(int k = 0; k < 4; k++) {
                int newx = i + dx[k];
                int newy = j + dy[k];
                if(newx < 0 || newy < 0 || newx >= m || newy >= n || vis[newx][newy] == 1 || grid[newx][newy] == '0')
                continue;
                
                dfs(newx, newy, vis, grid);
            }
    }
   

    int numIslands(vector<vector<char>>& grid) {
        
        //make adj list
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> que;
        vector<vector<int>> vis(m, vector<int>(n, 0));

         int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if( vis[i][j] == 0 && grid[i][j] == '1'){
                  dfs(i,j,vis,grid);
                  cnt++;
                }
            }
        }

        return cnt;
    }
};