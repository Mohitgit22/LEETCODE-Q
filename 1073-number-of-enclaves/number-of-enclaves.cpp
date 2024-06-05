class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> que;
        vector<vector<int>> vis(m ,vector<int>(n, 0));
        
        //push all 1 present at boundary and mark them visited
        for(int i = 0 ; i < m; i++) { 
            for(int j = 0; j < n; j++) {
                if((i ==0 || i == m-1 || j ==0 || j == n-1) && grid[i][j] == 1){
                    vis[i][j] = 1;
                    que.push({i, j});
                }
            }
        }
        

        int dx[4] = {0 , 0 , -1 ,1};
        int dy[4] = {-1, 1, 0, 0};

        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            //check all 4 neighbours
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx < 0 || newy < 0 || newx >= m || newy >= n || grid[newx][newy] == 0 || vis[newx][newy] == 1 )
                continue;
                
                que.push({newx, newy});
                vis[newx][newy] = 1;
            }
        }
        
        int cnt = 0; 
        for(int i =0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1)
                cnt++;
            }
        }
      
       return cnt;

    }
};