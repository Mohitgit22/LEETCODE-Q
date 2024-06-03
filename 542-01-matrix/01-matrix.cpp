class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int, int>, int>> que;
        vector<vector<int>> visited(m, vector(n, 0));
        vector<vector<int>> dist(m, vector(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n ; j++) {
                if(mat[i][j] == 0){
                   que.push({{i, j}, 0});
                   visited[i][j] = 1;
                }else
                visited[i][j] = 0;
            }
        }
       
       int dx[4] = {0 ,0 , -1, 1};
       int dy[4] = {-1, 1, 0 , 0};


        while(!que.empty()) {
                int x = que.front().first.first;
                int y = que.front().first.second;
                int steps = que.front().second;
                que.pop();
                dist[x][y] = steps;
                // for all 4 neighbours
                for(int i = 0; i < 4 ; i++) {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(newx < 0 || newy < 0 || newx >= m || newy >= n || visited[newx][newy] == 1)
                    continue;
                    visited[newx][newy] = 1;
                    que.push({{newx, newy}, steps + 1});
                }
            }
        
        return dist;
    }
};