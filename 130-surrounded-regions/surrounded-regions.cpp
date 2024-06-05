class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> que;
      
      //1. put all 'O' elements on the boundary to queue and mark them visited
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    que.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dx[4] = { 0 ,0 ,-1, 1};
        int dy[4] = {-1, 1, 0, 0};

        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for(int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx < 0 || newy < 0 || newx>= m || newy >= n || board[newx][newy] != 'O'||vis[newx][newy] == 1)
                continue;
                // if (newx < 0 || newy < 0 || newx >= m || newy >= n) continue; // Check boundaries first
                // if (vis[newx][newy] == 1 || board[newx][newy] != 'O') continue; // Then check visited and board state
                
                que.push({newx, newy});
                vis[newx][newy] = 1;
            }
        }
        for(int i =0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};