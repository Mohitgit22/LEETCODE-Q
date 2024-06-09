class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                   grid[i][j] = 0;
            }
        }

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            grid[u][v] = wt;
            grid[v][u] = wt;
        }

        for(int via = 0; via < n; via++) {
            for(int i = 0; i< n; i++) {
                for(int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }

      vector<int> ans;
        int cnt = 0;
        for(int i = 0; i < n;i++) {
            for(int j = 0; j < n; j++) {  
                if( i!= j && grid[i][j] <= distanceThreshold)
                  cnt+=1;
            }
            ans.push_back(cnt);
            cnt = 0;
        }
        
      int ans_city_cnt = INT_MAX;
      int anscity = -1;
        for(int i = 0; i < n; i++) {
            if(ans[i] < ans_city_cnt){
             anscity = i;
             ans_city_cnt = ans[i];
            }
             else if(ans[i] == ans_city_cnt && i > anscity){
                   anscity = i;
             }
        }
        return anscity;

    }
};