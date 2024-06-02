class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int total = 0;
        queue<pair<int, int>> que;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0)
                  total++;
                if(grid[i][j] == 2)
                  que.push({i,j});
            }
        }
          
        if(total == 0)
          return 0;

        int days = 0;
        int que_ele = 0;

        int dx[4] = {0, 0 ,1, -1};
        int dy[4] = {1, -1, 0, 0};

        while(!que.empty()){
            int size = que.size();
            que_ele += size;

            while(size--) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
           
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx < 0 || newy < 0 || newx >= m || newy >= n || grid[newx][newy]!=1)
                  continue;
                
                grid[newx][newy] = 2;
                que.push({newx, newy});
            }
        }
        if(!que.empty())
              days++;      
        }

        if(total != que_ele)
          return -1;
        
          return days;

    }
};