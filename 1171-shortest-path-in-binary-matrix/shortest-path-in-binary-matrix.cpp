class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n;
       
        if(grid[0][0] == 1)
         return -1;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        queue<pair<int, pair<int, int>>> que;
        que.push({1, {0, 0}});

        int dx[8] = {-1, 1, 1, 0, 0, -1, -1, 1};
        int dy[8] = {1, 0, 1, -1, 1, -1, 0, -1};

        while(!que.empty()) {
            int d = que.front().first;
            int x = que.front().second.first;
            int y = que.front().second.second;
            que.pop();

            for(int i = 0;i < 8; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >=0 && newy >= 0 && newx < n && newy < n && grid[newx][newy] == 0 && d + 1 < dist[newx][newy]){
                    dist[newx][newy] = d + 1;

                     if(newx == n-1 && newy == n-1)
                     return dist[newx][newy];

                     que.push({d+1, {newx, newy}});
                }
            }
        }
          if(dist[n-1][n-1] == 1e9)
         return -1;

         return dist[n-1][n-1];
    }
};